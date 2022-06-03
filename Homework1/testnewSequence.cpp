////#include "newSequence.h"
////
////#include <iostream>
////#include <cassert>
////using namespace std;
////
////int main()
////{
////     //The following codes are tested under the assumption that ItemType = std::string
////     Sequence m_new;
////     assert(m_new.size() == 0);
////     assert(m_new.empty() == true);
////     //checking the first insert function
////     assert(m_new.insert(1, "Queen") == -1);
////     assert(m_new.insert(0, "Queen") == 0);
////     assert(m_new.size() == 1);
////     assert(m_new.empty() == false);
////     assert(m_new.insert(1, "King") == 1);
////     assert(m_new.insert(1, "Wanton") == 1);
////     assert(m_new.insert(0, "Hola") == 0);
////     assert(m_new.insert(-2, "hoho") == -1);
////     assert(m_new.insert(4, "China") == 4);
////     assert(m_new.insert(100, "papa") == -1);
////     m_new.dump();
////
////     //checking the second insert function
////     assert(m_new.insert("Apple") == 0);
////     assert(m_new.insert("Banana") == 1);
////     assert(m_new.insert("Lol") == 3);
////     assert(m_new.insert("Zhao") == 8);
////     m_new.dump();
////
////     //checking erase()
////     assert(m_new.erase(0) == true);
////     assert(m_new.erase(-100) == false);
////     assert(m_new.erase(8) == false);
////     m_new.dump();
////     assert(m_new.erase(7) == true);
////     m_new.dump();
////     assert(m_new.erase(3) == true);
////     m_new.dump();
////     assert(m_new.size() == 6);
////
////     //checking remove()
////     assert(m_new.insert("China") == 1);
////     assert(m_new.insert("China") == 1);
////     assert(m_new.insert("China") == 1);
////     m_new.dump();
////     assert(m_new.remove("China") == 4);
////     assert(m_new.remove("") == 0);
////     assert(m_new.remove("Banana") == 1);
////     assert(m_new.size() == 4);
////     m_new.dump();
////
////     //checking get(int pos, ItemType& value)
////     ItemType testObject = "";
////     assert(m_new.get(0, testObject) == true && testObject == "Hola");
////     assert(m_new.get(-2, testObject) == false && testObject == "Hola");
////     assert(m_new.get(1, testObject) == true && testObject == "Lol");
////     assert(m_new.get(4, testObject) == false && testObject == "Lol");
////     assert(m_new.size() == 4);
////
////     //checking set(int pos, const ItemType& value)
////     assert(m_new.set(-1, testObject) == false && testObject == "Lol");
////     assert(m_new.set(1, testObject) == true);
////     assert(m_new.set(2, testObject) == true && testObject == "Lol");
////     assert(m_new.set(3, testObject) == true);
////     assert(m_new.set(4, testObject) == false);
////     m_new.dump();
////
////     //checking find()
////     assert(m_new.find(testObject) == 1);
////     assert(m_new.find("") == -1);
////     assert(m_new.find("Hola") == 0);
////
////
////     //checking swap()
////     Sequence m_new_2;
////     assert(m_new_2.insert("Apple") == 0);
////     assert(m_new_2.insert("Lol") == 1);
////     assert(m_new_2.insert("Banana") == 1);
////     assert(m_new_2.insert("Zhao") == 3);
////     assert(m_new_2.insert("Gobbler") == 2);
////     m_new.dump();
////     m_new_2.dump();
////     m_new.swap(m_new_2);
////     cerr << "--------------------------" << endl;
////     m_new.dump();
////     m_new_2.dump();
////
////     Sequence m_new_3;
////     m_new.swap(m_new_3);
////     m_new.dump();
////     m_new_3.dump();
////    
////    //test copy constructor, AO
////    Sequence CC(m_new_3);
////    m_new_3.dump();
////    CC.dump();
////    m_new = m_new_2;
////    m_new.dump();
////    
////    //test max capacity
////    Sequence defaultSize;
////    for (int i = 0; i < DEFAULT_MAX_ITEMS; i++)
////        assert(defaultSize.insert("gobblick") == 0);
////    assert(defaultSize.insert("gobbick") == -1);
////    
////    Sequence customSize(1000);
////    for (int i = 0; i < 1000; i++)
////        assert(customSize.insert("test") == 0);
////    assert(customSize.insert("test") == -1);
////    assert(customSize.size() == 1000);
////    assert(defaultSize.size() == 180);
////    
////    customSize.swap(defaultSize);
////    assert(customSize.size() == 180);
////    assert(defaultSize.size() == 1000);
////    assert(customSize.erase(0) == true);
////    assert(customSize.insert("test") == 179);
////    assert(customSize.insert("aaple") == -1);
////    defaultSize.dump();
////    assert(defaultSize.remove("test") == 1000);
////    assert(defaultSize.size() == 0);
////}
////
////    Sequence m_new;
////    m_new.insert(100000);
////    m_new.dump();
////
////    Sequence s;
////    assert(s.empty());
////    assert(s.find(42) == -1);
////    assert(s.insert(42) == 0);
////    assert(s.size() == 1  &&  s.find(42) == 0);
////
////    m_new = s;
////    s.dump();
////
////    Sequence copied(s);
////    copied.dump();
////    cerr << "Passed all tests" << endl;
////
//////    Sequence s;
//////    assert(s.empty());
//////    assert(s.find("laobing") == -1);
//////    assert(s.insert("laobing") == 0);
//////    assert(s.size() == 1  &&  s.find("laobing") == 0);
//////    cerr << "Passed all tests" << endl;
////
////}
//
//
//#include "newSequence.h"
//#include <iostream>
//#include <cassert>
//using namespace std;
//
//void test()
//{
//    Sequence s;
//    s.insert(0, 10);
//    s.insert(0, 20);
//    assert(s.size() == 2);
//    ItemType x = 999;
//    assert(s.get(0, x) && x == 20);
//    assert(s.get(1, x) && x == 10);
//}
//
//int main()
//{
//    test();
//    cout << "Passed all tests" << endl;
//}
//

