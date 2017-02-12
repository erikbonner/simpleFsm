#include "inputconsole.h"

#include <GL/glut.h>


int InputConsole::s_nextId = 0;


int InputConsole::RegisterCallback(std::function<void(ConsoleInputType)> cb) 
{
		// note: the following code is not threadsafe!
		m_callbackMap.emplace(++s_nextId, cb); 
		return s_nextId;
}

void InputConsole::UnregisterCallback(int id) 
{ 
		m_callbackMap.erase(id); 
}

void InputConsole::HandleKeyboard(unsigned char ch, int x, int y)
{
		switch (ch) {
		case (char)13: for (auto it : m_callbackMap) it.second(SELECT); break;
		default: break;
		}
}

void InputConsole::HandleSpecialKeyboard(int key, int x, int y)
{
		switch (key) {
		case GLUT_KEY_UP: for (auto it : m_callbackMap) it.second(UP); break;
		case GLUT_KEY_DOWN: for (auto it : m_callbackMap) it.second(DOWN); break;
		default: break;
		}
}
