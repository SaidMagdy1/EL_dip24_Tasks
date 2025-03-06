#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <algorithm>

template<typename T>  
void fun_name(T a){
    std::cout << a+a <<std::endl;
}

struct Functor {
    void operator()(std::string a){
        std::cout << a+a <<std::endl;
    }

};


int main(){

    std::vector<int>vec{1,2,3,4,5};
    std::list<std::string> names{"said","magdy","shhata"};

    std::list<std::string>::const_iterator it1 = names.begin();
    std::list<std::string>::const_reverse_iterator it2 = names.crbegin();
    
    std::cout <<"it1 : " << *it1 << "   it2 : "<<*it2 <<std::endl;  // said     shhata
    ++it1;
    ++it2;
    std::cout <<"it1 : " << *it1 << "   it2 : "<<*it2 <<std::endl;  //magdy     magdy

    //Functor<std::string> functor;
    Functor functor;
    std::cout << "-------------- Functor ----------------"<<std::endl;
    std::for_each(names.begin(),names.end(),functor);
   
    std::cout << "-------------- Func with Template----------------"<<std::endl;
    std::for_each(names.begin(),names.end(),fun_name<std::string>);   
    std::cout << "          ---------------"<<std::endl;
    std::for_each(vec.begin(),vec.end(),fun_name<int>);


    std::cout << "-------------- Lambda Expression----------------"<<std::endl;
    std::for_each(vec.begin(),vec.end(),[](int a){std::cout <<a+a<<std::endl;});



    return 0;
}