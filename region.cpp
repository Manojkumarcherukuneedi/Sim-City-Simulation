#include "region.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <iomanip>

using namespace std;

bool readRegion(const string &filename, vector<vector<Cell>> &region) {
    ifstream infile(filename);
    if (!infile.is_open()) return false;

    string line;
    while (getline(infile, line)) {
        stringstream ss(line);
        string token;
        vector<Cell> row;
        while (getline(ss, token, ',')) {
            if (!token.empty()) {
                Cell c;
                c.type = token[0];
                c.population = 0;
                c.pollutionLevel = 0;
                row.push_back(c);
            }
        }
        region.push_back(row);
    }
    infile.close();
    return true;
}

void displayRegion(const vector<vector<Cell>> &region) {
    size_t maxCols = 0;
    for (const auto &row : region) {
        if (row.size() > maxCols) maxCols = row.size();
    }

    for (const auto &row : region) {
        for (size_t col = 0; col < maxCols; ++col) {
            if (col < row.size()) {
                const Cell &cell = row[col];
                if ((cell.type == 'R' || cell.type == 'C' || cell.type == 'I') && cell.population == 0)
                    cout << setw(2) << cell.type;
                else if (cell.population > 0)
                    cout << setw(2) << cell.population;
                else
                    cout << setw(2) << cell.type;
            } else {
                cout << setw(2) << " ";
            }
        }
        cout << endl;
    }
}
