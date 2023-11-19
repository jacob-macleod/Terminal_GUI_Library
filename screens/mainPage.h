//
// Created by jacob on 19/11/23.
//

#ifndef GUI_FRAMEWORK_MAINPAGE_H
#define GUI_FRAMEWORK_MAINPAGE_H
#include <iostream>
#include "../widgets/screen.h"
#include "../widgets/character.h"
#include "../widgets/string.h"
using namespace std;

void mainPage() {
    screen page;
    character h("h", 15, 5, "\u001b[37;1m█\u001b[0m");
    // guiString(string s, screen p, int x, int y, string b) : str(s), page(p), strX(x), strY(y), background(b)
    guiString str ("Hello world! This is my message! I am typing this message to you!", page, 1, 0, "\u001b[37;1m█\u001b[0m", 10, 1);
    page.draw(str);
}
#endif //GUI_FRAMEWORK_MAINPAGE_H
