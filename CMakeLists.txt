cmake_minimum_required( VERSION 3.30 )

set( VCPKG_TARGET_TRIPLET "x64-windows" CACHE STRING "" )
set( CMAKE_TOOLCHAIN_FILE "C:/vcpkg/scripts/buildsystems/vcpkg.cmake" CACHE STRING "" )
# set( VCPKG_TARGET_TRIPLET "x64-mingw-dynamic" CACHE STRING "" )
# set( CMAKE_TOOLCHAIN_FILE "C:/vcpkg/scripts/buildsystems/vcpkg.cmake" CACHE STRING "" )

project( ComputerGraphicsThroughOpenGL3rd 
    VERSION 1.0
    DESCRIPTION "Computer Graphics Through OpenGL 3rd Edition"
    LANGUAGES CXX
)

set( CMAKE_CXX_STANDARD 17 )

find_package( fmt CONFIG REQUIRED )
find_package( httplib CONFIG REQUIRED )
find_package( CURL REQUIRED )
find_package( nlohmann_json CONFIG REQUIRED )
find_package( glfw3 CONFIG REQUIRED )
find_package( imgui CONFIG REQUIRED )
find_package( Stb REQUIRED )


add_subdirectory( "src" )

