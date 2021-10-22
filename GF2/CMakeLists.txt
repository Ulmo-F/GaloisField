add_library(GF2 STATIC SmallPolynomialOverF2.cpp)
target_include_directories(GF2 PRIVATE include/GF2 INTERFACE include)
