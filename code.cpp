#include <iostream>
#include <vector>
using namespace std;

string mergeAlternately(string word1, string word2) {
     int n1=word1.length(), n2=word2.length();
     string s="";
     for (int i=0, j=0; i<n1 && j<n2; ++i, ++j)
     {
          if (i==n1-1) 
               s+=word2[j];
          else if (j==n2-1) 
               s+=word1[i];
          else
          {
               if ((word1[i]-'a')<=(word2[j]-'a'))
               {
                    s+=word1[i]; s+=word2[j];
               }
               else
                    s+=word2[j];s+=word1[i];
          }
     } 
     return s;     
}
int main()
{    
     string word1="abc"; string word2="bcd";
     string s=mergeAlternately(word1, word2);
     cout<<s<<endl;
     return 0;
}