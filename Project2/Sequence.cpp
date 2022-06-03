#include "Sequence.h"
#include <iostream>

Sequence::Sequence()
    : m_head(nullptr), m_size(0){}

Sequence::Sequence(const Sequence& other)
    : m_head(nullptr), m_size(0)
{
    Sequence::Node* p = other.m_head;
    
    if (p == nullptr)
        return;
    
    for (int i = 0; i < other.size() && p != nullptr; i++, p = p->next)
        insert(i, p->val);
}

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
    while(erase(0)){}
}

int Sequence::insert(int pos, const ItemType& value)
{
    if (pos < 0 || pos > m_size)
        return -1;
    uncheckedInsert(pos, value);
    return pos;
}

int Sequence::insert(const ItemType& value)
{
    int pos;
    Sequence::Node* p = m_head;
    for (pos = 0; pos < size() && value > p->val; pos++, p = p->next);
    uncheckedInsert(pos, value);
    return pos;
}

bool Sequence::erase(int pos)
{
    if (pos < 0  ||  pos >= size())
        return false;
    uncheckedDelete(pos);
    return true;
}

int Sequence::remove(const ItemType& value)
{
    int count = 0;
    while(find(value) != -1)
    {
        erase(find(value));
        count++;
    }
    return count;
}

bool Sequence::get(int pos, ItemType& value) const
{
    if (pos < 0  ||  pos >= size() || m_head == nullptr)
        return false;
    Sequence::Node* p = m_head;
    for (int i = 0; i < pos; i++, p = p->next);
    value = p->val;
    return true;
}

bool Sequence::set(int pos, const ItemType& value)
{
    if (pos < 0  ||  pos >= size() || m_head == nullptr)
        return false;
    Sequence::Node* p = m_head;
    for (int i = 0; i < pos; i++, p = p->next);
    p->val = value;
    return true;
}

int Sequence::find(const ItemType& value) const
{
    Sequence::Node* p = m_head;
    for (int pos = 0; pos < size() && p != nullptr; pos++, p = p->next)
        if (p->val == value)
            return pos;
    return -1;
}

void Sequence::swap(Sequence& other)
{
      // Swap linked lists
    Sequence::Node* tmpHead = other.m_head;
    other.m_head = m_head;
    m_head = tmpHead;
      // Swap sizes
    int tempSize = m_size;
    m_size = other.m_size;
    other.m_size = tempSize;
}

void Sequence::dump() const
{
    std::cerr << "Sequence information: " << std::endl
    << "size: " << size() << std::endl;
    
    if (m_head == nullptr)
        return;
    
    Sequence::Node* p = m_head;
    int i = 0;
    while (p != nullptr)
    {
        std::cerr << i << "th index of Sequence: " << p->val << std::endl;
        p = p->next;
        i++;
    }
    std::cerr << "----------------------------------" << std::endl;
}

void Sequence::uncheckedInsert(int pos, const ItemType& value)
{
    Sequence::Node* p = m_head;
    if (p == nullptr)
        m_head = new Sequence::Node(value);
    
    else if (pos == 0)
    {
        Sequence::Node* n = new Sequence::Node(value);
        n->next = m_head;
        n->next->prev = n;
        m_head = n;
    }
    
    else if (pos == size())
    {
        while (p->next != nullptr)
            p = p->next;
        Sequence::Node* n = new Sequence::Node(value);
        n->val = value;
        n->prev = p;
        n->prev->next = n;
    }
    
    else
    {
        //insert a new node into the corresponding position
        for (int i = 0; i < pos; i++)
            p = p->next;
        
        Sequence::Node* n = new Sequence::Node(value);
        n->prev = p->prev;
        n->next = p;
        n->prev->next = n;
        n->next->prev = n;
    }
    m_size++;
}

void Sequence::uncheckedDelete(int pos)
{
    Sequence::Node* p = m_head;
    //case 1: list of single item
    if (size() == 1)
    {
        delete p;  //FIXME: somewhere in the code we did not use new to initialize this pointer.
        m_head = nullptr;
    }
        
    //case 2: deleting the first node
    else if (pos == 0)
    {
        m_head = p->next;
        p->next->prev = nullptr;
        delete p;
    }
    
    //case 3: deleting at the back
    else if (pos == size() - 1)
    {
        while(p->next != nullptr)
            p = p->next;
        p->prev->next = nullptr;
        delete p;
    }
    
    //case 4: delete in the middle
    else
    {
        for (int i = 0; i < pos && p != nullptr; i++, p = p->next);
        p->prev->next = p->next;
        p->next->prev = p->prev;
        delete p;
    }
    m_size--;
}

int subsequence(const Sequence& seq1, const Sequence& seq2)
{
    if (seq1.empty() || seq2.empty())
        return -1;
    else if (seq1.size() < seq2.size())
        return -1;
    
    ItemType val2;
    seq2.get(0, val2);
    int firstMatch = seq1.find(val2);
    if (firstMatch == -1)
        return -1;
    
    ItemType val1;
    for (int j = 0; j < seq2.size(); j++)
    {
        if (!seq1.get(firstMatch + j, val1))    return -1;
        seq2.get(j, val2);
        if (val1 != val2)
        {
            j = -1;
            firstMatch++;
        }
    }
    return firstMatch;
}

void interleave(const Sequence& seq1, const Sequence& seq2, Sequence& result)
{
    //clear result
    Sequence tempResult;
    
    int seq1_size = seq1.size();
    int seq2_size = seq2.size();
    
    int commonMax = (seq1_size >= seq2_size) ? seq2_size : seq1_size;
    
    ItemType val1;
    ItemType val2;
    
    int resultIndex = -1;
    for (int i = 0; i < commonMax; i++)
    {
        seq1.get(i, val1);
        tempResult.insert(++resultIndex, val1);
        seq2.get(i, val2);
        tempResult.insert(++resultIndex, val2);
    }
    
    if (seq1_size > seq2_size)
    {
        for (int i = commonMax; i < seq1_size; i++)
        {
            seq1.get(i, val1);
            tempResult.insert(++resultIndex, val1);
        }
    }
    
    else if (seq1_size < seq2_size)
    {
        for (int i = commonMax; i < seq2_size; i++)
        {
            seq2.get(i, val2);
            tempResult.insert(++resultIndex, val2);
        }
    }
    
    result = tempResult;
}
