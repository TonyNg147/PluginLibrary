project(MainUI)

find_package(Qt6 REQUIRED COMPONENTS Quick Core Qml)

set(SOURCES 
    src/Controller/MainWindow.cpp
)


add_library(${PROJECT_NAME} MODULE ${SOURCES})

add_subdirectory(src/View)

target_link_libraries(${PROJECT_NAME}
    PUBLIC
        Qt6::Core
        Qt6::Qml
        Qt6::Quick
        View
)

target_compile_definitions(${PROJECT_NAME} PRIVATE LIBRARY_EXPORTS)

set_target_properties(${PROJECT_NAME} PROPERTIES
    LIBRARY_OUTPUT_NAME "UILib"
    LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/out/lib
)
