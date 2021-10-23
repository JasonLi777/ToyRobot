#ifndef TOYROBOTSTATUS_H
#define TOYROBOTSTATUS_H

#include "..\Util\Position.h"
#include "..\Util\Direction.h"
#include <memory>

class TableTop;

class ToyRobotStatus
{
public:
    ToyRobotStatus();
    ~ToyRobotStatus();

    std::shared_ptr<TableTop> tableTop() const;
    void setTableTop(std::shared_ptr<TableTop> tableTop);

    Position position() const;
    void setPosition(const Position& position);

    Direction direction() const;
    void setDirection(const Direction& direction);

    //verify validation, include position on table
    bool isValid() const;

private:
    std::shared_ptr<TableTop> m_tableTop;
    Position m_position;
    Direction m_direction;
};

#endif // TOYROBOTSTATUS_H
