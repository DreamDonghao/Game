#pragma once 
#include <SFML/Graphics.hpp>
namespace sfui {
	using FilePath = std::string;
	class TextureItem {
	public:
		TextureItem(const FilePath &filepath,const int &width,const int &height) {
			if (!m_sf_texture.loadFromFile(filepath)) {
				
			}
			m_sf_sprite.setTexture(m_sf_texture);
		}
		sf::Sprite getSprite() const {
			return m_sf_sprite;
		}
		~TextureItem() {
		}

	private:
		sf::Texture m_sf_texture;
		sf::Sprite m_sf_sprite;
	};


}