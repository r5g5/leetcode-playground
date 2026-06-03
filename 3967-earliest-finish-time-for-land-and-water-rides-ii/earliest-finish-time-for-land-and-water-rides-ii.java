class Solution {
    private int solve(int[] firstTimes, int[] firstDuration, int[] secondTimes, int[] secondDuration) {
        int finish1 = Integer.MAX_VALUE;
        for (int i = 0; i < firstTimes.length; i++) {
            finish1 = Math.min(finish1, firstTimes[i] +  firstDuration[i]);
        }
        int finish = Integer.MAX_VALUE;
        for (int i = 0; i < secondTimes.length; i++) {
            finish = Math.min(finish, Math.max(secondTimes[i], finish1) + secondDuration[i]);
        }
        return finish;
    }
    public int earliestFinishTime(int[] landStartTime, int[] landDuration, int[] waterStartTime, int[] waterDuration) {
           return Math.min(solve(landStartTime, landDuration, waterStartTime, waterDuration),
                           solve(waterStartTime, waterDuration, landStartTime, landDuration));
    }
}