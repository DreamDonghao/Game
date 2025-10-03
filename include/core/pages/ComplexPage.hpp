// #pragma once
// #include <Page.hpp>
//
// namespace sfui {
//     /**
//      * @brief 混合界面类，结合了交互页面和控件页面的功能
//      *
//      * 既支持控件布局，也支持动态交互内容。
//      */
//     class ComplexPage :public Page {
//     public:
//         explicit ComplexPage(Window *p_window):Page(p_window){}
//         /**
//          * @brief 析构函数
//          */
//         ~ComplexPage() override =default;
//
//         /**
//          * @brief 同时缩放控件和交互内容
//          * @param ratio 缩放比例
//          */
//         // void zooms(const double& ratio){
//         //     ControlPage::zoom(ratio);
//         //     InteractivePage::zoom(ratio);
//         // }
//
//         /**
//          * @brief 更新视图，分别更新控件和交互内容的视图
//          */
//         void updateView() override{
//             i_updateView();
//         }
//
//         /**
//          * @brief 获取窗口视图
//          * @return 窗口视图
//          */
//         sf::View getWindowView() const {
//             return mi_view;
//         }
//
//         /**
//          * @brief 获取世界视图
//          * @return 世界视图
//          */
//         sf::View getWorldView() const {
//             return mi_view;
//         }
//
//         /**
//          * @brief 以窗口为依据绘制对象
//          * @tparam DrawObject 可绘制对象类型
//          * @param drawObject 绘制对象
//          */
//         template<typename DrawObject>
//         void drawForWindow(const DrawObject &drawObject ) {
//             draw(drawObject);
//         }
//
//         /**
//          * @brief 以视图为依据绘制对象
//          * @tparam DrawObject 可绘制对象类型
//          * @param drawObject 绘制对象
//          */
//         template<typename DrawObject>
//         void drawForView(const DrawObject &drawObject) {
//             draw(drawObject.drow(mp_window->getSfRenderWindow()));
//         }
//
//         void i_updateView() {
//             m_windowSize = mp_window->getWindowSize();
//             mi_view.setSize(
//                 static_cast<float>(m_windowSize.x),
//                 static_cast<float>(m_windowSize.y)
//             );
//             mi_view.setCenter(mi_x, mi_y);
//             mp_window->getSfRenderWindow().setView(mi_view);
//         }
//
//         void setViewCenter(const float &x, const float &y) {
//             mi_x = x;
//             mi_y = y;
//         }
//
//
//
//     protected:
//         double m_ratio = 1; ///< 当前缩放比例
//         sf::View mi_view;
//         float mi_x = 0.0; ///< 视图中心x坐标
//         float mi_y = 0.0; ///< 视图中心y坐标
//         // 窗口大小
//         WindowSize m_windowSize;
//     };
//
// }
