#include <stdio.h>
#include <strings.h>
#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

string encode(vector<string> inp) {
  string enc;
  char buf[32];
  vector<string>::iterator iter;
  for (iter = inp.begin(); iter != inp.end(); iter++) {
    sprintf(buf, "%8d", (*iter).length());
    enc += buf;
    enc += *iter;
  }
  return enc;
}

vector<string> decode(string enc) {
  vector<string> decoded;
  char buf[32];
  int size;
  int read_length_state = 1;
  int i = 0;
  int len;
  while (i < enc.length()) {
    if (read_length_state) {
      string len_str = enc.substr(i, 8);
      len = atoi(len_str.c_str());
      read_length_state = 0;
      i += 8;
    }
    else {
      decoded.push_back(enc.substr(i, len));
      i += len;
      read_length_state = 1;
    }
  }
  return decoded;
}

int main() {
  vector<string> inp;
  inp.push_back("1st string");
  inp.push_back("2nd string");
  string try1 = encode(inp);
  cout << try1 << endl;

  vector<string> decoded = decode(try1);
  vector<string>::iterator iter;
  for (iter = decoded.begin(); iter < decoded.end(); iter++) {
    cout << *iter << endl;
  };
}
