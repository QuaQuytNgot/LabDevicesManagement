#include <cctype>
#include <iomanip>
#include <iostream>
#include <string>

#include "my_print.h"

#include "device_info.h"

using namespace std;

void print_all_devices(device_info a[], int size)
{
  if (size <= 0)
  {
    cout << "No devices to display!\n";
    return;
  }

  cout << "\n" << string(100, '=') << "\n";
  cout << "                           ALL DEVICES INFORMATION\n";
  cout << string(100, '=') << "\n";

  cout << left;
  cout << setw(15) << "Device Name" << setw(12) << "Date" << setw(10)
       << "ID" << setw(15) << "Category" << setw(12) << "Cost ($)"
       << endl;

  cout << setw(15) << string(14, '-') << setw(12) << string(11, '-')
       << setw(10) << string(9, '-') << setw(15) << string(14, '-')
       << setw(12) << string(11, '-') << endl;

  for (int i = 0; i < size; i++)
  {
    cout << setw(15) << a[i].name << setw(12) << a[i].date
         << setw(10) << a[i].ID << setw(15) << a[i].category
         << setw(12) << fixed << setprecision(2) << a[i].cost
         << endl;
  }

  cout << string(100, '-') << "\n";
  cout << "Total devices: " << size << "\n";
  cout << "Back to print menu!\n\n";
}

void print_single_devices(device_info a[], int size)
{
  if (size <= 0)
  {
    cout << "No devices available!\n";
    return;
  }

  cout << "Enter device name or ID to display: ";
  string search_term;
  cin.ignore();
  getline(cin, search_term);

  string search_lower = search_term;
  for (int i = 0; i < search_lower.size(); i++)
  {
    search_lower[i] = static_cast<char>(
        tolower(static_cast<char>(search_lower[i])));
  }
  bool found = false;
  cout << "\n" << string(100, '=') << "\n";
  cout << "                    SEARCH RESULTS FOR: '" << search_term
       << "'\n";
  cout << string(100, '=') << "\n";

  for (int i = 0; i < size; i++)
  {
    string device_name_lower = a[i].name;
    string device_id_lower   = a[i].ID;

    for (int i = 0; i < device_name_lower.size(); i++)
    {
      device_name_lower[i] = static_cast<char>(
          tolower(static_cast<char>(device_name_lower[i])));
    }
    for (int i = 0; i < device_id_lower.size(); i++)
    {
      device_id_lower[i] = static_cast<char>(
          tolower(static_cast<char>(device_id_lower[i])));
    }

    if (device_name_lower.find(search_lower) != string::npos ||
        device_id_lower == search_lower)
    {
      if (!found)
      {
        cout << left;
        cout << setw(15) << "Device Name" << setw(12) << "Date"
             << setw(10) << "ID" << setw(15) << "Category"
             << setw(12) << "Cost ($)" << endl;
        cout << string(100, '-') << endl;
        found = true;
      }

      cout << setw(15) << a[i].name << setw(12) << a[i].date
           << setw(10) << a[i].ID << setw(15) << a[i].category
           << setw(12) << fixed << setprecision(2) << a[i].cost
           << endl;
    }
  }

  if (!found)
  {
    cout << "No device found matching: '" << search_term << "'\n";
    cout << "Available devices: Hot Plate, Microscope, Centrifuge, "
            "Spectrometer, Burette, Pipette\n";
  }
  else
  {
    cout << string(100, '-') << "\n";
  }

  cout << "Back to print menu!\n\n";
}
