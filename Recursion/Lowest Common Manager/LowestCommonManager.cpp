#include <vector>
using namespace std;

class OrgChart {
public:
	char name;
	vector<OrgChart*> directReports;

	OrgChart(char name) {
		this->name = name;
		this->directReports = {};
	}
	void addDirectReports(vector<OrgChart*> directReports);
};

struct OrgInfo {
	OrgChart* lowestCommonManager;
	int numImportantReport;
};
OrgInfo getOrgInfo(OrgChart* manager, OrgChart* reportOne, OrgChart* reportTwo);

OrgChart* getLowestCommonManager(OrgChart* topManager, OrgChart* reportOne, OrgChart* reportTwo) {

	return getOrgInfo(topManager, reportOne, reportTwo).lowestCommonManager;
}

OrgInfo getOrgInfo(OrgChart* manager, OrgChart* reportOne,
	OrgChart* reportTwo) {
	int numImportantReport = 0;

	for (auto directReport : manager->directReports) {
		OrgInfo orgInfo = getOrgInfo(directReport, reportOne, reportTwo);
		if (orgInfo.lowestCommonManager != NULL) {
			return orgInfo;
		}
		numImportantReport += orgInfo.numImportantReport;
	}
	if (manager == reportTwo || manager == reportOne) {
		numImportantReport++;
	}
	OrgChart* lowestCommonManager = numImportantReport == 2 ? manager : NULL;
	OrgInfo newOrgInfo = { lowestCommonManager, numImportantReport };
	return newOrgInfo;
}