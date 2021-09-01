#include "hal.h"

#include "switch_sense.h"

void InitSwitchSense()
{
    // switch sense is on GPIOB9 = ADC ch 9
    palSetPadMode(GPIOB, 1, PAL_MODE_INPUT_ANALOG);

    adcStart(&ADCD1, nullptr);
}

#define ADC_SAMPLING_SLOW ADC_SAMPLE_56

static constexpr int oversample = 32;

static constexpr ADCConversionGroup convGroup = {
	.circular			= FALSE,
	.num_channels		= 1,
	.end_cb				= nullptr,
	.error_cb			= nullptr,
	/* HW dependent part.*/
	.cr1				= 0,
	.cr2				= ADC_CR2_SWSTART,
	// Configure all channels to ADC_SAMPLING_SLOW sample time
	.smpr1 =
		ADC_SMPR1_SMP_AN10(ADC_SAMPLING_SLOW) |
		ADC_SMPR1_SMP_AN11(ADC_SAMPLING_SLOW) |
		ADC_SMPR1_SMP_AN12(ADC_SAMPLING_SLOW) |
		ADC_SMPR1_SMP_AN13(ADC_SAMPLING_SLOW) |
		ADC_SMPR1_SMP_AN14(ADC_SAMPLING_SLOW) |
		ADC_SMPR1_SMP_AN15(ADC_SAMPLING_SLOW),
	.smpr2 =
		ADC_SMPR2_SMP_AN0(ADC_SAMPLING_SLOW) |
		ADC_SMPR2_SMP_AN1(ADC_SAMPLING_SLOW) |
		ADC_SMPR2_SMP_AN2(ADC_SAMPLING_SLOW) |
		ADC_SMPR2_SMP_AN3(ADC_SAMPLING_SLOW) |
		ADC_SMPR2_SMP_AN4(ADC_SAMPLING_SLOW) |
		ADC_SMPR2_SMP_AN5(ADC_SAMPLING_SLOW) |
		ADC_SMPR2_SMP_AN6(ADC_SAMPLING_SLOW) |
		ADC_SMPR2_SMP_AN7(ADC_SAMPLING_SLOW) |
		ADC_SMPR2_SMP_AN8(ADC_SAMPLING_SLOW) |
		ADC_SMPR2_SMP_AN9(ADC_SAMPLING_SLOW),
	.htr	= 0,
	.ltr	= 0,
	// Simply sequence every channel in order
	.sqr1	= 0,
	.sqr2	= 0,
	.sqr3	= ADC_SQR3_SQ1_N(9),    // sample the channel with the switch connected
};

bool InRange(float min, float x, float max)
{
    return x > min && x < max;
}

static adcsample_t samples[oversample];

SwitchState SenseSwitch()
{
    adcConvert(&ADCD1, &convGroup, samples, oversample);

    uint32_t sum = 0;

    for (size_t i = 0; i < oversample; i++)
    {
        sum += samples[i];
    }

    // Resistor divider = 1.56
    // Supply voltage = 3.3
    // Max ADC count = 4096
    constexpr float ratio = 1.56f * 3.3f / (4096 * oversample);
    float volts = ratio * sum;

    // 2.7k pullup
    // roof down = 1k -> 1.351 volts
    // roof up = 2.2k -> 2.245 volts

    if (InRange(1.0f, volts, 1.7f))
    {
        return SwitchState::Down;
    }
    else if (InRange(1.8f, volts, 2.5f))
    {
        return SwitchState::Up;
    }
    else if (volts > 4.4f)
    {
        return SwitchState::None;
    }
    else
    {
        return SwitchState::Indeterminite;
    }
}
