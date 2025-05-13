// #ifndef MY_SEARCH_H
// #define MY_SEARCH_H

// #endif

#pragma once
#include <string>
#include "device_info.h"
#include "my_borrow_return.h"

using namespace std;

void search_device_name(device_info a[]);
void search_device_ID(device_info a[]);
void search_device_cost(device_info a[]);
void search_category(device_info a[]);
void search_and_print_through_borrower_list(node *borrow_list, string s);

