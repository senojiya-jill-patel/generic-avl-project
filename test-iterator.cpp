#include <bits/stdc++.h>
using namespace std;
#include "akhil.h"
int main()
{
    AVL<int> t = AVL<int>();
    t.insert(5);
    auto it = t.begin();
    auto it1(it);
    auto it2 = it1; 

    cout << *it1 << endl;

    cout << *it2 << endl;

    return 0;
}