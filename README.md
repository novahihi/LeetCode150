# Top Interview 150 Leetcode

## Array/String

### 88. Merge Sorted Array

**Approach:** Using mergeparts in mergesort arlgorithm to complete it.

```cpp
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    int i = 0, j = 0;
    vector <int> temp;
    while (i<m&&j<n) {
        if (nums1[i] <= nums2[j]) {
            temp.push_back(nums1[i]);
            i++;
        }
        else {
            temp.push_back(nums2[j]);
            j++;
        }
    }
        while (i<m) {
            temp.push_back(nums1[i]);
            i++; 
        }
        while (j<n) {
            temp.push_back(nums2[j]);
            j++;
        }
        for (i = 0; i<m+n;i++) nums1[i] = temp[i];
    }  
};
```
---
### 27. Remove Element

We have a vector of integers and we need to remove all occurences of a value. Completing 2 tasks:
- Change the array nums such that the first *k* elements of nums contain the elements which are not equal to val. The remaining elements of nums are not important as well as the size of nums.
- Return *k* - the quantity of value in vector.

**Approach:** 
- First, revising the vector to count the occurences of value.
- Then we use ```remove``` with the function that move every elements which are equal a value, to the end of array.

```cpp
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int cnt = 0;
        for (auto e: nums) 
        if (e==val) cnt++;
        int k = nums.size() - cnt;
        nums.erase(remove(nums.begin(), nums.end(), val), nums.end());
    return k;
    }
};
```
---
### 26. Remove Duplicates from Sorted Array

Completing 2 tasks:
- Change the array nums such that the first k elements of nums contain the unique elements in the order they were present in nums initially. The remaining elements of nums are not important as well as the size of nums.
- return *k* - the quantity of unique elements in vector.

**Approach:**
Using Slow and fast technique:
- Fast pointer i to check the condition nums[i] != nums[i-1].
- Slow pointer t start at index 1 (elements[0] is always unique). If the condition is true: nums[t] = nums[i] and t++.

```cpp
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int t = 1;  
        for (int i = 1; i < nums.size(); i++) {
            
            if (nums[i] != nums[i - 1]) {
                nums[t] = nums[i];
                t++;
            }
        }
        return t;
    }
};
```
---
### 80. Remove Duplicates from Sorted Array II

We have a sorted array, but a value can be appear more than twice. So we have to make the first *k* elements of vector that the occurences of a value just can be once or twice (the occurences >= 2 => reduce it to twice), and it will include all of value in that vector. Return k.
eg: 1 1 1 2 2 3 4 5 5 5 
-> first k elements: 1 1 2 2 3 4 5 5
=> k = 8.

**Approach:** Slow and fast pointers technique.
- Both pointers start from index 2. 
- If nums[k-2]!=i, nums[k] = nums[i]
-> key idea (because we can assure that every elements have distance of 2 is differnt).
from eg: i and k start from index 2 with value is 1. 
- First, nums[i] = 1 = nums[k-2] so we continue.
- Second, nums[i] = 2 != nums[k-2] = 1, so we change nums[k] to 2. 

```cpp
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
       int k = 0;
       for (int i = 0; i< nums.size(); i++) {
        if (k<2 || nums[i]!= nums[k-2]) {
            nums[k] = nums[i];
            k++;
        }
       }
    return k;
    }
};
```
---
### 169. Majority Element

We have to find the value that appears more than n/2 times in vector. 

**Approach:** Sorting vector and return the elements[n/2];

```cpp
class Solution {
public:
    int majorityElement(vector<int>& nums) {
    sort(nums.begin(),nums.end());
    return nums[nums.size()/2];
    }
};
```
---
### 189. Rotate Array

Given an integer array nums, rotate the array to the right by k steps, where k is non-negative.

eg: Input: nums = [1,2,3,4,5,6,7], k = 3
Output: [5,6,7,1,2,3,4]
Explanation:
- rotate 1 steps to the right: [7,1,2,3,4,5,6]
- rotate 2 steps to the right: [6,7,1,2,3,4,5]
- rotate 3 steps to the right: [5,6,7,1,2,3,4]

**Approach:** Use the mod to calculate the real k because after n (size of vector) times, we have the initial vector.
eg: 1 2 3 4 5
- Case 1: Change 2 times.
-> 5 1 2 3 4
   4 5 1 2 3
- Case 2: Change 7 times.
   5 1 2 3 4
   4 5 1 2 3
   3 4 5 1 2
   ...
   1 2 3 4 5
   5 1 2 3 4
   4 5 1 2 3
Then reserving 3 times:
- First: The whole vector.
- Second: From elements[0] to elements[k-1].
- Third: Remaining elements.

```cpp
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k = k % nums.size();
        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin()+k);
        reverse(nums.begin()+k, nums.end());
    }
};
```
---
### 121. Best Time to Buy and Sell Stock

**Description:**
You are given an array prices where prices[i] is the price of a given stock on the ith day.
We have to maximize profit by selling stocks in a day after buying day.

**Approach:** Slow and fast pointer technique.
Slow pointer find the minimum price to buy. Meanwhile, fast pointer find the maximum profit by minus buying price and compare it with the last profit. 

```cpp
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy_price = prices[0];
        int profit = 0;
        int n = prices.size();
        for (int i = 1; i<n; i++) {
            if (prices[i]<buy_price) {
                buy_price = prices[i];
                continue;
            }
            else {
                profit = max(profit, prices[i] - buy_price);
            }
        }
        return profit;
    }
};
```
---
### 122. Best Time to Buy and Sell Stock II

The same context with last problem. However, we have a change that we can hold a stock in some day. So we find the max profit that we can get.

**Approach:**
I found a rule that in a increase period, the max profit that we can get is buy in the first day and sell in the last day.
eg: 1 2 4 5 99 => max profit is 99 - 1 = 98
So we can divide the vector to smaller periods which are sorted increasing. The max profit we can get is sum of every periods' profit.

```cpp
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size(); 
        if (n==1) return 0;
        int profit = 0;
        int sum_pro = 0;
        int buy = prices[0];
        for (int i = 1; i<n-1; i++) {
            if (prices[i] < prices[i-1]) {
                buy = prices[i];
                continue;
            }
            else {
                profit = prices[i] - buy;
            }
            if (prices[i+1]<prices[i]) {
                sum_pro += profit;
                profit = 0;
            }
            else continue;
        }
        if (prices[n-1] > prices[n-2]) profit = prices[n-1] - buy;
        sum_pro += profit;
        return sum_pro;
    }
};
```
---
### 55. Jump Game

You have a vector and your position is index 0. The value at the index is the maximum distance that you can jump on that vector.
eg: 2 3 1 1 4
If you are at index 1 with value 3, you can jump to index 2, 3 or 4.
Can you reach the index n - 1.

**Approach:** In each turn, our aim is moving to the index so that we can move a longest distance after that.
eg: 2 3 1 1 4
If you are at index 0 with value 2, you can jump to index 1 or 2. 
- Index 1 - value 3, so the longest distance is 1+3 = 4
- Index 2 - value 1, so the longest distance is 1+2 = 3
So we choose the first case.

