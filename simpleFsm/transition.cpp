#include "transition.h"
#include "ifsm.h"

namespace simpleFsm {

Transition::Transition(IFsm& fsm,
           std::shared_ptr<IState> target,
           std::function<bool()> guard) :
    m_fsm(fsm),
    m_target(target),
    m_guard(guard)
{

}


bool Transition::Apply()
{
    if(m_guard()){
        m_fsm.SetState(m_target);
        return true;
    }
    return false;
}
}
