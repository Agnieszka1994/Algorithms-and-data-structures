#include "pch.h"
#include "ApartmentHunting.cpp"
#include <vector>

TEST(SampleTestCase, SampleTest) {
    vector<unordered_map<string, bool>> blocks(5);

    blocks[0].insert({ "gym", false });
    blocks[0].insert({ "school", true });
    blocks[0].insert({ "store", false });

    blocks[1].insert({ "gym", true });
    blocks[1].insert({ "school", false });
    blocks[1].insert({ "store", false });

    blocks[2].insert({ "gym", true });
    blocks[2].insert({ "school", true });
    blocks[2].insert({ "store", false });

    blocks[3].insert({ "gym", false });
    blocks[3].insert({ "school", true });
    blocks[3].insert({ "store", false });

    blocks[4].insert({ "gym", false });
    blocks[4].insert({ "school", true });
    blocks[4].insert({ "store", true });

    vector<string> reqs = { "gym", "school", "store" };
    EXPECT_EQ(apartmentHunting(blocks, reqs), 3);
}

