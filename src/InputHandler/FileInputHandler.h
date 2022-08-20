#ifndef FILEINPUTHANDLER_H
#define FILEINPUTHANDLER_H

#include "AbstractInputHandler.h"
#include <fstream>

namespace ToyRobot
{

class FileInputHandler : public AbstractInputHandler
{
public:
    FileInputHandler(const std::string& fileName);
    virtual ~FileInputHandler();

    virtual std::istream& getLine(std::string& output);

private:
    std::ifstream m_ifstream;
};

}

#endif // FILEINPUTHANDLER_H
