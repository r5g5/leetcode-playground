class SmallestInfiniteSet {
    static constexpr int _size = 1001;
private:
    vector<int> _container;
public:
    SmallestInfiniteSet() {
        _container.resize(_size);
        iota(_container.begin(), _container.end(), 1);
    }
    
    int popSmallest() {
        for (int i = 0; i < _size; i++) {
            if (_container[i] != -1) {
                _container[i] = -1;
                return i+1;
            }
        }
        return _size-1;
    }
    
    void addBack(int num) {
        int idx = num - 1;
        _container[idx] = num;
        return;
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */