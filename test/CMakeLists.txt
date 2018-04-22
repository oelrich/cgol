include(CTest)

enable_testing()
add_library(Catch INTERFACE)
target_include_directories(Catch INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/catch)

file(GLOB_RECURSE source_list "*.cpp")

add_executable(cgol_test ${source_list})
target_link_libraries(cgol_test Catch)