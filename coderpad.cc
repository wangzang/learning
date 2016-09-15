#include <iostream>
#include <cstring> // for strlen()
using namespace std;

/*
int cb(int (*fun)()) {
  return fun();
}
*/

bool always_true() {
  return false;
}

bool f( bool (*pCallbackFunction)() ) {
  return pCallbackFunction();
}

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
class IsDerivedFromHelper
{
  class No { };
  class Yes { No no[3]; };
  
  static Yes Test ( typeB* );
  static No Test  ( ... );
public:
  enum { Is = sizeof(Test(static_cast<typeA*>(0))) == sizeof(Yes) };
};

template<class classA, class classB>
bool IsDerivedFrom()
{
  return IsDerivedFromHelper<classA, classB>::Is;
};


// To execute C++, please define "int main()"
int main() {
  auto words = { "Hello, ", "World!", "\n" };
  for (const string& word : words) {
    cout << word;
  }
  
  cout << "f output: " << f(&always_true) << "\n";
  
  const char* hamster = "ham ster";
  
  cout << "25u - 50 = " << 25u - 50 << "\n";
  
  int i = 5;
  int j = i++;
  printf("i: %d, j: %d\n", i, j);
  
  foo b;
  
  {
    foo a;
    a.Assign(hamster);

    a.Print();
    printf("a.m_pString: %p, \"%s\" (%d)\n", a.m_pString, a.m_pString, __LINE__);
    printf("b.m_pString: %p, \"%s\" (%d)\n", b.m_pString, b.m_pString, __LINE__);

    b = a;
    printf("b.m_pString: %p, \"%s\" (%d)\n", b.m_pString, b.m_pString, __LINE__);
  
    for(int i = 0; i < a.m_length; i++)
    {
      //a.m_pString[i] = '\0';
    }
    printf("b.m_pString: %p, \"%s\" (%d)\n", b.m_pString, b.m_pString, __LINE__);
  }
  
  printf("b.m_pString: %p, \"%s\" (%d)\n", b.m_pString, b.m_pString, __LINE__);
  b.Print();
  
  
  {
    // size_t sz = strlen(b.m_pString);
    auto sz = (int)strlen(b.m_pString);
    cout << "sz: " << sz << "\n";

    while ( --sz >= 0 )
    {
      cout << "char: \"" << b.m_pString[sz] << "\" sz: " << sz << "\n";
    }
  }
  
  //const bool bIsDerivedFrom = IsDerivedFrom<foo, fooB>();
  const bool bIsDerivedFrom = IsDerivedFrom<fooB, foo>();
  printf("bIsDerivedFrom: %d.\n", bIsDerivedFrom);
  
  //const bool bIsSameClass = IsSameClass<fooB, foo>();
  //printf("bIsSameClass: %d.\n", bIsSameClass);
  
  return 0;
}