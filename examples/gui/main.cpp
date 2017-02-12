#include <string>
#include <vector>
#include <utility>
#include <GL/glut.h>
#include <map>

// FSM includes
#include <simpleFsm/fsm.h>
#include <simpleFsm/state.h>

// glut infrastructure
#include "irenderer.h"
#include "glutrenderwin.h"
#include "baserenderer.h"
#include "ikeyboardhandler.h"
#include "menurenderer.h"
#include "inputconsole.h"

using namespace std;
using namespace simpleFsm;

class MenuItemSelected : public simpleFsm::State
{
public:
		MenuItemSelected(IFsm& fsm,
				MenuRenderer& renderer,
				int itemIndex) : State(fsm),
				m_renderer(renderer), ItemIndex(itemIndex)
		{ }

		virtual void Enter()
		{
				m_renderer.SelectItem(ItemIndex);
		}

private:
		const int ItemIndex;
		MenuRenderer& m_renderer;
};

class MainMenuFsm : public simpleFsm::Fsm
{
public:
		MainMenuFsm(IFsm& parent, InputConsole& inputConsole,
				vector<pair<string, shared_ptr<IState>>> inputItems) : simpleFsm::Fsm(parent, "MainMenu"),
				//m_nextAction(IDLE), 
				m_currInput(NONE),
				m_inputConsole(inputConsole)
		{

				vector<shared_ptr<IState>> menuStates;

				// create menu states
				unsigned int i = 0;
				for (auto& item : inputItems)
				{
						m_renderer.AddItem(item.first);
						menuStates.push_back(make_shared<MenuItemSelected>(*this, m_renderer, i++));
				}

				// create transitions
				i = 0;
				auto guardNext = [&] {return m_currInput == ConsoleInputType::DOWN; };
				auto guardPrev = [&] {return m_currInput == ConsoleInputType::UP; };
				auto guardSelect = [&] {return m_currInput == ConsoleInputType::SELECT; };
				for (auto& state : menuStates)
				{
						state->AddTransition(make_shared<Transition>(parent, inputItems[i].second, guardSelect));
						if (i > 0) {
								state->AddTransition(make_shared<Transition>(*this, menuStates[i - 1], guardPrev));
						}

						if (i < menuStates.size() - 1){
								state->AddTransition(make_shared<Transition>(*this, menuStates[i + 1], guardNext));
						}

						i++;
				}

				SetFirstState(menuStates[0]);
		}

		virtual void SetState(std::shared_ptr<IState> state)
		{
				simpleFsm::Fsm::SetState(state);
				m_currInput = NONE;
		}

		virtual void OnInput(ConsoleInputType input)
		{
				// we can consider this method like an interrrupt routine.
				// here we would respond to various top-level interrupts

				// if nothig urgent is done, we record the input so that 
				// it can be delt with properly by the current state
				m_currInput = input;
		}

		virtual void Enter()
		{
				GlutRenderWin::SetRenderer(&m_renderer);
				m_inputConsoleCbId = m_inputConsole.RegisterCallback([&](ConsoleInputType input) {m_currInput = input; });
				Fsm::Enter();
		}

private:

		//enum {NEXT, PREV, IDLE, SELECT} m_nextAction;
		ConsoleInputType m_currInput;
		InputConsole& m_inputConsole;
		MenuRenderer m_renderer;
		int m_inputConsoleCbId;
};

class NavigationFsm : public Fsm
{
public:
		NavigationFsm(IFsm& parent, InputConsole& inputConsole) : Fsm(parent, "Navigation")
		{
				m_renderer.AddItem("Navigation System");
				m_renderer.SelectItem(-1);
		}

		virtual void Enter()
		{
				GlutRenderWin::SetRenderer(&m_renderer);
				Fsm::Enter();
		}

private:
		MenuRenderer m_renderer;
};



class RadioFsm : public Fsm
{
public:
		RadioFsm(IFsm& parent, InputConsole& inputConsole) : Fsm(parent, "Radio")
		{
				m_renderer.AddItem("Radio");
				m_renderer.SelectItem(-1);
		}

		virtual void Enter()
		{
				GlutRenderWin::SetRenderer(&m_renderer);
				Fsm::Enter();
		}

private:
		MenuRenderer m_renderer;
};

class HMI : public simpleFsm::Fsm
{
public:

		HMI(InputConsole& inputConsole) : simpleFsm::Fsm("HMI")
		{
				auto navigation = make_shared<NavigationFsm>(*this, inputConsole);
				auto radio = make_shared<RadioFsm>(*this, inputConsole);

				auto mainMenu =
						make_shared<MainMenuFsm>(
						*this,
						inputConsole,
						vector < pair<string, shared_ptr<IState>> > {
						make_pair("navigation system", navigation),
								make_pair("radio", radio)
				});

				SetFirstState(mainMenu);
		}


};

int
main(int argc, char **argv)
{
		InputConsole inputConsole;
		HMI hmi(inputConsole);
		GlutRenderWin::Create(argc, argv, 800, 600, "test window",
				[&]{ hmi.Step(); /* glutPostRedisplay();*/ },
				nullptr,
				&inputConsole);

		return 0;
}


// todo: consider using exit() method to push current state on the stack
// todo: need top level interrupts to transition between screens