# 设置最低所需的 CMake 版本为 3.8 或更高
cmake_minimum_required(VERSION 3.8)

# 设置项目的 C++ 标准为 C++23
set(CMAKE_CXX_STANDARD 23)

# 查找 SFML 库，要求版本为 2.6.2，并且必须包含图形（graphics）、窗口（window）和系统（system）组件
find_package(SFML 2.6.2 REQUIRED COMPONENTS graphics window system)

# 添加项目的头文件目录，包含自定义的路径
include_directories(
    "include"               
    "include/core"          
    "include/customizable"  
    "include/core/pages"    
)

# 添加源文件并生成可执行文件 SFMLUI
add_executable(SFMLUI 
    "src/core/Window.cpp"      
    "src/main.cpp"             
    "src/customizable/mainpage.cpp"  
)

# 链接 SFML 库到生成的可执行文件 SFMLUI
# 使用 sfml-graphics, sfml-window 和 sfml-system 库
target_link_libraries(SFMLUI PRIVATE sfml-graphics sfml-window sfml-system)
