#ifndef ALGORITHM_H
#define ALGORITHM_H

#include "DataLoader.h"
#include <vector>
#include <algorithm>

class Algorithm {
public:
    // 贪心算法：每组选价值密度最高的物品（快速得到近似解）
    static int greedySolve(int capacity, std::vector<ItemGroup>& groups) {
        int totalValue = 0;
        int remainingCapacity = capacity;

        for (auto& group : groups) {
            // 计算组内三个物品的价值密度
            double d1 = (double)group.v1 / group.w1;
            double d2 = (double)group.v2 / group.w2;
            double d3 = (double)group.v3 / group.w3;

            // 选价值密度最大且能装下的物品
            if (d1 >= d2 && d1 >= d3 && group.w1 <= remainingCapacity) {
                totalValue += group.v1;
                remainingCapacity -= group.w1;
            } else if (d2 >= d1 && d2 >= d3 && group.w2 <= remainingCapacity) {
                totalValue += group.v2;
                remainingCapacity -= group.w2;
            } else if (d3 <= remainingCapacity) {
                totalValue += group.v3;
                remainingCapacity -= group.w3;
            }
        }
        return totalValue;
    }

    // 动态规划：精确求解 D{0-1}KP（每组选且仅选一个物品）
    static int dpSolve(int capacity, std::vector<ItemGroup>& groups) {
        std::vector<int> dp(capacity + 1, 0);

        for (auto& group : groups) {
            std::vector<int> nextDp = dp;
            for (int j = 0; j <= capacity; ++j) {
                if (j >= group.w1) nextDp[j] = std::max(nextDp[j], dp[j - group.w1] + group.v1);
                if (j >= group.w2) nextDp[j] = std::max(nextDp[j], dp[j - group.w2] + group.v2);
                if (j >= group.w3) nextDp[j] = std::max(nextDp[j], dp[j - group.w3] + group.v3);
            }
            dp = std::move(nextDp);
        }
        return dp[capacity];
    }
};

#endif // ALGORITHM_H
