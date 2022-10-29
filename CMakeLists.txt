cmake_minimum_required(VERSION 3.23)
project(t_rex)

set(CMAKE_CXX_STANDARD 20)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin)

if (NOT WIN32)
    find_package(Curses REQUIRED)

    if (NOT CURSES_FOUND)
        message(FATAL_ERROR "Curses not found")
    else ()
        message(STATUS "Curses found")
        include_directories(${CURSES_INCLUDE_DIR})
    endif ()
endif ()

include_directories(include)

if (WIN32)
    include_directories(C:\\C++\\work_2022_1\\PDCurses)
endif ()

############################################################
#Generate the static library from the library sources
############################################################

add_library(t_rex_lib STATIC
            src/Game.cpp
            src/Menu.cpp
            src/Palette.cpp
            src/Screen.cpp
            src/Board.cpp
            src/Drawable.cpp
            src/Bonus.cpp
            src/Drawable_Str.cpp
            src/Drawable_Rect.cpp
            src/Trx.cpp
            src/T_Rex.cpp
            src/T_Rex_Step.cpp
            src/Cactus_1.cpp
            src/Movable_Rect.cpp
            src/Play_Again.cpp

            )

target_include_directories(t_rex_lib
                           PUBLIC
                           ${PROJECT_SOURCE_DIR}/include
                           )

if (WIN32)
    target_link_libraries(t_rex_lib PUBLIC C:\\C++\\work_2022_1\\PDCurses\\pdcurses.lib)
else ()
    target_link_libraries(t_rex_lib PUBLIC ${CURSES_LIBRARIES})
endif ()

############################################################
# Create an executable
############################################################

add_executable(t_rex App/main.cpp)

target_link_libraries(t_rex
                      PRIVATE
                      t_rex_lib
                      )



