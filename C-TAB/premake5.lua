project "C-TAB"
	kind "ConsoleApp"
	language "C"
	staticruntime "on"

	targetdir ("%{wks.location}/bin/" .. outputdir .. "/%{prj.name}")
	objdir ("%{wks.location}/bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"src/**.h",
		"src/**.c"
	}

	includedirs
	{
		"src"
	}

	defines
	{
		"_CRT_SECURE_NO_WARNINGS"
	}

	filter "system:windows"
		systemversion "latest"

		filter "configurations:Debug"
		defines "CTAB_DEBUG"
		runtime "Debug"
		symbols "on"

	filter "configurations:Release"
		defines "CTAB_RELEASE"
		runtime "Release"
		optimize "on"

	filter "configurations:Dist"
		defines "CTAB_DIST"
		runtime "Release"
		optimize "on"