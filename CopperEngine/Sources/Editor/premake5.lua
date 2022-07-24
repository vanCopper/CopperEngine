project "Editor"
    language "C++"
    files { "**.h", "**.cpp" }

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

    filter "configurations:Debug"
        defines "COPPER_DEBUG"
        runtime "Debug"
        symbols "On"
        kind "ConsoleApp"

    filter "configurations:Release"
        defines "COPPER_RELEASE"
        runtime "Release"
        optimize "On"
        kind "ConsoleApp"

    filter "configurations:Dist"
        defines "COPPER_DIST"
        runtime "Release"
        optimize "On"
        kind "WindowedApp"
