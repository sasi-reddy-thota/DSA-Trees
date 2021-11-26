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
int main()
{
	cout<<"Please Enter the Data and number of children of the root";
	int x,n;
	cin>>x>>n;
	TreeNode *root=new TreeNode(x,n);
	takeInputLevelWise(root);
	printLevelWise(root);
	cout<<endl;
	cout<<numberofNodes(root);
	return 0;
}
