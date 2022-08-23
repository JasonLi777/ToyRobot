#ifndef INPUTPARSERPROVIDER_H
#define INPUTPARSERPROVIDER_H

#include <string>
#include <vector>
#include <memory>
#include <optional>

namespace ToyRobot
{

class AbstractCommand;
class AbstractCommandFactory;

class InputParser
{
public:
    static InputParser* getInstance();

    std::shared_ptr<AbstractCommand> parse(const std::string& input) const;

    void registerCommandFactory(std::shared_ptr<AbstractCommandFactory> factory);

private:
    InputParser() = default;
    ~InputParser() = default;

private:
    std::vector<std::shared_ptr<AbstractCommandFactory>> m_parserContainer;
};

}

#endif // INPUTPARSERPROVIDER_H
