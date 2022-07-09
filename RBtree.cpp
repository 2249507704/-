/*
* 红黑树是一种特殊的二叉查找树，任意一个节点所包含的键值，大于等于左孩子的键值，小于等于右孩子的键值
* 
* 
*/
#include"RBTree.h"
#include"RBTNode.h"

/*
*	构造函数
*/
template<class T>
RBTree<T>::RBTree() :mRoot(NULL)
{
	mRoot = NULL;
}

/*
*	析构函数
*/
template<class T>
RBTree<T>::~RBTree()
{
	destory();
}

/*
*	前序遍历红黑树 根左右
*/
template<class T>
void RBTree<T>::preOrder(RBTNode<T>* tree)const
{
	if (tree != NULL)
	{
		cout << tree->key << " ";
		preOrder(tree->left);
		preOrder(tree->right);
	}
}
template<class T>
void RBTree<T>::preOrder()
{
	preOrder(mRoot);
}

/*
*	中序遍历红黑树 左根右
*/
template<class T>
void RBTree<T>::inOrder(RBTNode<T>* tree)const
{
	if (tree != NULL)
	{
		cout << tree->key << " ";
		inOrder(tree->right);
	}
} 
template<class T>
void RBTree<T>::inOrder()
{
	inOrder(mRoot);
}
/*
*	后序遍历红黑树 左右根
*/
template<class T>
void RBTree<T>::posOrder(RBTNode<T>* tree)const
{
	if (tree != NULL)
	{
		posOrder(tree->left);
		posOrder(tree->right);
		cout << tree->key << " ";
		
		
	}
}
template<class T>
void RBTree<T>::posOrder()
{
	posOrder(mRoot);
}

/*
*	递归实现 查找红黑树中键值为key的节点  要的是一个节点
*/

template<class T>
RBTNode<T>* RBTree<T>::search(RBTNode<T>* x, T key) const
{
	if (x == NULL || x->left, key)
		return x;
	if (key < x->key)
		return search(x->left, key);
	else
		return search(x->right, key);
}
template<class T>
RBTNode<T>* RBTree<T>::search(T key)
{
	search(mRoot, key);
}

/*
*	非递归实现 查找红黑树中键值为key的节点  要的是一个节点
*/

template<class T>
RBTNode<T>* RBTree<T>::iterativeSearch(RBTNode<T>* x, T key) const
{
	//红黑树的根的左节点小于根节点小于右节点
	while ((x == NULL) && (x->key) != key)
	{
		if (key < x->key)
			x = x->key;
		else
			x = x->right;
	}
	return x; //直接相等
}
template<class T>
RBTNode<T>* RBTree<T>::iterativeSearch(T key)
{
	iterativeSearch(mRoot, key);
}

/*
*	查找最小节点：返回tree为根节点的红黑树的最小节点
*/
template<class T>
RBTNode<T>* RBTree<T>::minimum(RBTNode<T>* tree)
{
	if (tree == NULL)
		return NULL;
	while (tree->left != NULL)
		tree = tree->left;
	return tree;
}
template<class T>
T RBTree<T>::minimum()//T RBTree<T>*p::minimum()
{
	RBTree<T>* p = minimum(mRoot);
	if (p != NULL)
		return p->key;

	return (T)NULL;
}

/*
*	查找最大节点：返回tree为根节点的红黑树的最小节点
*/
template<class T>
RBTNode<T>* RBTree<T>::maximum(RBTNode<T>* tree)
{
	if (tree == NULL)
		return NULL;
	while (tree->right != NULL)
		tree = tree->right;
	return tree;
}
template<class T>
T RBTree<T>::maximum()//T RBTree<T>*p::minimum()
{
	RBTree<T>* p = maximum(mRoot);
	if (p != NULL)
		return p->key;

	return (T)NULL;
}

