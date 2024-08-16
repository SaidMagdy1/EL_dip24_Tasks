#include <iostream>
#include <vector>

class Move{
public:

int get_value();
void set_value(int data);

Move(int data);
Move(const Move &move);
Move(Move &&move);
~Move();


private:
int* data;

};
Move::Move(int d)
    :data{nullptr}
{
    data = new int ;
    *data = d;
}

Move::Move(const Move &move)
    :Move{*move.data}
{
    std::cout << "Copy Constructor has Called.. "<< std::endl;
}

Move::Move(Move &&move)
    :data{move.data}   //here can remove this and do it in block  data = move.data then clean it (move.data = nullptr)
{
    
    move.data=nullptr;
    std::cout << "Move Constructor has Called.. "<< std::endl;

}

Move::~Move(){
    std::cout << "Destructor has Called.. "<< std::endl;
    delete data;
}

int Move::get_value(){
    return *data;
}

int main()
{
    std::vector<Move>V;
    V.push_back(Move{100});
    std::cout << V[0].get_value()<< std::endl;

    return 0;
}