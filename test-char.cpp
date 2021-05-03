#include <bits/stdc++.h>
using namespace std;
#include "akhil.h"
int main()
{
    AVL<char> t = AVL<char>();
    vector<char> arr = {'a', 'b', 'c', 'd', 'e', 'f'};
    cout << "Insert: \n";
    for (auto ele : arr)
    {

        t.insert(ele);
        cout << "tree after inserting " << ele << endl;
        t.print_tree();
        cout << "============================================\n";
    }
    cout << endl;

    //two iterators traverse
    cout << "Incrementing one iterator does not affect the other\n";
    AVL<char>::Iterator it1 = t.begin();
    AVL<char>::Iterator it2 = t.begin();
    it2++;
    cout << "it1 has value " << *it1 << endl;
    cout << "it2 has value " << *it2 << "\n";

    cout << "it2 : ";
    while (it2 != t.end())
    {
        cout << *it2 << " ";
        ++it2;
    }

    cout << endl;
    cout << "it1 : ";
    while (it1 != t.end())
    {
        cout << *it1 << " ";
        ++it1;
    }
    cout << endl;

    // Range for
    cout << "\nInorder traversal with range for\n";
    for (auto ele : t)
    {
        cout << ele << " ";
    }
    cout << endl;
    cout << "Iterating with for_each loop\n";
    for_each(t.begin(), t.end(), [](auto ele) { cout << ele << " "; });
    cout << endl;
    cout << endl;

    cout << "Testing compatibility with std::algorithms \n";

    cout << "\nCounting number of uppercase elements in tree with count_if\n";
    int upper = count_if(t.begin(), t.end(), [](char x) { return x >= 'A' && x <= 'Z'; });
    cout << upper << endl;

    cout << "\nTesting Find funtion of algorithms\n";
    char val1 = 'a';
    AVL<char>::Iterator it = find(t.begin(), t.end(), val1);
    if (it != t.end())
    {
        cout << *it << " found!\n";
    }
    else
    {
        cout << *it << " not found!\n";
    }

    cout << endl;

    //min_element
    cout << "\nTesting with min_element of algorithms\n";
    auto min_it = min_element(t.begin(), t.end());
    if (min_it != t.end())
        cout << "Min ele is :" << *min_it << endl;
    else
        cout << "Tree is empty!\n";

    cout << endl;

    cout << "\nTesting with max_element of algorithms\n";
    auto max_it = max_element(t.begin(), t.end());
    if (max_it != t.end())
        cout << "Max ele is : " << *max_it << endl;
    else
        cout << "Tree is empty!\n";

    cout << "\nTesting lower bound..\n";
    auto val = 'b';
    AVL<char>::Iterator low_it = upper_bound(t.begin(), t.end(), val);
    if (low_it != t.end())
        cout << "lower bound of " << val << " " << *low_it << endl;

    cout << "\nChecking DELETE :\n";
    vector<char> arr_del = {'d', 'b', 'e', 'a', 'c', 'f'};
    for (auto ele : arr_del)
    {
        cout << "Deleting " << ele << endl;
        t.erase(ele);
        t.print_tree();
        cout << "============================================\n";
    }

    return 0;
}
