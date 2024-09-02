#include <iostream>
#include <tuple>
#include<vector>

//function templates
template <typename T>
T Div(T a,T b){
    return a/b;
}

template <typename T,typename U>
auto Div(T a,U b){       //should put auto cuz it didnt know what is the return type 
    return a/b;
}

//class templates
template<typename T>
class CT{
    public:
    CT(T V){
        value = V;
    }
    T value;
    void get(){
        std::cout << value << std::endl;
    }

};

template<typename T>
class CT2{
    public:
    CT2(T V){
        value = V;
    }
    T value;
    template<typename U>
    void add(U val){
        std::cout << value+val << std::endl;
    }

};
//varadic arguments

void Print(){std::cout<<"End of print"<<std::endl;}  //this for print with 0 args it is must 

template<typename X,typename... args>
void Print(X a,args... arg){
    std::cout << a << " ";
    //std::cout << sizeof...(arg)<< std::endl; // look at saizeof
    Print(arg...);
}

int main(){


    std::cout <<Div(3,2)<< std::endl;
    std::cout <<Div(3.0,2.0)<< std::endl;
    std::cout <<Div(3.0f,2.0f)<< std::endl;
    std::cout <<Div(3.0,2)<< std::endl;

    CT<std::string>ct{"said"};  //<data type> here this was must before c++17 after 17 it is auto deduction
    ct.get();
    CT2<std::string>ct2{"said "};
    ct2.add("Magdy");  // here after c++14 auto deduction  but before 14  hould be ct2.add<dataType>("Magdy");

    Print(10,5.0);
    Print(10,5.0,"said");

    std::tuple<int ,float ,std::string,std::vector<int>>t{1,2.0,"said",{1,2,3}};
    std::cout << std::get<3>(t).at(1) << std::endl;

    return 0;
}