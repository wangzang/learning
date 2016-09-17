#include <iostream>
#include <cstring>
using namespace std;

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
		{
			cout << "\t index: " << i << " value: " << array[i] << std::endl;
			}
		
    }
private:
    typeA array[10];
    int depth;
};

int main()
{
    MyStack<char> myStack;
    myStack.push('a');
    myStack.push('b');
    myStack.push('c');
    myStack.printStack();
    auto value = myStack.pop();
	cout << "popped value: " << value << endl;
    value = myStack.pop();
	cout << "popped value: " << value << endl;
    value = myStack.pop();
    cout << "popped value: " << value << endl;
    return 1;
}