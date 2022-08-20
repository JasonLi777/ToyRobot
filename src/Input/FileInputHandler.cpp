#include "FileInputHandler.h"

namespace ToyRobot
{

FileInputHandler::FileInputHandler(const std::string &fileName)
{
    m_ifstream.open(fileName, std::ifstream::in);
}

FileInputHandler::~FileInputHandler()
{
    m_ifstream.close();
}

std::istream& FileInputHandler::getLine(std::string& output)
{
    return std::getline(m_ifstream, output);
}

}
