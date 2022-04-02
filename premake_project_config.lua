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

project "CopperEngine"
    location "CopperEngine"
    kind "SharedLib"
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
        "%{prj.name}/src",
        "%{prj.name}/vendor/spdlog/include"
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
