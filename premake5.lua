include "./vendor/premake/premake_customization/solution_items.lua"
include "Dependencies.lua"

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

group "Dependencies"
	include "vendor/premake"
	include "Honey/vendor/Box2D"
	include "Honey/vendor/GLFW"
	include "Honey/vendor/Glad"
	include "Honey/vendor/msdf-atlas-gen"
	include "Honey/vendor/imgui"
	include "Honey/vendor/yaml-cpp"
group ""

group "Core"
	include "Honey"
	include "Honey-ScriptCore"
group ""

group "Tools"
	include "Honeynut"
group ""

group "Misc"
	include "Sandbox"
group ""
