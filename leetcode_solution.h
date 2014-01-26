/*
 Author:     Annie Kim, anniekim.pku@gmail.com
 Date:       Apr 19, 2013
 Update:     Sep 22, 2013
 Problem:    3Sum
 Difficulty: Medium
 Source:     http://leetcode.com/onlinejudge#question_15
 Notes:
 Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0? 
 Find all unique triplets in the array which gives the sum of zero.
 Note:
 Elements in a triplet (a,b,c) must be in non-descending order. (ie, a <= b <= c)
 The solution set must not contain duplicate triplets.
 For example, given array S = {-1 0 1 2 -1 -4},
 A solution set is:
 (-1, 0, 1)
 (-1, -1, 2)

 Solution: Simplify '3sum' to '2sum' O(n^2). http://en.wikipedia.org/wiki/3SUM
*/

class Solution {
public:
    vector<vector<int> > threeSum(vector<int> &num) {
        vector<vector<int>> res;
        sort(num.begin(), num.end());
        int N = num.size();
        for (int i = 0; i < N-2 && num[i] <= 0; ++i)
        {
            if (i > 0 && num[i] == num[i-1])
                continue; // avoid duplicates
            int twosum = 0 - num[i];
            int l = i + 1, r = N - 1;
            while (l < r)
            {
                int sum = num[l] + num[r];
                if (sum < twosum)
                    l++;
                else if (sum > twosum)
                    r--;
                else {
                    vector<int> triplet;
                    triplet.push_back(num[i]);
                    triplet.push_back(num[l]);
                    triplet.push_back(num[r]);
                    res.push_back(triplet);
                    l++; r--;
                    while (l < r && num[l] == num[l-1]) l++;  // avoid duplicates
                    while (l < r && num[r] == num[r+1]) r--;  // avoid duplicates
                }
            }
        }
        return res;
    }
};
/*
 Author:     Annie Kim, anniekim.pku@gmail.com
 Date:       Apr 20, 2013
 Problem:    3Sum Closest
 Difficulty: Medium
 Source:     http://leetcode.com/onlinejudge#question_16
 Notes:
 Given an array S of n integers, find three integers in S such that the sum is closest to 
 a given number, target. Return the sum of the three integers. 
 You may assume that each input would have exactly one solution.
 For example, given array S = {-1 2 1 -4}, and target = 1.
 The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).

 Solution: Similar to 3Sum, taking O(n^2) time complexity.
 */

class Solution {
public:
    int threeSumClosest(vector<int> &num, int target) {
        int res = INT_MAX;
        int N = num.size();
        sort(num.begin(), num.end());
        for (int i = 0; i < N-2; ++i)
        {
            int l = i + 1, r = N - 1;
            while (l < r)
            {
                int threesum = num[i] + num[l] + num[r];
                if (threesum == target) return target;
                else if (threesum < target) l++;
                else r--;
                if (res == INT_MAX || abs(threesum - target) < abs(res - target))
                    res = threesum;
            }
        }
        return res;
    }
};/*
 Author:     Annie Kim, anniekim.pku@gmail.com
 Date:       Apr 20, 2013
 Update:     Sep 26, 2013
 Problem:    4Sum
 Difficulty: Medium
 Source:     http://leetcode.com/onlinejudge#question_18
 Notes:
 Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0? 
 Find all unique triplets in the array which gives the sum of zero.
 Note:
 Given an array S of n integers, are there elements a, b, c, and d in S such that a + b + c + d = target? 
 Find all unique quadruplets in the array which gives the sum of target.
 Note:
 Elements in a quadruplet (a,b,c,d) must be in non-descending order. (ie, a <= b <= c <= d)
 The solution set must not contain duplicate quadruplets.
 For example, given array S = {1 0 -1 0 -2 2}, and target = 0.
 A solution set is:
 (-1,  0, 0, 1)
 (-2, -1, 1, 2)
 (-2,  0, 0, 2)

 Solution: Similar to 3Sum, 2Sum.
 */

class Solution {
public:
    vector<vector<int> > fourSum(vector<int> &num, int target) {
        int N = num.size();
        vector<vector<int> > res;
        if (N < 4) return res;
        sort(num.begin(), num.end());
        for (int i = 0; i < N; ++i)
        {
            if (i > 0 && num[i] == num[i-1]) continue; // avoid duplicates
            for (int j = i+1; j < N; ++j)
            {
                if (j > i+1 && num[j] == num[j-1]) continue; // avoid duplicates
                int twosum = target - num[i] - num[j];
                int l = j + 1, r = N - 1;
                while (l < r)
                {
                    int sum = num[l] + num[r];
                    if (sum == twosum) {
                        vector<int> quadruplet(4);
                        quadruplet[0] = num[i];
                        quadruplet[1] = num[j];
                        quadruplet[2] = num[l];
                        quadruplet[3] = num[r];
                        res.push_back(quadruplet);
                        while (l < r && num[l+1] == num[l]) l++; // avoid duplicates
                        while (l < r && num[r-1] == num[r]) r--; // avoid duplicates
                        l++; r--;
                    }
                    else if (sum < twosum) l++;
                    else r--;
                }
            }
        }
        return res;
    }
};/*
 Author:     Annie Kim, anniekim.pku@gmail.com
 Date:       Apr 17, 2013
 Update:     Sep 25, 2013
 Problem:    Add Binary
 Difficulty: Easy
 Source:     http://leetcode.com/onlinejudge#question_67
 Notes:
 Given two binary strings, return their sum (also a binary string).
 For example,
 a = "11"
 b = "1"
 Return "100".

 Solution: '1'-'0' = 1.
 */

class Solution {
public:
    string addBinary(string a, string b) {
        int N = a.size(), M = b.size(), K = max(N, M);
        string res(K, ' ');
        int carry = 0;
        int i = N-1, j = M-1, k = K-1;
        while (i >= 0 || j >= 0)
        {
            int sum = carry;
            if (i >= 0) sum += a[i--] - '0';
            if (j >= 0) sum += b[j--] - '0';
            carry = sum / 2;
            res[k--] = sum % 2 + '0';
        }
        if (carry == 1)
            res.insert(res.begin(), '1');
        return res;
    }
};/*
 Author:     Annie Kim, anniekim.pku@gmail.com
 Date:       Jan 16, 2013
 Update:     Sep 22, 2013
 Problem:    Add Two Numbers
 Difficulty: easy
 Source:     http://www.leetcode.com/onlinejudge
 Notes:
 You are given two linked lists representing two non-negative numbers. 
 The digits are stored in reverse order and each of their nodes contain a single digit. 
 Add the two numbers and return it as a linked list.

 Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
 Output: 7 -> 0 -> 8

 Solution: dummy head...

 */

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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        ListNode dummy(0), *cur = &dummy;
        int carry = 0;
        while (l1 || l2 || carry)
        {
            int sum = carry;
            if (l1) {
                sum += l1->val;
                l1 = l1->next;
            }
            if (l2) {
                sum += l2->val;
                l2 = l2->next;
            }
            carry = sum >= 10 ? 1 : 0;
            sum %= 10;
            ListNode *newNode = new ListNode(sum);
            cur->next = newNode;
            cur = newNode;
        }
        return dummy.next;
    }
};
/*
 Author:     Annie Kim, anniekim.pku@gmail.com
 Date:       Apr 17, 2013
 Update:     Sep 25, 2013
 Problem:    Anagrams
 Difficulty: Easy
 Source:     http://leetcode.com/onlinejudge#question_49
 Notes:
 Given an array of strings, return all groups of strings that are anagrams.
 Note: All inputs will be in lower-case.

 Solution: Sort the string to see if they're anagrams.
           Solution 1 is simpler than 2.
 */

class Solution {
public:
    vector<string> anagrams(vector<string> &strs) {
        return anagrams_1(strs);
    }
    
    // solution 1
    vector<string> anagrams_1(vector<string> &strs) {
        typedef map<string, vector<int> > MAP;
        MAP map;
        for (int i = 0; i < strs.size(); ++i) 
        {
            string s = strs[i];
            sort(s.begin(), s.end());
            map[s].push_back(i);
        }
        vector<string> res;
        MAP::iterator it = map.begin();
        for (; it != map.end(); it++) 
        {
            vector<int> &anagrams = it->second;
            if (anagrams.size() > 1) {
                for (int i = 0; i < anagrams.size(); ++i)
                    res.push_back(strs[anagrams[i]]);
            }
        }
        return res;
    }
    
    // solution 2
    vector<string> anagrams_2(vector<string> &strs) {
        typedef unordered_map<string, int > MAP;
        vector<string> res;
        MAP anagram;
        for (int i = 0; i < strs.size(); ++i)
        {
            string s = strs[i];
            sort(s.begin(), s.end());
            MAP::iterator it = anagram.find(s);
            if (it == anagram.end()) 
            {
                anagram[s] = i;
            } 
            else 
            {
                if (it->second >= 0) {
                    res.push_back(strs[it->second]);
                    it->second = -1;
                }
                res.push_back(strs[i]);
            }
        }
        return res;
    }
};/*
 Author:     Annie Kim, anniekim.pku@gmail.com
 Date:       Apr 10, 2013
 Update:     Aug 4, 2013
 Problem:    Balanced Binary Tree
 Difficulty: Easy
 Source:     http://leetcode.com/onlinejudge#question_110
 Notes:
 Given a binary tree, determine if it is height-balanced.
 For this problem, a height-balanced binary tree is defined as a binary tree in which 
 the depth of the two subtrees of every node never differ by more than 1.

 Solution: DFS.
 */

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isBalanced(TreeNode *root) {
        int height = 0;
        return isBalancedRe(root, height);
    }
    
    bool isBalancedRe(TreeNode *root, int &height){
        if (!root) return true;
        
        int leftHeight = 0, rightHeight = 0;
        if (!isBalancedRe(root->left, leftHeight)) return false;
        if (!isBalancedRe(root->right, rightHeight)) return false;
        if (abs(leftHeight-rightHeight) > 1) return false;
        
        height = 1 + max(leftHeight, rightHeight);
        return true;
    }
};
/*
 Author:     Annie Kim, anniekim.pku@gmail.com
 Date:       Apr 28, 2013
 Problem:    Best Time to Buy and Sell Stock
 Difficulty: Easy
 Source:     http://leetcode.com/onlinejudge#question_121
 Notes:
 Say you have an array for which the ith element is the price of a given stock on day i.
 If you were only permitted to complete at most one transaction (ie, buy one and sell one share of the stock), 
 design an algorithm to find the maximum profit.

 Solution: For each element, calculate the max difference with the former elements.
 */

class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int imin = 0;
        int res = 0;
        for (int i = 1; i < prices.size(); ++i)
        {
            if (prices[i] < prices[imin])
                imin = i;
            res = max(res, prices[i] - prices[imin]);
        }
        return res;
    }
};
/*
 Author:     Annie Kim, anniekim.pku@gmail.com
 Date:       Apr 28, 2013
 Problem:    Best Time to Buy and Sell Stock II
 Difficulty: Medium
 Source:     http://leetcode.com/onlinejudge#question_122
 Notes:
 Say you have an array for which the ith element is the price of a given stock on day i.
 Design an algorithm to find the maximum profit. You may complete as many transactions as you like 
 (ie, buy one and sell one share of the stock multiple times). 
 However, you may not engage in multiple transactions at the same time 
 (ie, you must sell the stock before you buy again).

 Solution: 1. At the beginning of the ascending order: buy.
              At the ending of the ascending order: sell.
           2. For ascending order [1,2,4], (4 - 1) == (2 - 1) + (4 - 2).
 */

class Solution {
public:
    int maxProfit_1(vector<int> &prices) {
        int res = 0;
        int buy_i = -1;
        for (int i = 1; i < prices.size(); ++i)
        {
            if (prices[i] > prices[i-1] && buy_i == -1)
            {
                buy_i = i - 1;
            }
            else if (prices[i] < prices[i -1] && buy_i != -1)
            {
                res += prices[i-1] - prices[buy_i];
                buy_i = -1;
            }
        }
        if (buy_i != -1)
            res += prices[prices.size() - 1] - prices[buy_i];
        return res;
    }

    int maxProfit_2(vector<int> &prices) {
        int res = 0;
        for (int i = 1; i < prices.size(); ++i)
            if (prices[i] > prices[i-1])
                res += prices[i] - prices[i-1];
        return res;
    }
};
/*
 Author:     Annie Kim, anniekim.pku@gmail.com
 Date:       Apr 28, 2013
 Update:     Aug 22, 2013
 Problem:    Best Time to Buy and Sell Stock III
 Difficulty: Medium
 Source:     http://leetcode.com/onlinejudge#question_123
 Notes:
 Say you have an array for which the ith element is the price of a given stock on day i.
 Design an algorithm to find the maximum profit. You may complete at most two transactions.
 Note:
 You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).

 Solution: dp. max profit =  max { l2r[0...i] + r2l[i+1...N-1] }.
                         0 <= i <= N-1
 */

class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int N = prices.size();
        if (N <= 1) return 0;
        
        int l2r[N], r2l[N];
        l2r[0] = 0;
        r2l[N-1] = 0;
        
        int minn = prices[0];
        for (int i = 1; i < N; ++i)
        {
            minn = min(minn, prices[i]);
            l2r[i] = max(l2r[i-1], prices[i] - minn);
        }
        
        int maxx = prices[N-1];
        for (int i = N-2; i >= 0; --i)
        {
            maxx = max(maxx, prices[i]);
            r2l[i] = max(r2l[i+1], maxx - prices[i]);
        }
        
        int res = l2r[N-1];
        for (int i = 0; i < N-1; ++i)
            res = max(res, l2r[i] + r2l[i+1]);
        return res;
    }
};
/*
 Author:     Annie Kim, anniekim.pku@gmail.com
 Date:       Apr 22, 2013
 Update:     Aug 18, 2013
 Problem:    Binary Tree Inorder Traversal
 Difficulty: Easy
 Source:     http://leetcode.com/onlinejudge#question_94
 Notes:
 Given a binary tree, return the inorder traversal of its nodes' values.
 For example:
 Given binary tree {1,#,2,3},
 1
  \
   2
  /
 3
 return [1,3,2].
 Note: Recursive solution is trivial, could you do it iteratively?

 Solution: 1. Iterative way (stack).   Time: O(n), Space: O(n).
           2. Recursive solution.      Time: O(n), Space: O(n).
           3. Threaded tree (Morris).  Time: O(n), Space: O(1).
 */
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> inorderTraversal(TreeNode *root) {
        return inorderTraversal_1(root);
    }
    
    vector<int> inorderTraversal_1(TreeNode *root) {
        vector<int> res;
        stack<TreeNode *> stk;
        TreeNode *cur = root;
        while (cur || !stk.empty())
        {
            if (cur)
            {
                stk.push(cur);
                cur = cur->left;
            }
            else if (!stk.empty())
            {
                res.push_back(stk.top()->val);
                cur = stk.top()->right;
                stk.pop();
            }
        }
        return res;
    }
    
    vector<int> inorderTraversal_2(TreeNode *root) {
        vector<int> res;
        inorderTraversalRe(root, res);
        return res;
    }

    void inorderTraversalRe(TreeNode *node, vector<int> &res) {
        if (!node) return;
        inorderTraversalRe(node->left, res);
        res.push_back(node->val);
        inorderTraversalRe(node->right, res);
    }
    
    vector<int> inorderTraversal_3(TreeNode *root) {
        vector<int> res;
        TreeNode *cur = root;
        while (cur)
        {
            if (cur->left)
            {
                TreeNode *prev = cur->left;
                while (prev->right && prev->right != cur)
                    prev = prev->right;
                    
                if (prev->right == cur)
                {
                    res.push_back(cur->val);
                    cur = cur->right;
                    prev->right = NULL;
                }
                else
                {
                    prev->right = cur;
                    cur = cur->left;
                }
            }
            else
            {
                res.push_back(cur->val);
                cur = cur->right;
            }
        }
        return res;
    }
};
/*
 Author:     Annie Kim, anniekim.pku@gmail.com
 Date:       Apr 6, 2013
 Update:     Aug 15, 2013
 Problem:    Binary Tree Level Order Traversal
 Difficulty: easy
 Source:     http://leetcode.com/onlinejudge#question_102
 Notes:
 Given a binary tree, return the level order traversal of its nodes' values. 
 (ie, from left to right, level by level).

 For example:
 Given binary tree {3,9,20,#,#,15,7},
    3
   / \
  9  20
    /  \
   15   7
 return its level order traversal as:
 [
  [3],
  [9,20],
  [15,7]
 ]
 
 Solution: 1. Use queue. In order to seperate the levels, use 'NULL' as the end indicator of one level.
           2. DFS.
 */

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode *root) {
        return levelOrder_1(root);
    }
    
    vector<vector<int> > levelOrder_1(TreeNode *root) {
        vector<vector<int> > res;
        if (!root) return res;
        queue<TreeNode *> q;
        q.push(root);
        q.push(NULL);
        vector<int> level;
        while (true)
        {
            TreeNode *node = q.front(); q.pop();
            if (!node)
            {
                res.push_back(level);
                level.clear();
                if (q.empty()) break; // end
                q.push(NULL);
            }
            else
            {
                level.push_back(node->val);
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
        }
        return res;
    }
    
    vector<vector<int>> levelOrder_2(TreeNode *root) {
        vector<vector<int>> res;
        levelOrderRe(root, 0, res);
        return res;
    }

    void levelOrderRe(TreeNode *node, int level, vector<vector<int>> &res)
    {
        if (!node) return;
        if (res.size() <= level) res.push_back(vector<int>());
        res[level].push_back(node->val);
        levelOrderRe(node->left, level + 1, res);
        levelOrderRe(node->right, level + 1, res);
    }
};
/*
 Author:     Annie Kim, anniekim.pku@gmail.com
 Date:       Apr 7, 2013
 Problem:    Binary Tree Level Order Traversal II
 Difficulty: easy
 Source:     http://leetcode.com/onlinejudge#question_107
 Notes:
 Given a binary tree, return the bottom-up level order traversal of its nodes' values. 
 (ie, from left to right, level by level from leaf to root).

 For example:
 Given binary tree {3,9,20,#,#,15,7},
    3
   / \
  9  20
    /  \
   15   7
 return its bottom-up level order traversal as:
 [
  [15,7]
  [9,20],
  [3],
 ]
 
 Solution: Queue version. On the basis of 'Binary Tree Level Order Traversal', reverse the final vector.
 */

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<vector<int> > levelOrderBottom(TreeNode *root) {
        vector<vector<int>> root2leaf;
        queue<TreeNode *> q;
        if (!root) return root2leaf;
        q.push(root);
        q.push(NULL);   // end indicator of one level
        vector<int> level;
        while (true)
        {
            TreeNode *node = q.front(); q.pop();
            if (node)
            {
                level.push_back(node->val);
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            else
            {
                root2leaf.push_back(level);
                level.clear();
                if (q.empty()) break;    // CAUTIOUS! infinite loop
                q.push(NULL);
            }
        }
    	// reverse
        reverse(root2leaf.begin(), root2leaf.end());
        return root2leaf;
    }
};/*
 Author:     Annie Kim, anniekim.pku@gmail.com
 Date:       Apr 28, 2013
 Update:     Jul 30, 2013
 Problem:    Binary Tree Maximum Path Sum
 Difficulty: Easy
 Source:     http://leetcode.com/onlinejudge#question_124
 Notes:
 Given a binary tree, find the maximum path sum.
 The path may start and end at any node in the tree.
 For example:
 Given the below binary tree,
   1
  / \
 2   3
 Return 6.

 Solution: Recursion...
 */

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int maxPathSum(TreeNode *root) {
        int res = INT_MIN;
        maxPathSumRe(root, res);
        return res;
    }

    int maxPathSumRe(TreeNode *node, int &res)
    {
        if (!node) return 0;
        int l = maxPathSumRe(node->left, res);
        int r = maxPathSumRe(node->right, res);
        int sum = max(node->val, max(l, r) + node->val);
        res = max(res, sum);
        res = max(res, l + r + node->val);
        return sum;
    }
};
/*
 Author:     Annie Kim, anniekim.pku@gmail.com
 Date:       Nov 11, 2013
 Problem:    Binary Tree Preorder Traversal
 Difficulty: Easy
 Source:     http://oj.leetcode.com/problems/binary-tree-preorder-traversal/
 Notes:
 Given a binary tree, return the preorder traversal of its nodes' values.
 For example:
 Given binary tree {1,#,2,3},
    1
     \
      2
     /
    3
 return [1,2,3].
 Note: Recursive solution is trivial, could you do it iteratively?

 Solution: 1. Iterative way (stack).   Time: O(n), Space: O(n).
           2. Recursive solution.      Time: O(n), Space: O(n).
           3. Threaded tree (Morris).  Time: O(n), Space: O(1).
 */
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> preorderTraversal(TreeNode *root) {
        return preorderTraversal_3(root);
    }
    
    vector<int> preorderTraversal_1(TreeNode *root) {
        vector<int> res;
        stack<TreeNode *> stk;
        TreeNode *cur = root;
        while (cur || !stk.empty())
        {
            if (cur)
            {
                res.push_back(cur->val);
                stk.push(cur);
                cur = cur->left;
            }
            else if (!stk.empty())
            {
                cur = stk.top()->right;
                stk.pop();
            }
        }
        return res;
    }
    
    vector<int> preorderTraversal_2(TreeNode *root) {
        vector<int> res;
        preorderTraversalRe(root, res);
        return res;
    }

    void preorderTraversalRe(TreeNode *node, vector<int> &res) {
        if (!node) return;
        res.push_back(node->val);
        preorderTraversalRe(node->left, res);
        preorderTraversalRe(node->right, res);
    }
    
    vector<int> preorderTraversal_3(TreeNode *root) {
        vector<int> res;
        TreeNode *cur = root;
        while (cur)
        {
            if (cur->left)
            {
                TreeNode *prev = cur->left;
                while (prev->right && prev->right != cur)
                    prev = prev->right;
                    
                if (prev->right == cur)
                {
                    cur = cur->right;
                    prev->right = NULL;
                }
                else
                {
                    res.push_back(cur->val);
                    prev->right = cur;
                    cur = cur->left;
                }
            }
            else
            {
                res.push_back(cur->val);
                cur = cur->right;
            }
        }
        return res;
    }
};/*
 Author:     Annie Kim, anniekim.pku@gmail.com
 Date:       May 16, 2013
 Update:     Sep 12, 2013
 Problem:    Binary Tree Zigzag Level Order Traversal
 Difficulty: Easy
 Source:     http://leetcode.com/onlinejudge#question_103
 Notes:
 Given a binary tree, return the zigzag level order traversal of its nodes' values. (ie, from left 
 to right, then right to left for the next level and alternate between).
 For example:
 Given binary tree {3,9,20,#,#,15,7},
     3
    / \
   9  20
  / \
 15  7
 return its zigzag level order traversal as:
 [
  [3],
  [20,9],
  [15,7]
 ]

 Solution: 1. Queue + reverse.
           2. Two stacks.
           3. Vector. Contributed by yinlinglin.
 */

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode *root) {
        return zigzagLevelOrder_1(root);
    }
    
    // solution 1: Queue + Reverse.
    vector<vector<int>> zigzagLevelOrder_1(TreeNode *root) {
        vector<vector<int>> res;
        if (!root) return res;
        queue<TreeNode *> q;
        q.push(root);
        q.push(NULL);   // end indicator of one level
        bool left2right = true;
        vector<int> level;
        while (true)
        {
            TreeNode *node = q.front(); q.pop();
            if (node)
            {
                level.push_back(node->val);
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            else
            {
                if (!left2right) 
                    reverse(level.begin(), level.end());
                res.push_back(level);
                level.clear();
                if (q.empty()) break;
                q.push(NULL);
                left2right = !left2right;
            }
        }
        return res;
    }
    
    // Solution 2: Two stacks.
    vector<vector<int>> zigzagLevelOrder_2(TreeNode *root) {
        vector<vector<int>> res;
        if (!root) return res;
        stack<TreeNode *> stk[2];
        bool left2right = true;
        int cur = 1, last = 0;
        stk[last].push(root);
        vector<int> level;
        while (!stk[last].empty())
        {
            TreeNode *node = stk[last].top(); 
            stk[last].pop();
            if (node)
            {
                level.push_back(node->val);
                if (left2right)
                {
                    stk[cur].push(node->left);
                    stk[cur].push(node->right);
                }
                else
                {
                    stk[cur].push(node->right);
                    stk[cur].push(node->left);
                }
            }
            if (stk[last].empty())
            {
                if (!level.empty())
                    res.push_back(level);
                level.clear();
                swap(cur, last);
                left2right = !left2right;
            }
        }
        return res;
    }
    
    // Solution 3: Vector. Contributed by yinlinglin.
    // Compared to solution 1&2, this solution costs a little more space.
    // This solution uses only one single vector instead of two stacks in solution 2.
    vector<vector<int>> zigzagLevelOrder_3(TreeNode *root) {
        vector<vector<int>> result;
        if(!root) return result;
        vector<TreeNode*> v;
        v.push_back(root);
        bool left2right = true;
        int begin = 0, end = 0;
        while(begin <= end)
        {
            vector<int> row;
            for (int i = end; i >= begin; --i)
            {
                if (!v[i]) continue;
                row.push_back(v[i]->val);
                if(left2right)
                {
                    v.push_back(v[i]->left);
                    v.push_back(v[i]->right);
                }
                else
                {
                    v.push_back(v[i]->right);
                    v.push_back(v[i]->left);
                }
            }
            if (!row.empty())
                result.push_back(row);
            begin = end + 1;
            end = v.size() - 1;
            left2right = !left2right;
        }
        return result;
    }
};
/*
 Author:     Annie Kim, anniekim.pku@gmail.com
 Date:       Oct 3, 2013
 Problem:    Candy
 Difficulty: Easy
 Source:     http://oj.leetcode.com/problems/candy/
 Notes:
 There are N children standing in a line. Each child is assigned a rating value.
 You are giving candies to these children subjected to the following requirements:
 - Each child must have at least one candy.
 - Children with a higher rating get more candies than their neighbors.
 What is the minimum candies you must give?

 Solution: You may refer to https://github.com/AnnieKim/ITint5/blob/master/031_%E5%88%86%E9%85%8D%E7%B3%96%E6%9E%9C.cpp
           1. traverse only once with O(1) space. 2. O(n) space.
*/

