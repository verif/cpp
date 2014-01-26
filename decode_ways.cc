#include <stdio.h>
#include <assert.h>
#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    int count;
    int numDecodings(string s) {
    	count = 0;
        checkRe(s, 0);
        return count;
    }
    
    void checkRe(string & s, int idx ) {
        if (s.size() == 0)
            return;
        if (idx == s.size() - 1 ||
            idx == s.size() ) {
            count++;
            return;
        }
        if (s[idx] == '1') {
            if (s[idx+1] != '0')
                checkRe(s, idx+1);
            checkRe(s, idx+2);
        }
        else if (s[idx] == '2') {
            if (s[idx+1] != '0')
                checkRe(s, idx+1);
            if (s[idx+1] <= '6')
                checkRe(s, idx+2);
        }
        else {
            if (s[idx] == '0') {
               assert(0);
            }
            checkRe(s, idx+1);
        }
    }
};

int main () {
	Solution sol;

    string s = "4085393587263438197362839792651187379538211951318577884164713291143976212416731331985661435443671959";
    cout << "string: " << s << ": " << sol.numDecodings(s) << endl;
	return 0;
}
