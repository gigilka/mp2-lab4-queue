#include "pch.h"
#include "../Queue/TQueue.h"

TEST(TQueue, can_create_queue_with_positive_size_and_its_empty_and_not_full) {
	ASSERT_NO_THROW(TQueue<int> q(3));
	ASSERT_NO_THROW(TQueue<int> q(5));
	ASSERT_NO_THROW(TQueue<int> q(6));
	ASSERT_NO_THROW(TQueue<int> q(9));
	TQueue<int> q(3);
	EXPECT_TRUE(q.IsEmpty());
	EXPECT_FALSE(q.IsFull());
}
TEST(TQueue, cant_create_queue_with_non_positive_size_and_size_less_2) {
	ASSERT_ANY_THROW(TQueue<int> q(-10));
	ASSERT_ANY_THROW(TQueue<int> q(1));
	ASSERT_ANY_THROW(TQueue<int> q(0));
	ASSERT_ANY_THROW(TQueue<int> q(-1));
}
TEST(TQueue, full_empty) {
	TQueue<int> q(5);
	ASSERT_TRUE(q.IsEmpty());
	ASSERT_FALSE(q.IsFull());
	for (int i = 0; i < 4; i++) {
		q.Push(i);
	}
	ASSERT_FALSE(q.IsEmpty());
	ASSERT_FALSE(q.IsFull());
	q.Push(5);
	ASSERT_FALSE(q.IsEmpty());
	ASSERT_TRUE(q.IsFull());
}
TEST(TQueue, cant_push_full_pop_empty) {
	TQueue<int> q(2);
	ASSERT_ANY_THROW(q.Pop());
	q.Push(1);
	q.Push(2);
	ASSERT_ANY_THROW(q.Push(2));
}
TEST(TQueue, Clear) {
	TQueue<int> q(5);
	for (int i = 0; i < 5; i++) {
		q.Push(i);
	}
	ASSERT_NO_THROW(q.Clear());
	q.Clear();
	ASSERT_TRUE(q.IsEmpty());
	ASSERT_FALSE(q.IsFull());
}
TEST(TQueue, Copied) {
	TQueue<int> q(5);
	for (int i = 0; i < 5; i++) {
		q.Push(i);
	}
	ASSERT_NO_THROW(TQueue<int> copy(q));
	TQueue<int> copy(q);
	EXPECT_EQ(copy, q);
	EXPECT_EQ(copy, copy);
	TQueue<int> copy1=q;
	EXPECT_EQ(copy1, q);
	EXPECT_EQ(copy1, copy1);
	copy.Clear();
	copy1.Clear();
	for (int i = 0; i < 5; i++) {
		copy.Push(1);
		copy1.Push(1);
	}
	EXPECT_NE(copy, q);
	EXPECT_NE(copy1, q);
}
TEST(TQueue, Queue_assignation) {
	TQueue<int> q(100000);
	TQueue<int> q1(100000);
	TQueue<int> q2(23);
	for (int i = 0; i < 100000; i++) {
		q.Push(i);
	}
	q1 = q;
	q2 = q;
	EXPECT_EQ(q1, q);
	EXPECT_EQ(q2, q);
	EXPECT_EQ(q, q);
}
TEST(TQueue, Queue_comparation) {
	TQueue<int> q(100000);
	TQueue<int> q1(100000);
	TQueue<int> q2(23);
	EXPECT_EQ(q1, q);
	EXPECT_NE(q2, q);
	for (int i = 0; i < 100000; i++) {
		q.Push(i);
		q1.Push(i);
	}
	EXPECT_EQ(q1, q);
	q1.Clear();
	for (int i = 0; i < 100000; i++) {
		q1.Push(1);
	}
	EXPECT_NE(q1, q);
}