#include <bits/stdc++.h>
using namespace std;
//i done this previously in codechef lunchtime
//no algorithm just did what the question asked
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int test;
    cin >> test;
    while (test--)
    {
        string s;
        string t;
        string temp;
        int count{0};
        char x;
        cin >> s;
        unordered_multimap<char, int> frequency;
        for (int i = 0; i < s.length(); i = i + count)
        {
            count = 0;
            x = s[i];
            int j = i;
            while (s[j] == x)
            {
                count++;
                j++;
            }
            frequency.insert({s[i], count});
        }
        for (auto it = frequency.begin(); it != frequency.end(); it++)
        {
            string temp(1, it->first);
            t += temp;
            t += to_string(it->second);
        }
        if (t.length() < s.length())
            cout << t << '\n';
        else
            cout << s << '\n';
    }

    return 0;
}