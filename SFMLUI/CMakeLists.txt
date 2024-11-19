# 设置最低所需的 CMake 版本为 3.8 或更高
cmake_minimum_required(VERSION 3.8)

# 设置项目的 C++ 标准为 C++23
set(CMAKE_CXX_STANDARD 23)

# 项目名称
project(SFMLUI)

# 添加项目的头文件目录，包含自定义的路径
include_directories(
    "include"                # 主头文件目录
    "include/core"           # 核心功能的头文件
    "include/customizable"   # 可定制模块的头文件
    "include/core/pages"     # 页面相关功能的头文件
    "include/core/message"   # 消息相关功能的头文件
)

# 查找 SFML 库
find_package(SFML 2.5 REQUIRED COMPONENTS graphics window system)

# 添加源文件并生成可执行文件 SFMLUI
add_executable(SFMLUI 
    "src/core/Window.cpp"        # 窗口类的源文件
    "src/main.cpp"               # 主程序文件
    "src/customizable/mainpage.cpp"  # 可定制页面的源文件
)

# 链接 SFML 库到生成的可执行文件 SFMLUI
# 使用 sfml-graphics, sfml-window 和 sfml-system 库
target_link_libraries(SFMLUI sfml-graphics sfml-window sfml-system)

# 如果你的 SFML 是手动安装的，或者是源代码，可以通过下面的方式设置路径
# set(SFML_DIR "path/to/SFML")
# find_package(SFML 2.5 REQUIRED COMPONENTS graphics window system)
