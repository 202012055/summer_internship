#ifndef _RB_TREE_H
#define _RB_TREE_H
#include<iostream>
#include<algorithm>
#include<vector>
template<typename T> class rb_analyser;
using namespace std;

template<typename T>
class rb_tree{
public:
	struct node{
		bool is_red;
		node*left,*right,*parent;
		T data;
	};
	node sentinal{.is_red=false};
	node *root{};
	friend class rb_analyser<T>;
	void insert(const T new_data);
private:
	void insert_fixup(node* n);
	void rotate_left(node* n);
	void rotate_right(node* n);
};

template<typename T>
void rb_tree<T>::insert(const T new_data){
	//cout<<"inserting: "<<new_data<<endl;
	node* new_node=new node;
	new_node->data=new_data;
	new_node->left=new_node->right=&sentinal;
	new_node->is_red=true;
	if(root){
		node *y,*x=root;
		while(x!=&sentinal){
			y=x;
			//cout<<(y->data)<<endl;
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
	}else{
		root=new_node;
		new_node->parent=&sentinal;
	}
	insert_fixup(new_node);
}

template<typename T>
void rb_tree<T>::rotate_left(node* x){
	cout<<"rotate_left\n";
	node*y=x->right;
	x->right=y->left;
	if(y->left != &sentinal)y->left->parent=x;
	y->parent=x->parent;
	if(x->parent == &sentinal){
		root=y;
	}else if(x==x->parent->left){
		x->parent->left=y;
	}else{
		x->parent->right=y;
	}
	y->left=x;
	x->parent=y;

}
template<typename T>
void rb_tree<T>::rotate_right(node* x){
	cout<<"rotate_right\n";
	node*y=x->left;
	x->left=y->right;
	if(y->right != &sentinal)y->right->parent=x;
	y->parent=x->parent;
	if(x->parent == &sentinal){
		root=y;
	}else if(x==x->parent->right){
		x->parent->right=y;
	}else{
		x->parent->left=y;
	}
	y->right=x;
	x->parent=y;

}
template<typename T>
void rb_tree<T>::insert_fixup(node* n){
	cout<<"insert_fixup\n";
	while(n->parent->is_red){
		cout<<"current: "<<(n->data)<<endl;
		if(n->parent->parent->left==n->parent){ //parent is the left child
			cout<<"left child\n";
			if(n->parent->parent->right->is_red){
				cout<<"ripple up\n";
				n->parent->parent->right->is_red=false;
				n->parent->is_red=false;
				n->parent->parent->is_red=true;
				n=n->parent->parent;
			}else{
				if(n->parent->right==n){
					n=n->parent;
					rotate_left(n);
				}
				n->parent->is_red=false;
				n->parent->parent->is_red=true;
				rotate_right(n->parent->parent);
			}
		}else{
			cout<<"right child\n";
			if(n->parent->parent->left->is_red){
				cout<<"ripple up\n";
				n->parent->parent->left->is_red=false;
				n->parent->is_red=false;
				n->parent->parent->is_red=true;
				n=n->parent->parent;
			}else{
				if(n->parent->left==n){
					n=n->parent;
					rotate_right(n);
				}
				n->parent->is_red=false;
				n->parent->parent->is_red=true;
				rotate_left(n->parent->parent);
			}
		}
	}
	root->is_red=false;
}
#endif
