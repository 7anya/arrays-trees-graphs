#include<bits/stdc++.h>

using namespace std;
#define int long long int
#define ld long double
#define MOD 1000000007
#define endl "\n"
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define all(var) (var).begin(), (var).end()
#define MAXX 9000000000000000000
#define pii pair<int,int>
#define vi vector<int>
#define vvi vector<vector<int> >
#define vpi vector<pair<int,int> >
#define vvpi vector<vector<pair<int,int> > >

struct node {
    int data;
    struct node *left, *right;

    node(int data) {
        this->data = data;
        left = right = NULL;
    }
};

void Inorder(struct node *node) {
    //all of these are theta(n)
    if (node == NULL)
        return;
    Inorder(node->left);
    cout << node->data << " ";
    Inorder(node->right);

}

int minDepth(node *root) {

    if (root == NULL)
        return 0;

    if (root->left == NULL && root->right == NULL)
        return 1;

    if (!root->left)
        return minDepth(root->right) + 1;


    if (!root->right)
        return minDepth(root->left) + 1;

    return min(minDepth(root->left), minDepth(root->right)) + 1;
}

void PostOrder(struct node *node) {
    if (node == NULL)
        return;
    PostOrder(node->left);
    PostOrder(node->right);
    cout << node->data << " ";
}

void PreOrder(struct node *node) {
    if (node == NULL)
        return;
    cout << node->data << " ";
    PreOrder(node->left);
    PreOrder(node->right);

}

void invert(node *root) {
    if (!root)
        return;
    node *temp;
    temp = root->right;
    root->right = root->left;
    root->left = temp;
    invert(root->left);
    invert(root->right);
}

void LevelOrderBFS(node *head) {

    queue<node *> q;
    node *temp = head;
    while (temp != NULL) {
        cout << temp->data; //print value
        if (temp->left != NULL) //sanity check
            q.push(temp->left); //enqueue children
        if (temp->right != NULL) //sanity check
            q.push(temp->right);
        temp = q.front(); //dequeue
        q.pop();


    }
}

node *mergeTrees(node *t1, node *t2) {

    if (t1 == NULL)
        return t2;
    if (t2 == NULL)
        return t1;
    t1->data += t2->data;
    t1->left = mergeTrees(t1->left, t2->left);
    t1->right = mergeTrees(t1->right, t2->right);
    return t1;
}

int heightofTree(node *head) {

    if (head == NULL)
        return 0;
    return 1 + max(heightofTree(head->left), heightofTree(head->right));
}

node *searchBST(node *root, int data) {

    if (root == NULL || root->data == data)
        return root;
    if (data < root->data)
        return searchBST(root->left, data);
    return searchBST(root->left, data);
}

node *addIntoBST(node *Node, int data) {

    if (Node == NULL) {
        struct node *temp = new node(data);
        return temp; //finally add when u reach a leaf's null child
    }
    if (data > Node->data)
        Node->right = addIntoBST(Node->right, data); //go deeper into right subtree
    else
        Node->left = addIntoBST(Node->left, data); //do deeper into left subtree
    return Node;
}

node *ConvertSortedArrayIntoBSTBST(vector<int> &v, int start, int end) {
    if (start > end)
        return NULL;
    int mid = (start + end) / 2;
    node *root = new node(v[mid]);
    root->left = ConvertSortedArrayIntoBSTBST(v, start, mid - 1);
    root->right = ConvertSortedArrayIntoBSTBST(v, mid + 1, end);
    return root;
}

int identicalTrees(node *a, node *b) {
    /*1. both empty */
    if (a == NULL && b == NULL)
        return 1;

    /* 2. both non-empty -> compare them */
    if (a != NULL && b != NULL) {
        return
                (
                        a->data == b->data &&
                        identicalTrees(a->left, b->left) &&
                        identicalTrees(a->right, b->right)
                );
    }

    /* 3. one empty, one not -> false */
    return 0;
}
void inorderVector(node *a,vi &ans)
{
    if(!a)
        return ;
    inorderVector(a->left,ans);
    ans.push_back(a->data);
    inorderVector(a->right,ans);
}
int RangeSum(node * a,int low,int high)
{
vi ans;
    inorderVector(a, ans);
    int s=0;
    for(auto x:ans)
        if(x>=low && x<=high)
            s+=x;
        return s;
}
node* mergeTree(node* t1,node* t2)
{
    if(t1==NULL)
        return t2;
    if(t2==NULL)
        return t1;
    t1->data+=t2->data;
    t1->left=mergeTree(t1->left,t2->left);
    t1->right=mergeTree(t1->right,t2->right);
    return t1;
}
//Given the root of a binary search tree, rearrange the
//tree in in-order so that the leftmost node in the tree is now the root of the tree,
// and every node has no left child and only one right child
node* IncreasingOrderSearchtree(node* root)
{
    vi ans;
    inorderVector(root,ans);
    node * l=new node(ans[0]);
    node*temp=l;
    for(int i=1;i<ans.size();i++)
    {
        temp->right=new node(ans[i]);
        temp=temp->right;
    }

    return l;
}
node* SearchBSt(node* root,int val)
{
    if(!root)
        return NULL;
    if(root->data==val)
        return root;
    if(root->data>val)
        return  SearchBSt(root->left,val);
    else
        return SearchBSt(root->right,val);
}
//void naryPreorder(node* root)
//{
//    if(root==NULL)
//        return;
//    cout<<root->data;
//    for(auto x:node->children)
//        naryPreorder(x);
//}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
//    struct node *root = new node(1);
//    root->left             = new node(2);
//    root->right         = new node(3);
//    root->left->left     = new node(4);
//    root->left->right = new node(5);
    node *root = NULL;
    root = addIntoBST(root, -10);
    root = addIntoBST(root, -3);
    root = addIntoBST(root, 0);
    root = addIntoBST(root, 5);
    root = addIntoBST(root, 9);
//   root= addIntoBST(root,80);
    cout << "\nPreorder traversal of binary tree is \n";
    PreOrder(root);

    cout << "\nInorder traversal of binary tree is \n";
    Inorder(root);

    cout << "\nPostorder traversal of binary tree is \n";
    PostOrder(root);
    cout << "\nLevel Order traversal of binary tree is \n";
    LevelOrderBFS(root);
    cout << "\nheight of tree\n";
    cout << heightofTree(root);
    return 0;
}
