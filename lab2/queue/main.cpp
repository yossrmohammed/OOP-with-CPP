#include <iostream>

using namespace std;

class Queue{
    int Frist, last, Size;
     int* arr;
 public:
    Queue(){
    Size=5;
    Frist=0;
    last=0;
    arr= new int[Size]{0};

    }
    Queue(int _size){
    Size=_size;
    Frist=0;
    last=0;
    arr= new int[Size]{0};
    }
    void Enqueue(int x){
        if(Size==last){
            cout<<"Queue is full"<<endl;

        }
        else{
            arr[last]=x;
            last++;

        }
    }
    int Dequeue(){
        if(Frist==last){
            cout<<"Queue is empty"<<endl;
        }
        else{
            int x= arr[Frist];
            for(int i=0; i<last-1;i++){
                arr[i]=arr[i+1];

            }
        last--;
        return x;
        }

    }
    friend void displayAllElements(Queue q);
    ~Queue(){
    delete[] arr;
    }



}; //end class
int main()
{
    Queue q1(10);
    q1.Enqueue(1);
    q1.Enqueue(5);
    q1.Enqueue(4);
    cout<<q1.Dequeue()<<endl;
    cout<<q1.Dequeue()<<endl;
    q1.Enqueue(7);
    cout<<q1.Dequeue()<<endl;
    cout<<q1.Dequeue()<<endl;
    q1.Dequeue();

    cout<<"-------------------------------------------------"<<endl;
//    displayAllElements(q1);
    //cout<<q1.Dequeue()<<endl;
    return 0;
}

void displayAllElements(Queue q){
    int actualSize=q.last;
    for(int i=0;i<=actualSize;i++){
       cout<<q.Dequeue()<<endl;

    }

}
