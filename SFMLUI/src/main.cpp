#include <main.hpp>

int main() {
    sfui::Window window(2000, 1000);
    window.addPage(sfui::TitleName("1"), sfui::makePage<sfui::MainPage>());
    window.addPage(sfui::TitleName("2"), sfui::makePage<sfui::MainPage>());
    window.startShow(sfui::TitleName("1"));
    return 0;
}