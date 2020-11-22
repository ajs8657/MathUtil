workspace "MathUtil"
	architecture "x86"

	configurations {
		"Debug",
		"Release"
	}

OutDir = "%{cfg.buildcfg}/%{cfg.system}-%{cfg.architecture}"

project "MathUtil"
    staticruntime "On"
	kind "StaticLib"
	language "C++"
    cppdialect "C++17"

	targetdir ("bin/" .. OutDir .. "/%{prj.name}")
	objdir ("bin-obj/" .. OutDir .. "/%{prj.name}")

	files {
        "src/**.h",
        "src/**.cpp"
    }
    
	includedirs {
		"src"
	}

	filter "configurations:Debug"
		symbols "On"

	filter "configurations:Release"
		optimize "On"
