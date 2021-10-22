file(GLOB SRCS CONFIGURE_DEPENDS *.cpp)
add_executable(GF2_test ${SRCS})
target_link_libraries(GF2_test PUBLIC GF2 GTest::GTest GTest::Main ${GMOCK_BOTH_LIBRARIES})

add_test(GF2_test GF2_test)
