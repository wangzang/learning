#include <iostream>
#include <cstring> // for strlen()
using namespace std;

class foo
{
public:
  int m_length;
  char* m_pString;
  void Assign(const char* pString)
  {
    m_length = strlen(pString);
    m_pString = new char[m_length];
    for(int i = 0; i < m_length; i++)
    {
      m_pString[i] = pString[i];
    }
  }
  void Print()
  {
    cout << "String: \"" << m_pString << "\"\n";
  }
};


class fooB: public foo
{
  
};

template<typename typeA, typename typeB>
struct is_same;

template<typename typeA, typename typeB>
struct is_same
{
  static const bool value = false;
};

template<typename typeA>
struct is_same<typeA, typeA>
{
  static const bool value = true;
};

template<typename classA, typename classB>
bool IsSameClass()
{
  return is_same<classA, classB>::value;
};

int main() {
    const bool bIsSameClass = IsSameClass(foo, fooB);
    std::cout << "Hello World!" << std::endl;
}
