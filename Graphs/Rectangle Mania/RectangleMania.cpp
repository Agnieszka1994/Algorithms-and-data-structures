#include <vector>
#include <unordered_map>
#include <string>

using namespace std;

struct Point {
	int x;
	int y;
};

unordered_map<string, bool> getCoordinates(vector<Point> coordinates);
int countRectangles(vector<Point>, unordered_map<string, bool>);
bool isInUpperRight(Point, Point);
string coordToString(Point);

int rectangleMania(vector<Point> coords) {
	unordered_map<string, bool> coordsCache = getCoordinates(coords);
	return countRectangles(coords, coordsCache);
}

unordered_map<string, bool> getCoordinates(vector<Point> coordinates) {
	unordered_map<string, bool> coordsCache;
	for (auto coord : coordinates) {
		coordsCache.insert({ coordToString(coord), true });
	}
	return coordsCache;
}
int countRectangles(vector<Point> coordinates, unordered_map<string, bool> coordsCache) {
	int rectangCount{ 0 };
	for (auto coord1 : coordinates) {
		for (auto coord2 : coordinates) {
			if (!isInUpperRight(coord1, coord2))
				continue;
			string missingUpperCoord = coordToString(Point({ coord1.x, coord2.y }));
			string missingBottomCoord = coordToString(Point({ coord2.x, coord1.y }));
			//if both coordinates was found in the Cache - increment the rectangle counter
			if (coordsCache.find(missingUpperCoord) != coordsCache.end()
				&& coordsCache.find(missingBottomCoord) != coordsCache.end())
				rectangCount++;
		}
	}
	return rectangCount;
}
bool isInUpperRight(Point coord1, Point coord2) {
	return coord2.x > coord1.x && coord2.y > coord1.y;
}
string coordToString(Point coord) {
	return to_string(coord.x) + "-" + to_string(coord.y);
}