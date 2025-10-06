//
// Created by donghao on 25-8-4.
//
#ifndef COROUTINE_HPP
#define COROUTINE_HPP
#include <coroutine>
#include <exception>

namespace sfui {
    struct Task {
        struct promise_type {
            Task get_return_object() {
                return Task(std::coroutine_handle<promise_type>::from_promise(*this));
            }

            [[nodiscard]] std::suspend_always initial_suspend() const { return {}; }
            [[nodiscard]] std::suspend_always final_suspend() const noexcept { return {}; }

            void return_void() const {
            }

            void unhandled_exception() const { std::terminate(); }
        };

        explicit Task(const std::coroutine_handle<promise_type> h)
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
        void resume() {
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

    class TaskScheduler {
    public:
        TaskScheduler() = default;

        ~TaskScheduler() = default;

        void addTask(Task task) {
            m_tasks.emplace_back(std::move(task));
        }

        void resume() {
            std::ranges::for_each(m_tasks, [this](auto &task) {
                task.resume();
            });
            std::erase_if(m_tasks, [](auto &task) {
                return task.done();
            });
        }

    private:
        std::vector<Task> m_tasks;
    };
}
#endif //COROUTINE_HPP
