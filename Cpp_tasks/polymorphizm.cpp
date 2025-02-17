#include <iostream>

class Base {
public:
int a;
std::string name;
virtual void greeting() const{
    std::cout << "Hello from Base Class "<< std::endl;
}

Base()
{
    std::cout << "Base Constructor "<< std::endl;
}
Base(int a)
{
    std::cout << "Base Parm Constructor "<< a << std::endl;
}

//whenever use virtual fun U should use virtual destructor as well .
virtual ~Base(){
    std::cout << "Base Destructor "<< std::endl;
}
};




class Child : public Base {
public:
using Base::Base;     // make sure to reach all the Base constructors 
virtual void greeting()const override{    //override Keyward will make sure its overriding not a redefinition
    std::cout << "Hello from Child Class "<< std::endl;
}
Child()
{
    std::cout << "Child Constructor " << std::endl;
}
Child(int a):Base{a}
{
    std::cout << "Child Parm Constructor " << a <<std::endl;
}
virtual ~Child(){
    std::cout << "Child Destructor "<< std::endl;
}
};


int main(){
//dynamic binding (late binding)
    Base *ptr=new Base();
    Child g(5);  //Child doesnt have parm constructor but Base has and we used the using Class::Class
std::cout << "-----------------------------------" <<std::endl;
    ptr->greeting();
    ptr=&g;
    ptr->greeting();
std::cout << "-----------------------------------" <<std::endl;
    Base obj{10};
    Base &ref = obj;
    ref.greeting();
std::cout << "-----------------------------------" <<std::endl;
    Child obj2{20};
    Base &ref2=obj2;
    ref2.greeting();
std::cout << "-----------------------------------" <<std::endl;
    return 0;
}