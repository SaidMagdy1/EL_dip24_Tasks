#include <iostream>

class Int{
public:
int value;

Int();
Int(int v);
Int(const Int &source);
~Int();

int operator++();
int operator++(int a);

private:
};
//Constructors
Int::Int(): value{0}
{
    std::cout << "Default Constructor" << std::endl;
}

Int::Int(int v):value{v}
{
    std::cout << "Param Constructor" << std::endl;
}

Int::Int(const Int &source)
{
    std::cout << "Copy Constructor" << std::endl;
}

Int::~Int()
{
    std::cout << "Destructor" << std::endl;
}

//operators
int Int::operator++()
{
    std::cout << "This is Pre operator" << std::endl;
    return value +=1;
}

int Int::operator++(int a)
{
    std::cout << "This is Post operator" << std::endl;
    int temp = value;
    value +=1;
    return temp;
}

int main(){

    Int m1;
    m1++;
    ++m1;
    std:: cout << "value : " << m1.value << std::endl;
    return 0;
}