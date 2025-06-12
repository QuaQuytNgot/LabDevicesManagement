#pragma once
#include "device_info.h"
#include <iomanip>
#include <iostream>
#include <string>

void quicksort_by_name(device_info a[], int min, int max);
void sort_by_category(device_info a[], int size);

int  partition(device_info a[], int min, int max);
void display_list_by_name(device_info a[], int size);
