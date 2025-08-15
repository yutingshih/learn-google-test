#include <gtest/gtest.h>

int factorial(int);

TEST(FactorialTest, HandleZeroInput) {
    EXPECT_EQ(factorial(0), 1);
}

TEST(FactorialTest, HandlePositiveInput) {
    EXPECT_EQ((factorial(1)), 1);
    EXPECT_EQ((factorial(2)), 2);
    EXPECT_EQ((factorial(3)), 6);
    EXPECT_EQ((factorial(8)), 40320);
}
