#include <iostream>


class Deep{

 public:
    Deep();
    Deep(int );
    Deep(const Deep &);
    ~Deep();

    int get_data();

 private:
    int* data;
};


Deep::Deep(int d):
    data{nullptr}
{
    data = new int;
    *data = d;
    
}

Deep::Deep(const Deep &source):
    Deep{*source.data}
{
  std::cout << "Copy Constructor has Called.. "<< std::endl;
}

Deep::~Deep()
{
    delete data;
    data= nullptr;
    std::cout << "Destructor has Called.. "<< std::endl;

}
int Deep::get_data(){
    return *data;
}

void fun(Deep copy){
    std::cout << copy.get_data()<< std::endl;
}


int main()
{
    Deep test{100};
    fun(test);
    Deep test2{test};
    return 0;
}