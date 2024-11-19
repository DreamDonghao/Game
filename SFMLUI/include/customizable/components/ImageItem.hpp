#pragma once 

#include <SFML/Graphics.hpp>
namespace sfui {

	class ImageItem {
	public:
		ImageItem() {
		}

		~ImageItem() {
		}

	private:
		sf::Texture m_sf_texture;
		sf::Sprite m_sf_sprite;
	};


}