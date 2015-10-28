#ifndef FSM_H
#define FSM_H

#include "ifsm.h"

#include <string>
#include <memory>


namespace simpleFsm
{

/// \class Fsm
/// \brief A standard implementation of the IFsm interface.
/// \author Erik Bonner
class Fsm : public IFsm
{

public:
    /// \brief constructor
    /// \param name the name of this state machine
	Fsm(std::string name);

    /// \brief constructor
    /// \param name the name of this state machine
    /// \param parent a reference to the parent of this state machine
	Fsm(IFsm& parent, std::string name);
	
    /// \copydoc IState::Step
    virtual bool Step();

    /// \copydoc IState::Enter
    virtual void Enter();

    /// \copydoc IState::SetState
    virtual void AddTransition(std::shared_ptr<ITransition> t);

    /// \copydoc IFsm::SetState
    virtual void SetState (std::shared_ptr<IState> state);

protected:
    /// \brief returns a reference to the state used as the endstate for this FSM
    virtual const IState& EndState() const;

    /// \brief Sets the state that will be transitioned into when the FSM starts
    void SetFirstState(std::shared_ptr<IState> state);

    std::shared_ptr<IState> m_currState;
    std::shared_ptr<IState> m_endState;
    std::shared_ptr<IState> m_startState;
    std::string m_name;

};

}
#endif // FSM_H
