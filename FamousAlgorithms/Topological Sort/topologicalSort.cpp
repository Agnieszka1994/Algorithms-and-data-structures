#include <unordered_map>
#include <vector>
using namespace std;

class JobNode {
public:
	int job;
	vector<JobNode*> dependencies{};
	int numOfPrereqs{ 0 };
	JobNode(int job) : job(job) {};
};

class JobGraph {
public:
	vector<JobNode*> nodes;
	unordered_map <int, JobNode*> graph;

	JobGraph(vector<int> jobs) {
		nodes = {};
		for (auto job : jobs) {
			addNode(job);
		}
	}

	void addDependency(int job, int dep) {
		JobNode* jobNode = getNode(job);
		JobNode* dependencyNode = getNode(dep);
		jobNode->dependencies.push_back(dependencyNode);
		dependencyNode->numOfPrereqs++;
	}

	void addNode(int job) {
		graph[job] = new JobNode(job);
		nodes.push_back(graph[job]);
	}

	JobNode* getNode(int job) {
		if (graph.find(job) == graph.end()) {
			addNode(job);
		}
		return graph[job];
	}
};

JobGraph* createJobGraph(vector<int> jobs, vector<vector<int>> deps);
vector<int> getOrderedJobs(JobGraph*);
void removeDeps(JobNode* node, vector<JobNode*>* nodesWithNoPrereqs);

vector<int> topologicalSort(vector<int> jobs, vector<vector<int>> deps) {
	JobGraph* graph = createJobGraph(jobs, deps);
	return getOrderedJobs(graph);
}

JobGraph* createJobGraph(vector<int> jobs, vector<vector<int>> deps) {
	JobGraph* graph = new JobGraph(jobs);
	for (auto dependency : deps) {
		graph->addDependency(dependency[0], dependency[1]);
	}
	return graph;
}

vector<int> getOrderedJobs(JobGraph* graph) {
	vector<int> orderedJobs{};
	vector<JobNode*> nodesWithNoPrereqs(graph->nodes.size());

	auto noPrereqs = [](JobNode* node) { return node->numOfPrereqs == 0; };
	auto it = copy_if(graph->nodes.begin(), graph->nodes.end(), nodesWithNoPrereqs.begin(), noPrereqs);
	nodesWithNoPrereqs.resize(distance(nodesWithNoPrereqs.begin(), it));

	while (nodesWithNoPrereqs.size()) {
		JobNode* node = nodesWithNoPrereqs.back();
		nodesWithNoPrereqs.pop_back();
		orderedJobs.push_back(node->job);
		removeDeps(node, &nodesWithNoPrereqs);
	}
	bool graphHasEdges = false;
	for (auto node : graph->nodes) {
		if (node->numOfPrereqs) {
			graphHasEdges = true;
		}
	}
	return graphHasEdges ? vector<int>{} : orderedJobs;
}

void removeDeps(JobNode* node, vector<JobNode*>* nodesWithNoPrereqs) {
	while (node->dependencies.size()) {
		JobNode* dependency = node->dependencies.back();
		node->dependencies.pop_back();
		dependency->numOfPrereqs--;
		if (!dependency->numOfPrereqs) //if there are no prerequisites
			nodesWithNoPrereqs->push_back(dependency);
	}
}