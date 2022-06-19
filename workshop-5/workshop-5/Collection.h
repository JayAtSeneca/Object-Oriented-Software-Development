#ifndef SDDS_COLLECTION_H
#define SDDS_COLLECTION_H
#include <iostream>
#include <string>
namespace sdds
{
    template <typename T>
    class Collection
    {
        std::string m_name{};
        T* m_arr{};
        size_t m_size{};
        void (*ptrObserver)(const Collection<T>&, const T&) = nullptr;

    public:
        Collection<T>(const std::string& name);
        virtual ~Collection<T>();
        const std::string& name() const;
        size_t size() const;
        void setObserver(void (*observer)(const Collection<T>&, const T&));
        Collection<T>& operator+=(const T& item);
        T& operator[](size_t idx) const;
        T* operator[](const std::string& title) const;

        // delete all the copy operations
        Collection<T>& operator=(const Collection<T>&) = delete;
        Collection<T>& operator=(Collection<T>&&) = delete;
        Collection<T>(const Collection<T>&) = delete;
        Collection<T>(Collection<T>&&) = delete;

        // friend helper function
        template <typename T>
        friend std::ostream& operator<<(std::ostream& os, const Collection<T>& coll);
    };

    template <typename T>
    Collection<T>::Collection(const std::string& name)
    {
        m_name = name;
        m_arr = nullptr;
        m_size = 0u;
    }

    template <typename T>
    Collection<T>::~Collection()
    {
        delete[] m_arr;
    }

    template <typename T>
    const std::string& Collection<T>::name() const
    {
        return m_name;
    }

    template <typename T>
    size_t Collection<T>::size() const
    {
        return m_size;
    }
    template <typename T>
    void Collection<T>::setObserver(void (*observer)(const Collection<T>&, const T&))
    {
        ptrObserver = observer;
    }
    template <typename T>
    Collection<T>& Collection<T>::operator+=(const T& item)
    {
        bool itemExist = false;
        for (size_t i = 0; i < m_size && itemExist != true; i++)
        {
            if (m_arr[i].title() == item.title())
            {
                itemExist = true;
            }
        }
        if (itemExist == false)
        {
            T* temp = new T[m_size + 1];
            for (size_t i = 0; i < m_size; i++)
            {
                temp[i] = m_arr[i];
            }
            temp[m_size] = item;
            delete[] m_arr;
            m_arr = temp;
            m_size++;
            if (ptrObserver != nullptr)
            {
                ptrObserver(*this, item);
            }
        }
        return *this;
    }
    template <typename T>
    T& Collection<T>::operator[](size_t idx) const
    {
        if (idx > (m_size - 1))
        {
            std::string message = "Bad index [" + std::to_string(idx) + "]." + " Collection has [" + std::to_string(m_size) + "] items.";
            throw std::out_of_range(message);
        }
        else
        {
            return m_arr[idx];
        }
    }

    template <typename T>
    T* Collection<T>::operator[](const std::string& title) const
    {
        size_t i = 0u;
        for (; i < m_size; i++)
        {
            if (m_arr[i].title() == title)
            {
                return &m_arr[i];
            }
        }
        if (i == m_size)
            return nullptr;
    }
    template <typename T>
    std::ostream& operator<<(std::ostream& os, const Collection<T>& coll)
    {
        for (size_t i = 0u; i < coll.size(); i++)
        {
            os << coll[i];
        }
        return os;
    }
}

#endif // !SDDS_COLLECTION_H
