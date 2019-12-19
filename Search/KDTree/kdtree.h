#include <vector>
#include <iostream>
#include <memory>

struct Data
{
    int x;
    int y;
    Data(int val1, int val2) : x(val1), y(val2) {}
};

bool CompareX(Data d1, Data d2)
{
    return d1.x < d2.x;
}
bool CompareY(Data d1, Data d2)
{
    return d1.y < d2.y;
}

template <typename T>
struct treeNode
{
    T data;
    int split;
    std::shared_ptr<treeNode> left;
    std::shared_ptr<treeNode> right;
    treeNode(T value, int id) : data(value), split(id), left(nullptr), right(nullptr) {}
};

class kdtree
{
private:
    std::shared_ptr<treeNode<Data>> root_;

public:
    kdtree(std::shared_ptr<treeNode<Data>> val) : root_(val) {}
    kdtree() : root_(nullptr) {}
    void BuildKDTree(std::vector<Data> val);
    void SerachNearest(Data target, Data &nearestpoint, double &distance);
    void ChooseSplit(std::vector<Data> val) ~kdtree();
};
