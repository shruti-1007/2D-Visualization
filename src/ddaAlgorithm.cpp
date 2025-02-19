#include <graphics.h>
#include <iostream>
#include <cmath>
#include "ddaAlgorithm.h"
void drawDdaLine(int x1, int y1, int x2, int y2, int color) {
    int dx = x2 - x1;
    int dy = y2 - y1;
    int steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy);
    float xInc = dx / float(steps);
    float yInc = dy / float(steps);
    float x = x1;
    float y = y1;

    setcolor(color); // Set the color for the line

    for (int i = 0; i <= steps; i++) {
        putpixel(int(x), int(y), color);
        x += xInc;
        y += yInc;
    }
}