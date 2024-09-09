#include <iostream>
#include <fstream>



int main(){

    // std::fstream file("test.txt",std::ios::in | std::ios::out | std::ios::app);
    // file << "Hello said Trunc" << std::endl;

//write in the file
    // std::ofstream file("test.txt",std::ios::app);
    // if(file.is_open()){
    //     std::cout << "file is opened successfuily";
    //     file << "of trunc" << std::endl;
    // }
    // else
    //     std::cout << "file is not opened ";

    // file.flush();
    // file.close();


//Read from the file 
    std::ifstream file("test.txt");
    if(file.is_open()){
        std::cout << "file is opened successfuily"<<std::endl;;
        std::string line;
        while (file.good())
        {
            getline(file,line);
            std::cout << line <<std::endl;
            std::cout << file.tellg() <<std::endl;
        }
        file.seekg(0); //set the cursor to the begining again
        getline(file,line);   //make sure that the cursor set to start  so get the first line again
        std::cout << line <<std::endl;

    }
    else
        std::cout << "file is not opened ";

    file.close();

 return 0;
}