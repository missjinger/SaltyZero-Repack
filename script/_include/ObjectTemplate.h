/*
 * Copyright (C) 2016+     AzerothCore <www.azerothcore.org>, released under GNU GPL v2 license: https://github.com/azerothcore/azerothcore-wotlk/blob/master/LICENSE-GPL2
 * Copyright (C) 2008-2016 TrinityCore <http://www.trinitycore.org/>
 * Copyright (C) 2005-2009 MaNGOS <http://getmangos.com/>
 */

#ifndef _OBJECTTPL_H
#define _OBJECTTPL_H

template<class T>
class ObjectTemplate
{
private:
    ObjectTemplate() {};
    static T* m_instance = nullptr;
public:
    static T* GetInstance();
};

template<class T> T* ObjectTemplate<T>::GetInstance()
{
    return m_instance == nullptr ? m_instance = new T() : m_instance;
}

class LoadMgr
{
public:
    // custom data interface
    /// 自定义数据接口
    template<class T, class M> T const* GetStoredData(int64 Key)
    {
        M* m = ObjectTemplate<M>::GetInstance();

        ASSERT(m != nullptr);

        M::const_iterator itr = m->find(Key);

        if (itr != m->end())
        {
            return &itr->second;
        }

        return nullptr;
    }

    template<class M> auto GetStoredData(int64 Key)
    {
        M* m = ObjectTemplate<M>::GetInstance();

        ASSERT(m != nullptr);

        return (m->equal_range(Key));
    }
};
#endif
