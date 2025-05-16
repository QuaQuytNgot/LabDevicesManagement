#include <iostream>
#include <iomanip>
#include <cctype>
#include <string>
#include <my_borrow_return.h>
#include <my_print.h>
#include <my_search.h>
#include <utils.h>
#include <device_info.h>

using namespace std;

int main()
{
    const int MAX_SIZE = 100; 
    device_info devices[MAX_SIZE];
    string filename = "devices.csv";
    int device_count = read_csv(filename, devices, MAX_SIZE);
    if (device_count == 0)
    {
        cerr << "NO DATA\n"
             << endl;
        return 1;
    }

    cout << "WELCOME TO OUR DEVICE MANAGEMENT PRJ!!\n"
         << "----------------------------------\n"
         << "If you are new here, please type 'help' for more information\n";

    node *borrow_list;

    // declare linked list borrower - returner heres
    for (;;)
    {
        string user_choice;
        cin >> user_choice;
        int choice = 0;
        for (int i = 0; i < user_choice.size(); i++)
        {
            user_choice[i] = tolower(user_choice[i]);
        }

        if (user_choice == "borrow")
            choice = 1;
        else if (user_choice == "sort")
            choice = 2;
        else if (user_choice == "search")
            choice = 3;
        else if (user_choice == "print")
            choice = 4;
        else if (user_choice == "help")
            choice = 5;
        else
        {
            cout << "Please enter a valid option or 'help' for more information.\n";
            continue;
        }

        string case_1;
        switch (choice)
        {
        // Borrow: define 3 options "borrow", "show", "return"
        case 1:
        {
            int x = 0;
            cout << "Please enter one of these options: 'borrow', 'show', 'return' or 'back'\n";
            cin >> case_1;

            for (int i = 0; i < case_1.size(); i++)
            {
                case_1[i] = tolower(case_1[i]);
            }

            if (case_1 == "borrow")
                x = 1;
            else if (case_1 == "show")
                x = 2;
            else if (case_1 == "return")
                x = 3;
            else if (case_1 == "back")
                x = 4;
            else
            {
                cout << "Invalid option. Returning to main menu.\n"
                     << "You are in menu.\n";
                break;
            }
            switch (x)
            {
            case 1:
                borrow(borrow_list);
                // borrow function
                break;
            case 2:
                print_borrower(borrow_list);
                // show function
                break;
            case 3:
                return_device(borrow_list);
                // return function
                break;
            case 4:
                cout << "Back to menu successfully!!\n";
                break;

            default:
                break;
            }
            break;
        }
        // Sort: define 2 options: sort by name or sort by category
        case 2:
            cout << "--------------------------------------------------------\n"
                 << "We provide 2 options: sort by name or sort by category\n"
                 << "Please enter '1' for sort by name or '2' for sort by category or '3' for back to menu\n";
            int x;
            cin >> x;
            switch (x)
            {
            case 1:
                // sort by name;
                break;
            case 2:
                // sort by category;
                break;
            case 3:
                cout << "Back to menu successfully!\n";
                break;

            default:
                cout << "Invalid option. Returning to main menu.\n"
                     << "You are in menu!\n";
                break;
            }
            break;
        // Search: define 3 options search by "name", "category", "ID"
        case 3:
            cout << "-------------------------------------------\n"
                 << "We provide 3 options search: 'search by name', 'search by ID' and 'search by category' and 1 for 'back to menu'\n"
                 << "Please enter '1', '2', '3' or '4' for each of above options, respectively!\n";
            int y;
            cin >> y;
            switch (y)
            {
            case 1:
                search_device_name(devices, device_count);
                break;
            case 2:
                search_device_ID(devices, device_count);
                break;
            case 3:
                search_category(devices, device_count);
                break;
            case 4:
                cout << "Back to menu successfully!\n";
                break;

            default:
                cout << "Invalid option. Returning to main menu.\n"
                     << "You are in menu!\n";
                break;
            }
            break;
        // Print: print all, print all information about one device
        case 4:
            cout << "-------------------------------------------\n"
                 << "We provide 3 options print: 'print all devices', 'print a single device' and 'back to menu'\n"
                 << "Please enter '1', '2' or '3' for each of above options, respectively!\n";
            int z;
            cin >> z;
            // switch case z
            break;
        // Help:
        case 5:
            print_help();
            // enter print_help later
            break;

        default:
            break;
        }
    }
}
