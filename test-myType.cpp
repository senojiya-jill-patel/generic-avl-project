#include <bits/stdc++.h>
using namespace std;
#include "akhil.h"

/*
for the custom classes to work properly with gan_avl.h below mentioned operators must be accordingly overloaded
1.Default constructor
2.CopyConstructor
3.CopyAssignment operator
4.==
5.>
6.<
7.*
8.<<
*/

class myType
{
public:
    int num;
    myType(int n = 0)
    {
        num = n;
    }
    myType(const myType &rhs)
    {
        // cout << "copy  constructor of mytype\n";
        this->num = rhs.num;
    }

    myType &operator=(myType &rhs)
    {
        // cout << "copy  assignment of mytype\n";
        this->num = rhs.num;
        return *this;
    }

    bool operator==(const myType &rhs)
    {
        return this->num == rhs.num;
    }

    bool operator>(myType &rhs)
    {
        return this->num > rhs.num;
    }

    friend ostream &operator<<(ostream &os, const myType &m)
    {
        os << m.num;
        return os;
    }

    friend bool operator==(const myType &lhs, const myType &rhs)
    {
        return lhs.num == rhs.num;
    }

    friend bool operator>(const myType &lhs, const myType &rhs)
    {
        // cout << "> is called\n";
        return lhs.num > rhs.num;
    }

    friend bool operator<(const myType &lhs, const myType &rhs)
    {
        // cout << "< is called\n";
        return lhs.num < rhs.num;
    }

    int operator*()
    {
        return this->num;
    }
};

// template <>
// struct std::greater<myType>
// {
//     bool operator()(const myType &x, const myType &y) const
//     {
//         return x.num > y.num;
//     }
// };

// template <>
// struct std::less<myType>
// {
//     bool operator()(const myType &x, const myType &y) const
//     {
//         return x.num < y.num;
//     }
// };

int main()
{

    myType num1(1);
    myType tempnum1(num1);
    cout << tempnum1.num << " " << num1.num << endl;
    myType num2(2);
    myType num3(3);
    myType num4(4);
    myType temp(100);

    // Avl of integers
    AVL<myType> bt = AVL<myType>();
    //Inserting 1, 2, 3, 4
    bt.insert(num1);
    bt.insert(num2);
    bt.insert(num3);
    bt.insert(num4);

    // Display tree
    bt.print_tree();

    // Searching which is already present
    if (bt.find(num1) != bt.end())
        cout << "Found " << num1 << endl;
    else
        cout << "Not found " << num1 << endl;

    // Searching which is not present
    if (bt.find(temp) != bt.end())
        cout << "Found " << temp << endl;
    else
        cout << "Not found " << temp << endl;

    cout << "printing inorder traversal with AVL Iterators\n";
    for (AVL<myType>::Iterator it = bt.begin(); it != bt.end(); ++it)
    {
        cout << *it << " ";
    }
    cout << endl;

    cout << "Inorder traversal with range for\n";
    for (myType ele : bt)
    {
        cout << ele << " ";
    }
    cout << endl;

    cout << "Compatable with for each loop of algorithms\n";
    for_each(bt.begin(), bt.end(), [](myType ele) { cout << ele << " "; });
    cout << endl;

    cout << "Compatable with Find funtion of algorithms\n";
    AVL<myType>::Iterator it1 = find(bt.begin(), bt.end(), num2);
    AVL<myType>::Iterator it2 = find(bt.begin(), bt.end(), temp);
    if (it1 != bt.end())
        cout << *it1 << endl;
    else
        cout << "Not found\n";

    cout << "Compatable with min_element of algorithms\n";
    AVL<myType>::Iterator min_it = min_element(bt.begin(), bt.end());
    cout << *min_it << endl;

    cout << "Compatable with max_element of algorithms\n";
    AVL<myType>::Iterator max_it = max_element(bt.begin(), bt.end());
    cout << *max_it << endl;

    cout << "Compatable with count function of algorithms\n";

    cout << "Occurences of " << num1 << ": " << count(bt.begin(), bt.end(), num1) << endl;
    cout << "Occurences of " << temp << ": " << count(bt.begin(), bt.end(), temp) << endl;
    // Deleting nodes ont by one
    cout << "Deleting node one by one\n";
    bt.erase(num1);
    bt.print_tree();
    bt.erase(num2);
    bt.print_tree();
    bt.erase(num3);
    bt.print_tree();
    bt.erase(num4);
    bt.print_tree();

    return 0;
}
