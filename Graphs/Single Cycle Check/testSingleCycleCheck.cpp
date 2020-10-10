#include "pch.h"
#include "SingleCycleCheck.cpp"

    TEST(SampleTestCase_1, SampleTest) {
        assert(hasSingleCycle({ 2, 3, 1, -4, -4, 2 }) == true);
    };

