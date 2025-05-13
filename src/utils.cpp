#include "utils.h"
#include <iostream>
#include <iomanip>

using namespace std;

void print_help()
{
    cout <<  right << setw(12) << "------------------------------------------------------------------------------\n"
                                       << "Our project provides 4 options with multiple 'mini' options within each of them.\n"
                                       << "Having fun discorvering them ^^!\n"
                                       << "NOTE: You can type any characters below in any form, such as 'BorRow'.\n    It's perfectly fine, because my work is a work of art.\nSo:\n";
            cout << right << setw(15) << "Type 'borrow' to enter borrow option;" << endl;
            cout << right << setw(15) << "Type 'search' to enter search option;" << endl; 
            cout << right << setw(15) << "Type 'sort' to enter sort option;" << endl;
            cout << right << setw(15) << "Type 'print' to enter print option." << endl;
}

