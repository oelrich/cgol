set(CGOL_SRCS
  cgol.hpp
  cgol.cpp
)

add_library(Cgol STATIC
  ${CGOL_SRCS}
)

target_include_directories(Cgol PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})