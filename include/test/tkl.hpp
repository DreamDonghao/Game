//
// Created by donghao on 25-8-12.
//
#ifndef TKL_HPP
#define TKL_HPP
#pragma once

#include <Page.hpp>
#include <Rectangle.hpp>
#include <ParticleBuilder.hpp>
#include <boss.hpp>
using namespace std::chrono_literals;

namespace game {
    class TklPage final : public sfui::Page {
    private:
        std::vector<sfui::Rectangle> tkl;
        std::function<sfui::Task<void>()> updateTkl;
        std::vector<sfui::Task<void>> cos;
        sfui::TimeInterval tklUpdateTime;

    public:
        explicit TklPage(sfui::Window *p_window)
            : Page(p_window),
              tkl({
                  {800, 300, 185, 185, sf::Color::Yellow, sf::Color::Black},
                  {600, 500, 185, 185, sf::Color::White, sf::Color::Black},
                  {800, 500, 185, 185, sf::Color::White, sf::Color::Black},
                  {1000, 500, 185, 185, sf::Color::White, sf::Color::Black},
                  {800, 700, 185, 185, sf::Color::White, sf::Color::Black},
              }),
              updateTkl([&]()-> sfui::Task<void> {
                  co_await std::suspend_always{};
                  bool flag = true;
                  // ReSharper disable once CppDFAEndlessLoop
                  while (true) {
                      if (tklUpdateTime.elapsedMs() > 800) {
                          tklUpdateTime.reset();
                          if (flag) {
                              tkl[1].setSize(160, 160);
                              tkl[3].setSize(160, 160);
                              tkl[2].setSize(200, 200);
                              tkl[4].setSize(200, 200);
                              flag = false;
                          } else {
                              tkl[2].setSize(160, 160);
                              tkl[4].setSize(160, 160);
                              tkl[1].setSize(200, 200);
                              tkl[3].setSize(200, 200);
                              flag = true;
                          }
                      }
                      co_await std::suspend_always{};
                  }
              }){
        }

        // 初始化界面元素
        void init() override {
            cos.emplace_back(updateTkl());
        }

        void updateByMessage() override {
        }

        // 执行逻辑
        void update() override {
            cos[0].resume();
        }

        // 渲染页面内容到窗口
        void render() override {
            drawForWindow(
                tkl[0], tkl[1], tkl[2], tkl[3], tkl[4]
            );
            drawForView(

            );
        }
    };
}

#endif //TKL_HPP
