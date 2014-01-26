#include <stdio.h>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<string> > rslt;
    vector<vector<string> > partition(string s) {
        rslt.clear();
        vector<string> part;
        partitionRe(s, 0, part);
        return rslt;
    }
    void partitionRe(string & s, int start, vector<string> & part) {
        if (start == s.size()) {
            rslt.push_back(part);
            return;
        }
        string palindrom;
        for (int i = start; i < s.size(); i++) {
            palindrom.push_back(s[i]);
            if (!isPalindrom(palindrom))
                continue;
            part.push_back(palindrom);
            partitionRe(s, i+1, part);
            part.pop_back();
        }
        
    }
    bool isPalindrom(string & s) {
        int N = s.size();
        int i = 0;
        int j = N - 1;
        while (i < j) {
            if (s[i] != s[j]) {
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
};

int main () {
  Solution sol;
  vector<vector<string> > rslt;
  rslt = sol.partition("aab");
  for (int i = 0; i < rslt.size(); i++) {
    for (int j = 0; j < rslt[i].size(); j++)
      printf("%s ", rslt[i][j].c_str());
    printf("\n");
  }
  return 0;
}
