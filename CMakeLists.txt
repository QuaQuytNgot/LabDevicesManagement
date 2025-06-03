cmake_minimum_required(VERSION 3.14)

include(cmake/prelude.cmake)

project(
    LabDevicesManagement
    VERSION 0.1.0
    DESCRIPTION "Short description"
    HOMEPAGE_URL "https://example.com/"
    LANGUAGES CXX
)

include(cmake/project-is-top-level.cmake)
include(cmake/variables.cmake)

# ---- Declare library ----

file(GLOB_RECURSE LIB_SOURCES "source/*.cpp")

add_library(
    LabDevicesManagement_lib OBJECT
    ${LIB_SOURCES}
)

target_include_directories(
    LabDevicesManagement_lib ${warning_guard}
    PUBLIC
    "\$<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>"
    PRIVATE
    "\$<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/source>"
)

target_compile_features(LabDevicesManagement_lib PUBLIC cxx_std_17)

# ---- Declare executable ----

add_executable(LabDevicesManagement_exe app/main.cpp)
add_executable(LabDevicesManagement::exe ALIAS LabDevicesManagement_exe)

set_property(TARGET LabDevicesManagement_exe PROPERTY OUTPUT_NAME LabDevicesManagement)

target_compile_features(LabDevicesManagement_exe PRIVATE cxx_std_17)

target_link_libraries(LabDevicesManagement_exe PRIVATE LabDevicesManagement_lib)

# ---- Install rules ----

if(NOT CMAKE_SKIP_INSTALL_RULES)
  include(cmake/install-rules.cmake)
endif()

# ---- Developer mode ----

if(NOT LabDevicesManagement_DEVELOPER_MODE)
  return()
elseif(NOT PROJECT_IS_TOP_LEVEL)
  message(
      AUTHOR_WARNING
      "Developer mode is intended for developers of LabDevicesManagement"
  )
endif()

include(cmake/dev-mode.cmake)