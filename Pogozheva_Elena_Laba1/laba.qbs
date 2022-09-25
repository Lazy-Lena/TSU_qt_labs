import qbs

QtApplication {
    cpp.cxxLanguageVersion: "c++17"

    consoleApplication: true
    files: [
        "estackempty.h",
        "main.cpp",
        "exception.h"
    ]

    Group {     // Properties for the produced executable
        fileTagsFilter: "application"
        qbs.install: true
        qbs.installDir: "bin"
    }
}
