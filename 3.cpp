#include <bits/stdc++.h>
using namespace std;
#include "gen_avl.h"

int main()
{

    // Avl of string
    AVL<string> bt_string = AVL<string>();
    vector<string> arr3 = {"abc", "bcd", "cde", "def", "efg"};
    for (string ele : arr3)
    {
        // cout << "Inserting " << ele << endl;
        bt_string.insert(ele);
        // bt_string.print_tree();
        // cout << "============================================\n";
    }

    // for (string ele : arr3)
    // {
    //     if (bt_string.search(ele))
    //         cout << "Found " << ele << endl;
    //     else
    //         cout << "Not found " << ele << endl;
    // }

    // if (bt_string.search("fgc"))
    //     cout << "Found fgh" << endl;
    // else
    //     cout << "Not found fgh" << endl;

    bt_string.print_tree();
    cout << "printing inorder traversal with AVL Iterators\n";
    for (AVL_Iterator<string> it = bt_string.begin(); it != bt_string.end(); ++it)
    {
        cout << *it << " ";
    }
    cout << endl;

    cout << "Inorder traversal with range for\n";
    for (string ele : bt_string)
    {
        cout << ele << " ";
    }
    cout << endl;

    cout << "Compatable with for each loop of algorithms\n";
    for_each(bt_string.begin(), bt_string.end(), [](string ele) { cout << ele << " "; });
    cout << endl;

    cout << "Compatable with Find funtion of algorithms\n";
    AVL_Iterator<string> it = find(bt_string.begin(), bt_string.end(), "def");
    cout << *it << endl;

    cout << "Compatable with min_element of algorithms\n";
    AVL_Iterator<string> it1 = min_element(bt_string.begin(), bt_string.end());
    cout << *it1 << endl;

    cout << "Compatable with max_element of algorithms\n";
    AVL_Iterator<string> it2 = max_element(bt_string.begin(), bt_string.end());
    cout << *it2 << endl;

    cout << "Compatable with count function of algorithms\n";
    cout << count(bt_string.begin(), bt_string.end(), "cde") << endl;

    vector<string> arr3_del = {"bcd", "abc", "def", "cde", "efg"};
    for (string ele : arr3_del)
    {
        // cout << "Deleting " << ele << endl;
        bt_string.delete_node(ele);
        // bt_string.print_tree();
        // cout << "============================================\n";
    }

    return 0;
}