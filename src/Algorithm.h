#ifndef ALGORITHM_H
#define ALGORITHM_H

#include "DataLoader.h"
#include <vector>
#include <algorithm>

class Algorithm {
public:
    // 标准 0-1 背包：每个物品可选/不选，无分组限制
    static int standard01Knapsack(int capacity, std::vector<ItemGroup>& groups) {
        std::vector<int> dp(capacity + 1, 0);

        for (auto& g : groups) {
            // 物品1
            for (int j = capacity; j >= g.w1; j--) {
                dp[j] = std::max(dp[j], dp[j - g.w1] + g.v1);
            }
            // 物品2
            for (int j = capacity; j >= g.w2; j--) {
                dp[j] = std::max(dp[j], dp[j - g.w2] + g.v2);
            }
            // 物品3
            for (int j = capacity; j >= g.w3; j--) {
                dp[j] = std::max(dp[j], dp[j - g.w3] + g.v3);
            }
        }
        return dp[capacity];
    }
};

#endif
