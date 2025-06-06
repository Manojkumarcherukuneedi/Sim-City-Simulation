#include "pollution.h"

void spreadPollution(std::vector<std::vector<Cell>> &region) {
    int rows = region.size();
    int cols = region[0].size();

    // Prepare new pollution grid to store updates
    std::vector<std::vector<int>> newPollution(rows, std::vector<int>(cols, 0));

    for (int x = 0; x < rows; ++x) {
        for (int y = 0; y < cols; ++y) {
            const Cell &cell = region[x][y];
            if (cell.type == 'I' && cell.population > 0) {
                // Spread pollution to this and surrounding cells
                for (int dx = -cell.population; dx <= cell.population; ++dx) {
                    for (int dy = -cell.population; dy <= cell.population; ++dy) {
                        int dist = abs(dx) + abs(dy);
                        if (dist <= cell.population) {
                            int nx = x + dx;
                            int ny = y + dy;
                            if (nx >= 0 && ny >= 0 && nx < rows && ny < cols) {
                                int pollutionToAdd = std::max(0, cell.population - dist);
                                newPollution[nx][ny] += pollutionToAdd;
                            }
                        }
                    }
                }
            }
        }
    }

    // Update pollution levels in the region
    for (int x = 0; x < rows; ++x) {
        for (int y = 0; y < cols; ++y) {
            region[x][y].pollutionLevel += newPollution[x][y];
        }
    }
}
