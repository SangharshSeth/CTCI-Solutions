/*
Que: Given an array of distinct integer values count the number of pairs of integers that have difference k.
example: A ={1,7,5,9,2,12,3} and K = 2
*/
//Bruteforce
#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int>> solveBruteforce(vector<int> &v, int k)
{
    vector<pair<int, int>> s;
    pair<int, int> current;
    for (int i = 0; i < v.size(); i++)
    {
        for (int j = 0; j < v.size(); j++)
        {
            if (abs(v[i] - v[j]) == k)
            {
                current = make_pair(v[j], v[i]);
                if (find(s.begin(), s.end(), current) != s.end())
                {
                    continue;
                }
                s.emplace_back(v[i], v[j]);
            }
        }
    }
    return s;
}
//Optimised Linear Solution
vector<pair<int, int>> solveLinear(vector<int> &v, int k){
    map<int,int>map;
    vector<pair<int, int>>s;
    for(int i = 0; i < v.size(); i++){
        map[v[i]] = i;
    }
    for(int & i : v){
        int c1 = (i - k);
        int c2 = (i + k);
        auto it1 = map.find(c1);
        auto it2 = map.find(c2);
        if(it1 != map.end()){
            s.emplace_back(i,it1->first);
        }
        if(it2 != map.end()){
            s.emplace_back(i,it2->first);
        }
    }
    return s;
}
//Test
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<int>v = {1,7,5,9,2,12,3};
    vector<pair<int,int>>result;
    int k = 2;
    result = solveLinear(v,k);
    for(auto i:result)
        cout << i.first <<" " << i.second << endl;


    return 0;
}

