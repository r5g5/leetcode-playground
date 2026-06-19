class Solution {
    public int largestAltitude(int[] gain) {
        int h = 0;
        int highestAltitude = 0;
        for (int g : gain) {
            h += g;
            highestAltitude = Math.max(highestAltitude, h);
        }
        return highestAltitude;
    }
}