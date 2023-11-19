//
// Created by jacob on 19/11/23.
//

#ifndef GUI_FRAMEWORK_STRING_H
#define GUI_FRAMEWORK_STRING_H
#include <iostream>
#include <cstring>
#include "screen.h"
using namespace std;
class guiString {
    // The string being displayed
    string str;
    char * strArr;
    // The background of the page
    string background;
    // The page being displayed to
    screen page;
    // The width and height of the page
    int pageWidth;
    // The x and y locations the string will be drawn at
    int strX;
    int strY;
    // The start x position of each line
    int startX;

    // Even indexes indicate x coords, and odd index indicate y coords
    int *letterPositions;
    // Stores the number of letters in str
    int letters = 0;

public:
    guiString(string s, screen p, int x, int y, string b, int w = -1, int strtX = 0) : str(s), page(p), strX(x), strY(y), background(b), pageWidth(w), startX(strtX) {
        if (pageWidth == -1)
            pageWidth = page.width;
        str = str.c_str();
        int num = 0;
        int currentX = x;
        int currentY = y;
        // The index of letterPositions being set
        int index = 0;

        // Copy str to strArr
        strArr = new char[str.length() + 1];
        strcpy(strArr, str.c_str());

        // Count the letters in the string
        for (char letter : str)
            letters ++;

        letterPositions = new int[letters * 2];

        // For each letter in the string
        for (char letter : str) {
            // If the x coordinate is not too big
            if (currentX < pageWidth) {
                *(letterPositions + index) = currentX;
                *(letterPositions + index + 1) = currentY;
                currentX ++;
                index += 2;
            } else {
                // Start at the next line
                currentY += 1;
                currentX = startX;
                *(letterPositions + index) = currentX;
                *(letterPositions + index + 1) = currentY;
                currentX ++;
                index += 2;
            }
        }
    }

    string draw(int x, int y) {
        // The x and y of each square is passed to this function
        // The function decides whether to draw the string, which part to draw, or whether to draw the background
        // letterPositions stores all the avaliable index locations to draw a string

        // For every letter
        for (int i = 0; i < letters; i ++) {
            // If its x and y coords are in letter positions
            if (*(letterPositions + (i*2)) == y && *(letterPositions + (i*2) + 1) == x) {
                cout << strArr[i];
                return "";
            }
        }
        return background;
    }
};
#endif //GUI_FRAMEWORK_STRING_H