class Solution {
public:
    int candy(vector<int> &ratings) {
        return candy_1(ratings);
    }
    
    int candy_1(vector<int> &ratings) {
        int N = ratings.size();
        if (N == 0) return 0;
        int candy = 1, res = 1;
        int maxValue = 1, maxIndex = 0;
        for (int i = 1; i < N; ++i)
        {
            if (ratings[i] >= ratings[i-1]) 
            {
                candy = ratings[i] == ratings[i-1] ? 1 : candy + 1;
                maxValue = candy;
                maxIndex = i;
            }
            else
            {
                if (candy == 1) {
                    if (maxValue <= i - maxIndex) {
                        res += i - maxIndex;
                        maxValue++;
                    } else {
                        res += i - maxIndex - 1;
                    }
                }
                candy = 1;
            }
            res += candy;
        }
        return res;
    }
    
    int candy_2(vector<int> &ratings) {
        int N = ratings.size();
        if (N == 0) return 0;
        int candy[N];
        for (int i = 0; i < N; ++i)
            candy[i] = 1;
        for (int i = 1; i < N; ++i)
            if (ratings[i] > ratings[i-1])
                candy[i] = candy[i-1] + 1;
        for (int i = N-2; i >= 0; --i)
            if (ratings[i] > ratings[i+1] && candy[i] <= candy[i+1])
                candy[i] = candy[i+1] + 1;
        int res = 0;
        for (int i = 0; i < N; ++i)
            res += candy[i];
        return res;
    }
};/*
 Author:     Annie Kim, anniekim.pku@gmail.com
 Date:       May 8, 2013
 Problem:    Climbing Stairs
 Difficulty: Easy
 Source:     http://leetcode.com/onlinejudge#question_70
 Notes:
 You are climbing a stair case. It takes n steps to reach to the top.
 Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

 Solution: Clime one step from last stair or clime 2 steps from the last last stair.
 */

class Solution {
public:
    int climbStairs(int n) {
        int last = 1;
        int lastlast = 1;
        for (int i = 2; i <= n; i++)
        {
            int step = last + lastlast;
            lastlast = last;
            last = step;
        }
        return last;
    }
};/*
 Author:     Annie Kim, anniekim.pku@gmail.com
 Date:       Sep 26, 2013
 Problem:    Clone Graph
 Difficulty: Easy
 Source:     http://oj.leetcode.com/problems/clone-graph/
 Notes:
 Clone an undirected graph. Each node in the graph contains a label and a list of its neighbors.
 
 OJ's undirected graph serialization:
 Nodes are labeled from 0 to N - 1, where N is the total nodes in the graph.
 We use # as a separator for each node, and , as a separator for each neighbor of the node.
 As an example, consider the serialized graph {1,2#2#2}.
 The graph has a total of three nodes, and therefore contains three parts as separated by #.
 Connect node 0 to both nodes 1 and 2.
 Connect node 1 to node 2.
 Connect node 2 to node 2 (itself), thus forming a self-cycle.
 Visually, the graph looks like the following:

       1
      / \
     /   \
    0 --- 2
         / \
         \_/

 Solution: 1. DFS. 2. BFS.
 */

/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
public:
    typedef UndirectedGraphNode GraphNode;
    typedef unordered_map<GraphNode *, GraphNode *> MAP;
    
    GraphNode *cloneGraph(GraphNode *node) {
        return cloneGraph_1(node);
    }
    
    // DFS
    GraphNode *cloneGraph_1(GraphNode *node) {
        MAP map;
        return cloneGraphRe(node, map);
    }
    
    GraphNode *cloneGraphRe(GraphNode *node, MAP &map) {
        if (!node) return NULL;
        if (map.find(node) != map.end())
            return map[node];
        GraphNode *newNode = new GraphNode(node->label);
        map[node] = newNode;
        for (int i = 0; i < node->neighbors.size(); ++i)
            newNode->neighbors.push_back(cloneGraphRe(node->neighbors[i], map));
        return newNode;
    }
    
    // BFS
    GraphNode *cloneGraph_2(GraphNode *node) {
        if (!node) return NULL;
        queue<GraphNode*> q;
        q.push(node);
        MAP map;
        map[node] = new GraphNode(node->label);
        while (!q.empty())
        {
            GraphNode *oriNode = q.front(); q.pop();
            GraphNode *newNode = map[oriNode];
            for (int i = 0; i < oriNode->neighbors.size(); ++i)
            {
                GraphNode *oriNeighbor = oriNode->neighbors[i];
                if (map.find(oriNeighbor) != map.end()) {
                    newNode->neighbors.push_back(map[oriNeighbor]);
                    continue;
                }
                GraphNode *newNeighbor = new GraphNode(oriNeighbor->label);
                newNode->neighbors.push_back(newNeighbor);
                map[oriNeighbor] = newNeighbor;
                q.push(oriNeighbor);
            }
        }
        return map[node];
    }
};/*
 Author:     Annie Kim, anniekim.pku@gmail.com
 Date:       May 25, 2013
 Problem:    Combination Sum
 Difficulty: Easy
 Source:     http://leetcode.com/onlinejudge#question_39
 Notes:
 Given a set of candidate numbers (C) and a target number (T), find all unique 
 combinations in C where the candidate numbers sums to T.
 The same repeated number may be chosen from C unlimited number of times.
 Note:
 All numbers (including target) will be positive integers.
 Elements in a combination (a1, a2, .. , ak) must be in non-descending order. (ie, a1 <= a2 <= ... <= ak).
 The solution set must not contain duplicate combinations.
 For example, given candidate set 2,3,6,7 and target 7, 
 A solution set is: 
 [7] 
 [2, 2, 3] 

 Solution: Sort & Recursion.
*/

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int> &candidates, int target) {
        vector<vector<int>> res;
        sort(candidates.begin(), candidates.end());
        vector<int> com;
        combinationSumRe(candidates, target, 0, com, res);
        return res;
    }

    void combinationSumRe(const vector<int> &num, int target, int start, vector<int> &com, vector<vector<int>> &res)
    {
        if (target == 0) {
            res.push_back(com);
            return;
        }
        for (int i = start; i < num.size() && target >= num[i]; ++i) {
            com.push_back(num[i]);
            combinationSumRe(num, target-num[i], i, com, res);
            com.pop_back();
        }
    }
};/*
 Author:     Annie Kim, anniekim.pku@gmail.com
 Date:       May 6, 2013
 Problem:    Combination Sum II
 Difficulty: Easy
 Source:     http://leetcode.com/onlinejudge#question_40
 Notes:
 Given a collection of candidate numbers (C) and a target number (T), find all unique combinations
 in C where the candidate numbers sums to T.
 Each number in C may only be used once in the combination.
 Note:
 All numbers (including target) will be positive integers.
 Elements in a combination (a1, a2, .. , ak) must be in non-descending order. (ie, a1 <= a2 <= ... <= ak).
 The solution set must not contain duplicate combinations.
 For example, given candidate set 10,1,2,7,6,1,5 and target 8, 
 A solution set is: 
 [1, 7] 
 [1, 2, 5] 
 [2, 6] 
 [1, 1, 6] 

 Solution: ..Similar to Combination Sum I, except for line 42 && 44.
 */

class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int> &num, int target) {
        vector<vector<int>> res;
        sort(num.begin(), num.end());
        vector<int> com;
        combinationSum2Re(num, target, 0, com, res);
        return res;
    }

    void combinationSum2Re(const vector<int> &num, int target, int start, vector<int> &com, vector<vector<int>> &res)
    {
        if (target == 0) {
            res.push_back(com);
            return;
        }
        for (int i = start; i < num.size() && num[i] <= target; ++i) {
            if (i > start && num[i] == num[i-1]) continue;
            com.push_back(num[i]);
            combinationSum2Re(num, target-num[i], i+1, com, res);
            com.pop_back();
        }
    }
};/*
 Author:     Annie Kim, anniekim.pku@gmail.com
 Date:       May 5, 2013
 Update:     Sep 28, 2013
 Problem:    Combinations
 Difficulty: Easy
 Source:     http://leetcode.com/onlinejudge#question_77
 Notes:
 Given two integers n and k, return all possible combinations of k numbers out of 1 ... n.
 For example,
 If n = 4 and k = 2, a solution is:
 [
    [2,4],
    [3,4],
    [2,3],
    [1,2],
    [1,3],
    [1,4],
 ]

 Solution: DFS.
 */

class Solution {
public:
    vector<vector<int> > combine(int n, int k) {
        vector<vector<int> > res;
        vector<int> com;
        combineRe(n, k, 1, com, res);
        return res;
    }
    
    void combineRe(int n, int k, int start, vector<int> &com, vector<vector<int> > &res){
        int m = com.size();
        if (m == k) {
            res.push_back(com);
            return;
        }
        for (int i = start; i <= n-(k-m)+1; ++i) {
            com.push_back(i);
            combineRe(n, k, i+1, com, res);
            com.pop_back();
        }
    }
};/*
 Author:     Annie Kim, anniekim.pku@gmail.com
 Date:       May 16, 2013
 Problem:    Construct Binary Tree from Inorder and Postorder Traversal
 Difficulty: Easy
 Source:     http://leetcode.com/onlinejudge#question_106
 Notes:
 Given inorder and postorder traversal of a tree, construct the binary tree.
 Note:
 You may assume that duplicates do not exist in the tree.

 Solution: Recursion.
 */

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        int N = inorder.size();
        return buildTreeRe(inorder.begin(), postorder.begin(), N);
    }

    TreeNode *buildTreeRe(vector<int>::iterator inorder, vector<int>::iterator postorder, int N) {
        if (N <= 0) return NULL;
        vector<int>::iterator it = find(inorder, inorder+N, *(postorder+N-1));
        int pos = it - inorder;
        TreeNode *root = new TreeNode(*(postorder+N-1));
        root->left = buildTreeRe(inorder, postorder, pos);
        root->right = buildTreeRe(inorder+pos+1, postorder+pos, N-pos-1);
        return root;
    }
};/*
 Author:     Annie Kim, anniekim.pku@gmail.com
 Date:       May 16, 2013
 Problem:    Construct Binary Tree from Preorder and Inorder Traversal
 Difficulty: Easy
 Source:     http://leetcode.com/onlinejudge#question_105
 Notes:
 Given preorder and inorder traversal of a tree, construct the binary tree.
 Note:
 You may assume that duplicates do not exist in the tree.

 Solution: Recursion.
 */

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        return buildTreeRe(preorder.begin(), inorder.begin(), preorder.size());
    }

    TreeNode *buildTreeRe(vector<int>::iterator preorder, vector<int>::iterator inorder, int N) {
        if (N <= 0) return NULL;
        vector<int>::iterator it = find(inorder, inorder + N, *preorder);
        int pos = it - inorder;
        TreeNode *root = new TreeNode(*preorder);
        root->left = buildTreeRe(preorder+1, inorder, pos);
        root->right = buildTreeRe(preorder+1+pos, inorder+pos+1, N-1-pos);
        return root;
    }
};/*
 Author:     Annie Kim, anniekim.pku@gmail.com
 Date:       Apr 16, 2013
 Update:     Aug 22, 2013
 Problem:    Container With Most Water
 Difficulty: Easy
 Source:     http://leetcode.com/onlinejudge#question_11
 Notes:
 Given n non-negative integers a1, a2, ..., an, where each represents a point at coordinate (i, ai). 
 n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0). 
 Find two lines, which together with x-axis forms a container, such that the container contains the most water.
 Note: You may not slant the container.

 Solution: From both sides to the center.
*/

class Solution {
public:
    int maxArea(vector<int> &height) {
        int res = 0;
        int l = 0, r = height.size()-1;
        while (l < r)
        {
            if (height[l] <= height[r])
            {
                res = max(res, (r-l) * height[l]);
                l++;
            }
            else
            {
                res = max(res, (r-l) * height[r]);
                r--;
            }
        }
        return res;
    }
};
/*
 Author:     Annie Kim, anniekim.pku@gmail.com
 Date:       Apr 9, 2013
 Problem:    Convert Sorted Array to Binary Search Tree
 Difficulty: Easy
 Source:     http://leetcode.com/onlinejudge#question_108
 Notes:
 Given an array where elements are sorted in ascending order, convert it to a height balanced BST.

 Solution: Recursion.
 */

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode *sortedArrayToBST(vector<int> &num) {
        return buildBST(num, 0, num.size() - 1);
    }
    
    TreeNode *buildBST(vector<int> &num, int start, int end)
    {
        if (start > end) return NULL;

        int mid = (start + end) / 2;
        TreeNode *root = new TreeNode(num[mid]);
        root->left = buildBST(num, start, mid - 1);
        root->right = buildBST(num, mid + 1, end);

        return root;
    }
};/*
 Author:     Annie Kim, anniekim.pku@gmail.com
 Date:       Apr 10, 2013
 Update:     Jul 29, 2013
 Problem:    Convert Sorted List to Binary Search Tree
 Difficulty: Medium
 Source:     http://leetcode.com/onlinejudge#question_109
 Notes:
 Given a singly linked list where elements are sorted in ascending order, convert it to a height balanced BST.

 Solution: Recursion. Pre-order. O(n)
 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode *sortedListToBST(ListNode *head) {
        return sortedListToBSTRe(head, getLength(head));
    }
    
    TreeNode *sortedListToBSTRe(ListNode *&head, int length)
    {
        if (length == 0) return NULL;
        int mid = length / 2;
        TreeNode *left = sortedListToBSTRe(head, mid);
        TreeNode *root = new TreeNode(head->val);
        TreeNode *right = sortedListToBSTRe(head->next, length - mid - 1);
        root->left = left;
        root->right = right;
        head = head->next;
        return root;
    }
    
    int getLength(ListNode *head)
    {
        int length = 0;
        while (head)
        {
            length++;
            head = head->next;
        }
        return length;
    }
};
/*
 Author:     Annie Kim, anniekim.pku@gmail.com
 Date:       Oct 5, 2013
 Problem:    Copy List with Random Pointer
 Difficulty: Easy
 Source:     http://oj.leetcode.com/problems/copy-list-with-random-pointer/
 Notes:
 A linked list is given such that each node contains an additional random pointer 
 which could point to any node in the list or null.
 Return a deep copy of the list.

 Solution: Solution 1 uses constant extra space.
*/

/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        return copyRandomList_1(head);
    }
    
    RandomListNode *copyRandomList_1(RandomListNode *head) {
        for (RandomListNode *cur = head; cur; cur = cur->next->next) {
            RandomListNode *newNode = new RandomListNode(cur->label);
            newNode->next = cur->next;
            cur->next = newNode;
        }
        
        for (RandomListNode *cur = head; cur; cur = cur->next->next)
            if (cur->random)
                cur->next->random = cur->random->next;
        
        RandomListNode dummy(0), *curNew = &dummy;
        for (RandomListNode *cur = head; cur; cur = cur->next) {
            curNew->next = cur->next;
            curNew = curNew->next;
            cur->next = cur->next->next;
        }
        return dummy.next;
    }
    
    RandomListNode *copyRandomList_2(RandomListNode *head) {
        if (!head) return NULL;
        unordered_map<RandomListNode *, RandomListNode *> map;
        RandomListNode dummy(0), *curNew = &dummy, *cur = head;
        while (cur) 
        {
            if (map.find(cur) == map.end())
                map[cur] = new RandomListNode(cur->label);
            if (cur->random && map.find(cur->random) == map.end())
                map[cur->random] = new RandomListNode(cur->random->label);
            curNew->next = map[cur];
            curNew = curNew->next;
            curNew->random = map[cur->random];
            cur = cur->next;
        }
        return dummy.next;
    }
};/*
 Author:     Annie Kim, anniekim.pku@gmail.com
 Date:       Apr 8, 2013
 Update:     Aug 10, 2013
 Problem:    Count and Say
 Difficulty: Easy
 Source:     http://leetcode.com/onlinejudge#question_38
 Notes:
 The count-and-say sequence is the sequence of integers beginning as follows:
 1, 11, 21, 1211, 111221, ...

 1 is read off as "one 1" or 11.
 11 is read off as "two 1s" or 21.
 21 is read off as "one 2, then one 1" or 1211.
 Given an integer n, generate the nth sequence.
 Note: The sequence of integers will be represented as a string.

 Solution: ...
*/

class Solution {
public:
    string countAndSay(int n) {
        string res = "1";
        for (int i = 2; i <= n; ++i)
        {
            stringstream ss;
            int j = 0, N = res.size();
            while (j < N) {
                int k = j + 1;
                while (k < N && res[k] == res[j])
                    k++;
                ss << (k - j) << res[j];
                j = k;
            }
            ss >> res;
        }
        return res;
    }
};
/*
 Author:     Annie Kim, anniekim.pku@gmail.com
 Date:       May 20, 2013
 Problem:    Decode Ways
 Difficulty: Easy
 Source:     http://leetcode.com/onlinejudge#question_91
 Notes:
 A message containing letters from A-Z is being encoded to numbers using the following mapping:
 'A' -> 1
 'B' -> 2
 ...
 'Z' -> 26
 Given an encoded message containing digits, determine the total number of ways to decode it.
 For example,
 Given encoded message "12", it could be decoded as "AB" (1 2) or "L" (12).
 The number of ways decoding "12" is 2.

 Solution: dp. Note that '0' must be decoded in together with the number in front of it.
 */

class Solution {
public:
    int numDecodings(string s) {
        if (s.empty() || s[0] == '0') 
            return 0;
        int N = s.size();
        int dp[N+1];
        dp[0] = 1;
        dp[1] = 1;
        for (int i = 1; i < N; ++i)
        {
            if (s[i] == '0')
            {
                if (s[i-1] != '1' && s[i-1] != '2')
                    return 0;
                dp[i+1] = dp[i-1];
            }
            else
            {
                int num = s[i] - '0' + (s[i-1] - '0') * 10;
                if (num >= 11 && num <= 26)
                    dp[i+1] = dp[i] + dp[i-1];
                else
                    dp[i+1] = dp[i];
            }
        }
        return dp[N];
    }
};/*
 Author:     Annie Kim, anniekim.pku@gmail.com
 Date:       May 16, 2013
 Problem:    Distinct Subsequences
 Difficulty: Easy
 Source:     http://leetcode.com/onlinejudge#question_115
 Notes:
 Given a string S and a string T, count the number of distinct subsequences of T in S.
 A subsequence of a string is a new string which is formed from the original string by deleting 
 some (can be none) of the characters without disturbing the relative positions of the remaining characters. (ie, "ACE" is a subsequence of "ABCDE" while "AEC" is not).
 
 Here is an example:
 S = "rabbbit", T = "rabbit"
 Return 3.

 Solution: dp.
 */

class Solution {
public:
    int numDistinct(string S, string T) {
        int N = S.size(), M = T.size();
        int dp[M+1][N+1];
        dp[0][0] = 1;
        for (int j = 1; j <= N; ++j)
            dp[0][j] = 1;
        for (int i = 1; i <= M; ++i)
            dp[i][0] = 0;

        for (int i = 1; i <= M; ++i)
            for (int j = 1; j <= N; ++j)
                if (S[j-1] == T[i-1])
                    dp[i][j] = dp[i][j-1] + dp[i-1][j-1];
                else
                    dp[i][j] = dp[i][j-1];

        return dp[M][N];
    }
};/*
 Author:     Annie Kim, anniekim.pku@gmail.com
 Date:       Jul 8, 2013
 Update:     Sep 25, 2013
 Problem:    Divide Two Integers
 Difficulty: Medium
 Source:     http://leetcode.com/onlinejudge#question_29
 Notes:
 Divide two integers without using multiplication, division and mod operator.

 Solution: Use << operator.
*/

class Solution {
public:
    int divide(int dividend, int divisor) {
        assert(divisor != 0);
        bool flag = dividend > 0 && divisor < 0 || 
                    dividend < 0 && divisor > 0;
        long long dividendll = abs((long long)dividend);
        long long divisorll = abs((long long)divisor);
        int res = 0;
        while (dividendll >= divisorll)
        {
            long long div = divisorll;
            int quot = 1;
            while ((div << 1) <= dividendll) {
                div <<= 1;
                quot <<= 1;
            }
            dividendll -= div;
            res += quot;
        }
        return flag ? -res : res;
    }
};
/*
 Author:     Annie Kim, anniekim.pku@gmail.com
 Date:       Apr 7, 2013
 Update:     Sep 28, 2013
 Problem:    Edit Distance
 Difficulty: Medium
 Source:     http://leetcode.com/onlinejudge#question_72
 Notes:
 Given two words word1 and word2, find the minimum number of steps required to convert word1 to word2. (each operation is counted as 1 step.)
 You have the following 3 operations permitted on a word:
 a) Insert a character
 b) Delete a character
 c) Replace a character

 Solution: Dynamic Programming.
           1. Time: O(mn) Space: O(mn)
           2. Time: O(mn) Space: O(n);
 */

class Solution {
public:
    int minDistance(string word1, string word2) {
        return minDistance_2(word1, word2);
    }
    
    int minDistance_1(string word1, string word2) {
        int M = word1.size(), N = word2.size();
        int dp[N+1][M+1];
        for (int j = 0; j <= M; j++)
            dp[0][j] = j;
        for (int i = 0; i <= N; i++)
            dp[i][0] = i;
        for (int i = 1; i <= N; i++)
            for (int j = 1; j <= M; j++)
                if (word2[i-1] == word1[j-1])
                    dp[i][j] = dp[i-1][j-1];
                else
                    dp[i][j] = min(dp[i-1][j-1], min(dp[i][j-1], dp[i-1][j])) + 1;
        
        return dp[N][M];
    }
    
    int minDistance_2(string word1, string word2) {
        int M = word1.size(), N = word2.size();
        int dp[N+1];
        for (int j = 0; j <= N; ++j)
            dp[j] = j;
        for (int i = 1; i <= M; ++i)
        {
            int upperLeftBackup = dp[0];
            dp[0] = i;
            for (int j = 1; j <= N; ++j)
            {
                int upperLeft = upperLeftBackup;
                upperLeftBackup = dp[j];
                if (word1[i-1] == word2[j-1])
                    dp[j] = upperLeft;
                else
                    dp[j] = min(min(dp[j-1], dp[j]), upperLeft) + 1;
            }
        }
        return dp[N];
    }
};/*
 Author:     Annie Kim, anniekim.pku@gmail.com
 Date:       Apr 21, 2013
 Problem:    First Missing Positive
 Difficulty: Medium
 Source:     http://leetcode.com/onlinejudge#question_41
 Notes:
 Given an unsorted integer array, find the first missing positive integer.
 For example,
 Given [1,2,0] return 3,
 and [3,4,-1,1] return 2.
 Your algorithm should run in O(n) time and uses constant space.

 Solution: Although we can only use constant space, we can still exchange elements within input A!
           Swap elements in A and try to make all the elements in A satisfy: A[i] == i + 1.
           Pick out the first one that does not satisfy A[i] == i + 1.
 */

class Solution {
public:
    int firstMissingPositive(int A[], int n) {
        int i = 0;
        while (i < n)
        {
            if (A[i] != (i+1) && A[i] >= 1 && A[i] <= n && A[A[i]-1] != A[i])
                swap(A[i], A[A[i]-1]);
            else
                i++;
        }
        for (i = 0; i < n; ++i)
            if (A[i] != (i+1))
                return i+1;
        return n+1;
    }
};/*
 Author:     Annie Kim, anniekim.pku@gmail.com
 Date:       Apr 28, 2013
 Update:     Sep 29, 2013
 Problem:    Flatten Binary Tree to Linked List
 Difficulty: Medium
 Source:     http://leetcode.com/onlinejudge#question_114
 Notes:
 Given a binary tree, flatten it to a linked list in-place.
 For example,
 Given
     1
    / \
   2   5
  / \   \
 3   4   6
 The flattened tree should look like:
 1
  \
   2
    \
     3
      \
       4
        \
         5
          \
           6
 Hints:
 If you notice carefully in the flattened tree, each node's right child points to the next node 
 of a pre-order traversal.

 Solution: Recursion. Return the last element of the flattened sub-tree.
 */

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void flatten(TreeNode *root) {
        TreeNode *end = NULL;
        flattenRe(root, end);
    }
    
    void flattenRe(TreeNode *node, TreeNode *&end) {
        if (!node) return;
        TreeNode *lend = NULL, *rend = NULL;
        flattenRe(node->left, lend);
        flattenRe(node->right, rend);
        if (node->left) {
            lend->right = node->right;
            node->right = node->left;
            node->left = NULL;
        }
        end = rend ? rend : (lend ? lend : node);
    }
};/*
 Author:     Annie Kim, anniekim.pku@gmail.com
 Date:       Oct 3, 2013
 Problem:    Gas Station
 Difficulty: Easy
 Source:     http://oj.leetcode.com/problems/gas-station/
 Notes:
 There are N gas stations along a circular route, where the amount of gas at station i is gas[i].
 You have a car with an unlimited gas tank and it costs cost[i] of gas to travel from station i to its next station (i+1). You begin the journey with an empty tank at one of the gas stations.
 Return the starting gas station's index if you can travel around the circuit once, otherwise return -1.
 The solution is guaranteed to be unique.

 Solution: ...
*/

