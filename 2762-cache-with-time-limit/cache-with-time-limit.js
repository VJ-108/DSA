var TimeLimitedCache = function() {
    
};

/** 
 * @param {number} key
 * @param {number} value
 * @param {number} duration time until expiration in ms
 * @return {boolean} if un-expired key already existed
 */
TimeLimitedCache.prototype.set = function(key, value, duration) {
    let newValue = value + "-" + (Date.now() + duration);
    if (key in this && this[key].split("-")[1] > Date.now()){
        this[key] = newValue;
        return true;
    }
    this[key] = newValue;
    return false;
};

/** 
 * @param {number} key
 * @return {number} value associated with key
 */
TimeLimitedCache.prototype.get = function(key) {
    if (key in this && this[key].split("-")[1] > Date.now()) return Number(this[key].split("-")[0]);
    return -1;
};

/** 
 * @return {number} count of non-expired keys
 */
TimeLimitedCache.prototype.count = function() {
    let cnt = 0; 
    for (let key in this){
        if (this.hasOwnProperty(key)){
            if (this[key].split("-")[1] > Date.now()) cnt++;
        }
    }
    return cnt;
};

/**
 * const timeLimitedCache = new TimeLimitedCache()
 * timeLimitedCache.set(1, 42, 1000); // false
 * timeLimitedCache.get(1) // 42
 * timeLimitedCache.count() // 1
 */