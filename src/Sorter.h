#ifndef SORTER_H
#define SORTER_H

#include "DataLoader.h"
#include <algorithm>

class Sorter {
public:
    // 按每组物品的价值密度（价值/重量）降序排序
    static void sortByValueDensity(std::vector<ItemGroup>& groups) {
        std::sort(groups.begin(), groups.end(), [](const ItemGroup& a, const ItemGroup& b) {
            double densityA = (a.v1 + a.v2 + a.v3) / (double)(a.w1 + a.w2 + a.w3);
            double densityB = (b.v1 + b.v2 + b.v3) / (double)(b.w1 + b.w2 + b.w3);
            return densityA > densityB;
        });
    }
};

#endif // SORTER_H
