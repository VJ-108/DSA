class ProductOfNumbers {
public:
    vector<int> vec;
    int mult=1;
    ProductOfNumbers() {
        
    }
    
    void add(int num) {
        if (num==0){
            vec.clear();
            mult = 1;
        }
        else{
            mult*=num;
            vec.push_back(mult);
        }
    }
    
    int getProduct(int k) {
        if (vec.size() < k) return 0;
        if (vec.size() == k) return vec.back();
        return vec.back() / vec[vec.size() - k - 1];
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */