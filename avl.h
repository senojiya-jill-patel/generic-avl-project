#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data, height, balance_factor;
    Node *left, *right;
    Node(int x)
    {
        data = x;
        height = 1;
        balance_factor = 0;
        left = right = NULL;
    }

    int operator*()
    {
        return this->data;
    }
};

class AVL_Iterator
{
private:
    Node *next();
    stack<pair<Node *, int>> stk;
    Node *ptr = NULL;

public:
    AVL_Iterator(Node *n);

    AVL_Iterator &operator++()
    {
        ptr = next();
        return *this;
    }

    int operator*()
    {
        return ptr->data;
    }

    Node *operator->()
    {
        return ptr;
    }
    bool operator==(AVL_Iterator &other)
    {
        return this->ptr == other.ptr;
    }

    bool operator!=(AVL_Iterator other)
    {
        return this->ptr != other.ptr;
    }
};

class AVL
{
private:
    Node *root;
    stack<pair<Node *, int>> stk;
    void update_height_and_balance_factor(Node *n);
    Node *left_rotation(Node *n);
    Node *right_rotation(Node *n);
    Node *perform_rotation(Node *n);
    Node *insert_into_avl(Node *n, int data);
    int get_min(Node *n);
    Node *delete_from_avl(Node *root, int data);
    void print_tree(const std::string &prefix, Node *node, bool isLeft);
    bool search_in_avl(Node *n, int data);

public:
    AVL() : root(NULL) {}
    void insert(int data);
    void print_tree();
    void delete_node(int data);
    bool search(int data);
    void inorder();
    AVL_Iterator get_it();
    AVL_Iterator begin();
    AVL_Iterator end();
};

void AVL::update_height_and_balance_factor(Node *n)
{
    if (n == NULL)
        return;
    int left_height = n->left == NULL ? 0 : n->left->height;
    int right_height = n->right == NULL ? 0 : n->right->height;

    n->height = max(left_height, right_height) + 1;
    n->balance_factor = left_height - right_height;
}

Node *AVL::left_rotation(Node *n)
{
    Node *a = n;
    Node *b = a->right;
    Node *b_l = b->left;

    b->left = a;
    a->right = b_l;

    update_height_and_balance_factor(a);
    update_height_and_balance_factor(b);
    return b;
}

Node *AVL::right_rotation(Node *n)
{
    Node *a = n;
    Node *b = a->left;
    Node *b_r = b->right;

    b->right = a;
    a->left = b_r;

    update_height_and_balance_factor(a);
    update_height_and_balance_factor(b);
    return b;
}

Node *AVL::perform_rotation(Node *n)
{
    //Update height and balance factor
    update_height_and_balance_factor(n);
    int balance_factor = n->balance_factor;

    //Now perform ratations based on balance factor.
    if (balance_factor >= 2)
    { //L
        int left_balance_factor = n->left->balance_factor;
        if (left_balance_factor >= 1)
        {
            //perform LL rotation
            return perform_rotation(right_rotation(n));
        }
        else
        {
            //Perform LR rotation
            n->left = perform_rotation(left_rotation(n->left));
            return perform_rotation(right_rotation(n));
        }
    }

    if (balance_factor <= -2)
    { //R
        int right_balance_factor = n->right->balance_factor;
        if (right_balance_factor <= -1)
        {
            //perform RR rotation
            return perform_rotation(left_rotation(n));
        }
        else
        {
            //Perform RL rotation
            n->right = perform_rotation(right_rotation(n->right));
            return perform_rotation(left_rotation(n));
        }
    }

    return n;
}

void AVL::print_tree(const std::string &prefix, Node *node, bool isLeft)
{
    if (node != nullptr)
    {
        std::cout << prefix;

        std::cout << (isLeft ? "|--" : "\\--");

        // print the value of the node
        std::cout << to_string(node->data) << "(" << node->balance_factor << ")" << std::endl;

        // enter the next tree level - left and right branch
        print_tree(prefix + (isLeft ? "|   " : "    "), node->left, true);
        print_tree(prefix + (isLeft ? "|   " : "    "), node->right, false);
    }
}

void AVL::print_tree()
{
    print_tree("", root, false);
}

void AVL::insert(int data)
{
    root = insert_into_avl(root, data);
}

Node *AVL::insert_into_avl(Node *n, int data)
{
    if (n == NULL)
        return new Node(data);
    if (n->data > data)
    {
        n->left = insert_into_avl(n->left, data);
    }
    else if (n->data < data)
    {
        n->right = insert_into_avl(n->right, data);
    }

    return perform_rotation(n);
}

void AVL::delete_node(int data)
{
    root = delete_from_avl(root, data);
}

int AVL::get_min(Node *n)
{
    while (n->left != NULL)
        n = n->left;
    return n->data;
}

Node *AVL::delete_from_avl(Node *root, int data)
{
    // return root;
    if (root == NULL)
        return root;
    if (root->data > data)
    {
        root->left = delete_from_avl(root->left, data);
    }
    else if (root->data < data)
    {
        root->right = delete_from_avl(root->right, data);
    }
    else
    {
        //root contains data => root needs to be deleted
        if (root->left == NULL || root->right == NULL)
        {
            return root->left == NULL ? root->right : root->left;
        }
        else
        {
            int min_on_right = get_min(root->right);
            root->data = min_on_right;
            root->right = delete_from_avl(root->right, min_on_right);
        }
    }
    // return root;
    return perform_rotation(root);
}

bool AVL::search(int data)
{
    return search_in_avl(root, data);
}

bool AVL::search_in_avl(Node *n, int data)
{
    Node *curr = n;
    while (curr != NULL)
    {
        if (curr->data == data)
            return true;
        else if (curr->data > data)
            curr = curr->left;
        else
            curr = curr->right;
    }
    return false;
}

void AVL::inorder()
{
    /*
        1=> visit left;
        2 => visit curr
        3 => visit right;
        4 => pop from stack
    */
    stk.push({root, 1});
    while (!stk.empty())
    {
        if (stk.top().second == 1)
        {
            stk.top().second = 2;
            if (stk.top().first->left)
                stk.push({stk.top().first->left, 1});
        }
        else if (stk.top().second == 2)
        {
            stk.top().second = 3;
            cout << stk.top().first->data << " ";
        }
        else if (stk.top().second == 3)
        {
            stk.top().second = 4;
            if (stk.top().first->right)
                stk.push({stk.top().first->right, 1});
        }
        else
        {
            stk.pop();
        }
    }
    cout << "\n";
}

AVL_Iterator AVL::get_it()
{
    return AVL_Iterator(root);
}

AVL_Iterator AVL::begin()
{
    return AVL_Iterator(root);
}

AVL_Iterator AVL::end()
{
    return AVL_Iterator(NULL);
}

//AVL Iterators Function Definations====================

AVL_Iterator::AVL_Iterator(Node *n)
{
    if (n != NULL)
    {
        stk.push({n, 1});
        ptr = next();
    }
}

Node *AVL_Iterator::next()
{
    Node *curr = NULL;
    while (!stk.empty())
    {
        if (stk.top().second == 1)
        {
            stk.top().second = 2;
            if (stk.top().first->left)
                stk.push({stk.top().first->left, 1});
        }
        else if (stk.top().second == 2)
        {
            stk.top().second = 3;
            curr = stk.top().first;
            break;
        }
        else if (stk.top().second == 3)
        {
            stk.top().second = 4;
            if (stk.top().first->right)
                stk.push({stk.top().first->right, 1});
        }
        else
        {
            stk.pop();
        }
    }
    return curr;
}
