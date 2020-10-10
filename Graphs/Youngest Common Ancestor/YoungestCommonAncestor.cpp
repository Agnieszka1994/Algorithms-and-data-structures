#include <vector>
using namespace std;

class AncestralTree {
public:
	char name;
	AncestralTree* ancestor;

	AncestralTree(char name) {
		this->name = name;
		this->ancestor = NULL;
	}
	void addAsAncestor(vector<AncestralTree*> descendants);
};

AncestralTree* getYoungestCommonAncestor(AncestralTree* topAncestor,
	AncestralTree* descendantOne,
	AncestralTree* descendantTwo) {

	vector<AncestralTree*> ancestorsOne;
	AncestralTree* currentAncestor = descendantOne;
	vector<AncestralTree*> ancestorsTwo;
	while (currentAncestor != NULL) {
		ancestorsOne.push_back(currentAncestor);
		currentAncestor = currentAncestor->ancestor;
	}
	currentAncestor = descendantTwo;
	while (currentAncestor != NULL) {
		ancestorsTwo.push_back(currentAncestor);
		currentAncestor = currentAncestor->ancestor;
	}
	for (auto ancestor : ancestorsOne) {
		for (auto ancestor2 : ancestorsTwo) {
			if (ancestor == ancestor2)
				return ancestor;
		}
	}
	return NULL;
}