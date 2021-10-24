#ifndef POSITION_H
#define POSITION_H

class Position
{
public:
    Position();
    Position(const int x, const int y);
    ~Position();

    bool operator==(const Position& position) const;

    int x() const;
    void setX(const int x);

    int y() const;
    void setY(const int y);

    bool isValid() const;

private:
    int m_x;
    int m_y;
};

#endif // POSITION_H
