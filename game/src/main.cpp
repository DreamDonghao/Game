#include <MainMenuPage.hpp>

#include <Window.hpp>
#include <gamepage.hpp>
#include <windows.h>
#include <filesystem>

//#include <box2d.h>
constexpr int width = 16;
constexpr int heigth = 10;
constexpr int ratio = 80;

auto main() -> int {
    //FreeConsole();  // 现代C++依然支持隐藏控制台窗口
    sfui::Window window(width*ratio, heigth*ratio, sfui::WindowState::Windowed);
    window.init(165, false);
    window.addPage(sfui::TitleName("mainPage"), sfui::makePage<game::MainMenuPage>(&window.getSfRenderWindow()));
    window.addPage(sfui::TitleName("gamePage"), sfui::makePage<game::GamePage>(&window.getSfRenderWindow()));
    //window.addPage(sfui::TitleName("pauseGamePage"), sfui::makePage<game::PauseGamePage>());
    window.startShow(sfui::TitleName("mainPage"));


    return 0;
}


