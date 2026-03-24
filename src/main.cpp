#include <iostream>
#include <vector>
#include <algorithm>
#include "DataLoader.h"

using namespace std;

int knapSack(int cap, vector<Item>& items)
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
                dp[i][j] = max(dp[i-1][j], dp[i-1][j - w] + v);
            else
                dp[i][j] = dp[i-1][j];
        }
    }
    return dp[n][cap];
}

int main()
{
    try
    {
        auto data = DataLoader::loadData("data.txt");
        int cap = data.first;
        auto items = data.second;

        int ans = knapSack(cap, items);

        cout << "Capacity: " << cap << endl;
        cout << "Items: " << items.size() << endl;
        cout << "Max value: " << ans << endl;
    }
    catch (exception& e)
    {
        cout << "Error: " << e.what() << endl;
    }
    return 0;
}
