#include<bits/stdc++.h>

using namespace std;

bool isRotatedSubstring(string s1,string s2){
    int length = s1.length();
    if(length == s2.length() and length > 0){
        string big = s1 + s1;
        return big.find(s2);
    }
    return false;
}

int main()
{
 string s1 = "sangharsh";
 string s2 = "apple";
 cout << isRotatedSubstring(s1,s2);

  return 0;
}