# IdentifiedModules

How to setup a custom QML module (i.e. a namespace containing reusable QML components) that can be imported anywhere by name.

## Directory structure

```
IdentifiedModules/
├── CMakeLists.txt
├── README.md
└── src
    ├── CMakeLists.txt
    ├── main.cpp
    └── qml
        ├── components
        │   ├── AnotherCustomComponent.qml
        │   ├── components.qrc
        │   ├── CustomComponent.qml
        │   └── qmldir
        ├── main.qml
        └── qml.qrc
```

## Explanations

1. QML components (`CustomComponent` and `AnotherCustomComponent`) are located in `qml/components` and listed in a [`qmldir`](https://doc.qt.io/qt-6/qtqml-modules-qmldir.html) file.
2. The module identifier at the beginning of the `qmldir` file indicates the path of the module directory relative to the path that will be imported in step 4. The path names *have* to match.
3. The QML modules and the `qmldir` file are listed in `components.qrc` (the name of this particular file doesn't matter) under a prefix corresponding to the `qml/components` directory.
3. `src/CMakeLists.txt` adds `components.qrc` to the executable.
4. In `main.cpp`, the path to the `qml` directory is added to the engine via [`addImportPath()`](https://doc.qt.io/qt-6/qqmlengine.html#addImportPath).
5. `main.qml` imports the `components` module under the alias `Components` and uses the custom QML components with `Components.CustomComponent` and `Components.AnotherCustomComponent`.

## Resources

- [Qt doc](https://doc.qt.io/qt-6/qtqml-modules-identifiedmodules.html) on identified modules.
- [Qt doc](https://doc.qt.io/qt-6/qtqml-modules-qmldir.html) on qmldir files.
- [Useful answer](https://stackoverflow.com/a/46096179/6203129) on StackOverflow.
