class Solution {
    private static int min(int... args) {
        int ans = Integer.MAX_VALUE;
        for (int arg : args) {
            ans = Math.min(ans, arg);
        }
        return ans;
    }
    public int earliestFinishTime(int[] landStartTime, int[] landDuration, int[] waterStartTime, int[] waterDuration) {
        final int n = landDuration.length;
        final int m = waterDuration.length;

        int earliestTime = Integer.MAX_VALUE;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                // Land ride first
                int landTm = landStartTime[i] + landDuration[i];
                int finish1Tm =  Math.max(landTm, waterStartTime[j]) + waterDuration[j];

                // Water ride first
                int waterTm = waterStartTime[j] + waterDuration[j];
                int finish2Tm = Math.max(waterTm, landStartTime[i]) + landDuration[i];

                earliestTime = min(earliestTime, finish1Tm, finish2Tm);
            }
        }

        return earliestTime;


    }
}