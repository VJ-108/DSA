class ProductOfNumbers {
public:
    vector<int> vec;
    ProductOfNumbers() {
        
    }
    
    void add(int num) {
        vec.push_back(num);
    }
    
    int getProduct(int k) {
        int mult = 1,i=vec.size()-1;
        while(k>0 && i>=0){
            if (vec[i]==0) return 0;
            mult *= vec[i];
            i--;
            k--;
        }
        return mult;
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */