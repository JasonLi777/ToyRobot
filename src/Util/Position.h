#ifndef POSITION_H
#define POSITION_H

class Position
{
public:
    Position();
    Position(const int x, const int y);
    ~Position() = default;

    bool operator==(const Position& position) const;

    int getX() const;
    void setX(const int x);

    int getY() const;
    void setY(const int y);

    bool isValid() const;

private:
    int m_x;
    int m_y;
};

#endif // POSITION_H
