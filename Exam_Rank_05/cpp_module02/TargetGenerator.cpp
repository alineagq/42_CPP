#include "TargetGenerator.hpp"

TargetGenerator::TargetGenerator() {}

TargetGenerator::~TargetGenerator()
{
    for (std::map<std::string, ATarget*>::iterator it = targets.begin(); it != targets.end(); ++it)
    {
        delete it->second;
    }
    targets.clear();
}

void TargetGenerator::learnTargetType(ATarget* target)
{
    if (target)
        targets[target->getType()] = target->clone();
}

void TargetGenerator::forgetTargetType(const std::string& targetType)
{
    std::map<std::string, ATarget*>::iterator it = targets.find(targetType);
    if (it != targets.end())
    {
        delete it->second;
        targets.erase(it);
    }
}

ATarget* TargetGenerator::createTarget(const std::string& targetType)
{
    std::map<std::string, ATarget*>::iterator it = targets.find(targetType);
    if (it != targets.end())
        return it->second->clone(); // <-- return a new clone, not the stored pointer
    return NULL;
}

