#include <iostream>
#include <cstring>

template<typename typeA>
class MyStack<typeA>
{
public:
    MyStack();
    typeA array;
};

int main()
{
    MyStack<int> myStack;
    return 1;
}