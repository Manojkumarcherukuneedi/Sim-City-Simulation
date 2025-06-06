#include "environmental_zone.h"
#include <algorithm>

void updateEnvironmentalZones(std::vector<std::vector<Cell>> &region) {
    int rows = region.size();
    int cols = region[0].size();

    for (int x = 0; x < rows; ++x) {
        for (int y = 0; y < cols; ++y) {
            if (region[x][y].type == 'E') {
                for (int dx = -1; dx <= 1; ++dx) {
                    for (int dy = -1; dy <= 1; ++dy) {
                        if (dx == 0 && dy == 0) continue;
                        int nx = x + dx;
                        int ny = y + dy;
                        if (nx >= 0 && ny >= 0 && nx < rows && ny < cols) {
                            region[nx][ny].pollutionLevel = std::max(0, region[nx][ny].pollutionLevel - 2);
                        }
                    }
                }
            }
        }
    }
}