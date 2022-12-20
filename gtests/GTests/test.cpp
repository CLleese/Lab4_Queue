#include "pch.h"
#include "../../sources/TQueue.h"


TEST(TQueue, can_create_queue_with_positive_length)
{
  ASSERT_NO_THROW(TQueue<int> q(5));
}

TEST(TQueue, throws_when_create_queue_with_negative_length)
{
  ASSERT_ANY_THROW(TQueue<int> q(-5));
}

TEST(TQueue, can_copy_queue)
{
  TQueue<int> s1(5);
  ASSERT_NO_THROW(TQueue<int> q2(s1));
}


TEST(TQueue, can_put_and_low_element)
{
  TQueue<int> q(5);
  q.Put(5);
  q.Put(6);
  EXPECT_EQ(5, q.Low());
}

TEST(TQueue, can_get_and_pop_element)
{
  TQueue<int> q(5);
  q.Put(5);
  q.Put(6);
  EXPECT_EQ(5, q.Pop());
  EXPECT_EQ(6, q.Pop());
}

TEST(TQueue, can_pop_element)
{
  TQueue<int> q(5);
  q.Put(5);
  q.Put(6);
  q.Pop();
  EXPECT_EQ(6, q.Low());
}

TEST(TQueue, can_check_for_emptyness)
{
  TQueue<int> q(5);
  EXPECT_EQ(true, q.IsEmpty());
  q.Put(11);
  EXPECT_EQ(false, q.IsEmpty());
  q.Pop();
  EXPECT_EQ(true, q.IsEmpty());
}

TEST(TQueue, can_check_for_fullness)
{
  TQueue<int> q(5);
  EXPECT_EQ(false, q.IsFull());
  q.Put(0);
  EXPECT_EQ(false, q.IsFull());
  for (int i = 1; i < 5; i++)
    q.Put(i);
  EXPECT_EQ(true, q.IsFull());
}

TEST(TQueue, cant_pop_item_from_empty_queue)
{
  TQueue<int> q(5);
  q.Put(0);
  q.Pop();
  ASSERT_ANY_THROW(q.Pop());
}


TEST(TQueue, can_assign_queue_to_itself)
{
  TQueue<int> q(5);
  ASSERT_NO_THROW(q = q);
}
