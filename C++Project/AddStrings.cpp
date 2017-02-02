/*
@Problem: https://leetcode.com/problems/add-strings/
O(n) solution to add two strings represented as numbers and return the sum.
*/
class Solution {
public:
    string addStrings(string num1, string num2) {
    int carry=0;
    int i = num1.size()-1;
    int j = num2.size()-1;
    int strLen = max(i+1,j+1);
    string result(strLen+1,'0');
    while(true)
    {
        if(i<0 && j<0) break;
        int sum = returnVal(num1,i) + returnVal(num2,j) + carry;
        i--;j--;
        carry = sum/10;
        result[strLen] = sum%10 + '0';
        strLen--;
    }
    if(carry>0) result[strLen]=carry + '0';
    if(result.size() > 1 && result[0]=='0') return result.substr(1);
    return result;
    }
private: 
int returnVal(string num,int i)
{
    if(i<0 || i>=num.size()) return 0;
    return num[i]-'0';
}
};