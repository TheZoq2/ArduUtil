#include "catch.hpp"
#include "../BoundedQueue.h"

TEST_CASE("Bounded queue sizes")
{
    BoundedQueue<int> queue(5);

    //Ensure that the new queue is empty
    REQUIRE(queue.getSize() == 0);

    queue.enqueue(1);
    queue.enqueue(3);
    queue.enqueue(-1);
    queue.enqueue(-1);
    queue.enqueue(-1);

    SECTION( "Correct contents")
    {
        REQUIRE(queue.getSize() == 5);

        REQUIRE(queue.back() == -1);

        REQUIRE(queue.peek(0) == 1);
        REQUIRE(queue.peek(1) == 3);
        REQUIRE(queue.peek(2) == -1);
        REQUIRE(queue.peek(2) == -1);
        REQUIRE(queue.peek(2) == -1);

        //Dequeue a few elements
        REQUIRE(queue.dequeue() == 1);
        REQUIRE(queue.dequeue() == 3);

        REQUIRE(queue.getSize() == 3);

        //Enqueue 2 new elements to make sure that works
        queue.enqueue(2);
        queue.enqueue(4);
        
        REQUIRE(queue.dequeue() == -1);
        REQUIRE(queue.dequeue() == -1);
        REQUIRE(queue.dequeue() == -1);
        REQUIRE(queue.dequeue() == 2);
        REQUIRE(queue.dequeue() == 4);

        REQUIRE(queue.getSize() == 0);
    }
}
