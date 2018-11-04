add_subdirectory(cgol)

add_executable(cgolapp console.cpp)
target_link_libraries(cgolapp Cgol)