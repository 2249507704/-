#pragma once
#ifndef RBTNODE_H
#include<iostream>
using namespace std;

//基本定义  enum是一个枚举类型 
enum RBTColor { RED, BLACK };

//红黑树节点
template<class T>
class RBTNode
{
public:
	RBTColor color; //颜色
	T key;  //关键字(键值)
	RBTNode* left;  //左孩子
	RBTNode* right; //右孩子
	RBTNode* parent; //父节点 

	//构造函数 参数列表初始化
	RBTNode(T value, RBTColor c, RBTNode* p, RBTNode* l, RBTNode* r);
	//析构
	~RBTNode(void);

};
#endif