In each turn, we revise each cases to find the longest distance. If the longest distance that you can move is longer than size of vector, return true. But if the distance that you can move is 0, return false.
eg: 5 9 3 2 1 0 2 3 3 1 0 0
Turn 1: Index 1 - value 9
Turn 2: 
-- Index 10 - value 0
-- Index 9 - value 1
-- Index 8 - value 3 -> Possible

```cpp
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size(); int flag = 0;
        if (n==1) return true;
        int maxi = 0, i = 0, j = 0;
        while (true) {
        if (nums[i] == 0) return false;
        j = nums[i] + i;
        if (j>=n-1) return true;
        while (j>i) {
            int t = j + nums[j];
            if (t>maxi) {
                flag = j;
                maxi = t;
            }
            if (maxi>=n-1) return true;
            j--;
        }
        if (flag==i) return false;
        else i = flag;
        }
    }
};
```
---
### 45. Jump Game II

You are given a 0-indexed array of integers nums of length n. You are initially positioned at nums[0].
Each element nums[i] represents the maximum length of a forward jump from index i. In other words, if you are at nums[i], you can jump to any nums[i + j] where:
0 <= j <= nums[i] and
i + j < n
Return the minimum number of jumps to reach nums[n - 1]. The test cases are generated such that you can reach nums[n - 1].

**Approach:** I use the same idea with **55. Jump Game** but use a variant to count.

```cpp
class Solution {
public:
    int jump(vector<int>& nums) {
    int n = nums.size(); int cnt = 0;
    if (n==1) return 0; int max = 0;
    int j; int i = 0; int flag;
        while (i<n) {
        j = i + nums[i];
        cnt++;
        if (j>=n-1) return cnt;
        while (j>i) {
            int t = j + nums[j];
            if (t>max) {
                flag = j;
                max = t;
            }
            j--;
        }
        i = flag;
        }
    cnt = cnt+1;
    return cnt;
    }
};
```
---
### 274. H-Index

