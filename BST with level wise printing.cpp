#include<iostream>
#include<list>
#include<iomanip>
#include<cmath>
#include<stdlib.h>
#include<ctime>
using namespace std;
class BST
{
		struct node
		{
			int data;
			node *l;
			node* r;
		};
		node *root;
		node *makeEmpty(node *n)
		{
			if(n==NULL)		return NULL;
			makeEmpty(n->l);
			makeEmpty(n->r);
			delete n;
			return NULL;
		}
		node* insert(int x,node* n)
		{
			if(n==NULL)
			{
				n=new node;
				n->data=x;
				n->l=n->r=NULL;
			}
			else if(x<n->data)
				n->l=insert(x,n->l);
			else if(x>n->data)
				n->r=insert(x,n->r);
			return n;
		}
		node* findMin(node *n)
		{
			if(n==NULL) return NULL;
			else if(n->l==NULL) return n;
			else return findMin(n->l);
		}
		node* findMax(node *n)
		{
			if(n==NULL) return NULL;
			else if(n->r==NULL) return n;
			else return findMax(n->r);
		}
		node* remove(int x,node *n)
		{
			node* temp;
			if(n==NULL) return NULL;
			else if(x<n->data)
				n->l=remove(x,n->l);
			else if(x>n->data)
				n->r=remove(x,n->r);
			else if(n->l && n->r)
			{
				temp=findMin(n->r);
				n->data=temp->data;
				n->r=remove(n->data,n->r);
			}
			else
			{
				temp=n;
				if(n->l==NULL)
					n=n->r;
				else if(n->r==NULL)
					n=n->l;
				delete temp;
			}
			return n;
		}
		void inorder(node *n)
		{
			if(n==NULL) return;
			inorder(n->l);
			cout<<n->data<<" ";
			inorder(n->r);
		}
		node* find(node *n,int x)
		{
			if(n==NULL) return NULL;
			else if(x<n->data) find(n->l,x);
			else if(x>n->data) find(n->r,x);
			else return n;
		}
		int maxDepth(node *n)
		{
			if(!n) return 0;
			return 1 + std::max(maxDepth(n->l), maxDepth(n->r));
		}
	public:
		BST()
		{
			root=NULL;
		}
		~BST()
		{
			root=makeEmpty(root);
		}
		void insert(int x)
		{
			root=insert(x,root);
		}
		void remove(int x)
		{
			root=remove(x,root);
		}
		void display()
		{
			inorder(root);
		}
		void search(int x)
		{
			root=find(root,x);
		}

		void printLevelWise()
		{
			struct node_depth
			{
				node* n;
				int lvl;
				int no;
				node_depth(node* n_,int lvl_,int no_)
				{
					n=n_;
					lvl=lvl_;
					no=no_;
				}
			};
			int depth=maxDepth(root);
			int last_lvl=0;
			int last_no=1;
			list<node_depth> q;
			list<node_depth>t;
			q.push_back(node_depth(root,last_lvl,last_no));
			while(q.size())
			{
				node_depth& nd = *q.begin();
				if (last_lvl != nd.lvl)
				{
					std::cout << "\n";
					last_lvl = nd.lvl;
					last_no =nd.no;
				}
				if (nd.n)
				{
					if(nd.n->l) q.push_back(node_depth(nd.n->l, last_lvl + 1,2*last_no));
					if(nd.n->r) q.push_back(node_depth(nd.n->r, last_lvl + 1,(2*last_no+1)));
					last_no++;
				}
				t.push_back(node_depth(q.front().n,q.front().lvl,q.front().no));
				q.pop_front();
			}

			int i, space, ones, j, k,count,counter;
			count=1;
			counter=0;
			for(i = 1; i<=depth; i++)
			{
				ones = pow(2, i-1);
				space = pow(2, depth-i+1) - 1;
				for(j = 1; j<=ones; j++)
				{
					if(j == 1)
						for(k = 1; k<= space/2; k++)					cout<<" ";
					else
						for(k = 1; k<= space; k++)  					cout<<" ";
					if(count==t.front().no)
					{
						cout<<setfill(' ')<<setw(2)<<t.front().n->data;
						counter++;
						t.pop_front();
					}
					else
						for(k = 1; k<2; k++)
						{
							cout<<setfill(' ')<<setw(2)<<"_";
						}
					count++;
				}
				cout<<endl<<endl;

			}
		}

};
int main()
{
	BST random;
	cout<<"\tPrinting randomly genrated Binary Search Tree(BST)\n\n";
	srand((unsigned) time(0));
	int no_of_elements=5
	+(rand()%5);
	while(no_of_elements--)
	{
		random.insert(rand()%100);
 }
 cout<<"Inorder Display: ";
	random.display();
 random.printLevelWise();
	return 0;
}














