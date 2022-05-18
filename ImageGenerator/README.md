# ImageGenerator

C++ object generating a dynamic image and making it available to QML via a `QQuickImageProvider`.

## Directory structure

```
ImageGenerator
├── CMakeLists.txt
├── README.md
└── src
    ├── CMakeLists.txt
    ├── image_generator.cpp
    ├── image_generator.hpp
    ├── main.cpp
    ├── main.qml
    └── qml.qrc
```

## Explanations

1. `ImageGenerator` derives from `QQuickImageProvider` and internally changes some property of the generated image (here, the color) at regular intervals. Once this is done, it emits a signal.
2. `ImageGenerator` is made available to QML both as a general `QObject` via context property, and as an image provider.
3. In QML, an `Image` displays the provided image, refreshing it whenever the signal is received.

## Resources

- [Qt forum thread](https://forum.qt.io/topic/38978/solved-send-qimage-from-c-to-qml-via-qquickimageprovider-or-using-a-signal) about using a signal emitted from C++ to refresh an image provided via `QQuickImageProvider`.
