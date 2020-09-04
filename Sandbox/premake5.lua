project "Sandbox"
	kind "ConsoleApp"
	language "C++"
	cppdialect "C++17"
	staticruntime "on"

	targetdir ("%{wks.location}/bin/" .. outputdir .. "/%{prj.name}")
	objdir ("%{wks.location}/bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"src/**.h",
		"src/**.cpp"
	}

	includedirs
	{
		"%{wks.location}/Honey/vendor/spdlog/include",
		"%{wks.location}/Honey/src",
		"%{wks.location}/Honey/vendor",
		"%{IncludeDir.glm}",
		"%{IncludeDir.entt}"
	}

	links
	{
		"Honey"
	}

	filter "system:windows"
		systemversion "latest"

	filter "configurations:Debug"
		defines "HN_DEBUG"
		runtime "Debug"
		symbols "on"

	filter "configurations:Release"
		defines "HN_RELEASE"
		runtime "Release"
		optimize "on"

	filter "configurations:Dist"
		defines "HN_DIST"
		runtime "Release"
		optimize "on"
