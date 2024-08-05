//Said Magdy
#include <iostream>
#include<algorithm>
#include <vector>

int max_num(int* arr,int size){
    int max=0,value=0; 
    for(int i=0 ;i<size;i++){  
        value=arr[i];                  //by for-based loop
        if(max < value)
            max=value;
        }
    return max;    

}



int main()
{
 int arr[]={11,52,63,94,55,76,47,28,59,10,5,89,6,1};   //as arrary 
 std::vector<int>numbers{11,52,63,94,55,76,47,28,59,10,5,89,6,1,5};  // as Vector
 int size = sizeof(arr)/sizeof(arr[0]);

 
//  int max=0;
//  [arr,&max](){                             //Use lambda and safe it to std::function
//     for(int value : arr){                           //by for-based loop
//         if(max < value)
//             max=value;
//         }
//     std::cout << "Maximum number in C  is : " << max << std::endl;    
//     }();
 std::cout << "Maximum number in C  is : " << max_num(arr,size) << std::endl;    



//******************************************************************************************************** */
//Here we use C++ modern built-in fun
  //int max_num = *std::max_element(numbers.begin(), numbers.end());
  int max_num = *std::max_element(std::begin(arr), std::end(arr));
  std::cout << "Maximum number in C++ is : " << max_num << std::endl;


//******************************************************************************************************** */
//here Find a number in array   
  int number_to_find {};
  std::cout << "Enter the number we search for : " << std::endl;
  std::cin >>number_to_find;
  //auto it = std::find(numbers.begin(), numbers.end(), number_to_find);
  auto it = std::find(std::begin(arr), std::end(arr), number_to_find);

    if (it != std::end(arr)) {
        std::cout << "The number " << number_to_find << " was found in the vector." << std::endl;
    } else {
        std::cout << "The number " << number_to_find << " was not found in the vector." << std::endl;
    }
  

//******************************************************************************************************** */
//delete number from array 
//auto ind=std::remove(numbers.begin(), numbers.end(),5);  
auto ind = std::remove(std::begin(arr), std::end(arr),11);  
size = std::distance(arr,ind);
std::cout << "the new array size is : "<< size << std::endl;
//numbers.erase(5,numbers.end());
for(auto i : arr)
    std::cout << i << " ";
std::cout <<std::endl;

//******************************************************************************************************** */


    return 0;
}