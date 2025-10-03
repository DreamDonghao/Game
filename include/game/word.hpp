//
// Created by donghao on 25-8-25.
//
#ifndef WORD_HPP
#define WORD_HPP

#include <array>
#include <fstream>
#include <ranges>
#include <unordered_set>
#include <SFML/Window.hpp>

namespace game {
    template<class T1, class T2>
    struct pair_hash {
        std::size_t operator()(const std::pair<T1, T2> &p) const noexcept {
            auto h1 = std::hash<T1>{}(p.first);
            auto h2 = std::hash<T2>{}(p.second);
            // 通用的组合方式（boost::hash_combine 思想）
            return h1 ^ (h2 + 0x9e3779b9 + (h1 << 6) + (h1 >> 2));
        }
    };


    class Block {
    public:
        Block() = default;

        virtual ~Block() = default;

        virtual int32_t getId() = 0;

    private:
    };

    class Block1 final : public Block {
    public:
        static constexpr int32_t id = 1;

        int32_t getId() override {
            return id;
        }
    };


    class Block2 final : public Block {
    public:
        static constexpr int32_t id = 2;

        int32_t getId() override {
            return id;
        }
    };

    class Chunk {
    public:
        explicit Chunk(const int x = 100, const int y = 1000)
            : m_x(x * 32), m_y(y * 32) {
        }

        Chunk(Chunk &&other) noexcept
            : blocks(std::move(other.blocks)), m_x(other.m_x), m_y(other.m_y) {
        }

        void load(const std::filesystem::path &path) {
            std::ifstream file(path, std::ios::binary);
            int32_t type = 0;
            for (auto &block: blocks) {
                file.read(reinterpret_cast<char *>(&type), sizeof(type));
                switch (type) {
                    case Block1::id:
                        block = std::make_unique<Block1>();
                        break;
                    case Block2::id:
                        block = std::make_unique<Block2>();
                        break;
                    default:
                        block = nullptr; // 或者保持原样
                        break;
                }
            }
        }

        void storage(const std::filesystem::path &path) const {
            std::ofstream file(path, std::ios::binary);
            for (const auto &block: blocks) {
                int32_t blockTypeId = block ? block->getId() : 0;
                file.write(reinterpret_cast<const char *>(&blockTypeId), sizeof(blockTypeId));
            }
        }

        std::unique_ptr<Block> &getBlock(int x, int y) {
            return blocks[x + y * 32];
        }

        const std::unique_ptr<Block> &getBlock(int x, int y) const {
            return blocks[x + y * 32];
        }

        void loadVerTexArray() {
            for (int x = 0; x < 32; ++x) {
                for (int y = 0; y < 32; ++y) {
                    static int i = 0;

                    constexpr int tileSize = 32;
                    const int count = y * 32 + x;

                    const sf::Vector2f p0((m_x + x) * tileSize, (m_y + y) * tileSize);
                    //printf("%d %d\n",(m_x + x) * tileSize, (m_y + y) * tileSize);
                    const sf::Vector2f p1((m_x + x) * tileSize + tileSize, (m_y + y) * tileSize);
                    const sf::Vector2f p2((m_x + x) * tileSize + tileSize, (m_y + y) * tileSize + tileSize);
                    const sf::Vector2f p3((m_x + x) * tileSize, (m_y + y) * tileSize + tileSize);
                    if (getBlock(x, y)->getId() == Block1::id) {
                        const sf::Vector2f t0(0, 0);
                        const sf::Vector2f t1(tileSize, 0);
                        const sf::Vector2f t2(tileSize, tileSize);
                        const sf::Vector2f t3(0, tileSize);
                        // 三角形1
                        sf::Vertex *v = &quad[count * 6];

                        // 三角形1
                        v[0].position = p0;
                        v[0].texCoords = t0;
                        v[1].position = p1;
                        v[1].texCoords = t1;
                        v[2].position = p2;
                        v[2].texCoords = t2;

                        // 三角形2
                        v[3].position = p0;
                        v[3].texCoords = t0;
                        v[4].position = p2;
                        v[4].texCoords = t2;
                        v[5].position = p3;
                        v[5].texCoords = t3;
                    } else {
                        const sf::Vector2f t0(tileSize, tileSize);
                        const sf::Vector2f t1(tileSize + tileSize, tileSize + 0);
                        const sf::Vector2f t2(tileSize + tileSize, tileSize + tileSize);
                        const sf::Vector2f t3(tileSize + 0, tileSize + tileSize);
                        sf::Vertex *v = &quad[count * 6];

                        // 三角形1
                        v[0].position = p0;
                        v[0].texCoords = t0;
                        v[1].position = p1;
                        v[1].texCoords = t1;
                        v[2].position = p2;
                        v[2].texCoords = t2;

                        // 三角形2
                        v[3].position = p0;
                        v[3].texCoords = t0;
                        v[4].position = p2;
                        v[4].texCoords = t2;
                        v[5].position = p3;
                        v[5].texCoords = t3;
                    }

                    sf::Vertex *v = &quad[count * 6];
                }
            }

            tileset.loadFromFile("assets/images/block.png");
        }


        void draw(sf::RenderWindow &window) const {
            window.draw(quad, &tileset);
        }

    private:
        std::array<std::unique_ptr<Block>, 32 * 32> blocks;
        int m_x, m_y;
        mutable sfui::Rectangle m_rectangle{0, 0, 0, 0, sf::Color::White, sf::Color::White};
        mutable sf::RenderTexture renderTexture;
        mutable sf::Sprite sprite;

        sf::VertexArray quad{sf::Triangles, 32 * 32 * 6};
        sf::Texture tileset;
    };


    class Word {
    public:
        Word(const int m_x, const int m_y): m_x(m_x), m_y(m_y), m_oldX(m_x - 1), m_oldY(m_y - 1) {
        }

        void load() {
            std::erase_if(m_chunks, [&](auto &ch) {
                return ch.first.first < m_x - 3 || ch.first.first > m_x + 3 || ch.first.second < m_y - 3 || ch.first
                       .second > m_y + 3;
            });
            for (int i = m_x - 2; i <= m_x + 2; ++i) {
                for (int j = m_y - 1; j <= m_y + 1; ++j) {
                    if (auto [it, inserted] =
                            m_chunks.try_emplace({i, j}, i, j); inserted) {
                        it->second.load("a");
                        it->second.loadVerTexArray();
                    }
                }
            }
        }


        void draw(sf::RenderWindow &window) const {
            for (const auto &chunk: m_chunks | std::views::values) {
                chunk.draw(window);
            }
        }


        void setPosition(const int x, const int y) {
            m_x = x;
            m_y = y;
        }

    private:
        std::unordered_map<std::pair<int, int>, Chunk, pair_hash<int, int> > m_chunks;
        int m_x, m_y;
        int m_oldX, m_oldY;
        std::unordered_set<std::pair<int, int>, pair_hash<int, int> > m_oldChunks;
        bool a = true;
    };
} // game

#endif //WORD_HPP
