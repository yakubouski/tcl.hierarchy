#include <cstdio>
#include <string>
#include "include/chierarchylist.h"

struct node {
	int type;
	std::string name;
	std::string uid;

	node(const std::string& _name = {}, const std::string& _uid = {}, int _type = 0)
		: type(_type),name(_name), uid(_uid)
	{
		;
	}
};

int main()
{
	chierarchy_list<std::string, node> list;

	auto it = list.emplace_branch("Test 1");

	it = it.emplace_branch("Sub Test 1.1");

	auto& v = it.emplace_leaf("Data 1","1",1);

	it = it.emplace_branch("Sub Test 1.2");

	it = list.emplace_branch("Test 2");

	it = it.emplace_branch("Sub Test 2.2");

	it.emplace_branch("Sub Test 2.2.1");
	it.emplace_branch("Sub Test 2.2.2");
	it.emplace_branch("Sub Test 2.2.3");

	for (auto&& ti : list) {
		printf("%*s%s\n", ti.path.size()*4, "", ti.branch.c_str());
	}
    return 0;
}