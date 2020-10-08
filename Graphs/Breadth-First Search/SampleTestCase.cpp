#include "pch.h"
#include "BreadthFirstSearch.cpp"

TEST(SampleTest, Test) {
	Node graph("A");
    graph.addChild("B")->addChild("C")->addChild("D");
    graph.children[0]->addChild("E")->addChild("F");
    graph.children[2]->addChild("G")->addChild("H");
    graph.children[0]->children[1]->addChild("I")->addChild("J");
    graph.children[2]->children[0]->addChild("K");
    vector<string> expected{ "A", "B", "C", "D", "E", "F",
                             "G", "H", "I", "J", "K" };
    vector<string> inputArray{};
    EXPECT_EQ(graph.breadthFirstSearch(&inputArray),expected);
}
 