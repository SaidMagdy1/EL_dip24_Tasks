#include <iostream>

class Shallow{
private:
    int data;    // The Problem with Shallow if this data is a Raw Pointer 
                 // you will be pointing to same pointer for the copied obj too!
public:
    Shallow(){ std::cout<<"Def Constructor \n";}
    ~Shallow(){ std::cout<<"Destructor \n";}
    Shallow(const Shallow& sourse)
        : data{sourse.data}
    {
        std::cout<<"Shallow constructor \n";
    }
};

void fun_Shallow(Shallow m_Shallow){
    std::cout<<"the fun_Shallow \n";
}

int main(){

    Shallow copy;
    fun_Shallow(copy);
    return 0;
}