#include <graphics.h>
#include "midpointcircle.h"
void drawCircle(int centerX, int centerY, int radius, int color) {
    int x = radius;
    int y = 0;
    int decisionOver2 = 1 - x;  // Initial decision parameter

    // Draw initial points on the circle
    putpixel(centerX + x, centerY + y, color); // Right
    putpixel(centerX - x, centerY + y, color); // Left
    putpixel(centerX + x, centerY - y, color); // Bottom-right
    putpixel(centerX - x, centerY - y, color); // Bottom-left
    putpixel(centerX + y, centerY + x, color); // Top-right
    putpixel(centerX - y, centerY + x, color); // Top-left
    putpixel(centerX + y, centerY - x, color); // Bottom-top-right
    putpixel(centerX - y, centerY - x, color); // Bottom-top-left

    // Continue drawing points using the Midpoint algorithm
    while (x > y) {
        y++;
        
        // Update the decision variable
        if (decisionOver2 <= 0) {
            decisionOver2 += 2 * y + 1;  // Midpoint is inside or on the circle
        } else {
            x--;
            decisionOver2 += 2 * (y - x) + 1;  // Midpoint is outside the circle
        }

        // Draw points in all 8 octants
        putpixel(centerX + x, centerY + y, color);
        putpixel(centerX - x, centerY + y, color);
        putpixel(centerX + x, centerY - y, color);
        putpixel(centerX - x, centerY - y, color);
        putpixel(centerX + y, centerY + x, color);
        putpixel(centerX - y, centerY + x, color);
        putpixel(centerX + y, centerY - x, color);
        putpixel(centerX - y, centerY - x, color);
    }
}
