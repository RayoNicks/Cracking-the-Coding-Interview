class Solution {
public:
    int convertInteger(int A, int B) {
        int count = 0;
        for(unsigned int r = A ^ B; r != 0; r &= r - 1)
        {
            count++;
        }
        return count;
    }
};
