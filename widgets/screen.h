//
// Created by jacob on 19/11/23.
//

#ifndef GUI_FRAMEWORK_SCREEN_H
#define GUI_FRAMEWORK_SCREEN_H
#include <iostream>
using namespace std;

class screen {
    string background;
public:
    int width;
    int height;
    screen(int w = 20, int h = 20, string b = "\u001b[37;1m█\u001b[0m") : width(w), height(h), background(b) {}

    template <class T>
    void draw (T &widget) {
        for (int x = 0; x < width; x++) {
            for (int y = 0; y < height; y ++) {
                cout << widget.draw(x, y);
            }
            cout << endl;
        }
    }
};

#endif //GUI_FRAMEWORK_SCREEN_H
