#include <stack>
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
    stack<Coord> coordStack;
    coordStack.push(Coord(sr, sc));
    maze[sr][sc] = '#';

    while (!coordStack.empty())
    {
        Coord top = coordStack.top();
        int tr = top.r();
        int tc = top.c();
        coordStack.pop();

        if (tr == er && tc == ec)
            return true;

        if (maze[tr][tc - 1] == '.')
        {
            coordStack.push(Coord(tr, tc - 1));
            maze[tr][tc - 1] = '#';
        }

        if (maze[tr - 1][tc] == '.')
        {
            coordStack.push(Coord(tr - 1, tc));
            maze[tr - 1][tc] = '#';
        }

        if (maze[tr][tc + 1] == '.')
        {
            coordStack.push(Coord(tr, tc + 1));
            maze[tr][tc + 1] = '#';
        }

        if (maze[tr + 1][tc] == '.')
        {
            coordStack.push(Coord(tr + 1, tc));
            maze[tr + 1][tc] = '#';
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
        { 'X','.','.','.','.','.','.','X','X','X' },
        { 'X','.','X','X','X','X','.','X','.','X' },
        { 'X','.','.','.','.','X','X','X','.','X' },
        { 'X','.','X','.','.','X','.','.','.','X' },
        { 'X','X','X','X','X','X','X','X','X','X' }
    };

    assert(pathExists(maze, 5, 6, 8, 1));

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
