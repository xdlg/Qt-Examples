add_executable(${PROJECT_NAME}
    main.cpp
    qml.qrc
)

target_link_libraries(${PROJECT_NAME} PRIVATE Qt6::Core Qt6::Quick)
