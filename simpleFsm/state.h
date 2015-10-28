#ifndef STATE_H
#define STATE_H

#include "istate.h"
#include "ifsm.h"

#include <vector>

namespace simpleFsm
{

/// \class State
/// \brief Base implementation of IState
/// Defines behaviour common to most states in the system.
/// \author Erik Bonner
class State : public IState {
public:
    /// \brief constructor
    /// \param fsm a reference to the FSM to which this state belongs
    State(IFsm& fsm);

    /// \copydoc IState::AddTransition
    virtual void AddTransition(std::shared_ptr<ITransition> t);

    /// \copydoc IState::Step
    virtual bool Step();

protected:
    IFsm& m_fsm;
    std::vector<std::shared_ptr<ITransition>> m_transitions;
};

}

#endif // STATE_H
