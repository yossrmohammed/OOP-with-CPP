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
    Point *lp;
    Point *rp;
public:
    Rect(){
        lp=NULL;
        rp=NULL;

    }

    void setPointsForRectangle(Point * p1,Point * p2){
        lp=p1;
        rp=p2;

    }
    void paintRectangle(){
        if(lp==NULL && rp==NULL ){
            return ;
        }
        else{
        //cout<<"left top point is ("<<lp->getX() <<","<<lp->getY() <<")"<<endl;
        //cout<<"right bottom point is ("<<rp->getX()<<","<<rp->getY() <<")"<<endl;
        rectangle(lp->getX(),lp->getY(),rp->getX(), rp->getY());
        }

    }


};//end class
class Line{
    Point * a;
    Point * b;
public:

    Line(){
        a=NULL;
        b=NULL;

    }

    void setPointsForLine(Point * p1,Point * p2){
        a=p1;
        b=p2;

    }
    void paintLine(){
        if(a==NULL && b==NULL ){
                cout<<"pointer is equal Null"<<endl;
            return ;
        }
        else{
        //cout<<"left top point is ("<<a->getX() <<","<<a->getY() <<")"<<endl;
        //cout<<"right bottom point is ("<<b->getX()<<","<<b->getY() <<")"<<endl;
        line(a->getX(),a->getY(),b->getX(), b->getY());
        }

    }



};//end class
class Circle{
    Point * a;
    int radius;
public:
    Circle(){
        a=NULL;
        radius=0;

    }

    void setPointsForCircle(Point * p1,int _radius){
        a=p1;
        radius=_radius;

    }
    void paintCircle(){
        if(a==NULL){
                cout<<"pointer is equal Null"<<endl;
            return ;
        }
        else{
        //cout<<"left top point is ("<<a->getX() <<","<<a->getY() <<")"<<endl;
        //cout<<"Radius is " <<radius<<endl;
        circle(a->getX(),a->getY(), radius);
        }

    }



};//end class

int main()
{
    Point p1(100,200);
    Point p2(300,400);
    initwindow(1000,1000);
    //cout<<"----------------------------------- Rectangle -----------------------------"<<endl;
    Rect r;
    r.setPointsForRectangle(&p1,&p2);
    r.paintRectangle();
    //cout<<"----------------------------------- Line -----------------------------"<<endl;
    Line l;
    l.setPointsForLine(&p1,&p2);
    l.paintLine();
    //cout<<"----------------------------------- Circle -----------------------------"<<endl;
    Circle c;
    c.setPointsForCircle(&p1,100);
    c.paintCircle();
        getch();
    closegraph();



    return 0;
}

