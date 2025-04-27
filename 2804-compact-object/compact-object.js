/**
 * @param {Object|Array} obj
 * @return {Object|Array}
 */
var compactObject = function(obj,res=Array.isArray(obj) ? []: {}) {
    if (Array.isArray(obj)){
        for (let i=0;i<obj.length;i++){
            if (Array.isArray(obj[i]) || (typeof obj[i] === 'object' && obj[i] !== null)) res.push(compactObject(obj[i]));
            else if (obj[i]) res.push(obj[i]);
        }
    }else{
        for (let key in obj){
            if (Array.isArray(obj[key]) || (typeof obj[key] === 'object' && obj[key] !== null)) res[key] = compactObject(obj[key]);
            else if (obj[key]) res[key] = obj[key];
        }
    }
    return res;
};