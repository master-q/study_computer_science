#include "answer.h"
#include "gtest/gtest.h"

TEST(QuickSort, Test1) {
	vector<int> a, e;
	a.push_back(1);
	e.push_back(1);
	EXPECT_EQ(e, QuickSort::sort(a));
}

TEST(QuickSort, Test2) {
	vector<int> a, e;

	a.push_back(8);
	a.push_back(4);
	a.push_back(3);
	a.push_back(7);
	a.push_back(6);
	a.push_back(5);
	a.push_back(2);
	a.push_back(1);

	e.push_back(1);
	e.push_back(2);
	e.push_back(3);
	e.push_back(4);
	e.push_back(5);
	e.push_back(6);
	e.push_back(7);
	e.push_back(8);

	EXPECT_EQ(e, QuickSort::sort(a));
}
