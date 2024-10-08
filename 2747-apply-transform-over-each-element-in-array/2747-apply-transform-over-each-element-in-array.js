/**
 * @param {number[]} arr
 * @param {Function} fn
 * @return {number[]}
 */
var map = function(arr, fn) {
    let new_array = [];
    for (let i = 0; i < arr.length; i++) {
        new_array[i] = fn(arr[i], i); 
    }
    return new_array;
};