#include <iostream>
#include "DataLoader.h"
#include "Sorter.h"
#include "Algorithm.h"

int main() {
    try {
        // 1. 读取数据
        auto data = DataLoader::LoadD01KPFile("data.txt");
        int capacity = data.first;
        auto groups = data.second;

        // 2. 按价值密度排序
        Sorter::sortByValueDensity(groups);

        // 3. 求解
        int greedyResult = Algorithm::greedySolve(capacity, groups);
        int dpResult = Algorithm::dpSolve(capacity, groups);

        // 4. 输出结果
        std::cout << "背包容量: " << capacity << std::endl;
        std::cout << "项集数量: " << groups.size() << std::endl;
        std::cout << "贪心算法结果: " << greedyResult << std::endl;
        std::cout << "动态规划结果: " << dpResult << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "错误: " << e.what() << std::endl;
        return 1;
    }
    return 0;
}
