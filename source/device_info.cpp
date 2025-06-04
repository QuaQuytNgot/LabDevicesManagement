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
    word[0] = static_cast<char>(
        toupper(static_cast<unsigned char>(word[0])));
    for (size_t i = 1; i < word.size(); i++)
    {
      word[i] = static_cast<char>(
          tolower(static_cast<unsigned char>(word[i])));
    }
    if (!result.empty())
    {
      result += " ";
    }
    result += word;
  }

  x.name = result;
}
