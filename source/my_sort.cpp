#include "my_sort.h"
#include <algorithm>
#include <cctype>
#include <iomanip>
#include <iostream>
#include <string>

using namespace std;

string to_lower(const string &str)
{
  string result = str;
  for (char &c : result)
    c = tolower(c);
  return result;
}

void swap(device_info &a, device_info &b)
{
  device_info tmp = a;
  a               = b;
  b               = tmp;
}

int partition(device_info a[], int min, int max)
{
  string pivot = to_lower(a[max].name);
  int    i     = min - 1;

  for (int j = min; j < max; j++)
  {
    if (to_lower(a[j].name) <= pivot)
    {
      i++;
      swap(a[i], a[j]);
    }
  }

  swap(a[i + 1], a[max]);
  return i + 1;
}

void quicksort_by_name(device_info a[], int min, int max)
{
  if (min < max)
  {
    int pivot = partition(a, min, max);
    quicksort_by_name(a, min, pivot - 1);
    quicksort_by_name(a, pivot + 1, max);
  }
}

void display_list_by_name(device_info a[], int size)
{

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
}
