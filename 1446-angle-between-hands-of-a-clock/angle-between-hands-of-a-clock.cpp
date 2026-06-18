class Solution {
public:
    double angleClock(int hour, int minutes) {
        // hour hand moves from 0 - 11 = 30H (360 / 12)
        // also, in that one segment, it has 60 minutes = 30 / 60 = 0.5M
        // minutes hand moves from 0 - 59 = 360 / 60 = 6M
        // difference = 30H + 0.5M - 6M = 30H - 5.5M
        double degree = abs(30 * hour - 5.5 * minutes);
        return min(360 - degree, degree);
    }
};