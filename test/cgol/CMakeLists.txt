file(GLOB SRCS *.cpp)
add_executable(cgol_test ${SRCS})
target_link_libraries(cgol_test Cgol Catch)
add_test(NAME cgol_test COMMAND cgol_test)