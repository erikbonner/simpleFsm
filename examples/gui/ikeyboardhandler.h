#ifndef IKEYBOARDHANDLER
#define IKEYBOARDHANDLER

class IKeyboardHandler
{
public:
    virtual void HandleKeyboard(unsigned char, int, int) = 0;
    virtual void HandleSpecialKeyboard(int, int, int) = 0;
};

#endif // IKEYBOARDHANDLER

