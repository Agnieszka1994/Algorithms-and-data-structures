#include "pch.h"
#include "topologicalSort.cpp"
#include <unordered_map>

bool isValidTopologicalOrder(vector<int>, vector<int>,
    vector<vector<int>>);

TEST(SampleTestCase1, SampleTest) {
    vector<int> jobs = { 1, 2, 3, 4 };
    vector<vector<int>> deps = { {1, 2}, {1, 3}, {3, 2}, {4, 2}, {4, 3} };
    vector<int> order = topologicalSort(jobs, deps);
    assert(isValidTopologicalOrder(order, jobs, deps) == true);
};

bool isValidTopologicalOrder(vector<int> order, vector<int> jobs,
    vector<vector<int>> deps) {
    unordered_map<int, bool> visited;
    for (int candidate : order) {
        for (vector<int> dep : deps) {
            if (candidate == dep[0] && visited.find(dep[1]) != visited.end())
                return false;
        }
        visited[candidate] = true;
    }
    for (int job : jobs) {
        if (visited.find(job) == visited.end())
            return false;
    }
    return order.size() == jobs.size();
}