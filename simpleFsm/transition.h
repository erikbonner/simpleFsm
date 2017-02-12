#ifndef TRANSITION_H
#define TRANSITION_H


#include <memory>
#include <functional>

#include "itransition.h"

namespace simpleFsm {

	class IState;
    class IFsm;
	
	/// \class Transition
	/// \brief Concrete implementation of ITransition
	/// \author Erik Bonner
	class Transition : public ITransition
	{
	public:
		/// \brief constructor
		/// \param target the target state for this transtion
		/// \param guard a function that guards this transtion, i.e only when it returs true are we
		///		allowed to perform the transition. 
        Transition(IFsm& fsm,
                   std::shared_ptr<IState> target,
                   std::function<bool()> guard = [] { return true; });

        /// \copydoc ITranstion::Apply
        virtual bool Apply();

//		/// \copydoc ITranstion::TargetState
//		virtual std::shared_ptr<IState> TargetState() { return m_target; }

//		/// \copydoc ITranstion::Guard
//		virtual bool Guard() { return m_guard(); }

	protected:
        IFsm& m_fsm;
		std::shared_ptr<IState> m_target;
		std::function<bool()> m_guard;
	};

}


#endif // TRANSITION_H
