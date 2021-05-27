#ifndef _RB_ANALYSER_H
#define _RB_ANALYSER_H
#include"red_black_tree.h"
template<typename T>
class rb_analyser{
	rb_tree<T> &tree;
public:
	rb_analyser(rb_tree<T>& t):tree(t){}
	void print(){print_aux(tree.root,"");cout<<endl;}
	void print_aux(typename rb_tree<T>::node* n,string prefix);
};

template<typename T>
void rb_analyser<T>::print_aux(typename rb_tree<T>::node* n,string prefix){
	static const int rowspace=1,colspace=10;
	int len=to_string(n->data).size();
	for(int i=colspace;i>len;i--)cout<<'_';
	if(n->is_red)cout<<"\e[41m"<<(n->data)<<"\e[0m";
	else cout<<(n->data);
	string new_prefix(colspace,' ');
	prefix+=new_prefix;
	if(n->left!=&(tree.sentinal))prefix[prefix.size()-1]='|';
	if(n->right!=&(tree.sentinal)){
		print_aux(n->right,prefix);
	}
	if(n->left!=&(tree.sentinal)){
		for(int i=0;i<=rowspace;i++)cout<<endl<<prefix;
		prefix[prefix.size()-1]=' ';
		print_aux(n->left,prefix);
	}
}
#endif
