#include<graphics.h>
#include<iostream>
#include<cmath>
#include"midpointcircle.cpp"
#define PI 3.141592653589793
using namespace std;
// Function to draw Pie Chart with legend
void drawPiechart(int xc, int yc, int radius, double percentage[], string categories[], int n) {
    int startAngle = 0;

    for (int i = 0; i < n; i++) {
        int sweepAngle = round((percentage[i] * 360) / 100);  // Correct percentage calculation

        // Set color for each slice
        setfillstyle(SOLID_FILL, i + 1);
        setcolor(WHITE);

        // Draw and fill the pie slice
        sector(xc, yc, startAngle, startAngle + sweepAngle, radius, radius);

        // Display legend (index)
        int legendX = xc + radius + 50; // Position legend outside pie
        int legendY = yc - (n * 10) + (i * 25);
        setfillstyle(SOLID_FILL, i + 1);
        bar(legendX, legendY, legendX + 20, legendY + 20);  // Color box
        setcolor(WHITE);
        outtextxy(legendX + 30, legendY + 5, (char*)categories[i].c_str());  // Category text
	
        startAngle += sweepAngle; // Move to the next slice
    }
}

void pie_chart()
{
	
	  int xc = 250, yc = 250, radius = 100;
    int data[20], n, total = 0;
    double percentage[20];
    string categories[20];

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

    // Calculate percentage properly with floating-point division
    double sumPercentage = 0;
    for (int j = 0; j < n; j++) {
        percentage[j] = (double)data[j] * 100.0 / total;  // Use double to avoid rounding issues
        sumPercentage += percentage[j];  // Keep track of sum
    }

    // Adjust the last slice to ensure the sum is exactly 100%
    if (sumPercentage < 100) {
        percentage[n - 1] += (100 - sumPercentage);
    }

    drawPiechart(xc, yc, radius, percentage, categories, n);	
	
}
