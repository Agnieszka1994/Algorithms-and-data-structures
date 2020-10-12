#include "pch.h"
#include "MultiStringSearch.cpp"

TEST(SampleTestCase1, SampleTest) {
    vector<bool> expected{ true, false, true, true, false, true, false };
    assert(multiStringSearch("this is a big string",
        { "this", "yo", "is", "a", "bigger", "string",
         "kappa" }) == expected);
};
TEST(SampleTestCase2, SampleTest) {
    vector<bool> expected{ false, false, false, false, true, false, false };
    assert(multiStringSearch("adcb akfkw afnmc fkadn vkaca jdaf dacb cdba cbda",
        { "abcd", "acbd", "adbc", "dabc", "cbda", "cabd", "cdab"
          }) == expected);
};
TEST(TestThatFails, SampleTest) {
    vector<bool> expected{ false, false, false, false, false, false };
    assert(multiStringSearch("Everything in this test should fail.",
        { "everything", "inn", "that", "testers", "shall", "failure" }) == expected);
};
 