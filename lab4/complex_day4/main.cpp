#include <iostream>

using namespace std;

class ComplexNumbers
{
    int real;
    int image;
public:
    //constructor
    ComplexNumbers(int _real=0, int _image=0)
    {
        real=_real;
        image=_image;

    }

    void setReal(int _real)
    {
        real=_real;
    }
    void setImage(int _image)
    {
        image=_image;
    }
    int getReal(void)
    {
        return real;
    }
    int getImage(void)
    {
        return image;
    }


    void printMemberFun(void)
    {
        cout<<"Number= "<<real;
        if(image>0)
        {
            cout<<"+"<<image<<"j"<<endl;
        }
        else if(image<0)
        {
            cout<<image<<"j"<<endl;
        }
    }
    ComplexNumbers addMemberFun(ComplexNumbers c)
    {
        ComplexNumbers res;
        res.real= real+c.getReal();
        res.image=image+c.getImage();
        return res;
    }
    ComplexNumbers subMemberFun(ComplexNumbers c)
    {
        ComplexNumbers res;
        res.real= real-c.getReal();
        res.image=image-c.getImage();
        return res;
    }
    friend ComplexNumbers subfriend(ComplexNumbers c1, ComplexNumbers c2);



    //+ operator 2 complex+ complex
    ComplexNumbers operator +(ComplexNumbers &c)
    {
        ComplexNumbers res(this->real+c.real,this->image+c.image ) ;
        return res;
    }
    //- operator 2 complex- complex
    ComplexNumbers operator -(ComplexNumbers &c)
    {
        ComplexNumbers res(this->real-c.real,this->image-c.image ) ;
        return res;
    }

    //+ operator complex+integer
    ComplexNumbers operator +(int x)
    {
        ComplexNumbers res(this->real+x,this->image ) ;
        return res;
    }
    //- operator complex-integer
    ComplexNumbers operator -(int x)
    {
        ComplexNumbers res(this->real-x,this->image ) ;
        return res;
    }
    //== operator
    int operator ==(ComplexNumbers &c)
    {
        return this->real==c.real && this->image==c.image;
    }

    //+= operator
    ComplexNumbers operator += (ComplexNumbers &c )
    {
        this->real =this->real +c.real;
        this->image=this->image+c.image;
        return *this;
    }
    //++ operator ++ prefix
    ComplexNumbers operator++ ()
    {
        this->real=this->real+1;
        return *this;
    }
    //++ operator ++ postfix
    ComplexNumbers operator++ (int)
    {
        ComplexNumbers temp= *this;
        (this->real)=(this->real)+1;
        return temp;
    }
    //-- operator  prefix
    ComplexNumbers operator-- ()
    {
        this->real=this->real-1;
        return *this;
    }
    //-- operator  postfix
    ComplexNumbers operator-- (int)
    {
        ComplexNumbers temp= *this;
        (this->real)=(this->real)-1;
        return temp;
    }
    // casting operator (float)
     operator float(){
        return  this->real;
    }
    // [integer] operator
    void operator [](int index){
        if(index==0){
            cout<< "Real number is "<<this->real<<endl;
        }
        else if(index==1){
            cout<< "Image number is " <<this->image<< endl;
        }

    }
        // [string] operator
    void operator [](char *str){
        if(str=="real" ||str=="Real"){
            cout<< "Real number is "<<this->real<<endl;
        }
        else if(str=="image" ||str=="Image"){
            cout<< "Image number is " <<this->image<< endl;
        }

    }



}; //end class
ComplexNumbers addStandAlone(ComplexNumbers c1,ComplexNumbers c2);
ComplexNumbers subStandAlone(ComplexNumbers c1, ComplexNumbers c2);
void printStnadAlone(ComplexNumbers c);
ComplexNumbers operator + (int x, ComplexNumbers& c);
ComplexNumbers operator - (int x, ComplexNumbers& c);
istream & operator >> (istream &_cin,  ComplexNumbers &c);
ostream & operator << (ostream &_cout, ComplexNumbers &c);

