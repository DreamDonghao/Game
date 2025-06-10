#include <main.hpp>
#include <ComplexPage.hpp>
int main() {

    sfui::Window window(1000, 1000,sfui::WindowState::Windowed);
    window.init(165, false);
    window.addPage(sfui::TitleName("1"), sfui::makePage<sfui::TestPage>());
    window.addPage(sfui::TitleName("2"), sfui::makePage<sfui::TestPage>());
    window.startShow(sfui::TitleName("1"));

    return 0;
}