/*
*	找节点（x）的后继节点，即查找红黑树中数据值大于该节点的最小节点
*/
 template<class T>
 RBTNode<T>* RBTree<T>::successor(RBTNode<T>* x)
 {
	 //如果x存在右孩子，则x的后继节点为 以其右孩子为根的子树的最小节点
	 if (x->right != NULL)
		 return minimum(x->right);

	 /*
	 * 如果x没有右孩子 则x有以下几种可能性
	 * ·x是一个左孩子，则x的后继节点为他的父节点
	 * ·x是一个右孩子，则查找x的最低的父节点，并且该父节点要具有左孩子，找到的这个最低父节点就是x的后继节点
	 */
	 RBTNode<T>* y = x->parent; //节点y是x的父节点

	 while ((y!= NULL) && (x == y->right))
	 {
		 x = y;
		 y = y->parent;
	 }
	 return y;
 }	



 /*
 *	找节点（x）的前驱节点，即查找红黑树中数据值大于该节点的最大节点
 */
 template<class T>
 RBTNode<T>* RBTree<T>::predecessor(RBTNode<T>* x)
 {
	 //如果x存在左孩子，则x的前驱节点为 以其左孩子为根的子树的最大节点
	 if (x->right != NULL)
		 return minimum(x->right);

	 /*
	 * 如果x没有左孩子 则x有以下几种可能性
	 * ·x是一个右孩子，则x的后继节点为他的父节点
	 * ·x是一个左孩子，则查找x的最低的父节点，并且该父节点要具有右孩子，找到的这个最低父节点就是x的前驱节点
	 */
	 RBTNode<T>* y = x->parent; //节点y是x的父节点
	 while ((y != NULL) && (x == y->left))
	 {
		 x = y;
		 y = y->parent;
	 }
	 return y;
 }

 /*
 *	对红黑树的节点（x）进行左旋
 * 
 *	左旋示意图（对x节点进行左旋）
 *		px									px
 *	   /                                    /
 *    x                                    y
 *	 / \             ---->左旋  --->      / \
 * lx   y                                x  ry
 *     / \                              / \
 *	  ly  ry                           lx  ly
 */

 //以下就是对左旋的描述
template<class T>

void RBTree<T>::leftRotate(RBTNode<T>*& root, RBTNode<T>* x)
{
	//设计x的右孩子节点
	RBTNode<T>* y = x->right;

	//将y的左孩子设为x的右孩子 
	//如果y的左孩子非空，将x设为y的左孩子的父亲
	x->right = y->left;
	if (y->left != NULL)
	{
		y->left->parent = x;
	}

	//将x的父亲设置为y的父亲
	y->parent = x->parent;
	
	if (x->parent == NULL)
	{
		root = y;  //如果x的父节点为空 则 y为根节点
	}
	else
	{
		//如果x是他父亲节点的左孩子，则将y设置为x的父节点的左孩子
		if (x->parent->left == x)
			x->parent->left = y;
		else
			x->parent->right = y;
	}
	//将x设为y的左孩子
	y->left = x;
	//将x的父节点设为y
	x->parent = y;
}



/*
*	对红黑树的节点（x）进行右旋
*
*	右旋示意图（对y节点进行左旋）
*		py									py
*	   /                                    /
*     y                                    x
*	 / \             ---->右旋 --->       / \
*   x    ry                              lx  y
*  / \                                      / \
*lx  rx                                    rx  ry
*/
template<class T>

void RBTree<T>::rightRotate(RBTNode<T>*& root, RBTNode<T>* y)
{
	//设计x是当前节点的左孩子
	RBTNode<T>* x = y->left;

	//将x的右孩子设为y的左孩子
	//如果x的右孩子非空，将y设为x的右孩子的父亲
	y->left = x->right;
	if (x->right != NULL)
	{
		x->right->parent = y;
	}

	//将y的父亲设置为x的父亲
	x->parent = y->parent;

	if (y->parent == NULL)
	{
		root = x;  //如果y的父节点为空 则 x为根节点
	}
	else
	{
		//如果y是他父亲节点的右孩子，则将x设置为y的父节点的右孩子
		if (y->parent->right == y)
			y->parent->tight = x;
		else
			y->parent->left = x;
	}
	//将y设为x的右孩子
	x->right = y;
	//将y的父节点设为x
	y->parent = x;
}


