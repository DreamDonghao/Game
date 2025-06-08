#pragma once
#include <biology.hpp>
namespace game {

    class Player: private Biology{
    public:
        Player(const do                                                                                                                                                                                                                           2*94662800
            uble &x,const double &y){
            m_x = x;
            m_y = y;
        }
        bool init(const float &continuationtTime,
                  const int &width, const int &height, const float &x, const float &y) override{
            Biology::init(continuationtTime,width,height,x,y);
            return true;
        }
    private:

    };

}