#pragma once
#ifndef RBTREE_H
#include"RBTNode.h"
template<class T>
class RBTree
{

private:

	RBTNode<T>* mRoot; //���ڵ�
public:
	RBTree();
	~RBTree();

	//ǰ����� ������
	void preOrder();
	//������� �����
	void inOrder();
	//������� ���Ҹ�
	void posOrder();

	//�ݹ�ʵ�� ���Һ�����м�ֵΪkey�Ľڵ�  Ҫ����һ���ڵ�
	RBTNode<T>* search(T key);
	//�ݹ�ʵ�� ���Һ�����м�ֵΪkey�Ľڵ�  Ҫ����һ���ڵ�
	RBTNode<T>* iterativeSearch(T key);


	//������С�ڵ㣺������С�ڵ�ļ�ֵ
	T minimum();
	//�������ڵ㣺�������ڵ�ļ�ֵ
	T maximum();


	//�ҽڵ㣨x���ĺ�̽ڵ㣬�����Һ����������ֵ���ڸýڵ����С�ڵ� 
	RBTNode<T>* successor(RBTNode<T>* x);
	//�ҽڵ㣨x����ǰ���ڵ㣬�����Һ����������ֵ���ڸýڵ�����ڵ� 
	RBTNode<T>* predecessor(RBTNode<T>* x);


	//���ڵ㣨keyΪ�ڵ�ļ�ֵ�����뵽�������
	void insert(T key);

	//ɾ���ڵ㣨leyΪ�ڵ�ļ�ֵ��
	void remove(T key);

	//���ٺ����
	void destory();

	//��ӡ�����
	void Print();

private:
	//ǰ����� ������
	void preOrder(RBTNode<T>* tree) const;
	//������� �����
	void inOrder(RBTNode<T>* tree) const;
	//������� ���Ҹ�
	void posOrder(RBTNode<T>* tree) const;

	//�ݹ�ʵ�� ���Һ�����м�ֵΪkey�Ľڵ�  Ҫ����һ���ڵ�
	RBTNode<T>* search(RBTNode<T>* x, T key) const;
	//�ݹ�ʵ�� ���Һ�����м�ֵΪkey�Ľڵ�  Ҫ����һ���ڵ�
	RBTNode<T>* iterativeSearch(RBTNode<T>* x, T key) const;


	//������С�ڵ㣺������С�ڵ�ļ�ֵ
	RBTNode<T>* minimum(RBTNode<T>* tree);
	//�������ڵ㣺�������ڵ�ļ�ֵ
	RBTNode<T>* maximum(RBTNode<T>* tree);

	//����
	void leftRotate(RBTNode<T>*& root, RBTNode<T>* x);
	//����
	void rightRotate(RBTNode<T>*& root, RBTNode<T>* y);

	//���뺯��
	void insert(RBTNode<T>*& root, RBTNode<T>* node);

	//ɾ������
	void remove(RBTNode<T>*& root, RBTNode<T>* node);

	//������������
	void insertFixUp(RBTNode<T>*& root, RBTNode<T>* node, RBTNode<T>* parent);

	//ɾ����������
	void removeFixUp(RBTNode<T>*& root, RBTNode<T>* node, RBTNode<T>* parent);

	//���ٺ����
	void destory(RBTNode<T>*& tree);

	//��ӡ�����
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