/*
* 红黑树插入修正函数
* 
* 在向红黑树中插入节点之后树会失去平衡，此时再调用该函数
* 
* 目的是将它重新塑造成一颗新的红黑树
* 
* 参数说明
*	root   根
*	node   插入的节点
*/
template<class T>
void RBTree<T>::insertFixUp(RBTNode<T>*& root, RBTNode<T>* node,RBTNode<T>*parent)
{
	RBTNode<T>* gparent; //祖父节点

	//如果父节点存在 并且父节点的颜色是红色的
	while (parent = rb_parent(node) && rb_is_red(parent))
	{
		gparent = rb_parent(parent);

		//如果父节点是祖父节点的左孩子 那么叔叔节点就是右孩子了
		if (parent == gparent->left)
		{
			    //情况1 叔叔节点是红色
				RBTNode<T>* uncle = gparent->right;
				if (uncle && rb_is_red(uncle))
				{
					rb_set_black(uncle);
					rb_set_black(parent);
					rb_set_red(gparent);
					node = gparent;
					continue;
				}

			   //情况2 叔叔节点是黑色 并且当前节点是右孩子
				if (parent->right == node)
				{

					RBTNode<T>* tem;
					leftRotate(root, parent);
					tem = parent;
					parent = node;
					node = tem;
				}

			//情况3 叔叔节点是黑色 并且当前节点是左孩子
				{
					rb_set_black(parent);
					rb_set_red(gparent);
					rightRotate(root, parent);
				}
		}
		else//如果父节点是祖父节点的右孩子
		{
			//情况1 叔叔节点是红色
			RBTNode<T>* uncle = gparent->left;
			if (uncle && rb_is_red(uncle))
			{
				rb_set_black(uncle);
				rb_set_black(parent);
				rb_set_red(gparent);
				node = gparent;
				continue;
			}

			//情况2 叔叔节点是黑色 并且当前节点是左孩子
			if (parent->left == node)
			{

				RBTNode<T>* tem;
				leftRotate(root, parent);
				tem = parent;
				parent = node;
				node = tem;
			}

			//情况3 叔叔节点是黑色 并且当前节点是右孩子
			{
				rb_set_black(parent);
				rb_set_red(gparent);
				leftRotate(root, parent);
			}
		}

	}
	//将根节点设为黑色
	rb_set_black(root);
}


/*
*	将节点插入到红黑树中
*	root 红黑树的根节点
*	node 插入的节点
*/
template<class T>
void RBTree<T>::insert(RBTNode<T>*& root, RBTNode<T>* node)
{
	RBTNode<T>* y = NULL;
	RBTNode<T>* x = root;

	//将红黑树当成一个二叉查找树，将节点添加进去
	while (x != NULL)
	{
		y = x;
		if (node->key < y->key)
		{
			x->left = node;
		}
		else
			x->right = node;
	}


	node->parent = y;
	if (y != NULL)
	{
		if (node->key < y->key)
		{
			y->left = node;
		}
		else
			y->right = node;

	}
	else
		root = node;

	//设置节点的颜色为红色
	node->color = RED;
	
	//将他重新修正为一个红黑树
	insertFixUp(root, node);

}


/*
*	将节点KEY为键值插入到红黑树中
*	
*	key 插入的节点键值
*/
template<class T>
void RBTree<T>::insert(T key)
{
	RBTNode<T>* z = NULL;
	//如果新建节点失败 则返回
	if ((z = new RBTNode<T>(key, BLACK, NULL, NULL, NULL)) == NULL)
		return;
	insert(key);
}

/*
*	红黑树删除修正函数
*	在红黑树中删除节点后要给他变回一个新的红黑树
*	root 根节点
*	node 待修正的节点
*/
template<class T>
void RBTree<T>::removeFixUp(RBTNode<T>*& root, RBTNode<T>* node, RBTNode<T>* parent)
{
	RBTNode<T>* other;
	while (!node || rb_is_black(node) && node != root)
	{
		if (parent->left == node)
		{
			other = parent->right;
			if (rb_is_red(other))
			{
				//·x的兄弟是红色的
				rb_set_black(other);
				rb_set_red(parent);
				leftRotate(root, parent);
				other = parent->right;
			}
			if (!other->left || rb_is_black(other->left) && (!other->right||rb_is_black(other->right)))
			{
				//·x的兄弟是黑色的 并且两个孩子也是黑色
				rb_set_red(other);
				node = parent;
				parent = rb_parent(node);
			}
			else
			{
				if(!other->right || rb_is_black(other->right))
				{
					rb_set_black(other->left);
					rb_is_red(other);
					rightRotate(root, other);
					other = parent->right;
					//·x的兄弟是黑色的 并且左孩子是红色 右孩子是任意色
					rb_set_color(other, rb_color(parent));
					rb_set_black(parent);
					rb_set_black(other->right);
					leftRotate(root, parent);
					node = root;
					break;
				}
			}
			else
			{
				other = parent->left;
				if (rb_is_red(other))
				{
					//·x的兄弟是红色的
					rb_set_black(other);
					rb_set_red(parent);
					leftRotate(root, parent);
					other = parent->left;
				}
				if ((!other->left || rb_is_black(other->left))&&(!other -> right ||rb_is_black(othre->right)))
				{
					//·x的兄弟是黑色的 并且两个孩子也是黑色
						rb_set_red(other);
						node = parent;
						parent = rb_parent(node);
				}
				else
				{
					if (!other->left || rb_is_black(other->left))
					{
						//·x的兄弟是黑色的 并且左孩子是红色 右孩子是黑色
						rb_set_black(other->right);
						rb_set_red(other);
						leftRotate(root, parent);
						other = parent->left;
					}

					
					//·x的兄弟是黑色的 并且右孩子是红色 左孩子是任意颜色
					rb_set_color(other, rb_color(parent));
					rb_set_black(parent);
					rb_set_black(other->left);
					leftRotate(root, parent);
					node = root;
					break;
					

				}

			}
		}
	}
	if (node)
		rb_set_black(node);
}


