
#include "ch.hpp"

class CanThread : public chibios_rt::BaseStaticThread<256>
{
public:
    CanThread(CANDriver& from, CANDriver& to);

    void main() override;

protected:
    virtual void handle(CANRxFrame& frame) = 0;

    void pass();

private:
    CANDriver* const m_from;
    CANDriver* const m_to;

    CANRxFrame m_rxFrame;
};

class CanThreadToRoof : public CanThread
{
public:
    CanThreadToRoof() : CanThread(CAND1, CAND2) { }

protected:
    void handle(CANRxFrame& frame) override;
};

class CanThreadToCar : public CanThread
{
public:
    CanThreadToCar() : CanThread(CAND2, CAND1) { }

protected:
    void handle(CANRxFrame& frame) override;
};
