cmake_minimum_required(VERSION 3.15)
project(main VERSION 0.1.0)

# include(CTest)
# enable_testing()

# find_package(imgui QUIET)
# if (NOT imgui_FOUND)
#     include(FetchContent)
#     FetchContent_Declare(
#         imgui
#         URL https://github.com/ocornut/imgui/archive/refs/heads/docking.zip 
#     )
#     FetchContent_MakeAvailable(imgui)
# endif()

# glfw
find_package(glfw QUIET)
if (NOT glfw_FOUND)
    include(FetchContent)
    FetchContent_Declare(
        glfw
        URL https://github.com/glfw/glfw/releases/download/3.3.7/glfw-3.3.7.zip
    )
    FetchContent_MakeAvailable(glfw)
endif()

# glad
# find_package(glad QUIET)
# if (NOT glad_FOUND)
#     include(FetchContent)
#     FetchContent_Declare(
#         glad
#         URL https://glad.dav1d.de/generated/tmp4rucabykglad/glad.zip
#         # SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/ext/glad
#     )
#     FetchContent_MakeAvailable(glad)
#     file(
#         COPY
#         ${CMAKE_CURRENT_SOURCE_DIR}/build/_deps/glad-src/include/
#         DESTINATION ${CMAKE_CURRENT_SOURCE_DIR}/include/
#     )
#     file(
#         COPY
#         ${CMAKE_CURRENT_SOURCE_DIR}/build/_deps/glad-src/src/glad.c
#         DESTINATION ${CMAKE_CURRENT_SOURCE_DIR}/src/
#     )
# endif()

#cpp-httplib
find_package(cpp-httplib QUIET)
if (NOT cpp-httplib_FOUND)
    include(FetchContent)
    FetchContent_Declare(
        cpp-httplib
        URL https://github.com/yhirose/cpp-httplib/archive/refs/tags/v0.12.2.zip
    )
    FetchContent_MakeAvailable(cpp-httplib)
    # file(
    #     COPY
    #     ${CMAKE_CURRENT_SOURCE_DIR}/build/_deps/cpp-httplib-src/httplib.h
    #     DESTINATION ${CMAKE_CURRENT_SOURCE_DIR}/include/
    # )
endif()

# config source files
file(
    GLOB SOURCES 
    # "${CMAKE_SOURCE_DIR}/src/main.cpp" 
    "${CMAKE_SOURCE_DIR}/src/*"
    "${CMAKE_SOURCE_DIR}/src/**/*"
)

include_directories(${PROJECT_NAME} "${PROJECT_SOURCE_DIR}/include" "${PROJECT_SOURCE_DIR}/include/imgui")

add_executable(${PROJECT_NAME} ${SOURCES})
set_target_properties(${PROJECT_NAME} PROPERTIES CXX_STANDARD 11)
target_link_libraries(${PROJECT_NAME} PUBLIC glfw httplib::httplib)

# set(CPACK_PROJECT_NAME ${PROJECT_NAME})
# set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
# include(CPack)

