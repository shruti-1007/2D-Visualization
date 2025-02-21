#include <graphics.h>
#include <iostream>
#include <cmath>
#include <conio.h>
#include <vector>
#include <string>
#include "Algorithms/bresenham.h"
#include "Algorithms/midpointcircle.h"
#include "Algorithms/floodfill.h"
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

    cin.ignore(); // To clear any leftover newline characters

    string x_label, y_label, title;
    cout << "Enter the x-axis label: ";
    getline(cin, x_label);
    cout << "Enter the y-axis label: ";
    getline(cin, y_label);
    cout << "Enter the title of the scatter plot: ";
    getline(cin, title);

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

    // Draw X and Y axes using Bresenham's algorithm
    setcolor(BLACK);
    bresenhamLine(left_margin, bottom_margin, right_margin, bottom_margin, BLACK); // X-Axis
    bresenhamLine(left_margin, bottom_margin, left_margin, top_margin, BLACK); // Y-Axis

    // X-Axis Label (Centered below X-Axis)
    setcolor(GREEN);
    settextstyle(SIMPLEX_FONT, HORIZ_DIR, 1);
    char* x_label_cstr = new char[x_label.length() + 1];
    strcpy(x_label_cstr, x_label.c_str());
    outtextxy((left_margin + right_margin) / 2 - textwidth(x_label_cstr) / 2, bottom_margin + 40, x_label_cstr);
    delete[] x_label_cstr;

    // Y-Axis Label (Vertical on the left side)
    setcolor(GREEN);
    settextstyle(SIMPLEX_FONT, VERT_DIR, 1);
    char* y_label_cstr = new char[y_label.length() + 1];
    strcpy(y_label_cstr, y_label.c_str());
    outtextxy(left_margin - 55, (top_margin + bottom_margin) / 2 + 10, y_label_cstr);
    delete[] y_label_cstr;

    // Title (Centered at the top)
    setcolor(BLACK);
    settextstyle(SANS_SERIF_FONT, HORIZ_DIR, 2);
    char* title_cstr = new char[title.length() + 1];
    strcpy(title_cstr, title.c_str());
    outtextxy(getmaxx() / 2 - textwidth(title_cstr) / 2, top_margin - 40, title_cstr);
    delete[] title_cstr;

    // Draw X and Y axis ticks and labels
    for (int i = 0; i <= 10; i++) {
        settextstyle(SANS_SERIF_FONT, HORIZ_DIR, 1);
        int x_tick = left_margin + (i * plot_width / 10);
        int y_tick = bottom_margin;
        line(x_tick, y_tick, x_tick, y_tick + 10);

        char label[10];
        sprintf(label, "%d", x_min + i * (x_max - x_min) / 10);
        outtextxy(x_tick - textwidth(label) / 2, y_tick + 25, label); // X-axis labels
    }

    for (int i = 0; i <= 10; i++) {
        int x_tick = left_margin;
        int y_tick = bottom_margin - (i * plot_height / 10);
        line(x_tick, y_tick, x_tick - 10, y_tick);

        char label[10];
        sprintf(label, "%d", y_min + i * (y_max - y_min) / 10);
        outtextxy(x_tick - textwidth(label) - 15, y_tick - textheight(label) / 2, label); // Y-axis labels
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
