//#include <iostream>
//#include <cassert>
//#include "Sequence.h"
//using namespace std;
//
//int main()
//{
//    /*
//     //The following codes are tested under the assumption that ItemType = std::string
//     Sequence m_new;
//     assert(m_new.size() == 0);
//     assert(m_new.empty() == true);
//     //checking the first insert function
//     assert(m_new.insert(1, "Queen") == -1);
//     assert(m_new.insert(0, "Queen") == 0);
//     assert(m_new.size() == 1);
//     assert(m_new.empty() == false);
//     assert(m_new.insert(1, "King") == 1);
//     assert(m_new.insert(1, "Wanton") == 1);
//     assert(m_new.insert(0, "Hola") == 0);
//     assert(m_new.insert(-2, "hoho") == -1);
//     assert(m_new.insert(4, "China") == 4);
//     assert(m_new.insert(100, "papa") == -1);
//     m_new.dump();
//
//     //checking the second insert function
//     assert(m_new.insert("Apple") == 0);
//     assert(m_new.insert("Banana") == 1);
//     assert(m_new.insert("Lol") == 3);
//     assert(m_new.insert("Zhao") == 8);
//     m_new.dump();
//
//     //checking erase()
//     assert(m_new.erase(0) == true);
//     assert(m_new.erase(-100) == false);
//     assert(m_new.erase(8) == false);
//     m_new.dump();
//     assert(m_new.erase(7) == true);
//     m_new.dump();
//     assert(m_new.erase(3) == true);
//     m_new.dump();
//     assert(m_new.size() == 6);
//
//     //checking remove()
//     assert(m_new.insert("China") == 1);
//     assert(m_new.insert("China") == 1);
//     assert(m_new.insert("China") == 1);
//     m_new.dump();
//     assert(m_new.remove("China") == 4);
//     assert(m_new.remove("") == 0);
//     assert(m_new.remove("Banana") == 1);
//     assert(m_new.size() == 4);
//     m_new.dump();
//
//     //checking get(int pos, ItemType& value)
//     ItemType testObject = "";
//     assert(m_new.get(0, testObject) == true && testObject == "Hola");
//     assert(m_new.get(-2, testObject) == false && testObject == "Hola");
//     assert(m_new.get(1, testObject) == true && testObject == "Lol");
//     assert(m_new.get(4, testObject) == false && testObject == "Lol");
//     assert(m_new.size() == 4);
//
//     //checking set(int pos, const ItemType& value)
//     assert(m_new.set(-1, testObject) == false && testObject == "Lol");
//     assert(m_new.set(1, testObject) == true);
//     assert(m_new.set(2, testObject) == true && testObject == "Lol");
//     assert(m_new.set(3, testObject) == true);
//     assert(m_new.set(4, testObject) == false);
//     m_new.dump();
//
//     //checking find()
//     assert(m_new.find(testObject) == 1);
//     assert(m_new.find("") == -1);
//     assert(m_new.find("Hola") == 0);
//
//
//     //checking swap()
//     Sequence m_new_2;
//     assert(m_new_2.insert("Apple") == 0);
//     assert(m_new_2.insert("Lol") == 1);
//     assert(m_new_2.insert("Banana") == 1);
//     assert(m_new_2.insert("Zhao") == 3);
//     assert(m_new_2.insert("Gobbler") == 2);
//     m_new.dump();
//     m_new_2.dump();
//     m_new.swap(m_new_2);
//     cout << "--------------------------" << endl;
//     m_new.dump();
//     m_new_2.dump();
//
//     Sequence m_new_3;
//     m_new.swap(m_new_3);
//     m_new.dump();
//     m_new_3.dump();
//    */
//
//    Sequence m_new;
//    m_new.insert(100000);
//    m_new.dump();
//
//    Sequence s;
//    assert(s.empty());
//    assert(s.find(42) == -1);
//    assert(s.insert(42) == 0);
//    assert(s.size() == 1  &&  s.find(42) == 0);
//
//    m_new = s;
//    s.dump();
//
//    Sequence copied(s);
//    copied.dump();
//    cerr << "Passed all tests" << endl;
//
////    Sequence s;
////    assert(s.empty());
////    assert(s.find("laobing") == -1);
////    assert(s.insert("laobing") == 0);
////    assert(s.size() == 1  &&  s.find("laobing") == 0);
////    cout << "Passed all tests" << endl;
//}
