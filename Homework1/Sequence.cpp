//#include <iostream>
//#include "Sequence.h"
//
//// the items in a sequence are contained in a data member that is an array.
//Sequence::Sequence()
//    : m_size(0)
//{
//}
//
//bool Sequence::empty() const
//{
//    return (size() == 0);
//}
//
//int Sequence::size() const
//{
//    return m_size;
//}
//
//int Sequence::insert(int pos, const ItemType& value)
//{
//    if (size() >= DEFAULT_MAX_ITEMS)
//        return -1;
//    else if (pos < 0 || pos > size())
//        return -1;
//    else
//    {
//        for (int i = size(); i > pos; i--)
//            //shift everything over to the right
//            m_items[i] = m_items[i - 1];
//        m_items[pos] = value;
//        m_size++;
//        return pos;
//    }
//}
//
//int Sequence::insert(const ItemType& value)
//{
//    //find the index to insert at
//    for (int i = 0; i < size(); i++)
//    {
//        if (value <= m_items[i])
//            return insert(i, value);
//    }
//    return insert(size(), value);
//}
//
//bool Sequence::erase(int pos)
//{
//    if (pos < 0 || pos >= size())
//        return false;
//    else
//    {
//        m_size--;
//        for (int i = pos; i < size(); i++)
//            m_items[i] = m_items[i + 1];
//        return true;
//    }
//}
//
//int Sequence::remove(const ItemType& value)
//{
//    int counter = 0;
//    for (int i = 0; i < size(); i++)
//    {
//        if (m_items[i] == value)
//        {
//            erase(i);
//            i--;
//            counter++;
//        }
//    }
//    return counter;
//}
//
//bool Sequence::get(int pos, ItemType& value) const
//{
//    // If 0 <= pos < size(), copy into value the item at position pos
//    // of the sequence and return true.  Otherwise, leave value unchanged
//    // and return false.
//    if (pos < 0 || pos >= size())
//        return false;
//    value = m_items[pos];
//    return true;
//}
//
//bool Sequence::set(int pos, const ItemType& value)
//{
//    // If 0 <= pos < size(), replace the item at position pos in the
//    // sequence with value and return true.  Otherwise, leave the sequence
//    // unchanged and return false.
//    if (pos < 0 || pos >= size())
//        return false;
//    m_items[pos] = value;
//    return true;
//}
//
//int Sequence::find(const ItemType& value) const
//{
//    // Let p be the smallest integer such that value == the item at
//    // position p in the sequence; if no such item exists, let p be -1.
//    // Return p.
//    for (int i = 0; i < size(); i++)
//    {
//        if (m_items[i] == value)
//            return i;
//    }
//    return -1;
//}
//
//void Sequence::swap(Sequence& other)
//{
//    /*
//    // Exchange the contents of this sequence with the other one.
//    //create a temporary Sequence object with m_size and m_items[]
//    
//    Sequence tmp;
//    for (int i = 0; i < size(); i++)
//        tmp.insert(i, m_items[i]);
//    
//    //replace this Sequence with the other sequence
//    m_size = other.size();
//    for (int i = 0; i < other.size(); i++)
//        m_items[i] = other.m_items[i];
//    
//    other.m_size = tmp.size();
//    for (int i = 0; i < tmp.size(); i++)
//        other.set(i, tmp.m_items[i]);
//     */
//    
//    //much easier version:
//    Sequence tmp(*this);
//    *this = other;
//    other = tmp;
//}
//
//void Sequence::dump() const
//{
//    std::cerr << "Sequence information: " << std::endl
//    << "size: " << size() << std::endl;
//    
//    for (int i = 0; i < size(); i++)
//        std::cerr << i << "th index of Sequence: " << m_items[i] << std::endl;
//    std::cerr << "----------------------------------" << std::endl;
//}