class Solution {
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
        int N = gas.size();
        int res = 0, min = gas[0] - cost[0], sum = min;
        for (int i = 1; i < N; ++i)
        {
            sum += gas[i] - cost[i];
            if (sum < min) {
                min = sum;
                res = i;
            }
        }
        return sum >= 0 ? (res + 1) % N : -1;
    }
};/*
 Author:     Annie Kim, anniekim.pku@gmail.com
 Date:       May 17, 2013
 Update:     Jul 20, 2013
 Problem:    Generate Parentheses
 Difficulty: Easy
 Source:     http://leetcode.com/onlinejudge#question_22
 Notes:
 Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.
 For example, given n = 3, a solution set is:
 "((()))", "(()())", "(())()", "()(())", "()()()"

 Solution: Place n left '(' and n right ')'.
           Cannot place ')' if there are no enough matching '('.
 */

class Solution {
public:
    vector<string> res;
    vector<string> generateParenthesis(int n) {
        res.clear();
        generateParenthesisRe(n, n, "");
        return res;
    }

    void generateParenthesisRe(int left, int right, string s) {
        if (left == 0 && right == 0)
            res.push_back(s);
        if (left > 0)
            generateParenthesisRe(left - 1, right, s + "(");
        if (right > left)
            generateParenthesisRe(left, right - 1, s + ")");
    }
};
/*
 Author:     Annie Kim, anniekim.pku@gmail.com
 Date:       May 16, 2013
 Problem:    Gray Code
 Difficulty: Easy
 Source:     http://leetcode.com/onlinejudge#question_89
 Notes:
 The gray code is a binary numeral system where two successive values differ in only one bit.
 Given a non-negative integer n representing the total number of bits in the code, print the 
 sequence of gray code. A gray code sequence must begin with 0.
 For example, given n = 2, return [0,1,3,2]. Its gray code sequence is:
 00 - 0
 01 - 1
 11 - 3
 10 - 2
 Note:
 For a given n, a gray code sequence is not uniquely defined.
 For example, [0,2,3,1] is also a valid gray code sequence according to the above definition.
 For now, the judge is able to judge based on one instance of gray code sequence. Sorry about that.

 Solution: Refer to http://en.wikipedia.org/wiki/Gray_code.
 */

class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> result(1 << n, 0);
        for (int i = 0; i < 1 << n; ++i)
            result[i] = (i >> 1) ^ i;
        return result;
    }
};
/*
 Author:     Annie Kim, anniekim.pku@gmail.com
 Date:       Apr 9, 2013
 Update:     Jul 19, 2013 (Refactor)
 Problem:    Implement strStr()
 Difficulty: Easy
 Source:     http://leetcode.com/onlinejudge#question_28
 Notes:
 Implement strStr().
 Returns a pointer to the first occurrence of needle in haystack, or null if needle is not part of haystack.

 Solution: Check in the haystack one by one. If not equal to needle, reset the pointer.
 */

class Solution {
public:
    char *strStr(char *haystack, char *needle) {
        while(true)
        {
            char *h = haystack, *n = needle;
            while (*n != '\0' && *h == *n)
            {
                h++; 
                n++;
            }
            if (*n == '\0') return haystack;
            if (*h == '\0') return NULL;
            haystack++;
        }
    }
};
/*
 Author:     Annie Kim, anniekim.pku@gmail.com
 Date:       Jun 7, 2013
 Problem:    Insert Interval
 Difficulty: Medium
 Source:     http://leetcode.com/onlinejudge#question_57
 Notes:
 Given a set of non-overlapping intervals, insert a new interval into the intervals (merge if necessary).
 You may assume that the intervals were initially sorted according to their start times.
 Example 1:
 Given intervals [1,3],[6,9], insert and merge [2,5] in as [1,5],[6,9].
 Example 2:
 Given [1,2],[3,5],[6,7],[8,10],[12,16], insert and merge [4,9] in as [1,2],[3,10],[12,16].
 This is because the new interval [4,9] overlaps with [3,5],[6,7],[8,10].

 Solution: For example 2:
           1. compare [1,2] with [4,9], then insert [1,2];
           2. merge [3,5] with [4,9], get newInterval = [3,9];
           3. merge [6,7] with [3,9], get newInterval = [3,9];
           4. merge [8,10] with [3,9], get newInterval = [3,10];
           5. compare [12,16] with [3,10], insert newInterval [3,10], then all the remaining intervals...
*/

/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
        vector<Interval> res;
        vector<Interval>::iterator it = intervals.begin();
        bool inserted = false;
        for (; it != intervals.end(); ++it)
        {
            if (inserted || it->end < newInterval.start) // non-overlaping
            {
                res.push_back(*it);
            }
            else if (newInterval.end < it->start)
            {
                res.push_back(newInterval);
                res.push_back(*it);
                inserted = true;
            }
            else
            {
                newInterval.start = min(it->start, newInterval.start);
                newInterval.end = max(it->end, newInterval.end);
            }
        }
        if (!inserted)
            res.push_back(newInterval);
        return res;
    }
};/*
 Author:     Annie Kim, anniekim.pku@gmail.com
 Date:       May 13, 2013
 Problem:    Integer to Roman
 Difficulty: Easy
 Source:     http://leetcode.com/onlinejudge#question_12
 Notes:
 Given an integer, convert it to a roman numeral.
 Input is guaranteed to be within the range from 1 to 3999.

 Solution: Buffer the roman numbers.
 */

class Solution {
public:
    const string rom[4][10] = {{"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"},
                               {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"},
                               {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"},
                               {"", "M", "MM", "MMM"}};
    string intToRoman(int num) {
        string res;
        int i = 3;
        while (num > 0)
        {
            int divisor = (int)pow(10, i);
            res += rom[i][num / divisor];
            num %= divisor;
            i--;
        }
        return res;
    }
};
/*
 Author:     Annie Kim, anniekim.pku@gmail.com
 Date:       May 6, 2013
 Problem:    Interleaving String
 Difficulty: Medium
 Source:     http://leetcode.com/onlinejudge#question_97
 Notes:
 Given s1, s2, s3, find whether s3 is formed by the interleaving of s1 and s2.
 For example,
 Given:
 s1 = "aabcc",
 s2 = "dbbca",
 When s3 = "aadbbcbcac", return true.
 When s3 = "aadbbbaccc", return false.

 Solution: 1. dp. O(MN) time & space. 'dp[i][j] == true' means that there is at least one way to construct 
              the string s3[0...i+j-1] by interleaving s1[0...j-1] and s2[0...i-1].
           2. Recursion. Okay for Small but TLE for Large Test data.
 */

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        return isInterleave_1(s1, s2, s3);
    }

    bool isInterleave_1(string s1, string s2, string s3) {
        int M = s1.size(), N = s2.size(), K = s3.size();
        if (M + N != K) return false;
        
        int dp[N+1][M+1];
        for (int i = 1; i <= N; ++i)
            dp[i][0] = s2[i-1] == s3[i-1];
        for (int j = 1; j <= M; ++j)
            dp[0][j] = s1[j-1] == s3[j-1];

        for (int i = 1; i <= N; ++i)
            for (int j = 1; j <= M; ++j)
                dp[i][j] = dp[i-1][j] && s2[i-1] == s3[i+j-1] ||
                           dp[i][j-1] && s1[j-1] == s3[i+j-1];

        return dp[N][M];
    }
    
    bool isInterleave_2(string s1, string s2, string s3) {
        return isInterleaveRe(s1.c_str(), s2.c_str(), s3.c_str());
    }

    bool isInterleaveRe(const char *s1, const char *s2, const char *s3)
    {
        if (*s1 == '\0' && *s2 == '\0' && *s3 == '\0') return true;
        if (*s3 == '\0') return false;
        if (*s1 == '\0') return strcmp(s2, s3) == 0;
        if (*s2 == '\0') return strcmp(s1, s3) == 0;

        return *s1 == *s3 && isInterleaveRe(s1+1, s2, s3+1) || 
               *s2 == *s3 && isInterleaveRe(s1, s2+1, s3+1);
    }
};
/*
 Author:     Annie Kim, anniekim.pku@gmail.com
 Date:       Apr 21, 2013
 Update:     Jul 12, 2013
 Problem:    Jump Game
 Difficulty: Easy
 Source:     http://leetcode.com/onlinejudge#question_55
 Notes:
 Given an array of non-negative integers, you are initially positioned at the first index of the array.
 Each element in the array represents your maximum jump length at that position.
 Determine if you are able to reach the last index.
 For example:
 A = [2,3,1,1,4], return true.
 A = [3,2,1,0,4], return false.

 Solution: Updated solution: try every reachable index. 
           Thank to Wenxin Xing for kindly feedback and pointing out my big mistake:)
 */

class Solution {
public:
    bool canJump(int A[], int n) {
        int start = 0, end = 0;
        while (start <= end && end < n-1)
        {
            end = max(end, start + A[start]);
            start++;
        }
        return end >= (n-1);
    }
};
/*
 Author:     Annie Kim, anniekim.pku@gmail.com
 Date:       Apr 21, 2013
 Update:     Aug 22, 2013
 Problem:    Jump Game II
 Difficulty: Easy
 Source:     http://leetcode.com/onlinejudge#question_45
 Notes:
 Given an array of non-negative integers, you are initially positioned at the first index of the array.
 Each element in the array represents your maximum jump length at that position.
 Your goal is to reach the last index in the minimum number of jumps.
 For example:
 Given array A = [2,3,1,1,4]
 The minimum number of jumps to reach the last index is 2. (Jump 1 step from index 0 to 1, then 3 steps to the last index.)

 Solution: Jump to the position where we can jump farthest (index + A[index]) next time.
 */

class Solution {
public:
    int jump(int A[], int n) {
        int start = 0;
        int res = 0;
        while (start < n-1)
        {
            res++;
            if (start + A[start] >= n-1)
                return res;
            int mx = start;
            for (int i = start + 1; i <= start + A[start]; ++i)
                if (i + A[i] >= mx + A[mx])
                    mx = i;
            start = mx;
        }
    }
};
/*
 Author:     Annie Kim, anniekim.pku@gmail.com
 Date:       Oct 6, 2013
 Problem:    Largest Rectangle in Histogram
 Difficulty: Hard
 Source:     http://leetcode.com/onlinejudge#question_84
 Notes:
 Given n non-negative integers representing the histogram's bar height where the width of each 
 bar is 1, find the area of largest rectangle in the histogram.
 For example,
 Given height = [2,1,5,6,2,3],
 return 10.

 Solution: 1. Only calucate area when reaching local maximum value.
           2. Keep a non-descending stack. O(n).
*/

class Solution {
public:
    int largestRectangleArea(vector<int> &height) {
        return largestRectangleArea_2(height);
    }
    
    int largestRectangleArea_1(vector<int> &height) {
        int res = 0, N = height.size();
        for (int i = 0; i < N; ++i) {
            if (i < N-1 && height[i] <= height[i+1])
                continue;
            int minHeight = height[i];
            for (int j = i; j >= 0; --j) {
                minHeight = min(minHeight, height[j]);
                res = max((i-j+1) * minHeight, res);
            }
        }
        return res;
    }
    
    int largestRectangleArea_2(vector<int> &height) {
        height.push_back(0);
        int res = 0, i = 0, N = height.size();
        stack<int> stk;
        while (i < N) 
        {
            if (stk.empty() || height[stk.top()] <= height[i])
                stk.push(i++);
            else {
                int index = stk.top(); stk.pop();
                int width = stk.empty() ? i : i - stk.top() - 1;
                res = max(res, width * height[index]);
            }
        }
        return res;
    }
};
/*
 Author:     Annie Kim, anniekim.pku@gmail.com
 Date:       Apr 17, 2013
 Problem:    Length of Last Word
 Difficulty: Easy
 Source:     http://leetcode.com/onlinejudge#question_58
 Notes:
 Given a string s consists of upper/lower-case alphabets and empty space characters ' ', return the length of last word in the string.
 If the last word does not exist, return 0.
 Note: A word is defined as a character sequence consists of non-space characters only.
 For example, 
 Given s = "Hello World",
 return 5.

 Solution: ...
 */

class Solution {
public:
    int lengthOfLastWord(const char *s) {
        int res = 0;
        int length = strlen(s);
        for (int i = length - 1; i >= 0; --i)
            if (s[i] != ' ') res++;
            else if(res > 0) break;
        return res;
    }
};
/*
 Author:     Annie Kim, anniekim.pku@gmail.com
 Date:       May 12, 2013
 Update:     Jul 25, 2013
 Problem:    Letter Combinations of a Phone Number
 Difficulty: Easy
 Source:     http://leetcode.com/onlinejudge#question_17
 Notes:
 Given a digit string, return all possible letter combinations that the number could represent.
 A mapping of digit to letters (just like on the telephone buttons) is given below.
 Input:Digit string "23"
 Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
 Note:
 Although the above answer is in lexicographical order, your answer could be in any order you want.

 Solution: ...
 */

class Solution {
public:
    vector<string> res;
    vector<string> letterCombinations(string digits) {
        string mapping[] = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        res.clear();
        string s;
        letterCombinationsRe(digits, mapping, s);
        return res;
    }

    void letterCombinationsRe(const string &digits, string mapping[], string &s)
    {
        if (s.size() == digits.size())
        {
            res.push_back(s);
            return;
        }
        string &letters = mapping[digits[s.size()]-'2'];
        for (int i = 0; i < letters.size(); ++i)
        {
            s.push_back(letters[i]);
            letterCombinationsRe(digits, mapping, s);
            s.pop_back();
        }
    }
};
/*
 Author:     Annie Kim, anniekim.pku@gmail.com
 Date:       Nov 9, 2013
 Problem:    Linked List Cycle
 Difficulty: Easy
 Source:     http://oj.leetcode.com/problems/linked-list-cycle/
 Notes:
 Given a linked list, determine if it has a cycle in it.
 Follow up:
 Can you solve it without using extra space?

 Solution: two pointers.
*/

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
        if (!head || !head->next) return false;
        ListNode *back = head, *front = head->next->next;
        while (true) 
        {
            if (front == back) return true;
            if (!front || !front->next) return false;
            front = front->next->next;
            back = back->next;
        }
    }
};/*
 Author:     Annie Kim, anniekim.pku@gmail.com
 Date:       Apr 16, 2013
 Update:     Aug 10, 2013
 Problem:    Longest Common Prefix
 Difficulty: Easy
 Source:     http://leetcode.com/onlinejudge#question_14
 Notes:
 Write a function to find the longest common prefix string amongst an array of strings.

 Solution: ...
 */

class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
        string res;
        if (strs.empty()) return res;
        for (int i = 0; i < strs[0].size(); ++i)
        {
            char ch = strs[0][i];
            for (int j = 1; j < strs.size(); ++j)
                if (i == strs[j].size() || strs[j][i] != ch)
                    return res;
            res.push_back(ch);
        }
        return res;
    }
};
/*
 Author:     Annie Kim, anniekim.pku@gmail.com
 Date:       May 24, 2013
 Update:     Aug 8, 2013
 Problem:    Longest Consecutive Sequence
 Difficulty: Hard
 Source:     http://leetcode.com/onlinejudge#question_128
 Notes:
 Given an unsorted array of integers, find the length of the longest consecutive 
 elements sequence.
 For example,
 Given [100, 4, 200, 1, 3, 2],
 The longest consecutive elements sequence is [1, 2, 3, 4]. Return its length: 4.
 Your algorithm should run in O(n) complexity.

 Solution: Update solution. This solution is from Peking2 (http://blog.sina.com.cn/s/blog_b9285de20101iqar.html).
           This solution is much easier to understand.
*/

class Solution {
public:
    int longestConsecutive(vector<int> &num) {
        unordered_set<int> s;
        int res = 0;
        for (int i = 0; i < num.size(); ++i)
            s.insert(num[i]);
        for (int i = 0; i < num.size() && !s.empty(); ++i)
        {
            int upper = num[i], lower = num[i];
            while (s.find(upper+1) != s.end())
                s.erase(++upper);
            while (s.find(lower-1) != s.end())
                s.erase(--lower);
            res = max(res, upper - lower + 1);
        }
        return res;
    }
};/*
 Author:     Annie Kim, anniekim.pku@gmail.com
 Date:       Jul 13, 2013
 Problem:    Longest Palindromic Substring
 Difficulty: Medium
 Source:     http://leetcode.com/onlinejudge#question_5
 Notes:
 Given a string S, find the longest palindromic substring in S. 
 You may assume that the maximum length of S is 1000, and there exists one unique longest palindromic substring.

 Solution: 1. Time O(n^2), Space O(n^2)
           2. Time O(n^2), Space O(n)
           3. Time O(n^2), Space O(1) (actually much more efficient than 1 & 2)
           4. Time O(n), Space O(n) (Manacher's Algorithm)
 */

class Solution {
public:
    string longestPalindrome(string s) {
        return longestPalindrome_4(s);
    }
    string longestPalindrome_1(string s) {
        int N = s.size();
        bool dp[N][N];
        pair<int, int> res = make_pair(0, 0); // start pos and length
        for (int k = 0; k < N; ++k) // length
        {
            for (int i = 0; i < N-k; ++i) // start pos
            {
                if (k == 0 || k == 1) 
                    dp[i][i+k] = s[i] == s[i+k];
                else 
                    dp[i][i+k] = (s[i] == s[i+k]) ? dp[i+1][i+k-1] : false;
                
                if (dp[i][i+k] && k+1 > res.second)
                    res = make_pair(i, k+1);
            }
        }
        return s.substr(res.first, res.second);
    }

    string longestPalindrome_2(string s) {
        int N = s.size();
        bool dp[2][N];
        pair<int, int> res = make_pair(0, 0);
        int cur = 1, last = 0;
        for (int i = 0; i < N; ++i)
        {
            cur = !cur; last = !last;
            for (int j = i; j >= 0; --j)
            {
                if (j == i || j == i-1)
                    dp[cur][j] = s[j] == s[i];
                else
                    dp[cur][j] = s[j] == s[i] && dp[last][j+1];

                if (dp[cur][j] && i-j+1 > res.second)
                    res = make_pair(j, i-j+1);
            }
        }
        return s.substr(res.first, res.second);
    }

    string longestPalindrome_3(string s) {
        int N = s.size();
        pair<int, int> res = make_pair(0, 0); // start pos and length
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j <= 1; ++j) {
                bool isP = true;
                for (int k = 0; i-k >= 0 && i+k < N && isP; ++k) {
                    isP = s[i-k] == s[i+j+k];
                    if (isP && j+1+k*2 > res.second)
                        res = make_pair(i-k, j+1+k*2);
                }
            }
        }
        return s.substr(res.first, res.second);
    }

    string longestPalindrome_4(string s) {
        int N = s.size();
        int dp[2 * N + 1];
        int id = 0, mx = 0;
        for (int i = 0; i < 2 * N + 1; ++i)
        {
            int j = 2 * id - i;
            dp[i] = mx > i ? min(dp[j], mx - i) : 1;
            int left = i - dp[i], right = i + dp[i];
            for (; left >= 0 && right <= 2 * N; left--, right++)
            {
                if (left % 2 == 0 || s[left/2] == s[right/2]) // padding or char
                    dp[i]++;
                else
                    break;
            }
            if (i + dp[i] > mx)
            {
                id = i;
                mx = id + dp[id];
            }
        }

        int res = 0;
        for (int i = 1; i < 2 * N + 1; ++i)
            if (dp[i] > dp[res])
                res = i;

        return s.substr(res / 2 - (dp[res] - 1) / 2, dp[res] - 1);
    }
};/*
 Author:     Annie Kim, anniekim.pku@gmail.com
 Date:       Apr 16, 2013
 Update:     Aug 19, 2013
 Problem:    Longest Substring Without Repeating Characters
 Difficulty: Medium
 Source:     http://leetcode.com/onlinejudge#question_3
 Notes:
 Given a string, find the length of the longest substring without repeating characters. 
 For example, the longest substring without repeating letters for "abcabcbb" is "abc", which the length is 3. 
 For "bbbbb" the longest substring is "b", with the length of 1.

 Solution: Pay attention when moving the 'start' pointer forward.
 */

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        bool exist[256];
        memset(exist, false, sizeof(exist));
        int res = 0;
        int start = 0, end = 0, N = s.size();
        while (end < N && start + res < N)
        {
            if (!exist[s[end]])
                exist[s[end++]] = true;
            else
                exist[s[start++]] = false;
            res = max(end - start, res);
        }
        return res;
    }
};
/*
 Author:     Annie Kim, anniekim.pku@gmail.com
 Date:       May 6, 2013
 Update:     Sep 26, 2013
 Problem:    Longest Valid Parentheses
 Difficulty: Easy
 Source:     http://leetcode.com/onlinejudge#question_32
 Notes:
 Given a string containing just the characters '(' and ')', find the length of the longest valid 
 (well-formed) parentheses substring.
 For "(()", the longest valid parentheses substring is "()", which has length = 2.
 Another example is ")()())", where the longest valid parentheses substring is "()()", 
 which has length = 4.

 Solution: O(n).
 */

class Solution {
public:
    int longestValidParentheses(string s) {
        return longestValidParentheses_1(s);
    }
    
    // Solution 1, from fuwutu. Smart!
    // push the length of last valid parentheses into stack.
    int longestValidParentheses_1(string s) {
        stack<int> stk;
        int res = 0, count = 0;
        for(int i = 0; i < s.size(); ++i) {
            if (s[i] == '(') {
                stk.push(count);
                count = 0;
            } else if (!stk.empty()) {
                count += (1 + stk.top());
                stk.pop();
                res = max(res, count);
            } else {
                count = 0;
            }
        }
        return res * 2;
    }
    
    // Solution 2, my original version.
    // Traverse the string twice, taking O(n) time.
    // First time, mark all the matching parentheses as '*' (push the index of '(' into <stack>).
    // Second time, count the longest consecutive '*'.
    int longestValidParentheses_2(string s) {
        stack<int> stk;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '(') {
                stk.push(i);
            } else if (!stk.empty()) {
                s[stk.top()] = '*';
                s[i] = '*';
                stk.pop();
            }
        }
        int res = 0, part = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '*') {
                part++;
            } else {
                res = max(res, part);
                part = 0;
            }
        }
        res = max(res, part);
        return res;
    }
};/*
 Author:     Annie Kim, anniekim.pku@gmail.com
 Date:       May 23, 2013
 Update:     Aug 20, 2013
 Problem:    Maximal Rectangle
 Difficulty: Medium
 Source:     http://leetcode.com/onlinejudge#question_85
 Notes:
 Given a 2D binary matrix filled with 0's and 1's, find the largest rectangle containing all ones and return its area.

 Solution: 1. dp. (72 milli secs for the large).
              a) dp[i][j] records the number of consecutive '1' on the left and up of the element matrix[i][j].
              b) For each element(i,j), calculate the area of rectangle including the element itself.
           2. calculate 'Largest Rectangle in Histogram' for each row.
 */

class Solution {
public:
    int maximalRectangle(vector<vector<char>> &matrix) {
        return maximalRectangle_1(matrix);
    }
    
    int maximalRectangle_1(vector<vector<char>> &matrix) {
        if (matrix.empty() || matrix[0].empty()) return 0;
        int N = matrix.size(), M = matrix[0].size();
        pair<int, int> dp[N][M];
        memset(dp, 0, sizeof(dp));
        int res = 0;
        for (int i = 0; i < N; ++i)
        {
            for (int j = 0; j < M; ++j)
            {
                if (matrix[i][j] == '0')
                    continue;
                
                int x = (j == 0) ? 1 : dp[i][j-1].first + 1;
                int y = (i == 0) ? 1 : dp[i-1][j].second + 1;
                dp[i][j] = make_pair(x, y);
                
                int minHeight = y;
                for (int k = j; k > j - x; --k)
                {
                    minHeight = min(minHeight, dp[i][k].second);
                    res = max(res, minHeight * (j - k + 1));
                }
            }
        }
        return res;
    }
    
    int maximalRectangle_2(vector<vector<char> > &matrix) {
        if (matrix.empty() || matrix[0].empty()) return 0;
        int N = matrix.size(), M = matrix[0].size();
        vector<int> height(M+1, 0);
        int res = 0;
        for (int i = 0; i < N; ++i)
        {
            for (int j = 0; j < M; ++j)
                height[j] = (matrix[i][j] == '0') ? 0 : height[j] + 1;
            res = max(res, largestRectangleArea(height));
        }
        return res;
    }
    
    // a little different from 'Largest Rectangle in Histogram'
    // final 0 is already provided beforehand
    int largestRectangleArea(const vector<int> &height) {
        stack<int> stk;
        int res = 0, N = height.size();
        for (int i = 0; i < N; ++i)
        {
            int count = 0;
            while (!stk.empty() && stk.top() > height[i])
            {
                count++;
                res = max(res, count * stk.top());
                stk.pop();
            }
            while (count--)
                stk.push(height[i]);

            stk.push(height[i]);
        }
        return res;
    }
};
/*
 Author:     Annie Kim, anniekim.pku@gmail.com
 Date:       Apr 9, 2013
 Problem:    Maximum Depth of Binary Tree
 Difficulty: Easy
 Source:     http://leetcode.com/onlinejudge#question_104
 Notes:
 Given a binary tree, find its maximum depth.
 The maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.

 Solution: Recursion.
 */

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int maxDepth(TreeNode *root) {
        if (!root) return 0;
        return 1 + max(maxDepth(root->left), maxDepth(root->right));
    }
};
/*
 Author:     Annie Kim, anniekim.pku@gmail.com
 Date:       Apr 21, 2013
 Problem:    Maximum Subarray
 Difficulty: Medium
 Source:     http://leetcode.com/onlinejudge#question_53
 Notes:
 Find the contiguous subarray within an array (containing at least one number) which has the largest sum.
 For example, given the array [-2,1,-3,4,-1,2,1,-5,4], the contiguous subarray [4,-1,2,1] has the largest sum = 6.

 Solution: dp.
 */

