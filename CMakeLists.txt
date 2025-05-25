# ============ CMAKE SETUP ============
cmake_minimum_required(VERSION 3.17)
set(CMAKE_CXX_STANDARD_REQUIRED on)
set(CMAKE_CXX_STANDARD 23)

# ============ PROJECT SETUP ============
project(GF2D LANGUAGES CXX VERSION 0.0.1)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/build/bin/${CMAKE_BUILD_TYPE})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/build/bin/${CMAKE_BUILD_TYPE})

# ============ EXTERN ============
add_subdirectory(extern/spdlog)
add_subdirectory(extern/SDL3)

# ============ FRAMEWORK & GAME ============
add_subdirectory(framework)
add_subdirectory(game)