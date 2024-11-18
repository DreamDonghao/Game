#if(CMAKE_BUILD_TYPE STREQUAL "Debug")
#    set(SFML_DIR "C:/Programs/vcpkg-master/installed/x64-windows/debug/share/sfml")
#elseif(CMAKE_BUILD_TYPE STREQUAL "Release")
#    set(SFML_DIR "C:/Programs/vcpkg-master/installed/x64-windows/release/share/sfml")
#endif()


set(CMAKE_TOOLCHAIN_FILE "C:/Programs/vcpkg-master/scripts/buildsystems/vcpkg.cmake" CACHE STRING "")
find_package(OpenGL REQUIRED)
find_package(SFML REQUIRED graphics window system)


include_directories( "include" "include/core" "include/customizable" "include/core/pages")

add_executable (SFMLUI "src/core/Window.cpp" "src/main.cpp" "src/customizable/mainpage.cpp" )

target_link_libraries(SFMLUI sfml-graphics sfml-window sfml-system)

#target_link_libraries(SFMLUI PRIVATE OpenGL::GL)

set(CMAKE_CXX_STANDARD 23)