**Description**
In a vector, we should find a h index.
h index is the value so that the number of elements which are not smaller than h have to be not smaller than h.
eg: 3 0 1 5 6
3 is the h index because there are 3 elements (3, 5, 6) greater than 3.
eg: 1 1 3
1 is the h index because there are 3 elements (1 1 3) greater than 1 (it can't be 2 because there just 1 elements greater than 2, but 2>1).

**Approach** 
Sorting this array and starting revise it. 
- First, we set a stop condition: n - i < a[i]. If we have not met this condition, h = a[i].
- When we met the condition, let's check n - i > h (number of elements which are greater than h).

```cpp
class Solution {
public:
    int hIndex(vector<int>& citations) {
        int h = 1;
        int n = citations.size();
        sort(citations.begin(), citations.end());
        for (int i = 0; i<n; i++) {
            if (n-i<citations[i]) {
                if (n-i > h) h = n - i;
                break;
            }
            else h = citations[i];
        }
        return h;
    }
};
```
---
### 380. Insert Delete GetRandom O(1)

**Description**
Implement the RandomizedSet class:
RandomizedSet() Initializes the RandomizedSet object.
- bool insert(int val): Inserts an item val into the set if not present. Returns true if the item was not present, false otherwise.
- bool remove(int val): Removes an item val from the set if present. Returns true if the item was present, false otherwise.
- int getRandom(): Returns a random element from the current set of elements (it's guaranteed that at least one element exists when this method is called). Each element must have the same probability of being returned.

You must implement the functions of the class such that each function works in average O(1) time complexity.

**Approach**
Using map.

```cpp
class RandomizedSet {
    vector<int> v;
    unordered_map<int,int> mp;
public:
   
    RandomizedSet() {
    }

    bool search(int val){

         if(mp.find(val)!=mp.end())
            return true;
         return false;

    }

    
    bool insert(int val) {

        if(search(val))
            return false;

        v.push_back(val);
        mp[val] = v.size()-1;
        return true;
    }

    
    bool remove(int val) {

        if(!search(val))
            return false;

       
        auto it = mp.find(val);
        v[it->second] = v.back();
        v.pop_back();
        mp[v[it->second]] = it->second;
        mp.erase(val);
        return true;
    }

   
    int getRandom() {

        return v[rand()%v.size()];
    }
};
```
---
### 238. Product of Array Except Self

**Description** 
Given an integer array nums, return an array answer such that answer[i] is equal to the product of all the elements of nums except nums[i].

**Approach**
We have to deal with the case that nums[i] = 0.
- If we have more than 2 elements equal to 0, we fill answer vector by 0.
- If we have just one elements equal to 0, answer element at that position equal to product of remaining elements, and we fill 0.
- The last case is we have no 0, we calculate product of every elements and answers[i] = p/nums[i].

```cpp
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
      int p = 1;
      int n = nums.size();
      int cnt = 0;
      vector <int> answers (n);
      for (int i = 0; i<n;i++) {
        if (nums[i] == 0) {
            cnt++;
            continue;
        }
        else p *= nums[i]; 
      }
      if (cnt>=2) {
        fill(answers.begin(), answers.end(), 0);
      }
      else if (cnt == 1) {
        for (int i = 0; i<n;i++) {
            if (nums[i]==0) answers[i] = p;
            else answers[i] = 0;
        }
      }
      else {
        for (int i = 0; i<n; i++) {
            answers[i] = p/nums[i];
        }
      }

      return answers;
    }
};
```
### 134. Gas Station

**Description**
We have two vectors gas and cost.
- gas[i] is the amount of gas which can be provided by station i.
- cost[i] is the amount of gas which have been used to move from station i to station i+1.
Find a station to start so that we can move around every gas station.

**Approach**
- I made a prefix vector: pre[i] = gas[i] - cost[i].
- Calculate the sum of this vector to assure that we can move around.
- After that, we use two variation cur to control the amount of gas and idx to check the station.

```cpp
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        vector <int> pre(n);
        for (int i =0; i<n;i++) pre[i] = gas[i] - cost[i];
        int s = accumulate(pre.begin(), pre.end(), 0);
        if (s<0) return -1;
        int idx = 0, cur = 0;
        for (int i = 0; i<n-1;i++) {
            cur += pre[i];
            if (cur<0) {
                cur = 0;
                idx = i+1;
            }
        }
    return idx; 
    }
};
```
---
### 135. Candy

**Description**
We have a list of ratings of  ren. This is to rules to allocate the candies for them:
- Each child must have at least one candy.
- Children with a higher rating get more candies than their neighbors (neighbor of i is i+1 and i-1).

**Approach**
We create a candies vector, which every element has the value 1. The child at i index earn the candies[i]. 
We revise it 2 times, from the begin to the end and the end to the begin. 
eg: 
ratings 0 1 3 2 2 4
candies 1 1 1 1 1 1
In the first time, we follow a easy rule: If the i child has higher rating than i-1 child, he will receive one more candy.
eg:
candies 1 2 3 1 1 2
In the second time, we follow the rule: If the i-1 child has higher rating than the i child, candies[i-1] = max(candies[i]+1, candies[i-1]).
eg: 
candies 1 2 3 1 1 2

```cpp
class Solution {
public:
    int candy(vector<int>& ratings) {
    int n = ratings.size();
    vector <int> candies (n,1);
    for (int i = 1; i<n; i++) {
        if (ratings[i]>ratings[i-1]) candies[i] = candies[i-1] + 1;
    }
    for (int i = n-1; i>0; i--) {
        if (ratings[i-1] > ratings[i]) candies[i-1] = max(candies[i]+1, candies[i-1]); 
    }
    int s = accumulate (candies.begin(), candies.end(), 0);
    return s;
    }
};
```
---
### 13. Roman to Integer

**Description**
Calculate a value of roman number.

**Approach**
First, we have to hash 7 symbol in roman to integer number. 
I detect a law: If the right symbol has the value bigger than the left, we will add to the whole sum 
the differnce of them, else we will add to the sum each symbol like normal.
eg: 
MMC -> 1000 + 1000 + 100 = 2100
MCM -> 1000 + (1000 - 100) = 1900 

```cpp
class Solution {
public:
    int romanToInt(string s) {
        int res = 0;
        unordered_map<char, int> roman = {
            {'I', 1},
            {'V', 5},
            {'X', 10}, 
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000}
        };

        for (int i = 0; i < s.size() - 1; i++) {
            if (roman[s[i]] < roman[s[i + 1]]) {
                res -= roman[s[i]];
            } else {
                res += roman[s[i]];
            }
        }

        return res + roman[s[s.size() - 1]];        
    }
};
```
---
### 12. Integer to Roman

**Description**
Converting a number into roman number.

**Approach**
We will revise all the symbol in our hashmap. When we check a symbol, if our number is still bigger than the value of that symbol, we add that symbol to our result.
eg: 1974
check (1000 - M) -> res = M, num = 1974 - 1000 = 974
check (900 - CM) -> res = MCM, num = 74
skip 500, 400, 100, 90
check (50 - L) -> res = MCML, num = 24
skip 40
check (10 - X) -> res = MCMLXX, num = 4
check (4 - IV) -> res = MCMLXXIV
```cpp
class Solution {
public:
    string intToRoman(int num) {
    string res;
    const vector <pair <int, string>> valroman {
       {1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"}, {100, "C"},
            {90, "XC"},  {50, "L"},   {40, "XL"}, {10, "X"},   {9, "IX"},
            {5, "V"},    {4, "IV"},   {1, "I"} 
    };
    
    for (const auto [val, rom] : valroman) {
        if (num == 0) break;
        while (num>=val) {
            res+=rom;
            num-=val;
        }
    }
    return res;
    }
};
```
---
### 14. Longest Common Prefix

**Description**
Write a function to find the longest common prefix string amongst an array of strings.
If there is no common prefix, return an empty string "".

**Approach**
We use the first string for the prefix to revise vector. After a revised turn, we update the prefix string until it become none. When we get out the loop, we will have the final prefix.

```cpp
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return "";
        string prefix = strs[0]; 
        for (int i = 1; i < strs.size(); i++) {
            int j = 0;
            while (j < prefix.size() && j < strs[i].size() && prefix[j] == strs[i][j]) {
                j++;
            }
            prefix = prefix.substr(0, j); 
            if (prefix.empty()) return "";
        }

        return prefix;
    }
};
```
---
### 151. Reverse Words in a String

**Description**
We have to remove excessive space in a string and reverse that string but in word.
eg: the sky is blue -> blue is sky the

**Approach**
We revise that string and make words, put it in a stack to remove space. After that, take that word from the stack to complete result string.

```cpp
class Solution {
public:
    string reverseWords(string s) {
        stack<string> st;
        string word = "", res = "";

        for (char c : s) {
            if (c == ' ') {
                if (!word.empty()) {
                    st.push(word);
                    word = "";
                }
            } else {
                word += c;
            }
        }
        if (!word.empty()) st.push(word);

        while (!st.empty()) {
            res += st.top();
            st.pop();
            if (!st.empty()) res += " ";
        }
        return res;
    }
};
```
---
### 6. Zigzag Conversion

**Description**
eg: "PAYPALISHIRING" 
Convert to:
```
P   A   H   N
A P L S I I G
Y   I   R
```
-> PAHNAPLSIIGYIR
We have been given a string and a number n, which is the rows to write that string to zigzag conversion.

**Approach**
We create a vector of strings which contain characters in each rows. When we revise string s, we check the status of revising (up or down) to add character to rows[i] exactly.

```cpp
class Solution {
public:
    string convert(string s, int numRows) {
    int n = s.size();
    if (numRows == 1 || n <= numRows) return s;
    vector <string> rows (numRows);
    string res = "";
    int r = 0; bool up = false;
     for (int i = 0; i < n; ++i) {
            rows[r].push_back(s[i]);
            if (r == 0) up = false;              
            if (r == numRows-1) up = true;         
            if (up) r--;
            else r++;
        }
    for (auto e : rows) res+=e;
    
    return res;
    }
};
```
---
### 28. Find the Index of the First Occurrence in a String

**Description**
Given two strings needle and haystack, return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.

**Approach**
Use find function in string library.

```cpp
class Solution {
public:
    int strStr(string haystack, string needle) {
        int pos = haystack.find(needle);
        if (pos==string::npos) return -1;
        else return pos;
    }
};
```
---

## Two pointers

### 125. Valid Palindrome

**Description**
A phrase is a palindrome if, after converting all uppercase letters into lowercase letters and removing all non-alphanumeric characters, it reads the same forward and backward. Alphanumeric characters include letters and numbers.
Given a string s, return true if it is a palindrome, or false otherwise.

**Approach**
First, we create a new string that remove all space, special characters and transfer upper letter to lower.
After that, revise new string to check each character.

```cpp
class Solution {
public:
    bool isPalindrome(string s) {
        string s1 = "";
        for (char e : s) {
            if (isalnum(e)) {
                s1 += tolower(e);
            }
        }
        int n = s1.size();
        for (int i = 0; i < n / 2; i++) {
            if (s1[i] != s1[n - 1 - i]) return false;
        }
        return true;
    }
};
```
---
### 392. Is Subsequence

**Description**
We are given two string s and t. If we can make s from t by deleting some characters (or none), return true.

**Approach**
Use a while loop with a stop condition is the pointer that pass every characters in string t, but the pointer move on string s have not completed.

```cpp
class Solution {
public:
    bool isSubsequence(string s, string t) {
    int i = 0, j = 0;
    int lens = s.size();
    int lent = t.size();
    while (i<lens) {
        if (j==lent) return false;
        if (s[i] == t[j]) {
            i++;
            j++;
        }
        else j++;
    }  
    return true;
    }
};
```
---
### 167. Two Sum II - Input Array Is Sorted

**Description**
We have to find the index of two elements in a non-decreasing vector which have sum equal to a target.

**Approach**
Use two pointers from first element, and the last elements. 
- If sum of them greater than target, the right move.
- On the contrary, the left move.

```cpp
class Solution {
public:
    bool isSubsequence(string s, string t) {
    int i = 0, j = 0;
    int lens = s.size();
    int lent = t.size();
    while (i<lens) {
        if (j==lent) return false;
        if (s[i] == t[j]) {
            i++;
            j++;
        }
        else j++;
    }  
    return true;
    }
};
```
---
### 11. Container With Most Water

**Description**
We have a vector with the height each index. We have to calculate the maximum area which can be create from it. The length is shorter height, width is the difference of i and j.

**Approach**
Use two pointers from first element, and the last elements. 
- The pointer that has smaller height will move after update the max area that we can get.

```cpp
class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
      int i = 0, j = n - 1;
int max = 0;
while (i<j) {
if (height[i]<height[j]) {
    int s = height[i]*(j-i);
    if (s>max) max = s;
    i++;
}
else {
    int s = height[j]*(j-i);
    if (s>max) max = s;
    j--;
}
} 
return max;
    }
};
```
---
### 15. 3 sum

**Description**
We have a vector. Our mission is find every triplets equal to zero in that vector (not duplicate).

**Approach**
Sorting that vector and binary searching. However, when we find a triplet, we move 2 pointers until its value is differnt from last position.

```cpp
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
      sort(nums.begin(),nums.end());  
    vector <vector <int> > ans;
    int  n = nums.size();
    for (int i = 0; i<n-2; i++) {
        int l = i+1, r = n - 1;
        if (i>0 && nums[i]==nums[i-1]) continue;
        while (l<r) {
            int s = nums[i] + nums[l] + nums[r];
            if (s==0) {
            ans.push_back({nums[i], nums[l], nums[r]});
            while (l < r && nums[l] == nums[l + 1]) l++;       
            while (l < r && nums[r] == nums[r - 1]) r--;
                l++;
                r--;
                continue;
            }
            else if (s>0) {
                r--; continue;
            }
            else {
                l++;
                continue;
            }
        }
    }
    return ans;
    }
};
```
---
## Sliding Window

### 209. Minimum Size Subarray Sum

**Description**
We have a target number and a vector of numbers. Our mission is find the shortest sub-array which are greater than or equal to target.

**Approach**
Using sliding window technique with pointer l and r. 
When our sub-array is smaller than target, we wider our window by moving r to the right. When it is bigger, we narrower our window by moving l to the right, meanwhile update the minimum length.

```cpp
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
    int s = accumulate (nums.begin(), nums.end(), 0);
    if (s<target) return 0;
    int length = 999999, n = nums.size();
    int l = 0, r = 0;
    s = nums[0];
      while (r<n) {
        if (s>=target) {
            int temp = r-l+1;
            if (temp == 1) return 1; 
            length = min(length, temp);
            s -= nums[l];
            l++; 
        }
        else {
            r++;
            if(r<n) s += nums[r];
        }
      }
    return length;
    }
};
```
---
### 3. Longest Substring Without Repeating Characters


**Description**
Given a string s, find the length of the longest substring without duplicate characters.

**Approach**
Using sliding window technique with pointer l and r, combine with flag vector.
When we meet a new character, flag it and move r to the right, update the maximum length. But if we have seen this character before, use l pointer to find it, meanwhile remove the flag of every character on that process. After that, l move to the index next to that character.

```cpp
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
    vector <bool> flag (256, false);
    int n = s.size();
    int length = 0;
    int l = 0, r = 0;
    while (r<n) {
        if (flag[s[r]]) {
        while (s[l] != s[r]) {
                flag[s[l]] = false;
                l++;
            }
            // skip the first character
            flag[s[l]] = false;
            l++;
    }
        else {
            flag[s[r]] = true;
            length = max(length, r - l+1);
            r++;
        }  
    }
    return length;
    }
};
```
---
## Matrix

### 36. Valid Sudoku

**Description**
We have a 9x9 sudoku board. Checking its valid.

**Approach**
We use 9 set to save the appearance of a char in a row, 9 set to save a char in a column and 9 set to save a char in a board.

```cpp
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector <set <char> > row (9), col (9), block (9);

    for (int i = 0; i<9; i++) {
        for (int j = 0; j<9; j++) {
            char c = board[i][j];
            if (c == '.') continue;
            int b = (i/3)*3 + j/3; 
            if (row[i].count(c) || col[j].count(c) || block[b].count(c)) 
            return false;

            row[i].insert(c);
            col[j].insert(c);
            block[b].insert(c);
        }
    }    
     return true;
    }
};
```
---
### 54. Spiral Matrix

**Description**
Given an m x n matrix, return all elements of the matrix in spiral order.

**Approach**
We use 4 varieties top, bot, left, right to update the process of spiral matrix.

```cpp
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector <int> res;
        int top, bot, right, left;
        left = 0;
        right = matrix[0].size()-1;
        top = 0;
        bot = matrix.size()-1;
        while (left <= right && top <= bot) {
            for (int i = left; i <= right; i++) {
                res.push_back(matrix[top][i]);
            }
            top++;
            for (int i = top; i<=bot;i++) {
                res.push_back(matrix[i][right]);
            }
            right--;
            if (top <= bot) {
            for (int i = right; i>=left; i--) {
                res.push_back(matrix[bot][i]);
            }
            bot--;
            }
            if (left <= right) {
            for (int i = bot; i>=top; i--) {
                res.push_back(matrix[i][left]);
            }
            left++;
            }
        }
    return res;
    }
};
```
---
### 48. Rotate Image

**Description**
You are given an n x n 2D matrix representing an image, rotate the image by 90 degrees (clockwise).

You have to rotate the image in-place, which means you have to modify the input 2D matrix directly. DO NOT allocate another 2D matrix and do the rotation.

**Approach**
Transpose it, after that reverse each columns.

```cpp
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
    int n = matrix.size();   
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            swap(matrix[i][j], matrix[j][i]);
        }
    }
    for (int i = 0; i<n;i++) reverse(matrix[i].begin(), matrix[i].end());
    }
};
```
---
### 73. Set Matrix Zeros

**Description**
Given an mxn int matrix. If an element is 0, our mission is change every element in the same row and col to 0.

**Approach**
Use set to save rows and columns which have 0. After that, change it.

```cpp
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
    int m = matrix.size();
    int n = matrix[0].size();
    set <int> row;
    set <int> col;
    for (int i = 0; i<m; i++) {
        for (int j = 0; j < n; j++) {
            if (matrix[i][j]==0) {
                row.insert(i);
                col.insert(j);
            }
        }
    }
    for (auto i: row) {
        for (int j = 0; j<n; j++) matrix[i][j] = 0;
    }

    for (auto i: col) {
        for (int j = 0; j<m; j++) matrix[j][i] = 0;
    }
    }
};
```
---
## HashMap

### 383. Ransom Note

**Description**
We have magazine - a vector of characters. If we can create ransomNote from it, return true. Else return false.

**Approach**
We use map to count the frequency of each characters.
After that, we check the map again. If every value equal to 0, it means we can create ransomNote.

```cpp
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        map <char, int> freq;
        for (auto e: ransomNote) 
        freq[e]++;
        for (auto e: magazine) {
            auto it = freq.find(e);
            if (it==freq.end()) continue;
            else {
                if ((*it).second > 0) (*it).second--;
                else continue;
            }
        }
        for (auto [k, v]: freq) {
            if (v==0) continue;
            else return false;
        }
        return true;
    }
};
```
---
### 205. Isomorphic Strings

**Description**
All occurrences of a character must be replaced with another character while preserving the order of characters. No two characters may map to the same character, but a character may map to itself.

**Approach**
Using 2 maps to link s[i] and t[i], and [t]i to s[i].
eg: aa -> ba
If we just use 1 map, the first a will link to b, but after that, the second a will link to a. So we have to link from b to a.

```cpp
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (s.size() != t.size()) return false;
        map<char, char> m1, m2;
        for (int i = 0; i < s.size(); ++i) {
            char a = s[i], b = t[i];
            if (m1.count(a) && m1[a] != b) return false;
            if (m2.count(b) && m2[b] != a) return false;
            m1[a] = b;
            m2[b] = a;
        }
        return true;
    }
};
```
---
### 290. Word Pattern

**Description**
Same problem with 205 (above) but we have to link a word with a string. 

**Approach**
We use queue to separate each words in string. After that, link it with character in pattern by 2 maps (same idea). 

```cpp
class Solution {
public:
    bool wordPattern(string pattern, string s) {
    queue <string> q; string word = "";
    
    for (auto e: s) {
        
        if (e!=' ') {
            word += e;
            continue;
        }
        else {
            q.push(word);
            word = "";
        }
    }    
    if (!word.empty()) q.push(word);
    map <string, char> m1;
    map <char, string> m2;
    int n = pattern.size();
    int m = q.size();
    if (m!=n) return false;
    for (int i = 0; i<n; i++) {
        word = q.front();
        char c = pattern[i];
        if (m1.count(word) && m1[word]!=c) return false;
        if (m2.count(c) && m2[c]!=word) return false;
    m1[word] = c;
    m2[c] = word;
    q.pop();
    }
    return true;
    }
};
```
---
### 242. Valid Anagram

**Description**
Given two strings s and t. If we can rearrange s to make t, return true.

**Approach**
Using multiset to save every characters in s. Revising t and remove each character in that multiset.

```cpp
class Solution {
public:
    bool isAnagram(string s, string t) {
    if (s.size()!=t.size()) return false;
    multiset <char> ms;
    for (auto e: s) ms.insert(e);
    for (auto e: t)   {
        auto it = ms.find(e);
        if (it != ms.end()) ms.erase(it);
    }
    if (ms.empty()) return true;
    else return false;
    }
};
```
---
### 1. Two Sum

**Description**
We have a target number and a vector of numbers. Return indices of two numbers that they add up to target.

**Approach**
Using vector of pair that which contain two value:
- The first is the number.
- The second is the index.
Sorting that vector and starting using binary search.

```cpp
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
    vector <int> ans;
     int n = nums.size();
     vector <pair <int, int>> a(n);
     for (int i = 0; i<n;i++) {
        a[i].first = nums[i];
        a[i].second = i;
    }
    int l = 0, r = n -1;
    sort(a.begin(), a.end());
    while (l<r) {
        int s = a[l].first +  a[r].first;
        if (s==target) {
        ans.push_back(a[l].second);
        ans.push_back(a[r].second);
        break;
        }
        else if (s>target) r--;
        else l++;
    }
return ans;
    }
};
```
---
### 202. Happy Number

**Description**
Eg of happy number: 
n = 19
1^2 + 9^2 = 82
8^2 + 2^2 = 68
6^2 + 8^2 = 100
1^2 + 0^2 + 0^2 = 1

**Approach**
Converting a integer number to a string and starting to calculate the sum of square of each digits. However, the key is finding the stop case. So when a number appear second time, we stop while loop, use set to control it.
eg: 2 -> 4 -> 16 -> 37 -> 58 -> 89 -> 145 -> 40 -> 4.

```cpp
class Solution {
public:
    bool isHappy(int n) {
    set<int>s;
    while (true) {
        if (n==1) return true;
        if (s.find(n) != s.end()) break;
        else s.insert(n);
        string s = to_string(n);
        int sum = 0;
        for (char c: s) {
            int digit = c - '0';
            sum += pow(digit,2);
        }
        n = sum;
    }    
    return false;
    }
};
```
---
### 219. Contains Duplicate II

**Description**

Given an integer array nums and an integer k, return true if there are two distinct indices i and j in the array such that nums[i] == nums[j] and abs(i - j) <= k.

**Approach**

Using a vector to save the pairs include index and value, sorting and revising it.

```cpp
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
    int n = nums.size();
    vector <pair <int,int>> p (n);
    for (int i = 0; i<n;i++) {
        p[i].first = nums[i];
        p[i].second = i;
    }  
    sort (p.begin(), p.end());
    int i = 1;
    for (int i = 1; i<n; i++) {
        if (p[i].first==p[i-1].first) {
            if (abs(p[i].second - p[i-1].second)<=k) return true;
        }
        else continue;
    }
    return false;
    }
};
```
---
### 128. Longest Consecutive Sequence

**Description**
Given an unsorted array of integers nums, return the length of the longest consecutive elements sequence.

**Approach**

Sorting it and revising all case with some conditions.

```cpp
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
    int n = nums.size();
    if (n==0) return 0;
    sort (nums.begin(), nums.end());
    int cnt = 1;
    int maxi = 0;
    for (int i = 1; i<n;i++) {
        if (nums[i] == nums[i-1]) continue;
        else if (nums[i] - nums[i-1] == 1) 
            cnt++;
        else {
            maxi = max(cnt, maxi);
            cnt = 1;
        }
    }   
    maxi = max(cnt, maxi);
    return maxi;
    }
};
```
---
## STACK

### 20. Valid Parentheses

**Description**
Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
An input string is valid if:
- Open brackets must be closed by the same type of brackets.
- Open brackets must be closed in the correct order.
- Every close bracket has a corresponding open bracket of the same type.

**Approach**

Use a stack to control the last characters and checking after put every characters in s on it.

```cpp
class Solution {
public:
    bool isValid(string s) {
        stack <char> st;
        for (auto e: s) {
            if (st.empty()) {
                st.push(e);
                continue;
            }
            if (st.top() == '(' && e == ')') {
                st.pop();
                continue;
            }
            if (st.top() == '[' && e == ']') {
                st.pop();
                continue;
            }
            if (st.top() == '{' && e == '}') {
                st.pop();
                continue;
            }
            st.push(e);
        }
        if (st.empty()) return true;
        else return false;

    }
};
```
--- 
### 150. Evaluate Reverse Polish Notation

**Description**
Using eg:
Input: 1 3 5 * 9 - +
-> 1 + ((3*5) - 9) = 7

**Approach**

Use a stack to control the last value and token. 
For our eg, if the right value is the top a stack:
1 3 5
Now we have a "*" -> a = 5, b = 3 => a*b = 15
Push 15 to stack: 1 15
1 15 9
Now we have a "-" -> a = 9, b = 15 => b - a = 6
Push 6 to stack -> 1 6 
So the last result is 7.

```cpp
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
    stack <int> st;
    int a, b;
    for (auto c : tokens) {
        if (c == "+") {
            a = st.top();
            st.pop();
            b = st.top();
            st.pop();
            st.push(a+b);
        }
        else if (c == "-") {
            a = st.top();
            st.pop();
            b = st.top();
            st.pop();
            st.push(b-a);
        }
        else if (c == "*") {
            a = st.top();
            st.pop();
            b = st.top();
            st.pop();
            st.push(a*b);
        }
        else if (c == "/") {
            a = st.top();
            st.pop();
            b = st.top();
            st.pop();
            st.push(b/a);
        }
        else st.push(stoi(c));

    }
    return st.top();
    }
};
```
--- 
## LINK LISTED

### 141. Linked List Cycle

**Description**

We have a ListNode and we have to check if it has a cycle.

**Approach**

Using two pointers technique with slow pointer and fast pointer. In each loop, fast pointer will move 2 step, but the slow one will move just one. If they meet at a node, return true.

```cpp
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode* fast = head;
        ListNode* slow = head;

        while (fast != nullptr && fast->next != nullptr) {
            fast = fast->next->next;
            slow = slow->next;

            if (fast == slow) {
                return true;
            }
        }

        return false;        
    }
};
```
---
### 2. Add Two Numbers

**Description**

You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

**Approach**

We create a sum and a carry variety and their value is 0. Initially, sum = carry. Revising 2 lists, sum = val1 + val2. If sum < 10, carry = 0 and new result node will have value equal to sum. But if sum > 10, carry = 1 and node = sum%10.

```cpp
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode(0);
        ListNode* current = dummy;
        int carry = 0;

        while (l1 != nullptr || l2 != nullptr || carry != 0) {
            int sum = carry;

            if (l1 != nullptr) {
                sum += l1->val;
                l1 = l1->next;
            }

            if (l2 != nullptr) {
                sum += l2->val;
                l2 = l2->next;
            }

            carry = sum / 10;
            current->next = new ListNode(sum % 10);
            current = current->next;
        }

        return dummy->next;
    }
};
```
---
### 21. Merge Two Sorted Lists

**Description**

You are given the heads of two sorted linked lists list1 and list2. Merge into one sorted list.

**Approach**

Using mergesort algorithm.

```cpp
//**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    ListNode* dummy = new ListNode(0);
    ListNode* cur = dummy; 
    ListNode* p1 = list1; 
    ListNode* p2 = list2;
    while (p1 != nullptr && p2 != nullptr) {
        if ((p1->val) <= (p2->val)) {
            cur->next = new ListNode(p1->val);
            p1 = p1->next;
            cur = cur->next;
        }
        else {
            cur->next = new ListNode(p2->val);
            p2 = p2->next;
            cur = cur->next;
        }
    }
        while (p1!=nullptr) {
            cur->next = new ListNode(p1->val);
            p1 = p1->next;
            cur = cur->next;
        }
        while (p2!=nullptr) {
            cur->next = new ListNode(p2->val);
            p2 = p2->next;
            cur = cur->next;
        }
      return dummy->next;
    }
};
```
---
### 138. Copy List with Random Pointer

**Description**

We have a ListNode. But each nodes has two pointers: random and next. We have to create a duplicate list of initial list.

**Approach**

Using hash map which link the initial node with our duplicate. 

```cpp
//**
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
    //tạo một hash map với key là toàn bộ linked list cũ, value sẽ là linked list mới 
    unordered_map <Node*, Node*> oldtonew;
    Node* p = head;
    while (p) {
        oldtonew[p] = new Node(p->val);
        p = p->next;
    }   
    p = head;
    while (p) {
        oldtonew[p]->next = oldtonew[p->next];
        oldtonew[p]->random = oldtonew[p->random];
        p = p->next;
    }
    return oldtonew[head];
    }
};
```
---
### 92. Reverse Linked List II

**Description**

Given the head of a singly linked list and two integers left and right where left <= right, reverse the nodes of the list from position left to position right, and return the reversed list.

**Approach**

We use a stack to save the node in a reverse direction. After that, we link the top node in stack with the initial list. 

```cpp
/class Solution
{
public:
    ListNode* stack=NULL;
    
    inline void push(ListNode* temp)
    {
        temp->next=stack;
        stack=temp;
    }
    
    ListNode* reverseBetween(ListNode* head, int left, int right)
    {
        if(left==right)
        {
            return head;
        }
        ListNode start;
        start.next=head;
        ListNode* prev=&start;
        for(int i=1;i<left;i++)
        {
            prev=prev->next;
        }
        ListNode* temp=prev->next;
        ListNode* next=nullptr;
        for(int i=left;i<=right;i++)
        {
            next=temp->next;
            push(temp);
            temp=next;
        }
        prev->next=stack;
        temp=stack;
        while(temp->next)
        {
            temp=temp->next;
        }
        temp->next=next;
        return start.next;
    }
};
```
---
### 25. Reverse Nodes in k-Group

**Description**

I use eg: 
1 2 3 4 5 with k = 2 -> 2 1 4 3 5. We have to reverse k consecutive nodes.

**Approach**

I use the same idea with #92 by a stack to save the nodes in a reverse direction. However, i will put a count variety to count the number nodes in stack. When it equal to k, we link every nodes in stack to the dummy node (result).

```cpp
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head || k == 1) return head;

        stack<ListNode*> st;
        ListNode* dummy = new ListNode(0);
        ListNode* p = dummy;

        ListNode* curr = head;

        while (curr) {
            int count = 0;
            ListNode* temp = curr;

            while (temp && count < k) {
                st.push(temp);
                temp = temp->next;
                count++;
            }
            if (count == k) {
                while (!st.empty()) {
                    p->next = st.top();
                    st.pop();
                    p = p->next;
                }
                p->next = temp;
                curr = temp;
            } else {
                p->next = curr;
                break;
            }
        }

        return dummy->next;
    }
};
```
---
### 19. Remove Nth Node From End of List

**Description**

Given the head of a linked list, remove the nth node from the end of the list and return its head. 

eg: 1 2 3 4 5, n = 2 => 1 2 3 5

**Approach**

First, we count the number of nodes in list. Next, we have to find the index of the node which need to be deleted from the begin. Delete it in an easy way.

```cpp
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode* p = head;
    int cnt = 0;
    while (p!=nullptr) {
        cnt++;
        p = p->next;
    }
    ListNode*temp;
    if (cnt==1) {
        head = nullptr;
        return head;
    }
    if (n==cnt) {
        temp = head;
        head = head->next;
        delete(temp);
        return head;
    }
    p = head;
    for (int i = 1; i<cnt-n;i++) {
        p = p->next;
    }
    temp = p->next;
    p->next = p->next->next;
    delete (temp);
    return head;
    }
};
```
---
### 82. Remove Duplicates from Sorted List II

**Description**

If a value appears more than once in the list, we have to delete all the nodes which have that value.  

eg: 1 2 2 3 3 3 5 -> 1 5

**Approach**

Using two pointers technique. The fast will revise and if it detect a value that appear twice, it will find the first node which have different value. Meanwhile, move the slow one to the fast.

```cpp
/class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* dummy = new ListNode(0, head);
        ListNode* prev = dummy;

        while (head) {
            if (head->next && head->val == head->next->val) {
                while (head->next && head->val == head->next->val) {
                    head = head->next;
                }
                prev->next = head->next;
            } else {
                prev = prev->next;
            }
            head = head->next;
        }

        return dummy->next;
    }
};
```
---
### 86. Partition List

**Description**

Given the head of a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.

You should preserve the original relative order of the nodes in each of the two partitions.

![image](https://hackmd.io/_uploads/B1AQcmgExe.png)


**Approach**

I create 2 list for linking every nodes which have value less than x, the others will link every nodes greater than or equal to x. After revising the initial list, we will link 2 new lists.

![image](https://hackmd.io/_uploads/rJMe5XxNgg.png)

```cpp
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
    ListNode* small = new ListNode(); 
    ListNode* s = small;
    ListNode* big = new ListNode();
    ListNode* b = big;
    ListNode* p = head;
    while (p) {
        if ( (p->val) < x ) {
            s->next = p;
            s = s->next;
        }
        else {
            b->next = p;
            b = b->next;
        }
        p = p->next;
    }
    b->next = nullptr;
    s->next = big->next; 
    return small->next;   
    }
};
```
---
### 146. LRU Cache

**Description**

Design a data structure that follows the constraints of a Least Recently Used (LRU) cache.

Implement the LRUCache class:

- LRUCache(int capacity) Initialize the LRU cache with positive size capacity.
- int get(int key) Return the value of the key if the key exists, otherwise return -1.
- void put(int key, int value) Update the value of the key if the key exists. Otherwise, add the key-value pair to the cache. If the number of keys exceeds the capacity from this operation, evict the least recently used key.

The functions get and put must each run in O(1) average time complexity.

```cpp
class Node {
public:
    int key;
    int val;
    Node* prev;
    Node* next;

    Node(int key, int val) : key(key), val(val), prev(nullptr), next(nullptr) {}
};

class LRUCache {
public:
private:
    int cap;
    std::unordered_map<int, Node*> cache;
    Node* oldest;
    Node* latest;

public:
    LRUCache(int capacity) : cap(capacity) {
        oldest = new Node(0, 0);
        latest = new Node(0, 0);
        oldest->next = latest;
        latest->prev = oldest;
    }

    int get(int key) {
        if (cache.find(key) != cache.end()) {
            Node* node = cache[key];
            remove(node);
            insert(node);
            return node->val;
        }
        return -1;
    }

private:
    void remove(Node* node) {
        Node* prev = node->prev;
        Node* next = node->next;
        prev->next = next;
        next->prev = prev;
    }

    void insert(Node* node) {
        Node* prev = latest->prev;
        Node* next = latest;
        prev->next = next->prev = node;
        node->next = next;
        node->prev = prev;
    }

public:
    void put(int key, int value) {
        if (cache.find(key) != cache.end()) {
            remove(cache[key]);
        }
        Node* newNode = new Node(key, value);
        cache[key] = newNode;
        insert(newNode);

        if (cache.size() > cap) {
            Node* lru = oldest->next;
            remove(lru);
            cache.erase(lru->key);
            delete lru;
        }
    }

    // Destructor to release memory used by the nodes
    ~LRUCache() {
        Node* curr = oldest;
        while (curr != nullptr) {
            Node* next = curr->next;
            delete curr;
            curr = next;
        }
    }
};
```
---
## Binary Tree General

### 104. Maximum Depth of Binary Tree

**Description**

A binary tree's maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.

**Approach:** I use recursion to compare two depth if we move to left or right. I have made a animation.

![image](https://hackmd.io/_uploads/HkyT2GEVge.png)

```cpp
class Solution {
public:
    int maxDepth(TreeNode* root) {
    if (!root) return 0;
    int left = maxDepth(root->left);
    int right = maxDepth(root->right);
    return max(left, right) + 1;
    }
};
```
---
### 100. Same Tree

**Description**

Given the roots of two binary trees p and q, write a function to check if they are the same or not.

Two binary trees are considered the same if they are structurally identical, and the nodes have the same value.

**Approach** 

If both root p and q are nullptr, we stop recursion and return true. If p and q are existed and similar at value, we will check their left and right. If we can move to the last instruction, return false.

```cpp
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (!p && !q) {
            return true;
        }

        if (p && q && p->val == q->val) {
            return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
        }
        
        return false;        
    }
};
```
---
### 226. Invert Binary Tree

**Description**

Given the root of a binary tree, invert the tree, and return its root.

![image](https://hackmd.io/_uploads/Hy4OKZpElx.png)


**Approach** 

Using a temp node to save the left node, and swap it with right. Calling the recursion of the left and the right.

```cpp
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
    if (!root) return nullptr;
    TreeNode* temp = root->left;
    root->left = root->right;
    root->right = temp;
    invertTree(root->right);
    invertTree(root->left);
    return root;
    }
};
```
---
### 101. Symmetric Tree

**Description**

Given the root of a binary tree, check whether it is a mirror of itself (i.e., symmetric around its center).

![image](https://hackmd.io/_uploads/SJokibT4ex.png)

**Approach** 

We have to create two function. First, ismirror to check each node at the mirror position. So we have to check t1->left and t2->val. The issynmetric just to use ismirror for 2 branchs of tree.

```cpp
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
    if (!root) return nullptr;
    TreeNode* temp = root->left;
    root->left = root->right;
    root->right = temp;
    invertTree(root->right);
    invertTree(root->left);
    return root;
    }
};
```
---
### 105. Construct Binary Tree from Preorder and Inorder Traversal

**Description**

Given two integer arrays preorder and inorder where preorder is the preorder traversal of a binary tree and inorder is the inorder traversal of the same tree, construct and return the binary tree.

**Approach** 

First, we consider that the first element in vector preorder is the root of tree. So we start from it.

From preorder, we can know the order to create TreeNode from root -> left -> right. Inorder will let us know if a node has child node (left or right). So we will use a variation iodid to check the position of a node in  the tree.

Ex: preorder = [3,9,20,15,7], inorder  = [9,3,15,20,7]

Root = 3, iodid = 0, but inorder[iodid] is not 3 -> it has left child. So we check the next element in preorder. Now, it is 9 and it does not have chile, we have moved to the depth in left. We remove the top in stack and check next.


```cpp
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    TreeNode* root = new TreeNode(preorder[0]);
    stack <TreeNode*> st;
    st.push(root);
    int iodid = 0;
    for (int i = 1; i<preorder.size(); i++) {
        TreeNode* temp = st.top();
        int cur = preorder[i];
        if (temp->val!=inorder[iodid]) {
            temp->left = new TreeNode (cur);
            st.push(temp->left);
        }
        else {
        while (!st.empty() && st.top()->val==inorder[iodid]) {
            temp = st.top();
            st.pop();
            iodid++;
        }
        temp->right = new TreeNode (cur);
        st.push(temp->right);
    }
    }
    return root;
    }
};
```
---
### 117. Populating Next Right Pointers in Each Node II

**Description**

In a tree, we will link the node on the same level with a pointer next. In the last pointer in a level, the next ponter will be nullptr.

**Approach** 

We create a vector which include vector in each levels. Vector in each levels will include TreeNode* in that level. After complete the creation, we will set the next pointer in each child vector.


```cpp
class Solution {
public:
    Node* connect(Node* root) {
        if (!root) return nullptr; 

        vector<vector<Node*>> ln;
        queue<pair<Node*, int>> q;
        q.push({root, 0});

        while (!q.empty()) {
            auto [node, level] = q.front();
            q.pop();

            if (!node) continue;  // Fix 2: Bỏ qua nullptr

            if (level == ln.size())
                ln.push_back({});

            ln[level].push_back(node);

            q.push({node->left, level + 1});
            q.push({node->right, level + 1});
        }

        for (int i = 0; i < ln.size(); i++) {
            for (int e = 0; e < ln[i].size(); e++) {
                if (e == ln[i].size() - 1) ln[i][e]->next = nullptr;
                else ln[i][e]->next = ln[i][e + 1];
            }
        }
        return root;
    }
};
```
---
### 114. Flatten Binary Tree to Linked List

**Description**

From a binary tree, we make a linked list by TreeNode* but each node just have the right child. And the list will be in preorder.

**Approach** 

So we will travel the tree by preorder and push them in a queue to create linked list. After that, we check the queue to link the right pointer, and set the left pointer to nullptr.


```cpp
class Solution {
public:
    void flatten(TreeNode* root) {
    if (!root) return;
    queue <TreeNode*> q;
    stack <TreeNode*> st;
    st.push(root);
    while (!st.empty()) {
        TreeNode* temp = st.top();
        st.pop();
        q.push(temp);
        if (temp->right) st.push (temp->right);
        if (temp->left) st.push (temp->left);
    } 
    while (q.size()!=1) {
        TreeNode* temp = q.front();
        q.pop();
        temp->right = q.front();
        temp->left = nullptr;
    } 
    q.front()->right = nullptr;
    }
};
```
---
### 129. Sum Root to Leaf Numbers

**Description**

In each branches, we have a number with each digits is made from TreeNode. The root will be the left digit of all numbers. So we have to calculate sum of them.

**Approach** 

First, we will create a map to know which is dad of each node. Using level traversal to make it, and if a treenode which don't have child, we will push it into a vector. After that, we will calculate sum from the vector and the map.


```cpp
class Solution {
public:
    int sumNumbers(TreeNode* root) {
    unordered_map <TreeNode*, TreeNode*> m;
    m[root] = nullptr;
    vector <TreeNode*> v;
    queue <TreeNode*> q;
    TreeNode* cur;
    q.push(root);
    while (!q.empty()) {
        cur = q.front();
        q.pop();
        if (cur->left==nullptr && cur->right == nullptr) v.push_back(cur);
        if (cur->left) {
            m[cur->left] = cur;
            q.push(cur->left);
        }
        if (cur->right) {
            m[cur->right] = cur;
            q.push(cur->right);
        }
    }
    int s = 0;
    for (auto e: v) {
        cur = e; long long d = 1;
        while (cur!=nullptr) {
            s = s + (cur->val)*d;
            d = d*10;
            cur = m[cur];
        }
    }
    return s;     
    }
};

```
---
### 112. Path Sum

**Description**

Given the root of a binary tree and an integer targetSum, return true if the tree has a root-to-leaf path such that adding up all the values along the path equals targetSum.


![image](https://hackmd.io/_uploads/SyjJTzpVel.png)

In the eg, if the target sum is 22 we return true.

**Approach** 

We use a stack which each elements is a pair of a node and a sum of every node from the root to that node (eg: pair 11 - 20). And we just check every single leafs.

```cpp
class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (!root) return false;

        stack<pair<TreeNode*, int>> st;
        st.push({root, root->val});

        while (!st.empty()) {
            auto [node, sum] = st.top(); st.pop();
            if (!node->left && !node->right) {
                if (sum == targetSum) return true;
            }
            if (node->right) st.push({node->right, sum + node->right->val});
            if (node->left)  st.push({node->left, sum + node->left->val});
        }
    return false;
    }
};
```
---
## Binary Search Tree

### 530. Minimum Absolute Difference in BST

**Description**

Given the root of a Binary Search Tree (BST), return the minimum absolute difference between the values of any two different nodes in the tree.

**Approach**

We know that: In a BST, from left to right, the value of each node is in an increasing order. So our target is check the difference of two adjacent node and update the minimum.

```cpp
class Solution {
public:
    int getMinimumDifference(TreeNode* root) {
    if (!root) return 0;
    int mini = 999999;
    stack <TreeNode*> st;
    TreeNode* prev = nullptr;
    TreeNode* curr = root;
        while (curr != nullptr || !st.empty()) {
        while (curr != nullptr) {
            st.push(curr);
            curr = curr->left;
        }
        curr = st.top();
        st.pop();
        if (prev) mini = min(mini, curr->val - prev->val);
        prev = curr;
        curr = curr->right;
    }
   
    return mini;
    }
};
```
---
### 230. Kth Smallest Element in a BST

**Description**

Given the root of a binary search tree, and an integer k, return the kth smallest value (1-indexed) of all the values of the nodes in the tree.

**Approach**

Use InOrder traversal until k equal to zero. 

```cpp
class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
    stack <TreeNode*> st;
    TreeNode* cur = root;
    while (!st.empty() || cur!=nullptr) {
        while (cur!=nullptr) {
            st.push (cur);
            cur = cur->left;
        }
    //xu ly node
    cur = st.top();
    st.pop();
    k--;
    if (k==0) return cur->val;
    cur = cur->right;
    }
    return root->val;
    }
};
```
---
### 98. Validate Binary Search Tree

**Description**

Check a valid BST.

**Approach**

Use InOrder traversal to check from left to right. If the right node is smaller than or equal to the left node, we return false. 

```cpp
class Solution {
public:
    bool isValidBST(TreeNode* root) {
    long long temp = -9999999999;
    stack <TreeNode*> st;
    TreeNode* cur = root;
    while (!st.empty() || cur!=nullptr) {
        while (cur!=nullptr) {
            st.push (cur);
            cur = cur->left;
        }
    //xu ly node
    cur = st.top();
    st.pop();
    if (cur->val<=temp) return false;
    else temp = cur->val;
    cur = cur->right;
    }
    return true;   
    }
```
---
