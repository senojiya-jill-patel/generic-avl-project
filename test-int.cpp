#include <bits/stdc++.h>
using namespace std;
#include "generic_avl.h"
int main()
{
    AVL<int> bt = AVL<int>();
    AVL<int> t = bt;

    vector<int> arr = {80, 51, 95, 29, 66, 89, 99, 6, 40, 71, 94, 98};
    cout << "Insert: \n";
    for (int ele : arr)
    {

        t.insert(ele);
        cout << "tree after inserting " << ele << endl;
        t.print_tree();
        cout << "============================================\n";
    }
    cout << endl;

    //two iterators traverse
    cout << "Incrementing one iterator does not affect the other\n";
    AVL<int>::Iterator it1 = t.begin();
    AVL<int>::Iterator it2 = t.begin();
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
    for (int ele : t)
    {
        cout << ele << " ";
    }
    cout << endl;
    cout << "Iterating with for_each loop\n";
    for_each(t.begin(), t.end(), [](int ele) { cout << ele << " "; });
    cout << endl;
    cout << endl;

    cout << "Testing compatibility with std::algorithms \n";

    cout << "\nCounting number of odd elements in tree with count_if\n";
    int odd = count_if(t.begin(), t.end(), [](int x) { return x & 1; });
    cout << odd << endl;

    cout << "Checking if all elements of the tree are EVEN using all_of\n";
    if (all_of(t.begin(), t.end(), [](int i) { return i % 2 == 0; }))
        cout << "All the elements are even.\n";
    else
    {
        cout << "All elements are not even\n";
    }
    cout << endl;

    cout << "\nTesting Find funtion of algorithms\n";
    int val1 = 98;
    AVL<int>::Iterator it = find(t.begin(), t.end(), val1);
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

    cout << "\nCompatable with max_element of algorithms\n";
    auto max_it = max_element(t.begin(), t.end());
    if (max_it != t.end())
        cout << "Max ele is : " << *max_it << endl;
    else
        cout << "Tree is empty!\n";

    cout << "\nTesting lower bound..\n";
    int val = 6;
    AVL<int>::Iterator low_it = upper_bound(t.begin(), t.end(), val);
    if (low_it != t.end())
        cout << "lower bound of " << val << " " << *low_it << endl;

    cout << "\nChecking DELETE :\n";
    vector<int> arr_del = {80, 51, 95, 29, 66, 6, 40, 71, 94, 98, 99, 89};
    for (int ele : arr_del)
    {
        cout << "Deleting " << ele << endl;
        t.erase(ele);
        t.print_tree();
        cout << "============================================\n";
    }

    return 0;
}
