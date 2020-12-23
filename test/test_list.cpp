#include "list.h"

#include <gtest.h>

TEST(List, can_do_push_back) {
	List<int> list;
	list.push_back(0);
	list.push_back(1);
	EXPECT_EQ(1, list.GetLast());
}

TEST(List, can_do_push_front) {
	List<int> list;
	list.push_front(0);
	list.push_front(1);
	EXPECT_EQ(1, list.GetFirst());
}

TEST(List, can_do_pop_back) {
	List<int> list;
	list.push_back(0);
	list.push_back(1);
	list.pop_back();
	EXPECT_EQ(0, list.GetLast());
}

TEST(List, can_do_pop_front) {
	List<int> list;
	list.push_front(0);
	list.push_front(1);
	list.pop_front();
	EXPECT_EQ(0, list.GetFirst());
}

TEST(List, cant_do_pop_back_when_list_is_empty) {
	List<int> list;
	ASSERT_ANY_THROW(list.pop_back());
}

TEST(List, cant_do_pop_front_when_list_is_empty) {
	List<int> list;
	ASSERT_ANY_THROW(list.pop_front());
}

TEST(List, true_when_list_is_empty) {
	List<int> list;
	EXPECT_EQ(1, list.IsEmpty());
}

TEST(List, false_when_list_isnt_empty) {
	List<int> list;
	list.push_front(0);
	EXPECT_EQ(0, list.IsEmpty());
}



 