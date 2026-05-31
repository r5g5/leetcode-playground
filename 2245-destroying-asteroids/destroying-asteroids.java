class Solution {
    public boolean asteroidsDestroyed(int mass, int[] asteroids) {
        Arrays.sort(asteroids);
        long sum = mass;
        for (int asteroid : asteroids) {
            if (sum >= asteroid) {
                sum += asteroid;
                continue;
            }
            return false;
        }
        return true;
    }
}