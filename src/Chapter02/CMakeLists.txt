cmake_minimum_required( VERSION 3.30 )

project( Chapter02 
    VERSION 1.0
    DESCRIPTION "Chapter 02"
    LANGUAGES CXX
)


add_executable( ch02-square ch02-square.cpp )
target_link_libraries( ch02-square PRIVATE GLEW::GLEW )
target_link_libraries( ch02-square PRIVATE GLUT::GLUT )
target_link_libraries( ch02-square PRIVATE $<IF:$<TARGET_EXISTS:FreeGLUT::freeglut>,FreeGLUT::freeglut,FreeGLUT::freeglut_static>)

add_executable( ch02-square-glfw ch02-square-glfw.cpp )
target_link_libraries( ch02-square-glfw PRIVATE GLEW::GLEW )
# target_link_libraries( ch02-square-glfw PRIVATE GLUT::GLUT )
# target_link_libraries( ch02-square-glfw PRIVATE $<IF:$<TARGET_EXISTS:FreeGLUT::freeglut>,FreeGLUT::freeglut,FreeGLUT::freeglut_static>)
target_link_libraries( ch02-square-glfw PRIVATE glfw )

add_executable( ch02-circle ch02-circle.cpp )
target_link_libraries( ch02-circle PRIVATE GLEW::GLEW )
target_link_libraries( ch02-circle PRIVATE GLUT::GLUT )
target_link_libraries( ch02-circle PRIVATE $<IF:$<TARGET_EXISTS:FreeGLUT::freeglut>,FreeGLUT::freeglut,FreeGLUT::freeglut_static>)




set_target_properties( ch02-square ch02-square-glfw 
    ch02-circle
    PROPERTIES RUNTIME_OUTPUT_DIRECTORY_DEBUG "${CMAKE_SOURCE_DIR}/bin/msvc/Debug/Chapter02"
)

