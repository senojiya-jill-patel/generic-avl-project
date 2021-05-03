#include <bits/stdc++.h>
using namespace std;
#include "gen_avl.h"

int main()
{

    // Avl of integers
    AVL<int> bt = AVL<int>();
    vector<int> arr = {80, 51, 95, 29, 66, 89, 99, 6, 40, 71, 94, 98};
    for (int ele : arr)
    {
        // cout << "Inserting " << ele << endl;
        bt.insert(ele);
        // bt.print_tree();
        // cout << "============================================\n";
    }

    AVL_Iterator<int> it = bt.begin();
    AVL_Iterator<int> it2 = it;
    ++it2;

    cout << "it " << *it << endl;
    cout << "it2 " << *it2 << " ";
    while (it2 != bt.end())
    {
        cout << *it2 << " ";
        ++it2;
    }
    cout << endl;
    cout << "it: ";
    while (it != bt.end())
    {
        cout << *it << " ";
        ++it;
    }
    cout << endl;

    // Searching
    // for (int ele : arr)

    // {

    //     if (bt.search(ele))

    //         cout << "Found " << ele << endl;

    //     else

    //         cout << "Not found " << ele << endl;
    // }

    // if (bt.search(1000))
    //     cout << "Found " << 1000 << endl;
    // else
    //     cout << "Not found " << 1000 << endl;

    // bt.print_tree();
    // cout << "printing inorder traversal with AVL Iterators\n";
    // for (AVL_Iterator<int> it = bt.begin(); it != bt.end(); ++it)
    // {
    //     cout << *it << " ";
    // }
    // cout << endl;

    cout << "Inorder traversal with range for\n";
    for (int ele : bt)
    {
        cout << ele << " ";
    }
    cout << endl;

    AVL_Iterator<int> low_it = upper_bound(bt.begin(), bt.end(), 66);
    if (low_it != bt.end())
        cout << "lower bound: " << *low_it << endl;

    // cout << "Compatable with for each loop of algorithms\n";
    // for_each(bt.begin(), bt.end(), [](int ele) { cout << ele << " "; });
    // cout << endl;

    // cout << "Compatable with Find funtion of algorithms\n";
    // AVL_Iterator<int> it = find(bt.begin(), bt.end(), 98);
    // cout << *it << endl;

    // cout << "Compatable with min_element of algorithms\n";
    // AVL_Iterator<int> it1 = min_element(bt.begin(), bt.end());
    // cout << *it1 << endl;

    // cout << "Compatable with max_element of algorithms\n";
    // AVL_Iterator<int> it2 = max_element(bt.begin(), bt.end());
    // cout << *it2 << endl;

    // cout << "Compatable with count function of algorithms\n";
    // cout << count(bt.begin(), bt.end(), 80) << endl;

    // vector<int> arr_del = {80, 51, 95, 29, 66, 6, 40, 71, 94, 98, 99, 89};
    // for (int ele : arr_del)
    // {
    //     // cout << "Deleting " << ele << endl;
    //     bt.delete_node(ele);
    //     // bt.print_tree();
    //     // cout << "============================================\n";
    // }
    return 0;
}