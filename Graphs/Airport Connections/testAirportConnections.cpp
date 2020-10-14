#include "pch.h"
#include "AirportConnections.cpp"
#include <iostream>
vector<string> AIRPORTS = {
    "BGI", "CDG", "DEL", "DOH", "DSM", "EWR", "EYW", "HND", "ICN",
    "JFK", "LGA", "LHR", "ORD", "SAN", "SFO", "SIN", "TLV", "BUD",
};

TEST(SampleTestCase1, SampleTest) {
    string STARTING_AIRPORT = "LGA";
    vector<vector<string>> routes = {
                 {"DSM", "ORD"}, {"ORD", "BGI"}, {"BGI", "LGA"}, {"SIN", "CDG"},
                 {"CDG", "SIN"}, {"CDG", "BUD"}, {"DEL", "DOH"}, {"DEL", "CDG"},
                 {"TLV", "DEL"}, {"EWR", "HND"}, {"HND", "ICN"}, {"HND", "JFK"},
                 {"ICN", "JFK"}, {"JFK", "LGA"}, {"EYW", "LHR"}, {"LHR", "SFO"},
                 {"SFO", "SAN"}, {"SFO", "DSM"}, {"SAN", "EYW"} };
    assert(airportConnections(AIRPORTS, routes, STARTING_AIRPORT) == 3);
};