//#include <stdio.h>
//#include <cassert>
//#include "Game.h"
//#include "Board.h"
//
//int main()
//{
//    //TEST CASES FOR addship()
//    Game a(8, 5);
//    a.dump();
//    assert(a.addShip(3, 'a', "Harry") == true);
//    assert(a.addShip(0, 'b', "ERROR") == false);
//    assert(a.addShip(9, 'c', "ERROR") == false);
//    assert(a.addShip(8, 'd', "Beta") == true);
//    assert(a.addShip(5, 'e', "Gamma") == true);
//    assert(a.addShip(3, 'e', "ADFA") == false);
//    assert(a.addShip(3, 'd', "dd") == false);
//    assert(a.addShip(1, EOF, "dd") == false);
//    assert(a.addShip(2, 'x', "test") == true);
//    assert(a.addShip(2, 'X', "test") == false);
//    assert(a.addShip(3, 'o', "FAIK") == false);
//    assert(a.addShip(3, '.', "dd") == false);
//    a.dump();
//    Board b(a);
//    b.block();
//    b.display(true);
//    b.clear();
//    b.display(true);
//    
//    BoardImpl c(a);
//    
//}

#include "Game.h"
#include "Player.h"
#include <iostream>
#include <string>

using namespace std;

bool addStandardShips(Game& g)
{
    return g.addShip(5, 'A', "aircraft carrier")  &&
           g.addShip(4, 'B', "battleship")  &&
           g.addShip(3, 'D', "destroyer")  &&
           g.addShip(3, 'S', "submarine")  &&
           g.addShip(2, 'P', "patrol boat");
}

int main()
{
    const int NTRIALS = 9999;

    cout << "Select one of these choices for an example of the game:" << endl;
    cout << "  1.  A mini-game between two mediocre players" << endl;
    cout << "  2.  A human player against a human player" << endl;
    cout << "  3.  A " << NTRIALS
         << "-game match between a mediocre and an awful player, with no pauses"
         << endl;
    cout << "  4.  A " << NTRIALS
         << "-game match between a good and a mediocre player, with no pauses"
         << endl;
    cout << "Enter your choice: ";
    string line;
    getline(cin,line);
    if (line.empty())
    {
        cout << "You did not enter a choice" << endl;
    }
    else if (line[0] == '1')
    {
        Game g(2, 3);
        g.addShip(2, 'R', "rowboat");
        Player* p1 = createPlayer("mediocre", "Popeye", g);
        Player* p2 = createPlayer("mediocre", "Bluto", g);
        cout << "This mini-game has one ship, a 2-segment rowboat." << endl;
        g.play(p1, p2);
        delete p1;
        delete p2;
    }
    else if (line[0] == '2')
    {
        Game g(7, 7);
        addStandardShips(g);
        Player* p1 = createPlayer("human", "Harvey", g);
        Player* p2 = createPlayer("human", "Shubh", g);
        g.play(p1, p2);
        delete p1;
        delete p2;
    }
    else if (line[0] == '3')
    {
        int nMediocreWins = 0;

        for (int k = 1; k <= NTRIALS; k++)
        {
            cout << "============================= Game " << k
                 << " =============================" << endl;
            Game g(10, 10);
            addStandardShips(g);
            Player* p1 = createPlayer("awful", "Awful Audrey", g);
            Player* p2 = createPlayer("mediocre", "Mediocre Mimi", g);
            Player* winner = (k % 2 == 1 ?
                                g.play(p1, p2, false) : g.play(p2, p1, false));
            if (winner == p2)
                nMediocreWins++;
            delete p1;
            delete p2;
        }
        cout << "The mediocre player won " << nMediocreWins << " out of "
             << NTRIALS << " games." << endl;
          // We'd expect a mediocre player to win most of the games against
          // an awful player.  Similarly, a good player should outperform
          // a mediocre player.
    }
    else if (line[0] == '4')
    {
        int nMediocreWins = 0;

        for (int k = 1; k <= NTRIALS; k++)
        {
            cout << "============================= Game " << k
                 << " =============================" << endl;
            Game g(10, 10);
            addStandardShips(g);
            Player* p1 = createPlayer("good", "SmartyPants Harvey", g);
            Player* p2 = createPlayer("mediocre", "Mediocre Mimi", g);
            Player* winner = (k % 2 == 1 ?
                                g.play(p1, p2, false) : g.play(p2, p1, false));
            if (winner == p2)
                nMediocreWins++;
            delete p1;
            delete p2;
        }
        cout << "The mediocre player won " << nMediocreWins << " out of "
             << NTRIALS << " games." << endl;
          // We'd expect a mediocre player to win most of the games against
          // an awful player.  Similarly, a good player should outperform
          // a mediocre player.
    }
    else
    {
       cout << "That's not one of the choices." << endl;
    }
}