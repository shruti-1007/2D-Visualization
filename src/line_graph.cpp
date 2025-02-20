#include <graphics.h>
#include <iostream>
#include <cmath>
#include <conio.h>
#include <vector>
#include "Algorithms/bresenham.h"
#include "Algorithms/midpointcircle.h"
#include "Algorithms/floodfill.cpp"
using namespace std;

void lineGraph() {
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
    char title[1000];
    cout << "Enter the title of the line graph: ";
    cin.ignore();  // Clear the input buffer
    cin.getline(title, 1000);  // Get the title correctly
    

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
   
    //Set X and Y axis labels
    setcolor(GREEN);

    settextstyle(SIMPLEX_FONT, VERT_DIR, 1);
    outtextxy(left_margin - 70, (top_margin + bottom_margin) / 2, y_label);

    settextstyle(SIMPLEX_FONT, HORIZ_DIR, 1);
    outtextxy((left_margin + right_margin) / 2, bottom_margin + 40, x_label);

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
        outtextxy(x_tick - textwidth(label) / 2, y_tick + 25, label); // Moved 5 more down
    }

    for (int i = 0; i <= 10; i++) {
        int x_tick = left_margin;
        int y_tick = bottom_margin - (i * plot_height / 10);
        line(x_tick, y_tick, x_tick - 10, y_tick);

        char label[10];
        sprintf(label, "%d", y_min + i * (y_max - y_min) / 10);
        outtextxy(x_tick - 20, y_tick - 10, label); // Y-tick labels remain in the same place
    }

    // Plot the points and draw lines between them
    for (int i = 0; i < num_points - 1; i++) {
        // Scale the points to fit in the plot area
        int x_range = x_max - x_min;
        int y_range = y_max - y_min;

        if (x_range == 0) x_range = 1;
        if (y_range == 0) y_range = 1;

        int screen_x1 = left_margin + (points[i].x - x_min) * plot_width / x_range;
        int screen_y1 = bottom_margin - (points[i].y - y_min) * plot_height / y_range;

        int screen_x2 = left_margin + (points[i + 1].x - x_min) * plot_width / x_range;
        int screen_y2 = bottom_margin - (points[i + 1].y - y_min) * plot_height / y_range;

        // Draw the line between the points
        setcolor(RED);
        bresenhamLine(screen_x1, screen_y1, screen_x2, screen_y2, RED);
    }

    // Optionally, mark the points with small circles (if needed)
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

        // Draw the point (Circle) on the graph
        drawCircle(screen_x, screen_y, 3, BLUE);
        floodFill(screen_x, screen_y, GREEN, BLUE); 
    }
}
