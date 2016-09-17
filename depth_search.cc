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
        return array[--depth];
    };
    void printStack()
    {
        printf("Stack: \n");
        for(int i = 0; i < depth; i++)
            printf("\tindex: %d, value: %d\n", i, array[i]);
    }
private:
    //this is a set size because i can't get ctor/dtor declared correctly.
    typeA array[10];
    int depth;
};

int main()
{
    MyStack<int> myStack;
    myStack.push(3);
    myStack.push(2);
    myStack.push(1);
    myStack.printStack();
    int value = myStack.pop();
    printf("popped value: %d\n", value);
    value = myStack.pop();
    printf("popped value: %d\n", value);
    value = myStack.pop();
    printf("popped value: %d\n", value);
    return 1;
}