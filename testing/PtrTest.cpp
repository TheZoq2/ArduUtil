#include "catch.hpp"
#include "../UniquePtr.h"

TEST_CASE("Unique pointer")
{
    atd::UniquePtr<int> ptr1(new int(0));
}

