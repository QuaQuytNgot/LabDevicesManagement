// #ifndef DEVICE_INFO_H
// #define DEVICE_INFO_H

// #endif
#pragma once
#include <string>

using namespace std;

struct device_info
{
  string name, date, ID, category;
  double cost;
};

void date_standardize(device_info& x);
void name_standardize(device_info& x);
