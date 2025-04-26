/**
 * @param {Promise} promise1
 * @param {Promise} promise2
 * @return {Promise}
 */
var addTwoPromises = async function(promise1, promise2) {
    let temp1 = await promise1;
    let temp2 = await promise2;

    // return new Promise(resolve => resolve(temp1 + temp2));
    return temp1 + temp2;
};

/**
 * addTwoPromises(Promise.resolve(2), Promise.resolve(2))
 *   .then(console.log); // 4
 */