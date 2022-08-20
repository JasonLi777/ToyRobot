#ifndef TABLETOP_H
#define TABLETOP_H

class Position;

class TableTop
{
public:
    TableTop(const int width, const int length);
    ~TableTop() = default;

    int getWidth() const;
    int getLength() const;

    bool isValid() const;
    bool isOnTheTable(const Position& position) const;

private:
    int m_width;
    int m_length;
};

#endif // TABLETOP_H
