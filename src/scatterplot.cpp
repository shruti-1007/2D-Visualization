#include <graphics.h>
#include <iostream>
#include <cmath>
#include <conio.h>
#include <vector>
#include "bresenham.h"
#include "midpointcircle.h"
#include "floodfill.cpp"
using namespace std;

void scatterPlot() {
    int num_points;
    cout << "Enter the number of data points: ";
    cin >> num_points;

    vector<Point> points(num_points);
    for (int i = 0; i < num_points; i++) {
        cout << "Enter x and y coordinates for point " << i + 1 << ": ";
        cin >> points[i].x >> points[i].y;
    }

    char x_label[50], y_label[50];
    cout << "Enter the x-axis label: ";
    cin >> x_label;
    cout << "Enter the y-axis label: ";
    cin >> y_label;
    char title[100];
cout << "Enter the title of the scatter plot: ";
cin.ignore();  // To clear the newline from previous input
cin.getline(title, 100);


    // Find min and max values for scaling
    int x_min = points[0].x, x_max = points[0].x, y_min = points[0].y, y_max = points[0].y;
    for (int i = 0; i < num_points; i++) {
        if (points[i].x < x_min) x_min = points[i].x;
        if (points[i].x > x_max) x_max = points[i].x;
        if (points[i].y < y_min) y_min = points[i].y;
        if (points[i].y > y_max) y_max = points[i].y;
    }

    // Define plot area margins
    int left_margin = 100;
    int right_margin = getmaxx() - 100;
    int top_margin = 80;
    int bottom_margin = getmaxy() - 80;
    int plot_width = right_margin - left_margin;
    int plot_height = bottom_margin - top_margin;

    // Draw X and Y axes using DDA algorithm
    setcolor(BLACK);
    bresenhamLine(left_margin, bottom_margin, right_margin, bottom_margin, BLACK); // X-Axis
    bresenhamLine(left_margin, bottom_margin, left_margin, top_margin, BLACK); // Y-Axis

    setcolor(GREEN);
   // Set Y-axis label (Vertical)
settextstyle(SIMPLEX_FONT, VERT_DIR, 1);
outtextxy(left_margin - 70, (top_margin + bottom_margin) / 2, y_label);

// Reset text style for normal text
settextstyle(SIMPLEX_FONT, HORIZ_DIR, 1);

// Set X-axis label (Centered)
outtextxy((left_margin + right_margin) / 2, bottom_margin + 40, x_label);
    // Y-Axis Label

    // Display title at the top-center
    setcolor(BLACK);
    settextstyle(SANS_SERIF_FONT, HORIZ_DIR, 2);

    outtextxy(getmaxx() / 2 - textwidth(title) / 2, top_margin - 40, title);
 

    // Draw X and Y axis ticks and labels
    for (int i = 0; i <= 10; i++) {
        settextstyle(SANS_SERIF_FONT, HORIZ_DIR, 1);
        int x_tick = left_margin + (i * plot_width / 10);
        int y_tick = bottom_margin;
        line(x_tick, y_tick, x_tick, y_tick + 10);

        char label[10];
        sprintf(label, "%d", x_min + i * (x_max - x_min) / 10);
        outtextxy(x_tick - 10, y_tick + 20, label);
    }

    for (int i = 0; i <= 10; i++) {
        int x_tick = left_margin;
        int y_tick = bottom_margin - (i * plot_height / 10);
        line(x_tick, y_tick, x_tick - 10, y_tick);

        char label[10];
        sprintf(label, "%d", y_min + i * (y_max - y_min) / 10);
        outtextxy(x_tick - 40, y_tick - 10, label);
    }

    // Plot points on the graph
    for (int i = 0; i < num_points; i++) {
        int x = points[i].x;
        int y = points[i].y;

        // Scale the points to fit in the plot area
        int x_range = x_max - x_min;
        int y_range = y_max - y_min;

        if (x_range == 0) x_range = 1;
        if (y_range == 0) y_range = 1;

        int screen_x = left_margin + (x - x_min) * plot_width / x_range;
        int screen_y = bottom_margin - (y - y_min) * plot_height / y_range;

        // Draw the point
        drawCircle(screen_x, screen_y, 3, RED);
        floodFill(screen_x, screen_y, GREEN, RED); // Add flood fill inside the circle
    }
}