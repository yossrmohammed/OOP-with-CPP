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
        //cout<<"Destroy Point"<<endl;

    }

};//end class
class Rect{
    Point lp,rp;
public:
    Rect(){
        lp.setXY(0,0);
        rp.setXY(0,0);

    }
    Rect(Point p1,Point p2):lp(p1), rp(p2){
      //this->lp=p1;
      //this->rp=p2;
    }
    Rect(int x1,int y1,int x2,int y2):lp(x1,y1), rp(x2,y2){
        //lp.setXY(x1,y1);
        //rp.setXY(x2,y2);
    }

    void paintRectangle(){
        //cout<<"left top point is ("<<lp.getX() <<","<<lp.getY() <<")"<<endl;
        //cout<<"right bottom point is ("<<rp.getX()<<","<<rp.getY() <<")"<<endl;
        rectangle(lp.getX(),lp.getY(),rp.getX(), rp.getY());


    }

};//end class
class Line{
    Point a;
    Point b;
public:
    Line(){
        a.setXY(0,0);
        b.setXY(0,0);

    }
    Line(Point _a , Point _b):a(_a),b(_b){
     //this->a=_a;
      //this->b=_b;

    }
    Line(int x1,int y1,int x2,int y2):a(x1,y1), b(x2,y2){
        //a.setXY(x1,y1);
        //b.setXY(x2,y2);
    }
    void paintLine(){
        //cout<<"left  point is ("<<a.getX() <<","<<a.getY() <<")"<<endl;
        //cout<<"right  point is ("<<b.getX()<<","<<b.getY() <<")"<<endl;
       line(a.getX(),a.getY(),b.getX(), b.getY());


    }



};//end class
class Circle{
    Point a;
    int radius;
public:
        Circle(){
        a.setXY(0,0);
        radius=0;

    }
   Circle(Point p , int _redius):a(p){
        radius=_redius;
    }
    Circle(int x1,int y1, int rad):a(x1,y1){
        //a.setXY(x1,y1);
        radius=rad;

    }
     paintCircle(){
         //cout<<"Point is ("<<a.getX() <<","<<a.getY() <<")"<<endl;
         //cout<<"Radius is " <<radius<<endl;
         circle(a.getX(),a.getY(), radius);
    }



};//end class

int main()
{
    //Point p1(1,2);
    //Point p2(3,4);
    initwindow(1000,1000);
    Rect r(100,200,300,400);
    r.paintRectangle();
    Line l(400,500,600,700);
    l.paintLine();

    Circle c(100,200,100);
    c.paintCircle();
    getch();
    closegraph();



    return 0;
}
