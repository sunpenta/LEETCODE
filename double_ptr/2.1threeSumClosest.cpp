// 最接近三数之和 -排序+双指针 l-16  -DFS/vector/2.1,2.2
// -1000<=nums[i]<=1000; -1e4<=target<=1e4
#include <bits/stdc++.h>
using namespace std;
int threeSumClosest(vector<int>&nums,int target);

int main()
{
    vector<int> nums = {-1, 2, 1, -4}; int target = 1; // 输入
    cout<<threeSumClosest(nums,target)<<endl; // 输出:2
    system("pause");
}

// 三数之和最接近目标值
int threeSumClosest(vector<int>&nums,int target)
{
    int n = nums.size();
    sort(nums.begin(), nums.end()); // 从小到大排序

    int best = 1e7; // 最接近目标值三数之和 
    // lamada表达式，无返回值，捕获所有引用
    auto update = [&](int cur)
    {
        if (abs(cur-target)<abs(best-target))
        {
            best = cur;
        }
    };

    // 遍历；i,j,k分别是第1，2，3个下标
    for (int i = 0; i < n - 1; i++)
    {       
        if (i > 0 && nums[i] == nums[i + 1]) // 保证和上一次枚举的元素不相等
            continue;
        int j = i + 1; int k = n - 1; // 左右指针
        int sum = nums[i] + nums[j] + nums[k]; // 当前三数之和
        update(sum);
        while (j < k)
        {
            if (sum == target) best=target;
            if (sum < target) // 小于target，移动 j
            {
                int j0 = j + 1;   
                while (j0 < k && nums[j0] == nums[j]) // 跳过相等元素
                    ++j0;
                j = j0;
            }
            else // 大于target，移动 k
            {               
                int k0 = k - 1;
                while (j < k0 && nums[k0] == nums[k]) // 跳过相等元素
                    --k0;
                k = k0;
            }
        }
    }
    return best;
}