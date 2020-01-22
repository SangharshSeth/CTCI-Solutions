#include <bits/stdc++.h>
#include <regex>
using namespace std;
//using std::regex
string URLifyRegex(string S, int L)
{
    if (L < S.length())
        S = S.substr(0, L);
    return regex_replace(S, regex(" "), "%20");
}
//inplace method
string URLify(string &S, int L)
{
    int lastIndex = 0;
    int spaceCount = 0;
    for (int i = 0; i < L; i++)
        if (S[i] == ' ')
            spaceCount++;
    lastIndex = L + spaceCount * 2;
    S = S.substr(0, lastIndex);
    for (int i = L - 1; i >= 0; i--)
    {
        if (S[i] == ' ')
        {
            S[lastIndex - 1] = '0';
            S[lastIndex - 2] = '2';
            S[lastIndex - 3] = '%';
            lastIndex = lastIndex - 3;
        }
        else
        {
            S[lastIndex - 1] = S[i];
            lastIndex--;
        }
    }
    return S;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string S = "this is sangharsh speaking      ";
    int L = 26;
    string x = URLify(S, L);
    cout << x;
    return 0;
}