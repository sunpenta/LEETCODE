#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
int totalFruit(vector<int>& fruits);

int main()
{
    vector<int> fruits{1,2,3,2,2};
    int res=totalFruit(fruits);
    cout << res << endl; // output:4
    return 0;
}

int totalFruit(vector<int>& fruits)
{
    int n=fruits.size(), i=0,j=0;
    unordered_map<int,int> count;
    for (; j<n; j++)
    {
        count[fruits[j]]++;
        if (count.size()>2)
        {
            if (--count[fruits[i]]==0)
                count.erase(fruits[i]);
            i++;
        }
    }
    return j-i;
}