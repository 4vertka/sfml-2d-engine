cmake_minimum_required(VERSION 3.10)
project(SFML_Try)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(PkgConfig REQUIRED)
pkg_check_modules(SFML REQUIRED sfml-graphics sfml-audio sfml-window sfml-system)
if(POLICY CMP0072)
  cmake_policy(SET CMP0072 NEW)
endif()
find_package(OpenGL REQUIRED)

set(IMGUI_SRC
  ./imgui-sfml/imgui-SFML.cpp
)

add_executable(main
  ./src/main.cpp
  ./src/engine.cpp
  ./src/tilemap.cpp
  ./src/player.cpp
  ./src/camera.cpp
  ./src/levelState.cpp
  ${IMGUI_SRC}
)

target_include_directories(main PRIVATE
  ${SFML_INCLUDE_DIRS}
  /usr/include
)

target_link_libraries(main PRIVATE
  ${SFML_LIBRARIES}
  imgui
  OpenGL::GL
)
