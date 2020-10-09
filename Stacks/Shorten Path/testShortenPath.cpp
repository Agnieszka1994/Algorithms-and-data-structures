#include "pch.h"
#include "ShortenPath.cpp"

TEST(SampleTestCase_1, SampleTest) {
    string expected = "/foo/bar/baz";
    string actual = shortenPath("/foo/../test/../test/../foo//bar/./baz");
    assert(expected == actual);
};
