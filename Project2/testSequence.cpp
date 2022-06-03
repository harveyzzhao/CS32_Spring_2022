////#include "Sequence.h"
////#include <cassert>
////#include <iostream>
////using namespace std;
////
////int main()
////{
////    Sequence m_new;
////    assert(m_new.empty());
////    assert(m_new.size() == 0);
////    assert(m_new.insert(0, 100) == 0);
////    assert(m_new.size() == 1);
////    assert(m_new.insert(-1, 100) == -1);
////    assert(m_new.insert(2, 10000) == -1);
////    assert(m_new.insert(1, 100) == 1);
////    assert(m_new.size() == 2);
////    assert(m_new.insert(0, 10) == 0);
////    assert(m_new.size() == 3);
////    assert(m_new.insert(1, 1000) == 1);
////    assert(m_new.size() == 4);
////    assert(m_new.insert(2, 100000) == 2);
////    assert(m_new.size() == 5);
////    assert(m_new.insert(3, 999) == 3);
////    assert(m_new.size() == 6);
////    assert(m_new.insert(6, 5) == 6);
////    assert(m_new.size() == 7);
////    assert(m_new.insert(7, 100) == 7);
////    assert(m_new.insert(4, 8) == 4);
////    assert(m_new.insert(7, 666) == 7);
////    m_new.dump();
////
////    //test insert function
////    assert(m_new.insert(0) == 0);
////    assert(m_new.insert(1) == 1);
////    assert(m_new.insert(10) == 2);
////    assert(m_new.insert(1001) == 5);
////    m_new.dump();
////
////    Sequence m_new_2;
////    assert(m_new_2.insert(9) == 0);
////    assert(m_new_2.insert(100) == 1);
////    assert(m_new_2.insert(1) == 0);
////    assert(m_new_2.insert(2) == 1);
////    assert(m_new_2.insert(3) == 2);
////    m_new_2.dump();
////    assert(m_new_2.insert(100) == 4);
////    assert(m_new_2.insert(10001) == 6);
////    m_new_2.dump();
////    assert(m_new_2.size() == 7);
////    assert(!m_new_2.empty());
////
////    //test copy constructor
////    cout << "copy constructor: --------" << endl;
////    Sequence cc(m_new_2);
////    cc.dump();
////
////    Sequence empty;
////    Sequence cc_2(empty);
////    Sequence cc_3(m_new);
////    cc_2.dump();
////    m_new.dump();
////    cc_3.dump();
////
////    //test erase()
////    assert(!empty.erase(1));
////    assert(empty.insert(1000) == 0);
////    empty.dump();
////    assert(empty.erase(0));
////    empty.dump();
////    assert(m_new.erase(0));
////    m_new.dump();
////    assert(!m_new.erase(m_new.size()));
////    assert(m_new.erase(m_new.size() - 1));
////    m_new.dump();
////    assert(m_new.erase(10));
////    m_new.dump();
////
////    //test destructor
////    Sequence DS;
////    for (int i = 0; i < 1; i++)
////        assert(DS.insert(i) == DS.size() - 1);
////    DS.dump();
////
////    //test find()
////    Sequence a(m_new);
////    a.dump();
////    assert(a.find(10) == 1);
////    assert(a.find(1) == 0);
////    assert(a.find(999) == 6);
////    assert(a.find(999999999) == -1);
////    assert(a.find(5) == a.size() - 1);
////
////    empty.dump();
////    assert(a.find(4) == -1);
////    empty.insert(10);
////    ItemType val = 999;
////    assert(empty.get(0, val) == true && val == 10);
////    assert(empty.find(10) == 0);
////
////    //test remove()
////    assert(a.remove(10) == 2);
////    a.dump();
////    assert(a.remove(100) == 2);
////    a.dump();
////
////    assert(a.remove(1) == 1);
////    assert(a.remove(0) == 0);
////    assert(a.remove(5) == 1);
////    a.dump();
////
////    assert(empty.remove(10) == 1);
////    assert(empty.remove(10) == 0);
////
////    //test get()
////    assert(empty.get(0, val) == false && val == 10);
////    assert(a.get(4, val) == true && val == 8);
////    assert(a.get(0, val) == true && val == 1000);
////    assert(a.get(2, val) == true && val == 100000);
////
////    //test set()
////    assert(empty.set(0, 100) == false);
////    empty.dump();
////    assert(a.set(4, 888) == true);
////    assert(a.set(3, 777) == true);
////    assert(a.set(2, 666) == true);
////    assert(a.set(1, 555) == true);
////    assert(a.set(0, 444) == true);
////    a.dump();
////    empty.dump();
////
////    cout << "==========================================" << endl;
////    //test swap()
//////    empty.swap(a);
////    a.swap(empty);
////    a.dump();
////    empty.dump();
////
////    Sequence empty2(a);
////    empty2.swap(a);
////    a.dump();
////    empty2.dump();
////
////    m_new.dump();
////    empty.dump();
////
////    m_new.swap(empty);
////
////    m_new.dump();
////    empty.dump();
////
////    //test operator=
////    a = a;
////    a.dump();
////    empty = empty;
////    empty.dump();
////    a.insert(1);
////    empty = a;
////    empty.dump();
////    a.dump();
////    a = empty;
////
////
////    //test subsequence()
////    a.dump();
////    empty.dump();
////    assert (subsequence(a, empty) == 0);
////    assert(a.remove(1) == 1);
////    assert(empty.erase(0) == true);
////    a.dump();
////    empty.dump();
////    assert(subsequence(a, empty) == -1);
////    assert(subsequence(empty, a) == -1);
////
////    Sequence seq1;
////    Sequence seq2;
////    for (int i = 0; i < 4; i++)
//////        assert(seq1.insert(i) == seq1.size() - 1);  //FIXME
//////    for (int i = 0; i < 5; i++)
//////        assert(seq2.insert(i) == seq2.size() - 1);
//////    assert(subsequence(seq1, seq2) == -1);
//////    assert(subsequence(seq2, seq1) == 0);
//////
//////    assert(seq1.insert(4) == 4);
//////    seq1.dump();
//////    assert(subsequence(seq1, seq2) == 0);
//////    seq2.remove(0);
//////    seq2.remove(1);
//////    seq2.remove(2);
//////    seq2.insert(5);
//////    seq2.dump();
//////    assert(subsequence(seq1, seq2) == -1);
//////
//////    assert(seq2.remove(5) == 1);
//////    assert(subsequence(seq1, seq2) == 3);
//////    assert(seq2.remove(3) == 1);
//////    seq1.dump();
//////    seq2.dump();
//////    assert(subsequence(seq1, seq2) == 4);
//////    assert(subsequence(seq2, seq1) == -1);
//////    assert(subsequence(seq1, seq1) == 0);
//////    assert(seq2.remove(4) == 1);
//////    assert(subsequence(seq2, seq2) == -1);
//////
//////    //test interleave()
//////    a.dump();
//////    empty.dump();
//////    Sequence i;
//////    interleave(a, empty, i);
//////    i.dump();
//////    interleave(a, a, i);
//////    i.dump();
//////    seq1.dump();
//////    interleave(seq1, a, i);
//////    interleave(a, seq1, i);
//////    i.dump();
//////    seq2 = seq1;
//////    Sequence k;
//////    interleave(seq1, seq2, seq2);
//////
//////    seq2.dump();
//////    m_new.dump();
//////    Sequence tst;
//////    interleave(k, m_new, tst);
//////    tst.dump();
//////
//////    interleave(k, m_new, i);
//////    i.dump();
//////
//////    Sequence ds1;
//////    ItemType test1[] = {30, 21, 63, 42, 17, 63};
//////    ItemType test2[] = {42, 63, 84, 19};
//////    for (int i = 0; i < 6; i++)
//////        ds1.insert(i, test1[i]);
//////    ds1.dump();
//////
//////    Sequence ds2;
//////    for (int i = 0; i < 4; i++)
//////        ds2.insert(i, test2[i]);
//////
//////
//////    ds1.dump();
//////    ds2.dump();
////////    interleave(ds1, ds2, tst);
////////    tst.dump();
//////    interleave(ds1, ds2, ds1);
//////    ds1.dump();
//////}
////
//////#include "Sequence.h"
//////    #include <type_traits>
//////
//////    #define CHECKTYPE(c, f, r, a)  \
//////        {  \
//////         static_assert(std::is_same<decltype(&c::f), r (c::*)a>::value, \
//////             "You did not declare " #c "::" #f " as the Project 2 spec does");  \
//////         auto p = static_cast<r (c::*)a>(&c::f);  \
//////         (void) p;  \
//////        }
//////    #define CHECKTYPENONMEMBER(f, r, a)  \
//////        {  \
//////         static_assert(std::is_same<decltype(&f), r (*)a>::value, \
//////             "You did not declare " #f " as the Project 2 spec does");  \
//////         auto p = static_cast<r (*)a>(f);  \
//////         (void) p;  \
//////        }
//////
//////    static_assert(std::is_default_constructible<Sequence>::value,
//////        "Sequence must be default-constructible.");
//////    static_assert(std::is_copy_constructible<Sequence>::value,
//////        "Sequence must be copy-constructible.");
//////    static_assert(std::is_copy_assignable<Sequence>::value,
//////        "Sequence must be assignable.");
//////
//////    void thisFunctionWillNeverBeCalled()
//////    {
//////        CHECKTYPE(Sequence, empty, bool, () const);
//////        CHECKTYPE(Sequence, size, int, () const);
//////        CHECKTYPE(Sequence, erase, bool, (int));
//////        CHECKTYPE(Sequence, remove, int, (const ItemType&));
//////        CHECKTYPE(Sequence, get, bool, (int, ItemType&) const);
//////        CHECKTYPE(Sequence, set, bool, (int, const ItemType&));
//////        CHECKTYPE(Sequence, find, int, (const ItemType&) const);
//////        CHECKTYPE(Sequence, swap, void, (Sequence&));
//////        CHECKTYPENONMEMBER(subsequence, int, (const Sequence&, const Sequence&));
//////        CHECKTYPENONMEMBER(interleave, void, (const Sequence&, const Sequence&, Sequence&));
//////        { auto p = static_cast<int (Sequence::*)(int, const ItemType&)>(&Sequence::insert); (void) p; }
//////        { auto p = static_cast<int (Sequence::*)(const ItemType&)>(&Sequence::insert); (void) p; }
//////    }
//////
//////    int main()
//////    {}
////
//////#include "Sequence.h"
//////#include <string>
//////#include <iostream>
//////#include <cassert>
//////using namespace std;
//////
//////void test()
//////{
//////    Sequence s;
//////    assert(s.insert(0, "lavash") == 0);
//////    assert(s.insert(0, "tortilla") == 0);
//////    assert(s.size() == 2);
//////    ItemType x = "injera";
//////    assert(s.get(0, x)  &&  x == "tortilla");
//////    assert(s.get(1, x)  &&  x == "lavash");
//////}
//////
//////int main()
//////{
//////    test();
//////    cout << "Passed all tests" << endl;
////////}
//////
//////#include "Sequence.h"
//////#include <iostream>
//////#include <cassert>
//////using namespace std;
//////
//////void test()
//////{
//////    Sequence s;
//////    assert(s.insert(0, 10) == 0);
//////    assert(s.insert(0, 20) == 0);
//////    assert(s.size() == 2);
//////    ItemType x = 999;
//////    assert(s.get(0, x)  &&  x == 20);
//////    assert(s.get(1, x)  &&  x == 10);
//////}
//////
//////int main()
//////{
//////    test();
//////    cout << "Passed all tests" << endl;
//////}
//
////
////#include "Sequence.h"
////
////#include <iostream>
////#include <cassert>
////using namespace std;
//
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
//////
//////    //test max capacity
//////    Sequence defaultSize;
//////    for (int i = 0; i < DEFAULT_MAX_ITEMS; i++)
//////        assert(defaultSize.insert("gobblick") == 0);
//////    assert(defaultSize.insert("gobbick") == -1);
//////
//////    Sequence customSize(1000);
//////    for (int i = 0; i < 1000; i++)
//////        assert(customSize.insert("test") == 0);
//////    assert(customSize.insert("test") == -1);
//////    assert(customSize.size() == 1000);
//////    assert(defaultSize.size() == 180);
//////
//////    customSize.swap(defaultSize);
//////    assert(customSize.size() == 180);
//////    assert(defaultSize.size() == 1000);
//////    assert(customSize.erase(0) == true);
//////    assert(customSize.insert("test") == 179);
//////    assert(customSize.insert("aaple") == -1);
//////    defaultSize.dump();
//////    assert(defaultSize.remove("test") == 1000);
//////    assert(defaultSize.size() == 0);
//////}
//////
//////    Sequence m_new;
//////    m_new.insert(100000);
//////    m_new.dump();
//////
//////    Sequence s;
//////    assert(s.empty());
//////    assert(s.find(42) == -1);
//////    assert(s.insert(42) == 0);
//////    assert(s.size() == 1  &&  s.find(42) == 0);
//////
//////    m_new = s;
//////    s.dump();
//////
//////    Sequence copied(s);
//////    copied.dump();
////    cerr << "Passed all tests" << endl;
////}
//
////#include "Sequence.h"
////#include <iostream>
////#include <cassert>
////
////using namespace std;
////
////int main()
////{
////    //Testing subsequence
////    Sequence t1;
////    assert(t1.insert(0, 30) == 0);
////    assert(t1.insert(1, 21) == 1);
////    assert(t1.insert(2, 63) == 2);
////    assert(t1.insert(3, 42) == 3);
////    assert(t1.insert(4, 17) == 4);
////    assert(t1.insert(5, 63) == 5);
////    assert(t1.insert(6, 17) == 6);
////    assert(t1.insert(7, 29) == 7);
////    assert(t1.insert(8, 8) == 8);
////    assert(t1.insert(9, 32) == 9);
////
////    Sequence t2;
////    assert(t2.insert(0, 63) == 0);
////    assert(t2.insert(1, 17) == 1);
////    assert(t2.insert(2, 29) == 2);
////
////    assert(subsequence(t1, t2) == 5);
////
////    Sequence empty;
////    Sequence oneEl;
////
////    assert(oneEl.insert(63) == 0);
////    assert(subsequence(t1, empty) == -1);
////    assert(subsequence(empty, t1) == -1);
////    assert(subsequence(t2, t1) == -1);
////    assert(oneEl.remove(63) == 1);
////    assert(oneEl.insert(1) == 0);
////    assert(subsequence(t2, oneEl) == -1);
////
////
////    //Testing the interleave
////    Sequence shorter;
////    shorter.insert(0, 42);
////    shorter.insert(1, 63);
////    shorter.insert(2, 84);
////    shorter.insert(3, 19);
////
////    Sequence longer;
////    longer.insert(0, 30);
////    longer.insert(1, 21);
////    longer.insert(2, 63);
////    longer.insert(3, 42);
////    longer.insert(4, 17);
////    longer.insert(5, 63);
////    longer.insert(6, 100);
////    longer.insert(7, 110);
////    longer.insert(8, 120);
////
////    Sequence random;
////
////    interleave(longer, shorter, random);
////    //random.dump();
////
////    longer.swap(shorter);
////    //longer.dump();
////    //shorter.dump();
////
////    Sequence empty1;
////    Sequence empty2;
////    Sequence random1;
////    interleave(empty1, empty2, random1);
////    //random1.dump();
////    assert(empty1.insert(1) == 0);
////    assert(empty1.insert(1) == 0);
////    assert(empty1.insert(1) == 0);
////    interleave(empty1, empty2, random1);
////    //random1.dump();
////    assert(empty1.remove(1) == 3);
////    empty2 = longer;
////    interleave(empty1, empty2, random1);
////    //random1.dump();
////
////    Sequence s1;
////    assert(s1.insert(2) == 0);
////    assert(s1.insert(2) == 0);
////    assert(s1.insert(2) == 0);
////    assert(s1.insert(3, 3) == 3);
////    assert(s1.insert(1, 10) == 1);
////    assert(s1.insert(1, 5) == 1);
////    assert(s1.insert(3, 4) == 3);
////    assert(s1.insert(1) == 0);
////    assert(s1.insert(3) == 2);
////    //s1.dump();
////    assert(s1.remove(1) == 1);
////    assert(s1.remove(2) == 3);
////    //s1.dump();
////    assert(s1.size() == 5);
////    assert(s1.empty() == false);
////
////    //Erase test sequence
////    Sequence s;
////    assert(s.insert(1) == 0);
////    assert(s.insert(2) == 1);
////    assert(s.insert(3) == 2);
////    //s.dump();
////    assert(s.erase(0) == true);
////    //s.dump();
////    assert(s.erase(1) == true);
////    //s.dump();
////    assert(s.erase(0) == true);
////    //s.dump();
////
////
////    Sequence s2;
////    assert(s2.insert(2) == 0);
////    assert(s2.insert(2) == 0);
////    assert(s2.insert(2) == 0);
////    assert(s2.erase(1) == true);
////    assert(s2.erase(0) == true);
////    assert(s2.erase(0) == true);
////
////    //Test cases for remove function
////    Sequence c;
////    assert(c.insert(0, 1) == 0);
////    assert(c.insert(1, 2) == 1);
////    assert(c.insert(2, 3) == 2);
////    assert(c.insert(3, 4) == 3);
////    assert(c.insert(4) == 3);
////    assert(c.find(0) == -1);
////    assert(c.find(1) == 0);
////    assert(c.find(2) == 1);
////    assert(c.find(3) == 2);
////    assert(c.find(4) == 3);
////
////    Sequence s3;
////    assert(s3.insert(0) == 0);
////    assert(s3.insert(1) == 1);
////    assert(s3.insert(2) == 2);
////    assert(s3.insert(2) == 2);
////    assert(s3.insert(3) == 4);
////    assert(s3.find(0) == 0);
////    assert(s3.find(1) == 1);
////    assert(s3.find(2) == 2);
////    assert(s3.find(3) == 4);
////
////    s3 = c;
////    assert(s3.find(0) == -1);
////    assert(s3.find(1) == 0);
////    assert(s3.find(2) == 1);
////    assert(s3.find(3) == 2);
////    assert(s3.find(4) == 3);
////
////    Sequence t(s3);
////    //t.dump();
////    assert(t.find(0) == -1);
////    assert(t.find(1) == 0);
////    assert(t.find(2) == 1);
////    assert(t.find(3) == 2);
////    assert(t.find(4) == 3);
////
////    //CONTINUE TESTING BELOW
////
////    Sequence s4;
////    assert(s4.insert(1) == 0);
////    assert(s4.insert(2) == 1);
////    assert(s4.insert(2) == 1);
////    assert(s4.insert(3) == 3);
////    assert(s4.size() == 4);
////    assert(s4.empty() == false);
////    assert(s4.find(2) == 1);
////
////    ////Random test cases for erase function in general
////    Sequence mySeq;
////    assert(mySeq.insert(1) == 0);
////    assert(mySeq.insert(2) == 1);
////    assert(mySeq.insert(3) == 2);
////    //mySeq.dump();
////    assert(mySeq.erase(0) == true);
////    //mySeq.dump();
////    assert(mySeq.erase(1) == true);
////    //mySeq.dump();
////    assert(mySeq.erase(1) == false);
////    //mySeq.dump();
////    assert(mySeq.erase(0) == true);
////    //mySeq.dump();
////    assert(mySeq.empty() == true);
////
////    ////Test case for empty sequence and for linked list with one node
////    Sequence s5;
////    assert(s5.erase(0) == false);
////    assert(s5.insert(5) == 0);
////    assert(s5.erase(1) == false); //Can't erase something w/ a bigger position than the size
////    assert(s5.erase(0) == true);
////    assert(s5.size() == 0);
////    assert(s5.empty() == true);
////
////    //Test case for removing last node
////    assert(s5.insert(1) == 0);
////    assert(s5.insert(2) == 1);
////    //s.dump();
////    assert(s5.erase(1) == true);
////    //s.dump();
////
////    ////Test case for removing middle element
////    assert(s5.erase(0) == true);
////    assert(s5.size() == 0);
////    assert(s5.insert(1) == 0);
////    assert(s5.insert(2) == 1);
////    assert(s5.insert(3) == 2);
////    assert(s5.erase(1) == true);
////    //s.dump();
////
////
////    Sequence n;
////    assert(n.empty() == true);
////    assert(n.insert(0, 3) == 0);
////    assert(n.size() == 1);
////    assert(n.empty() == false);
////    assert(n.insert(0, 2) == 0);
////    assert(n.size() == 2);
////    assert(n.insert(0, 1) == 0);
////    assert(n.size() == 3);
////    assert(n.insert(3, 4) == 3);
////    assert(n.size() == 4);
////    assert(n.insert(2, 200) == 2);
////    assert(n.size() == 5);
////    assert(n.insert(5, 200) == 5);
////    assert(n.size() == 6);
////    assert(n.insert(100, 1) == -1);
////
////
////    Sequence s6;
////    assert(s6.insert(2, 5) == -1);
////    assert(s6.insert(1, 5) == -1);
////    assert(s6.insert(0, 1) == 0);
////
////    s6 = n;
////    assert(s6.size() == 6);
////
////    Sequence emp;
////    n = emp;
////    assert(n.empty() == true);
////
////    Sequence q;
////    assert(q.size() == 0);
////
////    Sequence copyS(s6);
////    assert(copyS.size() == 6);
////
////    Sequence copyQ(q);
////    assert(copyQ.empty() == true);
////    assert(copyQ.size() == 0);
////
////    cout << "All test cases passed." << endl;
////}
//
//#include "Sequence.h"
//#include <iostream>
//#include <cassert>
//
//int main()
//{
//    const int maxFill = 20;
//
//    // Default constructor
//    {
//        Sequence test;
//        assert(test.empty() == true);
//        assert(test.size() == 0);
//    }
//    // Copy constructor
//    {
//        Sequence base;
//        for (int i = 0; i < maxFill; i++)
//            assert(base.insert(i) == i);
//        Sequence test = base;
//        for (int i = 0; i < maxFill; i++)
//            assert(test.find(i) == i);
//        base.erase(maxFill - 1);
//        test.erase(0);
//        for (int i = 0; i < maxFill - 1; i++)
//        {
//            assert(base.find(i) == i);
//            assert(test.find(i + 1) == i);
//        }
//    }
//    // Assignment operator
//    {
//        Sequence base, test;
//        // Create different Sequences
//        for (int i = 0; i < maxFill; i++)
//        {
//            assert(base.insert(i) == i);
//            assert(test.insert(i + maxFill) == i);
//        }
//        // Validate different Sequences
//        for (int i = 0; i < maxFill; i++)
//        {
//            assert(base.find(i) == i);
//            assert(test.find(i + maxFill) == i);
//        }
//        // Check if Sequences are the same after assignment
//        test = base;
//        for (int i = 0; i < maxFill; i++)
//        {
//            assert(base.find(i) == i);
//            assert(test.find(i) == i);
//        }
//        // Check if modifying one does not modify the other
//        base.erase(maxFill - 1);
//        test.erase(0);
//        for (int i = 0; i < maxFill - 1; i++)
//        {
//            assert(base.find(i) == i);
//            assert(test.find(i + 1) == i);
//        }
//
//        // Assign to empty
//        Sequence testFull, testEmpty;
//        for (int i = 0; i < maxFill; i++)
//            assert(testFull.insert(i) == i);
//        for (int i = 0; i < maxFill; i++)
//            assert(testFull.find(i) == i);
//        testFull = testEmpty;
//        for (int i = 0; i < maxFill; i++)
//        {
//            assert(testFull.find(i) == -1);
//            assert(testEmpty.find(i) == -1);
//        }
//
//        // Aliasing
//        Sequence testAlias;
//        for (int i = 0; i < maxFill; i++)
//            assert(testAlias.insert(i) == i);
//        for (int i = 0; i < maxFill; i++)
//            assert(testAlias.find(i) == i);
//        testAlias = testAlias;
//        for (int i = 0; i < maxFill; i++)
//            assert(testAlias.find(i) == i);
//    }
//    // empty(), size()
//    {
//        Sequence test;
//        assert(test.empty());
//        assert(test.size() == 0);
//        for (int i = 0; i < maxFill; i++)
//        {
//            assert(test.insert(i) == i);
//            assert(test.empty() == false);
//            assert(test.size() == i + 1);
//        }
//    }
//    // insert(pos, value)
//    {
//        Sequence test;
//        int mid = 0;
//        for (int i = 0; i < maxFill; i++)
//        {
//            assert(test.insert(mid, i) == mid);
//            assert(test.size() == i + 1);
//            mid = test.size() / 2;
//        }
//        for (int i = 0; i < mid; i++)
//        {
//            assert(test.find(2 * i + 1) == i);
//            assert(test.find(2 * i) == maxFill - 1 - i);
//        }
//    }
//    // insert(value)
//    {
//        Sequence test1, test2;
//        for (int i = 0; i < maxFill; i++)
//        {
//            assert(test1.insert(i) == i);
//            assert(test2.insert(maxFill - i - 1) == 0);
//            assert(test1.size() == i + 1);
//            assert(test2.size() == i + 1);
//        }
//        for (int i = 0; i < maxFill; i++)
//        {
//            assert(test1.find(i) == i);
//            assert(test2.find(i) == i);
//        }
//    }
//    // erase(pos)
//    {
//        Sequence test;
//
//        // Remove from end
//        for (int i = 0; i < maxFill; i++)
//            assert(test.insert(i) == i);
//        for (int i = 0; i < maxFill; i++)
//        {
//            assert(test.erase(test.size() - 1));
//            assert(test.size() == maxFill - 1 - i);
//            for (int j = 0; j < test.size(); j++)
//                assert(test.find(j) == j);
//        }
//
//        // Remove from front
//        for (int i = 0; i < maxFill; i++)
//            assert(test.insert(i) == i);
//        for (int i = 0; i < maxFill; i++)
//        {
//            assert(test.erase(0));
//            assert(test.size() == maxFill - 1 - i);
//            for (int j = 0; j < test.size(); j++)
//                assert(test.find(j + i + 1) == j);
//        }
//    }
//    // remove(value)
//    {
//        Sequence test;
//        ItemType arr[] = { 0, 7, 1, 7, 2, 7, 3, 7, 4, 7 };
//        for (int i = 0; i < 10; i++)
//            assert(test.insert(i, arr[i]) == i);
//        assert(test.remove(7) == 5);
//        for (int i = 0; i < 5; i++)
//            assert(test.find(i) == i);
//        assert(test.remove(7) == 0);
//    }
//    // get(pos, value)
//    {
//        Sequence test;
//        ItemType IT;
//        for (int i = 0; i < maxFill; i++)
//            assert(test.insert(i) == i);
//        for (int i = 0; i < maxFill; i++)
//        {
//            assert(test.get(i, IT));
//            assert(IT == i);
//        }
//        assert(test.get(-1, IT) == false);
//        assert(test.get(test.size(), IT) == false);
//    }
//    // set(pos, value)
//    {
//        Sequence test;
//        for (int i = 0; i < maxFill; i++)
//            assert(test.insert(i) == i);
//        for (int i = 0; i < maxFill; i++)
//            assert(test.find(i) == i);
//        for (int i = 0; i < maxFill; i++)
//            assert(test.set(i, i + maxFill));
//        assert(test.set(-1, 1) == false);
//        assert(test.set(test.size(), 1) == false);
//        for (int i = 0; i < maxFill; i++)
//            assert(test.find(i + maxFill) == i);
//    }
//    // swap(Seq1, Seq2)
//    {
//        Sequence test1, test2;
//        for (int i = 0; i < maxFill; i++)
//            assert(test1.insert(i) == i);
//        for (int i = 0; i < 2 * maxFill; i++)
//            assert(test2.insert(i + maxFill) == i);
//        assert(test1.size() == maxFill);
//        assert(test2.size() == maxFill * 2);
//
//        for (int i = 0; i < maxFill; i++)
//            assert(test1.find(i) == i);
//        for (int i = 0; i < 2 * maxFill; i++)
//            assert(test2.find(i + maxFill) == i);
//
//        test1.swap(test2);
//        assert(test1.size() == maxFill * 2);
//        assert(test2.size() == maxFill);
//        for (int i = 0; i < maxFill; i++)
//            assert(test2.find(i) == i);
//        for (int i = 0; i < 2 * maxFill; i++)
//            assert(test1.find(i + maxFill) == i);
//
//        // Empty swap
//        Sequence testFull, testEmpty;
//        for (int i = 0; i < maxFill; i++)
//            assert(testFull.insert(i) == i);
//        for (int i = 0; i < maxFill; i++)
//            assert(testFull.find(i) == i);
//        assert(testFull.size() == maxFill);
//        assert(testEmpty.empty());
//
//        testFull.swap(testEmpty);
//        assert(testFull.empty());
//        assert(testEmpty.size() == maxFill);
//        for (int i = 0; i < maxFill; i++)
//        {
//            assert(testFull.find(i) == -1);
//            assert(testEmpty.find(i) == i);
//        }
//
//        // Aliasing
//        Sequence testAlias;
//        for (int i = 0; i < maxFill; i++)
//            assert(testAlias.insert(i) == i);
//        testAlias.swap(testAlias);
//        for (int i = 0; i < maxFill; i++)
//            assert(testAlias.find(i) == i);
//    }
//    // subsequence
//    {
//        Sequence t01, t02;
//        ItemType t01a[] = { 1, 2, 2, 3, 2, 3, 4, 5 };
//        ItemType t02a[] = { 2, 3, 4, 5 };
//        for (int i = 0; i < 8; i++)
//            t01.insert(i, t01a[i]);
//        for (int i = 0; i < 4; i++)
//            t02.insert(i, t02a[i]);
//        assert(subsequence(t01, t02) == 4);
//
//        Sequence t11, t12;
//        ItemType t11a[] = { 1, 2, 2, 3, 2, 3, 4, 5 };
//        ItemType t12a[] = { 2, 3, 4 };
//        for (int i = 0; i < 8; i++)
//            t11.insert(i, t11a[i]);
//        for (int i = 0; i < 3; i++)
//            t12.insert(i, t12a[i]);
//        assert(subsequence(t11, t12) == 4);
//
//        Sequence t21, t22;
//        ItemType t21a[] = { 1, 2, 2, 3, 5 };
//        ItemType t22a[] = { 2, 3, 4, 5 };
//        for (int i = 0; i < 5; i++)
//            t21.insert(i, t21a[i]);
//        for (int i = 0; i < 4; i++)
//            t22.insert(i, t22a[i]);
//        assert(subsequence(t21, t22) == -1);
//
//        Sequence t31, t32;
//        ItemType t31a[] = { 1, 2, 2, 3, 5 };
//        for (int i = 0; i < 5; i++)
//            t31.insert(i, t31a[i]);
//        assert(subsequence(t31, t32) == -1);
//
//        Sequence t41, t42;
//        ItemType t42a[] = { 2, 3, 4, 5 };
//        for (int i = 0; i < 4; i++)
//            t42.insert(i, t42a[i]);
//        assert(subsequence(t41, t42) == -1);
//    }
//    // interleave
//    {
//        Sequence t01, t02, t03;
//        for (int i = 0; i < 5; i++)
//        {
//            t01.insert(2 * i);
//            t02.insert(2 * i + 1);
//            t03.insert(-1);
//        }
//        interleave(t01, t02, t03);
//        assert(t03.size() == 10);
//        for (int i = 0; i < 10; i++)
//            assert(t03.find(i) == i);
//
//        Sequence t11, t12, t13;
//        ItemType t11a[] = { 1, 2, 3, 4, 5 };
//        ItemType t12a[] = { 6, 7, 8 };
//        ItemType t13a[] = { 1, 6, 2, 7, 3, 8, 4, 5 };
//        for (ItemType elem : t11a)
//            t11.insert(elem);
//        for (ItemType elem : t12a)
//            t12.insert(elem);
//        interleave(t11, t12, t13);
//        assert(t13.size() == 8);
//        int i1 = 0;
//        for (ItemType elem : t13a)
//        {
//            ItemType temp;
//            t13.get(i1, temp);
//            assert(temp == elem);
//            i1++;
//        }
//
//        Sequence t21, t22, t23;
//        ItemType t21a[] = { 6, 7, 8 };
//        ItemType t22a[] = { 1, 2, 3, 4, 5 };
//        ItemType t23a[] = { 6, 1, 7, 2, 8, 3, 4, 5 };
//        for (ItemType elem : t21a)
//            t21.insert(elem);
//        for (ItemType elem : t22a)
//            t22.insert(elem);
//        interleave(t21, t22, t23);
//        assert(t23.size() == 8);
//        int i2 = 0;
//        for (ItemType elem : t23a)
//        {
//            ItemType temp;
//            t23.get(i2, temp);
//            assert(temp == elem);
//            i2++;
//        }
//
//        Sequence t31, t32, t33;
//        ItemType t31a[] = { 1, 2, 3, 4, 5 };
//        for (ItemType elem : t31a)
//            t31.insert(elem);
//        interleave(t31, t32, t33);
//        assert(t33.size() == 5);
//        int i3 = 0;
//        for (ItemType elem : t31a)
//        {
//            ItemType temp;
//            t33.get(i3, temp);
//            assert(temp == elem);
//            i3++;
//        }
//
//        Sequence t41, t42, t43;
//        ItemType t42a[] = { 1, 2, 3, 4, 5 };
//        for (ItemType elem : t42a)
//            t42.insert(elem);
//        interleave(t41, t42, t43);
//        assert(t33.size() == 5);
//        int i4 = 0;
//        for (ItemType elem : t42a)
//        {
//            ItemType temp;
//            t43.get(i4, temp);
//            assert(temp == elem);
//            i4++;
//        }
//
//        Sequence t51, t52, t53;
//        interleave(t51, t52, t53);
//        assert(t53.size() == 0);
//    }
//    std::cout << "           ',\n        .-`-,\\__\n          .\"`   `,\n        .'_.  ._  `;.\n    __ / `      `  `.\\ .--.\n   /--,| 0)   0)     )`_.-,)\n  |    ;.-----.__ _-');   /\n   '--./         `.`/  `\"`\n      :   '`      |.\n      | \     /  //\n       \\ '---'  /'\n        `------' \\\n         _/       `--..." << std::endl;
//}


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
        assert(s.insert(SPEC_MAX, DUMMY) == 180);
            } break; case 80: {
        for (size_t k = 0; k < SPEC_MAX-1; k++)
        assert(s.insert(k, ARRAY[0]) == k);
        assert(s.insert(ARRAY[1]) == SPEC_MAX-1);
            } break; case 81: {
        for (size_t k = 0; k < SPEC_MAX-1; k++)
        assert(s.insert(k, ARRAY[0]) == k);
        assert(s.insert(ARRAY[2]) == SPEC_MAX-1);
        assert(s.insert(ARRAY[1]) == SPEC_MAX-1);
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
    for (int i = 1; i < 82; i++)
        testone(i);
    cout << "Passed" << endl;
}
