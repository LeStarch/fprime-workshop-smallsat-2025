// ======================================================================
// \title  Led.cpp
// \author dragon-scales
// \brief  cpp file for Led component implementation class
// ======================================================================

#include "Components/Led/Led.hpp"

namespace Components {

// ----------------------------------------------------------------------
// Component construction and destruction
// ----------------------------------------------------------------------

Led ::Led(const char* const compName) : LedComponentBase(compName) {}

Led ::~Led() {}

// ----------------------------------------------------------------------
// Handler implementations for commands
// ----------------------------------------------------------------------

void Led ::BLINKING_ON_OFF_cmdHandler(FwOpcodeType opCode, U32 cmdSeq, Fw::On onOff) {
    this->m_toggleCounter = 0;               // Reset count on any successful command
    this->m_blinking = Fw::On::ON == onOff;  // Update blinking state

    // TODO: Emit an event SetBlinkingState to report the blinking state (onOff).
    // NOTE: This event will be added during the "Events" exercise.
    this->log_ACTIVITY_HI_SetBlinkingState(onOff);

    // TODO: Report the blinking state (onOff) on channel BlinkingState.
    // NOTE: This telemetry channel will be added during the "Telemetry" exercise.

    // Provide command response
    this->cmdResponse_out(opCode, cmdSeq, Fw::CmdResponse::OK);
}

}  // namespace Components