class Solution {
public:
    int maxSubArray(int A[], int n) {
        int res = A[0];
        int dp = A[0];
        for (int i = 1; i < n; ++i) {
            dp = max(A[i], dp + A[i]);
            res = max(dp, res);
        }
        return res;
    }
};/*
 Author:     Annie Kim, anniekim.pku@gmail.com
 Date:       Jul 10, 2013
 Problem:    Median of Two Sorted Arrays
 Difficulty: Hard
 Source:     http://leetcode.com/onlinejudge#question_4
 Notes:
 There are two sorted arrays A and B of size m and n respectively. 
 Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).

 Solution: 1. O(m+n)
           2. O(log(m+n))
           3. O(logm + logn)
*/

class Solution {
public:
    double findMedianSortedArrays(int A[], int m, int B[], int n) {
        return findMedianSortedArrays_1(A, m, B, n);
    }

    double findMedianSortedArrays_1(int A[], int m, int B[], int n) {
        int i = 0, j = 0;
        int m1 = 0, m2 = 0;
        int total = m + n;

        for (int k = 0; k <= total / 2; ++k)
        {
            int a = (i == m) ? INT_MAX : A[i];
            int b = (j == n) ? INT_MAX : B[j];

            m1 = m2;
            m2 = min(a, b);

            if (a < b) i++;
            else j++;
        }

        if (total & 0x1) return m2;
        else return (m1 + m2) / 2.0;
    }

    double findMedianSortedArrays_2(int A[], int m, int B[], int n) {
        int total = m + n;
        if (total & 0x1)
            return findKthSortedArrays(A, m, B, n, total / 2 + 1);
        else
            return (findKthSortedArrays(A, m, B, n, total / 2) + findKthSortedArrays(A, m, B, n, total / 2 + 1)) / 2;
    }

    double findKthSortedArrays(int A[], int m, int B[], int n, int k) {
        if (m > n)
            return findKthSortedArrays(B, n, A, m, k);
        if (m == 0) return B[k-1];
        if (k == 1) return min(A[0], B[0]);

        int i = min(k / 2, m);
        int j = k - i;
        int a = A[i-1];
        int b = B[j-1];

        if (a < b) return findKthSortedArrays(A + i, m - i, B, n, k - i);
        else if (a > b) return findKthSortedArrays(A, m, B + j, n - j, k - j);
        else return a;
    }

    double findMedianSortedArrays_3(int A[], int m, int B[], int n) {
        return findMedian(A, m, B, n, max(0, (m + n) / 2 - n), min(m - 1, (m + n) / 2));
    }

    double findMedian(int A[], int m, int B[], int n, int l, int r) {
        if (l > r)
            return findMedian(B, n, A, m, max(0, (m + n) / 2 - m), min(n, (m + n) / 2));

        int i = (l + r) / 2;
        int j = (m + n) / 2 - i;

        int Ai_1 = (i == 0) ? INT_MIN : A[i-1];
        int Bj_1 = (j == 0) ? INT_MIN : B[j-1];
        int Ai = (i == m) ? INT_MAX : A[i];
        int Bj = (j == n) ? INT_MAX : B[j];

        if (Ai < Bj_1) return findMedian(A, m, B, n, i+1, r);
        if (Ai > Bj) return findMedian(A, m, B, n, l, i-1);

        if ((m + n) % 2 == 1) return Ai;
        else return (Ai + max(Ai_1, Bj_1)) / 2.0;
    }
};
/*
 Author:     Annie Kim, anniekim.pku@gmail.com
 Date:       Jun 7, 2013
 Update:     Jul 15, 2013
 Problem:    Merge Intervals
 Difficulty: Medium
 Source:     http://leetcode.com/onlinejudge#question_56
 Notes:
 Given a collection of intervals, merge all overlapping intervals.
 For example,
 Given [1,3],[2,6],[8,10],[15,18],
 return [1,6],[8,10],[15,18].

 Solution: 1. Sort in ascending order of 'start'.
           2. Traverse the 'intervals', merge or push...
*/

/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
bool compare(Interval a, Interval b)
{
    return a.start < b.start;
}

class Solution {
public:
    vector<Interval> merge(vector<Interval> &intervals) {
        int N = intervals.size();
        if (N <= 1) return intervals;
        sort(intervals.begin(), intervals.end(), mycompare);
        vector<Interval> res;
        Interval last = intervals[0];
        for (int i = 1; i < N; ++i) 
        {
            if (intervals[i].start > last.end) {
                res.push_back(last);
                last = intervals[i];
            } else {
                last.end = max(last.end, intervals[i].end);
            }
        }
        res.push_back(last);
        return res;
    }
};/*
 Author:     Annie Kim, anniekim.pku@gmail.com
 Date:       Apr 10, 2013
 Update:     Aug 7, 2013
 Problem:    Merge Sorted Array
 Difficulty: Easy
 Source:     http://leetcode.com/onlinejudge#question_88
 Notes:
 Given two sorted integer arrays A and B, merge B into A as one sorted array.
 Note:
 You may assume that A has enough space to hold additional elements from B. 
 The number of elements initialized in A and B are m and n respectively.

 Solution: From back to forth.
 */

class Solution {
public:
    void merge(int A[], int m, int B[], int n) {
        int i = m - 1;
        int j = n - 1;
        int x = m + n - 1;
        while (i >= 0 && j >= 0)
            if (A[i] >= B[j]) A[x--] = A[i--];
            else A[x--] = B[j--];
        while (j >= 0) A[x--] = B[j--];
    }
};
/*
 Author:     Annie Kim, anniekim.pku@gmail.com
 Date:       Apr 17, 2013
 Update:     Sep 2, 2013
 Problem:    Merge Two Sorted Lists
 Difficulty: Easy
 Source:     http://leetcode.com/onlinejudge#question_21
 Notes:
 Merge two sorted linked lists and return it as a new list. 
 The new list should be made by splicing together the nodes of the first two lists.

 Solution: ...
 */

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
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        ListNode head(0), *cur = &head;
        while (l1 && l2) 
        {
            ListNode **min = l1->val < l2->val ? &l1 : &l2;
            cur->next = *min;
            cur = cur->next;
            *min = (*min)->next;
        }
        if (l1) cur->next = l1;
        if (l2) cur->next = l2;
        return head.next;
    }
};
/*
 Author:     Annie Kim, anniekim.pku@gmail.com
 Date:       Apr 6, 2013
 Update:     Sep 22, 2013
 Problem:    Merge k Sorted Lists
 Difficulty: easy
 Source:     http://leetcode.com/onlinejudge#question_23
 Notes:
 Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.
 
 Solution: Find the smallest list-head first using minimum-heap(lgk).
           complexity: O(NlgK)
 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

class Mycompare {
public:
    bool operator()(ListNode *a, ListNode *b) {
        return a->val > b->val;
    }
};

class Solution {
public:
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        priority_queue<ListNode *, vector<ListNode *>, Mycompare> q;
        for (int i = 0; i < lists.size(); ++i)
            if (lists[i])
                q.push(lists[i]);
        
        ListNode dummy(0), *cur = &dummy;
        while (!q.empty()) {
            ListNode *node = q.top();
            q.pop();
            cur = cur->next = node;
            if (node->next)
                q.push(node->next);
        }
        return dummy.next;
    }
};
/*
 Author:     Annie Kim, anniekim.pku@gmail.com
 Date:       Apr 6, 2013
 Update:     Sep 8, 2013
 Problem:    Minimum Depth of Binary Tree
 Difficulty: easy
 Source:     http://leetcode.com/onlinejudge#question_111
 Notes:
 Given a binary tree, find its minimum depth.
 The minimum depth is the number of nodes along the shortest path from the root node 
 down to the nearest leaf node.
 
 Solution: 1. Recursion. Pay attention to cases when the non-leaf node has only one child.
           2. Iteration + Queue. Contributed by SUN Mian(å­™å†•).
 */

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int minDepth(TreeNode *root) {
        return minDepth_1(root);
    }
    
    int minDepth_1(TreeNode *root) {
        if (!root)
            return 0;
        
        if (!root->left && !root->right)
            return 1;
        else if (!root->left)
            return 1 + minDepth_1(root->right);
        else if (!root->right)
            return 1 + minDepth_1(root->left);
        else
            return 1 + min(minDepth_1(root->left), minDepth_1(root->right));
    }
    
    int minDepth_2(TreeNode *root) {
        if (!root) return 0;
        queue<TreeNode *> q;
        q.push(root);
        q.push(NULL);
        int depth = 1;
        while (true)
        {
            TreeNode *node = q.front();
            q.pop();
            if (!node) {
                depth++;
                q.push(NULL);
            } else {
                if (!node->left && !node->right) return depth;
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
        }
    }
};
/*
 Author:     Annie Kim, anniekim.pku@gmail.com
 Date:       Apr 17, 2013
 Update:     Jul 30, 2013
 Problem:    Minimum Path Sum
 Difficulty: Easy
 Source:     http://leetcode.com/onlinejudge#question_64
 Notes:
 Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right 
 which minimizes the sum of all numbers along its path.
 Note: You can only move either down or right at any point in time.

 Solution: Dynamic Programming. Space O(N).
 */

class Solution {
public:
    int minPathSum(vector<vector<int> > &grid) {
        if (grid.empty()) return INT_MIN;
        int M = grid.size(), N = grid[0].size();
        int dp[N];
        dp[0] = grid[0][0];
        for (int i = 1; i < N; ++i)
            dp[i] = grid[0][i] + dp[i-1];
        
        for (int i = 1; i < M; ++i)
        {
            dp[0] += grid[i][0];
            for (int j = 1; j < N; ++j)
                dp[j] = min(dp[j-1], dp[j]) + grid[i][j];
        }
        
        return dp[N-1];
    }
};
/*
 Author:     Annie Kim, anniekim.pku@gmail.com
 Date:       May 24, 2013
 Update:     Jul 30, 2013
 Problem:    Minimum Window Substring
 Difficulty: Medium
 Source:     http://leetcode.com/onlinejudge#question_76
 Notes:
 Given a string S and a string T, find the minimum window in S which will contain all the 
 characters in T in complexity O(n).
 For example,
 S = "ADOBECODEBANC"
 T = "ABC"
 Minimum window is "BANC".
 Note:
 If there is no such window in S that covers all characters in T, return the empty string "".
 If there are multiple such windows, you are guaranteed that there will always be only one unique 
 minimum window in S.

 Solution: 1. Use two pointers: start and end. 
              First, move 'end'. After finding all the needed characters, move 'start'.
           2. Use array as hashtable.
 */

class Solution {
public:
    string minWindow(string S, string T) {
        int N = S.size(), M = T.size();
        if (N < M) return "";
        int need[256] = {0};
        int find[256] = {0};
        for (int i = 0; i < M; ++i)
            need[T[i]]++;

        int count = 0, resStart = -1, resEnd = N;
        for (int start = 0, end = 0; end < N; ++end)
        {
            if (need[S[end]] == 0)
                continue;
            if (find[S[end]] < need[S[end]])
                count++;
            find[S[end]]++;
            if (count != M) continue;
            // move 'start'
            for (; start < end; ++start) {
                if (need[S[start]] == 0) continue;
                if (find[S[start]] <= need[S[start]]) break;
                find[S[start]]--;
            }
            // update result
            if (end - start < resEnd - resStart) {
                resStart = start;
                resEnd = end;
            }
        }
        return (resStart == -1) ? "" : S.substr(resStart, resEnd - resStart + 1);
    }
};/*
 Author:     Annie Kim, anniekim.pku@gmail.com
 Date:       Apr 23, 2013
 Update:     Aug 20, 2013
 Problem:    Multiply Strings
 Difficulty: Easy
 Source:     http://leetcode.com/onlinejudge#question_43
 Notes:
 Given two numbers represented as strings, return multiplication of the numbers as a string.
 Note: The numbers can be arbitrarily large and are non-negative.

 Solution: Just like what we do when multiplying integers.
 */

class Solution {
public:
    string multiply(string num1, string num2) {
        int N = num1.size(), M = num2.size();
        string res(N+M, '0');
        for (int i = N - 1; i >= 0; --i)
        {
            int carry = 0;
            for (int j = M - 1; j >= 0; --j)
            {
                int sum = carry + (res[i+j+1] - '0') + 
                          (num1[i] - '0') * (num2[j] - '0');
                res[i+j+1] = sum % 10 + '0';
                carry = sum / 10;
            }
            res[i] += carry;
        }
        while (res.size() > 1 && res[0] == '0')
            res.erase(res.begin());
        return res;
    }
};
/*
 Author:     Annie Kim, anniekim.pku@gmail.com
 Date:       Apr 24, 2013
 Update:     Jul 25, 2013
 Problem:    N-Queens
 Difficulty: Medium
 Source:     http://leetcode.com/onlinejudge#question_51
 Notes:
 The n-queens puzzle is the problem of placing n queens on an n*n chessboard such that no two queens attack each other.
 Given an integer n, return all distinct solutions to the n-queens puzzle.
 Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space respectively.
 For example,
 There exist two distinct solutions to the 4-queens puzzle:
 [
 [".Q..",  // Solution 1
 "...Q",
 "Q...",
 "..Q."],

 ["..Q.",  // Solution 2
 "Q...",
 "...Q",
 ".Q.."]
 ]

 Solution: Recursion (DFS). Use bit-manipulation solution (See N-QueensII for more details).
 */

class Solution {
public:
    vector<vector<string> > solveNQueens(int n) {
        vector<vector<string> > res;
        vector<string> sol;
        solveNQueensRe(n, 0, 0, 0, sol, res);
        return res;
    }
    
    void solveNQueensRe(int n, int row, int ld, int rd, vector<string> &sol, vector<vector<string>> &res)
    {
        if (row == (1 << n) - 1)
        {
            res.push_back(sol);
            return;
        }
        int avail = ~(row | ld | rd);
        for (int i = n-1; i >= 0; --i)
        {
            int pos = 1 << i;
            if (avail & pos)
            {
                string s(n, '.');
                s[i] = 'Q';
                sol.push_back(s);
                solveNQueensRe(n, row | pos, (ld|pos) << 1, (rd|pos) >> 1, sol, res);
                sol.pop_back();
            }
        }
    }
};
/*
 Author:     Annie Kim, anniekim.pku@gmail.com
 Date:       Apr 24, 2013
 Update:     Aug 23, 2013
 Problem:    N-Queens II
 Difficulty: Medium
 Source:     http://leetcode.com/onlinejudge#question_52
 Notes:
 The n-queens puzzle is the problem of placing n queens on an n*n chessboard such that no two queens attack each other.
 Given an integer n, return all distinct solutions to the n-queens puzzle.
 Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space respectively.
 For example,
 There exist two distinct solutions to the 4-queens puzzle:
 [
 [".Q..",  // Solution 1
 "...Q",
 "Q...",
 "..Q."],

 ["..Q.",  // Solution 2
 "Q...",
 "...Q",
 ".Q.."]
 ]

 Solution: 1. Recursion.
           2. Recursion + bit version. (fast)
              The idea is from http://www.matrix67.com/blog/archives/266 (in chinese).
           3. Iteration.
*/

class Solution {
public:
    int totalNQueens(int n) {
        return totalNQueens_2(n);
    }
    
    // solution 1: recursion
    int totalNQueens_1(int n) 
    {
        int board[n];
        memset(board, -1, sizeof(board));
        int res = 0;
        totalNQueensRe(n, 0, board, res);
        return res;
    }
    
    void totalNQueensRe(int n, int row, int board[], int &res)
    {
        if (row  == n)
        {
            res++;
            return;
        }
        for (int i = 0; i < n; ++i)
        {
            if (isValid(board, row, i))
            {
                board[row] = i;
                totalNQueensRe(n, row + 1, board, res);
                board[row] = -1;
            }
        }
    }
    
    bool isValid(int board[], int row, int col)
    {
        for (int i = 0; i < row; ++i)
            if (board[i] == col || row - i == abs(col - board[i]))
                return false;
        return true;
    }
    
    // solution 2: bit version
    int totalNQueens_2(int n) {
        int res = 0;
        totalNQueensRe_2(n, 0, 0, 0, res);
        return res;
    }

    void totalNQueensRe_2(int n, int row, int ld, int rd, int &res)
    {
        if (row == (1 << n) - 1)
        {
            res++;
            return;
        }
        int avail = ~(row | ld | rd);
        for (int i = n - 1; i >= 0; --i)
        {
            int pos = 1 << i;
            if (avail & pos)
                totalNQueensRe_2(n, row | pos, (ld | pos) << 1, (rd | pos) >> 1, res);
        }
    }
    
    // solution 3: iterative solution
    int totalNQueens_3(int n) 
    {
        int board[n];
        memset(board, -1, sizeof(board));
        int row = 0;
        int res = 0;
        while (row != -1)
        {
            if (row == n)
            {
                res++;
                row--;
            }
            int i = board[row] == -1 ? 0 : board[row] + 1;
            for (; i < n; ++i)
            {
                if (isValid(board, row, i))
                {
                    board[row] = i;
                    row++;
                    break;
                }
            }
            if (i == n)
            {
                board[row] = -1;
                row--;
            }
        }
        return res;
    }
};
/*
 Author:     Annie Kim, anniekim.pku@gmail.com
 Date:       May 6, 2013
 Problem:    Next Permutation
 Difficulty: Medium
 Source:     http://leetcode.com/onlinejudge#question_31
 Notes:
 Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.
 If such arrangement is not possible, it must rearrange it as the lowest possible order (ie, sorted in ascending order).
 The replacement must be in-place, do not allocate extra memory.
 Here are some examples. Inputs are in the left-hand column and its corresponding outputs are in the right-hand column.
 1,2,3 -> 1,3,2
 3,2,1 -> 1,2,3
 1,1,5 -> 1,5,1

 Solution: O(n)
 Processes: Take A = {1,3,2} as an example:
            1. Traverse from back to forth, find the turning point, that is A[i] = 3.
            2. Sort from the turning point to the end (A[i] to A[end]), so {3,2} becomes {2,3}.
            3. If i equals to 0, finish! Else, goto 4.
            4. Let j = i, search from A[j] to A[end] to find the first elem which is larger than A[i-1], '2' here.
            5. Swap the elem A[j] with A[i-1].
            Finally, the next permutation is {2,1,3}.
 */

class Solution {
public:
    void nextPermutation(vector<int> &num) {
        int i = num.size() - 1;
        while (i > 0 && num[i] <= num[i-1]) 
            i--;
        sort(num.begin() + i, num.end());
        if (i == 0) 
            return;
        int j = i;
        while (j < num.size() && num[j] <= num[i-1])
            j++;
        swap(num[j], num[i-1]);
    }
};/*
 Author:     Annie Kim, anniekim.pku@gmail.com
 Date:       Apr 16, 2013
 Update:     Aug 22, 2013
 Problem:    Palindrome Number
 Difficulty: Easy
 Source:     http://leetcode.com/onlinejudge#question_9
 Notes:
 Determine whether an integer is a palindrome. Do this without extra space.
 Some hints:
 Could negative integers be palindromes? (ie, -1) (No!)
 If you are thinking of converting the integer to string, note the restriction of using extra space.
 You could also try reversing an integer. However, if you have solved the problem "Reverse Integer", 
 you know that the reversed integer might overflow. How would you handle such case?
 There is a more generic way of solving this problem.

 Solution: 1. Count the number of digits first (traverse once) then check the digits from both sides to center.
           2. Reverse the number, then check to see if x == reverse(x).
           3. Recursion (interesting but a little hard to understand).
 */

class Solution {
public:
    bool isPalindrome(int x) {
        return isPalindrome1(x);
    }
    
    // solution 1
    bool isPalindrome1(int x) {
        if (x < 0) return false;
        int d = 1;
        while (x / d >= 10) d *= 10;
        while (d > 1)
        {
            if (x % 10 != x / d)
                return false;
            x = x % d / 10;
            d /= 100;
        }
        return true;
    }

    // solution 2
    bool isPalindrome2(int x) {
        if (x < 0) return false;
        return x == reverse(x);
    }

    int reverse(int x)
    {
        int rev = 0;
        while (x) {
            rev = rev * 10 + x % 10;
            x /= 10;
        }
        return rev;
    }
    
    // solution 3
    bool isPalindrome3(int x) {
        return isPalindromeRe(x, x);
    }
    
    bool isPalindromeRe(int x, int &y) {
        if (x < 0) return false;
        if (x == 0) return true;
        if (isPalindromeRe(x / 10, y) && x % 10 == y % 10)
        {
            y /= 10;
            return true;
        }
        return false;
    }
};
/*
 Author:     Annie Kim, anniekim.pku@gmail.com
 Date:       May 20, 2013
 Problem:    Palindrome Partitioning
 Difficulty: Easy
 Source:     http://leetcode.com/onlinejudge#question_131
 Notes:
 Given a string s, partition s such that every substring of the partition is a palindrome.
 Return all possible palindrome partitioning of s.
 For example, given s = "aab",
 Return
 [
  ["aa","b"],
  ["a","a","b"]
 ]

 Solution: ...
 */

class Solution {
public:
    vector<vector<string>> res;
    vector<vector<string>> partition(string s) {
        res.clear();
        vector<string> part;
        partitionRe(s, 0, part);
        return res;
    }

    void partitionRe(const string &s, int start, vector<string> &part) {
        if (start == s.size())
        {
            res.push_back(part);
            return;
        }
        string palindrom;
        for (int i = start; i < s.size(); ++i) {
            palindrom.push_back(s[i]);
            if (!isPalindrome(palindrom)) continue;
            part.push_back(palindrom);
            partitionRe(s, i + 1, part);
            part.pop_back();
        }
    }

    bool isPalindrome(const string &s) {
        int i = 0, j = s.size()-1;
        while (i < j) {
            if (s[i] != s[j]) return false;
            i++; j--;
        }
        return true;
    }
};/*
 Author:     Annie Kim, anniekim.pku@gmail.com
 Date:       May 23, 2013
 Update:     Sep 23, 2013
 Problem:    Palindrome Partitioning II
 Difficulty: Hard
 Source:     http://leetcode.com/onlinejudge#question_132
 Notes:
 Given a string s, partition s such that every substring of the partition is a palindrome.
 Return the minimum cuts needed for a palindrome partitioning of s.
 For example, given s = "aab",
 Return 1 since the palindrome partitioning ["aa","b"] could be produced using 1 cut.

 Solution: dp. Contributed by å­™å†•. Great job:)
 */

class Solution {
public:
    int minCut(string s) {
        int N = s.size();
        bool isP[N];
        int dp[N];
        dp[0] = 0;
        for (int i = 1; i < N; ++i) 
        {
            isP[i] = true;
            dp[i] = dp[i-1] + 1;
            for (int j = 0; j < i; ++j) 
            {
                isP[j] = (s[i] == s[j]) ? isP[j+1] : false; // isP[j] == true   -> [j...i] is a palindrome
                                                            // isP[j+1] == true -> [j+1...i-1] is a palindrome
                if (isP[j])
                    dp[i] = (j == 0) ? 0 : min(dp[i], dp[j-1] + 1);  // dp[i] -> minCount for [0...i]
            }
        }
        return dp[N-1];
    }
};
/*
 Author:     Annie Kim, anniekim.pku@gmail.com
 Date:       Apr 9, 2013
 Update:     Jul 30, 2013
 Problem:    Partition List
 Difficulty: Easy
 Source:     http://leetcode.com/onlinejudge#question_86
 Notes:
 Given a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.
 You should preserve the original relative order of the nodes in each of the two partitions.
 For example,
 Given 1->4->3->2->5->2 and x = 3,
 return 1->2->2->4->3->5.

 Solution: ...
 */

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
    ListNode *partition(ListNode *head, int x) {
        ListNode dummy(0), *ins = &dummy, *cur = &dummy;
        dummy.next = head;
        while (cur->next) 
        {
            if (cur->next->val >= x)
            {
                cur = cur->next;
            } 
            else 
            {
                if (cur == ins) 
                {
                    cur = cur->next;
                    ins = ins->next;
                } 
                else 
                {
                    ListNode *move = cur->next;
                    cur->next = move->next;
                    move->next = ins->next;
                    ins->next = move;
                    ins = move;
                }
            }
        }
        return dummy.next;
    }
};/*
 Author:     Annie Kim, anniekim.pku@gmail.com
 Date:       Apr 16, 2013
 Problem:    Pascal's Triangle
 Difficulty: Easy
 Source:     http://leetcode.com/onlinejudge#question_118
 Notes:
 Given numRows, generate the first numRows of Pascal's triangle.
 For example, given numRows = 5,
 Return
 [
      [1],
     [1,1],
    [1,2,1],
   [1,3,3,1],
  [1,4,6,4,1]
 ]

 Solution: .....
 */

