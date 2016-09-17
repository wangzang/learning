#include <iostream>
#include <cstring>

template<typename typeA>
class MyStack
{
public:
    void push(typeA value)
    {
        array[depth++] = value;
    };
    typeA pop()
    {
        return array[depth--];
    };
private:
    typeA array[10];
    int depth;
};

int main()
{
    MyStack<int> myStack;
    return 1;
}