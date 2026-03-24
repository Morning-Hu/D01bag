#ifndef KNAPSOLVER_H
#define KNAPSOLVER_H

#include "DataLoader.h"
#include <vector>
#include <algorithm>

using namespace std;

class KnapSolver
{
public:
    static int knapSack(int cap, vector<Item>& items)
    {
        int n = items.size();
        vector<vector<int>> dp(n + 1, vector<int>(cap + 1, 0));

        for (int i = 1; i <= n; i++)
        {
            int w = items[i-1].weight;
            int v = items[i-1].value;

            for (int j = 1; j <= cap; j++)
            {
                if (w <= j)
                {
                    dp[i][j] = max(dp[i-1][j], dp[i-1][j - w] + v);
                }
                else
                {
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        return dp[n][cap];
    }
};

#endif
