#include <bits/stdc++.h>
using namespace std;
#include "generic_avl.h"
int main()
{
    AVL<string> t = AVL<string>();
    vector<string> arr = {"abc", "bcd", "cde", "def", "efg"};
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
    AVL<string>::Iterator it1 = t.begin();
    AVL<string>::Iterator it2 = t.begin();
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

    cout << "\nCounting number of strings starting with 'a'  in tree with count_if\n";
    int upper = count_if(t.begin(), t.end(), [](string x) { return x.size() == 0 ? false : x[0] == 'a'; });
    cout << upper << endl;

    cout << "\nTesting Find funtion of algorithms\n";
    auto val1 = "bcd";
    AVL<string>::Iterator it = find(t.begin(), t.end(), val1);
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

    cout << "\n Testing with max_element of algorithms\n";
    auto max_it = max_element(t.begin(), t.end());
    if (max_it != t.end())
        cout << "Max ele is : " << *max_it << endl;
    else
        cout << "Tree is empty!\n";

    cout << "\nChecking DELETE :\n";
    vector<string> arr_del = {"abc", "bcd", "cde", "def", "efg"};
    for (auto ele : arr_del)
    {
        cout << "Deleting " << ele << endl;
        t.erase(ele);
        t.print_tree();
        cout << "============================================\n";
    }

    return 0;
}
