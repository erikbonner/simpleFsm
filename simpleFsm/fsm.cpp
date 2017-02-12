#include "fsm.h"
#include "nullstate.h"
#include "terminationstate.h"

#include <memory>

using namespace std;

namespace simpleFsm
{

Fsm::Fsm(IFsm& parent, string name) : Fsm(name)
{
	//  in this case, our ennd state will update the state of our parent
    m_endState = make_shared<NullState>(parent, "Fsm::EndState");
}


Fsm::Fsm(string name) : m_name(name)
{
	m_startState = make_shared<NullState>(*this, "Fsm::StartState");
	m_endState = make_shared<TerminationState>(*this);
	m_currState = m_startState;
}

bool Fsm::Step()
{
    return m_currState->Step();
}

void Fsm::SetState (shared_ptr<IState> state)
{
    state->Enter();
    m_currState = state;
}

void Fsm::AddTransition(std::shared_ptr<ITransition> t)
{
    m_endState->AddTransition(t);
}

const IState& Fsm::EndState() const
{
    return *m_endState;
}

void Fsm::Enter()
{
    cout << m_name << "::Enter() " << endl; SetState(m_startState);
}

void Fsm::SetFirstState(std::shared_ptr<IState> state)
{
    m_startState->AddTransition(make_shared<Transition>(*this, state));
}

}

