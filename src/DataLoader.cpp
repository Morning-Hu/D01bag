#include "DataLoader.h"
#include <fstream>
#include <sstream>
#include <stdexcept>

pair<int, vector<Item>> DataLoader::loadData(const string& filename)
{
    ifstream file(filename);
    if (!file.is_open())
    {
        throw runtime_error("文件打开失败");
    }

    int capacity, n;
    file >> capacity >> n;

    vector<Item> items(n);
    for (int i = 0; i < n; i++)
    {
        file >> items[i].weight >> items[i].value;
    }

    file.close();
    return {capacity, items};
}
