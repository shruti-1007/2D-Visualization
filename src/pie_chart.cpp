#include<graphics.h>
#include<iostream>
#include<cmath>
#include"Algorithms/midpointcircle.cpp"
#define PI 3.141592653589793
using namespace std;

// Function to draw Pie Chart with legend
void drawPiechart(int xc, int yc, int radius, double percentage[], string categories[], int n, string title) {
    int startAngle = 0;

    // Draw the pie slices
    for (int i = 0; i < n; i++) {
        int sweepAngle = round((percentage[i] * 360) / 100); 

        // Set color for each slice
        setfillstyle(SOLID_FILL, i + 1);
        setcolor(WHITE);

        // Draw and fill the pie slice
        sector(xc, yc, startAngle, startAngle + sweepAngle, radius, radius);

        startAngle += sweepAngle; // Move to the next slice
    }

    // Display the title at the top
    setcolor(BLACK);
    outtextxy(xc - 60, yc - radius - 30, (char*)title.c_str());  // Adjust position for title display

    // Display legend and labels beside color boxes
    int legendX = xc + radius + 50;  // Position legend outside pie
    int legendY = yc - (n * 10) + 10;  // Starting Y position for the legend

    for (int i = 0; i < n; i++) {
        setfillstyle(SOLID_FILL, i + 1);
        bar(legendX, legendY, legendX + 20, legendY + 20);  // Color box

        setcolor(BLACK);
        outtextxy(legendX + 30, legendY + 5, (char*)categories[i].c_str());  // Category text

        legendY += 25;  // Move down to the next position for the next category
    }
}

void pie_chart() {
    int xc = 250, yc = 250, radius = 150;
    int data[20], n, total = 0;
    double percentage[20];
    string categories[20];
    string title;

    // Get the title from the user
    cout << "Enter the title for the pie chart: ";
    cin.ignore();  // To clear the newline character from the input buffer
    getline(cin, title);  // Read the title

    cout << "Enter number of categories: ";
    cin >> n;

    cout << "Enter category names and values:\n";
    for (int i = 0; i < n; i++) {
        cout << "Category " << i + 1 << " name: ";
        cin >> categories[i];
        cout << "Value: ";
        cin >> data[i];
        total += data[i];
    }

    // Calculate percentage with floating-point division
    double sumPercentage = 0;
    for (int j = 0; j < n; j++) {
        percentage[j] = (double)data[j] * 100.0 / total;  // Use double to avoid rounding issues
        sumPercentage += percentage[j];  // Keep track of sum
    }

    // Adjust the last slice to ensure the sum is exactly 100%
    if (sumPercentage < 100) {
        percentage[n - 1] += (100 - sumPercentage);
    }

    drawPiechart(xc, yc, radius, percentage, categories, n, title);
}


