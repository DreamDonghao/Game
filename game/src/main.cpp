#include <MainMenuPage.hpp>
#include <Window.hpp>
//#include <box2d.h>
constexpr int width = 8;
constexpr int heigth = 5;
constexpr int ratio = 200;
auto main() -> int {
    sfui::Window window(width*ratio, heigth*ratio, sfui::WindowState::Windowed);
    window.init(165, false);
    window.addPage(sfui::TitleName("1"), sfui::makePage<game::MainMenuPage>());
    window.startShow(sfui::TitleName("1"));
    return 0;
}

