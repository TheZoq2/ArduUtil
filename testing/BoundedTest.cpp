#include "catch.hpp"
#include "../BoundedQueue.h"

#include  <iostream>
#include <queue>
#include <deque>
#include <stdlib.h>

TEST_CASE("Bounded queue sizes")
{
    BoundedQueue<int> queue(5);

    //Ensure that the new queue is empty
    REQUIRE(queue.getSize() == 0);

    queue.enqueue(1);
    queue.enqueue(3);
    queue.enqueue(-1);
    queue.enqueue(2);
    queue.enqueue(10);

    REQUIRE(queue.getSize() == 5);

    REQUIRE(queue.back() == 10);

    REQUIRE(queue.peek(0) == 1);
    REQUIRE(queue.peek(1) == 3);
    REQUIRE(queue.peek(2) == -1);
    REQUIRE(queue.peek(3) == 2);
    REQUIRE(queue.peek(4) == 10);

    //Dequeue a few elements
    REQUIRE(queue.dequeue() == 1);
    REQUIRE(queue.dequeue() == 3);

    REQUIRE(queue.getSize() == 3);

    //Enqueue 2 new elements to make sure that works
    queue.enqueue(2);
    queue.enqueue(4);

    REQUIRE(queue.dequeue() == -1);
    REQUIRE(queue.dequeue() == 2);
    REQUIRE(queue.dequeue() == 10);
    REQUIRE(queue.dequeue() == 2);
    REQUIRE(queue.dequeue() == 4);

    //Ensure that the size of the queue is 0 now
    REQUIRE(queue.getSize() == 0);
}


TEST_CASE("Randomized parameters")
{
    srand(time(NULL));

    std::size_t size = 500;
    int testAmount = 10;

    BoundedQueue<int> bQueue(size);
    std::deque<int> refQueue;

    for(int n = 0; n < testAmount; n++)
    {
        bQueue.clear();
        refQueue.clear();

        REQUIRE(bQueue.getSize() == 0);

        //Push size elements onto both queues
        for(std::size_t i = 0; i < size; ++i)
        {
            //int nVal = rand() % std::numeric_limits<int>::max();
            int nVal = rand() % 100;

            bQueue.enqueue(nVal);
            refQueue.push_back(nVal);

            REQUIRE(bQueue.back() == refQueue.back());
        }

        REQUIRE(bQueue.getSize() == refQueue.size());

        //Test some random elements
        for(std::size_t i = 0; i < size; ++i)
        {
            REQUIRE(bQueue.peek(i) == refQueue[i]);
        }

        std::size_t elemsToDequeue = rand() % size;

        for(std::size_t i = 0; i < elemsToDequeue; ++i)
        {
            REQUIRE(bQueue.dequeue() == refQueue.front());
            refQueue.pop_front();
        }

        //Test some random elements
        for(std::size_t i = 0; i < refQueue.size(); ++i)
        {
            REQUIRE(bQueue.peek(i) == refQueue[i]);
        }

        REQUIRE(bQueue.getSize() == refQueue.size());
    }
}
