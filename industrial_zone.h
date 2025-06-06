#ifndef INDUSTRIAL_ZONE_H
#define INDUSTRIAL_ZONE_H
#include "region.h"

bool updateIndustrial(std::vector<std::vector<Cell>> &region);
bool isNearEnvironmentalZone(const std::vector<std::vector<Cell>> &region, int x, int y);

#endif