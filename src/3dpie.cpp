#include <graphics.h>
#include <stdio.h>
#include <math.h>
#include <iostream>
#include <string>
using namespace std;

#define M_PI 3.14159265358979323846

// Function to draw the pie chart with an elliptical transformation for 3D effect
void draw_elliptical_pie_chart(int values[], string categories[], int n, int cx, int cy, int radius) {
    int total = 0;
    for (int i = 0; i < n; i++) {
        total += values[i];
    }

    int start_angle = 0;
    int depth = 20;  // Height of the 3D effect

    for (int i = 0; i < n; i++) {
        int angle = (values[i] * 360) / total;
        int color = i + 1;
        setcolor(color);
        
        // Draw the pie slice with 3D effect
        for (int theta = start_angle; theta < start_angle + angle; theta++) {
            float x = cx + radius * cos(theta * M_PI / 180);
            float y = cy + radius * sin(theta * M_PI / 180);

            // Draw depth for 3D effect
            for (int j = 1; j <= depth; j++) {
                putpixel(x, y + j, color);
            }

            putpixel(x, y, color);
        }

        start_angle += angle;
    }
}

// Function to draw the legend at the right side
void draw_legend(string categories[], int n, int legend_x, int legend_y) {
    int box_size = 15;  // Size of color boxes
    int spacing = 25;   // Spacing between legend entries

    for (int i = 0; i < n; i++) {
        int color = i + 1;
        
        // Draw color box
        setfillstyle(SOLID_FILL, color);
        bar(legend_x, legend_y + i * spacing, legend_x + box_size, legend_y + i * spacing + box_size);
        
        // Draw text beside the color box
        setcolor(WHITE);
        outtextxy(legend_x + box_size + 10, legend_y + i * spacing + 3, (char*)categories[i].c_str());
    }
}

// Function to draw a 3D Pie Chart with a legend
void Draw3dpie() {
    int n;
    string title;

    cout << "Enter the title of the pie chart: ";
    cin.ignore();  // To avoid issues with getline()
    getline(cin, title);  // Allows spaces in the title

    cout << "Enter the number of slices: ";
    cin >> n;
    cin.ignore();  // To avoid issues with getline()

    int values[n];
    string categories[n];

    for (int i = 0; i < n; i++) {
        cout << "Enter category name for slice " << i + 1 << ": ";
        getline(cin, categories[i]);

        cout << "Enter value for slice " << i + 1 << ": ";
        cin >> values[i];
        cin.ignore();  // Ignore newline character for next getline()
    }



    setbkcolor(BLACK);
    cleardevice();

    int cx = getmaxx() / 2 - 50, cy = getmaxy() / 2;
    int radius = 150;

    // Display title
    setcolor(WHITE);
    outtextxy(cx - 100, cy - radius - 50, (char*)title.c_str()); // Moved title slightly up

    // Draw the 3D Pie Chart
    draw_elliptical_pie_chart(values, categories, n, cx, cy, radius);

    // Draw legend on the right side of the pie chart
    int legend_x = cx + radius + 60;  // Position legend slightly to the right
    int legend_y = cy - (n * 15);     // Adjust vertical alignment

    draw_legend(categories, n, legend_x, legend_y);

}
