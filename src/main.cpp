#include <graphics.h>
#include <iostream>
#include "bargraph.cpp"
#include "bezier.cpp"
#include "pie_chart.cpp"
// #include "line_graph.cpp"
// #include "transformations.cpp"
// #include "export.cpp"

using namespace std;

void displayMenu() {
    cout << "Data Visualization Dashboard" << endl;
    cout << "1. Bar Chart" << endl;
    cout << "2. Pie Chart" << endl;
    cout << "3. Line Graph" << endl;
    cout << "4. Scatter Plot" << endl;
    cout << "5. Bezier Curve" << endl;
    cout << "6. Exit" << endl;
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, (char*)"");
    setbkcolor(WHITE);
    cleardevice();
    int choice;
    do {
        displayMenu();
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
               cleardevice();
               bargraph();
                break;
            case 2:
                cleardevice();  
                pie_chart();
                break;
            case 3:
                cleardevice();
                // line_graph();
               // Calls the function to draw line graph
                break;
            case 4:
                
                break;
            case 5:
                cleardevice();
                drawBezier();
                break;
            default:
                cout << "Invalid choice, try again." << endl;
        }
    } while (choice != 4);

    return 0;
}
