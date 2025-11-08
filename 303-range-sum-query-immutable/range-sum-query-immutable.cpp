class NumArray {
private:
    vector<int> prefixSum;
public:
    NumArray(vector<int>& nums): prefixSum(nums) {
        for (int i = 1; i < prefixSum.size(); i++) {
            prefixSum[i] += prefixSum[i-1];
        }
    }
    
    int sumRange(int left, int right) {
        if (left <= right) {
            int rightSum = prefixSum[right];
            int leftSum = 0;
            if (left != 0) {
                leftSum = prefixSum[left-1];
            }
            return rightSum - leftSum;
        }
        return -1;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */