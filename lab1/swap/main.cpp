#include <iostream>

using namespace std;
void swapPointer(int* x,int* y);
void swapRef(int &x, int &y);
void swapValue(int x,int y);
int main()
{
    int a=3, b=5, x=4,y=8;

    cout<<"Before swapping using value : \n a= "<<a<< "\t"<<"b="<<b<<endl;
    swapValue(a,b);
    cout<<"After swapping using value: \n a= "<<a<< "\t"<<"b="<<b<<endl;
    cout<<"-------------------------------------------------------"<<endl;
    cout<<"Before swapping using pointer  : \n a= "<<a<< "\t"<<"b="<<b<<endl;
    swapPointer(&a,&b);
    cout<<"After swapping using pointer: \n a= "<<a<< "\t"<<"b="<<b<<endl;
    cout<<"-------------------------------------------------------"<<endl;
    cout<<"Before swapping reference : \n x= "<<x<< "\t"<<"y="<<y<<endl;
    swapRef(x,y);
    cout<<"After swapping using reference: \n x= "<<x<< "\t"<<"y="<<y<<endl;


    return 0;
}

void swapPointer(int* x,int* y){
    int temp=0;
    temp=*x;
    *x=*y;
    *y=temp;

}

void swapRef(int &x, int &y){
    int temp=0;
    temp=x;
    x=y;
    y=temp;

}

void swapValue(int x,int y){
    int temp=0;
    temp=x;
    x=y;
    y=temp;

}
