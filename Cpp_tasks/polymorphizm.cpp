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




class Derived : public Base {
public:
//using Base::Base;     // make sure to reach all the Base constructors 
virtual void greeting()const override{    //override Keyward will make sure its overriding not a redefinition
    std::cout << "Hello from Derived Class "<< std::endl;
}
Derived()
{
    std::cout << "Derived Constructor " << std::endl;
}
Derived(int a):Base{a}
{
    std::cout << "Derived Parm Constructor " << a <<std::endl;
}
virtual ~Derived(){
    std::cout << "Derived Destructor "<< std::endl;
}
};


int main(){
//dynamic binding (late binding)
    Base *ptr = new Base();
    Derived g(5);  //Derived doesnt have parm constructor but Base has and we used the using Class::Class
std::cout << "-------------------(1)----------------" <<std::endl;
    ptr->greeting();
    ptr=&g;                         
    ptr->greeting();
std::cout << "-----------------(2)------------------" <<std::endl;
    Base obj{10};
    Base &ref = obj;
    ref.greeting();
std::cout << "------------------(3)-----------------" <<std::endl;
    Derived obj2{20};
    Base &ref2=obj2;
    ref2.greeting();
std::cout << "-------------------(4)----------------" <<std::endl;
    return 0;
} 