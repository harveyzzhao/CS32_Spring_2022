#include <iostream>
#include <cassert>
#include <string>
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
//    If the start location is equal to the ending location, then we've
//            solved the maze, so return true.
    if (sr == er && sc == ec)   return true;
    maze[sr][sc] = '#';
    
    if (maze[sr][sc - 1] == '.')
        if (pathExists(maze, sr, sc-1, er, ec)) return true;
    if (maze[sr - 1][sc] == '.')
        if (pathExists(maze, sr-1, sc, er, ec)) return true;
    if (maze[sr][sc + 1] == '.')
        if (pathExists(maze, sr, sc+1, er, ec)) return true;
    if (maze[sr + 1][sc] == '.')
        if (pathExists(maze, sr+1, sc, er, ec)) return true;
    
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
    cout << "passed all tests" << endl;
}