// tester.cpp
// To test HW 1 Problem 5, uncomment the following line:
//#define TESTNEW

#ifdef TESTNEW
#include "newSequence.h"  // ItemType should be a type alias for long
#else
#include "Sequence.h"  // ItemType should be a type alias for long
#endif

#include <iostream>
#include <cstdlib>
#include <cassert>
#include <type_traits>
using namespace std;

const ItemType DUMMY = 123;
const ItemType DEFAULT = 0;
const ItemType ARRAY[6] = { 10, 20, 30, 40, 50, 60 };

const int SPEC_MAX = 180;

void testone(int n)
{
    Sequence s;
    switch (n)
    {
                 default: {
        cout << "Bad argument" << endl;
            } break; case  1: {
        assert((is_same<decltype(&Sequence::empty), bool (Sequence::*)() const>::value));
            } break; case  2: {
        assert((is_same<decltype(&Sequence::size), int (Sequence::*)() const>::value));
            } break; case  3: {
        assert((is_same<decltype(&Sequence::get), bool (Sequence::*)(int, ItemType&) const>::value));
            } break; case  4: {
        assert((is_same<decltype(&Sequence::find), int (Sequence::*)(const ItemType&) const>::value));
            } break; case  5: {
        assert(s.empty());
            } break; case  6: {
        assert(s.size() == 0);
            } break; case  7: {
        assert(!s.erase(0)  &&  s.size() == 0);
            } break; case  8: {
        assert(s.remove(DEFAULT) == 0  &&  s.size() == 0);
            } break; case  9: {
        ItemType x = DUMMY;
        assert(!s.get(0, x));
            } break; case 10: {
        ItemType x = DUMMY;
        s.get(0, x);
        assert(x == DUMMY);
            } break; case 11: {
        assert(!s.set(0, DUMMY)  &&  s.size() == 0);
            } break; case 12: {
        assert(s.find(DEFAULT) == -1);
            } break; case 13: {
        assert(s.insert(0,DUMMY) == 0);
            } break; case 14: {
        s.insert(0,DUMMY);
        assert(! s.empty());
            } break; case 15: {
        s.insert(0,DUMMY);
        assert(s.size() == 1);
            } break; case 16: {
        s.insert(0,DUMMY);
        assert(s.find(DUMMY) == 0);
            } break; case 17: {
        s.insert(0,DUMMY);
        ItemType x = DEFAULT;
        assert(s.get(0, x));
            } break; case 18: {
        s.insert(0,DUMMY);
        ItemType x = DEFAULT;
        s.get(0, x);
        assert(x == DUMMY);
            } break; case 19: {
        s.insert(0,DUMMY);
        assert(s.set(0, DEFAULT));
            } break; case 20: {
        s.insert(0,DUMMY);
        s.set(0, DEFAULT);
        assert(s.size() == 1);
        ItemType x = DUMMY;
        s.get(0, x);
        assert(x == DEFAULT);
            } break; case 21: {
        s.insert(0,DEFAULT);
        s.set(0, DUMMY);
        assert(s.size() == 1);
        ItemType x = DEFAULT;
        s.get(0, x);
        assert(x == DUMMY);
            } break; case 22: {
        s.insert(0, ARRAY[0]);
        s.insert(1, ARRAY[1]);
        assert(! s.empty()   &&  s.size() == 2);
            } break; case 23: {
        s.insert(0, ARRAY[0]);
        s.insert(1, ARRAY[1]);
        ItemType x = DUMMY;
        s.get(0,x);
        assert(x == ARRAY[0]);
            } break; case 24: {
        s.insert(0, ARRAY[0]);
        s.insert(1, ARRAY[1]);
        ItemType x = DUMMY;
        s.get(1,x);
        assert(x == ARRAY[1]);
            } break; case 25: {
        s.insert(0, ARRAY[0]);
        s.insert(0, ARRAY[1]);
        assert(s.size() == 2);
            } break; case 26: {
        s.insert(0, ARRAY[0]);
        s.insert(0, ARRAY[1]);
        ItemType x = DUMMY;
        s.get(0,x);
        assert(x == ARRAY[1]);
            } break; case 27: {
        s.insert(0, ARRAY[0]);
        s.insert(0, ARRAY[1]);
        ItemType x = DUMMY;
        s.get(1,x);
        assert(x == ARRAY[0]);
            } break; case 28: {
        s.insert(0, ARRAY[3]);
        s.insert(1, ARRAY[1]);
        s.insert(2, ARRAY[0]);
        s.insert(0, ARRAY[4]);
        s.insert(2, ARRAY[2]);
        assert(s.size() == 5);
            } break; case 29: {
        s.insert(0, ARRAY[3]);
        s.insert(1, ARRAY[1]);
        s.insert(2, ARRAY[0]);
        s.insert(0, ARRAY[4]);
        s.insert(2, ARRAY[2]);
        for (size_t k = 0; k < 5; k++)
        {
        ItemType x = DUMMY;
        s.get(k, x);
        assert(x == ARRAY[5-1-k]);
        }
            } break; case 30: {
        s.insert(0, ARRAY[3]);
        s.insert(1, ARRAY[1]);
        s.insert(2, ARRAY[0]);
        s.insert(3, ARRAY[4]);
        s.insert(4, ARRAY[2]);
        for (size_t k = 0; k < 5; k++)
        s.set(k, ARRAY[k]);
        assert(s.size() == 5);
        for (size_t k = 0; k < 5; k++)
        {
        ItemType x = DUMMY;
        s.get(k, x);
        assert(x == ARRAY[k]);
        }
            } break; case 31: {
        assert(s.insert(DUMMY) == 0);
            } break; case 32: {
        s.insert(DUMMY);
        assert(! s.empty());
            } break; case 33: {
        s.insert(DUMMY);
        assert(s.size() == 1);
            } break; case 34: {
        s.insert(DUMMY);
        assert(s.find(DUMMY) == 0);
            } break; case 35: {
        s.insert(ARRAY[0]);
        s.insert(ARRAY[1]);
        assert(! s.empty()   &&  s.size() == 2);
            } break; case 36: {
        s.insert(DUMMY);
        ItemType x = DEFAULT;
        assert(s.get(0, x));
            } break; case 37: {
        s.insert(DUMMY);
        ItemType x = DEFAULT;
        s.get(0, x);
        assert(x == DUMMY);
            } break; case 38: {
        s.insert(ARRAY[0]);
        s.insert(ARRAY[1]);
        ItemType x = DUMMY;
        s.get(0,x);
        assert(x == ARRAY[0]);
            } break; case 39: {
        s.insert(ARRAY[0]);
        s.insert(ARRAY[1]);
        ItemType x = DUMMY;
        s.get(1,x);
        assert(x == ARRAY[1]);
            } break; case 40: {
        s.insert(ARRAY[1]);
        s.insert(ARRAY[0]);
        ItemType x = DUMMY;
        s.get(0,x);
        assert(x == ARRAY[0]);
            } break; case 41: {
        s.insert(ARRAY[1]);
        s.insert(ARRAY[0]);
        ItemType x = DUMMY;
        s.get(1,x);
        assert(x == ARRAY[1]);
            } break; case 42: {
        assert(s.insert(ARRAY[3]) == 0);
        assert(s.insert(ARRAY[1]) == 0);
        assert(s.insert(ARRAY[0]) == 0);
        assert(s.insert(ARRAY[4]) == 3);
        assert(s.insert(ARRAY[2]) == 2);
        assert(s.size() == 5);
            } break; case 43: {
        s.insert(ARRAY[3]);
        s.insert(ARRAY[1]);
        s.insert(ARRAY[0]);
        s.insert(ARRAY[4]);
        s.insert(ARRAY[2]);
        for (size_t k = 0; k < 5; k++)
        {
        ItemType x = DUMMY;
        s.get(k, x);
        assert(x == ARRAY[k]);
        }
            } break; case 44: {
        assert(s.insert(ARRAY[2]) == 0);
        assert(s.insert(ARRAY[1]) == 0);
        assert(s.insert(ARRAY[0]) == 0);
        assert(s.insert(ARRAY[1]) == 1);
        assert(s.insert(ARRAY[1]) == 1);
        assert(s.size() == 5);
        ItemType x = DUMMY;
        s.get(0, x);
        assert(x == ARRAY[0]);
        s.get(4, x);
        assert(x == ARRAY[2]);
        for (size_t k = 1; k < 4; k++)
        {
        x = DUMMY;
        s.get(k, x);
        assert(x == ARRAY[1]);
        }
            } break; case 45: {
        assert(s.insert(1, DUMMY) == -1  &&  s.size() == 0);
            } break; case 46: {
        assert(s.insert(-1, DUMMY) == -1  &&  s.size() == 0);
            } break; case 47: {
        s.insert(0, DUMMY);
        assert(s.insert(2, DUMMY) == -1  &&  s.size() == 1);
            } break; case 48: {
        s.insert(0, DUMMY);
        assert(! s.erase(1)  &&  s.size() == 1);
            } break; case 49: {
        s.insert(0, DUMMY);
        assert(s.erase(0)  &&  s.size() == 0);
            } break; case 50: {
        s.insert(0, ARRAY[0]);
        s.insert(1, ARRAY[1]);
        s.insert(2, ARRAY[2]);
        s.insert(3, ARRAY[3]);
        s.insert(4, ARRAY[4]);
        assert(s.erase(4)  &&  s.size() == 4);
            } break; case 51: {
        s.insert(0, ARRAY[0]);
        s.insert(1, ARRAY[1]);
        s.insert(2, ARRAY[2]);
        s.insert(3, ARRAY[3]);
        s.insert(4, ARRAY[4]);
        s.erase(4);
        ItemType x;
        s.get(3, x);
        assert(x == ARRAY[3]);
            } break; case 52: {
        s.insert(0, ARRAY[0]);
        s.insert(1, ARRAY[1]);
        s.insert(2, ARRAY[2]);
        s.insert(3, ARRAY[3]);
        s.insert(4, ARRAY[4]);
        assert(s.erase(1)  &&  s.size() == 4);
            } break; case 53: {
        s.insert(0, ARRAY[0]);
        s.insert(1, ARRAY[1]);
        s.insert(2, ARRAY[2]);
        s.insert(3, ARRAY[3]);
        s.insert(4, ARRAY[4]);
        s.erase(1);
        ItemType x;
        s.get(0, x);
        assert(x == ARRAY[0]);
        for (size_t k = 1; k < 4; k++)
        {
        s.get(k, x);
        assert(x == ARRAY[k+1]);
        }
            } break; case 54: {
        s.insert(0, DUMMY);
        assert(s.remove(DUMMY) == 1);
            } break; case 55: {
        s.insert(0, DUMMY);
        s.remove(DUMMY);
        assert(s.size() == 0);
            } break; case 56: {
        s.insert(0, ARRAY[0]);
        assert(s.remove(ARRAY[1]) == 0);
            } break; case 57: {
        s.insert(0, ARRAY[0]);
        s.remove(ARRAY[1]);
        assert(s.size() == 1);
            } break; case 58: {
        s.insert(0, ARRAY[4]);
        s.insert(1, ARRAY[3]);
        s.insert(2, ARRAY[2]);
        s.insert(3, ARRAY[1]);
        s.insert(4, ARRAY[0]);
        s.remove(ARRAY[2]);
        ItemType x;
        for (size_t k = 0; k < 2; k++)
        {
        s.get(k, x);
        assert(x == ARRAY[5-1-k]);
        }
        for (size_t k = 2; k < 4; k++)
        {
        s.get(k, x);
        assert(x == ARRAY[5-2-k]);
        }
            } break; case 59: {
        s.insert(0, ARRAY[4]);
        s.insert(1, ARRAY[2]);
        s.insert(2, ARRAY[2]);
        s.insert(3, ARRAY[4]);
        s.insert(4, ARRAY[2]);
        s.insert(5, ARRAY[2]);
        assert(s.remove(ARRAY[2]) == 4);
            } break; case 60: {
        s.insert(0, ARRAY[4]);
        s.insert(1, ARRAY[2]);
        s.insert(2, ARRAY[2]);
        s.insert(3, ARRAY[4]);
        s.insert(4, ARRAY[2]);
        s.insert(5, ARRAY[2]);
        s.remove(ARRAY[2]);
        assert(s.size() == 2);
            } break; case 61: {
        s.insert(0, ARRAY[4]);
        s.insert(1, ARRAY[2]);
        s.insert(2, ARRAY[2]);
        s.insert(3, ARRAY[4]);
        s.insert(4, ARRAY[2]);
        s.insert(5, ARRAY[2]);
        s.remove(ARRAY[2]);
        ItemType x;
        for (size_t k = 0; k < 2; k++)
        {
        x = ARRAY[0];
        s.get(k, x);
        assert(x == ARRAY[4]);
        }
            } break; case 62: {
        s.insert(0, ARRAY[2]);
        s.insert(1, ARRAY[2]);
        s.insert(2, ARRAY[2]);
        s.insert(3, ARRAY[2]);
        s.insert(4, ARRAY[2]);
        s.remove(ARRAY[2]);
        assert(s.size() == 0);
            } break; case 63: {
        s.insert(0, DUMMY);
        s.insert(1, DUMMY);
        s.insert(2, DUMMY);
        ItemType x;
        assert(! s.get(-1, x));
            } break; case 64: {
        s.insert(0, DUMMY);
        s.insert(1, DUMMY);
        s.insert(2, DUMMY);
        ItemType x = ARRAY[1];
        s.get(-1, x);
        assert(x == ARRAY[1]);
            } break; case 65: {
        s.insert(0, DUMMY);
        s.insert(1, DUMMY);
        s.insert(2, DUMMY);
        ItemType x;
        assert(! s.get(3, x));
            } break; case 66: {
        s.insert(0, DUMMY);
        s.insert(1, DUMMY);
        s.insert(2, DUMMY);
        ItemType x = ARRAY[1];
        s.get(3, x);
        assert(x == ARRAY[1]);
            } break; case 67: {
        s.insert(0, ARRAY[0]);
        s.insert(1, ARRAY[1]);
        s.insert(2, ARRAY[2]);
        assert(! s.set(-1, ARRAY[3]));
            } break; case 68: {
        s.insert(0, ARRAY[0]);
        s.insert(1, ARRAY[1]);
        s.insert(2, ARRAY[2]);
        s.set(-1, ARRAY[3]);
        assert(s.size() == 3);
        for (size_t k = 0; k < 3; k++)
        {
        ItemType x = DUMMY;
        assert(s.get(k,x)  &&  x == ARRAY[k]);
        }
            } break; case 69: {
        s.insert(0, ARRAY[0]);
        s.insert(1, ARRAY[1]);
        s.insert(2, ARRAY[2]);
        assert(! s.set(3, ARRAY[3]));
            } break; case 70: {
        s.insert(0, ARRAY[0]);
        s.insert(1, ARRAY[1]);
        s.insert(2, ARRAY[2]);
        s.set(-1, ARRAY[3]);
        assert(s.size() == 3);
        for (size_t k = 0; k < 3; k++)
        {
        ItemType x = DUMMY;
        assert(s.get(k,x)  &&  x == ARRAY[k]);
        }
            } break; case 71: {
        s.insert(DUMMY);
        assert(s.find(DEFAULT) == -1);
            } break; case 72: {
        s.insert(0, ARRAY[1]);
        s.insert(1, ARRAY[4]);
        s.insert(2, ARRAY[2]);
        s.insert(3, ARRAY[4]);
        assert(s.find(ARRAY[4]) == 1);
            } break; case 73: {
        s.insert(0, ARRAY[1]);
        s.insert(1, ARRAY[4]);
        s.insert(2, ARRAY[2]);
        s.insert(3, ARRAY[4]);
        assert(s.find(ARRAY[3]) == -1);
            } break; case 74: {
        s.insert(0, ARRAY[0]);
        s.insert(1, ARRAY[1]);
        {
        Sequence s2;
        s2.insert(0, ARRAY[2]);
        s2.insert(1, ARRAY[3]);
        s.swap(s2);
        assert(s.size() == 2  &&  s2.size() == 2);
        ItemType x;
        assert(s.get(0, x)  &&  x == ARRAY[2]);
        assert(s.get(1, x)  &&  x == ARRAY[3]);
        assert(s2.get(0, x)  &&  x == ARRAY[0]);
        assert(s2.get(1, x)  &&  x == ARRAY[1]);
        }
            } break; case 75: {
        s.insert(0, ARRAY[0]);
        s.insert(1, ARRAY[1]);
        s.insert(2, ARRAY[2]);
        {
        Sequence s2;
        s2.insert(0, ARRAY[3]);
        s2.insert(1, ARRAY[4]);
        s.swap(s2);
        assert(s.size() == 2  &&  s2.size() == 3);
        }
            } break; case 76: {
        s.insert(0, ARRAY[0]);
        s.insert(1, ARRAY[1]);
        s.insert(2, ARRAY[2]);
        {
        Sequence s2;
        s2.insert(0, ARRAY[3]);
        s2.insert(1, ARRAY[4]);
        s.swap(s2);
        ItemType x;
        assert(s.get(0, x)  &&  x == ARRAY[3]);
        assert(s.get(1, x)  &&  x == ARRAY[4]);
        assert(s2.get(0, x)  &&  x == ARRAY[0]);
        assert(s2.get(1, x)  &&  x == ARRAY[1]);
        assert(s2.get(2, x)  &&  x == ARRAY[2]);
        }
            } break; case 77: {
        s.insert(0, ARRAY[0]);
        s.insert(1, ARRAY[1]);
        s.insert(2, ARRAY[2]);
        {
        Sequence s2;
        s2.insert(0, ARRAY[3]);
        s2.insert(1, ARRAY[4]);
        s2.swap(s);
        ItemType x;
        assert(s.get(0, x)  &&  x == ARRAY[3]);
        assert(s.get(1, x)  &&  x == ARRAY[4]);
        assert(s2.get(0, x)  &&  x == ARRAY[0]);
        assert(s2.get(1, x)  &&  x == ARRAY[1]);
        assert(s2.get(2, x)  &&  x == ARRAY[2]);
        }
            } break; case 78: {
        for (size_t k = 0; k < SPEC_MAX; k++)
        assert(s.insert(k, DUMMY) == k);
            } break; case 79: {
        for (size_t k = 0; k < SPEC_MAX; k++)
        assert(s.insert(k, DUMMY) == k);
        assert(s.insert(SPEC_MAX, DUMMY) == -1);
            } break; case 80: {
        for (size_t k = 0; k < SPEC_MAX-1; k++)
        assert(s.insert(k, ARRAY[0]) == k);
        assert(s.insert(ARRAY[1]) == SPEC_MAX-1);
            } break; case 81: {
        for (size_t k = 0; k < SPEC_MAX-1; k++)
        assert(s.insert(k, ARRAY[0]) == k);
        assert(s.insert(ARRAY[2]) == SPEC_MAX-1);
        assert(s.insert(ARRAY[1]) == -1);
#ifdef TESTNEW
            } break; case 82: {
          // This test checked that swap executes the same number of
          // statements no matter how many items are in the sequences
            } break; case 83: {
        const size_t CAPACITY = 2;
        Sequence s2(CAPACITY);
        for (size_t k = 0; k < CAPACITY; k++)
        assert(s2.insert(k, DUMMY) == k);
        assert(s2.insert(CAPACITY, DUMMY) == -1);
            } break; case 84: {
        const size_t CAPACITY = SPEC_MAX*2;
        Sequence s2(CAPACITY);
        for (size_t k = 0; k < CAPACITY; k++)
        assert(s2.insert(k, DUMMY) == k);
        assert(s2.insert(CAPACITY, DUMMY) == -1);
            } break; case 85: {
          // This test checked that the destructor deletes the array of
          // sequence items.
            } break; case 86: {
          // This test checked that the copy constructor allocates a new
          // array of sequence items.
            } break; case 87: {
        s.insert(0, ARRAY[0]);
        s.insert(1, ARRAY[1]);
        s.insert(2, ARRAY[2]);
        {
        Sequence s2(s);
        s2.insert(3, ARRAY[3]);
        assert(s2.size() == s.size()+1);
        }
            } break; case 88: {
        s.insert(0, ARRAY[0]);
        s.insert(1, ARRAY[1]);
        s.insert(2, ARRAY[2]);
        {
        Sequence s2(s);
        s2.insert(0, ARRAY[3]);
        ItemType x;
        assert(s2.get(0, x)  &&  x == ARRAY[3]);
        assert(s2.get(1, x)  &&  x == ARRAY[0]);
        assert(s2.get(2, x)  &&  x == ARRAY[1]);
        assert(s2.get(3, x)  &&  x == ARRAY[2]);
        }
            } break; case 89: {
        s.insert(0, ARRAY[0]);
        s.insert(1, ARRAY[1]);
        s.insert(2, ARRAY[2]);
        {
        Sequence s2(s);
        s2.insert(0, ARRAY[3]);
        ItemType x;
        assert(s.get(0, x)  &&  x == ARRAY[0]);
        assert(s.get(1, x)  &&  x == ARRAY[1]);
        assert(s.get(2, x)  &&  x == ARRAY[2]);
        }
            } break; case 90: {
        {
        Sequence s2(2);
        s2.insert(0,DUMMY);
        s2.insert(1,DUMMY);
        Sequence s3(s2);
        assert(s3.insert(0,DUMMY) == -1);
        }
            } break; case 91: {
          // This test checked that the assignment operator doesn't
          // just copy a pointer.
            } break; case 92: {
          // This test checked that the assignment operator deletes its
          // left operand's array.
            } break; case 93: {
        {
        Sequence s2;
        Sequence s3;
        s3.insert(0, ARRAY[0]);
        s3.insert(1, ARRAY[1]);
        s3 = s2;
        s2.insert(s2.size(), ARRAY[2]);
        s3.insert(s3.size(), ARRAY[3]);
        assert(s2.size() == 1  &&  s3.size() == 1);
        ItemType x;
        s2.get(0, x);
        assert(x == ARRAY[2]);
        s3.get(0, x);
        assert(x == ARRAY[3]);
        }
            } break; case 94: {
        {
        Sequence s2;
        Sequence s3;
        s3.insert(0, ARRAY[0]);
        s3.insert(1, ARRAY[1]);
        assert(s3.size() == 2);
        s2 = s3;
        assert(s2.size() == 2  &&  s3.size() == 2);
        s2.insert(s2.size(), ARRAY[2]);
        s3.insert(s3.size(), ARRAY[3]);
        assert(s2.size() == 3  &&  s3.size() == 3);
        ItemType x;
        for (int k = 0; k < 2; k++)
        {
            s2.get(k, x);
            assert(x == ARRAY[k]);
            s3.get(k, x);
            assert(x == ARRAY[k]);
        }
        s2.get(2, x);
        assert(x == ARRAY[2]);
        s3.get(2, x);
        assert(x == ARRAY[3]);
        }
            } break; case 95: {
        s.insert(0, ARRAY[0]);
        s.insert(1, ARRAY[1]);
        {
        Sequence s2;
        s2.insert(0, ARRAY[3]);
        s2.insert(1, ARRAY[4]);
        s2.insert(2, ARRAY[5]);
        s2 = s;
        assert(s2.size() == s.size());
        ItemType x;
        assert(!s2.get(2, x));
        s2.insert(0, ARRAY[5]);
        assert(s2.size() == s.size()+1);
        }
            } break; case 96: {
        s.insert(0, ARRAY[0]);
        s.insert(1, ARRAY[1]);
        {
        Sequence s2;
        s2.insert(0, ARRAY[3]);
        s2.insert(1, ARRAY[4]);
        s2.insert(2, ARRAY[5]);
        s2 = s;
        s2.insert(0, ARRAY[5]);
        ItemType x;
        assert(s2.get(0, x)  &&  x == ARRAY[5]);
        assert(s2.get(1, x)  &&  x == ARRAY[0]);
        assert(s2.get(2, x)  &&  x == ARRAY[1]);
        }
            } break; case 97: {
        s.insert(0, ARRAY[0]);
        s.insert(1, ARRAY[1]);
        {
        Sequence s2;
        s2.insert(0, ARRAY[3]);
        s2.insert(1, ARRAY[4]);
        s2.insert(2, ARRAY[5]);
        s2 = s;
        s2.insert(0, ARRAY[5]);
        ItemType x;
        assert(s.get(0, x)  &&  x == ARRAY[0]);
        assert(s.get(1, x)  &&  x == ARRAY[1]);
        }
            } break; case 98: {
          // This test checked that self-assignment doesn't change the
          // number of sequence item objects in existence.
            } break; case 99: {
        {
        Sequence s2;
        s2.insert(0, ARRAY[0]);
        s2.insert(1, ARRAY[1]);
        s2.insert(2, ARRAY[2]);
        s2 = s2;
        s2.insert(3, ARRAY[3]);
        ItemType x;
        assert(s2.get(0, x)  &&  x == ARRAY[0]);
        assert(s2.get(1, x)  &&  x == ARRAY[1]);
        assert(s2.get(2, x)  &&  x == ARRAY[2]);
        assert(s2.get(3, x)  &&  x == ARRAY[3]);
        }
#endif
            }
    }
}

int main()
{
    for (int i = 1; i < 100; i++)
        testone(i);
    cout << "Passed" << endl;
}
