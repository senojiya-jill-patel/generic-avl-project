#include <bits/stdc++.h>
using namespace std;
#include "gen_avl.h"

int main()
{

    // Avl of chars
    AVL<char> bt_char = AVL<char>();
    vector<char> arr2 = {'a', 'b', 'c', 'd', 'e', 'f'};
    for (char ele : arr2)
    {
        // cout << "Inserting " << ele << endl;
        bt_char.insert(ele);
        // bt_char.print_tree();
        // cout << "============================================\n";
    }
    // for (char ele : arr2)
    // {
    //     if (bt_char.search(ele))
    //         cout << "Found " << ele << endl;
    //     else
    //         cout << "Not found " << ele << endl;
    // }

    // if (bt_char.search('z'))
    //     cout << "Found " << 'z' << endl;
    // else
    //     cout << "Not found " << 'z' << endl;

    bt_char.print_tree();
    cout << "printing inorder traversal with AVL Iterators\n";
    for (AVL_Iterator<char> it = bt_char.begin(); it != bt_char.end(); ++it)
    {
        cout << *it << " ";
    }
    cout << endl;

    cout << "Inorder traversal with range for\n";
    for (char ele : bt_char)
    {
        cout << ele << " ";
    }
    cout << endl;

    cout << "Compatable with for each loop of algorithms\n";
    for_each(bt_char.begin(), bt_char.end(), [](char ele) { cout << ele << " "; });
    cout << endl;

    cout << "Compatable with Find funtion of algorithms\n";
    AVL_Iterator<char> it = find(bt_char.begin(), bt_char.end(), 'c');
    cout << *it << endl;

    cout << "Compatable with min_element of algorithms\n";
    AVL_Iterator<char> it1 = min_element(bt_char.begin(), bt_char.end());
    cout << *it1 << endl;

    cout << "Compatable with max_element of algorithms\n";
    AVL_Iterator<char> it2 = max_element(bt_char.begin(), bt_char.end());
    cout << *it2 << endl;

    cout << "Compatable with count function of algorithms\n";
    cout << count(bt_char.begin(), bt_char.end(), 'a') << endl;
    vector<char> arr2_del = {'d', 'b', 'e', 'a', 'c', 'f'};
    for (char ele : arr2_del)
    {
        // cout << "Deleting " << ele << endl;
        bt_char.delete_node(ele);
        // bt_char.print_tree();
        // cout << "============================================\n";
    }

    return 0;
}