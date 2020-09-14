#pragma once
/*
937. Reorder Data in Log Files

You have an array of logs.  Each log is a space delimited string of words.

For each log, the first word in each log is an alphanumeric identifier.  Then, either:

Each word after the identifier will consist only of lowercase letters, or;
Each word after the identifier will consist only of digits.
We will call these two varieties of logs letter-logs and digit-logs.  It is guaranteed that each log has at least one word after its identifier.

Reorder the logs so that all of the letter-logs come before any digit-log.  The letter-logs are ordered lexicographically ignoring identifier, with the identifier used in case of ties.  The digit-logs should be put in their original order.

Return the final order of the logs.



Example 1:

Input: logs = ["dig1 8 1 5 1","let1 art can","dig2 3 6","let2 own kit dig","let3 art zero"]
Output: ["let1 art can","let3 art zero","let2 own kit dig","dig1 8 1 5 1","dig2 3 6"]


Constraints:

0 <= logs.length <= 100
3 <= logs[i].length <= 100
logs[i] is guaranteed to have an identifier, and a word after the identifier.
*/
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

class Item {
public:
    string content;
    string log;
    string identifier;
};

vector<string> reorderLogFiles(vector<string>& logs) {
    vector<string> res;

    auto myComp = [](Item* it1, Item* it2) {
        if (it1->content != it2->content) {
            return it1->content < it2->content;
        }
        else {
            return it1->identifier < it2->identifier;
        }
    };

    vector<Item*> letter_logs;
    vector<Item*> digit_items;
    for (string log : logs) {
        int content_idx = log.find(" ");
        string content = log.substr(content_idx + 1);

        Item* newItem = new Item();
        newItem->log = log;
        newItem->identifier = string(log.begin(), log.begin() + content_idx);
        newItem->content = content;

        if (isdigit(content[0])) {
            digit_items.push_back(newItem);
        }
        else {
            letter_logs.push_back(newItem);
        }
    }

    std::sort(letter_logs.begin(), letter_logs.end(), myComp);
    letter_logs.insert(letter_logs.end(), digit_items.begin(), digit_items.end());
    for (Item* cur : letter_logs) {
        res.emplace_back(cur->log);
    }

    return res;
}