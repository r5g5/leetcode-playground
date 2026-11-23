class ProductOfNumbers {
    vector<int> inStreams;
public:
    ProductOfNumbers() {
        inStreams.reserve(4096);
    }
    
    void add(int num) {
        inStreams.push_back(num); // TC: O(1) [ considering we have already initialized enough memory at initialization time, there shouldn't be any re-allocation happeing later on]
    }
    
    int getProduct(int k) {
        int product = 1;
        for (int i = inStreams.size() - 1, j = 0; j < k; j++, i--) {
            product *= inStreams[i];
        }
        return product; // TC: O(k)
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */