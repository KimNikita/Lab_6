#include <iostream>
#include "List.h"

using namespace std;

int main()
{
  TList<int> a;
  a.InsFirst(1);
  a.Ins(a.GetFirst(), 2);
  a.InsFirst(3);
  a.InsLast(4);
  cout << a;
  return 0;
}
