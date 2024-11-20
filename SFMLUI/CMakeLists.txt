# 设置最低所需的 CMake 版本为 3.8 或更高
cmake_minimum_required(VERSION 3.8)

# 设置项目的 C++ 标准为 C++17
set(CMAKE_CXX_STANDARD 17)

# 项目名称
project(SFMLUI)

# 设置 SFML 的路径
set(SFML_DIR SFML)

# 设置资源文件路径
set(ASSETS_DIR assets)

# 将资源文件复制到构建目录中
file(COPY ${ASSETS_DIR}/images DESTINATION ${CMAKE_BINARY_DIR}/SFMLUI/)

# 添加项目的头文件目录
include_directories(
    "include"               
    "include/core"           
    "include/customizable/components"   
    "include/core/pages"     
    "include/core/message"   
    "include/core/window" 
    "${SFML_DIR}/include"
)

# 添加 SFML 的库文件路径
link_directories(${SFML_DIR}/lib)

# 添加源文件
add_executable(SFMLUI 
    "src/core/Window.cpp"      
    "src/main.cpp"              
    "src/customizable/mainpage.cpp" 
)


# 链接 SFML 的库
target_link_libraries(SFMLUI 
    sfml-audio
    sfml-graphics
    sfml-network
    sfml-system
    sfml-window
)

file(COPY ${SFML_DIR}/bin DESTINATION ${CMAKE_BINARY_DIR})



