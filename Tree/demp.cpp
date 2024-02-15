#include<iostream>
using namespace std ; 
struct node 
{
    node * rchild  ; 
    node * lchild ; 
    int val ; 

    node(int a)
    {
        this -> val = a ; 
        this -> rchild = nullptr ;
        this -> lchild = nullptr ; 
    }
};

class BST 
{
    public  : 
    node * head ; 

    BST()
    {
        head = nullptr ; 
    }

    void InsertNode(int val)
    {
        node * newn = new node(val);
        if (head == nullptr)
        {
            head = newn ;
        }
        else 
        {
            node * temp = head ; 
            while (temp != nullptr)
            {
                if (temp -> val == val )
                {
                    return ;
                }
                 if (temp -> val > val)
                {
                    if (temp -> lchild == nullptr)
                    {
                        temp -> lchild = newn;
                        break ;
                    }
                    else 
                    {
                        temp  = temp -> lchild;
                    }
                }
                else if (temp -> val < val)
                {
                    if (temp -> rchild == nullptr)
                    {
                        temp -> rchild = newn ; 
                        break ; 
                    }
                    else 
                    {
                        temp = temp -> rchild ; 
                    }
                }
            }
        }
    }

    void displayPreorder(node * temp )
    {
        if (temp != nullptr)
        {
            cout<<temp -> val <<"\t"; 
            displayPreorder(temp -> lchild);
            displayPreorder(temp -> rchild); 
        }
    }

    void displayInorder(node * temp )
    {   
        if (temp != nullptr)
        {
            displayInorder(temp -> lchild);
            cout<<temp -> val << "\t";
            displayInorder(temp -> rchild);
        }
    }
    void displaPostorder(node * temp )
    {
        if (temp != nullptr)
        {
            displaPostorder(temp -> lchild);
            displaPostorder(temp -> rchild);
            cout<<temp -> val<< "\t";
        }
    }
    int countParent(node * temp)
    {
        static int iCnt = 0 ; 
        if (temp != nullptr)
        {
            if (temp -> lchild != nullptr && temp -> rchild != nullptr)
            {
                iCnt ++ ; 
            }
            countParent(temp -> rchild);
            countParent(temp -> lchild);
        }
    }

    int search(int no)
    {
        node * temp = head ; 
        while (temp != nullptr)
        {
            if (temp -> val ==  no)
            {
                return no;
            }
            else if (temp ->val < no)
            {
                temp = temp -> rchild;
            }
            else if (temp -> val > no)
            {
                temp = temp -> lchild;
            }
        }
        return -1;
    }
};

int main()
{
    BST o ; 
    o.InsertNode(10);
    o.InsertNode(20);
    o.InsertNode(30);
    o.InsertNode(9);
    o.InsertNode(5);
    o.InsertNode(8);

    o.displayPreorder(o.head);cout<<endl<<endl;;
    o.displayInorder(o.head);cout<<endl<<endl;;
    o.displaPostorder(o.head);cout<<endl<<endl;;
    cout<<o.search(8)<<endl<<endl;
    cout<<o.countParent(o.head)<<endl<<endl;

    return 0 ; 
}