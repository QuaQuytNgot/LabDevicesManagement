#include <cctype>
#include <sstream>
#include <string>

#include "device_info.h"

using namespace std;

void date_standardize(device_info &x)
{
  string &k = x.date;
  if (k[1] == '/')
  {
    k = '0' + k;
  }
  if (k[4] == '/')
  {
    k.insert(3, "0");
  }
}

void name_standardize(device_info &x)
{
  string      &k = x.name;
  stringstream ss(k);
  string       word;
  string       result;
  while (ss >> word)
  {
    word[0] = toupper(word[0]);
    for (int i = 1; i < word.size(); i++)
    {
      word[i] = tolower(word[i]);
    }
    if (!result.empty())
    {
      result += " ";
    }
    result += word;
  }

  x.name = result;
}
