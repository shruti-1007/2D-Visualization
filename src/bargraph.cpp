#include <graphics.h>
#include <iostream>
#include <string>
#include "ddaAlgorithm.cpp"
using namespace std;

// Function to draw the bar chart
void drawBarChart(int data[], string labels[], int n, string title, string yAxisLabel, string xAxisLabel) {
    int barWidth = 50; // width of each bar
    int spaceBetweenBars = 10; // space between each bar
    int originX = 100, originY = 400; // origin of the graph
    int maxHeight = 300; // maximum height of the bars (for scaling)

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

        // Draw the edges of the bars (using DDA line)
        drawDdaLine(x1, y1, x1, y2, GREEN);  // Left edge of the bar
        drawDdaLine(x2, y1, x2, y2, GREEN);  // Right edge of the bar
        drawDdaLine(x1, y2, x2, y2, GREEN);  // Bottom edge of the bar

        // Fill the bar with a color (Green)
        for (int y = y2; y < y1; y++) {
            for (int x = x1; x < x2; x++) {
                putpixel(x, y, GREEN); // Filling the bar with green
            }
        }

        // Show data on top of the bars
        char value[10];
        sprintf(value, "%d", data[i]);
        outtextxy(x1 + barWidth / 3, y2 - 20, value); // Position the text above the bar
    }

    // Label X-Axis with categorical labels
    for (int i = 0; i < n; i++) {
        char labelBuffer[100];
        strcpy(labelBuffer, labels[i].c_str());
        outtextxy(originX + i * (barWidth + spaceBetweenBars) + barWidth / 3, originY + 10, labelBuffer);
    }

    // **Add Title and Axis Labels from user input**
    settextstyle(SIMPLEX_FONT, HORIZ_DIR, 2); 
    outtextxy(originX + (n * (barWidth + spaceBetweenBars)) / 3, originY - maxHeight - 60, const_cast<char*>(title.c_str()));
    // Title
  
    // For vertical Y-Axis label
    settextstyle(SIMPLEX_FONT, VERT_DIR, 2);  // VERT_DIR for vertical text
    outtextxy(originX - 70, originY - maxHeight / 2 + 30, const_cast<char*>(yAxisLabel.c_str())); // Y-Axis Label moved down


    // For horizontal X-Axis label
    settextstyle(SIMPLEX_FONT, HORIZ_DIR, 2); // HORIZ_DIR for horizontal text
    outtextxy(originX + (n * (barWidth + spaceBetweenBars)) / 3, originY + 40, const_cast<char*>(xAxisLabel.c_str())); // X-Axis Label
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
    
    // **User input for the title, Y-axis label, and X-axis label**
    string title, yAxisLabel, xAxisLabel;
    cout << "Enter the title for the chart: ";
    cin.ignore(); // to clear the input buffer
    getline(cin, title); // To allow space in title
    cout << "Enter the label for Y-axis: ";
    getline(cin, yAxisLabel); // To allow space in label
    cout << "Enter the label for X-axis: ";
    getline(cin, xAxisLabel); // To allow space in label

    drawBarChart(data, labels, n, title, yAxisLabel, xAxisLabel);
}
