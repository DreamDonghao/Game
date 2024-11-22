#pragma once
#include <TextureItem.hpp>
#include <iostream>
namespace sfui {
    class AnimatedSprite {
    public:
        AnimatedSprite(){}
        bool init(const size_t &continuationFrame,
            const int &width, const int &height,const int &x,const int &y) {
            m_width = width;
            m_height = height;
            m_x = x;
            m_y = y;
            m_continuationFrame = continuationFrame;

           
            return true;
        }
        


        void addTextureItems(const FilePath &filepath ){
            m_textureItems.emplace_back().init(filepath, m_width, m_height, m_x, m_y);
        }

        const sf::Sprite &getSprite() {
            
            if (frame == m_continuationFrame) {
                frame = 0;
                ++m_nowTextureItemsIndex;
                if (m_nowTextureItemsIndex == m_textureItems.size()) {
                    m_nowTextureItemsIndex = 0;
                }
            }
          
            ++frame;
            std::cout << m_nowTextureItemsIndex;
            return m_textureItems[m_nowTextureItemsIndex].getSprite();
          

        }
    private:
        std::vector< TextureItem> m_textureItems;
        int m_x;
        int m_y;
        int m_width;
        int m_height;
        std::size_t frame = 0;
        std::size_t m_nowTextureItemsIndex = 0;
        std::size_t m_continuationFrame = 0;
    };
}