// #ifndef MY_BORROW_RETURN_H
// #define MY_BORROW_RETURN_H

// #endif
#pragma once
#include <iomanip>
#include <iostream>
#include <string>

#include "device_info.h"

/**
 * @struct borrower
 * @brief Structure representing borrower information
 * @details Contains name borrower, device, ID, day rented, expired day 
 * of the device.
 */
struct borrower {
    std::string name_borrower;
    std::string name_device;
    std::string ID;
    std::string today;
    std::string expired_day;
};

/**
 * @brief Operator Overloading "<<"  
 * @details Dev can print the struct's information by using "cout <<"
 */
std::ostream& operator<<(std::ostream& out, const borrower& x);

/**
 * @struct node
 * @brief This structure is used for linked list operation
 * @details Contains data type struct borrower, a struct node* next
 * point to next node in the linked list
 */
struct node
{
  borrower data;
  node* next;
  friend std::istream& operator>>(std::istream& in, node& x);
  friend std::ostream& operator<<(std::ostream& out, const node& x);
};

/**
 * @brief Make a node  
 * @details Init a node by dynamic memory allocation for data x 
 * @param x parameter type struct borrower
 * @return node*
 */
node* makenode(borrower x);
/**
 * @brief Add into first
 * @details Add a node to the beggining of the linked list 
 * @param x parameter type struct borrower, default linked list
 */
void add_to_node_first(node*& head, borrower x);
/**
 * @brief Print linked list
 * @details Iterate through linked list and print every single node
 * @param Default linked list
 */
void print_borrower(node* head);
/**
 * @brief Count linked list
 * @details Iterate through linked list and return length of linked list
 * @param Default linked list
 * @return Length of linked list
 */
int count_node(node* head);
/**
 * @brief Add into last
 * @details Add a node to the last of the linked list 
 * @param x parameter type struct borrower, default linked list
 */
void add_to_node_last(node*& head, borrower x);
/**
 * @brief Add into middle
 * @details Add a node to the middle of the linked list 
 * @param x parameter type struct borrower, default linked list
 */
void add_to_node_middle(node*& head, borrower x);
/**
 * @brief Delete the first node
 * @details Delete the first node of the linked list 
 * @param Default linked list
 */
void delete_first(node*& head);
/**
 * @brief Delete the middle node
 * @details Delete the middle node of the linked list 
 * @param Default linked list
 */
void delete_middle(node*& head);
/**
 * @brief Delete the last node
 * @details Delete the last node of the linked list 
 * @param Default linked list
 */
void delete_last(node*& head);
/**
 * @brief Add day
 * @details Add day from a beginning day in format xx/xx/xxxx 
 * @param A string date, number of days to add
 * @return string
 */
std::string addDays(const std::string& date_str, int days_to_add);
/**
 * @brief Borrow devices
 * @details Allow user to enter information to rent a device
 * and add their info to the last of the linked list 
 * @param Default linked list
 */
void borrow(node*& borrow_list);
/**
 * @brief Return devices
 * @details Allow user to enter information to rent a device
 * and delete their info as the node in the linked list 
 * @param Default linked list
 */
void return_device(node*& borrow_list);
