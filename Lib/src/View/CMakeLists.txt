qt6_add_qml_module(View STATIC
    URI View
    VERSION 1.0
    RESOURCE_PREFIX "/"
    QML_FILES MainView.qml
    RESOURCES qmldir
    NO_PLUGIN
)


set_source_files_properties(MainView.qml PROPERTIES
    QT_RESOURCE_ALIAS main.qml
)
