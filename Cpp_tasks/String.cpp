#include <iostream>
#include <string>
#include <array>
std::string name;
constexpr int MAX_SIZE = 10;
class String : public std::array<char,MAX_SIZE>{
public:
char *str;


String();

String(const char *str );


~String();
private:
};

String::String()
{
 str =new char();
 *str=' ';
}

String::String(const char *strr)
{
    str =new char();
    *str=*strr;
}

String::~String()
{
    delete str;
    str = nullptr;
}




int main(){
    String str1{"said"};
    std::cout << *str1.str<<std::endl;

return 0;
}