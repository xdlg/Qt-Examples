# ModelViewPresenter

Simple Model-View-Presenter architecture with a C++ model, a C++ presenter registered as instantiable type in QML, and a QML view.

## Directory structure

```
ModelViewPresenter/
├── CMakeLists.txt
├── README.md
└── src
    ├── CMakeLists.txt
    ├── main.cpp
    ├── Model.cpp
    ├── Model.hpp
    ├── Presenter.cpp
    ├── Presenter.hpp
    ├── qml.qrc
    └── View.qml
```

## Explanations

1. `Model` is a C++ class deriving from `QObject` holding one `unsigned int` value. I don't think that declaring `value` as `Q_PROPERTY` is necessary here, but it makes the code a bit more explicit.
2. `Presenter` is also a C++ class that has one instance of `Model` and associated functions. As far as I understand, the `Q_PROPERTY` here *is* necessary. The `QML_ELEMENT` macro prepares this class to be exposed to QML, as explained [here](https://doc.qt.io/qt-6/qtqml-cppintegration-definetypes.html#registering-c-types-with-the-qml-type-system).
3. In `src/CMakeLists.txt`, the directive [`qt_add_qml_module`](https://doc-snapshots.qt.io/qt6-6.2/qt-add-qml-module.html) is used to expose `Presenter` as an instantiable type to QML.
4. `View`, declared in QML, imports the `Presenter` type, instantiates one, and binds its `value` to UI components.

Additional remarks:
- There are debug statements here and there to make the call sequence apparent.
- This is just one way to implement an MVP UI in Qt. The way that the view instantiates the presenter, and that the presenter instantiates the model, wouldn't work for less trivial architectures, for example if one model had to provide data to several presenters. In that case, something like dependency injection could help, but that's beyond the scope of the example.
- Of course, this is a very simple example, so the presenter looks like it's doing nothing (just relaying function calls to the model). In a real application, the presenter would have other responsibilities, such as formatting the model data for displaying. For example, the model could provide a speed in km/h, and the presenter could relay it to the view in km/h or convert it to mph depending on the application's settings.

## Resources

- [Qt doc](https://doc.qt.io/qt-6/qtqml-cppintegration-definetypes.html#registering-c-types-with-the-qml-type-system) on registering C++ types in QML.
- [Great article](https://raymii.org/s/articles/Qt_QML_Integrate_Cpp_with_QML_and_why_ContextProperties_are_bad.html) describing various ways to expose C++ classes to QML.
- [StackOverflow answer](https://stackoverflow.com/a/65530243/6203129) on how to use `QML_ELEMENT` with CMake.
- [`qt_add_qml_module`](https://doc-snapshots.qt.io/qt6-6.2/qt-add-qml-module.html) documentation.
- [More examples](https://developernote.com/2021/09/using-qml_element-with-cmake/) on `qt_add_qml_module`.
