#include <iostream>
#include <cstring>

class String{
public:
char *str;
//Rule of 5
String();
String(const char *str );
String(const String &source);
String(String &&source);
~String();

char* get_string();

//Operator Overloading

String& operator=(const String &rhs);
String& operator=(String &&rhs);

private:
};
//----------------------------------

String& String::operator=(const String &rhs){
    std::cout << "Copy Assignment" << std::endl;
    if(this == &rhs)
        return *this;
    delete[] str;
    str= new char[std::strlen(rhs.str)+1];
    std::strcpy(str,rhs.str);
    return *this;
}

String& String::operator=(String &&rhs){
    std::cout << "Move Assignment" << std::endl;
    if(this == &rhs)
        return *this;
    delete[] str;
    str = rhs.str ;
    rhs.str = nullptr;
    return *this;
}


char* String::get_string(){return str;}

String::String()
    :str{nullptr}
{
    std::cout << "Default Constructor" << std::endl;
 str = new char[1];
  *str = '\0';
}

String::String(const char *strr)
    :str{nullptr}
{
    std::cout << "Paramet Constructor" << std::endl;
   if(strr == nullptr){
    str = new char[1];
    *str = '\0';
   }
   else{
    str = new char[std::strlen(strr)+1];
    std::strcpy(str,strr);
   }
}

String::String(const String &source)
    :str{nullptr}
{
    std::cout << "Copy Constructor" << std::endl;
    str = new char[std::strlen(source.str)+1];
    std::strcpy(str,source.str);
}


String::String(String &&source)
    :str{nullptr}
{
    std::cout << "Move Constructor" << std::endl;
    str = new char[std::strlen(source.str)+1];
    std::strcpy(str,source.str);
    delete[] source.str; 
    source.str = nullptr;
}


String::~String()
{
    std::cout << "Destructor" << std::endl;
    delete[] str;
    str = nullptr;
}



int main(){
    String str1{"said"};
    String str2;
    str2 = str1;
    std::cout << str2.get_string()<<std::endl;
    str2 = "Magdy";
    std::cout << str2.get_string()<<std::endl;
    str2 =String{"shehata"};
    std::cout << str2.get_string()<<std::endl;

return 0;
}