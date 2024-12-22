cmake_minimum_required(VERSION 3.10)
project(LetsGoBooboo)

set(CMAKE_FIND_LIBRARY_SUFFIXES ".a")
set(BUILD_SHARED_LIBS OFF)
set(CMAKE_EXE_LINKER_FLAGS "-static") # static linking

file(COPY ${CMAKE_SOURCE_DIR}/asciiArt DESTINATION ${CMAKE_BINARY_DIR})
file(COPY ${CMAKE_SOURCE_DIR}/audio DESTINATION ${CMAKE_BINARY_DIR})

set(SOURCES 
    src/main.cpp
    src/FileReader.cpp
    src/Enemy.cpp
    src/Character.cpp
    src/resources.cpp
    src/utils.cpp
    src/game.cpp
)

add_executable(LetsGoBooboo ${SOURCES})

target_link_libraries(${PROJECT_NAME} winmm)

# compiling flags
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
