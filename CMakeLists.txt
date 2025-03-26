# 指定最低的 CMake 版本要求，这里要求版本 3.8 或更高
cmake_minimum_required (VERSION 3.8)

# 如果支持，启用 MSVC 编译器的热重载功能（用于调试时的更高效率）
if(POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
endif() 

set(CMAKE_CXX_STANDARD 23)

project (GAME)

# 设置 SFML动态库 路径
#set(SFML_DIR _library/sfml)

set(SFMLUI_INCLUDE sfml_ui/include)

# 添加项目的头文件目录
include_directories(              
    "${SFMLUI_INCLUDE}/core"
    "${SFMLUI_INCLUDE}/customizable/components"   
    "${SFMLUI_INCLUDE}/customizable/controls"   
    "${SFMLUI_INCLUDE}/core/pages"     
    "${SFMLUI_INCLUDE}/core/message"   
    "${SFMLUI_INCLUDE}/core/window" 
    "${SFMLUI_INCLUDE}/test" 
    #"${SFML_DIR}/include"
    
    "game/include/pages"
    "elemental/include"
)

# 添加 SFML 的库文件路径
#link_directories(${SFML_DIR}/lib)
# 设置库文件目录
#link_directories("_library/box2d/lib")
# 添加源文件
add_executable(GAME 
    "sfml_ui/src/core/window/Window.cpp"      
    #"sfml_ui/src/test/main.cpp"              
    "sfml_ui/src/core/message/ActiveKeyBinding .cpp"

    "sfml_ui/src/core/message/Mouse.cpp" 
    "sfml_ui/src/core/pages/Page.cpp" 
    "sfml_ui/src/customizable/components/TimeAnimatedSprite.cpp" 
    "sfml_ui/src/customizable/components/TextureItem.cpp" 
    "sfml_ui/src/core/message/EventBinding.cpp"

    "game/src/main.cpp"

    "elemental/src/elemental.cpp"
)

find_package(SFML  COMPONENTS Network Graphics Window Audio System CONFIG REQUIRED)
target_link_libraries(GAME PRIVATE SFML::Network SFML::Graphics SFML::Window SFML::Audio SFML::System)

#file(COPY ${SFML_DIR}/bin/ DESTINATION ${CMAKE_BINARY_DIR}/)



# 链接 Box2D 静态库
#target_link_libraries(GAME box2d)
# 设置资源文件路径
set(ASSETS_DIR assets)

# 将资源文件复制到构建目录中
file(COPY ${ASSETS_DIR}/images DESTINATION ${CMAKE_BINARY_DIR}/)