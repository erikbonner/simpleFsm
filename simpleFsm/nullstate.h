#ifndef NULLSTATE
#define NULLSTATE

#include "state.h"
#include <string>
#include <iostream>

using namespace std;

namespace simpleFsm
{
    /// \class NullState
    /// \brief Special that performs a null-step (i.e does nothing).
    /// Used for transitioning in and out of StateMachines
    /// \author Erik Bonner
    class NullState : public State {
    public:
        /// \brief contstructor
        /// \param fsm the parent fsm of this state
        /// \param name the name of this state (helps with tracing)
        NullState(IFsm& fsm, std::string name) : State(fsm), m_name(name){}

        /// \brief A stub enter method
        virtual void Enter() { cout << "NullState (" << m_name << ")::Enter()" << endl; }
    private:
        std::string m_name;
    };

}

#endif // NULLSTATE

