#ifndef H_QUEUE
#define H_QUEUE

#include <stdint.h>


template<class T>
class BoundedQueue
{
public:
    typedef uint32_t size_t;

    BoundedQueue(size_t maxSize)
    {
        this->maxSize = maxSize;
        this->size = 0;
        data = new T[maxSize];
    }
    ~BoundedQueue()
    {
        delete[] data;
    }
    BoundedQueue(const BoundedQueue& other) = delete;

    void clear()
    {
        delete[] data;
        data = new T[maxSize];

        begin = 0;
        size = 0;
    }

    //Add an element to the end of the queue. If the queue is full, anything might happen
    void enqueue(T value)
    {
        data[(begin + size) % maxSize] = value;
        size++;
    }

    //Pop the element on top of the queue and return it. If the queue is empty, the possibilities are endless
    T& dequeue()
    {
        T& result = data[begin];
        size--;
        begin = (begin + 1) % maxSize;
        return result;
    }

    T& peek(size_t index)
    {
        return data[(begin + index) % maxSize];
    }

    T& back()
    {
        return peek(size - 1);
    }

    size_t getSize() const
    {
        return size;
    }
private:
    T* data;

    size_t maxSize;
    size_t size;

    size_t begin = 0;
};
#endif
