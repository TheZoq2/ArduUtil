
namespace atd
{
    template<class ValueType>
    class UniquePtr
    {
    public:
        //Create a new unique_ptr pointing to 'value'
        UniquePtr (ValueType* value);
        //Destroy the memory
        virtual ~UniquePtr ();

        //Return the current pointer
        ValueType* get();
        
        //Give value a new 
        void set(ValueType* value);
    private:
        ValueType* value = nullptr;
    };

    template<class ValueType>
    UniquePtr<ValueType>::UniquePtr(ValueType* value)
    {
        this->value = value;
    }

    template<class ValueType>
    UniquePtr<ValueType>::~UniquePtr()
    {
        
    }

    template<class ValueType>
    ValueType* UniquePtr<ValueType>::get()
    {
        return value;
    }

    template<class T>
    void UniquePtr<T>::set(T* newValue)
    {
        delete value;

        value = newValue
    }
}
