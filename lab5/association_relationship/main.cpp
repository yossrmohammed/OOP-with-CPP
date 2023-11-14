#include <iostream>
#include "graphics.h"
using namespace std;
class Point{
    int x;
    int y;
public:
    Point(int x=0,int y=0){
        this->x=x;
        this->y=y;

    }
    void setX(int x){
    this->x=x;
    }
    void setY(int y){
    this->y=y;
    }
    void setXY(int x, int y){
        this->x=x;
        this->y=y;
    }
    int getX(void){
    return (this->x);
    }
    int getY(void){
    return (this->y);
    }
    ~ Point(){
        cout<<"Destroy Point"<<endl;

    }

};//end class
class Rect{
    int x1,x2,y1,y2;
public:

    Rect(int x1=0,int y1=0,int x2=0,int y2=0 ){
        this->x1=x1;
        this->x2=x2;
        this->y1=y1;
        this->x2=x2;
    }

    void paintRectangle(Point & p1, Point & p2){
        //cout<<"left  point is ("<<p1.getX() <<","<<p1.getY() <<")"<<endl;
        //cout<<"right  point is ("<<p2.getX()<<","<<p2.getY() <<")"<<endl;
        rectangle(p1.getX(),p1.getY(),p2.getX(), p2.getY());

    }


};//end class
class Line{

    int x1,x2,y1,y2;
public:

    Line(int x1=0,int y1=0,int x2=0,int y2=0 ){
        this->x1=x1;
        this->x2=x2;
        this->y1=y1;
        this->x2=x2;
    }

    void paintLine(Point & p1, Point & p2){
        //cout<<"left  point is ("<<p1.getX() <<","<<p1.getY() <<")"<<endl;
        //cout<<"right  point is ("<<p2.getX()<<","<<p2.getY() <<")"<<endl;
        line(p1.getX(),p1.getY(),p2.getX(), p2.getY());

    }



};//end class
class Circle{
    int x,y;
    int radius;
public:
    Circle(int x=0,int y=0,int r=0 ){
        this->x=x;
        this->x=x;
        this->radius=radius;

    }
    void paintCircle(Point &p, int red){

        //cout<<" point is ("<<p.getX() <<","<<p.getY() <<")"<<endl;
        //cout<<"Radius is " <<red<<endl;
        circle(p.getX(),p.getY(), red);


    }



};//end class



int main()
{
    Point p1(100,200);
    Point p2(300,400);
    initwindow(1000,1000);
    //cout<<"----------------------------------- Rectangle -----------------------------"<<endl;
    Rect r;
    r.paintRectangle(p1,p2);

    //cout<<"----------------------------------- Line -----------------------------"<<endl;
    Line l;
    l.paintLine(p1, p2);

    //cout<<"----------------------------------- Circle -----------------------------"<<endl;
    Circle c;
    c.paintCircle(p1,100);

        getch();
    closegraph();



    return 0;
}

