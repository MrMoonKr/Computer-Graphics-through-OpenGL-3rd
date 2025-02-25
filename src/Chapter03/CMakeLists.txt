cmake_minimum_required( VERSION 3.30 )

project( Chapter03 
    VERSION 1.0
    DESCRIPTION "Chapter 03"
    LANGUAGES CXX
)


add_executable( ch03-fonts ch03-fonts.cpp )
target_link_libraries( ch03-fonts PRIVATE GLEW::GLEW )
target_link_libraries( ch03-fonts PRIVATE GLUT::GLUT )
target_link_libraries( ch03-fonts PRIVATE $<IF:$<TARGET_EXISTS:FreeGLUT::freeglut>,FreeGLUT::freeglut,FreeGLUT::freeglut_static>)

find_package( FTGL CONFIG REQUIRED )

add_executable( ch03-ftgl ch03-ftgl.cpp )
target_link_libraries( ch03-ftgl PRIVATE GLEW::GLEW )
target_link_libraries( ch03-ftgl PRIVATE GLUT::GLUT )
target_link_libraries( ch03-ftgl PRIVATE $<IF:$<TARGET_EXISTS:FreeGLUT::freeglut>,FreeGLUT::freeglut,FreeGLUT::freeglut_static>)
target_link_libraries( ch03-ftgl PRIVATE ftgl )


# add_executable( ch02-square-glfw ch02-square-glfw.cpp )
# target_link_libraries( ch02-square-glfw PRIVATE GLEW::GLEW )
# # target_link_libraries( ch02-square-glfw PRIVATE GLUT::GLUT )
# # target_link_libraries( ch02-square-glfw PRIVATE $<IF:$<TARGET_EXISTS:FreeGLUT::freeglut>,FreeGLUT::freeglut,FreeGLUT::freeglut_static>)
# target_link_libraries( ch02-square-glfw PRIVATE glfw )

# add_executable( ch02-circle ch02-circle.cpp )
# target_link_libraries( ch02-circle PRIVATE GLEW::GLEW )
# target_link_libraries( ch02-circle PRIVATE GLUT::GLUT )
# target_link_libraries( ch02-circle PRIVATE $<IF:$<TARGET_EXISTS:FreeGLUT::freeglut>,FreeGLUT::freeglut,FreeGLUT::freeglut_static>)




set_target_properties( ch03-fonts ch03-ftgl
    PROPERTIES RUNTIME_OUTPUT_DIRECTORY_DEBUG "${CMAKE_SOURCE_DIR}/bin/msvc/Debug/Chapter03"
)

# Copy the data folder to the output directory
file( COPY ${CMAKE_SOURCE_DIR}/data DESTINATION ${CMAKE_SOURCE_DIR}/bin/msvc/Debug/Chapter03 )

