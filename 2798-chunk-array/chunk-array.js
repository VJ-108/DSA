/**
 * @param {Array} arr
 * @param {number} size
 * @return {Array}
 */
var chunk = function(arr, size) {
    if (arr.length == 0) return [];
    if (size >= arr.length) return [arr];
    let result = [];
    let i=0;
    while(i<arr.length){
        result.push(arr.slice(i, i+size));
        i += size;
    }
    return result;
};
