#include "pch.h"
#include "RectangleMania.cpp"

TEST(SampleTestCase1, SampleTest) {
    vector<Point> coords = { Point({0, 0}), Point({0, 1}), Point({1, 1}),
                               Point({1, 0}), Point({2, 1}), Point({2, 0}),
                               Point({3, 1}), Point({3, 0}) };
    assert(rectangleMania(coords) == 6);
};