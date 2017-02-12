#ifndef ITRANSITION
#define ITRANSITION

#include <memory>

namespace simpleFsm {

	class IState;

    /// \class ITransition
    /// \brief Interface representation a transition (connection between states)
    /// \author Erik Bonner
	class ITransition
	{
	public:
//		/// \brief State to which this transition points
//		virtual std::shared_ptr<IState> TargetState() = 0;

//		/// \brief Guard method: only when this returns true are we allowed to apply transition.
//		virtual bool Guard() = 0;

        /// \brief apply the current transtion
        /// \returns true if transtion was made
        virtual bool Apply() = 0;
	};

}

#endif // ITRANSITION

