#include "SmallPolynomialOverF2.h"
#include <stdexcept>

template<size_t pol>
class FiniteFieldOverF2
{
    // TODO static_assert(pol irreductible)

    SmallPolynomialOverF2 value;

public:
    explicit FiniteFieldOverF2();
    explicit FiniteFieldOverF2(size_t);
    FiniteFieldOverF2(const FiniteFieldOverF2&) = default;
    FiniteFieldOverF2& operator=(const FiniteFieldOverF2&) = default;
    bool operator==(const FiniteFieldOverF2&) const;
    bool operator!=(const FiniteFieldOverF2&) const;
    // bool operator<(const FiniteFieldOverF2&);
    // int operator<=>(const FiniteFieldOverF2& other) const { return coefs - other.coefs; }

    FiniteFieldOverF2& operator+=(const FiniteFieldOverF2&);
    FiniteFieldOverF2& operator-=(const FiniteFieldOverF2&);
    FiniteFieldOverF2& operator*=(const FiniteFieldOverF2&);
    FiniteFieldOverF2& operator/=(const FiniteFieldOverF2&);

    void display(std::ostream&) const;
};

template<size_t pol>
FiniteFieldOverF2<pol>& FiniteFieldOverF2<pol>::operator+=(const FiniteFieldOverF2<pol>& op)
{
    value += op.value;
    return *this;
}

template<size_t pol>
FiniteFieldOverF2<pol>& FiniteFieldOverF2<pol>::operator-=(const FiniteFieldOverF2<pol>& op)
{
    value -= op.value;
    return *this;
}

template<size_t pol>
FiniteFieldOverF2<pol>& FiniteFieldOverF2<pol>::operator*=(const FiniteFieldOverF2<pol>& op)
{
    value *= op.value;
    value %= SmallPolynomialOverF2(pol);
    return *this;
}

template<size_t pol>
FiniteFieldOverF2<pol>& FiniteFieldOverF2<pol>::operator/=(const FiniteFieldOverF2<pol>& op)
{
    if (op.value == SmallPolynomialOverF2(0))
        throw std::runtime_error("Division by zero");
    auto truc = SmallPolynomialOverF2(pol);
    Bezout bez(truc, op.value);
    // BezoutLeft bez(SmallPolynomialOverF2(pol), op.value);
    value *= bez.v;
    return *this;
}

template<size_t pol>
FiniteFieldOverF2<pol> operator+(const FiniteFieldOverF2<pol>& l, const FiniteFieldOverF2<pol>& r)
{
    FiniteFieldOverF2<pol> result(l);
    result += r;
    return result;
}

template<size_t pol>
FiniteFieldOverF2<pol> operator-(const FiniteFieldOverF2<pol>& l, const FiniteFieldOverF2<pol>& r)
{
    FiniteFieldOverF2<pol> result(l);
    result -= r;
    return result;
}

template<size_t pol>
FiniteFieldOverF2<pol> operator*(const FiniteFieldOverF2<pol>& l, const FiniteFieldOverF2<pol>& r)
{
    FiniteFieldOverF2<pol> result(l);
    result *= r;
    return result;
}

template<size_t pol>
FiniteFieldOverF2<pol> operator/(const FiniteFieldOverF2<pol>& l, const FiniteFieldOverF2<pol>& r)
{
    FiniteFieldOverF2<pol> result(l);
    result /= r;
    return result;
}

template<size_t pol>
void FiniteFieldOverF2<pol>::display(std::ostream& os) const
{
    value.display(os);
}

template<size_t pol>
std::ostream& operator<<(std::ostream& os, const FiniteFieldOverF2<pol>& op)
{
    op.display(os);
    return os;
}

template<size_t pol>
FiniteFieldOverF2<pol>::FiniteFieldOverF2()
    : value(0)
{
}

template<size_t pol>
FiniteFieldOverF2<pol>::FiniteFieldOverF2(size_t v)
    : value(v % pol)
{
}

template<size_t pol>
bool FiniteFieldOverF2<pol>::operator==(const FiniteFieldOverF2<pol>& other) const
{
    return value == other.value;
}

template<size_t pol>
bool FiniteFieldOverF2<pol>::operator!=(const FiniteFieldOverF2<pol>& other) const
{
    return ! (*this == other);
}
