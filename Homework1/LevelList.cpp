//#include "LevelList.h"
//
//LevelList::LevelList()
//{
//    
//}
//
//bool LevelList::add(ItemType level)
//{
//    if (level < 30 || level > 400)
//        return false;
//    return (m_level_list.insert(level) != -1);
//}
//
//bool LevelList::remove(ItemType level)
//{
//    int targetIndex = m_level_list.find(level);
//    if (targetIndex == -1)
//        return false;
//    else
//        return m_level_list.erase(targetIndex);
//    return false;
//}
//
//
//int LevelList::size() const
//{
//    return m_level_list.size();
//}
//
//ItemType LevelList::minimum() const
//{
//    ItemType result;
//    if (!m_level_list.get(0, result))
//        return NO_LEVEL;
//    return result;
//}
//
//
//ItemType LevelList::maximum() const
//{
//    ItemType result;
//    if (!m_level_list.get(m_level_list.size() - 1, result))
//        return NO_LEVEL;
//    return result;
//}
//
//
