#include <bits/stdc++.h>
using namespace std;

//AVL NODE
template <typename T>
struct Node
{
    T data;
    int height, balance_factor;
    Node<T> *left, *right;
    Node(T x)
    {
        data = x;
        height = 1;
        balance_factor = 0;
        left = right = nullptr;
    }

    T operator*()
    {
        return this->data;
    }
};

// template <typename T>

template <typename T>
class AVL
{

public:
    class Iterator
    {
    private:
        //Private variables
        vector<pair<Node<T> *, int>> stk;
        Node<T> *ptr = nullptr;
        Node<T> *next();

    public:
        //Traits or properties assigned to the iterator to make it work with standard algos
        typedef ptrdiff_t difference_type;
        typedef T value_type;
        typedef T *pointer;
        typedef T &reference;
        typedef forward_iterator_tag iterator_category;
        // Constructor
        Iterator(Node<T> *n)
        {
            if (n)
            {
                //initial node and direction 1 pushed to the stack.
                stk.push_back({n, 1});
                ptr = next(); // move internal pointer to current
            }
        }

        // // Copy Constructor
        // Iterator<T>(const Iterator<T> &rhs)
        // {
        //     this->ptr = rhs.ptr;
        //     this->stk = rhs.stk;
        // }

        // // Copy assignment Constructor
        // Iterator<T> &operator=(const Iterator<T> &rhs)
        // {
        //     this->ptr = rhs.ptr;
        //     this->stk = rhs.stk;
        //     return *this;
        // }

        Iterator &operator++()
        {
            ptr = next();
            return *this;
        }
        //post increment
        Iterator operator++(int)
        {
            auto temp(*this);
            ++(*this);
            return temp;
        }

        T operator*()
        {
            return ptr->data;
        }

        Node<T> *operator->()
        {
            return ptr;
        }
        bool operator==(const Iterator &other) const
        {
            return this->ptr == other.ptr;
        }

        bool operator!=(Iterator other)
        {
            return this->ptr != other.ptr;
        }
    };
    // Constructor
    AVL<T>() : root(nullptr) {}

    // Insert
    void insert(T data);
    // Display
    void print_tree();
    // Delete
    void erase(T data);
    // Search
    Iterator find(T data);

    inline bool empty()
    {
        return root == nullptr;
    }
    //end and begin
    inline Iterator begin()
    {
        return Iterator(root);
    }

    inline Iterator end()
    {
        return Iterator(nullptr);
    }

private:
    // Private variables
    Node<T> *root;
    vector<pair<Node<T> *, int>> stk;
    // Rotations Utilities
    void update_height_and_balance_factor(Node<T> *n);
    Node<T> *left_rotation(Node<T> *n);
    Node<T> *right_rotation(Node<T> *n);
    Node<T> *perform_rotation(Node<T> *n);
    // Insert Utilities
    Node<T> *insert_into_avl(Node<T> *n, T data);

    // Display Tree
    void print_tree(const std::string &prefix, Node<T> *node, bool isLeft);

    // Delete Utilities
    T get_min(Node<T> *n);
    Node<T> *delete_from_avl(Node<T> *root, T data);

    // Search Utilities
    Iterator search_in_avl(Node<T> *n, T data);
};
template <typename T>
Node<T> *AVL<T>::Iterator::next()
{
    //goes to the inorder successor
    /*
        1=> visit left
        2=> curr
        3=> visit right
        4=> pop
    */
    Node<T> *curr = nullptr;
    while (stk.size() != 0)
    {
        if (stk.back().second == 1)
        {
            stk.back().second = 2;
            if (stk.back().first->left)
                stk.push_back({stk.back().first->left, 1});
        }
        else if (stk.back().second == 2)
        {
            stk.back().second = 3;
            curr = stk.back().first;
            break;
        }
        else if (stk.back().second == 3)
        {
            stk.back().second = 4;
            if (stk.back().first->right)
                stk.push_back({stk.back().first->right, 1});
        }
        else
        {
            stk.pop_back();
        }
    }
    return curr;
}

// template <typename IterT>
// struct iterator_traits<IterT>
// {
//     typedef ptrdiff_t difference_type;
//     typedef IterT::value_type value_type;
//     typedef IterT::pointer pointer;
//     typedef IterT::reference reference;
//     typedef IterT::iterator_category iterator_category;
// };

