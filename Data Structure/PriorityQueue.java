class PriorityQueue {
    private Integer[] pq;
    private int n;

    public PriorityQueue(int capacity) {
        pq = new Integer[capacity+1];
    }

    public void insert(Integer m) {
        pq[++n] = m;
        swim(n);
    }

    public Integer maxDel() {
        Integer maxP = pq[1];
        pq[1] = pq[n--];
        pq[n+1] = null; // loitering
        sink(1);
        return maxP;    
    }

    public boolean isEmpty() {
        return n == 0;
    }

    public Integer size() {
        return n;
    }

    private void exch(int i, int j) {
        int temp = pq[i];
        pq[i] = pq[j];
        pq[j] = temp;
    }

    private void swim(int k) {
        while(k > 1 && pq[k/2] < pq[k]) {
            exch(k, k/2);
            k = k/2;
        }
    }

    private void sink(int k) {
        while(2*k <= n) {
            int j = 2*k;
            if(j < n && pq[j] < pq[j+1]) j++;
            if(pq[k] >= pq[j]) break;
            exch(k ,j);
            k = j;
        }
    }

    public static void main(String args[]) {
        PriorityQueue pQueue = new PriorityQueue(10);

        pQueue.insert(10);
        pQueue.insert(9);
        pQueue.insert(7);
        pQueue.insert(11);

        assert pQueue.maxDel() == 11;

        pQueue.insert(15);
        pQueue.insert(16);
        pQueue.insert(1);

        assert pQueue.maxDel() == 16;
    }
}