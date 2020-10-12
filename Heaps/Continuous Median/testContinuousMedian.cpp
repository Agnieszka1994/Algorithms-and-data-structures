#include "pch.h"
#include "ContinuousMedian.cpp"
#include <vector>

TEST(SampleTestCase1, SampleTest) {
    ContinuousMedianHandler handler;
    handler.insert(5);
    handler.insert(10);
    assert(handler.getMedian() == 7.5);
    handler.insert(100);
    assert(handler.getMedian() == 10);
};

/*TEST(SampleTestCase2, SampleTest) {
    ContinuousMedianHandler handler;
    handler.insert(5);
    handler.insert(10);
    handler.insert(100);
    handler.insert(200);
    handler.insert(6);
    handler.insert(13);
    handler.insert(14);
    handler.insert(50);
    handler.insert(51);
    handler.insert(52);
    handler.insert(1000);
    handler.insert(10000);
    handler.insert(10001);
    handler.insert(10002);
    handler.insert(10003);
    assert(handler.getMedian() == 52);
    handler.insert(10004);
    assert(handler.getMedian() == 76);
};*/