class Solution {
    public int largestAltitude(int[] gain) {
        int highest = 0, alt = 0;
        for (int i = 0, n = gain.length; i < n; i++) {
            alt += gain[i];
            highest = Math.max(highest, alt);
            // System.out.println(highest);
        }
        return highest;
    }
}