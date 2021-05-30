#include"red_black_tree_analyser.h"
#include<numeric>

int main(){
	rb_tree<int> tree;
	rb_analyser<int> analyser(tree);
	vector<int> list(20);
	iota(begin(list),end(list),1);
	for_each(begin(list),end(list),[&](int x){tree.insert(x);});
	analyser.print();
	cout<<"is tree valid? : "<<(analyser.is_valid()?"yes":"no")<<endl;
	cout<<"is 5 present? : "<<((tree.find(5))?"yes":"no")<<endl;
	cout<<"is 21 present? : "<<((tree.find(21))?"yes":"no")<<endl;
}
