#include<graphics.h>
#include<iostream>
#include<cmath>
#include"midpointcircle.cpp"
#define PI 3.141592653589793
using namespace std;
//Function to draw line from center
void drawLine(int xc,int yc,int angle,int radius)
{
	int x=xc+radius*cos(angle*PI/180);
	int y=yc-radius*sin(angle*PI/180);
	line(xc,yc,x,y);
}
//Function to draw PieChart
void drawPiechart(int xc, int yc, int radius, int percentage[], int n) {
    int startAngle = 0;

    for (int i = 0; i < n; i++) {
        int sweepAngle = (percentage[i] * 360) / 100;

        // Set color for each slice
        setfillstyle(SOLID_FILL, i + 1);
        setcolor(WHITE);

        // Use sector() to draw and fill the slice directly
        sector(xc, yc, startAngle, startAngle + sweepAngle, radius, radius);

        startAngle += sweepAngle; // Move to the next slice
    }
}
void pie_chart()
{
	
	int xc=250,yc=250,radius=100;
	int data[20],n,total=0,percentage[20];
	cout<<"Enter number of data"<<endl;
	cin>>n;
	cout<<"Enter the data"<<endl;
	for (int i=0;i<n;i++)
	{
		cin>>data[i];
		total+=data[i];
	}
	for (int j=0;j<n;j++)
	{
		percentage[j]=(data[j]*100)/total;
	}
	drawPiechart(xc,yc,radius,percentage,n);
	
}
