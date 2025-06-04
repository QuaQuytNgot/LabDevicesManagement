// #ifndef MY_SEARCH_H
// #define MY_SEARCH_H

// #endif

#pragma once
#include <string>

#include "device_info.h"
#include "my_borrow_return.h"

int read_csv(const std::string& filename, device_info devices[], int max_size);
void search_device_name(device_info a[], int size);
void search_device_ID(device_info a[], int size);
void search_device_cost(device_info a[], int size);
void search_category(device_info a[], int size);
void search_and_print_through_borrower_list(node* borrow_list, std::string s);
