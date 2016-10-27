/*
@Problem: https://leetcode.com/problems/restore-ip-addresses/
@Author: Meera Ramesh   
@email:  meekar67@gmail.com
*/
class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> result;
        int len = s.size();
        for(int a=1;a<=3;a++)
        for(int b=1;b<=3;b++)
        for(int c=1;c<=3;c++)
        for(int d=1;d<=3;d++)
        if(a+b+c+d == s.size())
        {
            auto A = stoi(s.substr(0,a));
            auto B = stoi(s.substr(a,b));
            auto C = stoi(s.substr(a+b,c));
            auto D = stoi(s.substr(a+b+c,d));
            if(A<=255 && B<=255 && C<=255 && D<=255)
            {
            auto res = to_string(A) + '.' + to_string(B) + '.' + to_string(C) + '.' + to_string(D);
            if((res.size() - 3) == s.size()) result.push_back(res);
            }
        }
        return result;
    }
};