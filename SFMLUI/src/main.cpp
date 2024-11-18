#include <main.hpp>

int main() {
    sfui::Window window(800, 600,sfui::WindowState::Windowed());
    window.addPage(sfui::TitleName("1"), sfui::makePage<sfui::TestPage>());
    window.addPage(sfui::TitleName("2"), sfui::makePage<sfui::TestPage>());
    window.startShow(sfui::TitleName("1"));
    return 0;
}