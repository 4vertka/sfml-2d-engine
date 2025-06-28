cmake_minimum_required(VERSION 3.10)
project(SFML_Try)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Use pkg-config to find SFML
find_package(PkgConfig REQUIRED)
pkg_check_modules(SFML REQUIRED sfml-graphics)

add_executable(main ./src/main.cpp ./src/engine.cpp)

# Include SFML headers
target_include_directories(main PRIVATE ${SFML_INCLUDE_DIRS})
# Link SFML libraries
target_link_libraries(main PRIVATE ${SFML_LIBRARIES})

