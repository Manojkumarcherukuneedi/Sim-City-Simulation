#ifndef REGION_H
#define REGION_H
#include <vector>
#include <string>

struct Cell {
    char type;             
    int population;         
    int pollutionLevel;     
};

bool readRegion(const std::string &filename, std::vector<std::vector<Cell>> &region);
void displayRegion(const std::vector<std::vector<Cell>> &region);

#endif