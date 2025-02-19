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

    char x_label[50], y_label[50], title[100];
    cout << "Enter the x-axis label: ";
    cin >> x_label;
    cout << "Enter the y-axis label: ";
    cin >> y_label;
    cout << "Enter the title of the scatter plot: ";
    cin.ignore();
    cin.getline(title, 100);

    // Find min and max values for scaling
    int x_min = points[0].x, x_max = points[0].x, y_min = points[0].y, y_max = points[0].y;
    for (int i = 0; i < num_points; i++) {
        x_min = min(x_min, points[i].x);
        x_max = max(x_max, points[i].x);
        y_min = min(y_min, points[i].y);
        y_max = max(y_max, points[i].y);
    }

    // Define plot area margins
    int left_margin = 100, right_margin = getmaxx() - 80;
    int top_margin = 80, bottom_margin = getmaxy() - 80;
    int plot_width = right_margin - left_margin;
    int plot_height = bottom_margin - top_margin;

    // Draw X and Y axes
    setcolor(BLACK);
    bresenhamLine(left_margin, bottom_margin, right_margin, bottom_margin, BLACK);
    bresenhamLine(left_margin, bottom_margin, left_margin, top_margin, BLACK);

    setcolor(BLUE);
    settextstyle(SIMPLEX_FONT, VERT_DIR, 1);
    outtextxy(left_margin - 60, (top_margin + bottom_margin) / 2, y_label);  // Y-axis label

    settextstyle(SIMPLEX_FONT, HORIZ_DIR, 1);
    outtextxy((left_margin + right_margin) / 2, bottom_margin + 30, x_label); // X-axis label

    // Title
    setcolor(BLACK);
    settextstyle(SIMPLEX_FONT, HORIZ_DIR, 2);
    outtextxy(getmaxx() / 2 - textwidth(title) / 2, top_margin - 20, title);

    // Adjusted axis scaling to avoid overlap
    for (int i = 0; i <= 5; i++) {  // Reduced number of ticks
        int x_tick = left_margin + (i * plot_width / 5);
        int y_tick = bottom_margin;
        line(x_tick, y_tick, x_tick, y_tick + 5);

        char label[10];
        sprintf(label, "%d", x_min + i * (x_max - x_min) / 5);
        outtextxy(x_tick - 10, y_tick + 10, label);
    }

    for (int i = 0; i <= 5; i++) {
        int y_tick = bottom_margin - (i * plot_height / 5);
        line(left_margin, y_tick, left_margin - 5, y_tick); // Shorter tick closer to axis

        char label[10];
        sprintf(label, "%d", y_min + i * (y_max - y_min) / 5);
        outtextxy(left_margin - 35, y_tick - 5, label);  // Positioned closer to axis
    }

    // Plot points
    for (int i = 0; i < num_points; i++) {
        int x = points[i].x, y = points[i].y;

        int screen_x = left_margin + (x - x_min) * plot_width / (x_max - x_min + 1);
        int screen_y = bottom_margin - (y - y_min) * plot_height / (y_max - y_min + 1);

        drawCircle(screen_x, screen_y, 3, RED);
        floodFill(screen_x, screen_y, GREEN, RED);
    }
}
