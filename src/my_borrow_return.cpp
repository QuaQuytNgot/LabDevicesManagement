#include "my_borrow_return.h"
#include "my_search.h"
#include "device_info.h"
#include <iostream>
#include <string>
#include <cctype>
#include <iomanip>
#include <ctime>
#include <sstream>

using namespace std;

ostream &operator<<(ostream &out, const borrower &x)
{
    out << left;
    out << setw(20) << x.name_borrower
        << setw(15) << x.name_device
        << setw(10) << x.ID
        << setw(10) << x.today
        << setw(10) << x.expired_day
        << endl;

    return out;
}

istream &operator>>(istream &in, node &x)
{
    getline(in, x.data.name_borrower);
    getline(in, x.data.name_device);
    getline(in, x.data.ID);
    getline(in, x.data.today);
    return in;
}

ostream &operator<<(ostream &out, const node &x)
{
    out << x.data;
    return out;
}

void borrower_standardize(borrower &x)
{
    string &k = x.name_borrower;
    stringstream ss(k);
    string word;
    string result;
    while (ss >> word)
    {
        word[0] = toupper(word[0]);
        for (int i = 1; i < word.size(); i++)
        {
            word[i] = tolower(word[i]);
        }
        if (!result.empty())
        {
            result += " ";
        }
        result += word;
    }

    x.name_borrower = result;
}

node *makenode(borrower x)
{
    node *res = new node;
    res->data = x;
    res->next = NULL;
    return res;
}

void add_to_node_first(node *&head,
                       borrower x)
{
    node *newnode = makenode(x);
    newnode->next = head;
    head = newnode;
}

void print_borrower(node *head)
{
    cout << "---------------------------------------------------------------------------\n"
         << "We provide 3 options: show all borrower list or show only one borrower data or back to 'show' menu.\n"
         << "Please enter '1' or '2' or '3' to choose suitable showing options.\n";
    int x;
    cin >> x;
    cin.ignore();

    switch (x)
    {
    case 1:
    {
        cout << left;
        cout << setw(20) << "Name Borrower"
             << setw(15) << "Name Device"
             << setw(10) << "ID"
             << setw(10) << "Date"
             << setw(13) << "Expired Day"
             << endl;

        cout << setw(20) << "------------------"
             << setw(15) << "-------------"
             << setw(10) << "--------"
             << setw(10) << "------"
             << setw(13) << "------"
             << endl;
        while (head != NULL)
        {
            cout << head->data;
            head = head->next;
        }
        cout << "Return to 'show' option\n";
        break;
    }
    case 2:
    {
        cout << "Enter borrower name or ID to show: \n";
        string s;
        getline(cin, s);
        search_and_print_through_borrower_list(head, s);
        break;
    }
    case 3:
    {
        cout << "Back to 'show' menu successfully!!\n";
        break;
    }
    default:
        cout << "Invalid option. Returning to 'show' menu.\n"
             << "You are in 'show' option!\n";
        break;
    }
}

int count_node(node *head)
{
    int cnt = 0;
    while (head != NULL)
    {
        cnt++;
        head = head->next;
    }
    return cnt;
}

void add_to_node_last(node *&head,
                      borrower x)
{
    node *newnode = makenode(x);
    if (head == NULL)
    {
        head = newnode;
        return;
    }
    node *tmp = head;
    while (tmp->next != NULL)
    {
        tmp = tmp->next;
    }
    tmp->next = newnode;
}

void add_to_node_middle(node *&head,
                        borrower x,
                        int k)
{
    node *newnode = makenode(x);
    if (k < 1 || k > count_node(head))
    {
        return;
    }
    if (k == 1)
    {
        add_to_node_first(head, x);
        return;
    }
    node *tmp = head;
    for (int i = 0; i < k - 1; i++)
    {
        tmp = tmp->next;
    }
    newnode->next = tmp->next;
    tmp->next = newnode;
}

void delete_first(node *&head)
{
    if (head == NULL)
        return;
    node *tmp = head;
    head = head->next;
    delete tmp;
}

void delete_middle(node *&head, int k)
{
    if (k < 1 || k > count_node(head))
        return;
    if (head == NULL)
        return;
    if (k == 1)
    {
        delete_first(head);
        return;
    }
    node *tmp = head;
    for (int i = 1; i <= k - 2; i++)
    {
        tmp = tmp->next;
    }
    node *knode = tmp->next;
    tmp->next = tmp->next->next;
    delete knode;
}

void delete_last(node *&head)
{
    if (head == NULL)
        return;
    node *tmp = head;
    if (tmp->next == NULL)
    {
        head = NULL;
        delete tmp;
        return;
    }
    while (tmp->next->next != NULL)
    {
        tmp = tmp->next;
    }
    node *x = tmp->next;
    tmp->next = NULL;
    delete x;
}

string addDays(const string &date_str, int days_to_add)
{
    struct tm tm_date = {};
    istringstream ss(date_str);

    ss >> get_time(&tm_date, "%d/%m/%Y");

    if (ss.fail())
    {
        cerr << "Invalid date format!" << endl;
        return "";
    }

    time_t time_date = mktime(&tm_date);

    time_date += days_to_add * 24 * 60 * 60;

    struct tm *new_tm = localtime(&time_date);

    ostringstream result;
    result << put_time(new_tm, "%d/%m/%Y");
    return result.str();
}

