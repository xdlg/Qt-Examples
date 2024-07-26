add_executable(${PROJECT_NAME}
    main.cpp
    model.cpp
    presenter.cpp
    qml.qrc
)

target_link_libraries(${PROJECT_NAME} PRIVATE Qt6::Core Qt6::Quick)

qt_policy(SET QTP0001 NEW)

qt_add_qml_module(${PROJECT_NAME}
  URI Presenter
  VERSION 1.0
  SOURCES presenter.hpp presenter.cpp
)
