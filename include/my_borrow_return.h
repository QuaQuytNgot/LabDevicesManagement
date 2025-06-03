// #ifndef MY_BORROW_RETURN_H
// #define MY_BORROW_RETURN_H

// #endif
#pragma once
#include <iomanip>
#include <iostream>
#include <string>

#include "device_info.h"

using namespace std;

struct borrower
{
  string name_borrower, ID, name_device, today, expired_day;
};

ostream& operator<<(ostream& out, const borrower& x);

struct node
{
  borrower data;
  node* next;
  friend istream& operator>>(istream& in, node& x);
  friend ostream& operator<<(ostream& out, const node& x);
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
string addDays(const string& date_str, int days_to_add);
void borrow(node*& borrow_list);
void return_device(node*& borrow_list);
