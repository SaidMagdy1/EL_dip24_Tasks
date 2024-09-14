#include <iostream>

class Base {

public:
std::string name;
void greeting(){
    std::cout << "Hello from Base Class "<< std::endl;
}

int *num;
Base(){
    std::cout << "Base D Constructor" <<std::endl;
}
Base(int n , std::string name)
    :num{nullptr}
    ,name{name}
{
    num = new int(n);
    std::cout << "Base Constructor "<< std::endl;

}
~Base(){
    delete num;
    num=nullptr;
    std::cout << "Base Destructor "<< std::endl;
}

};


class Child : public Base {
public:
Child(){
    std::cout << "Child D Constructor" <<std::endl;
}
Child(std::string name):
    Base(5,name)
{
    std::cout << "Child Constructor "<< std::endl;
}
~Child(){
    std::cout << "Child Destructor "<< std::endl;
}
};

// multi-level inheritance 
class Boy : public Child {
public:
Boy(std::string name):
    Child(name)
{
    std::cout << "Boy Constructor "<< std::endl;
}
~Boy(){
    std::cout << "Boy Destructor "<< std::endl;
}
};


int main(){
    
    //Child test("said");
    Boy test2("saeed"); // look at the order of constructors from the output
    //std::cout << *test.num <<std::endl;
    std::cout << "--Name is : "<<test2.name <<std::endl;
    test2.greeting();  //make sure that Boy inherited Base

    Child T;   //will call the two Default constructors   base then child


    return 0;
}