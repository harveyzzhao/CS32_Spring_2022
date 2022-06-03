#include <iostream>
#include "History.h"
#include "globals.h"

History::History(int nRows, int nCols)
    : m_rows(nRows), m_cols(nCols)
{
    //initialize the table entries
    for (int i = 0; i < nRows; i++)
        for (int j = 0; j < nCols; j++)
            m_table[i][j] = 0;
}

//(1, 1) represents top left
bool History::record(int r, int c)
{
    if (r < 1 || r > m_rows)
        return false;
    else if (c < 1 || c > m_cols)
        return false;
    else
    {
        m_table[r - 1][c - 1]++;
        return true;
    }
}

void History::display() const
{
//    This function does clear the screen, display the history grid,
//    and write an empty line after the history grid; it does not print the Press enter to continue.
    
    clearScreen();
    
    //display history grid
    for (int i = 0; i < m_rows; i++)
    {
        for (int j = 0; j < m_cols; j++)
        {
            char displayedChar;
            if (m_table[i][j] == 0)
                displayedChar = '.';
                
            else if (m_table[i][j] >= 1 && m_table[i][j] <= 25)
                displayedChar = '@' + m_table[i][j];
            
            else if (m_table[i][j] > 25)
                displayedChar = 'Z';
            
            else
                return;
            std::cout << displayedChar;
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}


