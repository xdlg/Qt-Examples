find_package(Qt6 COMPONENTS Core Quick REQUIRED)

add_executable(${PROJECT_NAME}
  main.cpp
  qml/qml.qrc
  qml/components/components.qrc
)

target_link_libraries(${PROJECT_NAME} PRIVATE Qt6::Core Qt6::Quick)
