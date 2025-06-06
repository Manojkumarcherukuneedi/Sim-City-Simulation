#include "region_analysis.h"
#include <iostream>
using namespace std;

void displayFinalStats(const vector<vector<Cell>> &region) {
    int totalR = 0, totalC = 0, totalI = 0;
    int totalPollution = 0;

    for (const auto &row : region) {
        for (const auto &cell : row) {
            if (cell.type == 'R') totalR += cell.population;
            if (cell.type == 'C') totalC += cell.population;
            if (cell.type == 'I') totalI += cell.population;
            totalPollution += cell.pollutionLevel;
        }
    }

    cout << "\nFinal Region State:" << endl;
    displayRegion(region);

    cout << "\nTotal Residential Population: " << totalR << endl;
    cout << "Total Commercial Population: " << totalC << endl;
    cout << "Total Industrial Population: " << totalI << endl;
    cout << "Total Pollution: " << totalPollution << endl;
}

void analyzeRegion(const vector<vector<Cell>> &region) {
    int x1, y1, x2, y2;
    int rows = region.size();
    int cols = region[0].size();

    while (true) {
        cout << "\nEnter top-left and bottom-right coordinates of the area to analyze (x1 y1 x2 y2): ";
        cin >> x1 >> y1 >> x2 >> y2;

        if (x1 >= 0 && y1 >= 0 && x2 < rows && y2 < cols && x1 <= x2 && y1 <= y2) break;
        cout << "Invalid coordinates. Please try again." << endl;
    }

    int areaR = 0, areaC = 0, areaI = 0, areaPollution = 0;
    for (int x = x1; x <= x2; ++x) {
        for (int y = y1; y <= y2; ++y) {
            const Cell &cell = region[x][y];
            if (cell.type == 'R') areaR += cell.population;
            if (cell.type == 'C') areaC += cell.population;
            if (cell.type == 'I') areaI += cell.population;
            areaPollution += cell.pollutionLevel;
        }
    }

    cout << "\nRegion Analysis Results:" << endl;
    cout << "Residential Population: " << areaR << endl;
    cout << "Commercial Population: " << areaC << endl;
    cout << "Industrial Population: " << areaI << endl;
    cout << "Total Pollution: " << areaPollution << endl;
}
