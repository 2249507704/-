#include"RBTNode.h"
template<class T>
//实现要把模板类
RBTNode<T>::RBTNode(T value, RBTColor c, RBTNode* p, RBTNode* l, RBTNode* r) :
	key(value), color(c), parent(p), left(l), right(r) {

}
template <class T>
RBTNode<T>::~RBTNode(void)
{

}