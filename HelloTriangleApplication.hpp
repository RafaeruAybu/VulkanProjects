//
// Created by Rafael Aybulatov on 23.10.2023.
//

#ifndef VULKAN_PIPELINE_HELLOTRIANGLEAPPLICATION_HPP
#define VULKAN_PIPELINE_HELLOTRIANGLEAPPLICATION_HPP

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>
#include <iostream>
#include <stdexcept>
#include <cstdlib>
#include <vector>
#include <cstring>
#include <optional>

struct QueueFamilyIndices
{
    std::optional<uint32_t> graphicsFamily;
    bool isComplete()
    {
        return graphicsFamily.has_value();
    }
};

class HelloTriangleApplication
{
public:
    void run();

private:
    const int m_width = 800;
    const int m_height = 600;
    GLFWwindow *m_window = nullptr;
    VkInstance m_instance;
    VkDebugUtilsMessengerEXT m_debugMessenger;
    VkPhysicalDevice m_physicalDevice = VK_NULL_HANDLE;
    VkDevice m_device;
    VkPhysicalDeviceFeatures m_deviceFeatures{};
    VkQueue m_graphicsQueue;

    const std::vector<const char*> m_validationLayers = {
            "VK_LAYER_KHRONOS_validation"
    };

#ifdef NDEBUG
    const bool m_enableValidationLayers = false;
#else
    const bool m_enableValidationLayers = true;
#endif

private:
    void initWindow();
    void initVulkan();
    void createLogicalDevice();
    void pickPhysicalDevise();
    bool isDeviceSuitable(VkPhysicalDevice device);
    QueueFamilyIndices findQueueFamilies(VkPhysicalDevice device);
    void populateDebugMessengerCreateInfo(VkDebugUtilsMessengerCreateInfoEXT& createInfo);
    void setupDebugMessenger();
    void DestroyDebugUtilsMessengerEXT(VkInstance instance,
                                       VkDebugUtilsMessengerEXT debugMessenger,
                                       const VkAllocationCallbacks* pAllocator);
    void mainLoop();
    void cleanup();
    void createInstance();
    bool checkValidationLayerSupport();
    [[nodiscard]] std::vector<const char*> getRequiredExtension() const;
    static VKAPI_ATTR VkBool32 VKAPI_CALL debugCallback(
            VkDebugUtilsMessageSeverityFlagBitsEXT messageSeverity,
            VkDebugUtilsMessageTypeFlagsEXT messageType,
            const VkDebugUtilsMessengerCallbackDataEXT* pCallbackData,
            void* pUserData);
};


#endif //VULKAN_PIPELINE_HELLOTRIANGLEAPPLICATION_HPP
