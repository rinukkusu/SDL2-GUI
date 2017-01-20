project(SDL2-GUI)

include_directories(${SDL2_INCLUDE_DIRS})
include_directories(${SDL2IMAGE_INCLUDE_DIRS})
include_directories(${SDL2TTF_INCLUDE_DIRS})

set(SDL2-GUI_PROJECT_NAME ${PROJECT_NAME} PARENT_SCOPE)

set(SDL2-GUI-SOURCE
    ${PROJECT_SOURCE_DIR}/src/Rectangle.cpp
    ${PROJECT_SOURCE_DIR}/src/Point.cpp
    ${PROJECT_SOURCE_DIR}/src/Exception.cpp
    ${PROJECT_SOURCE_DIR}/src/components/Spinner.cpp
    ${PROJECT_SOURCE_DIR}/src/components/TextBasedComponent.cpp
    ${PROJECT_SOURCE_DIR}/src/components/Component.cpp
    ${PROJECT_SOURCE_DIR}/src/components/TextLabel.cpp
    ${PROJECT_SOURCE_DIR}/src/components/Container.cpp
    ${PROJECT_SOURCE_DIR}/src/components/NumberSpinner.cpp
    ${PROJECT_SOURCE_DIR}/src/components/TextInput.cpp
    ${PROJECT_SOURCE_DIR}/src/components/ClickableComponent.cpp
    ${PROJECT_SOURCE_DIR}/src/components/Button.cpp
    ${PROJECT_SOURCE_DIR}/src/components/TickBox.cpp
    ${PROJECT_SOURCE_DIR}/src/components/ImageLabel.cpp
    ${PROJECT_SOURCE_DIR}/src/components/ScrollPane.cpp
    ${PROJECT_SOURCE_DIR}/src/View.cpp
    ${PROJECT_SOURCE_DIR}/src/GraphicUserInterfaceView.cpp
    ${PROJECT_SOURCE_DIR}/src/Colours.cpp
)

set(SDL2-GUI-INCLUDES
    ${PROJECT_SOURCE_DIR}/include/Colours.hpp
    ${PROJECT_SOURCE_DIR}/include/Rectangle.hpp
    ${PROJECT_SOURCE_DIR}/include/Exception.hpp
    ${PROJECT_SOURCE_DIR}/include/components/ScrollPane.hpp
    ${PROJECT_SOURCE_DIR}/include/components/TextBasedComponent.hpp
    ${PROJECT_SOURCE_DIR}/include/components/TickBox.hpp
    ${PROJECT_SOURCE_DIR}/include/components/NumberSpinner.hpp
    ${PROJECT_SOURCE_DIR}/include/components/SDLEventHandler.hpp
    ${PROJECT_SOURCE_DIR}/include/components/TextLabel.hpp
    ${PROJECT_SOURCE_DIR}/include/components/Button.hpp
    ${PROJECT_SOURCE_DIR}/include/components/Container.hpp
    ${PROJECT_SOURCE_DIR}/include/components/Spinner.hpp
    ${PROJECT_SOURCE_DIR}/include/components/ImageLabel.hpp
    ${PROJECT_SOURCE_DIR}/include/components/Component.hpp
    ${PROJECT_SOURCE_DIR}/include/components/ClickableComponent.hpp
    ${PROJECT_SOURCE_DIR}/include/components/TextInput.hpp
    ${PROJECT_SOURCE_DIR}/include/View.hpp
    ${PROJECT_SOURCE_DIR}/include/IComponent.hpp
    ${PROJECT_SOURCE_DIR}/include/Point.hpp
    ${PROJECT_SOURCE_DIR}/include/GraphicUserInterfaceView.hpp
)

add_library(${PROJECT_NAME} SHARED ${SDL2-GUI-SOURCE} ${SDL2-GUI-INCLUDES})

target_link_libraries(${PROJECT_NAME} ${SDL2_LIBRARIES})
target_link_libraries(${PROJECT_NAME} ${SDL2IMAGE_LIBRARIES})
target_link_libraries(${PROJECT_NAME} ${SDL2TTF_LIBRARIES})

