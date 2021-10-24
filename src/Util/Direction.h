#ifndef DIRECTION_H
#define DIRECTION_H

#include <string>

class Direction
{
public:
    enum DirectionEnum {
        INVALID = 0,
        NORTH,
        EAST,
        SOUTH,
        WEST,
    };

    enum TurnEnum {
        LEFT = 0,
        RIGHT
    };

public:
    static Direction fromString(const std::string& direction);

public:
    Direction();
    Direction(const DirectionEnum direction);
    ~Direction();

    bool operator==(const Direction& direction) const;

    DirectionEnum value() const;
    void setValue(const DirectionEnum direction);

    std::string toString() const;

    bool isValid() const;

    //turn left or right
    bool turn(const TurnEnum turn);

private:
    DirectionEnum m_direction;
};

#endif // DIRECTION_H
