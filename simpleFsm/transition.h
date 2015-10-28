#ifndef TRANSITION_H
#define TRANSITION_H


#include <memory>
#include <functional>

#include "itransition.h"

namespace simpleFsm {

	class IState;
	
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
		Transition(std::shared_ptr<IState> target, std::function<bool()> guard = [] { return true; }) :
			m_target(target), m_guard(guard) {}

		/// \copydoc ITranstion::TargetState
		virtual std::shared_ptr<IState> TargetState() { return m_target; }

		/// \copydoc ITranstion::Guard
		virtual bool Guard() { return m_guard(); }

	protected:
		std::shared_ptr<IState> m_target;
		std::function<bool()> m_guard;
	};

}


#endif // TRANSITION_H
