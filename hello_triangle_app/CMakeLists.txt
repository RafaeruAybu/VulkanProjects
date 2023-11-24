cmake_minimum_required(VERSION 3.25)
project(Vulkan_pipeline)

set(CMAKE_CXX_STANDARD 23)
find_package(Vulkan REQUIRED)
include_directories(
        /opt/homebrew/Cellar/glfw/3.3.8/include
        /opt/homebrew/Cellar/glm/0.9.9.8/include
        /Users/rafaelaybulatov/VulkanSDK/1.3.250.1/macOS/include
)
link_directories(
        /opt/homebrew/Cellar/glfw/3.3.8/lib
        /opt/homebrew/Cellar/glm/0.9.9.8/lib
        /Users/rafaelaybulatov/VulkanSDK/1.3.250.1/macOS/lib
)


add_executable(Vulkan_pipeline main.cpp HelloTriangleApplication.hpp HelloTriangleApplication.cpp)
target_link_libraries(Vulkan_pipeline glfw ${GLFW_LIBRARIES} Vulkan::Vulkan)