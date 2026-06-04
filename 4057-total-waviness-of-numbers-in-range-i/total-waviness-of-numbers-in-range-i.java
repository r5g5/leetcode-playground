class Solution {
    private int getWaviness(int num) {
        String s = Integer.toString(num);
        int wavinessCnt = 0;
        for (int i = 1; i < s.length() - 1; i++) {
            boolean isPeak = s.charAt(i) > s.charAt(i-1) && s.charAt(i) > s.charAt(i+1);
            boolean isValley = s.charAt(i) < s.charAt(i-1) && s.charAt(i) < s.charAt(i+1);
            if (isPeak || isValley)
                wavinessCnt++;
        }
        return wavinessCnt;
    }
    public int totalWaviness(int num1, int num2) {
        int total = 0;
        for (int num = num1; num <= num2; num++) {
            total += getWaviness(num);
        }
        return total;
    }
}