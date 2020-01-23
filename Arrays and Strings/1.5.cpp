#include <bits/stdc++.h>

using namespace std;

bool areOneAway(const string &s1, const string &s2) {
    int l1 = s1.length();
    int l2 = s2.length();
    if (s1 == s2)
        return true;
    int counter = 0;
    if (abs(l1 - l2) > 1)
        return false;
    if (l1 == l2) {
        bool mismatchfound = false;
        for(int i = 0; i < l1; i++){
            if(s1[i] != s2[i]){
                if(mismatchfound)
                return false;
                else
                mismatchfound = true;
            }
        }
        return true;
    }
    if (l1 != l2) {
        string small, big;
        int ptr1 = 0, ptr2 = 0;
        if (l1 > l2) {
            small = s2;
            big = s1;
        } else {
            small = s1;
            big = s2;
        }
        while (ptr2 < big.length() and ptr1 < small.length()) {
            if (big[ptr2] != small[ptr1]) {
                if (ptr1 != ptr2)
                    return false;
                ptr2++;
            } else {
                ptr1++;
                ptr2++;
            }
        }
        return true;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s1, s2;
    cin >> s1 >> s2;
    cout << areOneAway(s1, s2);

    return 0;
}