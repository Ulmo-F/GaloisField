#include <gtest/gtest.h>
// #include <gmock/gmock.h>

#include <GF2/FiniteFieldOverF2.h>

#include <sstream>

TEST(GF2_tests, elements) {
    FiniteFieldOverF2<7> Zero(0);
    FiniteFieldOverF2<7> One(1);
    FiniteFieldOverF2<7> A(2);
    FiniteFieldOverF2<7> B(3);
    FiniteFieldOverF2<7> Zero2(0);
    FiniteFieldOverF2<7> One2(1);
    FiniteFieldOverF2<7> A2(2);
    FiniteFieldOverF2<7> B2(3);

    EXPECT_EQ(Zero, Zero2);
    EXPECT_EQ(One, One2);
    EXPECT_EQ(A, A2);
    EXPECT_EQ(B, B2);
    EXPECT_NE(Zero, One);
    EXPECT_NE(Zero, A);
    EXPECT_NE(Zero, B);
    EXPECT_NE(One, A);
    EXPECT_NE(One, B);
    EXPECT_NE(A, B);
}

TEST(GF2_tests, add) {
    FiniteFieldOverF2<7> Zero(0);
    FiniteFieldOverF2<7> One(1);
    FiniteFieldOverF2<7> A(2);
    FiniteFieldOverF2<7> B(3);

    EXPECT_EQ(One+Zero, One);
    EXPECT_EQ(A+Zero, A);
    EXPECT_EQ(B+Zero, B);
    EXPECT_EQ(A+A, Zero);
    EXPECT_EQ(One+One, Zero);
    EXPECT_EQ(B+B, Zero);
    EXPECT_EQ(A+One, B);
    EXPECT_EQ(B+One, A);
}

TEST(GF2_tests, mult) {
    FiniteFieldOverF2<7> Zero(0);
    FiniteFieldOverF2<7> One(1);
    FiniteFieldOverF2<7> A(2);
    FiniteFieldOverF2<7> B(3);

    EXPECT_EQ(A*Zero, Zero);
    EXPECT_EQ(B*Zero, Zero);
    EXPECT_EQ(One * Zero, Zero);
    EXPECT_EQ(A*One, A);
    EXPECT_EQ(One*B, B);
    EXPECT_EQ(A*A, B);
    EXPECT_EQ(B*B, A);
}

TEST(GF2_tests, div) {
    FiniteFieldOverF2<7> Zero(0);
    FiniteFieldOverF2<7> One(1);
    FiniteFieldOverF2<7> A(2);
    FiniteFieldOverF2<7> B(3);

    EXPECT_EQ(Zero/A, Zero);
    EXPECT_EQ(Zero/B, Zero);
    EXPECT_EQ(Zero/One, Zero);
    EXPECT_EQ(A/One, A);
    EXPECT_EQ(One/B, A);
    EXPECT_EQ(A/A, One);
}