class Solution {
public:
    vector<vector<int> > generate(int numRows) {
        vector<vector<int> > res(numRows);
        for (int i = 0; i < numRows; ++i)
        {
            res[i].push_back(1);
            for (int j = 1; j < i; ++j)
                res[i].push_back(res[i-1][j-1] + res[i-1][j]);
            if (i >= 1) res[i].push_back(1);
        }
        return res;
    }
};/*
 Author:     Annie Kim, anniekim.pku@gmail.com
 Date:       Apr 16, 2013
 Problem:    Pascal's Triangle II
 Difficulty: Easy
 Source:     http://leetcode.com/onlinejudge#question_119
 Notes:
 Given an index k, return the kth row of the Pascal's triangle.
 For example, given k = 3,
 Return [1,3,3,1].
 Note:
 Could you optimize your algorithm to use only O(k) extra space?

 Solution: from back to forth...
 */

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> res(rowIndex+1, 1);
        for (int i = 1; i <= rowIndex; ++i)
            for (int j = i-1; j >= 1; --j)
                res[j] += res[j-1];
        return res;
    }
};/*
 Author:     Annie Kim, anniekim.pku@gmail.com
 Date:       Apr 6, 2013
 Update:     Jul 26, 2013
 Problem:    Path Sum
 Difficulty: easy
 Source:     http://www.leetcode.com/onlinejudge
 Notes:
 Given a binary tree and a sum, determine if the tree has a root-to-leaf path such that adding up 
 all the values along the path equals the given sum.

 For example:
 Given the below binary tree and sum = 22,
              5
             / \
            4   8
           /   / \
          11  13  4
         /  \      \
        7    2      1
 return true, as there exist a root-to-leaf path 5->4->11->2 which sum is 22.
 
 Solution: Recursion.
 */

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool hasPathSum(TreeNode *root, int sum) {
        if (!root)
            return false;
        if (!root->left and !root->right)
            return sum == root->val;
        return hasPathSum(root->left, sum - root->val) || 
               hasPathSum(root->right, sum - root->val);
    }
};
/*
 Author:     Annie Kim, anniekim.pku@gmail.com
 Date:       Apr 6, 2013
 Update:     Jul 26, 2013
 Problem:    Path Sum 2
 Difficulty: easy
 Source:     http://leetcode.com/onlinejudge#question_113
 Notes:
 Given a binary tree and a sum, find all root-to-leaf paths where each path's sum equals the given sum.

 For example:
 Given the below binary tree and sum = 22,
              5
             / \
            4   8
           /   / \
          11  13  4
         /  \    / \
        7    2  5   1
 return
 [
   [5,4,11,2],
   [5,8,4,5]
 ]
 
 Solution: DFS. 
 */

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<vector<int> > pathSum(TreeNode *root, int sum) {
        vector<vector<int>> res;
        vector<int> path;
        pathSumRe(root, sum, res, path);
        return res;
    }
    void pathSumRe(TreeNode *root, int sum, vector<vector<int>> &res, vector<int> &path)
    {
        if (!root) return;
        if (!root->left && !root->right)
        {
            if (sum == root->val)
            {
                path.push_back(root->val);
                res.push_back(path);
                path.pop_back();
            }
            return;
        }
        path.push_back(root->val);
        pathSumRe(root->left, sum - root->val, res, path);
        pathSumRe(root->right, sum - root->val, res, path);
        path.pop_back();
    }
};
/*
 Author:     Annie Kim, anniekim.pku@gmail.com
 Date:       May 8, 2013
 Update:     Aug 12, 2013
 Problem:    Permutation Sequence
 Difficulty: Medium
 Source:     http://leetcode.com/onlinejudge#question_60
 Notes:
 The set [1,2,3,...,n] contains a total of n! unique permutations.
 By listing and labeling all of the permutations in order,
 We get the following sequence (ie, for n = 3):
 "123"
 "132"
 "213"
 "231"
 "312"
 "321"
 Given n and k, return the kth permutation sequence.
 Note: Given n will be between 1 and 9 inclusive.

 Solution: ...
 */

class Solution {
public:
    string getPermutation(int n, int k) {
        string num, res;
        int total = 1;
        for (int i = 1; i <= n; ++i)
        {
            num.push_back(i + '0');
            total *= i;
        }
        k--;
        while (n)
        {
            total /= n;
            int i = k / total;
            k %= total;
            res.push_back(num[i]);
            num.erase(i, 1);
            n--;
        }
        return res;
    }
};
/*
 Author:     Annie Kim, anniekim.pku@gmail.com
 Date:       Apr 29, 2013
 Update:     Jul 19, 2013
 Problem:    Permutations
 Difficulty: Easy
 Source:     http://leetcode.com/onlinejudge#question_46
 Notes:
 Given a collection of numbers, return all possible permutations.
 For example,
 [1,2,3] have the following permutations:
 [1,2,3], [1,3,2], [2,1,3], [2,3,1], [3,1,2], and [3,2,1].

 Solution: dfs...
 */

class Solution {
public:
    vector<vector<int>> res;

    vector<vector<int>> permute(vector<int> &num) {
        res.clear();
        vector<bool> avail(num.size(), true);
        vector<int> pum;
        permuteRe(num, avail, pum);
        return res;
    }

    void permuteRe(const vector<int> &num, vector<bool> &avail, vector<int> &pum)
    {
        if (pum.size() == num.size())
        {
            res.push_back(pum);
            return;
        }
        for (int i = 0; i < num.size(); ++i)
        {
            if (avail[i])
            {
                avail[i] = false;
                pum.push_back(num[i]);
                permuteRe(num, avail, pum);
                pum.pop_back();
                avail[i] = true;
            }
        }
    }
};
/*
 Author:     Annie Kim, anniekim.pku@gmail.com
 Date:       Apr 29, 2013
 Update:     Sep 2, 2013
 Problem:    Permutations II
 Difficulty: Easy
 Source:     http://leetcode.com/onlinejudge#question_47
 Notes:
 Given a collection of numbers that might contain duplicates, return all possible unique permutations.
 For example,
 [1,1,2] have the following unique permutations:
 [1,1,2], [1,2,1], and [2,1,1].

 Solution: dfs...
 */

class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> permuteUnique(vector<int> &num) {
        res.clear();
        sort(num.begin(), num.end());
        bool avail[num.size()];
        memset(avail, true, sizeof(avail));
        vector<int> pum;
        permuteUniqueRe(num, pum, avail);
        return res;
    }

    void permuteUniqueRe(vector<int> &num, vector<int> &pum, bool avail[])
    {
        if (pum.size() == num.size())
        {
            res.push_back(pum);
            return;
        }
        int last_index = -1;
        for (int i = 0; i < num.size(); ++i)
        {
            if (!avail[i]) continue;
            if (last_index != -1 && num[i] == num[last_index]) continue;
            
            avail[i] = false;
            pum.push_back(num[i]);
            permuteUniqueRe(num, pum, avail);
            pum.pop_back();
            avail[i] = true;
            last_index = i;
        }
    }
};
/*
 Author:     Annie Kim, anniekim.pku@gmail.com
 Date:       Apr 9, 2013
 Update:     Aug 29, 2013
 Problem:    Plus One
 Difficulty: Easy
 Source:     http://leetcode.com/onlinejudge#question_66
 Notes:
 Given a number represented as an array of digits, plus one to the number.

 Solution: ...
 */

class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
        int carry = 1, N = digits.size();
        for (int i = N-1; i >= 0 && carry; --i)
        {
            int sum = carry + digits[i];
            carry = sum / 10;
            digits[i] = sum % 10;
        }
        if (carry == 1)
            digits.insert(digits.begin(), 1);
        return digits;
    }
};
/*
 Author:     Annie Kim, anniekim.pku@gmail.com
 Date:       Apr 22, 2013
 Update:     Sep 8, 2013
 Problem:    Populating Next Right Pointers in Each Node
 Difficulty: Easy
 Source:     http://leetcode.com/onlinejudge#question_116
 Notes:
 Given a binary tree
 struct TreeLinkNode {
    TreeLinkNode *left;
    TreeLinkNode *right;
    TreeLinkNode *next;
 }
 Populate each next pointer to point to its next right node. If there is no next right node, the next pointer should be set to NULL.
 Initially, all next pointers are set to NULL.
 Note:
 You may only use constant extra space.
 You may assume that it is a perfect binary tree (ie, all leaves are at the same level, and every parent has two children).
 For example,
 Given the following perfect binary tree,
      1
    /  \
   2    3
  / \  / \
 4  5  6  7
 After calling your function, the tree should look like:
      1 -> NULL
    /  \
   2 -> 3 -> NULL
  / \  / \
 4->5->6->7 -> NULL

 Solution: 1. Iterative: Two 'while' loops: root->leaf and left->right.
           2. Iterative: Queue. Use extra space.
           3. Recursive: DFS. Defect: Use extra stack space for recursion.
 */

/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */

class Solution {
public:
    void connect(TreeLinkNode *root) {
        connect_1(root);
    }
    
    void connect_1(TreeLinkNode *root) {
        while (root)
        {
            TreeLinkNode *level = root;
            TreeLinkNode *last = NULL;
            while (level && level->left)
            {
                if (last) last->next = level->left;
                level->left->next = level->right;
                last = level->right;
                level = level->next;
            }
            root = root->left;
        }
    }
    
    void connect_2(TreeLinkNode *root) {
        if (!root) return;
        queue<TreeLinkNode *> q;
        q.push(root);
        q.push(NULL);
        TreeLinkNode *last = NULL;
        while (true)
        {
            TreeLinkNode *node = q.front();
            q.pop();
            if (!node) {
                last = NULL;
                if (q.empty()) break;
                q.push(NULL);
            } else {
                if (last) last->next = node;
                last = node;
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
        }
    }
    
    void connect_3(TreeLinkNode *node) {
        if (!node || !node->left) return;
        node->left->next = node->right;
        node->right->next = node->next ? node->next->left : NULL;
        connect_3(node->left);
        connect_3(node->right);
    }
};
/*
 Author:     Annie Kim, anniekim.pku@gmail.com
 Date:       Apr 23, 2013
 Update:     Sep 8, 2013
 Problem:    Populating Next Right Pointers in Each Node II
 Difficulty: Easy
 Source:     http://leetcode.com/onlinejudge#question_117
 Notes:
 Follow up for problem "Populating Next Right Pointers in Each Node".
 What if the given tree could be any binary tree? Would your previous solution still work?
 Note:
 You may only use constant extra space.
 For example,
 Given the following binary tree,
     1
    /  \
   2    3
  / \    \
 4   5    7
 After calling your function, the tree should look like:
     1 -> NULL
    /  \
   2 -> 3 -> NULL
  / \    \
 4-> 5 -> 7 -> NULL

 Solution: 1. iterative way with CONSTANT extra space.
           2. iterative way + queue. Contributed by SUN Mian(å­™å†•).
           3. tail recursive solution.
 */

/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        connect_1(root);
    }
    
    // solution 1
    void connect_1(TreeLinkNode *root) {
        TreeLinkNode *cur = root;
        while (cur)
        {
            TreeLinkNode *node = cur, *last = NULL;
            cur = NULL;
            while (node)
            {
                TreeLinkNode *left = node->left, *right = node->right;
                if (left || right) {
                    if (last) last->next = left ? left : right;
                    if (left) left->next = right;
                    if (!cur) cur = left ? left : right;
                    last = right ? right : left;
                }
                node = node->next;
            }
        }
    }
    
    // solution 2
    void connect_2(TreeLinkNode *root) {
        if (!root) return;
        queue<TreeLinkNode *> q;
        q.push(root);
        q.push(NULL);
        TreeLinkNode *last = NULL;
        while (true)
        {
            TreeLinkNode *node = q.front();
            q.pop();
            if (!node) {
                last = NULL;
                if (q.empty()) break;
                q.push(NULL);
            } else {
                if (last) last->next = node;
                last = node;
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
        }
    }
    
    // solution 3
    void connect_3(TreeLinkNode *root) {
        if (!root) return;
        TreeLinkNode *node = root;
        TreeLinkNode *last = NULL;
        TreeLinkNode *first = NULL;
        while (node)
        {
            if (node->left || node->right) {
                if (last) 
                    last->next = node->left ? node->left : node->right;
                if (node->left && node->right)
                    node->left->next = node->right;
                if (!first) 
                    first = node->left ? node->left : node->right;
                last = node->right ? node->right : node->left;
                
            }
            node = node->next;
        }
        connect_3(first);
    }
};
/*
 Author:     Annie Kim, anniekim.pku@gmail.com
 Date:       Apr 6, 2013
 Update:     Jul 15, 2013
 Problem:    Pow(x, n)
 Difficulty: easy
 Source:     http://leetcode.com/onlinejudge#question_50
 Notes:
 Implement pow(x, n).
 
 Solution: recursion.
 */

class Solution {
public:
    double pow(double x, int n) {
        if (x < 0) return (n % 2 == 0) ? pow(-x, n) : -pow(-x, n);
        if (x == 0 || x == 1) return x;
        if (n < 0) return 1.0 / pow(x, -n);
        if (n == 0) return 1.0;
        
        double half = pow(x, n / 2);
        if (n % 2 == 0) return half * half;
        else return x * half * half;
    }
};
/*
 Author:     Annie Kim, anniekim.pku@gmail.com
 Date:       Jun 15, 2013
 Problem:    Recover Binary Search Tree
 Difficulty: High
 Source:     http://leetcode.com/onlinejudge#question_99
 Notes:
 Two elements of a binary search tree (BST) are swapped by mistake.
 Recover the tree without changing its structure.
 Note:
 A solution using O(n) space is pretty straight forward. Could you devise a constant space solution?

 Solution: 1. recursive solution. O(n) space. get inorder list first.
           2. recursive solution. O(n) space. with only auxiliary two pointers.
           3. Morris inorder traversal. O(1) space. with only auxiliary two pointers.
*/

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    // first solution
    void recoverTree_1(TreeNode *root) {
        vector<TreeNode *> inorder;
        inorderTraversal(root, inorder);
        TreeNode *first = NULL, *second = NULL;
        for (int i = 1; i < inorder.size(); ++i)
        {
            if (inorder[i-1]->val < inorder[i]->val)
                continue;
            if (!first)
                first = inorder[i-1];
            second = inorder[i];
        }
        swap(first->val, second->val);
    }

    void inorderTraversal(TreeNode *root, vector<TreeNode *> &inorder) {
        if (!root) return;
        inorderTraversal(root->left, inorder);
        inorder.push_back(root);
        inorderTraversal(root->right, inorder);
    }

    // second solution
    void recoverTree_2(TreeNode *root) {
        TreeNode *prev = NULL, *first = NULL, *second = NULL;
        recoverTreeRe(root, prev, first, second);
        swap(first->val, second->val);
    }

    void recoverTreeRe(TreeNode *curNode, TreeNode *&preNode, TreeNode *&first, TreeNode *&second) {
        if (curNode == NULL) return;
        recoverTreeRe(curNode->left, preNode, first, second);
        if (preNode && preNode->val > curNode->val) {
            if (first == NULL) 
                first = preNode;
            second = curNode;
        }
        preNode = curNode;
        recoverTreeRe(curNode->right, preNode, first, second);
    }
    
    // third solution
    void recoverTree_3(TreeNode *root) {
        TreeNode *cur = root, *prev = NULL;
        TreeNode *first = NULL, *second = NULL, *last = NULL;
        while (cur != NULL)
        {
            if (cur->left == NULL)
            {
                compare(last, cur, first, second);
                last = cur;
                cur = cur->right;
            }
            else
            {
                prev = cur->left;
                while (prev->right != NULL && prev->right != cur)
                    prev = prev->right;

                if (prev->right == NULL)
                {
                    prev->right = cur;
                    cur = cur->left;
                }
                else
                {
                    compare(last, cur, first, second);
                    last = cur;
                    prev->right = NULL;
                    cur = cur->right;
                }
            }
        }
        swap(first->val, second->val);
    }

    void compare(TreeNode *last, TreeNode *cur, TreeNode *&first, TreeNode *&second)
    {
        if (last && last->val > cur->val)
        {
            if (!first)
                first = last;
            second = cur;
        }
    }
};/*
 Author:     Annie Kim, anniekim.pku@gmail.com
 Date:       May 26, 2013
 Update:     Aug 19, 2013
 Problem:    Regular Expression Matching
 Difficulty: Hard
 Source:     http://leetcode.com/onlinejudge#question_10
 Notes:
 Implement regular expression matching with support for '.' and '*'.
 '.' Matches any single character.
 '*' Matches zero or more of the preceding element.
 The matching should cover the entire input string (not partial).
 The function prototype should be:
 bool isMatch(const char *s, const char *p)
 Some examples:
 isMatch("aa","a") ? false
 isMatch("aa","aa") ? true
 isMatch("aaa","aa") ? false
 isMatch("aa", "a*") ? true
 isMatch("aa", ".*") ? true
 isMatch("ab", ".*") ? true
 isMatch("aab", "c*a*b") ? true

 Solution: Both of the two solutions are from http://leetcode.com/2011/09/regular-expression-matching.html .
*/

class Solution {
public:
    bool isMatch(const char *s, const char *p) {
        if (*p == '\0') return *s == '\0';
        
        if (*(p+1) == '*') // next is '*'
        {
            while ((*s == *p || *p == '.') && *s != '\0')
            {
                if (isMatch(s, p+2))
                    return true;
                s++;
            }
            return isMatch(s, p+2);
        }
        
        if (*s == '\0') return false;
        return (*s == *p || *p == '.') && isMatch(s+1, p+1);
    }
    
    bool isMatch_2(const char *s, const char *p) {
        if (*p == '\0') return *s == '\0';
        
        if (*s == *p || *p == '.' && *s != '\0')
            return *(p+1) != '*' ? isMatch(s+1, p+1) : 
                                   isMatch(s+1, p) || isMatch(s, p+2);
        else
            return *(p+1) == '*' && isMatch(s, p+2);
    }
};
/*
 Author:     Annie Kim, anniekim.pku@gmail.com
 Date:       Apr 10, 2013
 Update:     Jul 16, 2013
 Problem:    Remove Duplicates from Sorted Array
 Difficulty: Easy
 Source:     http://leetcode.com/onlinejudge#question_26
 Notes:
 Given a sorted array, remove the duplicates in place such that each element appear only once and return the new length.
 Do not allocate extra space for another array, you must do this in place with constant memory.
 For example,
 Given input array A = [1,1,2],
 Your function should return length = 2, and A is now [1,2].

 Solution: Update 7/16/2013: Let j start from 0 for better understanding.
 */

class Solution {
public:
    int removeDuplicates(int A[], int n) {
        int j = 0;
        for (int i = 0; i < n; ++i)
            if (i == 0 || A[i] != A[i-1])
                A[j++] = A[i];
        return j;
    }
};/*
 Author:     Annie Kim, anniekim.pku@gmail.com
 Date:       Apr 10, 2013
 Update:     Jul 16, 2013 [Two pointers ('last' and 'lastlast').]
 Problem:    Remove Duplicates from Sorted Array II
 Difficulty: Easy
 Source:     http://leetcode.com/onlinejudge#question_80
 Notes:
 Follow up for "Remove Duplicates":
 What if duplicates are allowed at most twice?
 For example,
 Given sorted array A = [1,1,1,2,2,3],
 Your function should return length = 5, and A is now [1,1,2,2,3].

 Solution: ...
 */

class Solution {
public:
    int removeDuplicates(int A[], int n) {
        if (n <= 2) return n;
        int j = 2;
        for (int i = 2; i < n; ++i)
            if (A[i] != A[j-1] || A[i] != A[j-2])
                A[j++] = A[i];
        return j;
    }
};/*
 Author:     Annie Kim, anniekim.pku@gmail.com
 Date:       Apr 10, 2013
 Update:     Jul 17, 2013 (Add solution 2)
 Problem:    Remove Duplicates from Sorted List
 Difficulty: Easy
 Source:     http://leetcode.com/onlinejudge#question_83
 Notes:
 Given a sorted linked list, delete all duplicates such that each element appear only once.
 For example,
 Given 1->1->2, return 1->2.
 Given 1->1->2->3->3, return 1->2->3.

 Solution: 1. Delete duplicates directly.
           2. Copy value first (like Remove Duplicates from Array) and then delete the remaining elements.
 */

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
    ListNode *deleteDuplicates(ListNode *head) {
        return deleteDuplicates_1(head);
    }
    
    ListNode *deleteDuplicates_1(ListNode *head) {
        if (!head) return head;
        ListNode *cur = head;
        while (cur->next)
        {
            if (cur->val == cur->next->val)
            {
                ListNode *del = cur->next;
                cur->next = del->next;
                delete del;
            }
            else
            {
                cur = cur->next;
            }
        }
        return head;
    }
    
    ListNode *deleteDuplicates_2(ListNode *head) {
        if (!head) return head;
        ListNode *last = head, *cur = head->next;
        while (cur)
        {
            if (last->val != cur->val) {
                last = last->next;
                last->val = cur->val;
            }
            cur = cur->next;
        }
        cur = last->next;
        while (cur) {
            ListNode *del = cur;
            cur = cur->next;
            delete del;
        }
        last->next = NULL;
        return head;
    }
};
/*
 Author:     Annie Kim, anniekim.pku@gmail.com
 Date:       Apr 10, 2013
 Update:     Sep 27, 2013
 Problem:    Remove Duplicates from Sorted List II
 Difficulty: Easy
 Source:     http://leetcode.com/onlinejudge#question_82
 Notes:
 Given a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list.
 For example,
 Given 1->2->3->3->4->4->5, return 1->2->5.
 Given 1->1->1->2->3, return 2->3.

 Solution: 1. iterative 2. recursive
 */

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
    ListNode *deleteDuplicates(ListNode *head) {
        return deleteDuplicates_1(head);
    }
    
    ListNode *deleteDuplicates_1(ListNode *head) {
        ListNode dummy(0), *cur = &dummy;
        dummy.next = head;
        while (cur->next)
        {
            ListNode *node = cur->next;
            int val = node->val;
            if (!node->next || node->next->val != val) {
                cur = cur->next;
                continue;
            }
            while (node && node->val == val) {
                ListNode *del = node;
                node = node->next;
                delete del;
            }
            cur->next = node;
        }
        return dummy.next;
    }
    
    ListNode *deleteDuplicates_2(ListNode *head) {
        if (!head) return NULL;
        if (!head->next || head->val != head->next->val) {
            head->next = deleteDuplicates(head->next);
            return head;
        }
        int val = head->val;
        while(head && head->val == val) {
            ListNode *del = head;
            head = head->next;
            delete del;
        }
        return deleteDuplicates(head);
    }
};/*
 Author:     Annie Kim, anniekim.pku@gmail.com
 Date:       Apr 10, 2013
 Update:     Jul 20, 2013
 Problem:    Remove Element
 Difficulty: Easy
 Source:     http://leetcode.com/onlinejudge#question_27
 Notes:
 Given an array and a value, remove all instances of that value in place and return the new length.
 The order of elements can be changed. It doesn't matter what you leave beyond the new length.

 Solution: Refactor: Update solution. Use two pointers.
 */

class Solution {
public:
    int removeElement(int A[], int n, int elem) {
        int i = 0;
        for (int j = 0; j < n; ++j)
            if (A[j] != elem)
                A[i++] = A[j];
        return i;
    }
};
/*
 Author:     Annie Kim, anniekim.pku@gmail.com
 Date:       Apr 10, 2013
 Update:     Sep 27, 2013
 Problem:    Remove Nth Node From End of List
 Difficulty: Medium
 Source:     http://leetcode.com/onlinejudge#question_19
 Notes:
 Given a linked list, remove the nth node from the end of list and return its head.
 For example,
 Given linked list: 1->2->3->4->5, and n = 2.
 After removing the second node from the end, the linked list becomes 1->2->3->5.
 Note:
 Given n will always be valid.
 Try to do this in one pass.

 Solution: head---back------front------>NULL
                   |          |
                   ---> n <----
 */

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
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        ListNode dummy(0), *back = &dummy, *front = &dummy;
        dummy.next = head;
        while (n--) front = front->next;
        while (front->next) {
            front = front->next;
            back = back->next;
        }
        ListNode *del = back->next;
        back->next = del->next;
        delete del;
        return dummy.next;
    }
};/*
 Author:     Annie Kim, anniekim.pku@gmail.com
 Date:       Nov 11, 2013
 Problem:    Reorder List
 Difficulty: Easy
 Source:     http://oj.leetcode.com/problems/reorder-list/
 Notes:
 Given a singly linked list L: L0->L1->...->Ln-1->Ln,
 reorder it to: L0->Ln->L1->Ln-1->L2->Ln-2->...
 You must do this in-place without altering the nodes' values.
 For example,
 Given {1,2,3,4}, reorder it to {1,4,2,3}.

 Solution: Reverse the back half first, then reorder.
*/

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
    void reorderList(ListNode *head) {
        if (!head || !head->next) return;
        ListNode *slow = head, *fast = head->next->next;
        while (fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
        }
        if (fast) slow = slow->next;
        ListNode *mid = slow, *cur = slow->next;
        while (cur->next) {
            ListNode *mov = cur->next;
            cur->next = mov->next;
            mov->next = mid->next;
            mid->next = mov;
        }
        cur = head;
        while (cur != mid && mid->next) {
            ListNode *mov = mid->next;
            mid->next = mov->next;
            mov->next = cur->next;
            cur->next = mov;
            cur = cur->next->next;
        }
    }
};/*
 Author:     Annie Kim, anniekim.pku@gmail.com
 Date:       May 1, 2013
 Update:     Jul 26, 2013
 Problem:    Restore IP Addresses
 Difficulty: Easy
 Source:     http://leetcode.com/onlinejudge#question_93
 Notes:
 Given a string containing only digits, restore it by returning all possible valid IP address combinations.
 For example:
 Given "25525511135",
 return ["255.255.11.135", "255.255.111.35"]. (Order does not matter)

 Solution: DFS.
 */

