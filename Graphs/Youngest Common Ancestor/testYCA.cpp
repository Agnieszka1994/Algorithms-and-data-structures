#include "pch.h"
#include "YoungestCommonAncestor.cpp"
#include <unordered_map>

void AncestralTree::addAsAncestor(vector<AncestralTree*> descendants) {
    for (AncestralTree* descendant : descendants) {
        descendant->ancestor = this;
    }
}

unordered_map<char, AncestralTree*> getAncestralTrees() {
    unordered_map<char, AncestralTree*> trees;
    string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    for (char a : alphabet) {
        trees.insert({ a, new AncestralTree(a) });
    }
    return trees;
}

TEST(SampleTestCase, SampleTest) {
    auto trees = getAncestralTrees();
    trees.at('A')->addAsAncestor({ trees.at('B'), trees.at('C') });
    trees.at('B')->addAsAncestor({ trees.at('D'), trees.at('E') });
    trees.at('D')->addAsAncestor({ trees.at('H'), trees.at('I') });
    trees.at('C')->addAsAncestor({ trees.at('F'), trees.at('G') });

    AncestralTree* yca = getYoungestCommonAncestor(trees.at('A'), trees.at('E'), trees.at('I'));
    assert(yca == trees.at('B'));
};

