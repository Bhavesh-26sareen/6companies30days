// Ques Find max 10 numbers in a list having 10M(10^7) entries.
// At first see what I am able to think is that we can store in the arr and then apply sorting
// which will take O(n*logn) time and O(10^7) space

// Another Approach is that we can use min heap Data Structure of size 10, like firtly we will store first 10 numbers in the min heap
// then for 11th element we will compare it with the minimum of those 10 numbers which is stored in min_heap which is min_heap top() element
// then if 11th element > min_heap top() element then 11th element may be the potential element so we remove the top() element
// and push the 11th number
// This way after iterating through the 10M entries in last we will have max 10 numbers in the heap
// TC O(2*n*logn) ~= O(n*logn)  and SC O(10)~=O(1) ;