#include <algorithm>
#include <cctype>
#include <iomanip>
#include <iostream>
#include <string>

#include "my_sort.h"

using namespace std;

string to_lower(const string &str)
{
  string result = str;
  for (char &c : result)
  {
    c = static_cast<char>(tolower(static_cast<unsigned char>(c)));
  }
  return result;
}

void sort_by_name(device_info a[], int size)
{
  for (int i = 0; i < size - 1; ++i)
  {
    for (int j = i + 1; j < size; ++j)
    {
      if (to_lower(a[i].name) > to_lower(a[j].name))
      {
        swap(a[i], a[j]);
      }
    }
  }

  cout << "\n" << string(70, '=') << "\n";
  cout << "\n             LIST AFTER SORTING LIST BY NAME\n";
  cout << "\n" << string(70, '=') << "\n";

  cout << left;
  cout << setw(15) << "Device Name" << setw(15) << "Catgory"
       << setw(10) << "ID" << setw(12) << "Date" << setw(12)
       << "Cost ($)" << endl;

  cout << setw(15) << string(14, '-') << setw(15) << string(14, '-')
       << setw(10) << string(9, '-') << setw(12) << string(11, '-')
       << setw(12) << string(11, '-') << endl;

  for (int i = 0; i < size; ++i)
  {
    cout << setw(15) << a[i].name << setw(15) << a[i].category
         << setw(10) << a[i].ID << setw(12) << a[i].date << setw(12)
         << a[i].cost << endl;
  }
  cout << "Back to menu!!\n";
}

void sort_by_category(device_info a[], int size)
{
  for (int i = 0; i < size - 1; ++i)
  {
    for (int j = i + 1; j < size; ++j)
    {
      if (to_lower(a[i].category) > to_lower(a[j].category))
      {
        swap(a[i], a[j]);
      }
    }
  }

  cout << "\n" << string(70, '=') << "\n";
  cout << "\n             LIST AFTER SORTING LIST BY CATEGORY\n";
  cout << "\n" << string(70, '=') << "\n";

  cout << left;
  cout << setw(15) << "Category" << setw(15) << "Name" << setw(10)
       << "ID" << setw(12) << "Date" << setw(12) << "Cost ($)"
       << endl;

  cout << setw(15) << string(14, '-') << setw(15) << string(14, '-')
       << setw(10) << string(9, '-') << setw(12) << string(11, '-')
       << setw(12) << string(11, '-') << endl;

  for (int i = 0; i < size; ++i)
  {
    cout << setw(15) << a[i].category << setw(15) << a[i].name
         << setw(10) << a[i].ID << setw(12) << a[i].date << setw(12)
         << a[i].cost << endl;
  }
  cout << "Back to menu!!\n";
}
