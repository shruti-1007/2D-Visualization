#include <graphics.h>
#include <math.h>


void shearPoint(float &x, float &y, float shearX, float shearY, float cx) {
    // Apply skew transformation
    float newX = x + shearX * (y - cx);  // Keep the center aligned
    float newY = y + shearY * x;

    x = newX;
    y = newY;
}
