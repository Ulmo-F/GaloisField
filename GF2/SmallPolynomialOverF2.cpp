#include "SmallPolynomialOverF2.h"

SmallPolynomialOverF2::SmallPolynomialOverF2(size_t val)
    : coefs(val)
{
}

void SmallPolynomialOverF2::display(std::ostream &os) const
{
    // os << "{" << coefs << "} ";
    bool first = true;
    for (int degree = (8*sizeof(size_t)-1); degree >= 0; degree--)
        if (coefs & (1ull << degree))
        {
            if ( ! first) os << " + ";
            if (degree == 0) os << "1";
            else if (degree == 1) os << "X";
            else os << "X^" << degree;
            first = false;
        }
}

SmallPolynomialOverF2& SmallPolynomialOverF2::operator+=(const SmallPolynomialOverF2& op)
{
    coefs ^= op.coefs;
    return *this;
}

SmallPolynomialOverF2& SmallPolynomialOverF2::operator-=(const SmallPolynomialOverF2& op)
{
    coefs ^= op.coefs;
    return *this;
}

SmallPolynomialOverF2& SmallPolynomialOverF2::operator*=(const SmallPolynomialOverF2& op)
{
    size_t shiftedCoefs = coefs;
    size_t otherShifted = op.coefs;
    coefs = 0;
    while (shiftedCoefs && otherShifted)
    {
        if (otherShifted & 1ull)
            coefs ^= shiftedCoefs;
        shiftedCoefs <<= 1;
        otherShifted >>= 1;
    }
    return *this;
}

SmallPolynomialOverF2& SmallPolynomialOverF2::operator/=(const SmallPolynomialOverF2& op)
{
    *this = (*this / op);
    return *this;
}

SmallPolynomialOverF2& SmallPolynomialOverF2::operator%=(const SmallPolynomialOverF2& op)
{
    *this = (*this % op);
    return *this;
}

int SmallPolynomialOverF2::degree() const
{
    size_t shiftedCoefs = coefs;
    int result = -1;
    while (shiftedCoefs)
    {
        result++;
        shiftedCoefs >>= 1;
    }
    return result;
}

SmallPolynomialOverF2 operator+(const SmallPolynomialOverF2& l, const SmallPolynomialOverF2& r)
{
    SmallPolynomialOverF2 result(l);
    result += r;
    // std::cout << "(" << l << ") + (" << r << ") = " << result << std::endl;
    return result;
}

SmallPolynomialOverF2 operator-(const SmallPolynomialOverF2& l, const SmallPolynomialOverF2& r)
{
    SmallPolynomialOverF2 result(l);
    result -= r;
    // std::cout << "(" << l << ") - (" << r << ") = " << result << std::endl;
    return result;
}

SmallPolynomialOverF2 operator*(const SmallPolynomialOverF2& l, const SmallPolynomialOverF2& r)
{
    SmallPolynomialOverF2 result(l);
    result *= r;
    // std::cout << "(" << l << ") * (" << r << ") = " << result << std::endl;
    return result;
}

SmallPolynomialOverF2 operator/(const SmallPolynomialOverF2& r, const SmallPolynomialOverF2& l)
{
    return Division(r, l).quotient;
}

SmallPolynomialOverF2 operator%(const SmallPolynomialOverF2& r, const SmallPolynomialOverF2& l)
{
    return Division(r, l).remainer;
}

std::ostream& operator<<(std::ostream& os, const SmallPolynomialOverF2& pol)
{
    pol.display(os);
    return os;
}

Division::Division(SmallPolynomialOverF2 a, SmallPolynomialOverF2 b)
    : quotient(0), remainer(a)
{
    size_t headOfA = 1ull << a.degree();
    int degreeDiff = a.degree() - b.degree();
    if (degreeDiff < 0)
        return;
    b.coefs <<= degreeDiff;
    do
    {
        quotient.coefs <<= 1;
        if (remainer.coefs & headOfA)
        {
            remainer -= b;
            quotient += SmallPolynomialOverF2(1);
        }
        headOfA >>= 1;
        b.coefs >>= 1;
    }
    while (degreeDiff--);
}

bool SmallPolynomialOverF2::operator==(const SmallPolynomialOverF2& other) const
{
    return coefs == other.coefs;
}

bool SmallPolynomialOverF2::operator!=(const SmallPolynomialOverF2& other) const
{
    return ! (*this == other);
}

Bezout::Bezout(SmallPolynomialOverF2 a, SmallPolynomialOverF2 b)
    : r(a)
    , u(1)
    , v(0)
{
    SmallPolynomialOverF2 rr(b);
    SmallPolynomialOverF2 uu(0);
    SmallPolynomialOverF2 vv(1);
    while (rr != SmallPolynomialOverF2(0))
    {
        Division div(r, rr);
        r -= div.quotient * rr;
        u -= div.quotient * uu;
        v -= div.quotient * vv;
        std::swap(r, rr);
        std::swap(u, uu);
        std::swap(v, vv);
    }
}

BezoutLeft::BezoutLeft(SmallPolynomialOverF2 a, SmallPolynomialOverF2 b)
    : r(a)
    , u(1)
{
    SmallPolynomialOverF2 rr(b);
    SmallPolynomialOverF2 uu(0);
    while (rr != SmallPolynomialOverF2(0))
    {
        Division div(r, rr);
        r -= div.quotient * rr;
        u -= div.quotient * uu;
        std::swap(r, rr);
        std::swap(u, uu);
    }
}
