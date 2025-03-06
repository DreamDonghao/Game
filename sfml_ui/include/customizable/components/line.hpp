#include <SFML/Graphics.hpp>

namespace sfui {

    class Line {
    public:
        Line() = default;
        bool init(const double &&x, const double &&y,
            const double &&xx, const double &yy, const sf::Color &&color) {
            m_x = x;
            m_y = y;
            m_xx = xx;
            m_yy = yy;
            m_color = color;
        }
    private:
        double m_x;
        double m_y;
        double m_xx;
        double m_yy;
        sf::Color m_color;
    };

}