/*
* 删除节点，并返回被删除的节点
*/
template<class T>
void RBTree<T>::remove(RBTNode<T>*& root, RBTNode<T>* node)
{
	RBTNode<T>* child, * parent;
	RBTColor color;
	//被删除节点“左右孩子不为空”
	if ((node->left != NULL) && (node->right != NULL))
	{
		//被删除节点的后继节点
		//用它来取代被删除节点的位置，然后在将被删除节点去掉
		RBTNode<T>* replace = node;

		//获取后继节点
		replace = replace->right;
		while (replace->left != NULL)
			replace = replace->left;

		//node节点不是根节点 只有根节点不存在父节点
		if (rb_parent(node))
		{
			if (rb_parent(node)->left == node)
			{
				rb_parent(node)->left = replace;
			}
			else
				rb_parent(node)->right = replace;
		}
		else
		{
			//node不是根节点 则更新新节点
			root = replace;

			//child是取代节点的右孩子 也是需要调整的节点
			//取代节点肯定不存在左孩子，因为他是一个后继节点
			child = replace->right;
			parent = rb_parent(replace);
			//保存取代节点的颜色
			color = rb_color(replace);

			//被删除节点是他后继节点的父节点
			if (parent == node)
			{
				parent = replace;
			}
			else
			{
				//child不为空
				if (child)
					rb_set_parent(child, parent);
				parent->left = child;

				replace->right = node->right;
				rb_set_parent(node->right, replace);
			}
			replace->parent = node->parent;
			replace->color = node->color;
			replace->left = node->left;
			node->left->parent = replace;

			if (color == BLACK)
				removeFixUp(root, child, parent);
			delete node;
			return;
		}
			
			
	}
	if (node->left != NULL)
		child->node->left;
	else
		child = node->left;

	parent = node->parent;
	//保存取代节点的颜色
	color = node->color;
	if (child)
		child->parent = parent;

	//node节点不是根节点
	if (parent)
	{
		if (parent->left == node)
			parent->left = child;
		else
			parent->right = child;
	}
	else
		root = child;

	if (color == BLACK)
	{
		removeFixUp(root, child, parent);
		delete node;
	}
}

/*
*	删除键值为key的节点
*/
template<class T>
void RBTree<T>::remove(T key)
{
	RBTNode<T>* node;
	//查找key对应的节点，找到的话就删除节点
	if ((node = search(mRoot, key)) != NULL)
		remove(mRoot, node);
}

/*
*  销毁红黑树
*/
template<class T>
void RBTree<T>::destory(RBTNode<T>*& tree)
{
	if (tree == NULL)
		return;
	if (tree->left != NULL)
		return destory(tree->left);
	if (tree->right != NULL)
		return destory(tree->right);

	delete tree;
	tree = NULL;
}

template<class T>
void RBTree<T>::destory()
{
	destory(mRoot);
}
/*
* 打印红黑树
* key -- 键值
* direction --- 0 该节点是根节点
*				1 该节点是他父节点的左孩子
*				2 该节点是他父节点的右孩子
*/
template<class T>
void RBTree<T>::Print(RBTNode<T>*& tree, T key, int direction)
{
	if (tree != NULL)
	{
		if (direction == 0) //tree是根节点
		{
			cout << setw(2) << tree->key << "(B) is root" << endl;
		}
		else
			cout << setw(2) << tree->key << (rb_is_red(tree) ? "(R)" : "(B)") << "is" << setw(2) <<
			key << "s" << setw(12) << (direction == 1 ? "right child" : "left child" << endl;

		Print(tree->left, tree->key, -1);
		Print(tree->right, tree->key, 1);
	}
}
template<class T>
void RBTree<T>::Print()
{
	if (mRoot != NULL)
		Print(mRoot, mRoot->key, 0);
}

