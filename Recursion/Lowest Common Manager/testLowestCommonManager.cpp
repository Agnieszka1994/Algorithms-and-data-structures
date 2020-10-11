#include "pch.h"
#include "LowestCommonManager.cpp"
#include <unordered_map>

void OrgChart::addDirectReports(vector<OrgChart*> directReports) {
    for (OrgChart* directReport : directReports) {
        this->directReports.push_back(directReport);
    }
}

unordered_map<char, OrgChart*> getOrgcharts() {
    unordered_map<char, OrgChart*> orgCharts;
    string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    for (char a : alphabet) {
        orgCharts.insert({ a, new OrgChart(a) });
    }
    orgCharts.at('X')->addDirectReports({
        orgCharts.at('Z'),
        });
    return orgCharts;
}

TEST(SampleTestCase1, SampleTest) {
    auto orgCharts = getOrgcharts();
    orgCharts.at('A')->addDirectReports(
        { orgCharts.at('B'), orgCharts.at('C') });
    orgCharts.at('B')->addDirectReports(
        { orgCharts.at('D'), orgCharts.at('E') });
    orgCharts.at('C')->addDirectReports(
        { orgCharts.at('F'), orgCharts.at('G') });
    orgCharts.at('D')->addDirectReports(
        { orgCharts.at('H'), orgCharts.at('I') });

    OrgChart* lcm = getLowestCommonManager(
        orgCharts.at('A'), orgCharts.at('E'), orgCharts.at('I'));
    assert(lcm == orgCharts.at('B'));
};