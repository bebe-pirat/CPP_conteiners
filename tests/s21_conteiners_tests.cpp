#include "../include/s21_queue.h"
#include "../include/s21_set.h"

#include <gtest/gtest.h>

TEST(S21QueueConstructor__Test, Constructor_zero_parameters) {
    S21Queue<int> queue1;

    ASSERT_EQ(queue1.size(), 0);
}

TEST(S21QueueConstructor__Test, Constructor_copy) {
    S21Queue<int> queue1;
    queue1.push(7);
    S21Queue<int> queue2(queue1);

    ASSERT_EQ(queue2.size(), 1);
    ASSERT_EQ(queue2.front(), 7);
    ASSERT_EQ(queue2.back(), 7);
}

TEST(S21QueueEmpty__Test, EmptyQueue) {
    S21Queue<int> queue1;

    ASSERT_TRUE(queue1.empty());
}

TEST(S21QueueEmpty__Test, NonEmptyQueue_1) {
    S21Queue<int> queue1;
    queue1.push(0);

    ASSERT_FALSE(queue1.empty());
}

TEST(S21QueueEmpty__Test, NonEmptyQueue_2) {
    S21Queue<int> queue1;
    queue1.push(0);
    queue1.push(0);

    ASSERT_FALSE(queue1.empty());
}

TEST(S21QueueSize__Test, EmptyQueue) {
    S21Queue<int> queue1;

    ASSERT_EQ(queue1.size(), 0);
}

TEST(S21QueueSize__Test, NonEmptyQueue_1) {
    S21Queue<int> queue1;
    queue1.push(0);

    ASSERT_EQ(queue1.size(), 1);
}

TEST(S21QueueSize__Test, NonEmptyQueue_2) {
    S21Queue<int> queue1;
    queue1.push(0);
    queue1.push(0);

    ASSERT_EQ(queue1.size(), 2);
}

TEST(S21QueueSize__Test, NonEmptyQueue_3) {
    S21Queue<int> queue1;
    queue1.push(0);
    queue1.push(0);
    queue1.pop();

    ASSERT_EQ(queue1.size(), 1);
}

TEST(S21QueuePush__Test, AddElemetToQueue) {
    S21Queue<double> queue1;
    queue1.push(1.1);

    ASSERT_FALSE(queue1.empty());
    ASSERT_EQ(queue1.size(), 1);
    ASSERT_DOUBLE_EQ(queue1.front(), 1.1);
    ASSERT_DOUBLE_EQ(queue1.back(), 1.1);
}

TEST(S21QueuePush__Test, AddTwoElemetsToQueue) {
    S21Queue<double> queue1;
    queue1.push(1.1);
    queue1.push(2.2);

    ASSERT_FALSE(queue1.empty());
    ASSERT_EQ(queue1.size(), 2);
    ASSERT_DOUBLE_EQ(queue1.front(), 1.1);
    ASSERT_DOUBLE_EQ(queue1.back(), 2.2);
}

TEST(S21QueuePush__Test, AddTenElemetsToQueue) {
    S21Queue<double> queue1;
    queue1.push(1.1);
    queue1.push(2.2);
    queue1.push(3.3);
    queue1.push(4.4);
    queue1.push(5.5);
    queue1.push(6.6);
    queue1.push(7.7);
    queue1.push(8.8);
    queue1.push(9.9);
    queue1.push(10.1);

    ASSERT_FALSE(queue1.empty());
    ASSERT_EQ(queue1.size(), 10);
    ASSERT_DOUBLE_EQ(queue1.front(), 1.1);
    ASSERT_DOUBLE_EQ(queue1.back(), 10.1);
}

TEST(S21QueuePop__Test, RemoveElemetFromQueue_1) {
    S21Queue<double> queue1;
    queue1.push(1.1);
    queue1.pop();

    ASSERT_TRUE(queue1.empty());
    ASSERT_EQ(queue1.size(), 0);
}

TEST(S21QueuePop__Test, RemoveElemetFromQueue_2) {
    S21Queue<double> queue1;
    queue1.push(1.1);
    queue1.push(2.2);
    queue1.push(3.3);
    queue1.pop();

    ASSERT_FALSE(queue1.empty());
    ASSERT_EQ(queue1.size(), 2);
    ASSERT_DOUBLE_EQ(queue1.front(), 2.2);
    ASSERT_DOUBLE_EQ(queue1.back(), 3.3);
}

TEST(S21QueuePop__Test, RemoveTwoElemetsToQueue) {
    S21Queue<double> queue1;
    queue1.push(1.1);
    queue1.push(2.2);
    queue1.push(3.3);
    queue1.push(4.4);
    queue1.push(5.5);
    queue1.push(6.6);
    queue1.push(7.7);
    queue1.push(8.8);
    queue1.push(9.9);
    queue1.push(10.1);
    queue1.pop();
    queue1.pop();

    ASSERT_FALSE(queue1.empty());
    ASSERT_EQ(queue1.size(), 8);
    ASSERT_DOUBLE_EQ(queue1.front(), 3.3);
    ASSERT_DOUBLE_EQ(queue1.back(), 10.1);
}

TEST(S21QueuePop__Test, RemoveElementFromEmptyQueue) {
    S21Queue<double> queue1;
 
    ASSERT_ANY_THROW(queue1.pop());
}

TEST(S21QueueFront___Test, GetFirstElementFromQueue_1) {
    S21Queue<double> queue1;
    queue1.push(1.1);
    queue1.push(2.2);

    ASSERT_DOUBLE_EQ(queue1.front(), 1.1);
}

TEST(S21QueueFront___Test, GetFirstElementFromQueue_2) {
    S21Queue<double> queue1;
    queue1.push(1.1);
    queue1.push(2.2);
    queue1.pop();

    ASSERT_DOUBLE_EQ(queue1.front(), 2.2);
}

TEST(S21QueueFront___Test, GetFirstElementFromEmptyQueue) {
    S21Queue<double> queue1;

    ASSERT_ANY_THROW(queue1.front());
}

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);

  return RUN_ALL_TESTS();
}