// TREE_DSA.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
#include<vector>
class Node
{
public:
    int data;
    Node* right;
    Node* left;
    Node(int x)
    {
        this->data = x;
        right = NULL;
        left = NULL;
    }
};
class StackNode
{
public:
    Node* address;
    int flag;
};
class Tree
{
    Node* root;
public:
    Tree()
    {
        root = NULL;
    }
    void create()
    {
        cout << "\nEnter value for root node";
        root=createRec();
    }
    Node* createRec()
    {
        int x;
        cin >> x;
        if (x == NULL) return NULL;
        Node* p = new Node(x);
        //as x is valid  i have to create a node then check if user is interested in its left and right child incremnt
        //the same fun will be called for p.left as well as p ka right;
       // p->left = creatRec();
        p->left = createRec();
        p->right = createRec();
            //once i have created a node and all its incremeted child the node from which we have created all its
            //child shoudl be returned 
            return p;
    }
    //we have to create a binary tree such that it should obey the three rules
    //recursive and non recursive 
    //let's create with an another object 
    void createBinaryTree()
    {
        //specific root is allocaited to this objct 
        int x;
        cout << "keep entering number in binary tree enter 0 to stop";
        while (true)
        {
            cin >> x;
            if (x == 0) break;
            else
            {
               root= createRecBT(x,root);
            } 
        }

    }
    void search()
    {
        int x;
        cout << "Enter data to search";
        cin >> x;
        if (NonRecSearch(x))
        {
            cout << "data found sucessfully";
        }
        else
        {
            cout << "Data not found";
        }
    }
    int searchRec(Node* T, int x) {
        if (T == NULL) {
            return 0;
        }
        if (T->data == x) {
            return 1;
        }
        if (T->data > x) {
            return searchRec(T->left, x);
        }
        else {
            return searchRec(T->right, x);
        }
    }
    int NonRecSearch(int x) {
        Node* T = root;

        if (T == NULL) {
            return 0;
        }

        while (T != NULL) {
            if (T->data == x) {
                return 1;
            }
            if (T->data > x) {
                // left
                T = T->left;
            }
            else {
                T = T->right;
            }
        }

        return 0;
    }
    void count()
    {
        cout << "count of nodes is " << countRec(root);
    }
    int countRec(Node* root) {
        if (root == NULL) {
            return 0;
        }
        else {
            return countRec(root->left) + countRec(root->right) + 1;
        }
    }
    void getHeight()
    {
        cout << "\n height of  binary tree is " << BST_HeightRec(root);
    }
    int BST_HeightRec(Node* root) {
        if (root == NULL) {
            return 0;
        }
        else {
            return 1 + max(BST_HeightRec(root->left), BST_HeightRec(root->right));
        }
    }
    //see er havo to create rec
    Node* createRecBT(int data,Node *T)//recursive
    {
        if (T == NULL)
        {
            return new Node(data);
        }
        if (T->data > data)//x should at the left
        {
          T->left=createRecBT(data, T->left);
        }
        else if (T->data < data)//xshould be at  the right
        {
           T->right=createRecBT(data, T->right);
        }
        else
        {
            cout << "data has already been inserted";
        }
        return T;
    }
    void show()
    {
       // showPreorder(root);
        //showPostorder(root);
       showIterativeInorder();

    }
    void showPreorder(Node* root)
    {
        if (root == NULL) return;//if the root node is going to be null return
        //root node null means it is not created .it does'nt means it consist null root->next==null
        cout << endl << root->data;
        //once done call the showRec() for the left child as well as the right child
        showPreorder(root->left);
        showPreorder(root->right);
    }
    void showInorder(Node* root)
    {
        if (root == NULL) return;//if the root node is going to be null return
        //root node null means it is not created .it does'nt means it consist null root->next==null
        
        //once done call the showRec() for the left child as well as the right child
        showInorder(root->left);
        cout << endl << root->data;
        showInorder(root->right);
    }
    void showPostorder(Node* root)
    {
        if (root == NULL) return;//if the root node is going to be null return
        //root node null means it is not created .it does'nt means it consist null root->next==null

        //once done call the showRec() for the left child as well as the right child
        showPostorder(root->left);
        showPostorder(root->right);
        cout << endl << root->data;

    }
    void showIterativePreorder()
    {

        if (root == NULL)
        {
            return;
        }
        Node* t = root;
        vector<Node*>stack;
        while (t != NULL)
        {
            //first is the root node for every value of t hence vist it and the next corresponding
            //value in preoder is the value of the left child so go to left child and visit it 
            cout << endl << t->data;
            stack.push_back(t);
            t = t->left;
        }
        //as this fun is terminated the t is null  so i have to pop the values till the stack is not empty
        //then i have to check if the right is not null if it is not null then i have to visit it and push
        //it onto stack such that t=t->left;
        //then i have do till it reaches to null and then traverse it till all its left and right becomers
        //not null
        while (!stack.empty())
        {
            t = stack.back();
            stack.pop_back();
            t = t->right;
           // cout << endl << t->data; cannt give condtion here as if left c;hild are possible i have to print in the while loop
            while (t != NULL)
            {
                cout << endl << t->data;
                stack.push_back(t);
                t = t->left;

            }
        }
    }
    void iterativePostorder()
    {
        //print the left node at he first print the left node then i have to print the right node and then the root 
        if (root == NULL) return;
        vector<StackNode>stack;
        Node* t = root;
        StackNode node;
        while (t != NULL)
        {
            node.address = t;
            node.flag = 1;
            stack.push_back(node);
            t = t->left;
        }
        while (!stack.empty())
        {
            node = stack.back();
            stack.pop_back();
            t = node.address;
            if (node.flag == 1)//means it is a left node  
            {
                node.flag = 2;
                stack.push_back(node);
                t = t->right;
                while (t != NULL)
                {
                    node.address = t;
                    node.flag = 1;
                    stack.push_back(node);
                    t = t->left;
                }
            }
            else
            {
                cout << endl << t->data;
            }
        }
    }
    void showIterativeInorder();
};
void Tree::showIterativeInorder()
{   
    vector<Node*>stack;
    if (root == NULL) return;
    Node* T = root;
    while (T != NULL)
    {
        stack.push_back(T);
        T = T->left;
    }
    while(!stack.empty())
    {
        T = stack.back();
        cout << "  " << T->data;
        stack.pop_back();
        T = T->right;
        while (T != NULL)
        {
            stack.push_back(T);
            T = T->left;
        }
    }
    
}

int main()
{
    Tree tree;  
    ///tree.create();
    tree.createBinaryTree();
    tree.show();
    //tree.search();
    tree.count();
    tree.getHeight();
    //wnate to create a binary tree see we just have to change the create function instead rather than changing the whole code 
    //change the create fun 
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
