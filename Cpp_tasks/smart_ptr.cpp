#include <iostream>
#include <memory>

int main(){
//unique_pointer
    std::unique_ptr<int>p=std::make_unique<int>(100);
    std::unique_ptr<int>p2=std::make_unique<int>(10);
    p = std::move(p2);

    std::cout <<"the value is : "<< *p<<std::endl;
    std::cout <<"the Raw ptr is : "<< p.get()<<std::endl;

//shared_pointer
    std::shared_ptr<int>sp=std::make_shared<int>(100);
    std::shared_ptr<int>sp2=std::make_shared<int>(10);
    //sp = std::move(sp2);
    sp = sp2 ; // it works cuz it is shared

    std::cout <<"the value is : "<< *sp<<std::endl;
    std::cout <<"the Count is : "<< sp.use_count()<<std::endl;
    sp2.reset();
    std::cout <<"the Count is : "<< sp.use_count()<<std::endl;


    return 0;
}