#ifndef SOUNDEFFECT_HPP
#define SOUNDEFFECT_HPP

#include <filesystem>
#include <SFML/Audio.hpp>

namespace sfui {
    class SoundEffect {
    public:
        explicit SoundEffect(const std::filesystem::path &path) {
            if (!m_soundBuffer.loadFromFile(path.string())) {
                throw std::runtime_error("Failed to load sound effect: " + path.string());
            }
            m_sound.setBuffer(m_soundBuffer);
        }

        SoundEffect(SoundEffect &&other) noexcept
            : m_soundBuffer(other.m_soundBuffer) {
            m_sound.setBuffer(m_soundBuffer);
        }

        SoundEffect &operator=(SoundEffect &&other) noexcept {
            if (this != &other) {
                m_soundBuffer = other.m_soundBuffer;
                m_sound.setBuffer(m_soundBuffer);
            }
            return *this;
        }

        SoundEffect(const SoundEffect&) = delete;
        SoundEffect& operator=(const SoundEffect&) = delete;

        void play() { m_sound.play(); }
        void stop() { m_sound.stop(); }

    private:
        sf::Sound m_sound;
        sf::SoundBuffer m_soundBuffer;
    };
} // namespace sfui

#endif // SOUNDEFFECT_HPP
