#include <iostream>
#include <algorithm>
#include <vector>
#include <array>
#include <list>


int main(){
    std::array<int ,6>arr{1,2,3,4,5,6};
    std::vector<int>V{2,2,3,4,5,6};
    std::vector<int>sub_v{55,6};
    //int *ptr = V.begin(); //its Error cuz its iterator so use auto ptr or std::vector<int>::iterator ptr ;
    //non-modifing algorithms
    std::cout << std::all_of(V.begin(),V.end(),[](int i){return i>1;})<<std::endl; //this return true if all of elments greater than 1
    std::cout << std::any_of(V.begin(),V.end(),[](int i){return i>1;})<<std::endl; //this return true if any of elments greater than 1
    std::cout << std::for_each(V.begin(),V.end(),[](int i){std::cout<< i << std::endl;})<<std::endl;
    std::cout << "count : "<<std::count(V.begin(),V.end(),2)<<std::endl;

    auto p=std::mismatch(V.begin(),V.end(),arr.begin(),arr.end());
    std::cout << *p.first << " : " << *p.second <<std::endl;
    auto f = std::find(V.begin(),V.end(),10);   // id U want to get the pos  U can  (itrator=f) - .begin() = the pos
    if (f == V.end())      // when it is not found it returns .end() ptr
        std::cout << " not found : " <<std::endl;
    std::distance(V.begin(),f); //here also U get the position
    std::cout << *std::search(V.begin(),V.end(),sub_v.begin(),sub_v.end())<<std::endl;
    //--------

    std::vector<int>v2;
    std::transform(arr.begin(),arr.end() ,std::back_inserter(v2),[](int i){return i+1;});
    std::for_each(v2.begin(),v2.end(),[](int i){std::cout<< i <<std::endl;});

    std::cout <<"lower_bound : " <<*std::lower_bound(V.begin(),V.end(),40)<<std::endl; //note container should be sorted

    try{
        arr[10]= 10;
        throw "HM exception";
    }catch(const char *e){
        std::cout << "HM exception " << std::endl;
    }catch(std::exception const& e){
        std::cout << e.what() << std::endl;
    }catch(...){
        std::cout << "other exception " << std::endl;
        
    }


    return 0;
}