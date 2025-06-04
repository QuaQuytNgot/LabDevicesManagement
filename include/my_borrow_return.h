// #ifndef MY_BORROW_RETURN_H
// #define MY_BORROW_RETURN_H

// #endif
#pragma once
#include <iomanip>
#include <iostream>
#include <string>

#include "device_info.h"

struct borrower {
    std::string name_borrower;
    std::string name_device;
    std::string ID;
    std::string today;
    std::string expired_day;
};

std::ostream& operator<<(std::ostream& out, const borrower& x);

struct node
{
  borrower data;
  node* next;
  friend std::istream& operator>>(std::istream& in, node& x);
  friend std::ostream& operator<<(std::ostream& out, const node& x);
};

node* makenode(borrower x);
void add_to_node_first(node*& head, borrower x);
void print_borrower(node* head);
int count_node(node* head);
void add_to_node_last(node*& head, borrower x);
void add_to_node_middle(node*& head, borrower x);
void delete_first(node*& head);
void delete_middle(node*& head);
void delete_last(node*& head);
std::string addDays(const std::string& date_str, int days_to_add);
void borrow(node*& borrow_list);
void return_device(node*& borrow_list);
