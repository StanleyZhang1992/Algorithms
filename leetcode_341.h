#pragma once
/*
341. Flatten Nested List Iterator

Given a nested list of integers, implement an iterator to flatten it.

Each element is either an integer, or a list -- whose elements may also be integers or other lists.

Example 1:

Input: [[1,1],2,[1,1]]
Output: [1,1,2,1,1]
Explanation: By calling next repeatedly until hasNext returns false,
             the order of elements returned by next should be: [1,1,2,1,1].
Example 2:

Input: [1,[4,[6]]]
Output: [1,4,6]
Explanation: By calling next repeatedly until hasNext returns false,
             the order of elements returned by next should be: [1,4,6].
*/

/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
#include<stack>
#include<vector>

using namespace std;

/*
need to understand the new data structure NestedInteger
use stack to store the elements in reverse order and implement iterator
*/
class NestedIterator {
public:
    stack<NestedInteger> stk;
    NestedIterator(vector<NestedInteger>& nestedList) {
        for (auto iter = nestedList.rbegin(); iter != nestedList.rend(); ++iter) {
            stk.push(*iter);
        }
    }

    int next() {
        NestedInteger cur = stk.top();
        stk.pop();
        return cur.getInteger();
    }

    bool hasNext() {
        while (!stk.empty()) {
            NestedInteger cur = stk.top();
            if (cur.isInteger())
                return true;
            stk.pop();
            vector<NestedInteger> curList = cur.getList();
            for (auto iter = curList.rbegin(); iter != curList.rend(); ++iter) {
                stk.push(*iter);
            }
        }
        return false;
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */