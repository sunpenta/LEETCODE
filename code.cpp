#include <iostream>
#include <vector>
using namespace std;

string mergeAlternately(string word1, string word2) {
     int n1=word1.length(), n2=word2.length();
     string s="";
     int i=0, j=0;
     for (i=0, j=0; i<n1 && j<n2; ++i, ++j)
     {

          if (word1[i]<=word2[j])
          {
               s+=word1[i]; 
               s+=word2[j];
          }
          else
          {
               s+=word2[j];
               s+=word1[i];
          }
          
     } 
     while (i<n1) s+=word1[i++];
     while (j<n2) s+=word2[j++];
     return s;     
}
int main()
{    
     string word1="abc"; string word2="bcd";
     string s=mergeAlternately(word1, word2);
     string ss=""+'a'+'b';
     cout<<ss<<endl;
     return 0;
}