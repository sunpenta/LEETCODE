/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet(); 初始化为所有正整数num⋿[1,1000]
 * int param_1 = obj->popSmallest(); 移除并返回集合内的最小值
 * obj->addBack(num); 若集合不存在num，加入集合
 */
#include <set>
class SmallestInfiniteSet
{
    set<int> nums; // set元素自动排序
public:
    SmallestInfiniteSet()
    {
        for (int i=1; i<1000; ++i)
            nums.insert(i);
    }
    int popSmallest()
    {
        int smallest;
        if (!nums.empty())
        {
            smallest=*nums.begin();
            nums.erase(nums.begin());
        }
        return smallest;
    }
    addBack(int num)
    {
        if (!nums.count(num))
            nums.insert(num);
    }
};
