#include <graphics.h>
#include <cmath>
#include <iostream>
#include <vector>
#include "bresenham.cpp"
#include "bresenham.h" 

using namespace std;


Point interpolate(Point P1, Point P2, float t) {
    Point result;
    result.x = (1 - t) * P1.x + t * P2.x;
    result.y = (1 - t) * P1.y + t * P2.y;
    return result;
}

Point generalizedBezier(vector<Point>& controlPoints, float t) {
    vector<Point> points = controlPoints;
    while (points.size() > 1) {
        vector<Point> newPoints;
        for (size_t i = 0; i < points.size() - 1; i++) {
            newPoints.push_back(interpolate(points[i], points[i + 1], t));
        }
        points = newPoints;
    }
    return points[0];
}

void drawBezierCurve(vector<Point>& controlPoints) {
    for (float t = 0; t <= 1; t += 0.0001) {
        Point pt = generalizedBezier(controlPoints, t);
        putpixel(pt.x, pt.y, BLUE);  // Directly plot the point for the curve
    }
}

void drawControlPoints(vector<Point>& controlPoints) {
    setcolor(RED);
    for (size_t i = 0; i < controlPoints.size(); i++) {
        circle(controlPoints[i].x, controlPoints[i].y, 5);  // Draw control points
        floodfill(controlPoints[i].x, controlPoints[i].y, RED);
    }

    setcolor(GREEN);
    for (size_t i = 0; i < controlPoints.size() - 1; i++) {
        // Passing two Point objects directly to Bresenham's line function
        bresenhamLine(controlPoints[i].x, controlPoints[i].y, controlPoints[i + 1].x, controlPoints[i + 1].y);
    }
}

void displayTitle() {
    setcolor(BLACK);
    settextstyle(SIMPLEX_FONT, HORIZ_DIR, 4);
    outtextxy(200, 20, (char*)"Your Bezier Curve");
}

void drawBezier() {
    int numPoints;
    cout << "Enter the number of control points: ";
    cin >> numPoints;

    vector<Point> controlPoints(numPoints);

    cout << "Enter the coordinates for the control points of the Bézier curve:\n";
    for (int i = 0; i < numPoints; i++) {
        cout << "Control Point P" << i << ": ";
        cin >> controlPoints[i].x >> controlPoints[i].y;
    }

    displayTitle();
    drawBezierCurve(controlPoints);
    drawControlPoints(controlPoints);
}


