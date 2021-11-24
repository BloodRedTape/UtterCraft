#ifndef ABSTRACTION_HPP
#define ABSTRACTION_HPP 

#include <memory>
#include <core/math/matrix4.hpp>
#include <core/math/vector3.hpp>
#include <core/os/window.hpp>
#include <graphics/api/framebuffer.hpp>
#include <graphics/api/semaphore.hpp>

class Abstraction{
public:
    virtual void Tick(float dt, const Framebuffer *fb, const Semaphore &wait, const Semaphore &signal) = 0;
};

using AbstractionRef = std::unique_ptr<Abstraction>;

class AbstractionManager{
private:
    AbstractionRef m_CurrentAbstraction;
    AbstractionRef m_PendingAbstraction;
private:
    AbstractionManager(const Window &window);

    ~AbstractionManager();
public:
    void Tick(float dt);

    static void Initialize(const Window &window);

    static void Finalize();

    static AbstractionManager &Get();
};

#endif//ABSTRACTION_HPP 