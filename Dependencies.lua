-- Honey Dependencies

VULKAN_SDK = os.getenv("VULKAN_SDK")

IncludeDir = {}
IncludeDir["stb_image"] = "%{wks.location}/Honey/vendor/stb_image"
IncludeDir["yaml_cpp"] = "%{wks.location}/Honey/vendor/yaml-cpp/include"
IncludeDir["Box2D"] = "%{wks.location}/Honey/vendor/Box2D/include"
IncludeDir["GLFW"] = "%{wks.location}/Honey/vendor/GLFW/include"
IncludeDir["Glad"] = "%{wks.location}/Honey/vendor/Glad/include"
IncludeDir["ImGui"] = "%{wks.location}/Honey/vendor/ImGui"
IncludeDir["ImGuizmo"] = "%{wks.location}/Honey/vendor/ImGuizmo"
IncludeDir["glm"] = "%{wks.location}/Honey/vendor/glm"
IncludeDir["entt"] = "%{wks.location}/Honey/vendor/entt/include"
IncludeDir["shaderc"] = "%{wks.location}/Honey/vendor/shaderc/include"
IncludeDir["SPIRV_Cross"] = "%{wks.location}/Honey/vendor/SPIRV-Cross"
IncludeDir["VulkanSDK"] = "%{VULKAN_SDK}/Include"

LibraryDir = {}

LibraryDir["VulkanSDK"] = "%{VULKAN_SDK}/Lib"

Library = {}
Library["Vulkan"] = "%{LibraryDir.VulkanSDK}/vulkan-1.lib"
Library["VulkanUtils"] = "%{LibraryDir.VulkanSDK}/VkLayer_utils.lib"

Library["ShaderC_Debug"] = "%{LibraryDir.VulkanSDK}/shaderc_sharedd.lib"
Library["SPIRV_Cross_Debug"] = "%{LibraryDir.VulkanSDK}/spirv-cross-cored.lib"
Library["SPIRV_Cross_GLSL_Debug"] = "%{LibraryDir.VulkanSDK}/spirv-cross-glsld.lib"
Library["SPIRV_Tools_Debug"] = "%{LibraryDir.VulkanSDK}/SPIRV-Toolsd.lib"

Library["ShaderC_Release"] = "%{LibraryDir.VulkanSDK}/shaderc_shared.lib"
Library["SPIRV_Cross_Release"] = "%{LibraryDir.VulkanSDK}/spirv-cross-core.lib"
Library["SPIRV_Cross_GLSL_Release"] = "%{LibraryDir.VulkanSDK}/spirv-cross-glsl.lib"
