#include "config.h"
#include <fstream>
#include <sstream>
#include <iostream>

bool readConfig(const std::string &filename, std::string &regionFile, int &timeLimit, int &refreshRate) {
    std::ifstream infile(filename);
    if (!infile.is_open()) return false;

    std::string line;
    while (getline(infile, line)) {
        if (line.find("Region Layout:") != std::string::npos) {
            regionFile = line.substr(line.find(":") + 1);
        } else if (line.find("Time Limit:") != std::string::npos) {
            timeLimit = std::stoi(line.substr(line.find(":") + 1));
        } else if (line.find("Refresh Rate:") != std::string::npos) {
            refreshRate = std::stoi(line.substr(line.find(":") + 1));
        }
    }
    infile.close();
    return true;
}