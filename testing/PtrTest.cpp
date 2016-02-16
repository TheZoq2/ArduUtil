#include "catch.hpp"
#include "../UniquePtr.h"

TEST_CASE("Unique pointer")
{
    int* rawPtr1 = new int(0);
    atd::UniquePtr<int> ptr1(rawPtr1);
    atd::UniquePtr<int> ptr2(new int(2));

    REQUIRE(ptr1.get() == rawPtr1);
    REQUIRE(*ptr1 == *rawPtr1);

    //Test move operator
    //ptr2 = std::move(ptr1);

    //REQUIRE(ptr2.get() == rawPtr1);

}

