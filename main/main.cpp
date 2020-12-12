#include <iostream>
#include "Stack.h"
#include "Queue.h"

int main()
{
  TList<int> s(3);
  TQueue<int> q(3);
  s.Push(1);
  s.Push(2);
  s.Push(3);
  s.Pop();
  cout << s << endl;
  q.Push(1);
  q.Push(2);
  q.Push(3);
  q.Pop();
  q.Push(4);
  cout << q;

  return 0;
}
