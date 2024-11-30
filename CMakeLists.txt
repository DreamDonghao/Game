# 指定最低的 CMake 版本要求，这里要求版本 3.8 或更高
cmake_minimum_required (VERSION 3.8)

# 设置 vcpkg 工具链文件的路径，指定使用 vcpkg 来管理第三方库
#  set(CMAKE_TOOLCHAIN_FILE "C:/Programs/vcpkg/scripts/buildsystems/vcpkg.cmake" CACHE STRING "")

# 如果支持，启用 MSVC 编译器的热重载功能（用于调试时的更高效率）
if (POLICY CMP0141)
  # 设置 CMake 策略 CMP0141 为 NEW，启用热重载功能
  cmake_policy(SET CMP0141 NEW)
  
  # 设置 MSVC 编译器的调试信息格式为 EditAndContinue（支持热重载）
  # 对于 Debug 和 RelWithDebInfo 配置，使用 EditAndContinue 或 ProgramDatabase 格式
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

# 设置项目的 C++ 标准为 C++23
set(CMAKE_CXX_STANDARD 26)

#set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} /Ox /fp:fast")

# 设置项目名称为 "SFMLUI"
project ("MY")

# 包含名为 "SFMLUI" 的子项目
add_subdirectory (SFMLUI)

add_subdirectory (Game)
