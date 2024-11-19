# 设置最低所需的 CMake 版本为 3.8 或更高
cmake_minimum_required(VERSION 3.8)

# 设置项目的 C++ 标准为 C++23
set(CMAKE_CXX_STANDARD 17)

# 项目名称
project(SFMLUI)

# 设置资源文件路径
set(ASSETS_DIR ${CMAKE_SOURCE_DIR}/assets)
# 将资源文件复制到构建目录中
file(COPY assets/images DESTINATION ${CMAKE_BINARY_DIR}/images)

# 设置 SFML 的路径


# 添加 SFML 子目录




# 添加项目的头文件目录，包含自定义的路径
include_directories(
    "include"                # 主头文件目录
    "include/core"           # 核心功能的头文件
    "include/customizable/components"   # 可定制模块的头文件
    "include/core/pages"     # 页面相关功能的头文件
    "include/core/message"   # 消息相关功能的头文件
    "include/core/window"
   
)

# 查找 SFML 库
find_package(SFML 2.5 REQUIRED COMPONENTS graphics window system)

# 添加源文件并生成可执行文件 SFMLUI
add_executable(SFMLUI 
    "src/core/Window.cpp"        # 窗口类的源文件
    "src/main.cpp"               # 主程序文件
    "src/customizable/mainpage.cpp"  # 可定制页面的源文件
)


# 链接 SFML 的库
target_link_libraries(SFMLUI PRIVATE sfml-graphics sfml-window sfml-system)

# 设置 SFML 的头文件路径
target_include_directories(SFMLUI PRIVATE "SFML/include/")
# 链接 SFML 库到生成的可执行文件 SFMLUI
# 使用 sfml-graphics, sfml-window 和 sfml-system 库
#target_link_libraries(SFMLUI sfml-graphics sfml-window sfml-system)

# 如果你的 SFML 是手动安装的，或者是源代码，可以通过下面的方式设置路径
# set(SFML_DIR "path/to/SFML")
# find_package(SFML 2.5 REQUIRED COMPONENTS graphics window system)
