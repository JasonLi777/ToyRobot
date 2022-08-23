#ifndef COMMANDFACTORYMANAGER_H
#define COMMANDFACTORYMANAGER_H

#include <string>
#include <vector>
#include <memory>
#include <optional>

namespace ToyRobot
{

class AbstractCommand;
class AbstractCommandFactory;

class CommandFactoryManager
{
public:
    static CommandFactoryManager* getInstance();

    std::shared_ptr<AbstractCommand> buildCommand(const std::string& input) const;

    void registerCommandFactory(std::shared_ptr<AbstractCommandFactory> factory);

private:
    CommandFactoryManager() = default;
    ~CommandFactoryManager() = default;

private:
    std::vector<std::shared_ptr<AbstractCommandFactory>> m_allFactory;
};

}

#endif // COMMANDFACTORYMANAGER_H
