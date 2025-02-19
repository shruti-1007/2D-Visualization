#include <graphics.h>
#include <stdio.h>
#include <math.h>
#include "transformations.cpp"  

#define M_PI 3.14159265358979323846

// Function to draw the pie chart with an elliptical transformation for 3D effect
void draw_elliptical_pie_chart(int values[], int n, int cx, int cy, int radius) {
    int total = 0;
    for (int i = 0; i < n; i++) {
        total += values[i];
    }

    int start_angle = 0;
    int depth = 20;  // Height of the 3D lines
    for (int i = 0; i < n; i++) {
        int angle = (values[i] * 360) / total;
        
        for (int theta = start_angle; theta < start_angle + angle; theta++) {
            float x = cx + (radius * cos(theta * M_PI / 180));
            float y = cy + radius * sin(theta * M_PI / 180);

            // Apply skew transformation
            skewPoint(x, y, 0.1, 0, cx);  // Skew in the X-direction

            int color = i + 1;
            setcolor(color);

            for (int j = 1; j <= depth; j++) {
                putpixel(x, y - j, color);
            }
        }

        start_angle += angle;
    }
}

// Function to simulate a 3D effect by rotating the pie chart
void Draw3dpie() {
    int n;
    printf("Enter the number of slices: ");
    scanf("%d", &n);
    
    int values[n];
    for (int i = 0; i < n; i++) {
        printf("Enter value for slice %d: ", i + 1);
        scanf("%d", &values[i]);
    }

    int gd = DETECT, gm;
    initgraph(&gd, &gm, (char*)"");

    int cx = getmaxx() / 2, cy = getmaxy() / 2;
    int radius = 150;

    draw_elliptical_pie_chart(values, n, cx, cy, radius);
}

