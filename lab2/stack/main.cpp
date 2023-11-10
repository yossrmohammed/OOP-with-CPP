#include <iostream>

using namespace std;

class Stack{
    int * arr;
    int  top;
    int Size;
public:
    /*Stack(){
    Size=5;
    top=-1;
    arr= new int[Size]{0};

    }*/
    Stack(Stack &s){
        Size=s.Size;
        top=s.top;
        arr= new int[Size];
        for(int i=0; i<=top;i++){
            arr[i]=s.arr[i];

        }


    }
    Stack(int _size){
    Size=_size;
    top=-1;
    arr= new int[Size]{0};
    }
    void push(int x){
        if(top==(Size-1)){
            cout<<"Sorry stack is full"<<endl;
        }
        else{
            top++;
            arr[top]=x;

        }
    }
    int pop(){
        if(top!=-1){
              int x=arr[top];
              top--;
              cout<<"POP"<<x<<endl;
              return x;
        }
        else{
            cout<<"Stack is empty"<<endl;
            return -10;
        }

    }
    int getTop(){
    return top;
    }


    ~Stack(){
    delete []arr;
    }



}; //end class
void popAllElements(Stack s);
int main()
{
    Stack s1(10);
    s1.push(1);
    s1.push(2);
    s1.push(5);
    s1.push(7);
    s1.push(10);

    //cout<<s1.pop()<<endl;//9
    //cout<<s1.pop()<<endl;
    cout<<"-------------------------------------------------"<<endl;
    s1.push(11);
    //cout<<s1.pop()<<endl;//10
    //cout<<s1.pop()<<endl;//7
    //cout<<s1.pop()<<endl;//5
    Stack s2(10);
    s2.push(1);
    s2.push(2);
    popAllElements(s2);
   s2.pop();
    s2.pop();




    return 0;
}
void popAllElements(Stack s){
    cout<<" -------------------Inside Function -------------------"<<endl;
    s.push(7);
    s.push(8);
    s.pop();//8
    s.pop();//7
    s.pop();//2//0


}
