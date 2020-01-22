#include <bits/stdc++.h>
using namespace std;
//Naive solution
bool isUnique(string s)
{
    unordered_map<char, int> map;
    for (auto i : s)
        map[i]++;
    for (auto i : map)
    {
        if (i.second > 1)
            return false;
    }
    return true;
}
//In place solution
bool isUniqueLinear(string s){
    
}
int main()
{
    string s = "abcd";
    cout << isUnique(s);
    return 0;
}