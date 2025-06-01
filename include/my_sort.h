#ifndef MY_SORT_H
#define MY_SORT_H

#include <iostream>
#include "device_info.h"

// Sort devices by name (ascending, case-insensitive)
void sort_by_name(device_info a[], int size);

// Sort devices by category (ascending, case-insensitive)
void sort_by_category(device_info a[], int size);

#endif

