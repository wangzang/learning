#include <iostream>
#include <cstring> // for strlen()
using namespace std;

class foo{};
class fooB: public foo {};

template<typename typeA, typename typeB>
struct is_the_same;

template<typename typeA, typename typeB>
struct is_the_same
{
  static const bool value = false;
};

template<typename typeA>
struct is_the_same<typeA, typeA>
{
  static const bool value = true;
};

template<typename classA, typename classB>
const bool IsSameClass()
{
  return is_the_same<classA, classB>::value;
};

template<typename classA, typename classB>
const bool IsSameClass(const char* pClassA, const char* pClassB)
{
  const bool bTheSame = is_the_same<classA, classB>::value;
  printf("Checking '%s' and '%s' and they are %s\n", pClassA, pClassB, bTheSame ? "the same." : "different.");
  return is_the_same<classA, classB>::value;
};

//let's get the type, and the name of the type in a const char*
#define IS_SAME_CLASS(A, B) IsSameClass<A, B>(#A, #B)

int main() {
    const bool bIsSameClass = IsSameClass<foo, fooB>();
    std::cout << "bIsSameClass? " << (bIsSameClass ? "true" : "false") << std::endl;
    
    const bool bIsSameClassB = IS_SAME_CLASS(foo, fooB);

    return 1;
}
