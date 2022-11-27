/*
Problem Name: 190. Reverse Bits
Problem Link: https://leetcode.com/problems/reverse-bits/
*/

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t temp=0,left=1, right=1 << 31, val1, val2;
        for(int i=0; i<16; i++){
            if (left&n){
                temp |= right;
            }
            
            if (right&n){
                temp |= left;
            }
            left <<= 1;
            right >>= 1;
        }
        return temp;
    }
};
