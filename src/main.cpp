#include "SmallPolynomialOverF2.h"

#include <iomanip>

int main()
{
    // size_t i = 65538;
    // for (int v = 0; v < 70; ++v)
    //     std::cout << std::hex << (i << v) << std::endl;
    SmallPolynomialOverF2 One(1);
    SmallPolynomialOverF2 X(2);
    SmallPolynomialOverF2 P = X + One;
    std::cout << "One: " << One << std::endl;
    std::cout << "X: " << X << std::endl;
    std::cout << "P: " << P << std::endl;
    std::cout << "P^2: " << P*P << std::endl;
    SmallPolynomialOverF2 A = X*X*X+X+One;
    SmallPolynomialOverF2 B = X + One;
    std::cout << "A: " << A << std::endl;
    std::cout << "B: " << B << std::endl;
    Division div(A, B);
    std::cout << A << " / " << B << " : " << div.quotient << " [" << div.remainer << "]" << std::endl;

    Bezout bez(A, B);
    std::cout << "R: " << bez.r << std::endl;
    std::cout << "U: " << bez.u << std::endl;
    std::cout << "V: " << bez.v << std::endl;
    return 0;
}
