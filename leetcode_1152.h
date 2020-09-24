#pragma once
/*
1152. Analyze User Website Visit Pattern

We are given some website visits: the user with name username[i] visited the website website[i] at time timestamp[i].

A 3-sequence is a list of websites of length 3 sorted in ascending order by the time of their visits.  (The websites in a 3-sequence are not necessarily distinct.)

Find the 3-sequence visited by the largest number of users. If there is more than one solution, return the lexicographically smallest such 3-sequence.



Example 1:

Input: username = ["joe","joe","joe","james","james","james","james","mary","mary","mary"], timestamp = [1,2,3,4,5,6,7,8,9,10], website = ["home","about","career","home","cart","maps","home","home","about","career"]
Output: ["home","about","career"]
Explanation:
The tuples in this example are:
["joe", 1, "home"]
["joe", 2, "about"]
["joe", 3, "career"]
["james", 4, "home"]
["james", 5, "cart"]
["james", 6, "maps"]
["james", 7, "home"]
["mary", 8, "home"]
["mary", 9, "about"]
["mary", 10, "career"]
The 3-sequence ("home", "about", "career") was visited at least once by 2 users.
The 3-sequence ("home", "cart", "maps") was visited at least once by 1 user.
The 3-sequence ("home", "cart", "home") was visited at least once by 1 user.
The 3-sequence ("home", "maps", "home") was visited at least once by 1 user.
The 3-sequence ("cart", "maps", "home") was visited at least once by 1 user.


Note:

3 <= N = username.length = timestamp.length = website.length <= 50
1 <= username[i].length <= 10
0 <= timestamp[i] <= 10^9
1 <= website[i].length <= 10
Both username[i] and website[i] contain only lowercase characters.
It is guaranteed that there is at least one user who visited at least 3 websites.
No user visits two websites at the same time.
*/
#include<vector>
#include<string>
#include<unordered_map>
#include<set>
#include<map>
#include<algorithm>

using namespace std;

vector<string> mostVisitedPattern(vector<string>& username, vector<int>& timestamp, vector<string>& website) {
    unordered_map<string, vector<pair<int, string> > > cache;
    int len = username.size();
    for (int i = 0; i < len; ++i) {
        cache[username[i]].push_back(make_pair(timestamp[i], website[i]));
    }

    auto myComp = [](pair<int, string>& p1, pair<int, string>& p2) {
        return p1.first < p2.first;
    };
    for (auto& p : cache) {
        std::sort(p.second.begin(), p.second.end(), myComp);
    }

    unordered_map<string, set<vector<string> > > seq_by_user;
    for (auto p : cache) {
        int visits = p.second.size();
        for (int i = 0; i < visits - 2; ++i) {
            for (int j = i + 1; j < visits - 1; ++j) {
                for (int k = j + 1; k < visits; ++k) {
                    seq_by_user[p.first].insert(vector<string>{p.second[i].second, p.second[j].second, p.second[k].second});
                }
            }
        }
    }

    map<vector<string>, int> seq_count;
    for (auto p : seq_by_user) {
        set<vector<string> > seqs = p.second;
        for (vector<string> seq : seqs) {
            seq_count[seq] += 1;
        }
    }

    int maxFreq = 0;
    vector<string> res;
    for (auto p : seq_count) {
        if (p.second > maxFreq) {
            res = p.first;
        }
        maxFreq = max(maxFreq, p.second);
    }

    return res;
}