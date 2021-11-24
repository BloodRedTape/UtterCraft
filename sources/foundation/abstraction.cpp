#include "foundation/abstraction.hpp"
#include <core/raw_var.hpp>

AbstractionManager::AbstractionManager(const Window &window){

}

AbstractionManager::~AbstractionManager(){

}

void AbstractionManager::Tick(float dt){
    if(m_CurrentAbstraction)
        ;//m_CurrentAbstraction->Tick(dt, const Framebuffer *fb, const Semaphore &wait, const Semaphore &signal)
    if(m_PendingAbstraction)
        m_CurrentAbstraction = Move(m_PendingAbstraction);
}

static RawVar<AbstractionManager> s_Instance;

void AbstractionManager::Initialize(const Window &window){
    s_Instance.Construct(window);
}

void AbstractionManager::Finalize(){
    s_Instance.Destruct();
}

AbstractionManager &AbstractionManager::Get(){
    return *s_Instance;
}
