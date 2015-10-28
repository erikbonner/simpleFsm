#ifndef TERMINATIONSTATE
#define TERMINATIONSTATE


#include "state.h"

namespace simpleFsm
{

/// \class TerminationState
/// \brief Special state used to terminate a state-machine.
/// Step functions returns false, which signals termination
/// \author Erik Bonner
class TerminationState : public State {
public:
    TerminationState(IFsm& fsm) : State(fsm){}
    virtual void Enter() {}
    virtual bool Step() { return false; }
};

}


#endif // TERMINATIONSTATE

