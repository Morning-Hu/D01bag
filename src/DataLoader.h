#ifndef DATALOADER_H
#define DATALOADER_H

#include <vector>
#include <string>

using namespace std;

struct Item
{
    int weight;
    int value;
};

class DataLoader
{
public:
    static pair<int, vector<Item>> loadData(const string& filename);
};

#endif
