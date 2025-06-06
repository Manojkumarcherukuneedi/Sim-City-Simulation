#include "commercial_zone.h"

int countAdjacentCommercial(const std::vector<std::vector<Cell>> &region, int x, int y, int threshold) {
    int count = 0;
    for (int dx = -1; dx <= 1; ++dx) {
        for (int dy = -1; dy <= 1; ++dy) {
            if (dx == 0 && dy == 0) continue;
            int nx = x + dx, ny = y + dy;
            if (nx >= 0 && ny >= 0 && nx < region.size() && ny < region[0].size()) {
                const Cell &adj = region[nx][ny];
                if (adj.type == 'C' && adj.population >= threshold)
                    ++count;
            }
        }
    }
    return count;
}

bool updateCommercial(std::vector<std::vector<Cell>> &region) {
    bool changed = false;
    std::vector<std::vector<Cell>> next = region;

    for (int x = 0; x < region.size(); ++x) {
        for (int y = 0; y < region[x].size(); ++y) {
            Cell &cell = region[x][y];
            if (cell.type != 'C' || cell.population >= 2) continue;

            int availableWorkers = 1000; // placeholder
            int availableGoods = 1000;   // placeholder
            if (availableWorkers < 1 || availableGoods < 1) continue;

            int count = countAdjacentCommercial(region, x, y, cell.population);
            bool shouldGrow = false;

            if ((cell.population == 0 && count >= 1) ||
                (cell.population == 1 && count >= 2)) {
                shouldGrow = true;
            } else if (cell.population == 0) {
                for (int dx = -1; dx <= 1 && !shouldGrow; ++dx) {
                    for (int dy = -1; dy <= 1 && !shouldGrow; ++dy) {
                        int nx = x + dx, ny = y + dy;
                        if (nx >= 0 && ny >= 0 && nx < region.size() && ny < region[0].size()) {
                            char t = region[nx][ny].type;
                            if (t == 'T' || t == '#') {
                                shouldGrow = true;
                            }
                        }
                    }
                }
            }

            if (shouldGrow) {
                next[x][y].population++;
                changed = true;
            }
        }
    }

    region = next;
    return changed;
}