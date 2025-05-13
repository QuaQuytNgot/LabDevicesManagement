#include "my_search.h"
#include <string>
#include <iomanip>
#include <cctype>
#include <sstream>

using namespace std;

void search_and_print_through_borrower_list(node *borrow_list, string s)
{
    bool check = false;
    cout << left;
    cout << setw(20) << "Name Borrower"
         << setw(15) << "Name Device"
         << setw(10) << "ID"
         << setw(10) << "Date"
         << endl;

    cout << setw(20) << "------------------"
         << setw(15) << "-------------"
         << setw(10) << "--------"
         << setw(10) << "------"
         << endl;
    while (borrow_list != NULL)
    {
        if (borrow_list->data.name_borrower == s || borrow_list->data.ID == s)
        {
            cout << borrow_list->data << endl;
            check = true;
        }
        borrow_list = borrow_list->next;
    }
    if (check == false)
    {
        cout << "Your search return nothing!!\n";
    }
}

void search_device_name(device_info a[])
{   
    int n = sizeof(a) / sizeof(device_info);
    for (int i = 0; i < n; i++)
    {
        if(device_info x);
    }
}