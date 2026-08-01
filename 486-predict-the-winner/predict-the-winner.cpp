class Solution {
private:
    bool solve(const vector<int>& nums, int score1, int score2, int idx, int jdx, bool isP1turn) {

        if (idx > jdx) {
            return score1 >= score2;
        }

        int front = nums[idx];
        int last  = nums[jdx];

        bool ans;

        if (isP1turn) {
            ans = false;
            // option 1: take from the front
            ans |= solve(nums, score1 + front, score2, idx + 1, jdx, !isP1turn);
            // option 2: take from the back
            ans |= solve(nums, score1 + last, score2, idx, jdx - 1, !isP1turn);
        } else {
            ans = true;
            ans &= solve(nums, score1, score2 + front, idx + 1, jdx, !isP1turn);
            ans &= solve(nums, score1, score2 + last, idx, jdx - 1, !isP1turn);
        }

        return ans;
    }
public:
    bool predictTheWinner(vector<int>& nums) {
        return solve(nums, 0, 0, 0, nums.size() - 1, true);
    }
};