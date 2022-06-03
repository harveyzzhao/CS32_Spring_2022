#ifndef History_h
#define History_h

#include "globals.h"
//This command shows you for each grid point how many times during the course of the game a gark
//was at that point when the player attacked the gark without that gark dying: dot means 0 times,
//a letter character A through Y means 1 through 25 times (A means 1, B means 2, etc.) and Z means
//26 or more times.

class History
{
public:
    History(int nRows, int nCols);
    bool record(int r, int c);
    void display() const;
    ~History(){}
private:
    int m_rows;
    int m_cols;
    int m_table[MAXROWS][MAXCOLS];
};

#endif /* History_hpp */
