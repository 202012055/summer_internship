#include"red_black_tree_analyser.h"
#include<numeric>

int main(){
	rb_tree<int> tree;
	rb_analyser<int> analyser(tree);
	vector<int> list(20);
	iota(begin(list),end(list),1);
	random_shuffle(begin(list),end(list));
	for_each(begin(list),end(list),[&](int x){tree.insert(x);});
	analyser.print();
	cout<<analyser.is_valid()<<endl;
}
