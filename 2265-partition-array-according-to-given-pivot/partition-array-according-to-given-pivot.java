class Solution {
    public int[] pivotArray(int[] nums, int pivot) {
        final int n = nums.length;
        int[] ans = new int[n];
        int lessThanPivotCnt = 0, pivotElementsCnt = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] < pivot) {
                lessThanPivotCnt++;
            } else if (nums[i] == pivot) {
                pivotElementsCnt++;
            }
        }
        int i = lessThanPivotCnt;
        while (pivotElementsCnt-- > 0) {
            ans[i++] = pivot;
        }

        int j = i;
        i = 0;
        for (int k = 0; k < n; k++) {
            if (nums[k] == pivot) continue;
            if (nums[k] < pivot) {
                ans[i] = nums[k];
                i++;
            } else {
                ans[j] = nums[k];
                j++;
            }
        }
        return ans;
    }
}