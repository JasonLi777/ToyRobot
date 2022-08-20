#ifndef COMMANDFACTORYREGISTER_H
#define COMMANDFACTORYREGISTER_H

#include <memory>

class AbstractCommandFactory;

class CommandFactoryRegister
{
public:
    CommandFactoryRegister(std::shared_ptr<AbstractCommandFactory> parser);
    ~CommandFactoryRegister() = default;
};

#define REGISTER_COMMAND_FACTORY(className)                                                                 \
    static CommandFactoryRegister s_commandFactoryRegister##className(std::make_shared<className>());       \

#endif // COMMANDFACTORYREGISTER_H
