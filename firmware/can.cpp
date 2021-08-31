#include "hal.h"

#include "can.h"

#include <cstring>

static const CANConfig canConfig500 =
{
	CAN_MCR_ABOM | CAN_MCR_AWUM | CAN_MCR_TXFP,
	CAN_BTR_SJW(0) | CAN_BTR_BRP(5) | CAN_BTR_TS1(10) | CAN_BTR_TS2(1)
};

CanThreadToRoof toRoof;
CanThreadToCar toCar;

void initCan()
{
	palSetPadMode(GPIOD, 0, PAL_MODE_ALTERNATE(9));
	palSetPadMode(GPIOD, 1, PAL_MODE_ALTERNATE(9));
	palSetPadMode(GPIOB, 12, PAL_MODE_ALTERNATE(9));
	palSetPadMode(GPIOB, 13, PAL_MODE_ALTERNATE(9));

	canStart(&CAND1, &canConfig500);
	canStart(&CAND2, &canConfig500);

	toRoof.start(NORMALPRIO + 11);
	toCar.start(NORMALPRIO + 10);
}

CanThread::CanThread(CANDriver& from, CANDriver& to)
	: m_from(&from)
	, m_to(&to)
{
}

void CanThread::main()
{
	while (true)
	{
		// get a frame
		canReceiveTimeout(m_from, 0, &m_rxFrame, TIME_INFINITE);

		// handle it
		handle(m_rxFrame);
	}
}

void CanThread::pass()
{
	CANTxFrame tx;

	if (m_rxFrame.IDE)
	{
		tx.EID = m_rxFrame.EID;
		tx.IDE = 1;
	}
	else
	{
		tx.SID = m_rxFrame.SID;
		tx.IDE = 0;
	}

	uint8_t dlc = m_rxFrame.DLC;
	tx.DLC = dlc;

	// plop data in place
	memcpy(&tx.data8[0], &m_rxFrame.data8[0], dlc);

	canTransmitTimeout(m_to, 0, &tx, TIME_INFINITE);
}

void CanThreadToRoof::handle(const CANRxFrame& frame)
{
	pass();
}

void CanThreadToCar::handle(const CANRxFrame& frame)
{
	if (frame.EID == 0x172)
	{
		// TODO: process roof status message from roof -> dash
	}

	pass();
}
