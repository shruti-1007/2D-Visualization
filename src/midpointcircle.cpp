void drawCircle(int xc,int yc,int r)
{
	int x=0,y=r;
	int d=1-r;
	while(x<=y)
	{
		putpixel(x+xc,y+yc,WHITE);
		putpixel(xc-x,yc+y,WHITE);
		putpixel(xc+x,yc-y,WHITE);
		putpixel(xc-x,yc-y,WHITE);
		putpixel(xc+y,yc+x,WHITE);
		putpixel(xc-y,yc+x,WHITE);
		putpixel(xc+y,yc-x,WHITE);
		putpixel(xc-y,yc-x,WHITE);
		x++;
		if(d<0)
		{
			d+=2*x+1;
		}
		else{
			y--;
			d+=2*(x-y)+1;
		}
	}
}