// bresenham.cpp
#include <graphics.h>
#include <cmath>
#include <iostream>
using namespace std;
#include "bresenham.h"
// Bresenham's line drawing algorithm
 void bresenhamLine(int x1, int y1, int x2, int y2) {
    int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);
    int sx = x1 < x2 ? 1 : -1;
    int sy = y1 < y2 ? 1 : -1;
    int err = dx - dy;

    while (true) {
        putpixel(x1, y1, BLUE);  // Plot the pixel at the current point

        if (x1 == x2 && y1 ==y2) break;  // Exit condition

        int e2 = err * 2;
        if (e2 > -dy) {
            err -= dy;
            x1 += sx;
        }
        if (e2 < dx) {
            err += dx;
            y1 += sy;
        }
    }
}
