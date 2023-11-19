//
// Created by jacob on 19/11/23.
//

#ifndef GUI_FRAMEWORK_CHARACTER_H
#define GUI_FRAMEWORK_CHARACTER_H
#include <iostream>
using namespace std;

class character {
    string letter;
    int letterX;
    int letterY;
    string background;
public:
    character(string c, int x, int y, string b) : letter(c),letterX(x), letterY(y), background(b) {}

    string draw(int x, int y) {
        return ((x == letterX) && y == letterY) ? letter : background;
    }
};
#endif //GUI_FRAMEWORK_CHARACTER_H
