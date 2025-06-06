#include "config.h"
#include "region.h"
#include "residential_zone.h"
#include "industrial_zone.h"
#include "commercial_zone.h"
#include "pollution.h"
#include "region_analysis.h"
#include "environmental_zone.h"
#include <iostream>
#include <vector>
using namespace std;

int main() {
    string configFile = "config1.txt";
    string regionFile;
    int timeLimit = 0, refreshRate = 0;

    if (!readConfig(configFile, regionFile, timeLimit, refreshRate)) {
        cout << "Failed to read config file." << endl;
        return 1;
    }

    vector<vector<Cell>> region;
    if (!readRegion(regionFile, region)) {
        cout << "Failed to read region layout." << endl;
        return 1;
    }

    cout << "Initial Region State (Time Step 0):" << endl;
    displayRegion(region);

    int currentTime = 0;
    bool changed = true;

    while (currentTime < timeLimit && changed) {
        changed = false;

        // Apply growth logic
        changed |= updateResidential(region);
        changed |= updateIndustrial(region);
        changed |= updateCommercial(region);

        // Spread pollution
        spreadPollution(region);
        updateEnvironmentalZones(region);

        currentTime++;

        if (currentTime % refreshRate == 0) {
            cout << "Time Step " << currentTime << ":" << endl;
            displayRegion(region);
        }
    }

    // Final statistics
    displayFinalStats(region);

    // Analyze specific region
    analyzeRegion(region);

    return 0;
}
