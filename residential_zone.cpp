#include "residential_zone.h"

// Helper to count adjacent cells with population >= threshold
int countAdjacentPopulation(const std::vector<std::vector<Cell>> &region, int x, int y, int threshold) {
    int count = 0;
    for (int dx = -1; dx <= 1; ++dx) {
        for (int dy = -1; dy <= 1; ++dy) {
            if (dx == 0 && dy == 0) continue;
            int nx = x + dx, ny = y + dy;
            if (nx >= 0 && ny >= 0 && nx < region.size() && ny < region[0].size()) {
                const Cell &adj = region[nx][ny];
                if ((adj.type == 'R' || adj.type == 'C' || adj.type == 'I') && adj.population >= threshold)
                    ++count;
            }
        }
    }
    return count;
}

bool updateResidential(std::vector<std::vector<Cell>> &region) {
    bool changed = false;
    std::vector<std::vector<Cell>> next = region;

    for (int x = 0; x < region.size(); ++x) {
        for (int y = 0; y < region[x].size(); ++y) {
            Cell &cell = region[x][y];
            if (cell.type != 'R' || cell.population >= 5) continue;

            // Rule-based population growth
            int count = countAdjacentPopulation(region, x, y, cell.population);
            if ((cell.population == 0 && count >= 1) ||
                (cell.population == 1 && count >= 2) ||
                (cell.population == 2 && count >= 4) ||
                (cell.population == 3 && count >= 6) ||
                (cell.population == 4 && count >= 8)) {
                next[x][y].population++;
                changed = true;
            } else if (cell.population == 0) {
                // Check powerline adjacency
                for (int dx = -1; dx <= 1 && !changed; ++dx) {
                    for (int dy = -1; dy <= 1 && !changed; ++dy) {
                        int nx = x + dx, ny = y + dy;
                        if (nx >= 0 && ny >= 0 && nx < region.size() && ny < region[0].size()) {
                            char t = region[nx][ny].type;
                            if (t == 'T' || t == '#') {
                                next[x][y].population = 1;
                                changed = true;
                            }
                        }
                    }
                }
            }
        }
    }

    region = next;
    return changed;
}
