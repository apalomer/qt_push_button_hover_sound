add_library(mainwindow mainwindow.cpp mainwindow.h mainwindow.ui qt_resources.qrc)
target_link_libraries(mainwindow Qt5::Core Qt5::Widgets Qt5::Multimedia)
add_executable(main main.cpp)
target_link_libraries(main mainwindow)
