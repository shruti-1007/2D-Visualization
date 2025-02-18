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
void drawPiechart(int xc,int yc,int radius,int percentage[20],int n)
{
	drawCircle(xc,yc,radius);
	int startAngle=0;
	for(int i=0;i<n;i++)
	{
		int sweepAngle=percentage[i]*360/100;
		setcolor(i+1);
		//To draw line for pie slices
		drawLine(xc,yc,startAngle,radius);
		drawLine(xc,yc,startAngle+sweepAngle,radius);
		//Fill pie slices with different color
		for(int angle=startAngle; angle<startAngle+sweepAngle; angle++)
		{
			for(int r=0; r<radius; r++ )
			{
				int x=xc+r*cos(angle*PI/180);
				int y=yc-r*sin(angle*PI/180);
				putpixel(x,y,i+1);
			}
		
		}
		startAngle+=sweepAngle;
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
	getch();
	closegraph();
	return 0;
}