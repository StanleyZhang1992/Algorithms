#pragma once
/*
146. LRU Cache

Design and implement a data structure for Least Recently Used (LRU) cache. It should support the following operations: get and put.

get(key) - Get the value (will always be positive) of the key if the key exists in the cache, otherwise return -1.
put(key, value) - Set or insert the value if the key is not already present. When the cache reached its capacity, it should invalidate the least recently used item before inserting a new item.

The cache is initialized with a positive capacity.

Follow up:
Could you do both operations in O(1) time complexity?

Example:

LRUCache cache = new LRUCache( 2 );

cache.put(1, 1);
cache.put(2, 2);
cache.get(1);       // returns 1
cache.put(3, 3);    // evicts key 2
cache.get(2);       // returns -1 (not found)
cache.put(4, 4);    // evicts key 1
cache.get(1);       // returns -1 (not found)
cache.get(3);       // returns 3
cache.get(4);       // returns 4
*/
#include<unordered_map>

using namespace std;

/*
use doubly linked list as the internal data structure to store nodes
use addNode and deleteNode functions to achieve LRU updates
*/
class LRUCache {
public:
    class Node {
    public:
        int key;
        int val;
        Node* prev;
        Node* next;
        Node() {
            key = -1;
            val = -1;
            prev = nullptr;
            next = nullptr;
        }
        Node(int k, int value) {
            key = k;
            val = value;
            prev = nullptr;
            next = nullptr;
        }
    };
    Node* dummyHead;
    Node* dummyTail;
    unordered_map<int, Node*> lookup;
    int cap;
    int size;

    LRUCache(int capacity) {
        dummyHead = new Node();
        dummyTail = new Node();
        dummyHead->next = dummyTail;
        dummyTail->prev = dummyHead;
        cap = capacity;
        size = 0;
    }

    int get(int key) {
        if (lookup.count(key)) {
            Node* curNode = lookup[key];
            deleteNode(curNode);
            addFront(curNode);
            return curNode->val;
        }
        else {
            return -1;
        }
    }

    void put(int key, int value) {
        if (lookup.count(key)) {
            Node* curNode = lookup[key];
            curNode->val = value;
            deleteNode(curNode);
            addFront(curNode);
        }
        else {
            if (size < cap) {
                Node* newNode = new Node(key, value);
                addFront(newNode);
            }
            else {
                Node* newNode = new Node(key, value);
                deleteTail();
                addFront(newNode);
            }
        }
    }

    void addFront(Node* node) {
        size += 1;
        node->next = dummyHead->next;
        node->prev = dummyHead;
        dummyHead->next = node;
        node->next->prev = node;
        lookup.insert({ node->key, node });
    }

    void deleteNode(Node* curNode) {
        size -= 1;
        curNode->prev->next = curNode->next;
        curNode->next->prev = curNode->prev;
        lookup.erase(curNode->key);
    }

    void deleteTail() {
        Node* node = dummyTail->prev;
        deleteNode(node);
    }

};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */