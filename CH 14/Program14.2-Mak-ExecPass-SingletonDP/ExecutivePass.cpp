#include "ExecutivePass.h"

ExecutivePass *ExecutivePass::single_instance = nullptr;

ExecutivePass::~ExecutivePass() { single_instance = nullptr; }

ExecutivePass *ExecutivePass::obtain(const string holder)
{
    if (single_instance == nullptr)
    {
        single_instance = new ExecutivePass();
    }

    single_instance->holder = holder;
    return single_instance;
}
