#include<iostream>
using namespace std;

template<typename T>
class rb_tree{
	struct node{
		bool is_red;
		node*left,*right,*parent;
		T data;
	};
	node sentinal{.is_red=true};
	node *root{};
public:
	void insert(const T new_data);
};

template<typename T>
void rb_tree<T>::insert(const T new_data){
	cout<<"inserting: "<<new_data<<endl;
	node* new_node=new node;
	new_node->data=new_data;
	new_node->left=new_node->right=&sentinal;
	if(root){
		node *y,*x=root;
		while(x!=&sentinal){
			y=x;
			cout<<(y->data)<<endl;
			if(x->data > new_data){
				x=x->left;
			}else{
				x=x->right;
			}
		}
		if(y->data > new_data){
			y->left=new_node;
		}else{
			y->right=new_node;
		}
		new_node->parent=y;
		new_node->is_red=true;
	}else{
		root=new_node;
		new_node->parent=&sentinal;
		new_node->is_red=false;
	}
}
