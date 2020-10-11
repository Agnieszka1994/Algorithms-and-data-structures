#include "pch.h"
#include "knuthMorrisPratt.cpp"
#include <any>

TEST(SampleTestCase1, SampleTest) {
    assert(knuthMorrisPrattAlgorithm("aefoaefcdaefcdaed", "aefcdaed") == true);
};