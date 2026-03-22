#ifndef DATALOADER_H
#define DATALOADER_H

#include <vector>
#include <string>

// 项集结构体：存储每组3个物品的重量和价值
struct ItemGroup
{
    int w1; // 第一个物品重量
    int v1; // 第一个物品价值
    int w2; // 第二个物品重量
    int v2; // 第二个物品价值
    int w3; // 第三个物品重量
    int v3; // 第三个物品价值
};

// 数据读取类：负责读取D{0-1}KP数据集文件
class DataLoader
{
public:
    // 静态方法：读取D01KP数据文件
    // 参数：filePath - 文件路径
    // 返回：pair<int, vector<ItemGroup>> - 第一个元素是背包容量，第二个是项集列表
    static std::pair<int, std::vector<ItemGroup>> LoadD01KPFile(const std::string& filePath);

private:
    // 私有方法：校验一行数据是否有效（是否为6个整数）
    static bool IsValidLine(const std::string& line);
};

#endif // DATALOADER_H
