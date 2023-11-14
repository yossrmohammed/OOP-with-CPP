#include <iostream>
#include "graphics.h"
using namespace std;


class Point
{
    int x;
    int y;
public:
    Point(int x=0,int y=0)
    {
        this->x=x;
        this->y=y;

    }
    void setX(int x)
    {
        this->x=x;
    }
    void setY(int y)
    {
        this->y=y;
    }
    void setXY(int x, int y)
    {
        this->x=x;
        this->y=y;
    }
    int getX(void)
    {
        return (this->x);
    }
    int getY(void)
    {
        return (this->y);
    }
    ~ Point()
    {
        //cout<<"Destroy Point"<<endl;

    }

};//end point class
class Shape
{
protected:
    Point p1,p2;
    int color;
public:
    Shape()
    {
        p1.setXY(0,0);
        p2.setXY(0,0);
        color=0;

    }

    Shape(int x1,int y1,int x2=0,int y2=0, int _color=0):p1(x1,y1), p2(x2,y2)
    {
        color=_color;
    }

    void draw()
    {
    };

};// end shape class
class Rect:public Shape
{

public:
    Rect():Shape()
    {

    }
    Rect(int x1,int y1,int x2,int y2, int _color):Shape(x1,y1,x2,y2,_color)
    {
        color=_color;
    }
    void setRectangleParameters(int x1,int y1,int x2,int y2, int _color)
    {
        p1.setXY(x1,y1);
        p2.setXY(x2,y2);

        color=_color;

    }

    void draw()
    {
        setcolor(color);
        rectangle(p1.getX(),p1.getY(),p2.getX(), p2.getY());



    }

};//end rectangle class
class Line: public Shape
{

public:
    Line():Shape()
    {

    }


    Line(int x1,int y1,int x2,int y2, int _color):Shape(x1,y1,x2,y2,_color)
    {
    }
    void setLineParameters(int x1,int y1,int x2,int y2, int _color)
    {
        p1.setXY(x1,y1);
        p2.setXY(x2,y2);

        color=_color;

    }
    void draw()
    {
        setcolor(color);
        line(p1.getX(),p1.getY(),p2.getX(), p2.getY());



    }



};//end line class
class Circle: public Shape
{
    int radius;
public:
    Circle():Shape()
    {
        radius=0;
    }


    Circle(int x1,int y1, int rad, int _color):Shape(x1,y1)
    {

        radius=rad;
        color=_color;

    }
    void setCircleParameters(int x1,int y1, int rad, int _color)
    {
        p1.setXY(x1,y1);
        radius=rad;
        color=_color;

    }

    void draw()
    {
        setcolor(color);
        circle(p1.getX(),p1.getY(),radius);

    }



};//end circle class
istream & operator >> (istream &_cin,  Circle &c);
istream & operator >> (istream &_cin,  Line &l);
istream & operator >> (istream &_cin,  Rect &r);
int main()
{
    initwindow(1000,1000);
    int noOfShape=0;
    cout<<"Enter number of shapes: "<<endl;
    cin>>noOfShape;
    Rect * r =new Rect[noOfShape];
    Circle * c =new Circle[noOfShape];
    Line * l =new Line[noOfShape];
    int countC=0,countR=0,countL=0;
    for(int i=0; i<noOfShape; i++)
    {
        int shapeIndex;
        cout<<"what is type of shape "<<i+1<<endl;
        cout<<"Note: 0 for circle \n 1 for rectangle \n 2 for line"<<endl;
        cin>>shapeIndex ;
        while(shapeIndex!=0 && shapeIndex!=1 && shapeIndex!=2)
        {
            cout<<"Invalid value ,please enter valid value " <<endl;
            cout<<"what is type of shape "<<i+1<<endl;
            cout<<"Note: 0 for circle \n 1 for rectangle \n 2 for line"<<endl;
            cin>>shapeIndex ;

        }

        switch(shapeIndex)
        {
        case 0:
        {

            cin >> c[countC];
            countC++;

            break;
        }
        case 1:
        {

            cin >> r[countR];
            countR++;

            break;
        }
        case 2:
        {
            cin >> l[countL];
            countL++;
            break;
        }
        default:
        {
            cout<<"invalid value"<<endl;

        }
        }


    }

    for(int i=0; i<countC; i++)
    {
        c[i].draw();

    }
    for(int i=0; i<countR; i++)
    {
        r[i].draw();

    }
    for(int i=0; i<countL; i++)
    {
        l[i].draw();

    }

    getch();
    closegraph();

    return 0;
}

// cin>> for circle
istream & operator >> (istream &_cin,  Circle &c)
{
    int _x, _y, rad, _color;

    cout << "Enter x ";
    _cin >> _x;
    cout << "Enter y  ";
    _cin >>_y;
    cout << "Enter radius ";
    _cin >>rad;
    cout << "Enter color ";
    _cin >>_color;
    c.setCircleParameters(_x,_y,rad,_color);
    return _cin;
}

// cin>> for line
istream & operator >> (istream &_cin,  Line &l)
{
    int _x1, _y1,_x2,_y2, _color;

    cout<<"For sarting point :"<<endl;
    cout << "Enter x ";
    _cin >> _x1;
    cout << "Enter y  ";
    _cin >>_y1;
    cout<<"For  ending point :"<<endl;
    cout << "Enter x ";
    _cin >> _x2;
    cout << "Enter y  ";
    _cin >>_y2;
    cout << "Enter color ";
    _cin >>_color;
    l.setLineParameters(_x1,_y1,_x2,_y2,_color);
    return _cin;
}

// cin>> for rectangle
istream & operator >> (istream &_cin,  Rect &r)
{
    int _x1, _y1,_x2,_y2, _color;
    cout<<"For left top point :"<<endl;
    cout << "Enter x ";
    _cin >> _x1;
    cout << "Enter y  ";
    _cin >>_y1;
    cout<<"For right bottom point :"<<endl;
    cout << "Enter x ";
    _cin >> _x2;
    cout << "Enter y  ";
    _cin >>_y2;
    cout << "Enter color ";
    _cin >>_color;
    r.setRectangleParameters(_x1,_y1,_x2,_y2,_color);
    return _cin;
}



