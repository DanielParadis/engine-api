cmake_minimum_required(VERSION 3.16)
project(EngineAPI C CXX)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Force modern C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_C_STANDARD 23)

add_library(engine_api INTERFACE
)

target_include_directories(engine_api INTERFACE
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
)

add_library(Engine::API ALIAS engine_api)