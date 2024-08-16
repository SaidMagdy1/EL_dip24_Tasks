#include <iostream>

class Base {
public:
std::string name;
virtual void greeting(){
    std::cout << "Hello from Base Class "<< std::endl;
}
//here the pure virual function  and you should make it in any child class either
// and we call this Class the interface Classs
// not allowed to create instance from interface Class
// in child class we must implement all virtual functions
virtual void fun_overriding_1()=0;
virtual void fun_overriding_2()=0;
virtual void fun_overriding_3()=0;


Base()
{
    std::cout << "Base Constructor "<< std::endl;
}
~Base(){
    std::cout << "Base Destructor "<< std::endl;
}
};




class Child : public Base {
public:
virtual void fun_overriding_1() override {

}
virtual void fun_overriding_2() override {

}
virtual void fun_overriding_3() override {

}
virtual void greeting(){
    std::cout << "Hello from Child Class "<< std::endl;
}
Child()
{
    std::cout << "Child Constructor "<< std::endl;
}
~Child(){
    std::cout << "Child Destructor "<< std::endl;
}
};


int main(){
    Child g;


    return 0;
}