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

TEST(S21Queue_Empty__Test, EmptyQueue) {
    S21Queue<int> queue1;

    ASSERT_TRUE(queue1.empty());
}

TEST(S21Queue_Empty__Test, NonEmptyQueue_1) {
    S21Queue<int> queue1;
    queue1.push(0);

    ASSERT_FALSE(queue1.empty());
}

TEST(S21Queue_Empty__Test, NonEmptyQueue_2) {
    S21Queue<int> queue1;
    queue1.push(0);
    queue1.push(0);

    ASSERT_FALSE(queue1.empty());
}

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);

  return RUN_ALL_TESTS();
}