int main()
{
    ComplexNumbers c1(10,20);
    ComplexNumbers c2(20,30);
    ComplexNumbers c3;
    cout<<"--------------------------Complex + Complex----------------------------------"<<endl;
    c3=c2+c1;
    printStnadAlone(c3);
    cout<<"--------------------------Complex - Complex----------------------------------"<<endl;
    c3=c2-c1;
    printStnadAlone(c3);
    cout<<"-------------------------------Complex + integer-----------------------------"<<endl;
    ComplexNumbers c4;
    c4=c1+8;
    printStnadAlone(c4);
    cout<<"-------------------------------Complex - integer-----------------------------"<<endl;
    c4=c1-5;
    printStnadAlone(c4);
    cout<<"-------------------------------integer + complex-----------------------------"<<endl;
    c4=5+c1;
    printStnadAlone(c4);
    cout<<"-------------------------------integer - complex-----------------------------"<<endl;
    c4=5-c1;
    printStnadAlone(c4);

    cout<<"------------------------------== Operator------------------------------"<<endl;
    cout<<(c1==c2)<<endl;
    //(c1==c2) ? "true" : "false";
    cout<<"------------------------------+= Operator------------------------------"<<endl;
    ComplexNumbers c5(1,2);
    c5+=c1;
    printStnadAlone(c5);
    cout<<"------------------------------++ prefix------------------------------"<<endl;
    ComplexNumbers c6(3.4);
    c6=++c1;
    cout<<"c6= ";
    printStnadAlone(c5);
    cout<<"c1= ";
    printStnadAlone(c1);
    cout<<"------------------------------++ postfix------------------------------"<<endl;
    c6=c1++;
    cout<<"c6= ";
    printStnadAlone(c5);
    cout<<"c1= ";
    printStnadAlone(c1);
    cout<<"------------------------------ (--) prefix------------------------------"<<endl;
    c6=--c1;
    cout<<"c6= ";
    printStnadAlone(c5);
    cout<<"c1= ";
    printStnadAlone(c1);
    cout<<"------------------------------ (--) postfix------------------------------"<<endl;
    c6=c1--;
    cout<<"c6= ";
    printStnadAlone(c5);
    cout<<"c1= ";
    printStnadAlone(c1);
    cout<<"------------------------------ (float) -----------------------------"<<endl;
    ComplexNumbers c7(15,9);
    cout<< (float)c7<<endl;
    cout<<"------------------------------ cin>> -----------------------------"<<endl;
    ComplexNumbers c8;
    cin >> c8;
    cout<<"------------------------------ cout<< -----------------------------"<<endl;
    cout << c8;
    cout<<"------------------------------ [integer] -----------------------------"<<endl;
    c8[1];
    cout<<"------------------------------ [string] -----------------------------"<<endl;
    c8["real"];
    return 0;
}

void printStnadAlone(ComplexNumbers c)
{
    cout<<"Number= "<<c.getReal();
    if(c.getImage()>0)
    {
        cout<<"+"<<c.getImage()<<"j"<<endl;
    }
    else if(c.getImage()<0)
    {
        cout<<c.getImage()<<"j"<<endl;
    }
}

//+ operator integer + complex
ComplexNumbers operator + (int x, ComplexNumbers& c)
{
    ComplexNumbers res(c.getReal()+x,c.getImage()) ;
    return res;
}

//- operator integer - complex
ComplexNumbers operator - (int x, ComplexNumbers &c)
{
    ComplexNumbers res(c.getReal()-x,c.getImage()) ;
    return res;
}
istream & operator >> (istream &_cin,  ComplexNumbers &c)
{
    int _real,_image;
    cout << "Enter Real  ";
    _cin >> _real;
    c.setReal(_real);
    cout << "Enter image  ";
    _cin >>_image;
    c.setImage(_image);
    return _cin;
}
ostream & operator << (ostream &_cout, ComplexNumbers &c)
{
    _cout << c.getReal();

        if(c.getImage()>0)
    {
        _cout<<"+"<<c.getImage()<<"j"<<endl;
    }
    else if(c.getImage()<0)
    {
        _cout<<c.getImage()<<"j"<<endl;
    }
    return _cout;
}



ComplexNumbers addStandAlone(ComplexNumbers c1,ComplexNumbers c2){
        ComplexNumbers res;
        res.setReal(c1.getReal()+c2.getReal());
        res.setImage(c1.getImage()+c2.getImage());
        return res;
}

ComplexNumbers subStandAlone(ComplexNumbers c1, ComplexNumbers c2){
        ComplexNumbers res;
        res.setReal(c1.getReal()-c2.getReal());
        res.setImage(c1.getImage()-c2.getImage());
        return res;
}

ComplexNumbers subfriend(ComplexNumbers c1, ComplexNumbers c2){
        ComplexNumbers res;
        res.setReal(c1.real-c2.real);
        res.setImage(c1.image-c2.image);
        return res;

}


