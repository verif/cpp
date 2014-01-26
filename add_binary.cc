#include <stdio.h>
#include <string>

using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        int M = a.size();
        int N = b.size();
        string rslt;
        int i = M - 1;
        int j = N - 1;
        int carry = 0;
        int ia, ib;
        while (i >= 0 || j >=0 || carry) {
            ia = (i >= 0) ? (a[i] == '1') : 0;
            ib = (j >= 0) ? (b[j] == '1') : 0;
            int sum = ia + ib + carry;
            char c;
            if (sum == 3) {
                carry = 1;
                c = '1';
            }
            else if (sum == 2) {
                carry = 1;
                c = '0';
            }
            else if (sum == 1) {
                carry = 0;
                c = '1';
            }
            else {
                carry = 0;
                c = '0';
            }
            rslt = c + rslt;
            i--;
            j--;
        }
        return rslt;
      
    }
};

int main () {
  Solution S;
  string s1 = S.addBinary("0", "1");
  printf("s1=%s\n", s1.c_str());
  return 0;
}
