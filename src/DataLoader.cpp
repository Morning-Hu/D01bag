#include "DataLoader.h"
#include <fstream>
#include <sstream>
#include <stdexcept>

// 校验一行数据是否为 6 个有效整数（w1,v1,w2,v2,w3,v3）
bool DataLoader::IsValidLine(const std::string& line) {
    std::istringstream iss(line);
    int val;
    int count = 0;
    while (iss >> val) {
        count++;
    }
    return count == 6;
}

// 读取 D01KP 数据文件
std::pair<int, std::vector<ItemGroup>> DataLoader::LoadD01KPFile(const std::string& filePath) {
    std::ifstream file(filePath);
    if (!file.is_open()) {
        throw std::runtime_error("无法打开文件：" + filePath);
    }

    int capacity;
    if (!(file >> capacity)) {
        throw std::runtime_error("文件格式错误：第一行必须是背包容量");
    }

    std::vector<ItemGroup> groups;
    std::string line;
    std::getline(file, line); // 跳过容量行的换行符

    while (std::getline(file, line)) {
        if (line.empty()) continue;
        if (!IsValidLine(line)) {
            throw std::runtime_error("无效数据行：" + line);
        }

        std::istringstream iss(line);
        ItemGroup group;
        iss >> group.w1 >> group.v1 >> group.w2 >> group.v2 >> group.w3 >> group.v3;
        groups.push_back(group);
    }

    file.close();
    return {capacity, groups};
}