class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> res;
        string ip;
        restoreIpAddressRe(s, res, ip, 0, 0);
        return res;
    }
    
    void restoreIpAddressRe(string &s, vector<string> &res, string &ip, int deep, int start)
    {
        if (deep == 4 && start == s.size())
            res.push_back(ip);
        if (deep == 4) return;
        
        int num = 0, origSize = ip.size();
        if (origSize != 0) ip.push_back('.');
        for (int i = start; i < s.size(); ++i)
        {
            num = num * 10 + s[i] - '0';
            if (num > 255) break;
            ip.push_back(s[i]);
            restoreIpAddressRe(s, res, ip, deep + 1, i + 1);
            if (num == 0) break;
        }
        ip.resize(origSize);
    }
};/*
 Author:     Annie Kim, anniekim.pku@gmail.com
 Date:       Apr 7, 2013
 Update:     Sep 1, 2013
 Problem:    Reverse Integer
 Difficulty: Easy
 Source:     http://leetcode.com/onlinejudge#question_7
 Notes:
 Reverse digits of an integer.
 Example1: x = 123, return 321
 Example2: x = -123, return -321

 Have you thought about this?
 Here are some good questions to ask before coding. Bonus points for you if you have already thought through this!
 If the integer's last digit is 0, what should the output be? ie, cases such as 10, 100.
 Did you notice that the reversed integer might overflow? Assume the input is a 32-bit integer, then the reverse of 1000000003 overflows. How should you handle such cases?
 Throw an exception? Good, but what if throwing an exception is not an option? You would then have to re-design the function (ie, add an extra parameter).

 Solution: Use % and / iteratively.
 */
class Solution {
public:
    int reverse(int x) {
        long long res = 0;
        while (x) {
            res = res * 10 + (x % 10);
            x /= 10;
        }
        assert(res >= INT_MIN && res <= INT_MAX);
        return res;
    }
};/*
 Author:     Annie Kim, anniekim.pku@gmail.com
 Date:       Apr 9, 2013
 Update:     Jul 28, 2013
 Problem:    Reverse Linked List II
 Difficulty: Easy
 Source:     http://leetcode.com/onlinejudge#question_92
 Notes:
 Reverse a linked list from position m to n. Do it in-place and in one-pass.
 For example:
 Given 1->2->3->4->5->NULL, m = 2 and n = 4,
 return 1->4->3->2->5->NULL.
 Note:
 Given m, n satisfy the following condition:
 1 <= m <= n <= length of list.

 Solution: in-place & one-pass.
 */

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
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        ListNode dummy(0), *ins = &dummy;
        dummy.next = head;
        for (int i = 0; i < m-1; ++i)
            ins = ins->next;
        ListNode *cur = ins->next;
        for (int i = 0; i < n-m; ++i) {
            ListNode *move = cur->next;
            cur->next = move->next;
            move->next = ins->next;
            ins->next = move;
        }
        return dummy.next;
    }
};/*
 Author:     Annie Kim, anniekim.pku@gmail.com
 Date:       Apr 18, 2013
 Update:     Jul 20, 2013
 Problem:    Reverse Nodes in k-Group
 Difficulty: Easy
 Source:     http://leetcode.com/onlinejudge#question_25
 Notes:
 Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.
 If the number of nodes is not a multiple of k then left-out nodes in the end should remain as it is.
 You may not alter the values in the nodes, only nodes itself may be changed.
 Only constant memory is allowed.
 For example,
 Given this linked list: 1->2->3->4->5
 For k = 2, you should return: 2->1->4->3->5
 For k = 3, you should return: 3->2->1->4->5

 Solution: ...
 */

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
    ListNode *reverseKGroup(ListNode *head, int k) {
        if (k <= 1) return head;
        int reverseTimes = GetLength(head) / k;
        ListNode dummy(0); dummy.next = head;
        ListNode *ins = &dummy, *cur = ins->next;
        while (reverseTimes--) 
        {
            for (int i = 0; i < k - 1; ++i) {
                ListNode *move = cur->next;
                cur->next = move->next;
                move->next = ins->next;
                ins->next = move;
            }
            ins = cur;
            cur = ins->next;
        }
        return dummy.next;
    }

    int GetLength(ListNode *head) {
        int length = 0;
        while (head) {
            head = head->next;
            length++;
        }
        return length;
    }
};/*
 Author:     Annie Kim, anniekim.pku@gmail.com
 Date:       May 13, 2013
 Update:     Sep 22, 2013
 Problem:    Roman to Integer
 Difficulty: Easy
 Source:     http://leetcode.com/onlinejudge#question_13
 Notes:
 Given a roman numeral, convert it to an integer.
 Input is guaranteed to be within the range from 1 to 3999.

 Solution: use <map> or <unordered_map> (clean)
 */

class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> roman;
        roman['M'] = 1000;
        roman['D'] = 500;
        roman['C'] = 100;
        roman['L'] = 50;
        roman['X'] = 10;
        roman['V'] = 5;
        roman['I'] = 1;

        int res = 0, N = s.size();
        for (int i = 0; i < N; ++i)
        {
            if (i < N-1 && roman[s[i]] < roman[s[i+1]])
                res -= roman[s[i]];
            else
                res += roman[s[i]];
        }
        return res;
    }
};
/*
 Author:     Annie Kim, anniekim.pku@gmail.com
 Date:       Apr 9, 2013
 Update:     Jul 21, 2013 (Add solution 2)
 Problem:    Rotate Image
 Difficulty: Easy
 Source:     http://leetcode.com/onlinejudge#question_48
 Notes:
 You are given an n x n 2D matrix representing an image.
 Rotate the image by 90 degrees (clockwise).
 Follow up:
 Could you do this in-place?

 Solution: 1. Rotate one-fourth of the image clockwise.
           2. 123   ->  147   ->   741    (preferable)
              456       258        852
              789       369        963
 */

class Solution {
public:
    void rotate(vector<vector<int> > &matrix) {
        rotate_2(matrix);
    }
    
    void rotate_1(vector<vector<int> > &matrix) {
        int n = matrix.size();
        for (int i = 0; i < (n + 1) / 2; i++)
            for (int j = 0; j < n / 2; j++)
                rotateElement(matrix, i, j);
    }
    void rotateElement(vector<vector<int> > &matrix, int row, int col)
    {
        int temp = matrix[row][col];
        for (int i = 0; i < 3; i++)
        {
            int c = row;
            int r = matrix.size() - 1 - col;
            matrix[row][col] = matrix[r][c];
            row = r;
            col = c;
        }
        matrix[row][col] = temp;
    }
    
    void rotate_2(vector<vector<int> > &matrix) {
        int N = matrix.size();
        for (int i = 0; i < N; ++i)
            for (int j = i+1; j < N; ++j)
                swap(matrix[i][j], matrix[j][i]);
        for (int j = 0; j < N/2; ++j)
            for (int i = 0; i < N; ++i)
                swap(matrix[i][j], matrix[i][N-j-1]);
    }
};
/*
 Author:     Annie Kim, anniekim.pku@gmail.com
 Date:       Apr 8, 2013
 Problem:    Rotate List
 Difficulty: Easy
 Source:     http://leetcode.com/onlinejudge#question_61
 Notes:
 Given a list, rotate the list to the right by k places, where k is non-negative.

 For example:
 Given 1->2->3->4->5->NULL and k = 2,
 return 4->5->1->2->3->NULL.

 Solution: Notice that k can be larger than the list size (k % list_size).
           This solution traverses the list twice at most.
*/

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
    ListNode *rotateRight(ListNode *head, int k) {
        if (!head) return NULL;
        
        ListNode* tail = head;
        int count = 1;
        while (tail->next)
        {
            tail = tail->next;
            count++;
        }
        k = k % count;   // in case the list rotates more than one round.
        if (k == 0) return head;
        
        ListNode* cur = head;
        for (int i = 0; i < count - k - 1; i++)
            cur = cur->next;
        
        ListNode* newHead = cur->next;
        cur->next = NULL;
        tail->next = head;
        
        return newHead;
    }
};/*
 Author:     Annie Kim, anniekim.pku@gmail.com
 Date:       Apr 7, 2013
 Problem:    Same Tree
 Difficulty: easy
 Source:     http://leetcode.com/onlinejudge#question_100
 Notes:
 Given two binary trees, write a function to check if they are equal or not.
 Two binary trees are considered equal if they are structurally identical and the nodes have the same value.

 Solution: recursion.
 */

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isSameTree(TreeNode *p, TreeNode *q) {
        if (!p && !q) return true;
        if (p && !q || !p && q) return false;
        if (p->val != q->val) return false;
        
        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};/*
 Author:     Annie Kim, anniekim.pku@gmail.com
 Date:       Jul 12, 2013
 Update:     Sep 13, 2013
 Problem:    Scramble String
 Difficulty: Medium
 Source:     http://leetcode.com/onlinejudge#question_87
 Notes:
 Given a string s1, we may represent it as a binary tree by partitioning it to two non-empty substrings recursively.
 Below is one possible representation of s1 = "great":
       great
      /     \
     gr    eat
    / \    /  \
   g   r  e   at
  / \
 a   t
 To scramble the string, we may choose any non-leaf node and swap its two children.
 For example, if we choose the node "gr" and swap its two children, it produces a scrambled string "rgeat".
       rgeat
      /     \
     rg    eat
    / \    /  \
   r   g  e   at
  / \
 a   t
 We say that "rgeat" is a scrambled string of "great".
 Similarly, if we continue to swap the children of nodes "eat" and "at", it produces a scrambled string "rgtae".
      rgtae
      /    \
     rg    tae
    / \    /  \
   r   g  ta  e
  / \
 t   a
 We say that "rgtae" is a scrambled string of "great".
 Given two strings s1 and s2 of the same length, determine if s2 is a scrambled string of s1.

 Solution: 1. 3-dimensional dp. Contributed by yinlinglin. I really appreciate it!
              'dp[k][i][j] == true' means string s1(start from i, length k) is a scrambled string of 
              string s2(start from j, length k).
           2. Recursion + pruning.
 */

class Solution {
public:
    bool isScramble(string s1, string s2) {
        return isScramble_2(s1, s2);
    }
    
    // solution 1: dp.
    bool isScramble_1(string s1, string s2) {
        if(s1.size() != s2.size()) return false;
        int N = s1.size();
        bool dp[N+1][N][N];
        for (int k = 1; k <= N; ++k)
            for (int i = 0; i <= N-k; ++i)
                for (int j = 0; j <= N-k; ++j)
                {
                    dp[k][i][j] = false;
                    if (k == 1) 
                        dp[1][i][j] = (s1[i] == s2[j]);
                    for (int p = 1; p < k && !dp[k][i][j]; ++p)
                        if (dp[p][i][j] && dp[k-p][i+p][j+p] || dp[p][i][j+k-p] && dp[k-p][i+p][j])
                            dp[k][i][j] = true;
                }
        return dp[N][0][0];
    }

    // solution 2: recursion + pruning.
    typedef string::iterator Iterator;
    
    bool isScramble_2(string s1, string s2) {
        if (s1.size() != s2.size()) return false;
        return isScrambleRe(s1.begin(), s2.begin(), s1.size());
    }

    bool isScrambleRe(Iterator s1, Iterator s2, int len) {
        if (!hasSameLetters(s1, s2, len)) return false;
        if (len == 0 || len == 1) return true;
        for (int i = 1; i < len; ++i)  // highlight
            if (isScrambleRe(s1, s2, i) && isScrambleRe(s1 + i, s2 + i, len - i) ||
                isScrambleRe(s1, s2 + len - i, i) && isScrambleRe(s1 + i, s2, len - i))
                return true;
        return false;
    }

    bool hasSameLetters(Iterator s1, Iterator s2, int len) {
        int count[256] = {0};
        for (int i = 0; i < len; ++i) count[*s1++]++;
        for (int i = 0; i < len; ++i) count[*s2++]--;
        for (int i = 0; i < 256; ++i)
            if (count[i] != 0) return false;
        return true;
    }
};
/*
 Author:     Annie Kim, anniekim.pku@gmail.com
 Date:       Apr 18, 2013
 Problem:    Search Insert Position
 Difficulty: Easy
 Source:     http://leetcode.com/onlinejudge#question_35
 Notes:
 Given a sorted array and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.
 You may assume no duplicates in the array.
 Here are few examples.
 [1,3,5,6], 5 -> 2
 [1,3,5,6], 2 -> 1
 [1,3,5,6], 7 -> 4
 [1,3,5,6], 0 -> 0

 Solution: Binary search.
 */

class Solution {
public:
    int searchInsert(int A[], int n, int target) {
        int i = 0, j = n - 1;
        while (i <= j)
        {
            int mid = (i + j) / 2;
            if (A[mid] == target)
                return mid;
            if (A[mid] < target)
                i = mid + 1;
            else
                j = mid - 1;
        }
        return i;
    }
};/*
 Author:     Annie Kim, anniekim.pku@gmail.com
 Date:       Apr 16, 2013
 Update:     Sep 27, 2013
 Problem:    Search a 2D Matrix
 Difficulty: Easy
 Source:     http://leetcode.com/onlinejudge#question_74
 Notes:
 Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:

 Integers in each row are sorted from left to right.
 The first integer of each row is greater than the last integer of the previous row.
 For example,

 Consider the following matrix:

 [
    [1,   3,  5,  7],
    [10, 11, 16, 20],
    [23, 30, 34, 50]
 ]
 Given target = 3, return true.

 Solution: Binary-search.
 */

class Solution {
public:
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        return searchMatrix_2(matrix, target);
    }
    
    // Solution 1.
    bool searchMatrix_1(vector<vector<int> > &matrix, int target) {
        if (matrix.empty() || matrix[0].empty()) return false;
        int N = matrix.size(), M = matrix[0].size();
        int i = 0, j = N-1;
        while (i <= j)
        {
            int mid = (i + j) / 2;
            if (matrix[mid][0] == target) return true;
            else if (matrix[mid][0] < target) i++;
            else j--;
        }
        int row = j;
        if (row < 0) return false;
        i = 0, j = M - 1;
        while (i <= j)
        {
            int mid = (i + j) / 2;
            if (matrix[row][mid] == target) return true;
            else if (matrix[row][mid] < target) i++;
            else j--;
        }
        return false;
    }
    
    // Solution 2.
    bool searchMatrix_2(vector<vector<int> > &matrix, int target) {
        if (matrix.empty() || matrix[0].empty()) return false;
        int N = matrix.size(), M = matrix[0].size();
        int i = 0, j = M * N - 1;
        while (i <= j)
        {
            int mid = (i + j) / 2;
            int row = mid / M, col = mid % M;
            if (matrix[row][col] == target) return true;
            else if (matrix[row][col] < target) i = mid + 1;
            else j = mid - 1;
        }
        return false;
    }
};/*
 Author:     Annie Kim, anniekim.pku@gmail.com
 Date:       Apr 8, 2013
 Problem:    Search for a Range
 Difficulty: Medium
 Source:     http://leetcode.com/onlinejudge#question_34
 Notes:
 Given a sorted array of integers, find the starting and ending position of a given target value.

 Your algorithm's runtime complexity must be in the order of O(log n).

 If the target is not found in the array, return [-1, -1].

 For example,
 Given [5, 7, 7, 8, 8, 10] and target value 8,
 return [3, 4].

 Solution: It takes O(lgN) to find both the lower-bound and upper-bound.
 */

class Solution {
public:
    vector<int> searchRange(int A[], int n, int target) {
        vector<int> res(2, -1);
        int lower = getLowerBound(A, n, target);
        int upper = getUpperBound(A, n, target);
        if (lower <= upper)
        {
            res[0] = lower;
            res[1] = upper;
        }
        return res;
    }
    
    int getLowerBound(int A[], int n, int target)
    {
        int l = 0, u = n-1;
        while (l <= u)
        {
            int mid = (l + u) / 2;
            if (A[mid] < target)
                l = mid + 1;
            else
                u = mid - 1;
        }
        return l;
    }
    
    int getUpperBound(int A[], int n, int target)
    {
        int l = 0, u = n-1;
        while (l <= u)
        {
            int mid = (l + u) / 2;
            if (A[mid] <= target)
                l = mid + 1;
            else
                u = mid - 1;
        }
        return u;
    }
};
/*
 Author:     Annie Kim, anniekim.pku@gmail.com
 Date:       Apr 8, 2013
 Update:     Aug 7, 2013
 Problem:    Search in Rotated Sorted Array
 Difficulty: Medium
 Source:     http://leetcode.com/onlinejudge#question_33
 Notes:
 Suppose a sorted array is rotated at some pivot unknown to you beforehand.
 (i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).
 You are given a target value to search. If found in the array return its index, otherwise return -1.
 You may assume no duplicate exists in the array.

 Solution: Binary search. O(lgn) eg. [4 5 6] -7- 8 1 2, 5 6 0 -1- [2 3 4]
 */

class Solution {
public:
    int search(int A[], int n, int target) {
        int i = 0, j = n - 1;
        while (i <= j)
        {
            int mid = (i + j) / 2;
            if (A[mid] == target)
                return mid;
            if (A[i] <= A[mid])
            {
                if (A[i] <= target && target < A[mid])
                    j = mid - 1;
                else
                    i = mid + 1;
            }
            else
            {
                if (A[mid] < target && target <= A[j])
                    i = mid + 1;
                else
                    j = mid - 1;
            }
        }
        return -1;
    }
};
/*
 Author:     Annie Kim, anniekim.pku@gmail.com
 Date:       Apr 8, 2013
 Problem:    Search in Rotated Sorted Array II
 Difficulty: Medium
 Source:     http://leetcode.com/onlinejudge#question_81
 Notes:
 Suppose a sorted array is rotated at some pivot unknown to you beforehand.
 (i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).
 What if duplicates are allowed?
 Would this affect the run-time complexity? How and why?
 Write a function to determine if a given target is in the array.

 Solution: Sequence search. O(n)
           Since there are duplicates, it's hard to decide which branch to go if binary-search is deployed.
 */

class Solution {
public:
    bool search(int A[], int n, int target) {
        for (int i = 0; i < n; i++)
            if (A[i] == target)
                return true;
        return false;
    }
};/*
 Author:     Annie Kim, anniekim.pku@gmail.com
 Date:       May 25, 2013
 Update:     Jul 23, 2013
 Problem:    Set Matrix Zeroes
 Difficulty: Medium
 Source:     http://leetcode.com/onlinejudge#question_73
 Notes:
 Given a m x n matrix, if an element is 0, set its entire row and column to 0. Do it in place.
 Follow up:
 Did you use extra space?
 A straight forward solution using O(mn) space is probably a bad idea.
 A simple improvement uses O(m + n) space, but still not the best solution.
 Could you devise a constant space solution?

 Solution: Use first row and column as auxiliary spaces instead of newly allocating ones.
*/

class Solution {
public:
    void setZeroes(vector<vector<int>> &matrix) {
        if (matrix.empty()) return;
        int N = matrix.size(), M = matrix[0].size();
        bool setFirstRowZero = false;
        bool setFirstColZero = false;

        for (int i = 0; i < N && !setFirstColZero; ++i)
            setFirstColZero = (matrix[i][0] == 0);
        for (int j = 0; j < M && !setFirstRowZero; ++j)
            setFirstRowZero = (matrix[0][j] == 0);

        for (int i = 1; i < N; ++i)
            for (int j = 1; j < M; ++j)
                if (matrix[i][j] == 0) {
                    matrix[0][j] = 0;
                    matrix[i][0] = 0;
                }

        for (int i = 1; i < N; ++i)
            if (matrix[i][0] == 0)
                for (int j = 1; j < M; ++j)
                    matrix[i][j] = 0;

        for (int j = 1; j < M; ++j)
            if (matrix[0][j] == 0)
                for (int i = 1; i < N; ++i)
                    matrix[i][j] = 0;

        if (setFirstRowZero)
            for (int j = 0; j < M; ++j)
                matrix[0][j] = 0;

        if (setFirstColZero)
            for (int i = 0; i < N; ++i)
                matrix[i][0] = 0;
    }
};
/*
 Author:     Annie Kim, anniekim.pku@gmail.com
 Date:       May 13, 2013
 Update:     Aug 11, 2013
 Problem:    Simplify Path
 Difficulty: Easy
 Source:     http://leetcode.com/onlinejudge#question_71
 Notes:
 Given an absolute path for a file (Unix-style), simplify it.

 For example,
 path = "/home/", => "/home"
 path = "/a/./b/../../c/", => "/c"

 Corner Cases:
 Did you consider the case where path = "/../"?
 In this case, you should return "/".
 Another corner case is the path might contain multiple slashes '/' together, such as "/home//foo/".
 In this case, you should ignore redundant slashes and return "/home/foo".

 Solution: Add an additional '/' at the end of 'path' for simply detecting the end.
 */

class Solution {
public:
    string simplifyPath(string path) {
        string res;
        path += "/";
        size_t pos = path.find_first_of("/"), last = 0;
        while (pos != string::npos)
        {
            string s = path.substr(last, pos - last);
            if (s == "..") 
            {
                if (!res.empty())
                    res.resize(res.find_last_of("/"));
            }
            else if (!s.empty() && s != ".")
            {
                res += "/";
                res += s;
            }
            last = pos + 1;
            pos = path.find_first_of("/", last);
        }
        return res.empty() ? "/" : res;
    }
};
/*
 Author:     Annie Kim, anniekim.pku@gmail.com
 Date:       Oct 3, 2013
 Problem:    Single Number
 Difficulty: Easy
 Source:     http://oj.leetcode.com/problems/single-number/
 Notes:
 Given an array of integers, every element appears twice except for one. 
 Find that single one.
 Your algorithm should have a linear runtime complexity. 
 Could you implement it without using extra memory?

 Solution: XOR.
*/

class Solution {
public:
    int singleNumber(int A[], int n) {
        for (int i = 1; i < n; ++i)
            A[0] ^= A[i];
        return A[0];
    }
};/*
 Author:     Annie Kim, anniekim.pku@gmail.com
 Date:       Oct 5, 2013
 Problem:    Single Number II
 Difficulty: Easy
 Source:     http://oj.leetcode.com/problems/single-number-ii/
 Notes:
 Given an array of integers, every element appears three times except for one. 
 Find that single one.
 Your algorithm should have a linear runtime complexity. Could you implement it 
 without using extra memory?

 Solution: Count the number of each bit.
*/

class Solution {
public:
    int singleNumber(int A[], int n) {
        int res = 0;
        for (int i = 0; i < 32; ++i) 
        {
            int count = 0, bit = 1 << i;
            for (int j = 0; j < n; ++j)
                if (A[j] & bit)
                    count++;
            if (count % 3 != 0)
                res |= bit;
        }
        return res;
    }
};/*
 Author:     Annie Kim, anniekim.pku@gmail.com
 Date:       Apr 8, 2013
 Update:     Jul 24, 2013
 Problem:    Sort Colors
 Difficulty: Medium
 Source:     http://leetcode.com/onlinejudge#question_75
 Notes:
 Given an array with n objects colored red, white or blue, sort them so that objects of the same color
 are adjacent, with the colors in the order red, white and blue.
 Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively.
 Note:
 You are not suppose to use the library's sort function for this problem.
 Follow up:
 A rather straight forward solution is a two-pass algorithm using counting sort.
 First, iterate the array counting number of 0's, 1's, and 2's, then overwrite array with 
 total number of 0's, then 1's and followed by 2's.
 Could you come up with an one-pass algorithm using only constant space?

 Solution: 0 0 0 1 1 1 1 ...... 2 2 2 2
               |         |      |
             zero        i     two
              ->        ->     <-  
 */

class Solution {
public:
    void sortColors(int A[], int n) {
        int zero = -1, two = n;
        int i = 0;
        while (i < two)
        {
            switch(A[i])
            {
            case 0:
                swap(A[i++], A[++zero]);
                break;
            case 1:
                i++;
                break;
            case 2:
                swap(A[i], A[--two]);
            }
        }
    }
};
/*
 Author:     Annie Kim, anniekim.pku@gmail.com
 Date:       May 13, 2013
 Update:     Sep 30, 2013
 Problem:    Spiral Matrix
 Difficulty: Easy
 Source:     http://leetcode.com/onlinejudge#question_54
 Notes:
 Given a matrix of m x n elements (m rows, n columns), return all elements of the matrix in spiral order.
 For example,
 Given the following matrix:
 [
 [ 1, 2, 3 ],
 [ 4, 5, 6 ],
 [ 7, 8, 9 ]
 ]
 You should return [1,2,3,6,9,8,7,4,5].

 Solution: ...
 */

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int> > &matrix) {
        vector<int> res;
        if (matrix.empty() || matrix[0].empty()) return res;
        int imin = 0, imax = matrix.size()-1;
        int jmin = 0, jmax = matrix[0].size()-1;
        while (true)
        {
            for (int j = jmin; j <= jmax; ++j) res.push_back(matrix[imin][j]);
            if (++imin > imax) break;
            for (int i = imin; i <= imax; ++i) res.push_back(matrix[i][jmax]);
            if (jmin > --jmax) break;
            for (int j = jmax; j >= jmin; --j) res.push_back(matrix[imax][j]);
            if (imin > --imax) break;
            for (int i = imax; i >= imin; --i) res.push_back(matrix[i][jmin]);
            if (++jmin > jmax) break;
        }
        return res;
    }
};
/*
 Author:     Annie Kim, anniekim.pku@gmail.com
 Date:       May 13, 2013
 Update:     Aug 24, 2013
 Problem:    Spiral Matrix II
 Difficulty: Easy
 Source:     http://leetcode.com/onlinejudge#question_59
 Notes:
 Given an integer n, generate a square matrix filled with elements from 1 to n2 in spiral order.
 For example,
 Given n = 3,
 You should return the following matrix:
 [
 [ 1, 2, 3 ],
 [ 8, 9, 4 ],
 [ 7, 6, 5 ]
 ]

 Solution: ...
 */

