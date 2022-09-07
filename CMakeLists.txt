cmake_minimum_required(VERSION 3.20)
project(graphics)

set(CMAKE_CXX_STANDARD 17)

file (GLOB_RECURSE Graphics_SOURCES CONFIGURE_DEPENDS "*.h")



add_executable(graphics main.c animation.c scenario.c body.c body_utils.c ${Graphics_SOURCES})

target_include_directories(graphics PRIVATE ${Graphics_INCLUDE_DIRS})


find_package(glfw3 3.3.7 REQUIRED)
find_package(glm REQUIRED)
find_package(GLEW 2.2.0 REQUIRED)
find_package(OpenGL REQUIRED)
find_package(GLUT 3.2.2 REQUIRED)

target_include_directories(graphics PUBLIC ${OPENGL_INCLUDE_DIR})

target_link_libraries(graphics "-framework Cocoa")
target_link_libraries(graphics "-framework OpenGL")
target_link_libraries(graphics "-framework IOKit")
target_link_libraries(graphics glfw ${OPENGL_gl_LIBRARY})
target_link_libraries(graphics GLEW::GLEW)
#target_link_libraries(graphics ${GLEW_LIBRARIES})
target_link_libraries(graphics ${GLM_LIBRARY})
target_link_libraries(graphics GLUT::GLUT)
