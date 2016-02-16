#ifndef H_UNIQUE_PTR
#define H_UNIQUE_PTR

#include <utility>
#include <iostream>

namespace atd
{
    template<class ValueType>
    class UniquePtr
    {
    public:
        //Create a new unique_ptr pointing to 'value'
        UniquePtr(ValueType* value);
        UniquePtr(UniquePtr&& value);

        //Destroy the memory
        virtual ~UniquePtr ();

        //Return the current pointer
        ValueType* get();
        
        //Give value a new 
        void set(ValueType* value);

        ValueType* operator->();
        ValueType operator*();
        UniquePtr& operator=(const UniquePtr& other) = delete;
        UniquePtr& operator=(const UniquePtr&& other);
    private:
        ValueType* value = nullptr;
    };

    template<class ValueType>
    UniquePtr<ValueType>::UniquePtr(ValueType* value)
    {
        this->value = value;
    }

    template<class ValueType>
    UniquePtr<ValueType>::UniquePtr(UniquePtr&&  other)
    {
        this->value = other.value;
    }

    template<class ValueType>
    UniquePtr<ValueType>::~UniquePtr()
    {
        std::cout << "Running destructor for value " << *value << std::endl;
        if(value != nullptr)
        {
            delete value;
        }
    }

    template<class ValueType>
    ValueType* UniquePtr<ValueType>::get()
    {
        return value;
    }

    template<class T>
    void UniquePtr<T>::set(T* newValue)
    {
        delete this->value;

        this->value = newValue;
    }

    template<class ValueType>
    ValueType* UniquePtr<ValueType>::operator->()
    {
        return this->value;
    }
    template<class ValueType>
    ValueType UniquePtr<ValueType>::operator*()
    {
        return *get();
    }

    template<class ValueType>
    UniquePtr<ValueType>& UniquePtr<ValueType>::operator=(const UniquePtr<ValueType>&& other)
    {
        this->value = std::move(other.value);

        //return *this;
    }

}
#endif
