/**
 * @param {Array} arr1
 * @param {Array} arr2
 * @return {Array}
 */
var join = function(arr1, arr2) {
    let res = [];
    let i=0,j=0;
    arr1.sort((a, b) => a.id - b.id);
    arr2.sort((a, b) => a.id - b.id);
    while (i < arr1.length && j < arr2.length) {
        if (arr1[i].id < arr2[j].id) {
            res.push(arr1[i]);
            i++;
        } else if (arr1[i].id > arr2[j].id) {
            res.push(arr2[j]);
            j++;
        } else {
            let newObj = { ...arr1[i], ...arr2[j] };
            res.push(newObj);
            i++;
            j++;
        }
    }
    while(i<arr1.length){
        res.push(arr1[i]);
        i++;
    }
    while(j<arr2.length){
        res.push(arr2[j]);
        j++;
    }
    return res;
};