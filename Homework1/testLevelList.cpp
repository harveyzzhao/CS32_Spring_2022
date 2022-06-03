//#include <cassert>
//#include <iostream>
//#include "LevelList.h"
//
//using namespace std;
//
//int main()
//{
//    LevelList a;
//    assert(a.add(10000) == false);
//    assert(a.add(300) == true);
//    for (int i = 0; i < 179; i++)
//    {
//        assert(a.add(35 + i) == true);
//    }
//    assert(a.add(305) == false);
////    a.retrieveLevelList().dump();
//    assert(a.size() == 180);
//    assert(a.minimum() == 35);
//    assert(a.maximum() == 300);
//
//    //testing remove()
//    assert(a.remove(300) == true);
//    assert(a.remove(300) == false);
//    assert(a.size() == 179);
//    for (int i = 178; i >= 0; i--)
//    {
//        assert(a.remove(35 + i) == true);
//    }
//    assert(a.remove(35) == false);
////    a.retrieveLevelList().dump();
//
//
//    //testing size()
//    assert(a.size() == 0);
//
//    //testing minimum()
//    assert(a.minimum() == NO_LEVEL);
//    assert(a.maximum() == NO_LEVEL);
//    assert(a.add(36) == true);
//    assert(a.add(35) == true);
//    assert(a.minimum() == 35);
//
//    //testing maximum()
//    assert(a.maximum() == 36);
////    a.retrieveLevelList().dump();
//
//    //testing copy constructor and assignment operator
//    LevelList b = a;
////    b.retrieveLevelList().dump();
//
//    LevelList c;
////    c.retrieveLevelList().dump();
//    c = b;
////    c.retrieveLevelList().dump();
//}
