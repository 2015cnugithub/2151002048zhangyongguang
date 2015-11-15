#include <graphics.h>
#include<iostream>
#include <conio.h>
#include <time.h>
#include <fstream>
using namespace std;
int d = 20;
class car
{
public:
	double locx, locy;
	double speed;
	void drawcar()
	{
		setlinecolor(BLACK);
		setorigin(0, 500);
		lineto(1000, 0);
		type();
		setorigin(locx, locy);
		circle(1.75*d, -d / 2, d / 2);
		circle(6.25*d, -d / 2, d / 2);
		rectangle(0, -2 * d, 8 * d, -d);
		rectangle(2.25*d, -3 * d, 5.75*d, -2 * d);
		POINT pts1[] = { { 2.25*d,-3 * d },{ 1.25*d,-2 * d },{ 2.25*d,-2 * d } };
		polygon(pts1, 3);
		POINT pts2[] = { { 5.75*d,-3 * d },{ 6.75*d,-2 * d },{ 5.75*d,-2 * d } };
		polygon(pts2, 3);
	};
	void move() 
	{
			locx = locx + speed;
			clearcliprgn();
			drawcar();
	}
	void type()
	{
		settextstyle(16, 8, _T("Courier"));
		settextcolor(BLACK);
		char start[] = "Press <S> key to start moving";
		char pause[] = "Press <P> key to pause / continue moving";
		char end[] = "Press <E> key to end moving ";
		char accelerate[] = "Press <+> key to speed up";
		char clutch[] = "Press <-> key to speed down";
		outtextxy(0, -500, start);
		outtextxy(0, -500+18, pause);
		outtextxy(0, -500+36, end);
		outtextxy(0, -500+54, accelerate);
		outtextxy(0, -500+72, clutch);
	}
    car(int x,int y) 
	{
		locx = x;
		locy = y;
		speed = 1;
	};
};
void initial() 
{
	initgraph(1000, 600);
	setbkcolor(WHITE);
	cleardevice();
}


void main()
{
	int sx = 0, sy = 500;
	char kbtp,p='r';
	void initial();
	car q(sx,sy);
	initial();
	q.drawcar();
	while (true)
	{
		kbtp=_getch();
		{
			if (kbtp != '+'&&kbtp != '-'&&kbtp != 's'&&kbtp != 'e'&&kbtp != 'p')
			{
				while (!_kbhit())
				{
					q.move();
					Sleep(20);
				}
			}
			if (kbtp == 's')
			{
				while (!_kbhit())
				{
					q.move();
					Sleep(20);
				}
			}
			if (kbtp == '+')
			{
				q.speed = q.speed + 0.1;
				while (!_kbhit())
				{
					q.move();
					Sleep(20);
				}
			}
			if (kbtp == '-')
			{
				q.speed = q.speed - 0.1;
				while (!_kbhit())
				{
					q.move();
					Sleep(20);
				}
			}
			if (kbtp == 'e')
			{
				exit(1);
			}
			if (kbtp == 'p')
			{
				if (p == 'r')
				{
					p = 'p';
					while (!_kbhit())
					{}
				}
				else
				{
					p = 'r';
					while (!_kbhit())
					{
						q.move();
						Sleep(20);
					}
				}
			}
		}
	}
}