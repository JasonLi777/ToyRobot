#ifndef DIRECTION_H
#define DIRECTION_H

#include <string>
#include <vector>

namespace ToyRobot
{

class Direction
{
public:

    enum class TurnDirection {
        LEFT,
        RIGHT
    };

public:
    Direction();
    Direction(const std::string& direction);
    ~Direction() = default;

    bool operator==(const Direction& direction) const;

    bool isValid() const;

    bool turn(const TurnDirection turn);

    std::string toString() const;

private:
    int m_index;

    static const std::vector<std::string> m_allDirection;
};

}

#endif // DIRECTION_H
