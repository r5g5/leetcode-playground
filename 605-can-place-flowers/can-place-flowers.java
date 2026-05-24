class Solution {
    public boolean canPlaceFlowers(int[] flowerbed, int n) {
        var canPlantCnt = 0;
        for (int i = 0, sz = flowerbed.length; i < sz; i++) {
            if (flowerbed[i] == 0) {
                var emptyLeft = (i == 0) || (flowerbed[i - 1] == 0);
                var emptyRight = (i == sz - 1) || (flowerbed[i + 1] == 0);
                if (emptyLeft && emptyRight) {
                    flowerbed[i] = 1;
                    canPlantCnt++;
                }
            }
        }
        return canPlantCnt >= n;
    }
}