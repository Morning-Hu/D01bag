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

        cout << "bag cap#include <iostream>
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

        cout << "Bag Capacity:" << cap << endl;
        cout << "Number of Items:" << items.size() << endl;
        cout << "Max Value:" << ans << endl;
    }
    catch (exception& e)
    {
        cout << "错误：" << e.what() << endl;
    }

    return 0;
}
