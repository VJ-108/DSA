/**
 * @param {Function} fn
 * @return {Object}
 */
Array.prototype.groupBy = function(fn) {
    let obj = {};
    for (let i=0;i<this.length;i++){
        let temp = fn(this[i]);
        if (temp in obj) obj[temp].push(this[i]);
        else obj[temp] = [this[i]];
    }
    return obj;
};

/**
 * [1,2,3].groupBy(String) // {"1":[1],"2":[2],"3":[3]}
 */