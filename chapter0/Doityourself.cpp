/*
Que:Given a smaller string s and a bigger string b design an algorithm to find all permutations of the shorter string within the longer one.Print the location of each permutation.
*/
#include <bits/stdc++.h>
using namespace std;
bool isPermutation(string s, string t)
{
    sort(s.begin(), s.end());
    sort(t.begin(), t.end());
    return s == t;
}
//slow bruteforce kinda
vector<int> findAnagrams(string s, string p)
{
    vector<int> result;
    if (p.length() > s.length())
        return result;
    int length = p.length();
    for (int i = 0; i <= s.length() - length; i++)
    {
        string substring = s.substr(i, length);
        if (isPermutation(substring, p))
            result.push_back(i);
    }
    return result;
}
//Linear solution
vector<int> findAnagrams(string s, string p)
{
    vector<int> result;
    vector<int> small(26, 0);
    vector<int> big(26, 0);
    if (s.size() < p.size())
        return result;

    for (int i = 0; i < p.size(); ++i)
    {
        small[p[i] - 'a']++;
        big[s[i] - 'a']++;
    }
    if (small == big)
        result.push_back(0);
    for (int i = p.size(); i < s.size(); ++i)
    {
        big[s[i] - 'a']++;
        big[s[i - p.size()] - 'a']--;
        if (small == big)
            result.push_back(i - p.size() + 1);
    }

    return result;
}
int main()
{
    string s = "abcbdgfbcbancbcbabbcbacbcba";
    string p = "abcb";
    vector<int> result = findAnagrams(s, p);
    for (auto i : result)
        cout << i << endl;

    return 0;
}