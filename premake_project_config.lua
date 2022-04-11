workspace "CopperEngine"
    architecture "x64"
    startproject "Sandbox"

    configurations
    {
        "Debug",
        "Release",
        "Dist"
    }

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

IncludeDir = {}
IncludeDir["glfw"] = "CopperEngine/vendor/glfw/include"

-- Include glfw premake config
include "CopperEngine/vendor/glfw"

project "CopperEngine"
    location "CopperEngine"
    kind "SharedLib"
    language "C++"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

    pchheader "CopperPCH.h"
    pchsource "Copper/src/CopperPCH.cpp"

    files
    {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp"
    }

    includedirs
    {
        "%{prj.name}/src",
        "%{prj.name}/vendor/spdlog/include",
        "%{IncludeDir.glfw}"
    }

    links
    {
        "glfw",
        "opengl32.lib"
    }

    filter "system:windows"
        cppdialect "C++17"
        staticruntime "On"
        systemversion "latest"

        defines
        {
            "COPPER_PLATFORM_WINDOWS",
            "COPPER_BUILD_DLL"
        }

        postbuildcommands
        {
            ("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
        }

    filter "configurations:Debug"
        defines "COPPER_DEBUG"
        symbols "On"

    filter "configurations:Release"
        defines "COPPER_RELEASE"
        optimize "On"

    filter "configurations:Dist"
        defines "COPPER_DIST"
        optimize "On"

project "Sandbox"
    location "Sandbox"
    kind "ConsoleApp"
    language "C++"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

    files
    {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp"
    }

    includedirs
    {
        "CopperEngine/vendor/spdlog/include",
        "CopperEngine/src"
    }

    links
    {
        "CopperEngine"
    }

    filter "system:windows"
        cppdialect "C++17"
        staticruntime "On"
        systemversion "latest"

        defines
        {
            "COPPER_PLATFORM_WINDOWS"
        }

    filter "configurations:Debug"
        defines "COPPER_DEBUG"
        symbols "On"

    filter "configurations:Release"
        defines "COPPER_RELEASE"
        optimize "On"

    filter "configurations:Dist"
        defines "COPPER_DIST"
        optimize "On"
