/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet(); 初始化为所有正整数num⋿[1,1000]
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */
#include <set>
class SmallestInfiniteSet
{
    set<int> nums; // set内元素自动排序
public:
    SmallestInfiniteSet()
    {
        for (int i=1; i<1000; ++i)
            nums.insert(i);
    }
    ~SmallestInfiniteSet();
};
