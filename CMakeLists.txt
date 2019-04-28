CMAKE_MINIMUM_REQUIRED (VERSION 2.8)
PROJECT (jscore)

SET (jscore_VERSION_MAJOR 1)
SET (jscore_VERSION_MINOR 0)

FIND_PACKAGE(PkgConfig REQUIRED)
PKG_CHECK_MODULES(JAVASCRIPTCORE_LIBRARY REQUIRED javascriptcoregtk-4.0)

INCLUDE_DIRECTORIES(
  "/usr/include/webkitgtk-4.0"
)

add_executable (jscore main.cpp)
target_link_libraries(jscore
  javascriptcoregtk-4.0
)

install (TARGETS jscore DESTINATION bin)
