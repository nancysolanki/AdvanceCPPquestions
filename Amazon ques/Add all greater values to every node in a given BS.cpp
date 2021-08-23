// The method discussed in this article uses the technique of reverse in-order tree traversal of BST which optimizes the problem to be solved in a single traversal. 
// Approach: In this problem as we could notice that the largest node would remain the same. The value of 2nd largest node = value of largest + value of second largest node. 
//   Similarly, the value of nth largest node will be the sum of the n-th node and value of (n-1)th largest node after modification. So if we traverse the tree in descending order 
//   and simultaneously update the sum value at every step while adding the value to the root node, the problem would be solved. 
// So to traverse the BST in descending order we use reverse in-order traversal of BST. This takes a global variable sum which is updated at every node and once the root node is
// reached it is added to the value of root node and value of the root node is updated.

// C++ program to add all greater
// values in every node of BST
#include <bits/stdc++.h>
using namespace std;

class Node {
public:
	int data;
	Node *left, *right;
};

// A utility function to create
// a new BST node
Node* newNode(int item)
{
	Node* temp = new Node();
	temp->data = item;
	temp->left = temp->right = NULL;
	return temp;
}

// Recursive function to add all
// greater values in every node
void modifyBSTUtil(Node* root, int* sum)
{
	// Base Case
	if (root == NULL)
		return;

	// Recur for right subtree
	modifyBSTUtil(root->right, sum);

	// Now *sum has sum of nodes
	// in right subtree, add
	// root->data to sum and
	// update root->data
	*sum = *sum + root->data;
	root->data = *sum;

	// Recur for left subtree
	modifyBSTUtil(root->left, sum);
}

// A wrapper over modifyBSTUtil()
void modifyBST(Node* root)
{
	int sum = 0;
	modifyBSTUtil(root, &sum);
}

// A utility function to do
// inorder traversal of BST
void inorder(Node* root)
{
	if (root != NULL) {
		inorder(root->left);
		cout << root->data << " ";
		inorder(root->right);
	}
}

/* A utility function to insert
a new node with given data in BST */
Node* insert(Node* node, int data)
{
	/* If the tree is empty,
	return a new node */
	if (node == NULL)
		return newNode(data);

	/* Otherwise, recur down the tree */
	if (data <= node->data)
		node->left = insert(node->left, data);
	else
		node->right = insert(node->right, data);

	/* return the (unchanged) node pointer */
	return node;
}

// Driver code
int main()
{
	/* Let us create following BST
			50
		/ \
		30 70
		/ \ / \
	20 40 60 80 */
	Node* root = NULL;
	root = insert(root, 50);
	insert(root, 30);
	insert(root, 20);
	insert(root, 40);
	insert(root, 70);
	insert(root, 60);
	insert(root, 80);

	modifyBST(root);

	// print inorder traversal of the modified BST
	inorder(root);

	return 0;
}

// This code is contributed by rathbhupendra
