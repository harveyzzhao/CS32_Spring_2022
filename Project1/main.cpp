#include "Game.h"

///////////////////////////////////////////////////////////////////////////
//  main()
///////////////////////////////////////////////////////////////////////////
int main()
{
      // Create a game
      // Use this instead to create a mini-game:   Game g(3, 4, 2);
    Game g(7, 8, 25);

      // Play the game
    g.play();

//    //test history function incrementally
//    History* history = new History(7, 8);
//    history->display();
//    cout << "------------------" << endl;
//    assert(history->record(100, 8) == false);
//    assert(history->record(1, 1) == true);
//    assert(history->record(1, 1) == true);
//    for (int i = 0; i < 100; i++)
//        assert(history->record(4, 3) == true);
//    for (int i = 0; i < 10; i++)
//        assert(history->record(5, 4) == true);
//    assert(history->record(0, 0) == false);
//    assert(history->record(7, 8) == true);
//    assert(history->record(0, 7) == false);
//    history->display();
//
//    Mesa* m = new Mesa(7, 8);
//    Gark i(m, 1, 2);
//    cout << i.row() << " " << i.col() << endl;
//    Gark dead(m, 1, 1);
//    assert(!i.getAttacked(RIGHT));
//    assert(i.getAttacked(RIGHT));
//    Gark second(m, 1, 2);
//    assert(!i.getAttacked(RIGHT));
//    assert(i.getAttacked(UP));
//    assert(dead.getAttacked(LEFT));
//    assert(!second.getAttacked(RIGHT));
//    m->history().display();
}

