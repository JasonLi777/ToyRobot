#ifndef TOYROBOT_H
#define TOYROBOT_H

#include <memory>
#include "../Util/Direction.h"
#include "../Util/Position.h"

namespace ToyRobot
{

class AbstractCommand;
class TableTop;

class ToyRobot
{
public:
    ToyRobot(const std::shared_ptr<TableTop>& tableTop);
    ~ToyRobot() = default;

    bool place(const Position& position, const Direction& direction);

    bool setPosition(const Position& position);
    Position getPosition() const;

    bool setDirection(const Direction& direction);
    Direction getDirection() const;

    bool isReady() const;

private:
    std::shared_ptr<TableTop> m_tableTop;
    Position m_position;
    Direction m_direction;
    bool m_ready;
};

}

#endif // TOYROBOT_H
