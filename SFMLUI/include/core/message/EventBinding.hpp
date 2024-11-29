//#pragma once
//#include <SFML/Graphics.hpp>
//#include <functional>
//#include <unordered_map>
//
//namespace sfui {
//    // 事件
//    using Action = std::function<void()>;
//
//
//
//    struct  MouseEvent {
//        int left; int up; int right; int lowe;
//        sf::Mouse::Button mousrButton;
//    };
//
//    class EvectBingding {
//    public:
//        EvectBingding() {}
//
//        // 绑定瞬间消息与事件
//       /* void bindEvent(Key key, Action action) {
//            keyBindings[key] = action;
//        }*/
//        void bindEvent(MouseEvent mouseEvent, Action action) {
//            mouseBindings[mouseEvent] = action;
//        }
//        // 检查消息并执行消息对应的事件
//        void update(sf::Event event) {
//            // 处理键盘事件
//           
//
//            // 处理鼠标点击事件
//            //for (const auto &[button, action] : mouseBindings) {
//            //    if (sf::Mouse::isButtonPressed(button)) {
//            //        // 获取鼠标坐标
//            //        sf::Vector2i mousePos = sf::Mouse::getPosition();
//            //        MouseClickEvent mouseEvent(button, mousePos.x, mousePos.y);
//            //        action(mouseEvent);  // 触发绑定的鼠标点击事件
//            //    }
//            //}
//        }
//
//
//        /////////////////////////////////////////////////////////////////////////
//        void update(sf::RenderWindow &window, sf::Event &sf_event) {
//
//            while (window.pollEvent(sf_event)) {
//                switch (sf_event.type) {
//                case sf::Event::Closed:
//
//                    break;
//
//                case sf::Event::Resized:
//
//                    break;
//
//                case sf::Event::LostFocus:
//
//                    break;
//
//                case sf::Event::GainedFocus:
//
//                    break;
//
//                case sf::Event::TextEntered:
//
//                    break;
//
//                case sf::Event::KeyPressed:
//
//                    break;
//
//                case sf::Event::KeyReleased:
//
//                    break;
//
//                case sf::Event::MouseWheelScrolled:
//
//                    break;
//
//                case sf::Event::MouseButtonPressed:
//
//                    break;
//
//                case sf::Event::MouseButtonReleased:
//
//                    break;
//
//                case sf::Event::MouseMoved:
//
//                    break;
//
//                case sf::Event::MouseEntered:
//
//                    break;
//
//                case sf::Event::MouseLeft:
//
//                    break;
//
//                case sf::Event::TouchBegan:
//
//                    break;
//
//                case sf::Event::TouchMoved:
//
//                    break;
//
//                case sf::Event::TouchEnded:
//
//                    break;
//
//                case sf::Event::SensorChanged:
//
//                    break;
//
//                case sf::Event::JoystickButtonPressed:
//
//                    break;
//
//                case sf::Event::JoystickButtonReleased:
//
//                    break;
//
//                case sf::Event::JoystickMoved:
//
//                    break;
//
//                case sf::Event::JoystickConnected:
//
//                    break;
//
//                case sf::Event::JoystickDisconnected:
//
//                    break;
//
//                default:
//
//                    break;
//                }
//            }
//        }
//
//        void handleClosed();
//
//
//    private:
//        std::unordered_map<sf::Event, Action> keyBindings;  // 键盘按键与事件的映射
//        std::unordered_map<MouseEvent, Action> mouseBindings;  // 鼠标按钮与事件的映射
//    };
//}