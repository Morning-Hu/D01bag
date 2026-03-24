#include <iostream>
#include "DataLoader.h"
#include "KnapSolver.h"

using namespace std;

int main()
{
    try
    {
        auto data = DataLoader::loadData("data.txt");
        int cap = data.first;
        auto items = data.second;

        int ans = KnapSolver::knapSack(cap, items);

        cout << "背包容量：" << cap << endl;
        cout << "物品数量：" << items.size() << endl;
        cout << "最大价值：" << ans << endl;
    }
    catch (exception& e)
    {
        cout << "错误：" << e.what() << endl;
    }

    return 0;
}
