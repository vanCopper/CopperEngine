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
IncludeDir["glad"] = "CopperEngine/vendor/glad/include"
IncludeDir["ImGui"] = "CopperEngine/vendor/imgui"

group "Dependencies"
    include "CopperEngine/vendor/glfw"
    include "CopperEngine/vendor/glad"
    include "CopperEngine/vendor/imgui"


group ""

project "CopperEngine"
    location "CopperEngine"
    kind "SharedLib"
    language "C++"
    staticruntime "off" -- MultiThreadedDLL(Visual Studio)

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

    pchheader "CopperPCH.h"
    pchsource "CopperEngine/src/CopperPCH.cpp"

    files
    {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp"
    }

    includedirs
    {
        "%{prj.name}/src",
        "%{prj.name}/vendor/spdlog/include",
        "%{IncludeDir.glfw}",
        "%{IncludeDir.glad}",
        "%{IncludeDir.ImGui}"
    }

    links
    {
        "glfw",
        "glad",
        "ImGui",
        "opengl32.lib"
    }

    filter "system:windows"
        cppdialect "C++17"
        systemversion "latest"

        defines
        {
            "COPPER_PLATFORM_WINDOWS",
            "COPPER_BUILD_DLL",
            "GLFW_INCLUDE_NONE"
        }

        postbuildcommands
        {
            ("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
        }

    filter "configurations:Debug"
        defines "COPPER_DEBUG"
        runtime "Debug"
        symbols "On"

    filter "configurations:Release"
        defines "COPPER_RELEASE"
        runtime "Release"
        optimize "On"

    filter "configurations:Dist"
        defines "COPPER_DIST"
        runtime "Release"
        optimize "On"

project "Sandbox"
    location "Sandbox"
    kind "ConsoleApp"
    language "C++"
    staticruntime "off" -- MultiThreadedDLL(Visual Studio)

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
        systemversion "latest"

        defines
        {
            "COPPER_PLATFORM_WINDOWS"
        }

    filter "configurations:Debug"
        defines "COPPER_DEBUG"
        symbols "On"
        runtime "Debug"

    filter "configurations:Release"
        defines "COPPER_RELEASE"
        runtime "Release"
        optimize "On"

    filter "configurations:Dist"
        defines "COPPER_DIST"
        runtime "Release"
        optimize "On"
