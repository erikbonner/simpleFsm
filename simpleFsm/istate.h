#ifndef ISTATE
#define ISTATE

#include "transition.h"

namespace simpleFsm
{
    /// \class IState
    /// \brief Interface to be implemented by all states in our system
    /// \author Erik Bonner
	class IState
	{
	public:
		/// \brief method to execute upon entering this state
		virtual void Enter() = 0;

		/// \brief apply the current state
		virtual bool Step() = 0;

		/// \brief add a transition to a neighbouring state
		virtual void AddTransition(std::shared_ptr<ITransition>) = 0;
	};

}


#endif // ISTATE

