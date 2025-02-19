#include <graphics.h> // Ensure graphics.h is included in your project

// Flood Fill Algorithm (4-connected)
void floodFill(int x, int y, int fillColor, int borderColor) {
    // Get the color of the current pixel
    int currentColor = getpixel(x, y);
    
    // Check if the current pixel is not the border color and not already filled
    if (currentColor != borderColor && currentColor != fillColor) {
        // Fill the pixel with the fill color
        putpixel(x, y, fillColor);
        
        // Recursively fill the 4-connected pixels
        floodFill(x + 1, y, fillColor, borderColor); // Right
        floodFill(x - 1, y, fillColor, borderColor); // Left
        floodFill(x, y + 1, fillColor, borderColor); // Bottom
        floodFill(x, y - 1, fillColor, borderColor); // Top
    }
}