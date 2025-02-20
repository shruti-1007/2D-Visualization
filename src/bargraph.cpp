#include <graphics.h>
#include <iostream>
#include <string>
#include "Algorithms/ddaAlgorithm.cpp"
#include "Algorithms/boundaryfill.cpp"
using namespace std;



void drawBarChart(int data[], string labels[], int n, string title, string yAxisLabel, string xAxisLabel) {
    int barWidth = 50; 
    int spaceBetweenBars = 10; 
    int originX = 100, originY = 400; 
    int maxHeight = 300; // 

    // Draw the X and Y axes using DDA
    drawDdaLine(originX, originY, originX + (n * (barWidth + spaceBetweenBars)), originY, BLACK); // X-Axis
    drawDdaLine(originX, originY, originX, originY - maxHeight, BLACK); // Y-Axis

    // Label Y-Axis
    for (int i = 0; i <= maxHeight; i += 50) {
        char label[10];
        sprintf(label, "%d", i);
        outtextxy(originX - 30, originY - i, label);
    }

    // Draw bars and their data
    for (int i = 0; i < n; i++) {
        int x1 = originX + i * (barWidth + spaceBetweenBars);
        int y1 = originY;
        int x2 = x1 + barWidth;
        int y2 = originY - data[i];

        // Draw the edges of the bars using DDA
        drawDdaLine(x1, y1, x1, y2, BLACK);  // Left edge
        drawDdaLine(x2, y1, x2, y2, BLACK);  // Right edge
        drawDdaLine(x1, y2, x2, y2, BLACK);  // Top edge

        // Apply Boundary Fill
        int fillX = (x1 + x2) / 2;  
        int fillY = (y1 + y2) / 2;
        boundaryFill(fillX, fillY, GREEN, BLACK);
        
        // Display data on top of bars
        char value[10];
        sprintf(value, "%d", data[i]);
        outtextxy(x1 + barWidth / 3, y2 - 20, value);
    }

    // Label X-Axis with categorical labels
    for (int i = 0; i < n; i++) {
        char labelBuffer[100];
        strcpy(labelBuffer, labels[i].c_str());
        outtextxy(originX + i * (barWidth + spaceBetweenBars) + barWidth / 3, originY + 10, labelBuffer);
    }

    // Add Title and Axis Labels
    settextstyle(SIMPLEX_FONT, HORIZ_DIR, 2);
    outtextxy(originX + (n * (barWidth + spaceBetweenBars)) / 3, originY - maxHeight - 60, const_cast<char*>(title.c_str()));

    // Y-Axis Label (Vertical)
    settextstyle(SIMPLEX_FONT, VERT_DIR, 2);
    outtextxy(originX - 70, originY - maxHeight / 2 + 30, const_cast<char*>(yAxisLabel.c_str()));

    // X-Axis Label (Horizontal)
    settextstyle(SIMPLEX_FONT, HORIZ_DIR, 2);
    outtextxy(originX + (n * (barWidth + spaceBetweenBars)) / 3, originY + 40, const_cast<char*>(xAxisLabel.c_str()));
}

void bargraph() {
    int n;
    cout << "Enter number of bars: ";
    cin >> n;

    int data[n];
    string labels[n];

    cout << "Enter the values for the bars: \n";
    for (int i = 0; i < n; i++) {
        cin >> data[i];
    }

    cout << "Enter categorical labels for the X-axis: \n";
    for (int i = 0; i < n; i++) {
        cout << "Label " << i + 1 << ": ";
        cin >> labels[i];
    }

    // User input for the title and labels
    string title, yAxisLabel, xAxisLabel;
    cout << "Enter the title for the chart: ";
    cin.ignore(); // Clear input buffer
    getline(cin, title);
    cout << "Enter the label for Y-axis: ";
    getline(cin, yAxisLabel);
    cout << "Enter the label for X-axis: ";
    getline(cin, xAxisLabel);

    drawBarChart(data, labels, n, title, yAxisLabel, xAxisLabel);
}
