class Solution {
public:
    int dominantIndex(vector<int>& nums) {

        int largest = nums[0];
        int index = 0;

        for(int i = 1; i < nums.size(); i++) {

            if(nums[i] > largest) {
                largest = nums[i];
                index = i;
            }
        }
        
        for(int i = 0; i < nums.size(); i++) {

            if(i != index && largest < 2 * nums[i]) {
                return -1;
            }
        }

        return index;
    }
};