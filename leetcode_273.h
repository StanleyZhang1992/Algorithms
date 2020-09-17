#pragma once
/*
273. Integer to English Words

Convert a non-negative integer to its english words representation. Given input is guaranteed to be less than 231 - 1.

Example 1:

Input: 123
Output: "One Hundred Twenty Three"
Example 2:

Input: 12345
Output: "Twelve Thousand Three Hundred Forty Five"
Example 3:

Input: 1234567
Output: "One Million Two Hundred Thirty Four Thousand Five Hundred Sixty Seven"
Example 4:

Input: 1234567891
Output: "One Billion Two Hundred Thirty Four Million Five Hundred Sixty Seven Thousand Eight Hundred Ninety One"
*/

string numberToWords(int num) {
    if (num == 0) {
        return "Zero";
    }

    int billion = num / pow(10, 9);
    num -= billion * pow(10, 9);
    int million = num / pow(10, 6);
    num -= million * pow(10, 6);
    int thousand = num / pow(10, 3);
    num -= thousand * pow(10, 3);
    int rest = num;

    string res;
    if (billion != 0) {
        res += three(billion) + " Billion";
    }
    if (million != 0) {
        if (res.size() > 0) {
            res += " ";
        }
        res += three(million) + " Million";
    }
    if (thousand != 0) {
        if (res.size() > 0) {
            res += " ";
        }
        res += three(thousand) + " Thousand";
    }
    if (rest != 0) {
        if (res.size() > 0) {
            res += " ";
        }
        res += three(rest);
    }

    return res;
}

string three(int num) {
    int hundred = num / 100;
    int rest = num - hundred * 100;
    string res;
    if (hundred * rest != 0) {
        res += one(hundred) + " Hundred" + " " + two(rest);
    }
    else if (hundred == 0) {
        res += two(rest);
    }
    else {
        res += one(hundred) + " Hundred";
    }
    return res;
}

string two(int num) {
    string res;
    if (num < 10) {
        res += one(num);
    }
    else if (num < 20) {
        res += twoSpecial(num);
    }
    else {
        int tenner = num / 10;
        int rest = num - tenner * 10;
        if (rest == 0) {
            res += ten(tenner);
        }
        else {
            res += ten(tenner) + " " + one(rest);
        }
    }
    return res;
}

string one(int num) {
    vector<string> strs{ " ", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine" };
    return strs[num];
}

string twoSpecial(int num) {
    vector<string> strs{ "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen" };
    return strs[num - 10];
}

string ten(int num) {
    vector<string> strs{ " ", " ", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety" };
    return strs[num];
}