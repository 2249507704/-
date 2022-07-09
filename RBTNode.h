#pragma once
#ifndef RBTNODE_H
#include<iostream>
using namespace std;

//��������  enum��һ��ö������ 
enum RBTColor { RED, BLACK };

//������ڵ�
template<class T>
class RBTNode
{
public:
	RBTColor color; //��ɫ
	T key;  //�ؼ���(��ֵ)
	RBTNode* left;  //����
	RBTNode* right; //�Һ���
	RBTNode* parent; //���ڵ� 

	//���캯�� �����б��ʼ��
	RBTNode(T value, RBTColor c, RBTNode* p, RBTNode* l, RBTNode* r);
	//����
	~RBTNode(void);

};
#endif
