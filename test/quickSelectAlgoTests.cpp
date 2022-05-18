#include "gtest/gtest.h"
#include "quickSelectAlgo.h"

TEST(QuickSelectALgoTests, QuickSelectOperationTest)
{
    std::vector<int> list{10, 2, 11, 6, 2};
    EXPECT_EQ(quickSelectOperation(list, 0, list.size() - 1), 3);
    std::vector<int> list1{10, 2, 11, 6, 2, 1, 5, 12, 22};
    EXPECT_EQ(quickSelectOperation(list1, 0, list1.size() - 1), 5);
    std::vector<int> list2{50, 2, 11, 0, 2, 1, 5, 12, 8};
    EXPECT_EQ(quickSelectOperation(list2, 0, list2.size() - 1), 8);
    std::vector<int> list3{15, 13, 11, 6, 2, 19, 5, 12, 22};
    EXPECT_EQ(quickSelectOperation(list3, 0, list3.size() - 1), 6);
    std::vector<int> list4{1, 13, 11, 6, 2, 19, 5, 12, 22};
    EXPECT_EQ(quickSelectOperation(list4, 0, list4.size() - 1), 0);
    std::vector<int> list5{15, 13};
    EXPECT_EQ(quickSelectOperation(list5, 0, list5.size() - 1), 1);
}

TEST(QuickSelectALgoTests, QuickSelectFinalTest)
{
    std::vector<int> list{10, 2, 11, 6, 2};
    EXPECT_EQ(quickSelect(list, 3), 6);
    std::vector<int> list1{10, 2, 11, 6, 3, 1, 5, 12, 22};
    EXPECT_EQ(quickSelect(list1, 4), 5);
/*    std::vector<int> list2{50, 2, 11, 0, 2, 1, 5, 12, 8};
    EXPECT_EQ(quickSelectOperation(list2, 0, list2.size() - 1), 8);
    std::vector<int> list3{15, 13, 11, 6, 2, 19, 5, 12, 22};
    EXPECT_EQ(quickSelectOperation(list3, 0, list3.size() - 1), 6);
    std::vector<int> list4{1, 13, 11, 6, 2, 19, 5, 12, 22};
    EXPECT_EQ(quickSelectOperation(list4, 0, list4.size() - 1), 0);
    std::vector<int> list5{15, 13};
    EXPECT_EQ(quickSelectOperation(list5, 0, list5.size() - 1), 1);
*/}