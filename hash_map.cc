#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <map>
//#include <hash_map.h>
#include <unordered_map>
#include <iostream>

using namespace std;

struct eqstr
{
  bool operator()(const char* s1, const char* s2) const
  {
    return strcmp(s1, s2) == 0;
  }
};

int main()
{
  //hash_map<const char*, int, hash<const char*>, eqstr> months;
  //unordered_map<const char*, int, hash<const char*>, eqstr> months;
  unordered_map<const char*, int> months;
  
  months["january"] = 31;
  months["february"] = 28;
  months["march"] = 31;
  months["april"] = 30;
  months["may"] = 31;
  months["june"] = 30;
  months["july"] = 31;
  months["august"] = 31;
  months["september"] = 30;
  months["october"] = 31;
  months["november"] = 30;
  months["december"] = 31;
  
  cout << "september -> " << months["september"] << endl;
  cout << "april     -> " << months["april"] << endl;
  cout << "june      -> " << months["june"] << endl;
  cout << "november  -> " << months["november"] << endl;
}
