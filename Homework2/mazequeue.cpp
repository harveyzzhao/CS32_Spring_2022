#include <queue>
#include <iostream>
#include <cassert>
using namespace std;

class Coord
{
  public:
    Coord(int rr, int cc) : m_row(rr), m_col(cc) {}
    int r() const { return m_row; }
    int c() const { return m_col; }
  private:
    int m_row;
    int m_col;
};

bool pathExists(char maze[][10], int sr, int sc, int er, int ec)
{
    queue<Coord> coordQueue;
    coordQueue.push(Coord(sr, sc));
    maze[sr][sc] = '#';
    
    while (!coordQueue.empty())
    {
        Coord front = coordQueue.front();
        int fr = front.r();
        int fc = front.c();
        coordQueue.pop();
        
        if (fr == er && fc == ec)
            return true;
        
        if (maze[fr][fc - 1] == '.')
        {
            coordQueue.push(Coord(fr, fc - 1));
            maze[fr][fc - 1] = '#';
        }
        
        if (maze[fr - 1][fc] == '.')
        {
            coordQueue.push(Coord(fr - 1, fc));
            maze[fr - 1][fc] = '#';
        }
        
        if (maze[fr][fc + 1] == '.')
        {
            coordQueue.push(Coord(fr, fc + 1));
            maze[fr][fc + 1] = '#';
        }
        
        if (maze[fr + 1][fc] == '.')
        {
            coordQueue.push(Coord(fr + 1, fc));
            maze[fr + 1][fc] = '#';
        }
    }
    return false;
}

int main()
{
    char maze[10][10] = {
        { 'X','X','X','X','X','X','X','X','X','X' },
        { 'X','.','X','.','.','.','X','.','.','X' },
        { 'X','.','X','.','X','X','X','X','.','X' },
        { 'X','.','X','.','.','X','.','X','.','X' },
        { 'X','.','X','X','.','X','.','.','.','X' },
        { 'X','.','.','.','.','.','#','X','X','X' },
        { 'X','.','X','X','X','X','.','X','.','X' },
        { 'X','.','.','.','.','X','X','X','.','X' },
        { 'X','.','X','.','.','X','.','.','.','X' },
        { 'X','X','X','X','X','X','X','X','X','X' }
    };

    assert(pathExists(maze, 5, 6, 1, 5));
    
    char mazeAlpha[10][10] = {
        { 'X','X','X','X','X','X','X','X','X','X' },
        { 'X','.','X','.','.','.','X','.','.','X' },
        { 'X','.','X','.','X','X','X','X','.','X' },
        { 'X','.','X','.','.','X','.','X','.','X' },
        { 'X','.','X','X','.','X','.','.','.','X' },
        { 'X','.','.','X','.','.','.','X','X','X' },
        { 'X','.','X','X','X','X','.','X','.','X' },
        { 'X','.','.','.','.','X','X','X','.','X' },
        { 'X','.','X','.','.','X','.','.','.','X' },
        { 'X','X','X','X','X','X','X','X','X','X' }
    };
    assert(pathExists(mazeAlpha, 2, 1, 5, 4) == false);

}

