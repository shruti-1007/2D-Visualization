#include <graphics.h>
#include <math.h>


void skewPoint(float &x, float &y, float skewFactorX, float skewFactorY, float cx) {
    // Apply skew transformation
    float newX = x + skewFactorX * (y - cx);  // Keep the center aligned
    float newY = y + skewFactorY * x;

    x = newX;
    y = newY;
}
