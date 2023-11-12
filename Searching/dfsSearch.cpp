#include<iostream>
#include<stack>
using namespace std;

class node
{
	node* prev;
	int val;
	node* next;
	
	public:
		node(node* ptr=0,int a=0,node* ptr1=0)
		{
			prev=ptr;
			val=a;
			next=ptr1;
			return;
		}
		friend class DLL;
		friend class graph;
};

class DLL
{
	node* head;
	node* tail;
	
	public:
		DLL()
		{
			head = new node(0,0,tail);
			tail= new node(head,0,0);
			head->next = tail;
			return;
		}
		void add(node* ptr,int a);
		void insertattail(int a);
		void print();
		friend class graph;
};

void DLL::add(node* ptr,int a)
{
	node* current=ptr->prev;
	current->next=ptr->prev=new node(current,a,ptr);
	return;
}

void DLL::insertattail(int a)
{
	add(tail,a);
	return;
}

void DLL::print()
{
	if(head->next!=tail)
	{
		node* current=head->next;
		while(current!=tail)
		{
			cout<<current->val;
			current=current->next;
			if(current!=tail)
			{
				cout<<"->";
			}
		}
		cout<<endl;
	}
	return;
}

class graph{
	DLL *d;
	int v;
	
	public:
		graph()
		{
			
		}
		graph(int n)
		{
			d = new DLL[n];
			v=n;
			for(int i=0;i<n;i++)
			{
				d[i].insertattail(i+1);
			}
		}
		int vertices()
		{
			return v;
		}
		void inputnodes(int n);
		void display();
		void DFS(int s);
		void find_path(int a,int v);
		
};

void graph::inputnodes(int n){
	
	d = new DLL[n];
    v=n;
    for(int i=0;i<n;i++)
	{
		d[i].insertattail(i+1);
	}
	int e;
	cout<<"Enter the number of edges in the Graph: ";
	cin>>e;
	for(int i=0;i<e;i++)
	{
		cout<<"Enter both vertices having "<<i+1<<"st edge in between: ";
		int a,b;
		cin>>a>>b;
		if(a<=n&&b<=n)
		{
		  d[a-1].insertattail(b);
		  d[b-1].insertattail(a);
    	}
    	else{
    		cout<<"Input node not exist.\n";
    		i--;
		}
	}
}

void graph::display(){
	cout<<endl;
	for(int i=0;i<v;i++)
	{
		d[i].print();		
	}
}

void graph::DFS(int s)
{
	stack<int> q;
	bool discovered[vertices()];
	int parent[vertices()];
	int distance[vertices()];
	for(int i=0;i<vertices();i++)
	{
		discovered[i]= false;
		parent[i]=0;
		distance[i]=-1;
	}
	distance[s-1]=0;
	q.push(s);
	int u;
	while(q.empty()!=true)
	{
		u = q.top();
		q.pop();
		if(!discovered[u-1])
		{
			discovered[u-1]=true;
			node* current = d[u-1].head->next->next;
		    for(;current!=d[u-1].tail;current = current->next)
		    {
		    	if(!discovered[(current->val)-1])
		    	{
		    		q.push((current->val));
		    		parent[(current->val)-1] = u;
				    distance[(current->val)-1]=distance[u-1]+1;
				}
		    }
		}
	}
	cout<<"\nNode\tDiscovered\tParent\tDistance\n"
	    <<"------------------------------------------------------------------------------\n";
	for(int i=0;i<vertices();i++)
	{
		cout<<i+1<<"\t"<<discovered[i]<<"\t\t"
		    <<parent[i]<<"\t\t"<<distance[i]<<endl;
	}
	
}

void graph::find_path(int a,int v)
{
	stack<int> q;
	bool discovered[vertices()];
	int parent[vertices()];
	int distance[vertices()];
	for(int i=0;i<vertices();i++)
	{
		discovered[i]= false;
		parent[i]=0;
		distance[i]=-1;
	}
	distance[a-1]=0;
	q.push(a);
	int u;
    bool flag=false;
	while(q.empty()!=true)
	{
		u = q.top();
		q.pop();
		if(!discovered[u-1])
		{
			discovered[u-1]=true;
			if(u==v)
			{
				flag=true;
			}
			node* current = d[u-1].head->next->next;
		    for(;current!=d[u-1].tail;current = current->next)
		    {
		    	if(!discovered[(current->val)-1])
		    	{
		    		q.push((current->val));
		    		parent[(current->val)-1] = u;
				    distance[(current->val)-1]=distance[u-1]+1;
				}
		    }
		}
	}
	if(flag)
	{
		cout<<"The path is: "<<v;
		for(int i=v-1;distance[i];)
		{
			cout<<"-->"<<parent[i];
			i=parent[i]-1;			
	    }
	}
	else
	{
		cout<<"There is no path between the given node....";
	}	
	
}

int main()
{
    int ch,n;
    graph g;
    cout<<"....................................DFS Algorithm for undirected graph"
	    <<"....................................\n";
    cout<<"Choices: \n1.Input\n2.Run DFS\n3.Find Path between vertices"
    	    <<"\n4.Exit\n";
    do{
    	cout<<"\nEnter your choice: ";
    	cin>>ch;
    	switch(ch)
    	{
    		case 1:
    			cout<<"Input\n";
	            cout<<"Enter the number of vertices in the Graph: ";
	            cin>>n;
	            g.inputnodes(n);
	            cout<<"The input Graph is: ";
	            g.display();
    			break;
    		case 2:
    			cout<<"Run DFS\n";
    			cout<<"Enter the node for DFS run: ";
	            cin>>n;
	            g.DFS(n);
    			break;
    		case 3:
    			cout<<"Path between vertices\n";
    			cout<<"Enter the starting node: ";
	            cin>>n;
	            int v;
	            cout<<"Enter the ending node: ";
	            cin>>v;
	            g.find_path(v,n);
    			break;
    		case 4:
    			cout<<"Exiting...";
    			break;
    		default: 
    		    cout<<"Enter Valid choice.\n"; 		
		}
	}while(ch!=4);
		
}