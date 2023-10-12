cmake_minimum_required(VERSION 3.25)
project(touching_grass)

set(CMAKE_CXX_STANDARD 17)

add_executable(touching_grass src/main.cpp src/Input.cpp src/Application.cpp src/Mesh.cpp src/Model.cpp src/Shader.cpp src/Entity.cpp src/Entity.hpp src/Component.hpp src/Event.cpp src/Event.hpp src/Scene.cpp src/Scene.hpp src/Id.cpp src/Id.hpp src/Transform.hpp src/CameraData.hpp src/System.hpp src/CollisionBox.hpp)

add_custom_target(copy_runtime_resources ALL COMMAND ${CMAKE_COMMAND} -E copy_directory ${CMAKE_SOURCE_DIR}/runtime_resources ${CMAKE_BINARY_DIR})
add_dependencies(touching_grass copy_runtime_resources)

include_directories(vendor/assimp/include vendor/glfw-3.3.8/include vendor/glad/include vendor/glm vendor/stb_image vendor/imgui)

add_library(glad STATIC vendor/glad/src/glad.c)
add_library(stb_image STATIC vendor/stb_image/stb_image.c)
add_library(imgui STATIC vendor/imgui/imgui.cpp vendor/imgui/imgui_demo.cpp vendor/imgui/imgui_draw.cpp vendor/imgui/imgui_tables.cpp vendor/imgui/imgui_widgets.cpp vendor/imgui/imgui_impl_opengl3.cpp vendor/imgui/imgui_impl_glfw.cpp)

add_subdirectory(vendor/assimp)
add_subdirectory(vendor/glfw-3.3.8)

target_link_libraries(touching_grass glad)
target_link_libraries(touching_grass stb_image)
target_link_libraries(touching_grass assimp)
target_link_libraries(touching_grass glfw)
target_link_libraries(touching_grass imgui)
