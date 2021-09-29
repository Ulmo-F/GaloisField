#pragma once

#include <iostream>

class SmallPolynomialOverF2
{
    size_t coefs;
    friend struct Division;
public:
    explicit SmallPolynomialOverF2(size_t);
    SmallPolynomialOverF2(const SmallPolynomialOverF2&) = default;
    SmallPolynomialOverF2& operator=(const SmallPolynomialOverF2&) = default;
    bool operator==(const SmallPolynomialOverF2&) const;
    bool operator!=(const SmallPolynomialOverF2&) const;
    // bool operator<(const SmallPolynomialOverF2&);
    // int operator<=>(const SmallPolynomialOverF2& other) const { return coefs - other.coefs; }

    SmallPolynomialOverF2& operator+=(const SmallPolynomialOverF2&);
    SmallPolynomialOverF2& operator-=(const SmallPolynomialOverF2&);
    SmallPolynomialOverF2& operator*=(const SmallPolynomialOverF2&);
    SmallPolynomialOverF2& operator/=(const SmallPolynomialOverF2&);
    SmallPolynomialOverF2& operator%=(const SmallPolynomialOverF2&);

    void display(std::ostream&) const;
    int degree() const;
};

struct Division
{
    explicit Division(SmallPolynomialOverF2 a, SmallPolynomialOverF2 b);

    SmallPolynomialOverF2 quotient;
    SmallPolynomialOverF2 remainer;
};

SmallPolynomialOverF2 operator+(const SmallPolynomialOverF2&, const SmallPolynomialOverF2&);
SmallPolynomialOverF2 operator-(const SmallPolynomialOverF2&, const SmallPolynomialOverF2&);
SmallPolynomialOverF2 operator*(const SmallPolynomialOverF2&, const SmallPolynomialOverF2&);
SmallPolynomialOverF2 operator/(const SmallPolynomialOverF2&, const SmallPolynomialOverF2&);
SmallPolynomialOverF2 operator%(const SmallPolynomialOverF2&, const SmallPolynomialOverF2&);

std::ostream& operator<<(std::ostream&, const SmallPolynomialOverF2&);

// Bezout
// check taille proche 64
// gestion taille >= 64
// Use bitset<N>
struct Bezout
{
    explicit Bezout(SmallPolynomialOverF2 a, SmallPolynomialOverF2 b);

    SmallPolynomialOverF2 r;
    SmallPolynomialOverF2 u;
    SmallPolynomialOverF2 v;
};

struct BezoutLeft
{
    explicit BezoutLeft(SmallPolynomialOverF2 a, SmallPolynomialOverF2 b);

    SmallPolynomialOverF2 r;
    SmallPolynomialOverF2 u;
};
