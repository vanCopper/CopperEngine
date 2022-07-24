project "Runtime"
    kind "SharedLib"
    language "C++"
    files { "**.h", "**.cpp" }

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

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