class Solution {
public:
    vector<vector<int> > generateMatrix(int n) {
        if (n == 0) return vector<vector<int> >();
        vector<vector<int> > res(n, vector<int>(n));
        int imin = 0, imax = n-1, jmin = 0, jmax = n-1;
        int number = 1;
        while (true)
        {
            for (int j = jmin; j <= jmax; ++j) res[imin][j] = number++;
            if (++imin > imax) break;
            for (int i = imin; i <= imax; ++i) res[i][jmax] = number++;
            if (jmin > --jmax) break;
            for (int j = jmax; j >= jmin; --j) res[imax][j] = number++;
            if (imin > --imax) break;
            for (int i = imax; i >= imin; --i) res[i][jmin] = number++;
            if (++jmin > jmax) break;
        }
        return res;
    }
};
/*
 Author:     Annie Kim, anniekim.pku@gmail.com
 Date:       Apr 18, 2013
 Problem:    Sqrt(x)
 Difficulty: Easy
 Source:     http://leetcode.com/onlinejudge#question_69
 Notes:
 Implement int sqrt(int x).
 Compute and return the square root of x.

 Solution: 1. Binary search in range [0, x / 2 + 1].
           2. Newton iteration method. x(i+1) = (x(i) + n/x(i)) / 2.
 See my blog (http://www.cnblogs.com/AnnieKim/archive/2013/04/18/3028607.html) for more explanation (in Chinese).
 */

class Solution {
public:
    int sqrt_1(int x) {
        long long i = 0;
        long long j = x / 2 + 1;
        while (i <= j)
        {
            long long mid = (i + j) / 2;
            long long sq = mid * mid;
            if (sq == x) return mid;
            else if (sq < x) i = mid + 1;
            else j = mid - 1;
        }
        return j;
    }

    int sqrt_2(int x) {
        if (x == 0) return 0;
        double last = 0;
        double res = 1;
        while (res != last)
        {
            last = res;
            res = (res + x / res) / 2;
        }
        return int(res);
    }
};
/*
 Author:     Annie Kim, anniekim.pku@gmail.com
 Date:       May 17, 2013
 Update:     Sep 22, 2013
 Problem:    String to Integer (atoi)
 Difficulty: Easy
 Source:     http://leetcode.com/onlinejudge#question_8
 Notes:
 Implement atoi to convert a string to an integer.
 Hint: Carefully consider all possible input cases. If you want a challenge, please do not 
 see below and ask yourself what are the possible input cases.
 Notes: It is intended for this problem to be specified vaguely (ie, no given input specs). 
 You are responsible to gather all the input requirements up front.

 Requirements for atoi:
 The function first discards as many whitespace characters as necessary until the first 
 non-whitespace character is found. Then, starting from this character, takes an optional
 initial plus or minus sign followed by as many numerical digits as possible, and interprets 
 them as a numerical value.
 The string can contain additional characters after those that form the integral number, which 
 are ignored and have no effect on the behavior of this function.
 If the first sequence of non-whitespace characters in str is not a valid integral number, or 
 if no such sequence exists because either str is empty or it contains only whitespace characters, 
 no conversion is performed.
 If no valid conversion could be performed, a zero value is returned. If the correct value is out 
 of the range of representable values, INT_MAX (2147483647) or INT_MIN (-2147483648) is returned.

 Solution: ...
 */

class Solution {
public:
    int atoi(const char *str) {
        if (!str) return 0;
        while (*str == ' ') str++;
        bool positive = true;
        if (*str == '+' || *str == '-') {
            positive = *str == '+';
            str++;
        }
        long long res = 0;
        while (isdigit(*str)) {
            res = res * 10 + (*str - '0');
            str++;
        }
        res = positive ? res : -res;
        if (res > INT_MAX) return INT_MAX;
        if (res < INT_MIN) return INT_MIN;
        return (int)res;
    }
};
/*
 Author:     Annie Kim, anniekim.pku@gmail.com
 Date:       Apr 24, 2013
 Update:     Sep 16, 2013
 Problem:    Subsets
 Difficulty: Easy
 Source:     http://leetcode.com/onlinejudge#question_78
 Notes:
 Given a set of distinct integers, S, return all possible subsets.
 Note:
 Elements in a subset must be in non-descending order.
 The solution set must not contain duplicate subsets.
 For example,
 If S = [1,2,3], a solution is:
 [
  [3],
  [1],
  [2],
  [1,2,3],
  [1,3],
  [2,3],
  [1,2],
  []
 ]

 Solution: 1. Recursive solution.
           2. Iterative solution. Contributed by yinlinglin.
 */

class Solution {
public:
    vector<vector<int> > subsets(vector<int> &S) {
        return subsets_1(S);
    }
    
    vector<vector<int> > subsets_1(vector<int> &S) {
        vector<vector<int> > res(1, vector<int>());
        sort(S.begin(), S.end());
        vector<int> set;
        int N = S.size();
        for (int l = 1; l <= N; ++l)
            subsetsRe(S, l, 0, set, res);
        return res;
    }
    
    void subsetsRe(vector<int> &S, int L, int start, vector<int> &set, vector<vector<int> > &res)
    {
        int N = S.size(), M = set.size();
        if (M == L) {
            res.push_back(set);
            return;
        }
        for (int i = start; i <= N - (L - M); ++i) {
            set.push_back(S[i]);
            subsetsRe(S, L, i + 1, set, res);
            set.pop_back();
        }
    }
    
    vector<vector<int> > subsets_2(vector<int> &S) {
        vector<vector<int> > res(1, vector<int>());
        sort(S.begin(), S.end());
        int N = S.size();
        for (int L = 1; L <= N; ++L)
        {
            int stk[L];
            stk[0] = 0;
            int top = 0;
            while (true)
            {
                if (stk[top] == N)
                {
                    top--;
                    if (top < 0) break;
                    stk[top]++;
                }
                else if (top == L - 1) 
                {
                    vector<int> set;
                    for (int i = 0; i < L; ++i)
                        set.push_back(S[stk[i]]);
                    res.push_back(set);
                    stk[top]++;
                }
                else
                {
                    top++;
                    stk[top] = stk[top-1] + 1;
                }
            }
        }
        return res;
    }
};
/*
 Author:     Annie Kim, anniekim.pku@gmail.com
 Date:       Apr 30, 2013
 Problem:    Subsets II
 Difficulty: Easy
 Source:     http://leetcode.com/onlinejudge#question_90
 Notes:
 Given a collection of integers that might contain duplicates, S, return all possible subsets.
 Note:
 Elements in a subset must be in non-descending order.
 The solution set must not contain duplicate subsets.
 For example,
 If S = [1,2,2], a solution is:
 [
  [2],
  [1],
  [1,2,2],
  [2,2],
  [1,2],
  []
 ]

 Solution: ..Similar to Subset I, except for line 45.
 */
class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int> &S) {
        vector<vector<int> > res(1, vector<int>());
        sort(S.begin(), S.end());
        vector<int> set;
        int N = S.size();
        for (int l = 1; l <= N; ++l)
            subsetsWithDupRe(S, l, 0, set, res);
        return res;
    }

    void subsetsWithDupRe(vector<int> &S, int L, int start, vector<int> &set, vector<vector<int>> &res)
    {
        int N = S.size(), M = set.size();
        if (M == L) {
            res.push_back(set);
            return;
        }
        for (int i = start; i <= N - (L - M); ++i) {
            if (i > start && S[i] == S[i-1]) continue;
            set.push_back(S[i]);
            subsetsWithDupRe(S, L, i + 1, set, res);
            set.pop_back();
        }
    }
};/*
 Author:     Annie Kim, anniekim.pku@gmail.com
 Date:       May 26, 2013
 Update:     Aug 10, 2013
 Problem:    Substring with Concatenation of All Words
 Difficulty: Easy
 Source:     http://leetcode.com/onlinejudge#question_30
 Notes:
 You are given a string, S, and a list of words, L, that are all of the same length. Find all 
 starting indices of substring(s) in S that is a concatenation of each word in L exactly once 
 and without any intervening characters.
 For example, given:
 S: "barfoothefoobarman"
 L: ["foo", "bar"]
 You should return the indices: [0,9].
 (order does not matter).

 Solution: ...
*/

class Solution {
public:
    vector<int> findSubstring(string S, vector<string> &L) {
        vector<int> res;
        if (S.empty() || L.empty()) return res;
        int M = S.size(), N = L.size();
        int K = L[0].size();
        unordered_map<string, int> need;
        unordered_map<string, int> found;
        for (int i = 0; i < N; ++i)
            need[L[i]]++;
        for (int i = 0; i <= M - N * K; ++i)
        {
            found.clear();
            int j;
            for (j = 0; j < N; ++j)
            {
                string s = S.substr(i + j * K, K);
                auto it = need.find(s);
                if (it == need.end())
                    break;
                if (it->second <= found[s])
                    break;
                found[s]++;
            }
            if (j == N) res.push_back(i);
        }
        return res;
    }
};
/*
 Author:     Annie Kim, anniekim.pku@gmail.com
 Date:       Jun 19, 2013
 Update:     Sep 29, 2013
 Problem:    Sudoku Solver
 Difficulty: Medium
 Source:     http://leetcode.com/onlinejudge#question_37
 Notes:
 Write a program to solve a Sudoku puzzle by filling the empty cells.
 Empty cells are indicated by the character '.'.
 You may assume that there will be only one unique solution.

 Solution: back-tracking..
 */

class Solution {
public:
    typedef vector<vector<char> > BOARDTYPE;
    
    void solveSudoku(BOARDTYPE &board) {
        solveSudokuRe(board, 0, 0);
    }
    
    bool solveSudokuRe(BOARDTYPE &board, int row, int col) {
        getNextEmpty(board, row, col);
        if (row == 9) return true;
        vector<bool> avail(9, true);
        getAvailable(board, avail, row, col);
        for (int i = 0; i < 9; ++i)
        {
            if (!avail[i]) continue;
            board[row][col] = i + '1';
            if (solveSudokuRe(board, row, col)) return true;
        }
        board[row][col] = '.';
        return false;
    }
    
    void getNextEmpty(BOARDTYPE &board, int &row, int &col) {
        do {
            if (board[row][col] == '.') return;
            row = (col == 8) ? row + 1 : row;
            col = (col + 1) % 9;
        } while (row < 9);
    }
    
    void getAvailable(BOARDTYPE &board, vector<bool> &avail, int row, int col) {
        for (int i = 0; i < 9; ++i) {
            if (board[row][i] != '.') avail[board[row][i]-'1'] = false;
            if (board[i][col] != '.') avail[board[i][col]-'1'] = false;
            int box_i = row/3*3 + i/3, box_j = col/3*3 + i%3;
            if (board[box_i][box_j] != '.') avail[board[box_i][box_j]-'1'] = false;
        }
    }
};/*
 Author:     Annie Kim, anniekim.pku@gmail.com
 Date:       Apr 23, 2013
 Update:     Jul 21, 2013
 Problem:    Sum Root to Leaf Numbers
 Difficulty: Easy
 Source:     http://leetcode.com/onlinejudge#question_129
 Notes:
 Given a binary tree containing digits from 0-9 only, each root-to-leaf path could represent a number.
 An example is the root-to-leaf path 1->2->3 which represents the number 123.
 Find the total sum of all root-to-leaf numbers.
 For example,
   1
  / \
 2   3
 The root-to-leaf path 1->2 represents the number 12.
 The root-to-leaf path 1->3 represents the number 13.
 Return the sum = 12 + 13 = 25.

 Solution: 1. Recursion (add to sum when reaching the leaf).
           2. Iterative solution.
 */

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int sumNumbers(TreeNode *root) {
        return sumNumbers_1(root);
    }
    
    int sumNumbers_1(TreeNode *root) {
        int sum = 0;
        sumNumbersRe(root, 0, sum);
        return sum;
    }
    
    void sumNumbersRe(TreeNode *node, int num, int &sum) {
        if (!node) return;
        num = num * 10 + node->val;
        if (!node->left && !node->right) { 
            sum += num;
            return;
        }
        sumNumbersRe(node->left, num, sum);
        sumNumbersRe(node->right, num, sum);
    }
    
    int sumNumbers_2(TreeNode *root) {
        if (!root) return 0;
        int res = 0;
        queue<pair<TreeNode *, int>> q;
        q.push(make_pair(root, 0));
        while(!q.empty())
        {
            TreeNode *node = q.front().first;
            int sum = q.front().second * 10 + node->val;
            q.pop();
            if (!node->left && !node->right)
            {
                res += sum;
                continue;
            }
            if (node->left)
                q.push(make_pair(node->left, sum));
            if (node->right)
                q.push(make_pair(node->right, sum));
        }
        return res;
    }
};
/*
 Author:     Annie Kim, anniekim.pku@gmail.com
 Date:       May 20, 2013
 Update:     Aug 21, 2013
 Problem:    Surrounded Regions
 Difficulty: Easy
 Source:     http://leetcode.com/onlinejudge#question_130
 Notes:
 Given a 2D board containing 'X' and 'O', capture all regions surrounded by 'X'.
 A region is captured by flipping all 'O's into 'X's in that surrounded region .
 For example,
 X X X X
 X O O X
 X X O X
 X O X X
 After running your function, the board should be:
 X X X X
 X X X X
 X X X X
 X O X X

 Solution: Traverse from the boarder to the inside and mark all the 'O's that are not surrounded by 'X' as 'V' (visited).
           1. DFS.
           2. BFS (queue).
 */

class Solution {
public:
    typedef vector<vector<char> > BOARDTYPE;
    
    void solve(BOARDTYPE &board) {
        if (board.empty() || board[0].empty()) return;
        int N = board.size(), M = board[0].size();
        for (int i = 0; i < N; ++i)
            for (int j = 0; j < M; ++j)
                if (i == 0 || j == 0 || i == N-1 || j == M-1)
                    dfs(board, i, j); // you may call dfs or bfs here!
        for (int i = 0; i < N; ++i)
            for (int j = 0; j < M; ++j)
                board[i][j] = (board[i][j] == 'V') ? 'O' : 'X';
    }
    
    void dfs(BOARDTYPE &board, int row, int col) {
        int N = board.size(), M = board[0].size();
        if (row < 0 || row >= N || col < 0 || col >= M) return;
        if (board[row][col] != 'O') return;
        board[row][col] = 'V';
        dfs(board, row+1, col);
        dfs(board, row-1, col);
        dfs(board, row, col+1);
        dfs(board, row, col-1);
    }

    void bfs(BOARDTYPE &board, int row, int col) {
        if (board[row][col] != 'O') return;
        int N = board.size(), M = board[0].size();
        queue<pair<int, int>> q;
        q.push(make_pair(row, col));
        while (!q.empty())
        {
            int i = q.front().first, j = q.front().second;
            q.pop();
            if (i < 0 || i >= N || j < 0 || j >= M) continue;
            if (board[i][j] != 'O') continue;// important to recheck!
            board[i][j] = 'V';
            q.push(make_pair(i-1, j));
            q.push(make_pair(i+1, j));
            q.push(make_pair(i, j-1));
            q.push(make_pair(i, j+1));
        }
    }
};/*
 Author:     Annie Kim, anniekim.pku@gmail.com
 Date:       Apr 9, 2013
 Update:     Sep 3, 2013
 Problem:    Swap Nodes in Pairs
 Difficulty: Medium
 Source:     http://leetcode.com/onlinejudge#question_24
 Notes:
 Given a linked list, swap every two adjacent nodes and return its head.
 For example,
 Given 1->2->3->4, you should return the list as 2->1->4->3.
 Your algorithm should use only constant space. You may not modify the values in the list, only nodes itself can be changed.

 Solution: 1. Iterative solution with constant space.
           2. Recursive solution with O(n) space (for practice).
 */

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
    ListNode *swapPairs(ListNode *head) {
        return swapPairs_1(head);
    }
    
    ListNode *swapPairs_1(ListNode *head) {
        ListNode dummy(0), *cur = &dummy;
        cur->next = head;
        while (cur->next && cur->next->next)
        {
            ListNode *move = cur->next->next;
            cur->next->next = move->next;
            move->next = cur->next;
            cur->next = move;
            cur = move->next;
        }
        return dummy.next;
    }
    
    ListNode *swapPairs_2(ListNode *head) {
        if (!head || !head->next) return head;
        ListNode *first = head, *second = head->next;
        first->next = second->next;
        second->next = first;
        first->next = swapPairs(first->next);
        return second;
    }
};
/*
 Author:     Annie Kim, anniekim.pku@gmail.com
 Date:       Apr 22, 2013
 Update:     Jul 23, 2013
 Problem:    Symmetric Tree
 Difficulty: Easy
 Source:     http://leetcode.com/onlinejudge#question_101
 Notes:
 Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).
 For example, this binary tree is symmetric:
     1
    / \
   2   2
  / \ / \
 3  4 4  3
 But the following is not:
    1
   / \
  2   2
   \   \
   3    3
 Note:
 Bonus points if you could solve it both recursively and iteratively.

 Solution: 1. Recursive solution 2.Iterative way (queue).
 */
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isSymmetric(TreeNode *root) {
        return isSymmetric_1(root);
    }
    
    bool isSymmetric_1(TreeNode *root) {
        if (!root) return true;
        return isSymmetricRe(root->left, root->right);
    }

    bool isSymmetricRe(TreeNode *t1, TreeNode *t2)
    {
        if (!t1 && !t2) return true;
        if (!t1 || !t2 || t1->val != t2->val) return false;
        return isSymmetricRe(t1->left, t2->right) &&
               isSymmetricRe(t1->right, t2->left);
    }

    bool isSymmetric_2(TreeNode *root) {
        if (!root) return true;
        queue<TreeNode *> q;
        q.push(root->left);
        q.push(root->right);
        while (!q.empty())
        {
            TreeNode *t1 = q.front(); q.pop();
            TreeNode *t2 = q.front(); q.pop();
            if (!t1 && !t2) continue;
            if (!t1 || !t2 || t1->val != t2->val)
                return false;
            q.push(t1->left);
            q.push(t2->right);
            q.push(t1->right);
            q.push(t2->left);
        }
        return true;
    }
};
/*
 Author:     Annie Kim, anniekim.pku@gmail.com
 Date:       May 8, 2013
 Problem:    Text Justification
 Difficulty: Easy
 Source:     http://leetcode.com/onlinejudge#question_68
 Notes:
 Given an array of words and a length L, format the text such that each line has exactly L 
 characters and is fully (left and right) justified.
 You should pack your words in a greedy approach; that is, pack as many words as you can in each line. 
 Pad extra spaces ' ' when necessary so that each line has exactly L characters.
 Extra spaces between words should be distributed as evenly as possible. If the number of spaces 
 on a line do not divide evenly between words, the empty slots on the left will be assigned more 
 spaces than the slots on the right.
 For the last line of text, it should be left justified and no extra space is inserted between words.

 For example,
 words: ["This", "is", "an", "example", "of", "text", "justification."]
 L: 16.
 Return the formatted lines as:
 [
 "This    is    an",
 "example  of text",
 "justification.  "
 ]
 Note: Each word is guaranteed not to exceed L in length.
 Corner Cases:
 A line other than the last line might contain only one word. What should you do in this case?
 In this case, that line should be left-justified.

 Solution: ...
 */

class Solution {
public:
    vector<string> fullJustify(vector<string> &words, int L) {
        vector<string> res;
        int i = 0, N = words.size();
        while (i < N)
        {
            int length = words[i].size();
            int j = i + 1;
            while (j < N && length + words[j].size() + (j-i) <= L)
                length += words[j++].size();
            // build line
            string s(words[i]);
            bool isLastLine = (j == N);
            bool oneWord = (j == i + 1);
            int average = isLastLine || oneWord ? 1 : (L - length) / (j - i - 1);
            int extra = isLastLine || oneWord ? 0 : (L - length) % (j - i - 1);
            for (int k = i + 1; k < j; ++k) {
                s.append(extra > 0 ? average + 1 : average, ' ');
                s.append(words[k]);
                extra--;
            }
            s.append(L - s.size(), ' ');
            // push line
            res.push_back(s);
            i = j;
        }
        return res;
    }
};/*
 Author:     Annie Kim, anniekim.pku@gmail.com
 Date:       May 25, 2013
 Problem:    Trapping Rain Water
 Difficulty: Easy
 Source:     http://leetcode.com/onlinejudge#question_42
 Notes:
 Given n non-negative integers representing an elevation map where the width of 
 each bar is 1, compute how much water it is able to trap after raining.
 For example, 
 Given [0,1,0,2,1,0,1,3,2,1,2,1], return 6.

 Solution: Find left bound and right bound for each element. O(n).
*/

class Solution {
public:
    int trap(int A[], int n) {
        if (n == 0) return 0;
        int left[n];
        int right[n];

        int lmax = A[0];
        for (int i = 0; i < n; ++i)
        {
            lmax = max(lmax, A[i]);
            left[i] = lmax;
        }

        int rmax = A[n-1];
        for (int i = n - 1; i >= 0; --i)
        {
            rmax = max(rmax, A[i]);
            right[i] = rmax;
        }

        int res = 0;
        for (int i = 0; i < n; ++i)
            res += min(left[i], right[i]) - A[i];

        return res;
    }
};
/*
 Author:     Annie Kim, anniekim.pku@gmail.com
 Date:       May 14, 2013
 Problem:    Triangle
 Difficulty: Easy
 Source:     http://leetcode.com/onlinejudge#question_120
 Notes:
 Given a triangle, find the minimum path sum from top to bottom. Each step you may move to adjacent numbers on the row below.
 For example, given the following triangle
 [
    [2],
   [3,4],
  [6,5,7],
 [4,1,8,3]
 ]
 The minimum path sum from top to bottom is 11 (i.e., 2 + 3 + 5 + 1 = 11).
 Note:
 Bonus point if you are able to do this using only O(n) extra space, where n is the total number 
 of rows in the triangle.

 Solution: Note that there are n elements in the n-th row (n starts from 1).
           1. DFS. (Time Limit Exceeded for large test data).
           2. DP. Do not need additional spaces (happen in-place).
           3. DP. O(n) space (If the input 'triangle' can not be changed).
 */

class Solution {
public:
    int minimumTotal(vector<vector<int>> &triangle) {
        return minimumTotal_2(triangle);
    }

    int minimumTotal_1(vector<vector<int>> &triangle) {
        int res = INT_MAX;
        minimumTotal_1_Re(triangle, 0, res, 0, 0);
        return res;
    }

    void minimumTotal_1_Re(vector<vector<int>> &triangle, int partSum, int &res, int deep, int j)
    {
        if (deep == triangle.size()) {
            res = min(res, partSum);
            return;
        }
        for (int i = j; i < triangle[deep].size() && i <= j + 1; ++i)
            minimumTotal_1_Re(triangle, partSum + triangle[deep][i], res, deep + 1, i);
    }

    int minimumTotal_2(vector<vector<int>> &triangle) {
        for (int i = triangle.size() - 2; i >= 0; --i)
            for (int j = 0; j < i + 1; ++j)
                triangle[i][j] = triangle[i][j] + min(triangle[i+1][j], triangle[i+1][j+1]);
        return triangle[0][0];
    }

    int minimumTotal_3(vector<vector<int>> &triangle) {
        int N = triangle.size();
        int *dp = new int[N];
        for (int i = 0; i < N; ++i)
            dp[i] = triangle[N-1][i];
        for (int i = N - 2; i >= 0; --i)
            for (int j = 0; j < i + 1; ++j)
                dp[j] = triangle[i][j] + min(dp[j], dp[j+1]);
        int res = dp[0];
        delete [] dp;
        return res;
    }
};/*
 Author:     Annie Kim, anniekim.pku@gmail.com
 Date:       Jan 17, 2013
 Update:     Sep 10, 2013
 Problem:    Two Sum
 Difficulty: easy
 Source:     http://leetcode.com/onlinejudge#question_1
 Notes:
 Given an array of integers, find two numbers such that they add up to a specific target number.

 The function twoSum should return indices of the two numbers such that they add up to the target, 
 where index1 must be less than index2. Please note that your returned answers (both index1 and index2) are not zero-based.

 You may assume that each input would have exactly one solution.

 Input: numbers={2, 7, 11, 15}, target=9
 Output: index1=1, index2=2

 Solution: 1. Sort first. O(nlgn)
           2. Hash table. O(n)
 */

bool compare(pair<int, int> a, pair<int, int> b) {
    return a.first < b.first;
}

