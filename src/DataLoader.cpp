#include "DataLoader.h"
#include <fstream>
#include <sstream>
#include <stdexcept>

bool DataLoader::IsValidLine(const std::string& line) {
    std::istringstream iss(line);
    int val;
    int count = 0;
    while (iss >> val) {
        count++;
    }
    return count == 6;
}

std::pair<int, std::vector<ItemGroup>> DataLoader::LoadD01KPFile(const std::string& filePath) {
    std::ifstream file(filePath);
    if (!file.is_open()) {
        throw std::runtime_error("无法打开文件");
    }

    int capacity;
    if (!(file >> capacity)) {
        throw std::runtime_error("文件格式错误");
    }

    std::vector<ItemGroup> groups;
    std::string line;
    std::getline(file, line);

    while (std::getline(file, line)) {
        if (line.empty()) continue;
        if (!IsValidLine(line)) continue;

        std::istringstream iss(line);
        ItemGroup g;
        iss >> g.w1 >> g.v1 >> g.w2 >> g.v2 >> g.w3 >> g.v3;
        groups.push_back(g);
    }

    return {capacity, groups};
}
