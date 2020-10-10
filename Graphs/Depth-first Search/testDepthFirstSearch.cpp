#include "pch.h"
#include "DepthFirstSearch.cpp"

    TEST(SampleTestCase_1, SampleTest) {
        Node graph("A");
        graph.addChild("B")->addChild("C")->addChild("D");
        graph.children[0]->addChild("E")->addChild("F");
        graph.children[2]->addChild("G")->addChild("H");
        graph.children[0]->children[1]->addChild("I")->addChild("J");
        graph.children[2]->children[0]->addChild("K");

        vector<string> expected{ "A", "B", "E", "F", "I", "J",
                                "C", "D", "G", "K", "H" };
        vector<string> inputArray{};
        assert(graph.depthFirstSearch(&inputArray) == expected);
    };

