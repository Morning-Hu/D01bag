#include <iostream>
#include <fstream>
#include <chrono>
#include <iomanip>
#include "DataLoader.h"
#include "Algorithm.h"

using namespace std;
using namespace chrono;

// 绘制散点图数据
void drawScatter(vector<ItemGroup>& groups) {
    ofstream fout("scatter_data.txt");
    for (auto& g : groups) {
        fout << g.w1 << " " << g.v1 << endl;
        fout << g.w2 << " " << g.v2 << endl;
        fout << g.w3 << " " << g.v3 << endl;
    }
    cout << "散点数据已保存到 scatter_data.txt" << endl;
}

// 按第三项价值密度降序排序
void sortByThirdDensity(vector<ItemGroup>& groups) {
    sort(groups.begin(), groups.end(), [](ItemGroup& a, ItemGroup& b) {
        double da = (double)a.v3 / a.w3;
        double db = (double)b.v3 / b.w3;
        return da > db;
    });
    cout << "已按第三项价值密度降序排序" << endl;
}

// 保存结果到文件
void saveResult(int cap, int ans, double ms) {
    ofstream ftxt("result.txt");
    ftxt << "背包容量: " << cap << endl;
    ftxt << "最大价值: " << ans << endl;
    ftxt << "运行时间: " << fixed << setprecision(2) << ms << "ms" << endl;

    ofstream fcsv("result.csv");
    fcsv << "capacity,max_value,time_ms" << endl;
    fcsv << cap << "," << ans << "," << ms << endl;

    cout << "结果已保存到 result.txt / result.csv" << endl;
}

int main() {
    try {
        auto data = DataLoader::LoadD01KPFile("data.txt");
        int cap = data.first;
        auto groups = data.second;

        drawScatter(groups);
        sortByThirdDensity(groups);

        auto start = steady_clock::now();
        int ans = Algorithm::standard01Knapsack(cap, groups);
        auto end = steady_clock::now();
        double ms = duration<double, milli>(end - start).count();

        cout << "\n==== 运行结果 ====" << endl;
        cout << "背包容量: " << cap << endl;
        cout << "最大价值: " << ans << endl;
        cout << "运行时间: " << ms << "ms" << endl;

        saveResult(cap, ans, ms);
    }
    catch (exception& e) {
        cout << "错误: " << e.what() << endl;
    }
    return 0;
}
