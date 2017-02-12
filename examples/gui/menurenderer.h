#ifndef MENURENDERER_H
#define MENURENDERER_H

#include <vector>
#include <string>

#include "baserenderer.h"

class MenuRenderer : public BaseRenderer {
public:

    enum Color{Red, Green, White};

    MenuRenderer();
    MenuRenderer(std::vector<std::string> menuItems);

    void Display(void);
    void SelectItem(int index);
    void AddItem(std::string item);

private:
    void DrawString(int x, int y, std::string str, Color color=White);
    void SelectColor(Color color);

    std::vector<std::string> m_menuItems;
    void *m_font;
    int m_selectedItem;
};
#endif // MENURENDERER_H
