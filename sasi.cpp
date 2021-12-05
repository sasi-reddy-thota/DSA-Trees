#include<bits/stdc++.h>
using namespace std;

class TreeNode{
	public:
	int data;
	int numChild;
	vector<TreeNode*>children;
	TreeNode(int x, int n)
	{
		data=x;
		numChild=n;
		children.assign(numChild,NULL);
	}
};
TreeNode* takeInput()
{
	int x,n;
	cin>>x>>n;
	TreeNode *root=new TreeNode(x,n);
	for(int i=0;i<n;i++)
	{
		root->children[i]=takeInput();
	}
	return root;

}
void takeInputLevelWise(TreeNode *root)
{
	queue<TreeNode*>q;
	q.push(root);
	while(q.size())
	{
		TreeNode *ptr=q.front();q.pop();
		if(ptr->numChild)
		cout<<"Please Enter the childeren's data and number of grand children of "<<ptr->data<<": ";
		for(int i=0;i<ptr->numChild;i++)
		{
			int x,n;
			cin>>x>>n;
			TreeNode *newNode=new TreeNode(x,n);
			ptr->children[i]=newNode;
			q.push(newNode);
		}
	}

}
void printLevelWise(TreeNode *root)
{
	queue<TreeNode*>q;
	q.push(root);
	while(q.size())
	{
		TreeNode *ptr=q.front();q.pop();
		cout<<"children of "<<ptr->data<<" are: ";
		for(int i=0;i<ptr->numChild;i++)
		{
			cout<<ptr->children[i]->data<<" ";
			q.push(ptr->children[i]);
		}
		cout<<"\n";
	}
}
int numberofNodes(TreeNode *root)
{
	if(root==NULL)
	return 0;
	int count=0;
	for(int i=0;i<root->numChild;i++)
	{
		count+=numberofNodes(root->children[i]);
	}
	return 1+count;
}
int sumofNodes(TreeNode *root)
{
	if(root==NULL)
	return 0;
	int sum=root->data;
	for(int i=0;i<root->numChild;i++)
	sum+=sumofNodes(root->children[i]);
	return sum;
}
TreeNode* maxNodeData(TreeNode* root)
{
	TreeNode *maxNode=root;
	for(int i=0;i<root->numChild;i++)
	{
		TreeNode* temp=maxNodeData(root->children[i]);
		if(temp->data>maxNode->data)
		maxNode=temp;
	}
	return maxNode;
}
int heightOfTree(TreeNode *root)
{
	if(root==NULL)
	return 0;
	int maxHeight=0;
	for(int i=0;i<root->numChild;i++)
	maxHeight=max(maxHeight,heightOfTree(root->children[i]));
	return maxHeight+1;
}
int countLeafNodes(TreeNode* root)
{
	if(root==NULL)
	return 0;
	if(!root->numChild)
	return 1;
	int count=0;
	for(int i=0;i<root->numChild;i++)
	count+=countLeafNodes(root->children[i]);
	return count;
}
void preOrder(TreeNode *root)
{
	if(root==NULL)
	return;
	cout<<root->data<<" ";
	for(int i=0;i<root->numChild;i++)
	preOrder(root->children[i]);
}
void postOrder(TreeNode *root)
{
	if(root==NULL)
	return;
	for(int i=0;i<root->numChild;i++)
	postOrder(root->children[i]);
	cout<<root->data<<" ";
}
bool containData(TreeNode* root,int x)
{
	if(root->data==x)
	return 1;
	for(int i=0;i<root->numChild;i++)
	{
		if(containData(root->children[i],x))
		return 1;
	}
	return 0;
}
int countGreater(TreeNode *root,int x)
{
	int count=0;
	if(root->data>x)
	count++;
	for(int i=0;i<root->numChild;i++)
	count+=countGreater(root->children[i],x);
	return count;
}
TreeNode* maxSumChild(TreeNode* root){
	if(root==NULL)
	return NULL;
	TreeNode *ans=root;
	int sum=root->data;
	for(int i=0;i<root->numChild;i++)
	sum+=root->children[i]->data;
	for(int i=0;i<root->numChild;i++)
	{
		TreeNode *x=maxSumChild(root->children[i]);
		int xsum=x->data;
		for(int i=0;i<x->numChild;i++)
		xsum+=x->children[i]->data;
		if(xsum>sum)
		{
			sum=xsum;
			ans=x;
		}
	}
	return ans;
}
bool areIdentical(TreeNode *root1,TreeNode *root2)
{
	if(root1==NULL||root2==NULL)
	return !((root1==NULL)^(root2==NULL));
	if(root1->data!=root2->data)
	return 0;
	if(root1->numChild==root2->numChild)
	{
		for(int i=0;i<root1->numChild;i++)
		{
			if(!areIdentical(root1->children[i],root2->children[i]))
			return 0;
		}
		return 1;
	}
	return 0;
}
TreeNode* nextLarger(TreeNode* root, int x)
{
	if(root==NULL)
	return NULL;
	TreeNode *nextL=NULL;
	if(root->data>x)
	nextL=root;
	for(int i=0;i<root->numChild;i++)
	{
		TreeNode *ptr=nextLarger(root->children[i],x);
		if(nextL && ptr)
		{
			if(nextL->data>ptr->data&&ptr->data>x)
			nextL=ptr;
		}
		else if(ptr)
		{
			if(ptr->data>x)
			nextL=ptr;
		}
	}
	return nextL;
}
void replaceDepth(TreeNode* root,int depth)
{
	if(root==NULL)
	return;
	root->data=depth;
	for(int i=0;i<root->numChild;i++)
	replaceDepth(root->children[i],depth+1);
}
//1 3 2 3 5 2 11 0 12 0 6 2 13 0 14 0 7 1 15 0 3 2 8 2 16 0 17 0 9 2 18 0 19 0 4 1 10 1 20 0
int main()
{
	TreeNode *root1=takeInput();
	// TreeNode *root2=takeInput();
	printLevelWise(root1);
	cout<<endl;
	cout<<"Number of nodes in Tree: "<<numberofNodes(root1);
	cout<<endl;
	cout<<"Sum of all nodes in Tree: "<<sumofNodes(root1);
	cout<<endl;
	cout<<"Maximum data in all nodes: "<<maxNodeData(root1)->data;
	cout<<endl;
	cout<<"Height of a tree: "<<heightOfTree(root1);
	cout<<endl;
	cout<<"Total leafNOdes in a tree: "<<countLeafNodes(root1);
	cout<<endl;
	preOrder(root1);
	cout<<endl;
	postOrder(root1);
	cout<<endl;
	cout<<"Is the data is present in the tree: "<<containData(root1,14);
	cout<<endl;
	cout<<"Number of nodes, which are greater than the 5 is: "<<countGreater(root1, 5);
	cout<<endl;
	cout<<"Maximum root child sum in the Tree is: "<<maxSumChild(root1)->data;
	cout<<endl;
	cout<<"both trees are identical: "<<areIdentical(root1,root1);
	cout<<endl;
	cout<<"next larger element: "<<nextLarger(root1,19)->data;
	cout<<endl;
	replaceDepth(root1,0);
	preOrder(root1);
	return 0;
}
