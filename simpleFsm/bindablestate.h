#ifndef BINDABLESTATE
#define BINDABLESTATE


#include "state.h"

namespace simpleFsm
{
/// \class BindableState
/// \brief Special state where the entry function can be specified externally as a std::function
/// \author Erik Bonner
class BindableState : public State {
public:
    /// \brief constructor
    /// \param fsm the FSM to which this state belongs
    /// \param enter the callback to use when state is entered
    BindableState(IFsm& fsm, std::function<void()> enter) : State(fsm), m_enter(enter){}

    /// \copydoc IState::Enter
    virtual void Enter() { m_enter(); }

protected:
    std::function<void()> m_enter;
};

}

#endif // BINDABLESTATE

