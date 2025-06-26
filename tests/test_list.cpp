#include <gtest/gtest.h>  
#include "../implementation/list.hpp"

using namespace blgt;

TEST(ListTest, EmptyListInitially) {
    list l;
    EXPECT_TRUE(l.empty());
    EXPECT_EQ(l.size(), 0);
}

TEST(ListTest, InsertFrontIncreasesSize) {
    list l;
    l.insert_front(10);
    EXPECT_FALSE(l.empty());
    EXPECT_EQ(l.size(), 1);
}

TEST(ListTest, InsertBackIncreasesSize) {
    list l;
    l.insert_back(20);
    EXPECT_EQ(l.size(), 1);
}

TEST(ListTest, EraseFrontRemovesElement) {
    list l;
    l.insert_front(5);
    l.erase_front();
    EXPECT_TRUE(l.empty());
}

TEST(ListTest, EraseBackRemovesElement) {
    list l;
    l.insert_back(7);
    l.erase_back();
    EXPECT_TRUE(l.empty());
}

TEST(ListTest, MultipleInsertionsCorrectSize) {
    list l;
    for (int i = 0; i < 5; ++i) l.insert_back(i);
    EXPECT_EQ(l.size(), 5);
}

TEST(ListTest, IteratorTraversesElements) {
    list l;
    l.insert_back(1);
    l.insert_back(2);
    l.insert_back(3);

    auto it = l.begin();
    EXPECT_EQ(*it, 1);
    ++it;
    EXPECT_EQ(*it, 2);
    ++it;
    EXPECT_EQ(*it, 3);
}

TEST(ListTest, IteratorEquality) {
    list l;
    EXPECT_TRUE(l.begin() == l.end());

    l.insert_back(9);
    EXPECT_FALSE(l.begin() == l.end());
}

TEST(ListTest, IteratorInequality) {
    list l;
    l.insert_back(11);
    EXPECT_TRUE(l.begin() != l.end());
}

TEST(ListTest, InsertFrontCorrectOrder) {
    list l;
    l.insert_front(1);
    l.insert_front(2);
    l.insert_front(3); 
    auto it = l.begin();
    EXPECT_EQ(*it, 3); ++it;
    EXPECT_EQ(*it, 2); ++it;
    EXPECT_EQ(*it, 1);
}
