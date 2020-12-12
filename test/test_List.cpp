#include "List.h"
#include <fstream>
#include <../gtest/gtest.h>

TEST(TList, can_create_list_positive_size)
{
  ASSERT_NO_THROW(TList<int>(3));
}

TEST(TList, throw_when_create_list_negative_size)
{
  ASSERT_ANY_THROW(TList<int>(-3));
}

TEST(TList, can_push_any_elements)
{
  TList<int> S(4);
  S.Push(1);
  S.Push(2);
  EXPECT_EQ(2, S.Get());
}

TEST(TList, can_pop_any_elements)
{
  TList<int> S(4);
  S.Push(1);
  S.Push(2);
  S.Push(3);
  S.Pop();
  S.Pop();
  EXPECT_EQ(1, S.Get());
}

//доп задачи

TEST(TList, can_find_max_element)
{
  TList<int> S(4);
  S.Push(1);
  S.Push(2);
  S.Push(-1);
  EXPECT_EQ(2, S.GetMaxElem());
}

TEST(TList, can_find_min_element)
{
  TList<int> S(4);
  S.Push(1);
  S.Push(2);
  S.Push(-1);
  EXPECT_EQ(-1, S.GetMinElem());
}

TEST(TList, can_write_list_to_file)
{
  const int size = 9;
  TList<int> S(size);
  for (int i = 0; i < size / 2; i++)
    S.Push(i);
  S.WriteToFile("output_s.txt");
  string expS = "0123";
  string Stack = "";
  ifstream fin("output_s.txt");
  fin >> Stack;
  fin.close();
  EXPECT_EQ(expS, Stack);
}


