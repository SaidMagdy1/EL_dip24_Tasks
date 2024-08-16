#include <iostream>

class Base {
public:
int a;
std::string name;
virtual void greeting(){
    std::cout << "Hello from Base Class "<< std::endl;
}

Base()
{
    std::cout << "Base Constructor "<< std::endl;
}
Base(int a)
{
    std::cout << "Base Constructor "<< a << std::endl;
}
~Base(){
    std::cout << "Base Destructor "<< std::endl;
}
};




class Child : public Base {
public:
using Base::Base;     // make sure to reach all the Base constructors 
virtual void greeting(){
    std::cout << "Hello from Child Class "<< std::endl;
}
Child()
{
    std::cout << "Child Constructor " << std::endl;
}
~Child(){
    std::cout << "Child Destructor "<< std::endl;
}
};


int main(){
//dynamic binding (late binding)
    Base *ptr=new Base();
    Child g(5);  //Child doesnt have parm constructor but Base has and we used the using Class::Class
    ptr->greeting();
    ptr=&g;
    ptr->greeting();

    return 0;
}