// template <typename IterT>
// struct iterator_traits<IterT *>
// {
//     typedef ptrdiff_t difference_type;
//     typedef T value_type;
//     typedef T *pointer;
//     typedef T &reference;
//     typedef forward_iterator_tag iterator_category;
// };

//AVL Functions===================================================================
template <typename T>
void AVL<T>::update_height_and_balance_factor(Node<T> *n)
{
    if (n == nullptr)
        return;
    int left_height = n->left == nullptr ? 0 : n->left->height;
    int right_height = n->right == nullptr ? 0 : n->right->height;

    n->height = max(left_height, right_height) + 1;
    n->balance_factor = left_height - right_height;
}

template <typename T>
Node<T> *AVL<T>::left_rotation(Node<T> *n)
{
    Node<T> *a = n;
    Node<T> *b = a->right;
    Node<T> *b_l = b->left;

    b->left = a;
    a->right = b_l;

    update_height_and_balance_factor(a);
    update_height_and_balance_factor(b);
    return b;
}

template <typename T>
Node<T> *AVL<T>::right_rotation(Node<T> *n)
{
    Node<T> *a = n;
    Node<T> *b = a->left;
    Node<T> *b_r = b->right;

    b->right = a;
    a->left = b_r;

    update_height_and_balance_factor(a);
    update_height_and_balance_factor(b);
    return b;
}

template <typename T>
Node<T> *AVL<T>::perform_rotation(Node<T> *n)
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
            //perform LL rotation (right rotate)
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

template <typename T>
Node<T> *AVL<T>::insert_into_avl(Node<T> *n, T data)
{
    if (n == nullptr)
        return new Node<T>(data);
    // if (n->data > data)
    if (greater<T>()(n->data, data))
    {
        n->left = insert_into_avl(n->left, data);
    }
    // else
    else if (less<T>()(n->data, data))
    {
        n->right = insert_into_avl(n->right, data);
    }

    return perform_rotation(n);
}

template <typename T>
void AVL<T>::insert(T data)
{
    root = insert_into_avl(root, data);
}

template <typename T>
void AVL<T>::print_tree(const std::string &prefix, Node<T> *node, bool isLeft)
{
    if (node != nullptr)
    {
        std::cout << prefix;

        std::cout << (isLeft ? "├── " : "└──> ");

        // print the value of the node
        std::cout << node->data << "(" << node->balance_factor << ")" << std::endl;

        // enter the next tree level - left and right branch
        print_tree(prefix + (isLeft ? "|   " : "    "), node->left, true);
        print_tree(prefix + (isLeft ? "|   " : "    "), node->right, false);
    }
}

template <typename T>
void AVL<T>::print_tree()
{
    print_tree("", root, false);
}

template <typename T>
T AVL<T>::get_min(Node<T> *n)
{
    while (n->left != nullptr)
        n = n->left;
    return n->data;
}

template <typename T>
Node<T> *AVL<T>::delete_from_avl(Node<T> *root, T data)
{
    // return root;
    if (root == nullptr)
        return root;
    // if (root->data > data)
    if (greater<T>()(root->data, data))
    {
        root->left = delete_from_avl(root->left, data);
    }
    // else if (root->data < data)
    else if (less<T>()(root->data, data))
    {
        root->right = delete_from_avl(root->right, data);
    }
    else
    {
        //root contains data => root needs to be deleted
        if (root->left == nullptr || root->right == nullptr)
        {
            return root->left == nullptr ? root->right : root->left;
        }
        else
        {
            T min_on_right = get_min(root->right); //gets min node from right subtree
            root->data = min_on_right;
            root->right = delete_from_avl(root->right, min_on_right);
        }
    }
    // return root;
    return perform_rotation(root);
}

template <typename T>
void AVL<T>::erase(T data)
{
    root = delete_from_avl(root, data);
}

template <typename T>

typename AVL<T>::Iterator AVL<T>::search_in_avl(Node<T> *n, T data)
{
    Node<T> *curr = n;
    while (curr != nullptr)
    {
        // if (curr->data == data)
        if (equal_to<T>()(curr->data, data))
            return AVL<T>::Iterator(curr);
        // else if (curr->data > data)
        else if (greater<T>()(curr->data, data))
            curr = curr->left;
        else
            curr = curr->right;
    }
    return AVL<T>::Iterator(nullptr);
}

template <typename T>
typename AVL<T>::Iterator AVL<T>::find(T data)
{
    return search_in_avl(root, data);
}