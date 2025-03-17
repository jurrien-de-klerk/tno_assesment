enable_testing()

add_executable(unit_tests test_subject.cpp)
target_link_libraries(unit_tests gtest_main gtest gmock_main gmock infra model)
add_test(NAME unit_tests COMMAND unit_tests)
