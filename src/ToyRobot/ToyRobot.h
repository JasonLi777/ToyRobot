#ifndef TOYROBOT_H
#define TOYROBOT_H

#include <memory>
#include <functional>
#include "Direction.h"
#include "Position.h"

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
    bool move();
    bool rotate(const Direction::TurnDirection turnDirection);

    Position getPosition() const;
    Direction getDirection() const;

    bool isPlaced() const;

private:
    const static std::unordered_map<std::string, std::function<void(Position& position)>> m_moveFuncMap;

    std::shared_ptr<TableTop> m_tableTop;
    Position m_position;
    Direction m_direction;
    bool m_placed;
};

}

#endif // TOYROBOT_H
