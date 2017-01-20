project(SDL2-GUI-Test)

include_directories(${SDL2_INCLUDE_DIRS})
include_directories(${SDL2IMAGE_INCLUDE_DIRS})
include_directories(${SDL2TTF_INCLUDE_DIRS})
include_directories(${SDL2-GUI_SOURCE_DIR}/include)

set(SDL2-GUI-Test-SOURCE
    ${PROJECT_SOURCE_DIR}/src/main.cpp
)

add_executable(${PROJECT_NAME} ${SDL2-GUI-Test-SOURCE})

target_link_libraries(${PROJECT_NAME} ${SDL2_LIBRARIES})
target_link_libraries(${PROJECT_NAME} ${SDL2IMAGE_LIBRARIES})
target_link_libraries(${PROJECT_NAME} ${SDL2TTF_LIBRARIES})
target_link_libraries(${PROJECT_NAME} ${SDL2-GUI_PROJECT_NAME})
