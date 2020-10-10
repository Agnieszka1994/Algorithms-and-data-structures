#include "pch.h"
#include "numbersInPi.cpp"

string PI = "3141592653589793238462643383279";

TEST(SampleTestCase, SampleTest) {
    vector<string> numbers = {
          "314159265358979323846", "26433", "8", "3279", "314159265",
          "35897932384626433832",  "79" };
    assert(numbersInPi(PI, numbers) == 2);
};
