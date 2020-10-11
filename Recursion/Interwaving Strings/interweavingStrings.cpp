using namespace std;
bool interweavingHelper(string, string, string, int, int);

bool interweavingStrings(string one, string two, string three) {
	if (three.size() != one.size() + two.size())
		return false;

	return interweavingHelper(one, two, three, 0, 0);
}

bool interweavingHelper(string one, string two, string three, int i, int j) {
	int k = i + j;
	if (k == three.size()) {
		return true;
	}
	if (i < one.size() && one[i] == three[k]) {
		if (interweavingHelper(one, two, three, i + 1, j))
			return true;
	}
	if (j < two.size() && two[j] == three[k]) {
		if (interweavingHelper(one, two, three, i, j + 1))
			return true;
	}
	return false;
}