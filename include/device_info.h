// #ifndef DEVICE_INFO_H
// #define DEVICE_INFO_H

// #endif
#pragma once
#include <string>
#include <stddef.h>

struct device_info
{
    std::string name;
    std::string date;
    std::string ID;
    std::string category;
    double cost;
};

void date_standardize(device_info& x);
void name_standardize(device_info& x);
