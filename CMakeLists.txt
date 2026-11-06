cmake_minimum_required(VERSION 3.25)
project(cubesatsim LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# ---- Third-party libraries, downloaded once at configure time and pinned ----
include(FetchContent)

# Eigen is header-only. SOURCE_SUBDIR points at a folder that doesn't exist so
# CMake unpacks it without running Eigen's own (large) build scripts.
FetchContent_Declare(eigen
  URL https://gitlab.com/libeigen/eigen/-/archive/3.4.0/eigen-3.4.0.tar.gz
  URL_HASH SHA256=8586084f71f9bde545ee7fa6d00288b264a2b7ac3607b974e54d13e7162c1c72
  SOURCE_SUBDIR do-not-build
)
FetchContent_Declare(googletest
  URL https://github.com/google/googletest/releases/download/v1.17.0/googletest-1.17.0.tar.gz
  URL_HASH SHA256=65fab701d9829d38cb77c14acdc431d2108bfdbf8979e40eb8ae567edf10b27c
  EXCLUDE_FROM_ALL
  SYSTEM
)
set(BUILD_GMOCK OFF CACHE BOOL "" FORCE)
set(INSTALL_GTEST OFF CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(eigen googletest)

# ---- Shared compile settings ----
add_library(project_options INTERFACE)
target_compile_options(project_options INTERFACE -Wall -Wextra -Wpedantic)
# Link the compiler runtime statically so programs run from any terminal.
if(MINGW)
  target_link_options(project_options INTERFACE -static)
endif()

# ---- sim: every sim/*.cpp is picked up automatically ----
file(GLOB SIM_SOURCES CONFIGURE_DEPENDS sim/*.cpp)
add_library(sim INTERFACE)
target_sources(sim INTERFACE ${SIM_SOURCES})
target_include_directories(sim INTERFACE ${PROJECT_SOURCE_DIR})
target_include_directories(sim SYSTEM INTERFACE ${eigen_SOURCE_DIR})
target_link_libraries(sim INTERFACE project_options)

# ---- apps: each apps/*.cpp becomes its own program (build/apps/<name>) ----
file(GLOB APP_SOURCES CONFIGURE_DEPENDS apps/*.cpp)
foreach(app_source ${APP_SOURCES})
  get_filename_component(app_name ${app_source} NAME_WE)
  add_executable(${app_name} ${app_source})
  target_link_libraries(${app_name} PRIVATE sim)
  set_target_properties(${app_name} PROPERTIES RUNTIME_OUTPUT_DIRECTORY apps)
endforeach()

# ---- tests: every tests/*.cpp goes into one test program ----
enable_testing()
include(GoogleTest)
file(GLOB TEST_SOURCES CONFIGURE_DEPENDS tests/*.cpp)
add_executable(unit_tests ${TEST_SOURCES})
target_link_libraries(unit_tests PRIVATE sim GTest::gtest_main)
gtest_discover_tests(unit_tests)
