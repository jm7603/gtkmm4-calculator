CMAKE_MINIMUM_REQUIRED(VERSION 3.27)
PROJECT(calculator_ui LANGUAGES CXX)

SET(CMAKE_CXX_STANDARD 17)

# Find packages
FIND_PACKAGE(PkgConfig REQUIRED)
PKG_CHECK_MODULES(GTKMM4 REQUIRED gtkmm-4.0)

# Add gtkmm4 header file and lib directories to search path
INCLUDE_DIRECTORIES(${GTKMM4_INCLUDE_DIRS})
LINK_DIRECTORIES(${GTKMM4_LIBRARY_DIRS})

# Add other flags to the compiler, equivalent to the following command
#   c++ `pkg-config --cflags --libs gtkmm-4.0`
ADD_COMPILE_OPTIONS(${GTKMM4_FLAGS_OTHER} )
if (CMAKE_BUILD_TYPE MATCHES Release)
    ADD_COMPILE_OPTIONS("-O3")
endif()

SET(SRC main.cpp
        src/calculator/calculator_window.cpp
        src/interpreter/token.hpp
        src/interpreter/lexer.cpp
        src/interpreter/parser.cpp)

ADD_EXECUTABLE(${PROJECT_NAME} ${SRC})
TARGET_LINK_LIBRARIES(${PROJECT_NAME} PUBLIC ${GTKMM4_LIBRARIES})
