#include "stdafx.h"
#include<vector>
#include<string>
#include<iostream>
#include<sstream>
#include<memory>
using namespace std;

class point
{
public:
	point(int num) :value(num){}
public:
	int value;
	vector<shared_ptr<point>> child;
};

class tree
{
public:
	shared_ptr<point> findpoint(int num);
	void printtree();
private:
	shared_ptr<point> find(shared_ptr<point> tmp, int num);
	void printpoint(shared_ptr<point> tmp, int lay);
public:
	shared_ptr<point> root;
	vector<vector<int>> printarry;
};

shared_ptr<point> tree::findpoint(int num)
{
	return find(root,num);
}
shared_ptr<point> tree::find(shared_ptr<point> tmp, int num)
{
	if (!tmp)
		return NULL;
	if (num == tmp->value)
		return tmp;
	for each (shared_ptr<point> childptr in tmp->child)
	{
		return find(childptr, num);
	}
	return NULL;
}
void tree::printtree()
{
	printpoint(root,0);
	for each (vector<int> varvector in printarry)
	{
		for each(int var in varvector)
			cout << var << " ";
	}

}
void tree::printpoint(shared_ptr<point> tmp,int lay)
{
	try
	{
		printarry.at(lay).push_back(tmp->value);
	}
	catch (...)
	{
		printarry.push_back(vector<int>());
		printarry.at(lay).push_back(tmp->value);
	}
	for each (shared_ptr<point> pointptr in tmp->child)
	{
		printpoint(pointptr,lay+1);
	}
	
}



int _tmain(int argc, _TCHAR* argv[])
{
	tree tree;
	string str;
	int num;
	shared_ptr<point> tmp;

	while (getline(cin, str))
	{
		if (str.empty()) break;
		stringstream strm(str);
		strm >> num;
		if (!tree.findpoint(num))
		{
			tree.root = make_shared<point>(num);
		}
		tmp = tree.findpoint(num);
		
		while (strm >> num)
		{
			tmp->child.push_back(make_shared<point>(num));
		}
	}

	tree.printtree();

	num = 0;
	return 0;
}
