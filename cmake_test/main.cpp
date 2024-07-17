#include <iostream>
#include <string.h>
#include "calc.hpp"
#include "base.hpp"
#include <vector>
#include "defaultConfig.h"

int main()
{

#ifdef DEBUGINFO
    std::cout<<DEBUGINFO<<std::endl;
#endif // DEBUG

    std::vector<int>nums = {1,2,3,4,5,6};
std::string name = "said";
std::cout <<"here is my name :"<<name <<" ** -> sum: "<<sum(1.3,1.2)<<std::endl;
base_INIT();

std::cout <<"here is my name :"<<  nums.size() <<std::endl;

return 0;
}