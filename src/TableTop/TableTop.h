#ifndef TABLETOP_H
#define TABLETOP_H

namespace ToyRobot
{

class TableTop
{
public:
    TableTop(const int width, const int length);
    ~TableTop() = default;

    int getWidth() const;
    int getLength() const;

    bool isValid() const;
    bool isOnTheTable(const int x, const int y) const;

private:
    int m_width;
    int m_length;
};

}

#endif // TABLETOP_H
