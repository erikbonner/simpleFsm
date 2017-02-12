#include "state.h"

#include "itransition.h"

using namespace std;
namespace simpleFsm
{

// ctor
State::State(IFsm& fsm) : m_fsm(fsm)
{
}

void State::AddTransition(shared_ptr<ITransition> t)
{
    m_transitions.push_back(t);
}

bool State::Step()
{
    for(auto t : m_transitions){
//        if(t->Guard())
//        {
//            m_fsm.SetState(t->TargetState());
//            break;
//        }
        if(t->Apply()){ break; }
    }
    return true;
}

}
