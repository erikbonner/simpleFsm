#include <map>
#include <functional>

#include "ikeyboardhandler.h"

typedef enum { NONE, SELECT, UP, DOWN } ConsoleInputType;

class InputConsole : public IKeyboardHandler
{
public:
		int RegisterCallback(std::function<void(ConsoleInputType)> cb);
		void UnregisterCallback(int id);

		virtual void HandleKeyboard(unsigned char ch, int x, int y);
		virtual void HandleSpecialKeyboard(int key, int x, int y);

private:
		static int s_nextId;
		typedef std::map<int, std::function<void(ConsoleInputType)>> CallbackMap;
		CallbackMap m_callbackMap;
};