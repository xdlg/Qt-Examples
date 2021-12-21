add_executable(${PROJECT_NAME}
    main.cpp
    Model.cpp
    Presenter.cpp
    qml.qrc
)

target_link_libraries(${PROJECT_NAME} PRIVATE Qt6::Core Qt6::Quick)

qt_add_qml_module(${PROJECT_NAME}
  URI Presenter
  VERSION 1.0
  SOURCES Presenter.hpp Presenter.cpp
)
