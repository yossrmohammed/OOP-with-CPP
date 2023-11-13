#include <iostream>

using namespace std;

class Stack
{
    int * arr;
    int  top;
    int Size;
public:
    /*Stack(){
    Size=5;
    top=-1;
    arr= new int[Size]{0};

    }*/
    Stack(Stack &s)
    {
        Size=s.Size;
        top=s.top;
        arr= new int[Size];
        for(int i=0; i<=top; i++)
        {
            arr[i]=s.arr[i];

        }


    }
    // = operator
    Stack operator=(Stack & s)
    {
        this->top=s.top;
        this->Size=s.Size;
        delete[] this->arr;

        this->arr=new int [this->Size];

        for(int i=0; i<=this->top; i++)
        {
            this->arr[i]=s.arr[i];
        }

        return *this;
    }

    Stack(int _size)
    {
        Size=_size;
        top=-1;
        arr= new int[Size] {0};
    }
    void push(int x)
    {
        if(top==(Size-1))
        {
            cout<<"Sorry stack is full"<<endl;
        }
        else
        {
            top++;
            arr[top]=x;

        }
    }
    int pop()
    {
        if(top!=-1)
        {
            int x=arr[top];
            top--;
            cout<<"POP"<<x<<endl;
            return x;
        }
        else
        {
            cout<<"Stack is empty"<<endl;
            return -10;
        }

    }
    int getTop()
    {
        return top;
    }


    ~Stack()
    {
        delete []arr;
    }



}; //end class
void displayAllElements(Stack s);
int main()
{
    Stack s1(10);
    s1.push(10);
    s1.push(9);
    s1.push(5);
    Stack s2(5);
    s2.push(4);
    s2.push(1);
    cout<<"--------------------------------- Before = operator ---------------------------"<<endl;
    cout<<"s1= "<<endl;;
    displayAllElements(s1);
    cout<<"s2= "<<endl;
    displayAllElements(s2);
    cout<<"--------------------------------- After = operator ---------------------------"<<endl;
    s2=s1;
    s2.push(3);
    s2.push(11);
    cout<<"s1= "<< endl;;
    displayAllElements(s1);
    cout<<"s2= " <<endl;
    displayAllElements(s2);


    return 0;
}
void displayAllElements(Stack s){
    int actualSize= s.getTop();
    for(int i =0; i<=actualSize; i++){
        s.pop();
    }



}

