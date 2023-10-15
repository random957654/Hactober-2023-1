

// CODE OF IMPLEMENTATION OF B-TREE DATA STRUCTURE

#include <stdio.h>
#include <stdlib.h>                    //HEADER FILES
#include <stdbool.h>
#include <string.h>

struct B_tree_Node                  //STRUCTURE OF THE NODE 
{
    int n;                           //NUMBER OF KEYS IN NODE
    int *keys;                       //POINTER CARRYING ADDRESS OF KEYS
    struct B_tree_Node **children;       //POINTER TO CHILD NODES
    int leaf;                           //LEAF NODE
};

//B-TREE NODE CREATION
struct B_tree_Node *CREATENode(int leaf, int t)
{
    struct B_tree_Node *newNode = (struct B_tree_Node *)malloc(sizeof(struct B_tree_Node));
    {
        newNode->n = 0;
        newNode->leaf = leaf;
        newNode->keys = (int *)malloc(sizeof(int) * (2 * t - 1));
        newNode->children = (struct B_tree_Node **)malloc(sizeof(struct B_tree_Node *) * (2 * t));
        return newNode;
    }
}

//SPLIT FUNCTION TO SPLIT CHILD

void split_child(struct B_tree_Node *x, int i, struct B_tree_Node *x1, int t)
{
    struct B_tree_Node *x2 = CREATENode(x1->leaf, t);
    x2->n = t - 1;

    for (int i = 0; i < t - 1; i++)
    {
        x2->keys[i] = x1->keys[i + t];
    }

    if (!x1->leaf)
    {
        for (int j = 0; j < t; j++)
        {
            x2->children[j] = x1->children[j + t];
        }
    }

    x1->n = t - 1;
    for (int k = x->n; k > i; k--)
    {
        x->children[k + 1] = x->children[k];
    }

    x->children[i + 1] = x2;
    for (int l = x->n - 1; l >= i; l--)
    {
        x->keys[l + 1] = x->keys[l];
    }

    x->keys[i] = x1->keys[t - 1];
    x->n++;
}
//INSERT FUNCTION BASED ON WHETHER TREE IS EMPTY OR FULL
//FULL-NEW ROOT
//EMPTY-NEW NODE
void insert_non_full(struct B_tree_Node *x, int k, int t)
{
    int j = x->n - 1;

    if (x->leaf)        //
    {
        while (j >= 0 && k < x->keys[j])
        {
            x->keys[j + 1] = x->keys[j];
            j--;
        }
        x->keys[j + 1] = k;
        x->n++;
    }

    else
    {
        while (j >= 0 && k < x->keys[j])
        {
            j--;
        }
        j++;

        if (x->children[j]->n == (2 * t) - 1)
        {
            split_child(x, j, x->children[j], t);
            if (k > x->keys[j])
            {
                j++;
            }
        }
        insert_non_full(x->children[j], k, t);
    }
}

void insert(struct B_tree_Node **root, int k, int t)
{
    struct B_tree_Node *root_address = *root;

    if (root_address->n == (2 * t) - 1)
    {
        struct B_tree_Node *leaf_positon = CREATENode(0, t);
        leaf_positon->children[0] = root_address;
        *root = leaf_positon;
        split_child(leaf_positon, 0, root_address, t);
        insert_non_full(leaf_positon, k, t);
    }

    else
    {
        insert_non_full(root_address, k, t);
    }
}
//INORDER TRAVERSAL FUNCTION
void Inorder_Transversal(struct B_tree_Node *x)
{
    if (x != NULL)
    {
        int p;
        for (p = 0; p < x->n; p++)
        {
            if (!x->leaf)
            {
                Inorder_Transversal(x->children[p]);   //FOR LEFT PART OF B-TREE(RECURSIVE)
            }
            printf("%d,", x->keys[p]);
        }
        if (!x->leaf)
        {
            Inorder_Transversal(x->children[p]);       //FOR RIGHT PART OF B-TREE(RECURSIVE)
        }
    }
}
//SERACH FUNCTION IN B-TREE
bool search(struct B_tree_Node *x, int k)   //BOOLEAN OUTPUT :1-TRUE,0-FALSE
{
    int a = 0;
    while (a < x->n && k > x->keys[a])
    {
        a++;
    }
    if (a < x->n && k == x->keys[a])
    {
        return true;           //IF KEY FOUND
    }
    if (x->leaf)
    {
        return false;     //IF KEY NOT FOUND
    }

    return search(x->children[a], k);     //RETURN BACK FOR RECURSIVE SEARCH
}

