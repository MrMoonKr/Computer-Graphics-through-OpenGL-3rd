cmake_minimum_required( VERSION 3.30 )

project( Chapter00 
    VERSION 1.0
    DESCRIPTION "프로젝트 생성이 잘 되었는지 체크용 입니다다"
    LANGUAGES CXX
)

add_executable( main
    main.cpp
)
add_executable( Chapter00-01 
    ch00-01.cpp
)
add_executable( Chapter00-02 
    ch00-02.cpp
)

set_target_properties( main Chapter00-01 Chapter00-02
    PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY_DEBUG "${CMAKE_SOURCE_DIR}/bin/msvc/Debug/Chapter00"
)
