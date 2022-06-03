#include <iostream>
#include <algorithm>
#include "newSequence.h"

// the items in a sequence are contained in a data member that is an array.
Sequence::Sequence(int capacity)
{
    if (capacity < 0)
    {
        std::cout << "Capacity should be greater or equal to 0." << std::endl;
        std::exit(-1);
    }
    m_capacity = capacity;
    m_size = 0;
    m_items = new ItemType[capacity];
}

Sequence::Sequence(const Sequence& other)
{
    m_capacity = other.m_capacity;
    m_size = other.m_size;
    m_items = new ItemType[m_capacity];
    for (int i = 0; i < m_size; i++)
        m_items[i] = other.m_items[i];  //Why does assigning by address work but using * doesn't work?
}

//review the modern way of writing the assignment operator
Sequence& Sequence::operator=(const Sequence& other)
{
    if (this != &other)
    {
        Sequence temp(other);
        swap(temp);
    }
    return *this;
}

Sequence::~Sequence()
{
    m_capacity = 0;
    m_size = 0;
    delete [] m_items;
}

bool Sequence::empty() const
{
    return (size() == 0);
}

int Sequence::size() const
{
    return m_size;
}

int Sequence::insert(int pos, const ItemType& value)
{
    if (size() >= m_capacity)
        return -1;
    else if (pos < 0 || pos > size())
        return -1;
    else
    {
        //I already allocated an array of size m_capacity, no need to allocate memory for the new index.
        for (int i = size(); i > pos; i--)
            //shift everything over to the right
            m_items[i] = m_items[i - 1];
        m_items[pos] = value;
        m_size++;
        return pos;
    }
}

int Sequence::insert(const ItemType& value)
{
    //find the index to insert
    for (int i = 0; i < size(); i++)
    {
        if (value <= m_items[i])
            return insert(i, value);
    }
    return insert(size(), value);
}

//FIXME: why doesn't the erase function have to delete the content at the associated index?
bool Sequence::erase(int pos)
{
    if (pos < 0 || pos >= size())
        return false;
    else
    {
        m_size--;
//        delete &m_items[pos];
        for (int i = pos; i < size(); i++)
            m_items[i] = m_items[i + 1];
        return true;
    }
}

int Sequence::remove(const ItemType& value)
{
    int counter = 0;
    for (int i = 0; i < size(); i++)
    {
        if (m_items[i] == value)
        {
            erase(i);
            i--;
            counter++;
        }
    }
    return counter;
}

bool Sequence::get(int pos, ItemType& value) const
{
    // If 0 <= pos < size(), copy into value the item at position pos
    // of the sequence and return true.  Otherwise, leave value unchanged
    // and return false.
    if (pos < 0 || pos >= size())
        return false;
    value = m_items[pos];
    return true;
}

bool Sequence::set(int pos, const ItemType& value)
{
    // If 0 <= pos < size(), replace the item at position pos in the
    // sequence with value and return true.  Otherwise, leave the sequence
    // unchanged and return false.
    if (pos < 0 || pos >= size())
        return false;
    m_items[pos] = value;
    return true;
}

int Sequence::find(const ItemType& value) const
{
    // Let p be the smallest integer such that value == the item at
    // position p in the sequence; if no such item exists, let p be -1.
    // Return p.
    for (int i = 0; i < size(); i++)
    {
        if (m_items[i] == value)
            return i;
    }
    return -1;
}

void Sequence::swap(Sequence& other)
{
    /*
    // Exchange the contents of this sequence with the other one.
    //create a temporary Sequence object with m_size and m_items[]
    
    Sequence tmp;
    for (int i = 0; i < size(); i++)
        tmp.insert(i, m_items[i]);
    
    //replace this Sequence with the other sequence
    m_size = other.size();
    for (int i = 0; i < other.size(); i++)
        m_items[i] = other.m_items[i];
    
    other.m_size = tmp.size();
    for (int i = 0; i < tmp.size(); i++)
        other.set(i, tmp.m_items[i]);
     */
    std::swap(m_capacity, other.m_capacity);
    std::swap(m_size, other.m_size);
    std::swap(m_items, other.m_items);  //why does swapping it like this work but not when we swap it by address using & operator?
}

void Sequence::dump() const
{
    std::cerr << "Sequence information: " << std::endl
    << "size: " << size() << std::endl;
    
    for (int i = 0; i < size(); i++)
        std::cerr << i << "th index of Sequence: " << m_items[i] << std::endl;
    std::cerr << "----------------------------------" << std::endl;
}

