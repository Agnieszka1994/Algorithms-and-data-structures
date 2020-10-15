#include <vector>
#include <unordered_map>
using namespace std;

class Airport {
public:
	string code;
	vector<string> connections;
	bool isReachable;
	vector<string> unreachableAirports;

	Airport(string code) {
		this->code = code;
		connections = {};
		isReachable = true;
		unreachableAirports = {};
	}
};

// O(a + r) time | O(a + r) space
unordered_map<string, Airport*> createGraph(vector<string> airports, vector<vector<string>> routes);
// standard depth-firstSearch complexity - O(a + r + a) time | O(a) space
vector<Airport*> getUnreachableAirports(unordered_map<string, Airport*>, vector<string>, string);

void depthFirstTraverse(unordered_map<string, Airport*>, string, unordered_map<string, bool>*);

void markUnreachableAirports(unordered_map<string, Airport*>, vector< Airport*>);

void depthFirstAddUnreachable(unordered_map<string, Airport*>, string, vector<string>*, unordered_map<string, bool>*);

int getMinNumOfNewConnections(unordered_map<string, Airport*>, vector< Airport*>);

// Main method-----------------------------------------------------------------------------
int airportConnections(vector<string> airports, vector<vector<string>> routes, string startingAirport) {
	unordered_map<string, Airport*> airportGraph = createGraph(airports, routes);
	vector< Airport*> unreachableAirports = getUnreachableAirports(airportGraph, airports, startingAirport);
	markUnreachableAirports(airportGraph, unreachableAirports);
	return getMinNumOfNewConnections(airportGraph, unreachableAirports);
}
//------------------------------------------------------------------------------------------
unordered_map<string, Airport*> createGraph(vector<string> airports, vector<vector<string>> routes) {
	unordered_map<string, Airport*> airportGraph = {};
	for (string airport : airports) {
		airportGraph[airport] = new Airport(airport);
	}
	for (auto route : routes) {
		string depart = route[0];
		string destination = route[1];
		airportGraph[depart]->connections.push_back(destination);
	}
	return airportGraph;
}
//------------------------------------------------------------------------------------------
// get a table of all the airports that cannot be reached from the starting airport
vector<Airport*> getUnreachableAirports(unordered_map<string, Airport*> graph, vector<string> airports, string startAirport) {
	unordered_map<string, bool> visitedAirports = {};
	depthFirstTraverse(graph, startAirport, &visitedAirports);

	vector<Airport*> unreachableAirports = {};
	for (string airport : airports) {
		if (visitedAirports.find(airport) != visitedAirports.end())
			continue;
		Airport* airportPtr = graph[airport];
		// if the airport is not on the list of visited airports 
		// after the depth first traverse - it is unreachable
		airportPtr->isReachable = false;
		unreachableAirports.push_back(airportPtr);
	}
	return unreachableAirports;
}
//------------------------------------------------------------------------------------------
// this is a recursive function that add all reachable airports to the list of visited
void depthFirstTraverse(unordered_map<string, Airport*> graph, string airport, unordered_map<string, bool>* visitedAirports) {
	//if the airport was already visited - is in the hash table - return
	if (visitedAirports->find(airport) != visitedAirports->end()) {
		return;
	}
	visitedAirports->insert({ airport, true });
	vector<string> connections = graph[airport]->connections;
	for (auto connection : connections) {
		depthFirstTraverse(graph, connection, visitedAirports);
	}
}
//------------------------------------------------------------------------------------------
// this function add a 'score' to each unreachable airport
// a number of airports reaachable from a given airport
// (how many airports it will 'unlock' when it becomes reachable)
void markUnreachableAirports(unordered_map<string, Airport*> graph, vector< Airport*> unreachableAirports) {
	for (auto airport: unreachableAirports) {
		string code = airport->code;
		vector<string> unreachableAirports = {};
		unordered_map<string, bool> visitedAirports = {};
		depthFirstAddUnreachable(
				graph, code, &unreachableAirports, &visitedAirports);
		//update the list of airports that are unreachable from a given airport
		airport->unreachableAirports = unreachableAirports;
	}
}
//------------------------------------------------------------------------------------------
// traverse the graph to check how many unreachable 
// airports will be unlocked from a given airport 
void depthFirstAddUnreachable(unordered_map<string, Airport*> graph, string airport, vector<string>* unreachable, unordered_map<string, bool>* visitedAirports) {
	// if the current airport is reachable - return 
	// we only iterate through the unreachable airports
	if (graph[airport]->isReachable) {
		return;
	}
	// if the airport is already on the list of visited airports - return 
	if (visitedAirports->find(airport) != visitedAirports->end()) {
		return;
	}
	// the airport is not on the list of visited - add it
	visitedAirports->insert({airport, true});
	// add the current airport to the list as every airport
	// unlocks one additional airport - itself
	unreachable->push_back(airport);
	// connections = all reachable airports from the current airport 
	vector<string> connections = graph[airport]->connections;
	// add unreachable connections for rach airport on the connection list
	for (string connection : connections) {
		depthFirstAddUnreachable(graph, connection, unreachable, visitedAirports);
	}
}

int getMinNumOfNewConnections(unordered_map<string, Airport*> graph, vector< Airport*> unreachableAirports) {
	// sort the unreachable airports by number of airports they potentially unlock
	sort(unreachableAirports.begin(), unreachableAirports.end(), 
			 [](Airport* a1, Airport* a2) -> bool 
			{ return a2->unreachableAirports.size() <
							 a1->unreachableAirports.size(); 
			});
	
	int numOfNewConnections = 0;
	for (auto airport : unreachableAirports) {
		if (airport->isReachable)
			continue;
		//if the airport is unreachable - make a new connection
		numOfNewConnections++;
		// mark all unlocked airports as reachable
		for (auto connection : airport->unreachableAirports) {
			graph[connection]->isReachable = true;
		}
	}
	return numOfNewConnections;
}
