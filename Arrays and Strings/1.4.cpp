//Que:- Check if a string can be permutated into a pallindrome
#include <bits/stdc++.h>

using namespace std;

bool permutableToPalindrome(string s) {
    if (s.empty())
        return false;
    if (s.length() % 2 == 0) {
        map<char, int> map;
        for (auto i : s)
            map[i]++;
        for (auto i : map)
            if (i.second != 2)
                return false;
            else
                return true;
    } else {
        map<char, int> map;
        int c = 0;
        for (auto i : s)
            map[i]++;
        for (auto i : map) {
            if (i.second % 2 != 0)
                c++;
        }
        return c == 1;
    }
    return false;
}

int main() {
    string s = "";
    cout << permutableToPalindrome(s);

    return 0;
}