void borrow(node *&borrow_list)
{
    cout << "--------------------------------------------------------\n"
         << "You can select a suitable period to borrow lab devices.\n"
         << "We provide 3 periods: 3 days, 7 days or 30 days or back to 'borrow' menu!!\n"
         << "Please enter '3', '7', '30' or '1' to choose borrowing period.\n";

    borrower b;
    string cf;
    int x;
    cin >> x;
    cin.ignore();

    switch (x)
    {
    case 3:
    {
        while (true)
        {
            cout << "Please enter your name:\n";
            getline(cin, b.name_borrower);
            cout << "Please enter device you want to borrow and its ID:\n";
            getline(cin, b.name_device);
            getline(cin, b.ID);
            cout << "Please enter today following format 'xx/xx/xxxx':\n";
            getline(cin, b.today);
            b.expired_day = addDays(b.today, 3);
            cout << "--------------------------------------\n"
                 << "CONFIRM YOUR INFORMATION:\n"
                 << "Your name: " << b.name_borrower << endl
                 << "Device you want to borrow: " << b.name_device << endl
                 << "Device ID: " << b.ID << endl
                 << "Today: " << b.today << endl
                 << "Expired day: " << b.expired_day << endl;
            cout << "------------------------------------------------------\n"
                 << "Now, enter 'yes' to confirm or 'no' to enter again\n"
                 << "NOTE: you can type 'y', 'n', it will still work bc this is a work of art ^^!!\n";
            getline(cin, cf);
            if (cf == "NO" || cf == "no" || cf == "n" || cf == "No")
            {
                cout << "Please enter your information again ^^: \n";
            }
            else
            {
                add_to_node_last(borrow_list, b);
                cout << "Borrow successfully!! Return to borrow menu\n";
                break;
            }
        }
        break;
    }
    case 7:
    {
        while (true)
        {
            cout << "Please enter your name:\n";
            getline(cin, b.name_borrower);
            cout << "Please enter device you want to borrow and its ID:\n";
            getline(cin, b.name_device);
            getline(cin, b.ID);
            cout << "Please enter today following format 'xx/xx/xxxx':\n";
            getline(cin, b.today);
            b.expired_day = addDays(b.today, 7);
            cout << "--------------------------------------\n"
                 << "CONFIRM YOUR INFORMATION:\n"
                 << "Your name: " << b.name_borrower << endl
                 << "Device you want to borrow: " << b.name_device << endl
                 << "Device ID: " << b.ID << endl
                 << "Today: " << b.today << endl
                 << "Expired day: " << b.expired_day << endl;
            cout << "------------------------------------------------------\n"
                 << "Now, enter 'yes' to confirm or 'no' to enter again\n"
                 << "NOTE: you can type 'y', 'n', it will still work bc this is a work of art ^^!!\n";
            getline(cin, cf);
            if (cf == "NO" || cf == "no" || cf == "n" || cf == "No")
            {
                cout << "Please enter your information again ^^: \n";
            }
            else
            {
                add_to_node_last(borrow_list, b);
                cout << "Borrow successfully!! Return to 'borrow' menu\n";
                break;
            }
        }
        break;
    }
    case 30:
    {
        cout << "You can refuse to enter in by enter 'refuse' ^^!\n";
        while (true)
        {
            cout << "Please enter your name:\n";
            getline(cin, b.name_borrower);
            cout << "Please enter device you want to borrow and its ID:\n";
            getline(cin, b.name_device);
            getline(cin, b.ID);
            cout << "Please enter today following format 'xx/xx/xxxx':\n";
            getline(cin, b.today);
            b.expired_day = addDays(b.today, 30);
            cout << "--------------------------------------\n"
                 << "CONFIRM YOUR INFORMATION:\n"
                 << "Your name: " << b.name_borrower << endl
                 << "Device you want to borrow: " << b.name_device << endl
                 << "Device ID: " << b.ID << endl
                 << "Today: " << b.today << endl
                 << "Expired day: " << b.expired_day << endl;
            cout << "------------------------------------------------------\n"
                 << "Now, enter 'yes' to confirm or 'no' to enter again\n"
                 << "NOTE: you can type 'y', 'n', it will still work bc this is a work of art ^^!!\n";
            getline(cin, cf);
            if (cf == "NO" || cf == "no" || cf == "n" || cf == "No")
            {
                cout << "Please enter your information again ^^: \n";
            }
            else if (cf == "refuse")
            {
                cout << "Back to 'borrow' menu!!\n";
                break;
            }
            else
            {
                add_to_node_last(borrow_list, b);
                cout << "Borrow successfully!! Return to 'borrow' menu\n";
                break;
            }
        }
        break;
    }
    case 1:
        cout << "Back to menu successfully!!\n";
        break;

    default:
        cout << "Invalid option. Returning to 'borrow' menu.\n"
             << "You are in 'borrow' option!\n";
        break;
    }
}

void return_device(node *&borrow_list)
{
    while (true)
    {
        cout << "----------------------------------\n"
             << "Enter your name (name you registered to borrow): \n";
        string s;
        getline(cin, s);
        int cnt = 0;
        node *tmp = borrow_list;
        while (tmp != NULL)
        {
            if (s == tmp->data.name_borrower)
            {
                break;
            }
            tmp = tmp->next;
            cnt++;
        }
        if (tmp == NULL)
            return;
        delete_middle(tmp, cnt + 1);
    }
    cout << "Return successfullly ^^!!\n";
}
//fix return function!!