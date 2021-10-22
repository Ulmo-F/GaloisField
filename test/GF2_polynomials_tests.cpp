#include <gtest/gtest.h>
// #include <gmock/gmock.h>

#include <GF2/SmallPolynomialOverF2.h>

#include <sstream>

TEST(GF2_polynomials_tests, display) {
    SmallPolynomialOverF2 One(1);
    SmallPolynomialOverF2 X(2);

    EXPECT_EQ(static_cast<std::stringstream&>(std::stringstream() << One).str(), "1");
    EXPECT_EQ(static_cast<std::stringstream&>(std::stringstream() << X).str(), "X");
    EXPECT_EQ(static_cast<std::stringstream&>(std::stringstream() << X + One).str(), "X + 1");
}

TEST(GF2_polynomials_tests, add) {
    SmallPolynomialOverF2 One(1);
    SmallPolynomialOverF2 X(2);
    SmallPolynomialOverF2 P = X + One;

    EXPECT_EQ(SmallPolynomialOverF2(3), One + X);
    EXPECT_EQ(SmallPolynomialOverF2(0), One + X + P);
}

TEST(GF2_polynomials_tests, mult) {
    SmallPolynomialOverF2 Zero(0);
    SmallPolynomialOverF2 P(3);

    EXPECT_EQ(Zero, Zero * P);
    EXPECT_EQ(SmallPolynomialOverF2(5), P*P);
}

TEST(GF2_polynomials_tests, div) {
    SmallPolynomialOverF2 A(11);
    SmallPolynomialOverF2 B(3);
    Division div(A, B);
    SmallPolynomialOverF2 One(1);
    SmallPolynomialOverF2 X(2);

    EXPECT_EQ(div.quotient, X*X+X);
    EXPECT_EQ(div.remainer, One);
}

TEST(GF2_polynomials_tests, Bezout) {
    {
        SmallPolynomialOverF2 A(11);
        SmallPolynomialOverF2 B(3);
        Bezout bez(A, B);

        EXPECT_EQ(bez.r, SmallPolynomialOverF2(1));
        EXPECT_EQ(bez.r, A*bez.u + B*bez.v);
    }

    {
        SmallPolynomialOverF2 A(8);
        SmallPolynomialOverF2 B(4);
        Bezout bez(A, B);

        EXPECT_EQ(bez.r, SmallPolynomialOverF2(4));
        EXPECT_EQ(bez.r, A*bez.u + B*bez.v);
    }
}
