include "./vendor/premake/premake_customization/solution_items.lua"

workspace "Honey"
	architecture "x86_64"
	startproject "Honeynut"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

	solution_items
	{
		".editorconfig"
	}

	flags
	{
		"MultiProcessorCompile"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

-- Include directories relative to root folder (solution directory)
IncludeDir = {}
IncludeDir["GLFW"] = "%{wks.location}/Honey/vendor/GLFW/include"
IncludeDir["Glad"] = "%{wks.location}/Honey/vendor/Glad/include"
IncludeDir["ImGui"] = "%{wks.location}/Honey/vendor/imgui"
IncludeDir["glm"] = "%{wks.location}/Honey/vendor/glm"
IncludeDir["stb_image"] = "%{wks.location}/Honey/vendor/stb_image"
IncludeDir["entt"] = "%{wks.location}/Honey/vendor/entt/include"
IncludeDir["yaml_cpp"] = "%{wks.location}/Honey/vendor/yaml-cpp/include"

group "Dependencies"
	include "vendor/premake"
	include "Honey/vendor/GLFW"
	include "Honey/vendor/Glad"
	include "Honey/vendor/imgui"
	include "Honey/vendor/yaml-cpp"
group ""

include "Honey"
include "Sandbox"
include "Honeynut"
