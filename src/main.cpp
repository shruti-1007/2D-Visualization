#include <graphics.h>
#include <iostream>
#include "bargraph.cpp"
#include "Algorithms/bezier.cpp"
#include "pie_chart.cpp"
#include "scatterplot.cpp"
#include "line_graph.cpp"
#include "3dpie.cpp"

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
                int choice2;
                cleardevice();  
                cout<<"1.2D Pie Chart \n2.3D Pie Chart"<<endl;
                cin>>choice2;
                if(choice2==1)
                {
                    cleardevice();
                    pie_chart();
                }
                else if(choice2==2)
                {

                    setbkcolor(BLACK);
                    cleardevice();
                    Draw3dpie();
                }
                else
                {
                    cout<<"Invalid choice"<<endl;
                }
                break;
            case 3:
                cleardevice();
                lineGraph();
    
                break;
            case 4:
                cleardevice();
                scatterPlot();
                break;
            case 5:
                cleardevice();
                drawBezier();
                break;
            case 6:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice, try again." << endl;
        }
    } while (choice != 7);

 closegraph();
 getch();
 return 0;
}
