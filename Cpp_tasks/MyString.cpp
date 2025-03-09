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
bool operator==(const String &rhs)const;
String operator+(const String &rhs);
String &operator+=(const String &rhs);
String operator>(const String &rhs)const;
String operator>(String &&rhs);

friend std::istream& operator>>(std::istream& in,String &source);
friend std::ostream& operator<<(std::ostream& out,const String &source);

private:
};
//----------------------------------
//here the friend i&o stream operator overloading
std::istream& operator>>(std::istream& in,String &source){
    in >> source.str ;
    return in;
}

std::ostream& operator<<(std::ostream& out,const String &source){
    out << source.str ;
    return out;
}
// here the operators 

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

String String::operator+(const String &rhs) {
    std::cout << "------It is + Operator" << std::endl;
    size_t buff_size= std::strlen(str)+std::strlen(rhs.str)+1;
    char *buff = new char[buff_size];
    std::strcpy(buff,str);
    std::strcat(buff,rhs.str);
    String temp{buff};
    delete[] buff;
    return temp;
}
String &String::operator+=(const String &rhs){
      *this = *this + rhs;
      return *this;         
}

bool String::operator==(const String &rhs)const{
    std::cout << "------It is == Operator" << std::endl;
    return (std::strcmp(str,rhs.str)==0); 
}

String String::operator>(const String &rhs)const{
    if(std::strcmp(str,rhs.str)==0){
        std::cout << " Both are equal ";
        return "equal";
    }
    else  if(std::strcmp(str,rhs.str)>0){
        std::cout << str<< " greater than "<< rhs.str << std::endl;
        return "greater";
    }
    else{
        std::cout << str<< " is not greater than "<< rhs.str << std::endl;
        return "less";
    }
}
String String::operator>(String &&rhs){
    std::cout << "the R-V grater operator \n";
    if(std::strcmp(str,rhs.str)==0){
        std::cout << " Both are equal ";
        return "equal";
    }
    else if (std::strcmp(str,rhs.str)>0){
        std::cout << str<< " greater than "<< rhs.str << std::endl;
        return "greater";
    }
    else{
        std::cout << str<< " is not greater than "<< rhs.str << std::endl;
        return "less";
    }
}


char* String::get_string(){return str;}
//  here the Constructors
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

}



int main(){
std::cout << "************************"<<std::endl; 
    String str1{"said"};
    String str2;
std::cout << "************************"<<std::endl;
    str2 = str1;
    std::cout << str2.get_string()<<std::endl;
std::cout << "************************"<<std::endl;
    String str3;
    str3 = "Magdy";
    std::cout << str2.get_string()<<std::endl;
std::cout << "************************"<<std::endl;
    str2 =String{"shehata"};
    std::cout << str2.get_string()<<std::endl;
std::cout << "************************"<<std::endl;
    String str4{"said"};
    if (str1 == str4)
        std::cout << "They are equal"<<std::endl;
std::cout << "************************"<<std::endl;
    String str5;
    str5 = str1+str2 ;
    std::cout <<str5.get_string() <<std::endl;
std::cout << "************************"<<std::endl;
String cmp= str1 > str3;
cmp= str1 > String{"said"};

cmp+=str1;
std::cout <<cmp.get_string() <<std::endl;

String inText;
std::cin >> inText;
std::cout <<"here ostream operator<<" <<inText<<std::endl;


return 0;
}