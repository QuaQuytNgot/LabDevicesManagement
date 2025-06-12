#include <cctype>
#include <cmath>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>

#include "my_search.h"

const double EPS = 1e-6;
using namespace std;

int read_csv(const string &filename,
             device_info   devices[],
             int           max_size)
{
  ifstream file(filename);
  if (!file.is_open())
  {
    cerr << "Can not open file: " << filename << endl;
    return 0;
  }

  string line;
  getline(file, line);

  int count = 0;
  while (getline(file, line) && count < max_size)
  {
    stringstream ss(line);
    string       cost_str;
    getline(ss, devices[count].name, ',');
    getline(ss, devices[count].date, ',');
    getline(ss, devices[count].ID, ',');
    getline(ss, devices[count].category, ',');
    getline(ss, cost_str, ',');

    devices[count].cost = stod(cost_str);
    count++;
  }

  file.close();
  return count;
}

void search_and_print_through_borrower_list(node  *borrow_list,
                                            string s)
{
  bool check = false;
  cout << left;
  cout << setw(20) << "Name Borrower" << setw(15) << "Name Device"
       << setw(10) << "ID" << setw(10) << "Date" << setw(10)
       << "Return Date" << endl;

  cout << setw(20) << "------------------" << setw(15)
       << "-------------" << setw(10) << "--------" << setw(10)
       << "------" << setw(10) << "------" << endl;
  while (borrow_list != NULL)
  {
    if (borrow_list->data.name_borrower == s ||
        borrow_list->data.ID == s)
    {
      cout << borrow_list->data << endl;
      check = true;
    }
    borrow_list = borrow_list->next;
  }
  cout << setw(10) << "------"
       << "Back to menu !!\nType help for more info!\n";
  if (check == false)
  {
    cout << "Your search return nothing!!\n";
  }
}

void search_device_name(device_info a[], int size)
{
  string name;
  cout << "Enter device's name: ";
  // cin.ignore();
  getline(cin, name);

  bool found = false;
  for (int i = 0; i < size; i++)
  {
    if (a[i].name == name)
    {
      cout << "Name: " << a[i].name << ", Date: " << a[i].date
           << ", ID: " << a[i].ID << ", Category: " << a[i].category
           << ", Cost: " << a[i].cost << endl;
      found = true;
    }
  }
  if (!found)
  {
    cout << "No result matches value: " << name << endl;
  }
}

void search_device_ID(device_info a[], int size)
{
  string ID;
  cout << "Enter device's ID: ";
  // cin.ignore();
  getline(cin, ID);

  bool found = false;
  for (int i = 0; i < size; i++)
  {
    if (a[i].ID == ID)
    {
      cout << "Name: " << a[i].name << ", Date: " << a[i].date
           << ", ID: " << a[i].ID << ", Category: " << a[i].category
           << ", Cost: " << a[i].cost << endl;
      found = true;
    }
  }
  if (!found)
  {
    cout << "No result matches value: " << ID << endl;
  }
}

void search_device_cost(device_info a[], int size)
{
  double cost;
  cout << "Enter device's cost: ";
  cin >> cost;
  cout << endl;

  bool found = false;
  for (int i = 0; i < size; i++)
  {
    if (abs(a[i].cost - cost) < EPS)
    {
      cout << "Name: " << a[i].name << ", Date: " << a[i].date
           << ", ID: " << a[i].ID << ", Category: " << a[i].category
           << ", Cost: " << a[i].cost << endl;
      found = true;
    }
  }
  if (!found)
  {
    cout << "No result matches value: " << cost << endl;
  }
}

void search_category(device_info a[], int size)
{
  string category;
  cout << "Enter devices category: ";
  // cin.ignore();
  getline(cin, category);

  bool found = false;
  for (int i = 0; i < size; i++)
  {
    if (a[i].category == category)
    {
      cout << "Name: " << a[i].name << ", Date: " << a[i].date
           << ", ID: " << a[i].ID << ", Category: " << a[i].category
           << ", Cost: " << a[i].cost << endl;
      found = true;
    }
  }
  if (!found)
  {
    cout << "No result matches value: " << category << endl;
  }
}