class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        return twoSum_1(numbers, target);
    }
    
    vector<int> twoSum_1(vector<int> &numbers, int target) {
        vector<pair<int, int>> nums(numbers.size());
        for (int i = 0; i < numbers.size(); ++i)
            nums[i] = make_pair(numbers[i], i+1);
        sort(nums.begin(), nums.end(), compare);
        
        int l = 0, r = nums.size() - 1;
        while (l < r)
        {
            int sum = nums[l].first + nums[r].first;
            if (sum == target) break;
            else if (sum < target) l++;
            else r--;
        }

        vector<int> res;
        res.push_back(min(nums[l].second, nums[r].second));
        res.push_back(max(nums[l].second, nums[r].second));
        return res;
    }
    
    vector<int> twoSum_2(vector<int> &numbers, int target) {
        unordered_map<int, int> map;
        for (int i = 0; i < numbers.size(); ++i)
            map[numbers[i]] = i + 1;
        for (int i = 0; i < numbers.size(); ++i)
        {
            unordered_map<int, int>::iterator it = map.find(target - numbers[i]);
            if (it == map.end()) continue;
            vector<int> res;
            res.push_back(min(i+1, it->second));
            res.push_back(max(i+1, it->second));
            return res;
        }
    }
};
/*
 Author:     Annie Kim, anniekim.pku@gmail.com
 Date:       Jul 10, 2013
 Problem:    Unique Binary Search Trees
 Difficulty: Easy
 Source:     http://leetcode.com/onlinejudge#question_96
 Notes:
 Given n, how many structurally unique BST's (binary search trees) that store values 1...n?
 For example,
 Given n = 3, there are a total of 5 unique BST's.
 1         3     3      2      1
  \       /     /      / \      \
   3     2     1      1   3      2
  /     /       \                 \
 2     1         2                 3

 Solution: dp.
*/

class Solution {
public:
    int numTrees(int n) {
        int dp[n+1];
        memset(dp, 0, sizeof(dp));
        dp[0] = 1;
        for (int i = 1; i <= n; ++i)
            for (int j = 0; j < i; j++)
                dp[i] += dp[j] * dp[i-j-1];
        return dp[n];
    }
};/*
 Author:     Annie Kim, anniekim.pku@gmail.com
 Date:       Jul 11, 2013
 Problem:    Unique Binary Search Trees II
 Difficulty: Medium
 Source:     http://leetcode.com/onlinejudge#question_95
 Notes:
 Given n, generate all structurally unique BST's (binary search trees) that store values 1...n.
 For example,
 Given n = 3, your program should return all 5 unique BST's shown below.
 1         3     3      2      1
  \       /     /      / \      \
   3     2     1      1   3      2
  /     /       \                 \
 2     1         2                 3

 Solution: 1. DFS directly. (from the Internet)
           2. DP + DFS. (my solution)
              a. Generate trees for 'n' from 1 to n. (DP)
              b. When generate trees for n = i, get the left and right subtrees 
                 by copying tree structures of dp[1...i-1]. (copy tree uses DFS)
*/

class Solution {
public:
    vector<TreeNode *> generateTrees(int n) {
        return generateTrees_1(n);
    }

    // solution 1
    vector<TreeNode *> generateTrees_1(int n) {
        return generateTreesRe(1, n);
    }

    vector<TreeNode*> generateTreesRe(int l, int r) {
        vector<TreeNode*> res;
        if (l > r) {
            res.push_back(NULL);
            return res;
        }
        for (int k = l; k <= r; k++) {
            vector<TreeNode*> leftTrees = generateTreesRe(l, k-1);
            vector<TreeNode*> rightTrees = generateTreesRe(k+1, r);
            for (size_t i = 0; i < leftTrees.size(); i++) {
                for (size_t j = 0; j < rightTrees.size(); j++) {
                    TreeNode* root = new TreeNode(k);
                    root->left = leftTrees[i];
                    root->right = rightTrees[j];
                    res.push_back(root);
                }
            }
        }
        return res;
    }

    // solution 2
    vector<TreeNode *> generateTrees_2(int n) {
        vector<TreeNode *> dp[n+1];
        dp[0] = vector<TreeNode *>(1, (TreeNode *)NULL);
        for (int i = 1; i <= n; ++i)
        {
            for (int j = 1; j <= i; ++j)
            {
                for (int m = 0; m < dp[j-1].size(); ++m)
                {
                    for (int k = 0; k < dp[i-j].size(); ++k)
                    {
                        TreeNode *root = new TreeNode(j);
                        CopyTree(dp[j-1][m], root->left, 0);
                        CopyTree(dp[i-j][k], root->right, j);
                        dp[i].push_back(root);
                    }
                }
            }
        }
        return dp[n];
    }

    void CopyTree(TreeNode *original, TreeNode *&newNode, int diff)
    {
        if (!original) return;
        newNode = new TreeNode(original->val + diff);
        CopyTree(original->left, newNode->left, diff);
        CopyTree(original->right, newNode->right, diff);
    }
};
/*
 Author:     Annie Kim, anniekim.pku@gmail.com
 Date:       Apr 8, 2013
 Update:     Apr 9, 2013
 Problem:    Unique Paths
 Difficulty: Easy
 Source:     http://leetcode.com/onlinejudge#question_62
 Notes:
 A robot is located at the top-left corner of a m x n grid.
 The robot can only move either down or right at any point in time. The robot is trying to reach 
 the bottom-right corner of the grid (marked 'Finish' in the diagram below).
 How many possible unique paths are there?

 Solution: 
 1. Use formula C(x,t) = t!/(x!*(t-x)!) (x should be large for calculation).
 2. Dynamic programming. UP(i,j) = UP(i-1,j) + UP(i,j-1).
 */

class Solution {
public:
    int uniquePaths_1(int m, int n) {
        if (m == 1  || n == 1) return 1;
        int t = (m-1)+(n-1);
        int x = (m > n) ? (m-1) : (n-1);
        
        long long res = 1;
        for (int i = t; i > x; i--)
            res *= i;
        for (int i = t-x; i > 1; i--)
            res /= i;
        
        return res;
    }

    int uniquePaths_2(int m, int n) {
        int dp[m][n];
        for (int i = 0; i < m; i++)
            dp[i][0] = 1;
        for (int j = 0; j < n; j++)
            dp[0][j] = 1;
        
        for (int i = 1; i < m; i++)
            for (int j = 1; j < n; j++)
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
        
        return dp[m-1][n-1];
    }
};/*
 Author:     Annie Kim, anniekim.pku@gmail.com
 Date:       Apr 9, 2013
 Problem:    Unique Paths II
 Difficulty: Easy
 Source:     http://leetcode.com/onlinejudge#question_63
 Notes:
 Follow up for "Unique Paths":
 Now consider if some obstacles are added to the grids. How many unique paths would there be?
 An obstacle and empty space is marked as 1 and 0 respectively in the grid.
 For example,
 There is one obstacle in the middle of a 3x3 grid as illustrated below.
 [
  [0,0,0],
  [0,1,0],
  [0,0,0]
 ]
 The total number of unique paths is 2.
 Note: m and n will be at most 100.

 Solution: Dynamic programming.
 */

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        int dp[m][n];
        if (obstacleGrid[0][0] == 1) return 0;
        dp[0][0] = 1;
        for (int i = 1; i < m; i++)
            dp[i][0] = obstacleGrid[i][0] == 1 ? 0 : dp[i-1][0];
        for (int j = 1; j < n; j++)
            dp[0][j] = obstacleGrid[0][j] == 1 ? 0 : dp[0][j-1];
        
        for (int i = 1; i < m; i++)
            for (int j = 1; j < n; j++)
                dp[i][j] = obstacleGrid[i][j] == 1 ? 0: dp[i-1][j] + dp[i][j-1];
        
        return dp[m-1][n-1];
    }
};
/*
 Author:     Annie Kim, anniekim.pku@gmail.com
 Date:       May 25, 2013
 Update:     Sep 30, 2013
 Problem:    Valid Number
 Difficulty: Hard
 Source:     http://leetcode.com/onlinejudge#question_65
 Notes:
 Validate if a given string is numeric.
 Some examples:
 "0" => true
 " 0.1 " => true
 "abc" => false
 "1 a" => false
 "2e10" => true
 Note: It is intended for the problem statement to be ambiguous. You should gather all 
 requirements up front before implementing one.

 Solution: This finite-state machine solution. Learn from fuwutu & snakeDling.
*/

class Solution {
public:
    bool isNumber(const char *s) {
        enum InputType {INVALID, SPACE, SIGN, DIGIT, DOT, EXPONENT};
        int transitionTable[][SPACEEND] = 
        { /* 0   1   2   3   4   5  */
             0,  1,  2,  3,  4,  0, // 0: INVALID
             0,  1,  2,  3,  4,  0, // 1: SPACE
             0,  0,  0,  3,  4,  0, // 2: SIGN
             0,  6,  0,  3,  7,  5, // 3: DIGIT
             0,  0,  0,  7,  0,  0, // 4: DOT
             0,  0,  2,  8,  0,  0, // 5: EXPONENT
             0,  6,  0,  0,  0,  0, // 6: END WITH SPACE
             0,  6,  0,  7,  0,  5, // 7: DOT AND DIGIT
             0,  6,  0,  8,  0,  0, // 8: END WITH SPACE OR DIGIT
        };
        
        InputType last = INVALID;
        while (*s != '\0')
        {
            InputType state = INVALID;
            if (*s == ' ')
                state = SPACE;
            else if (isdigit(*s))
                state = DIGIT;
            else if (*s == '+' || *s == '-')
                state = SIGN;
            else if (*s == 'e')
                state = EXPONENT;
            else if (*s == '.')
                state = DOT;
            last = (InputType) transitionTable[last][state];
            if (last == INVALID) return false;
            s++;
        }
        bool validFinal[] = {0, 0, 0, 1, 0, 0, 1, 1, 1};
        return validFinal[last];
    }
};/*
 Author:     Annie Kim, anniekim.pku@gmail.com
 Date:       Apr 29, 2013
 Update:     Jul 19, 2013
 Problem:    Valid Palindrome
 Difficulty: Easy
 Source:     http://leetcode.com/onlinejudge#question_125
 Notes:
 Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.
 For example,
 "A man, a plan, a canal: Panama" is a palindrome.
 "race a car" is not a palindrome.
 Note:
 Have you consider that the string might be empty? This is a good question to ask during an interview.
 For the purpose of this problem, we define empty string as valid palindrome.

 Solution: traverse from both side.
 */
#include <cctype> // needed for isalnum(), isupper() and tolower().

class Solution {
public:
    bool isPalindrome(string s) {
        for (int i = 0, j = s.size() - 1; i < j; ++i, --j)
        {
            while (i < j && !isalnum(s[i])) i++;
            while (i < j && !isalnum(s[j])) j--;

            if (tolower(s[i]) != tolower(s[j]))
                return false;
        }
        return true;
    }
};
/*
 Author:     Annie Kim, anniekim.pku@gmail.com
 Date:       Apr 29, 2013
 Update:     Jul 14, 2013
 Problem:    Valid Parentheses
 Difficulty: Easy
 Source:     http://leetcode.com/onlinejudge#question_20
 Notes:
 Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
 The brackets must close in the correct order, "()" and "()[]{}" are all valid but "(]" and "([)]" are not.

 Solution: stack.
 */

class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        for (int i = 0; i < s.size(); ++i)
        {
            if (s[i] == '(' || s[i] == '[' || s[i] == '{')
            {
                stk.push(s[i]);
            }
            else
            {
                if (stk.empty() || abs(stk.top() - s[i]) > 2) 
                    return false;
                stk.pop();
            }
        }
        return stk.empty();
    }
};
/*
 Author:     Annie Kim, anniekim.pku@gmail.com
 Date:       May 20, 2013
 Problem:    Valid Sudoku
 Difficulty: Easy
 Source:     http://leetcode.com/onlinejudge#question_36
 Notes:
 Determine if a Sudoku is valid, according to: Sudoku Puzzles - The Rules (http://sudoku.com.au/TheRules.aspx).
 The Sudoku board could be partially filled, where empty cells are filled with the character '.'.

 Solution: 1. Traverse the Sudoku only once.
           2. Bit manipulation. Use only one bit to represent a number. Space: sizeof(int) * (1+9+9).
 */

class Solution {
public:
    bool isValidSudoku(vector<vector<char>> &board) {
        const int N = 9;
        int row, col[N] = {0}, box[N] = {0};
        for (int i = 0; i < N; ++i)
        {
            row = 0;
            for (int j = 0; j < N; ++j)
            {
                if (board[i][j] == '.') continue;
                
                int bit = 1 << (board[i][j] - '1');
                int box_index = i/3*3 + j/3;
                
                if (row & bit || col[j] & bit || box[box_index] & bit)
                    return false;
                
                row |= bit;
                col[j] |= bit;
                box[box_index] |= bit;
            }
        }
        return true;
    }
};
/*
 Author:     Annie Kim, anniekim.pku@gmail.com
 Date:       Apr 10, 2013
 Update:     Aug 17, 2013
 Problem:    Validate Binary Search Tree
 Difficulty: Easy
 Source:     http://leetcode.com/onlinejudge#question_98
 Notes:
 Given a binary tree, determine if it is a valid binary search tree (BST).
 Assume a BST is defined as follows:
 The left subtree of a node contains only nodes with keys less than the node's key.
 The right subtree of a node contains only nodes with keys greater than the node's key.
 Both the left and right subtrees must also be binary search trees.

 Solution: Recursion. 1. Add lower & upper bound. O(n)
                      2. Inorder traversal with one additional parameter (value of predecessor). O(n)
 */

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isValidBST(TreeNode *root) {
        return isValidBST_1(root);
    }

    // solution 1: lower bound + higher bound
    bool isValidBST_1(TreeNode *root) {
        return isValidBSTRe_1(root, INT_MIN, INT_MAX);
    }

    bool isValidBSTRe_1(TreeNode *node, int lower, int upper){
        if (!node) return true;
        if (node->val <= lower || node->val >= upper) return false;

        return isValidBSTRe_1(node->left, lower, node->val) && 
               isValidBSTRe_1(node->right, node->val, upper);
    }

    // solution 2: inorder
    bool isValidBST_2(TreeNode *root) {
        int val = INT_MIN;
        return isValidBSTRe_2(root, val);
    }

    bool isValidBSTRe_2(TreeNode *node, int &val)
    {
        if (!node) return true;
        if (node->left && !isValidBSTRe_2(node->left, val))
            return false;
        if (node->val <= val)
            return false;
        val = node->val;
        if (node->right && !isValidBSTRe_2(node->right, val))
            return false;
        return true;
    }
};
/*
 Author:     Annie Kim, anniekim.pku@gmail.com
 Date:       Aug 20, 2013
 Problem:    Wildcard Matching
 Difficulty: Medium
 Source:     http://leetcode.com/onlinejudge#question_44
 Notes:
 Implement wildcard pattern matching with support for '?' and '*'.
 '?' Matches any single character.
 '*' Matches any sequence of characters (including the empty sequence).
 The matching should cover the entire input string (not partial).
 The function prototype should be:
 bool isMatch(const char *s, const char *p)
 Some examples:
 isMatch("aa","a") ? false
 isMatch("aa","aa") ? true
 isMatch("aaa","aa") ? false
 isMatch("aa", "*") ? true
 isMatch("aa", "a*") ? true
 isMatch("ab", "?*") ? true
 isMatch("aab", "c*a*b") ? false

 Solution: ...
*/

class Solution {
public:
    bool isMatch(const char *s, const char *p) {
        const char *sBackup = NULL, *pBackup = NULL;
        while (*s != '\0') {
            if (*p == '?' || *s == *p) {
                s++;
                p++;
            } else if (*p == '*') {
                while (*p == '*') p++;
                if (*p == '\0') return true;
                sBackup = s;
                pBackup = p;
            } else {
                if (!sBackup) return false;
                s = ++sBackup;
                p = pBackup;
            }
        }
        while (*p == '*') p++;
        return *s == '\0' && *p == '\0';
    }
};/*
 Author:     Annie Kim, anniekim.pku@gmail.com
 Date:       Oct 6, 2013
 Problem:    Word Break
 Difficulty: Easy
 Source:     http://oj.leetcode.com/problems/word-break/
 Notes:
 Given a string s and a dictionary of words dict, determine if s can be segmented into 
 a space-separated sequence of one or more dictionary words.
 For example, given
 s = "leetcode",
 dict = ["leet", "code"].
 Return true because "leetcode" can be segmented as "leet code".

 Solution: dp.
*/

class Solution {
public:
    bool wordBreak(string s, unordered_set<string> &dict) {
        int N = s.size();
        bool canBreak[N+1];
        memset(canBreak, false, sizeof(canBreak));
        canBreak[0] = true;
        for (int i = 1; i <= N; ++i) {
            for (int j = i-1; j >= 0; --j) {
                if (canBreak[j] && dict.find(s.substr(j, i-j)) != dict.end()) {
                    canBreak[i] = true;
                    break;
                }
            }
        }
        return canBreak[N];
    }
};
/*
 Author:     Annie Kim, anniekim.pku@gmail.com
 Date:       Oct 7, 2013
 Problem:    Word Break II
 Difficulty: Easy
 Source:     http://oj.leetcode.com/problems/word-break-ii/
 Notes:
 Given a string s and a dictionary of words dict, add spaces in s to 
 construct a sentence where each word is a valid dictionary word.
 Return all such possible sentences.
 For example, given
 s = "catsanddog",
 dict = ["cat", "cats", "and", "sand", "dog"].
 A solution is ["cats and dog", "cat sand dog"].

 Solution: check before constructing the sentences.
*/

class Solution {
public:
    vector<string> wordBreak(string s, unordered_set<string> &dict) {
        vector<string> res;
        if (!wordBreakPossible(s, dict)) return res;
        wordBreakRe(s, dict, 0, "", res);
        return res;
    }
    
    void wordBreakRe(const string &s, const unordered_set<string> &dict, 
                     int start, string sentence, vector<string> &res) {
        if (start == s.size()) {
            res.push_back(sentence);
            return;
        }
        if (start != 0) sentence.push_back(' ');
        for (int i = start; i < s.size(); ++i) {
            string word = s.substr(start, i-start+1);
            if (dict.find(word) == dict.end())
                continue;
            wordBreakRe(s, dict, i+1, sentence + word, res);
        }
    }
    
    bool wordBreakPossible(const string &s, const unordered_set<string> &dict) {
        int N = s.size();
        bool canBreak[N+1];
        memset(canBreak, false, sizeof(canBreak));
        canBreak[0] = true;
        for (int i = 1; i <= N; ++i) {
            for (int j = i-1; j >= 0; --j) {
                if (canBreak[j] && dict.find(s.substr(j, i-j)) != dict.end()) {
                    canBreak[i] = true;
                    break;
                }
            }
        }
        return canBreak[N];
    }
};
/*
 Author:     Annie Kim, anniekim.pku@gmail.com
 Date:       Jun 8, 2013
 Problem:    Word Ladder
 Difficulty: High
 Source:     http://leetcode.com/onlinejudge#question_127
 Notes:
 Given two words (start and end), and a dictionary, find the length of shortest transformation 
 sequence from start to end, such that:
 Only one letter can be changed at a time
 Each intermediate word must exist in the dictionary
 For example,
 Given:
 start = "hit"
 end = "cog"
 dict = ["hot","dot","dog","lot","log"]
 As one shortest transformation is "hit" -> "hot" -> "dot" -> "dog" -> "cog",
 return its length 5.
 Note:
 Return 0 if there is no such transformation sequence.
 All words have the same length.
 All words contain only lowercase alphabetic characters.

 Solution: BFS.
*/

class Solution {
public:
    int ladderLength(string start, string end, unordered_set<string> &dict) {
        queue<pair<string, int>> q;
        q.push(make_pair(start, 1));
        while (!q.empty())
        {
            pair<string, int> front = q.front();
            q.pop();
            string word = front.first;
            for (size_t i = 0; i < word.size(); i++)
            {
                char before = word[i];
                for (char c = 'a'; c <= 'z'; c++)
                {
                    word[i] = c;
                    if (word == end)
                        return front.second + 1;
                    if (dict.find(word) != dict.end())
                    {
                        q.push(make_pair(word, front.second + 1));
                        dict.erase(word);
                    }
                }
                word[i] = before;
            }
        }
        return 0;
    }
};/*
 Author:     Annie Kim, anniekim.pku@gmail.com
 Date:       Jul 8, 2013
 Problem:    Word Ladder II
 Difficulty: High
 Source:     http://leetcode.com/onlinejudge#question_126
 Notes:
 Given two words (start and end), and a dictionary, find all shortest transformation sequence(s) from start to end, such that:
 Only one letter can be changed at a time
 Each intermediate word must exist in the dictionary
 For example,
 Given:
 start = "hit"
 end = "cog"
 dict = ["hot","dot","dog","lot","log"]
 Return
 [
  ["hit","hot","dot","dog","cog"],
  ["hit","hot","lot","log","cog"]
 ]
 Note:
 All words have the same length.
 All words contain only lowercase alphabetic characters.

 Solution: Idea is from blog: http://blog.csdn.net/niaokedaoren/article/details/8884938
*/

class Solution {
public:
    vector<vector<string>> findLadders(string start, string end, unordered_set<string> &dict) {
        map<string, vector<string>> traces; // If A->C and B->C, then traces[C] contains A and B.
                                            // This is used for recovering the paths.
        vector<unordered_set<string>> level(2);
        int cur = 0;
        int prev = 1;
        level[cur].insert(start);
        dict.insert(end);

        while (true)
        {
            prev = !prev;
            cur = !cur;
            level[cur].clear();

            // remove visited words. IMPORTANT!
            for (unordered_set<string>::iterator it = level[prev].begin(); it != level[prev].end(); ++it)
                dict.erase(*it);

            for (unordered_set<string>::iterator it = level[prev].begin(); it != level[prev].end(); ++it)
            {
                string word = *it;
                for (size_t i = 0; i < word.size(); i++) {
                    char before = word[i];
                    for (char c = 'a'; c <= 'z'; c++) {
                        if (c == before)
                            continue;
                        word[i] = c;
                        if (dict.find(word) != dict.end()) {
                            traces[word].push_back(*it);
                            level[cur].insert(word);
                        }
                    }
                    word[i] = before;
                }
            }

            if (level[cur].empty() || level[cur].count(end) > 0)
                break;
        }

        vector<vector<string>> res;
        vector<string> onePath;
        if (!traces.empty())
            buildResult(traces, res, onePath, end);

        return res;
    }

    void buildResult(map<string, vector<string>> &traces, vector<vector<string>> &res, vector<string> &onePath, string word)
    {
        if (traces.count(word) == 0)
        {
            vector<string> copy(onePath);
            copy.push_back(word);
            reverse(copy.begin(), copy.end());
            res.push_back(copy);
            return;
        }

        const vector<string> &s = traces[word];
        onePath.push_back(word);
        for (vector<string>::const_iterator it = s.begin(); it != s.end(); ++it)
            buildResult(traces, res, onePath, *it);
        onePath.pop_back();
    }
};/*
 Author:     Annie Kim, anniekim.pku@gmail.com
 Date:       May 13, 2013
 Update:     Sep 20, 2013
 Problem:    Word Search
 Difficulty: Easy
 Source:     http://leetcode.com/onlinejudge#question_79
 Notes:
 Given a 2D board and a word, find if the word exists in the grid.
 The word can be constructed from letters of sequentially adjacent cell, where "adjacent" cells are 
 those horizontally or vertically neighboring. The same letter cell may not be used more than once.
 For example,
 Given board =
 [
  ["ABCE"],
  ["SFCS"],
  ["ADEE"]
 ]
 word = "ABCCED", -> returns true,
 word = "SEE", -> returns true,
 word = "ABCB", -> returns false.

 Solution: DFS. (For 'visited', using two-dimensional array will be faster than vector<vector>.[90+ms->50+ms])
 */

class Solution {
public:
    typedef vector<vector<char> > VECTOR2D;
    
    bool exist(VECTOR2D &board, string word) {
        int N = board.size(), M = board[0].size();
        VECTOR2D avail(N, vector<char>(M, 'o'));
        for (int i = 0; i < N; ++i)
            for (int j = 0; j < M; ++j)
                if (existRe(board, word, 0, i, j, avail))
                    return true;
        return false;
    }

    bool existRe(const VECTOR2D &board, const string &word, int deep, int i, int j, VECTOR2D &avail)
    {
        int N = board.size(), M = board[0].size();
        if (deep == word.size()) return true;
        if (i < 0 || i >= N || j < 0 || j >= M) return false;
        if (board[i][j] != word[deep] || avail[i][j] == 'x') return false;
        
        avail[i][j] = 'x';
        if (existRe(board, word, deep + 1, i-1, j, avail)) return true;
        if (existRe(board, word, deep + 1, i+1, j, avail)) return true;
        if (existRe(board, word, deep + 1, i, j-1, avail)) return true;
        if (existRe(board, word, deep + 1, i, j+1, avail)) return true;
        avail[i][j] = 'o';
        
        return false;
    }
};/*
 Author:     Annie Kim, anniekim.pku@gmail.com
 Date:       Apr 7, 2013
 Update:     Sep 26, 2013
 Problem:    ZigZag Conversion
 Difficulty: Easy
 Source:     http://leetcode.com/onlinejudge#question_6
 Notes:
 The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)

 P   A   H   N
 A P L S I I G
 Y   I   R
 And then read line by line: "PAHNAPLSIIGYIR"
 Write the code that will take a string and make this conversion given a number of rows:

 string convert(string text, int nRows);
 convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR".

 Solution: ...
 */

class Solution {
public:
    string convert(string s, int nRows) {
        if (nRows == 1) return s;
        string res;
        int inc = (nRows - 1) * 2, N = s.size();
        for (int r = 0; r < nRows; ++r)
        {
            int j = 0;
            while (true)
            {
                if (r > 0 && r < nRows-1 && j-r >= 0 && j-r < N)
                    res.push_back(s[j-r]);
                if (j+r < N)
                    res.push_back(s[j+r]);
                if (j+r >= N)
                    break;
                j += inc;
            }
        }
        return res;
    }
};
