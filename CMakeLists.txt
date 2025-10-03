# 指定最低的 CMake 版本要求，这里要求版本 3.8 或更高
cmake_minimum_required(VERSION 3.8)

# 如果支持，启用 MSVC 编译器的热重载功能（用于调试时的更高效率）
if (POLICY CMP0141)
    cmake_policy(SET CMP0141 NEW)
endif ()

set(CMAKE_CXX_STANDARD 23)

project(GAME)

# 设置 SFML动态库 路径
set(SFML_DIR _library/SFML-2.6.1)

set(SFMLUI_INCLUDE include)

# 添加项目的头文件目录
include_directories(
        "${SFMLUI_INCLUDE}/core"
        "${SFMLUI_INCLUDE}/customizable/components"
        "${SFMLUI_INCLUDE}/customizable/controls"
        "${SFMLUI_INCLUDE}/core/pages"
        "${SFMLUI_INCLUDE}/core/message"
        "${SFMLUI_INCLUDE}/core/window"
        "${SFMLUI_INCLUDE}/test"
        "${SFML_DIR}/include"

        "game/include/pages"

        "include/game"
        "include/core/tool"
        "include/core/audio"
)

# 添加 SFML 的库文件路径
link_directories(${SFML_DIR}/lib)
# 设置库文件目录
#link_directories("_library/box2d/lib")
# 添加源文件
add_executable(GAME
        "src/core/window/Window.cpp"
        "src/test/main.cpp"
        "src/core/message/ActiveKeyBinding.cpp"
        "src/core/message/Mouse.cpp"
        "src/core/pages/Page.cpp"
        "src/customizable/components/TimeAnimatedSprite.cpp"
        "src/customizable/components/TextureItem.cpp"
        "src/core/message/EventBinding.cpp"
        src/customizable/components/textbox.cpp
        include/customizable/components/textbox.hpp
        include/customizable/components/inputbox.hpp
        include/core/tool.hpp
        src/customizable/components/inputbox.cpp
        include/customizable/components/Circle.hpp
        include/customizable/components/ParticleBuilder.hpp
        include/customizable/components/timepiece.hpp
        include/game/player.hpp
        include/game/hitbox.hpp
        include/game/boss.hpp
        include/game/bullet.hpp
        include/game/playerWithCircle.hpp
        include/core/tool/co.hpp
        include/test/tkl.hpp
        include/customizable/components/Rectangle.hpp
        include/core/tool/Angle.hpp
        src/game/boss.cpp
        include/game/test/boss_a.hpp
        src/game/buttle.cpp
        include/customizable/components/progressBar.hpp
        include/game/test/player_a.hpp
        include/core/audio/soundEffect.hpp
        include/game/item.hpp
        include/game/test/weapon1.hpp
        include/game/word.hpp
)

# 链接 SFML 的库
# 链接 SFML 的库（自动选择 debug / release）
set(SFML_LIBS sfml-audio sfml-graphics sfml-network sfml-system sfml-window)

foreach (lib IN LISTS SFML_LIBS)
    target_link_libraries(GAME
            debug ${lib}-d
            optimized ${lib}
    )
endforeach ()

file(COPY ${SFML_DIR}/bin/ DESTINATION ${CMAKE_BINARY_DIR}/)

# 链接 Box2D 静态库
#target_link_libraries(GAME box2d)
# 设置资源文件路径
set(ASSETS_DIR assets)

# 将资源文件复制到构建目录中
#file(COPY ${ASSETS_DIR}/images DESTINATION ${CMAKE_BINARY_DIR}/)
file(COPY ${ASSETS_DIR} DESTINATION ${CMAKE_BINARY_DIR}/)