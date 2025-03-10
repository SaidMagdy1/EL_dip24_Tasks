#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <algorithm>
#include <array>
#include <set>


// a generic displayer
template<typename T> 
void display(T container){
    std::cout << "[";
    for(const auto &con : container){
        std::cout << " "<<con ;
    }
    std::cout << " ]"<<std::endl;
}


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
    bool operator<(const Person &rhs){
        return (age < rhs.age);
    }
};

std::ostream& operator<<(std::ostream &os, const Person &rhs){
    os << "[ " << rhs.name << "," << rhs.age << " ] " << std::endl;
    return os;
}


int main(){

    std::vector<int>vec{1,2,3,4,5,6,7,8,9,10};
    std::list<std::string> names{"said","magdy","shhata"};
    std::array<int,5>arr{1,2,3,4,5};

    auto min = std::min_element(arr.begin(),arr.end());
    auto max = std::max_element(arr.begin(),arr.end());

    std::cout << "minimum: " << *min <<"  maximum: "<<*max <<std::endl;
    std::cout << "Row pointer for 1st element: " << arr.data() <<std::endl;

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

    std::cout << "-------------- Vector cases ----------------"<<std::endl;
    std::vector<int>copy(vec.size());
    std::copy(vec.begin(),vec.end(),copy.begin()); // copy vector must be sized 
    copy.emplace_back(150);
    display(copy);

    std::cout << "-------------- std::set cases ----------------"<<std::endl;
    std::set<int>si{1,4,5,6,7,1,2};
    for(auto e: si){
        std::cout <<e;
    }
    std::cout <<std::endl;
    auto it_p = si.insert(200); // in Set insert it returns pair(iterator,bool)
    std::cout << std::boolalpha <<*it_p.first<<std::endl;
    std::cout <<it_p.second<<std::endl;

    //Don't forget that set will sort so you need operator< in your class 
    // std::set<Person> s {
    //     {"said",25},
    //     {"magdy",55},
    //     {"mohamed",15}
    // };

    return 0;
}