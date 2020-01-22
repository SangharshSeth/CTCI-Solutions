#include <bits/stdc++.h>
using namespace std;
bool isPermutation(string s1, string s2)
{
    unordered_map<char, int> map;
    for (int i = 0; i < s1.length(); i++)
    {
        map[s1[i]]++;
        map[s2[i]]--;
    }
    for (auto i : map)
        if (i.second != 0)
            return false;
    return true;
}
//sorting based slow solution
/*
bool isPermutation(string s, string t)
{
    sort(s.begin(), s.end());
    sort(t.begin(), t.end());
    return s == t;
} 
*/
int main()
{
    string s = "azcd", t = "bcda";
    cout << isPermutation(s, t);
    return 0;
}