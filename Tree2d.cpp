#include<iostream>
#include<queue>
#include<graphics.h>
#include<stdlib.h>
#include<string.h>
#include <cmath>
#include <sstream>
using namespace std;
class Node{
	public:
	int data;
	Node* left;
	Node* right;
	Node(int d){
		this->data=d;
		this->left=NULL;
		this->right=NULL;
	}
};
//traversals
//inorder
void inorder(Node* root){
	if(root==NULL){
		return;
	}
	inorder(root->left);
	cout<<root->data<<" ";
	inorder(root->right);
}
//preorder
void preorder(Node* root){
	if(root==NULL){
		return;
	}
	cout<<root->data<<" ";
	preorder(root->left);
	preorder(root->right);
}
//postorder
void postorder(Node* root)
{	if(root==NULL){
		return;
	}
	postorder(root->left);
	postorder(root->right);
	cout<<root->data<<" ";
}


//buildTree 
Node* buildTree(Node* root){
	cout<<"Enter the data"<<endl;
	int data;
	cin>>data;
	root=new Node(data);
	if(data==-1){
		return NULL;
	}
	cout<<"Enter data for inserting in LEFT of "<<endl;
	root->left=buildTree(root->left);
	cout<<"Enter data for inserting in RIGHT of "<<endl;
	root->right=buildTree(root->right);
	return root;
}
void printTree(int x, int y, Node* root, int index) {
    Node* left;
     Node* right;
    int lx, ry;
    string str;
    stringstream ss;

    // Base case of our recursive function
    if (!root)
        return;

    // Convert int value into string
        ss << root->data;
        ss >> str;

    // Set color of the boundary of circle as green
    setcolor(GREEN);

    // Draw the circle of radius 20 that represents the node of the Tree
    circle(x, y, 20);
    delay(200);
    floodfill(x, y, GREEN);
    delay(200);

    // Print the values of the node in the circle
    outtextxy(x - 2, y - 3, const_cast<char*>(str.c_str()));
    delay(200);
    // Set the color of the line from parent to child as green
    setcolor(GREEN);

    // Evaluating left and right child
    left = root->left;
    right = root->right;
    lx = 2 * index + 1;
    ry = 2 * index + 1;

    // Recursively draw the left subtree and the right subtree
    printTree(x - y / (index + 1), y + 50, left, lx);
    printTree(x + y / (index + 1), y + 50, right, ry);

    // Draw the line (or link) when the node is not the leaf node
    if (left != NULL) {
        delay(200);
        line(x, y + 14, x - y / (index + 1), y + 50 - 14);
    }
    if (right != NULL) {
        delay(200);
        line(x, y + 14, x + y / (index + 1), y + 50 - 14);
    }
    return;
}
int main(){
//	cout<<"hi project for tree builder"<<endl;
    cout << "USE -1 for NULL" << endl;
    Node* root = NULL;
    root = buildTree(root);

    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    printTree(500, 50, root, 0);

    delay(5000);

    closegraph();
    int c=1,choice;
	while(c){
		cout<<"1.In-Order Traversal\n2.Pre-Order Traversal\n3.Post-Order Traversal\n4.To exit\n ";
		cin>>choice;
		switch(choice){
			case 1:
			{
	         	cout<<"Inorder: ";
				inorder(root);
				break;
		    }
			case 2:
			{
				cout<<"Preorder: ";
				preorder(root);
				break;
		    } 
			case 3:
			{
				cout<<"Postorder: ";
				postorder(root);
				break;
		    }
			case 4:
			{
			    c=0;
				break;
		    }
			default:
			{
			cout<<"INVALID INPUT";
			}
					
		}
		cout<<"\n";
	}

	return 0;
}
