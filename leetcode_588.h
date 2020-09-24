#pragma once
/*
588. Design In-Memory File System

Design an in-memory file system to simulate the following functions:

ls: Given a path in string format. If it is a file path, return a list that only contains this file's name. If it is a directory path, return the list of file and directory names in this directory. Your output (file and directory names together) should in lexicographic order.

mkdir: Given a directory path that does not exist, you should make a new directory according to the path. If the middle directories in the path don't exist either, you should create them as well. This function has void return type.

addContentToFile: Given a file path and file content in string format. If the file doesn't exist, you need to create that file containing given content. If the file already exists, you need to append given content to original content. This function has void return type.

readContentFromFile: Given a file path, return its content in string format.



Example:

Input:
["FileSystem","ls","mkdir","addContentToFile","ls","readContentFromFile"]
[[],["/"],["/a/b/c"],["/a/b/c/d","hello"],["/"],["/a/b/c/d"]]

Output:
[null,[],null,null,["a"],"hello"]

Explanation:
filesystem


Note:

You can assume all file or directory paths are absolute paths which begin with / and do not end with / except that the path is just "/".
You can assume that all operations will be passed valid parameters and users will not attempt to retrieve file content or list a directory or file that does not exist.
You can assume that all directory names and file names only contain lower-case letters, and same names won't exist in the same directory.
*/
#include<unordered_map>
#include<vector>
#include<string>
#include<queue>
#include<sstream>

using namespace std;

class FileSystem {
public:
    class Dir {
    public:
        unordered_map<string, Dir*> dirs;
        unordered_map<string, string> files;
    };

    Dir* root;

    FileSystem() {
        root = new Dir();
    }

    vector<string> ls(string path) {
        Dir* curDir = root;
        vector<string> names;

        queue<string> q;
        if (path != "/") {
            stringstream ss(path);
            string token;
            vector<string> dirs;
            while (std::getline(ss, token, '/')) {
                q.push(token);
            }
            q.pop();
            while (q.size() > 1) {
                string cur = q.front();
                q.pop();
                if (curDir->dirs.count(cur)) {
                    curDir = curDir->dirs[cur];
                }
            }
        }

        if (q.size() > 0) {
            string last = q.front();
            if (curDir->dirs.count(last)) {
                curDir = curDir->dirs[last];
            }
            else {
                return vector<string>{ {last}};
            }
        }

        for (auto p : curDir->dirs) {
            names.push_back(p.first);
        }
        for (auto p : curDir->files) {
            names.push_back(p.first);
        }
        std::sort(names.begin(), names.end());
        return names;
    }

    void mkdir(string path) {
        Dir* curDir = root;

        queue<string> q;
        stringstream ss(path);
        string token;
        vector<string> dirs;
        while (std::getline(ss, token, '/')) {
            q.push(token);
        }
        q.pop();
        while (!q.empty()) {
            string cur = q.front();
            q.pop();
            if (curDir->dirs.count(cur)) {
                curDir = curDir->dirs[cur];
            }
            else {
                Dir* newDir = new Dir();
                curDir->dirs[cur] = newDir;
                curDir = curDir->dirs[cur];
            }
        }
    }

    void addContentToFile(string filePath, string content) {
        Dir* curDir = root;

        queue<string> q;
        stringstream ss(filePath);
        string token;
        vector<string> dirs;
        while (std::getline(ss, token, '/')) {
            q.push(token);
        }
        q.pop();
        while (q.size() > 1) {
            string cur = q.front();
            q.pop();
            curDir = curDir->dirs[cur];
        }
        string filename = q.front();
        if (curDir->files.count(filename)) {
            curDir->files[filename] += content;
        }
        else {
            curDir->files[filename] = content;
        }
    }

    string readContentFromFile(string filePath) {
        Dir* curDir = root;

        queue<string> q;
        stringstream ss(filePath);
        string token;
        vector<string> dirs;
        while (std::getline(ss, token, '/')) {
            q.push(token);
        }
        q.pop();
        while (q.size() > 1) {
            string cur = q.front();
            q.pop();
            curDir = curDir->dirs[cur];
        }
        string filename = q.front();
        return curDir->files[filename];
    }
};