#ifndef IFSM
#define IFSM

#include "istate.h"
#include <memory>

namespace simpleFsm
{

    /// \class IFsm
    /// \brief Represents a Finite State Machine.
    /// A finite state machine is itself a state (hence the inheritance from IState)
    /// The difference between a FSM and a simple state is that a FSM itself contains states.
    /// \author Erik Bonner
	class IFsm : public IState
	{
	public:
		/// \brief set the state of teh current stat machine
		virtual void SetState(std::shared_ptr<IState>) = 0;
	};

}



#endif // IFSM

