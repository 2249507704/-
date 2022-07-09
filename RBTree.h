#pragma once
#ifndef RBTREE_H
#include"RBTNode.h"
template<class T>
class RBTree
{

private:

	RBTNode<T>* mRoot; //根节点
public:
	RBTree();
	~RBTree();

	//前序遍历 根左右
	void preOrder();
	//中序遍历 左根右
	void inOrder();
	//后序遍历 左右根
	void posOrder();

	//递归实现 查找红黑树中键值为key的节点  要的是一个节点
	RBTNode<T>* search(T key);
	//递归实现 查找红黑树中键值为key的节点  要的是一个节点
	RBTNode<T>* iterativeSearch(T key);


	//查找最小节点：返回最小节点的键值
	T minimum();
	//查找最大节点：返回最大节点的键值
	T maximum();


	//找节点（x）的后继节点，即查找红黑树中数据值大于该节点的最小节点 
	RBTNode<T>* successor(RBTNode<T>* x);
	//找节点（x）的前驱节点，即查找红黑树中数据值大于该节点的最大节点 
	RBTNode<T>* predecessor(RBTNode<T>* x);


	//将节点（key为节点的键值）插入到红黑树中
	void insert(T key);

	//删除节点（ley为节点的键值）
	void remove(T key);

	//销毁红黑树
	void destory();

	//打印红黑树
	void Print();

private:
	//前序遍历 根左右
	void preOrder(RBTNode<T>* tree) const;
	//中序遍历 左根右
	void inOrder(RBTNode<T>* tree) const;
	//后序遍历 左右根
	void posOrder(RBTNode<T>* tree) const;

	//递归实现 查找红黑树中键值为key的节点  要的是一个节点
	RBTNode<T>* search(RBTNode<T>* x, T key) const;
	//递归实现 查找红黑树中键值为key的节点  要的是一个节点
	RBTNode<T>* iterativeSearch(RBTNode<T>* x, T key) const;


	//查找最小节点：返回最小节点的键值
	RBTNode<T>* minimum(RBTNode<T>* tree);
	//查找最大节点：返回最大节点的键值
	RBTNode<T>* maximum(RBTNode<T>* tree);

	//左旋
	void leftRotate(RBTNode<T>*& root, RBTNode<T>* x);
	//右旋
	void rightRotate(RBTNode<T>*& root, RBTNode<T>* y);

	//插入函数
	void insert(RBTNode<T>*& root, RBTNode<T>* node);

	//删除函数
	void remove(RBTNode<T>*& root, RBTNode<T>* node);

	//插入修正函数
	void insertFixUp(RBTNode<T>*& root, RBTNode<T>* node, RBTNode<T>* parent);

	//删除修正函数
	void removeFixUp(RBTNode<T>*& root, RBTNode<T>* node, RBTNode<T>* parent);

	//销毁红黑树
	void destory(RBTNode<T>*& tree);

	//打印红黑树
	void Print(RBTNode<T>*& tree, T key, int direction);

#define rb_parent(r) ((r)->parent)
#define rb_color(r) ((r)->color)
#define rb_is_red(r)    ((r)->color == RED)
#define rb_is_black(r)   ((r)->color == BLACK)

#define rb_set_black(r)   do{(r)->color == BLACK;} while (0)
#define rb_set_red(r)     do{(r)->color == RED;} while (0)

#define rb_set_parent(r,p) do{(r)->color = (p);} while (0)
#define rb_set_color(r,p) do{(r)->color = (c);} while (0)
};
#endif