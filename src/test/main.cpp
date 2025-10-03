// TIP
// Created by donghao on 25-6-12.
// TIP
#include <Window.hpp>
#include <TestPage.hpp>
#include <windows.h>
#include <filesystem>
#include <tkl.hpp>
#include <timepiece.hpp>
//#include <box2d.h>
constexpr int width = 16;
constexpr int heigth = 10;
constexpr int ratio = 100;

#define TEST

int main() {
    sf::Music music;
    music.openFromFile("assets/media/PixelDreams.mp3");
    music.setPitch(0.5);
    music.setLoop(true);
    music.play();

    //#define TEST

#ifdef TEST
    sfui::Window window(
        width * ratio, heigth * ratio, sfui::WindowState::Windowed,
        12000, false
    );
    window.addPage(sfui::strToWstr("铁傀儡机"), sfui::makePage<game::TklPage>(&window));
    window.addPage(sfui::strToWstr("主界面"), sfui::makePage<game::MainMenuPage>(&window));
    window.startShow(sfui::strToWstr("主界面"));
#endif
    return 0;
}