//MINIMUM FUNCTION IN B-TRE
int find_Minimum(struct B_tree_Node *x)
{
    while (!x->leaf)
    {
        x = x->children[0];
    }

    return x->keys[0];
}

//DELETE FUNCTION
//->SEARCH OF KEY
//->IF KEY IN A LEAF NODE  ->REMOVE KEY FROM LEAF NODE
//->KEY NOT IN LEAF NODE  ->FIND PREDECESSOR AND SUCCESSOR
//->MERGING
void delete_key(struct B_tree_Node **root, int k, int t)
{
    struct B_tree_Node *r = *root;

    if (!r)     //FOR NO ELEMENT
    {
        printf("Empty Tree.\n");
        return;
    }

    int i = 0;
    while (i < r->n && k > r->keys[i])
    {
        i++;
    }
    if (i < r->n && k == r->keys[i])
    {
        if (r->leaf)
        {
            for (int j = i; j < r->n - 1; j++)
            {
                r->keys[j] = r->keys[j + 1];
            }
            r->n--;
            printf("Key deleted");
        }
        else
        {
            int min_key = find_Minimum(r->children[i + 1]);
            r->keys[i] = min_key;
            delete_key(&r->children[i + 1], min_key, t);
        }
    }

    else
    {
        if (r->leaf)
        {
            printf("Element not found");
            return;
        }

        bool in_last_child = (i == r->n);

        if (r->children[i]->n < t)
        {
            if (i < r->n && r->children[i + 1]->n >= t)
            {
                struct B_tree_Node *child = r->children[i];
                struct B_tree_Node *right_sibling = r->children[i + 1];

                child->keys[t-1] = r->keys[i];
                // child->n++;

                r->keys[i] = right_sibling->keys[0];

                for (int j = 0; j < right_sibling->n - 1; j++)
                {
                    right_sibling->keys[j] = right_sibling->keys[j + 1];
                }

                for (int j = 0; j <= right_sibling->n; j++)
                {
                    right_sibling->children[j] = right_sibling->children[j + 1];
                }
                child->n++;
                right_sibling->n--;

                delete_key(&child, k, t);
            }

            else if (i > 0 && r->children[i - 1]->n >= t)
            {
                struct B_tree_Node *child = r->children[i];
                struct B_tree_Node *left_sibling = r->children[i - 1];

                for (int j = child->n - 1; j >= 0; j--)
                {
                    child->keys[j + 1] = child->keys[j];
                }

                for (int j = child->n; j >= 0; j--)
                {
                    child->children[j + 1] = child->children[j];
                }

                child->keys[0] = r->keys[i - 1];
                // child->n++;

                r->keys[i - 1] = left_sibling->keys[left_sibling->n - 1];

                left_sibling->n--;
                child->n++;
                delete_key(&child, k, t);
            }

            else
            {
                if (i < r->n)
                {
                    struct B_tree_Node *child = r->children[i];
                    struct B_tree_Node *right_sibling = r->children[i + 1];

                    child->keys[t - 1] = r->keys[i];

                    for (int j = 0; j < right_sibling->n; j++)
                    {
                        child->keys[t + j] = right_sibling->keys[j];
                    }

                    for (int j = 0; j <= right_sibling->n; j++)
                    {
                        child->children[t + j] = right_sibling->children[j];
                    }

                    child->n += right_sibling->n + 1;

                    for (int j = i; j < r->n - 1; j++)
                    {
                        r->keys[j] = r->keys[j + 1];
                    }

                    for (int j = i + 1; j < r->n; j++)
                    {
                        r->children[j] = r->children[j + 1];
                    }

                    r->n--;

                    free(right_sibling);
                }

                else
                {
                    struct B_tree_Node *child = r->children[i];
                    struct B_tree_Node *left_sibling = r->children[i - 1];

                    left_sibling->keys[left_sibling->n] = r->keys[i - 1];

                    for (int j = 0; j < child->n; j++)
                    {
                        left_sibling->keys[left_sibling->n + 1 + j] = child->keys[j];
                    }

                    for (int j = 0; j <= child->n; j++)
                    {
                        left_sibling->children[left_sibling->n + 1 + j] = child->children[j];
                    }

                    left_sibling->n += child->n + 1;

                    for (int j = i - 1; j < r->n - 1; j++)
                    {
                        r->keys[j] = r->keys[j + 1];
                    }
                    for (int j = i; j < r->n; j++)
                    {
                        r->children[j] = r->children[j + 1];
                    }

                    r->n--;

                    free(child);
                }

                delete_key(&r->children[i], k, t);
            }
        }

        else
        {
            delete_key(&r->children[i], k, t);
        }
    }
}
int main()
{
    int t, n;
    char choice[10];
    char option;
    int key;
    int num_insert;

    // struct B_tree_Node*root=CREATENode(1,t);

    printf("Enter the minimum degree of the B-tree t: ");
    scanf("%d", &t);
    printf("Enter First or Second: ");
    scanf("%s", &choice);

    if (choice[0] == 'F')             //FOR FIRST OPERATIONS
    {
        printf("Enter'n': ");
        scanf("%d", &n);

        struct B_tree_Node *root = CREATENode(1, t);

        for (int i = n; i >= 1; i--)          //INSERTION OF KEY IN NODE
        {
            insert(&root, i, t);
        }

        printf("Inorder transversal is: ");
        Inorder_Transversal(root);                //INORDER TRANVERSAL OF KEY ELEMENTS
        printf("\n");

        printf("Enter an element to search: ");
        scanf("%d", &key);
        if (search(root, key))                //SEARCHING OF PARTICULAR KEY
        {
            printf("Present\n");
        }
        else
        {
            printf("Not Present\n");
        }
    }
    else if (choice[0] == 'S')          //FOR SECOND OPERATIONS
    {

        struct B_tree_Node *root = CREATENode(1, t);
        // printf("options: I for insertion, S for search, M for finding minimum, T for traversing the B-tree, D for Delete, E for exit:");
        //     scanf("%c", &option);
        // printf("options: I for insertion, S for search, M for finding minimum, T for traversing the B-tree, D for Delete, E for exit:");
        do
        {

            printf("options: I for insertion, S for search, M for finding minimum, T for traversing the B-tree, D for Delete, E for exit:");
            scanf("%c", &option);

            switch (option)                      //SWITCH CASES
            {
            case 'I':
                printf("Enter number of elements you want to enter: ");
                scanf("%d", &num_insert);
                printf("Enter %d numbers to insert: \n", num_insert);      //INSERTION OF KEY

                struct B_tree_Node *root = CREATENode(1, t);

                for (int b = num_insert; b >= 1; b--)
                {
                    int ins_key;
                    scanf("%d", &ins_key);
                    insert(&root, ins_key, t);
                }
                break;

            case 'S':
                printf("Enter element to search: ");//SEARCHING OF PARTICULAR KEY
                scanf("%d", &key);

                if (search(root, key))
                {
                    printf("Present\n");
                }
                else
                {
                    printf("Absent\n");
                }
                break;

            case 'M':

                if (root->n > 0)
                {
                    printf("Minimum key: %d\n", find_Minimum(root));//MINIMUM KEY IN THE B-TREE
                }

                else
                {
                    printf("Tree is empty.\n");
                }
                break;

            case 'T':

                if(root->n==0)
                {
                    printf("Empty tree\n");
                }

                else if(root==NULL)
                {
                    printf("Empty tree\n");
                }
                else{
                printf("Inorder traversal is: ");   //INORDER TRAVERSAL
                Inorder_Transversal(root);
                printf("\n");
                
                }
                break;

            case 'D':
                printf("Enter element to delete: ");      //DELETE
                scanf("%d", &key);
                delete_key(&root, key, t);
                break;

            case 'E':
                return 0;             //EXIT 
                break;

            default:
                break;
            }

        } while (option != 'S' || option != 'I' || option != 'M' || option != 'T' || option != 'D' || option != 'E');
        {
            return 0;
        }
    }
    else
    {
        printf("Invalid Choice");    //INVALID CHOICE
    }
}
