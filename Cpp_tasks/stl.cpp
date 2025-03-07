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
class Person{
    public:
    std::string name;
    int age;
    Person()=default;
    Person(std::string name , int age)
        :name{name},age{age}
    {}
    bool operator==(const Person &rhs){
        return ((name== rhs.name) && (age==rhs.age));
    }
   //friend std::ostream& operator<<(std::ostream &os, const Person &rhs);
   //std::ostream& operator<<(std::ostream &os);
};

std::ostream& operator<<(std::ostream &os, const Person &rhs){
    os << "[ " << rhs.name << "," << rhs.age << " ] " << std::endl;
    return os;
}

// std::ostream& Person::operator<<(std::ostream &os){
//         os << "[ " << name << "," << age << " ] " << std::endl;
//         return os;
//     }

int main(){

    std::vector<int>vec{1,2,3,4,5};
    std::list<std::string> names{"said","magdy","shhata"};

    std::cout << "-------------- List of Person ----------------"<<std::endl;
    std::list<Person>men{
        Person{"said",25},
        Person{"magdy",55},
        Person{"mohamed",16}
    };
    // for(auto man :men){
    //  std::cout <<   man.name <<std::endl;
   // }
    auto p = std::find(std::begin(men),std::end(men),Person{"said",25});
    if(p != std::end(men))
        std::cout <<   "Found " <<std::endl;  
    else
        std::cout <<   "Not Found " <<std::endl; 
    
    
    Person man{"name",18};
    std::cout << man <<std::endl;

    std::cout << "----------------List iterators ----------------"<<std::endl;
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