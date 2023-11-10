#include <iostream>

using namespace std;

class ComplexNumbers{
    int real;
    int image;
public:
    void setReal(int _real){
        real=_real;
    }
    void setImage(int _image){
        image=_image;
    }
    int getReal(void){
    return real;
    }
    int getImage(void){
    return image;
    }

    void printMemberFun(void){
    cout<<"Number= "<<real;
    if(image>0){
        cout<<"+"<<image<<"j"<<endl;
    }
    else if(image<0){
        cout<<image<<"j"<<endl;
    }
    }
    ComplexNumbers addMemberFun(ComplexNumbers c){
        ComplexNumbers res;
        res.real= real+c.getReal();
        res.image=image+c.getImage();
        return res;
    }
    ComplexNumbers subMemberFun(ComplexNumbers c){
        ComplexNumbers res;
        res.real= real-c.getReal();
        res.image=image-c.getImage();
        return res;
    }
    friend ComplexNumbers subfriend(ComplexNumbers c1, ComplexNumbers c2);





};
ComplexNumbers addStandAlone(ComplexNumbers c1,ComplexNumbers c2);
ComplexNumbers subStandAlone(ComplexNumbers c1, ComplexNumbers c2);
void printStnadAlone(ComplexNumbers c);

int main()
{
    ComplexNumbers *c1=new ComplexNumbers;
    ComplexNumbers c2, c3,c4;
    //----------member functions-----
    c1->setReal(2);
    c1->setImage(3);
    c1->printMemberFun();
    c2.setReal(5);
    c2.setImage(-7);
    c2.printMemberFun();
    c3=c1->addMemberFun(c2);
    c3.printMemberFun();
    c4=c1->subMemberFun(c2);
    c4.printMemberFun();
    delete(c1);


    //----------stand alone functions-----
    /*ComplexNumbers c1,c2,c3,c4, c5;
    c1.setReal(2);
    c1.setImage(3);
    printStnadAlone(c1);
    c2.setReal(5);
    c2.setImage(-7);
    printStnadAlone(c2);
    c3=addStandAlone(c1,c2);
    printStnadAlone(c3);
    c4=subStandAlone(c1,c2);
    printStnadAlone(c4);
    c5=subfriend(c1,c2);
    printStnadAlone(c5);*/





    return 0;
}

void printStnadAlone(ComplexNumbers c){
        cout<<"Number= "<<c.getReal();
    if(c.getImage()>0){
        cout<<"+"<<c.getImage()<<"j"<<endl;
    }
    else if(c.getImage()<0){
        cout<<c.getImage()<<"j"<<endl;
    }
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


