//
// Created by donghao on 25-8-4.
//
#ifndef COROUTINE_HPP
#define COROUTINE_HPP
#include <coroutine>
#include <exception>

namespace sfui {
    template<typename ReturnType>
    struct Task {
        struct promise_type {
            Task get_return_object() {
                return Task(std::coroutine_handle<promise_type>::from_promise(*this));
            }

            [[nodiscard]] std::suspend_never initial_suspend() const { return {}; }
            [[nodiscard]] std::suspend_always final_suspend() const noexcept { return {}; }

            void return_value(ReturnType val) { m_val = val; }

            auto yield_value(ReturnType val) {
                m_val = val;
                return std::suspend_always{};
            }

            void unhandled_exception() const { std::terminate(); }
            ReturnType m_val;
        };

        explicit Task(std::coroutine_handle<promise_type> h)
            : m_coroutine(h) {
        }

        Task(const Task &) = delete;

        Task &operator=(const Task &) = delete;

        Task(Task &&other) noexcept
            : m_coroutine(other.m_coroutine) {
            other.m_coroutine = nullptr;
        }

        Task &operator=(Task &&other) noexcept {
            if (this != &other) {
                if (m_coroutine) m_coroutine.destroy();
                m_coroutine = other.m_coroutine;
                other.m_coroutine = nullptr;
            }
            return *this;
        }

        ~Task() {
            if (m_coroutine) {
                if (!m_coroutine.done())
                    m_coroutine.resume();
                m_coroutine.destroy();
            }
        }

        void resume(){
            if (!m_coroutine.done()) {
                m_coroutine.resume();
            }
        }

        ReturnType getValue() {
            return m_coroutine.promise().m_val;
        }

        [[nodiscard]] bool done() const {
            return !m_coroutine || m_coroutine.done();
        }

    private:
        std::coroutine_handle<promise_type> m_coroutine;
    };


    template<>
    struct Task<void> {
        struct promise_type {
            Task get_return_object() {
                return Task(std::coroutine_handle<promise_type>::from_promise(*this));
            }

            [[nodiscard]] std::suspend_never initial_suspend() const { return {}; }
            [[nodiscard]] std::suspend_always final_suspend() const noexcept { return {}; }

            void return_void() const {
            }

            void unhandled_exception() const { std::terminate(); }
        };

        explicit Task(std::coroutine_handle<promise_type> h)
            : m_coroutine(h) {
        }

        Task(const Task &) = delete;

        Task &operator=(const Task &) = delete;

        Task(Task &&other) noexcept
            : m_coroutine(other.m_coroutine) {
            other.m_coroutine = nullptr;
        }

        Task &operator=(Task &&other) noexcept {
            if (this != &other) {
                if (m_coroutine) m_coroutine.destroy();
                m_coroutine = other.m_coroutine;
                other.m_coroutine = nullptr;
            }
            return *this;
        }

        ~Task() {
            if (m_coroutine) m_coroutine.destroy();
        }

        // ReSharper disable once CppMemberFunctionMayBeConst
        void resume(){
            if (!m_coroutine.done()) {
                m_coroutine.resume();
            }
        }

        [[nodiscard]] bool done() const {
            return !m_coroutine || m_coroutine.done();
        }

    private:
        std::coroutine_handle<promise_type> m_coroutine;
    };
}
#endif //COROUTINE_HPP
