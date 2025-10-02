#include <gtest/gtest.h>
#include "../includes/swrr/swrr.hpp"
#include "../includes/server/server.hpp"


TEST(ServerTest, ConstructorAndAccessors) {
    Server s("A", 5);
    EXPECT_EQ(s.getId(), "A");
    EXPECT_EQ(s.getStaticWeight(), 5);
    EXPECT_EQ(s.getCurrentWeight(), 0);


    EXPECT_FALSE(s.setCurrentWeight(10));
    EXPECT_EQ(s.getCurrentWeight(), 10);
    EXPECT_FALSE(s.incCurrentWeight(5));
    EXPECT_EQ(s.getCurrentWeight(), 15);
    EXPECT_FALSE(s.decCurrentWeight(3));
    EXPECT_EQ(s.getCurrentWeight(), 12);
}


TEST(SWRRTest, EmptyAndSingleServer) {
    SmoothWeightedRR lb;
    auto empty_pick = lb.pick();
    EXPECT_FALSE(empty_pick.has_value());


    lb.addServer("A", 5);
    auto pick = lb.pick();
    ASSERT_TRUE(pick.has_value());
    EXPECT_EQ(*pick, "A");
}


TEST(SWRRTest, ClearAndSetWeight) {
    SmoothWeightedRR lb;
    lb.addServer("A", 2);
    lb.addServer("B", 3);


    EXPECT_FALSE(lb.setWeight(0, 7));
    lb.clear();
    EXPECT_FALSE(lb.pick().has_value());
}


TEST(SWRRTest, DistributionApprox) {
    SmoothWeightedRR lb;
    lb.addServer("A", 5);
    lb.addServer("B", 3);
    lb.addServer("C", 1);


    const int N = 90;
    std::unordered_map<std::string, int> counts;
    for (int i = 0; i < N; ++i){
        auto s = lb.pick();
        if (s) counts[*s]++;
    }
    int a = counts["A"]; int b = counts["B"]; int c = counts["C"];
    double total = a + b + c;
    ASSERT_GT(total, 0.0);
    double ra = a / total, rb = b / total, rc = c / total;
    EXPECT_NEAR(ra, 5.0/9.0, 0.25);
    EXPECT_NEAR(rb, 3.0/9.0, 0.25);
    EXPECT_NEAR(rc, 1.0/9.0, 0.25);
}


int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}