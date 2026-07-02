class Solution {
    class Pair {
        private int first;
        private int second;

        public Pair(int f, int s) {
            first = f;
            second = s;
        }

        public int getFirst() {
            return first;
        }

        public int getSecond() {
            return second;
        }
    }
    public boolean findSafeWalk(List<List<Integer>> grid, int health) {
        final int m = grid.size();
        final int n = grid.get(0).size();

        int[][] dist = new int[m][n];

        for (int i = 0; i < m; i++)
            Arrays.fill(dist[i], Integer.MAX_VALUE);

        Queue<Pair> q = new ArrayDeque<Pair>();

        dist[0][0] = grid.get(0).get(0); //[0];

        q.offer(new Pair(0, 0));

        List<Integer> dx = List.of(-1, 1, 0, 0);
        List<Integer> dy = List.of(0, 0, -1, 1);

        while (!q.isEmpty()) {
            Pair cord = q.poll();
            
            for (int i = 0; i < dx.size(); i++) {
                int newX = dx.get(i) + cord.getFirst();
                int newY = dy.get(i) + cord.getSecond();

                if ((newX >= 0) && (newX < m) && (newY >= 0) && (newY < n)) {
                    if (dist[newX][newY] > dist[cord.getFirst()][cord.getSecond()] + grid.get(newX).get(newY)) {
                        dist[newX][newY] = dist[cord.getFirst()][cord.getSecond()] + grid.get(newX).get(newY);
                        q.offer(new Pair(newX, newY));
                    }
                }
            }
        }

        return dist[m-1][n-1] < health;

    }
}