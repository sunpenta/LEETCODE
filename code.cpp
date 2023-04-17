#include <iostream>
#include <vector>
using namespace std;

int numWays(vector<string>& words, string target) {
     int n = target.length(), m=words[0].size(), mod = 1e9 + 7;
     vector<long> res(n + 1); // ways to form i-first characters
     res[0] = 1;
     for (int i = 0; i < m; ++i) {
          vector<int> count(26);
          for (auto& w : words)
               count[w[i] - 'a']++;
          for (int j = n - 1; j >= 0; --j) {
               res[j + 1] += res[j] * count[target[j] - 'a'] % mod;
          }
     }
     return res[n] % mod;
}
int main()
{    
     vector<string> words = {"acca","bbbb","caca"}; string target = "aba";
     cout<<numWays(words, target)<<endl;
     return 0;
}