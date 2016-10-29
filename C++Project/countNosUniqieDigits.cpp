/*
@Problem: https://leetcode.com/problems/count-numbers-with-unique-digits/
@author: Meera Ramesh
@email: meekar67@gmail.com
*/
class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        if(n==0) return 1;
        int result = 10;
        int uniqueNumber = 9;
        int availableNumber = 9;
        while(n-- > 1 && availableNumber > 0)
        {
            uniqueNumber = uniqueNumber * availableNumber;
            result = result + uniqueNumber;
            availableNumber--;
        }
        return result;
    }
};