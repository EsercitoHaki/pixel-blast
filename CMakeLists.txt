cmake_minimum_required(VERSION 3.10)
project(PixelBlast VERSION 1.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(libs/SDL)

find_package(glm REQUIRED)

file(GLOB_RECURSE GAME_SOURCES "src/*.cpp")

add_subdirectory(libs/SDL_image)

include_directories(
    src
)

add_executable(${PROJECT_NAME} ${GAME_SOURCES})

target_link_libraries(${PROJECT_NAME} 
    SDL3::SDL3
    SDL3_image::SDL3_image
    glm::glm
)

file(COPY "${CMAKE_CURRENT_SOURCE_DIR}/assets/" DESTINATION "${CMAKE_CURRENT_BINARY_DIR}/assets")


install(TARGETS ${PROJECT_NAME} DESTINATION bin)
install(DIRECTORY ${PROJECT_SOURCE_DIR}/assets/ DESTINATION assets)