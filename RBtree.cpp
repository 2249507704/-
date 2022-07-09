/*
* �������һ������Ķ��������������һ���ڵ��������ļ�ֵ�����ڵ������ӵļ�ֵ��С�ڵ����Һ��ӵļ�ֵ
* 
* 
*/
#include"RBTree.h"
#include"RBTNode.h"

/*
*	���캯��
*/
template<class T>
RBTree<T>::RBTree() :mRoot(NULL)
{
	mRoot = NULL;
}

/*
*	��������
*/
template<class T>
RBTree<T>::~RBTree()
{
	destory();
}

/*
*	ǰ���������� ������
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
*	������������ �����
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
*	������������ ���Ҹ�
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
*	�ݹ�ʵ�� ���Һ�����м�ֵΪkey�Ľڵ�  Ҫ����һ���ڵ�
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
*	�ǵݹ�ʵ�� ���Һ�����м�ֵΪkey�Ľڵ�  Ҫ����һ���ڵ�
*/

template<class T>
RBTNode<T>* RBTree<T>::iterativeSearch(RBTNode<T>* x, T key) const
{
	//������ĸ�����ڵ�С�ڸ��ڵ�С���ҽڵ�
	while ((x == NULL) && (x->key) != key)
	{
		if (key < x->key)
			x = x->key;
		else
			x = x->right;
	}
	return x; //ֱ�����
}
template<class T>
RBTNode<T>* RBTree<T>::iterativeSearch(T key)
{
	iterativeSearch(mRoot, key);
}

/*
*	������С�ڵ㣺����treeΪ���ڵ�ĺ��������С�ڵ�
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
*	�������ڵ㣺����treeΪ���ڵ�ĺ��������С�ڵ�
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
*	�ҽڵ㣨x���ĺ�̽ڵ㣬�����Һ����������ֵ���ڸýڵ����С�ڵ�
*/
 template<class T>
 RBTNode<T>* RBTree<T>::successor(RBTNode<T>* x)
 {
	 //���x�����Һ��ӣ���x�ĺ�̽ڵ�Ϊ �����Һ���Ϊ������������С�ڵ�
	 if (x->right != NULL)
		 return minimum(x->right);

	 /*
	 * ���xû���Һ��� ��x�����¼��ֿ�����
	 * ��x��һ�����ӣ���x�ĺ�̽ڵ�Ϊ���ĸ��ڵ�
	 * ��x��һ���Һ��ӣ������x����͵ĸ��ڵ㣬���Ҹø��ڵ�Ҫ�������ӣ��ҵ��������͸��ڵ����x�ĺ�̽ڵ�
	 */
	 RBTNode<T>* y = x->parent; //�ڵ�y��x�ĸ��ڵ�

	 while ((y!= NULL) && (x == y->right))
	 {
		 x = y;
		 y = y->parent;
	 }
	 return y;
 }	



 /*
 *	�ҽڵ㣨x����ǰ���ڵ㣬�����Һ����������ֵ���ڸýڵ�����ڵ�
 */
 template<class T>
 RBTNode<T>* RBTree<T>::predecessor(RBTNode<T>* x)
 {
	 //���x�������ӣ���x��ǰ���ڵ�Ϊ ��������Ϊ�������������ڵ�
	 if (x->right != NULL)
		 return minimum(x->right);

	 /*
	 * ���xû������ ��x�����¼��ֿ�����
	 * ��x��һ���Һ��ӣ���x�ĺ�̽ڵ�Ϊ���ĸ��ڵ�
	 * ��x��һ�����ӣ������x����͵ĸ��ڵ㣬���Ҹø��ڵ�Ҫ�����Һ��ӣ��ҵ��������͸��ڵ����x��ǰ���ڵ�
	 */
	 RBTNode<T>* y = x->parent; //�ڵ�y��x�ĸ��ڵ�
	 while ((y != NULL) && (x == y->left))
	 {
		 x = y;
		 y = y->parent;
	 }
	 return y;
 }

 /*
 *	�Ժ�����Ľڵ㣨x����������
 * 
 *	����ʾ��ͼ����x�ڵ����������
 *		px									px
 *	   /                                    /
 *    x                                    y
 *	 / \             ---->����  --->      / \
 * lx   y                                x  ry
 *     / \                              / \
 *	  ly  ry                           lx  ly
 */

 //���¾��Ƕ�����������
template<class T>

void RBTree<T>::leftRotate(RBTNode<T>*& root, RBTNode<T>* x)
{
	//���x���Һ��ӽڵ�
	RBTNode<T>* y = x->right;

	//��y��������Ϊx���Һ��� 
	//���y�����ӷǿգ���x��Ϊy�����ӵĸ���
	x->right = y->left;
	if (y->left != NULL)
	{
		y->left->parent = x;
	}

	//��x�ĸ�������Ϊy�ĸ���
	y->parent = x->parent;
	
	if (x->parent == NULL)
	{
		root = y;  //���x�ĸ��ڵ�Ϊ�� �� yΪ���ڵ�
	}
	else
	{
		//���x�������׽ڵ�����ӣ���y����Ϊx�ĸ��ڵ������
		if (x->parent->left == x)
			x->parent->left = y;
		else
			x->parent->right = y;
	}
	//��x��Ϊy������
	y->left = x;
	//��x�ĸ��ڵ���Ϊy
	x->parent = y;
}



/*
*	�Ժ�����Ľڵ㣨x����������
*
*	����ʾ��ͼ����y�ڵ����������
*		py									py
*	   /                                    /
*     y                                    x
*	 / \             ---->���� --->       / \
*   x    ry                              lx  y
*  / \                                      / \
*lx  rx                                    rx  ry
*/
template<class T>

void RBTree<T>::rightRotate(RBTNode<T>*& root, RBTNode<T>* y)
{
	//���x�ǵ�ǰ�ڵ������
	RBTNode<T>* x = y->left;

	//��x���Һ�����Ϊy������
	//���x���Һ��ӷǿգ���y��Ϊx���Һ��ӵĸ���
	y->left = x->right;
	if (x->right != NULL)
	{
		x->right->parent = y;
	}

	//��y�ĸ�������Ϊx�ĸ���
	x->parent = y->parent;

	if (y->parent == NULL)
	{
		root = x;  //���y�ĸ��ڵ�Ϊ�� �� xΪ���ڵ�
	}
	else
	{
		//���y�������׽ڵ���Һ��ӣ���x����Ϊy�ĸ��ڵ���Һ���
		if (y->parent->right == y)
			y->parent->tight = x;
		else
			y->parent->left = x;
	}
	//��y��Ϊx���Һ���
	x->right = y;
	//��y�ĸ��ڵ���Ϊx
	y->parent = x;
}


/*
* �����������������
* 
* ���������в���ڵ�֮������ʧȥƽ�⣬��ʱ�ٵ��øú���
* 
* Ŀ���ǽ������������һ���µĺ����
* 
* ����˵��
*	root   ��
*	node   ����Ľڵ�
*/
template<class T>
void RBTree<T>::insertFixUp(RBTNode<T>*& root, RBTNode<T>* node,RBTNode<T>*parent)
{
	RBTNode<T>* gparent; //�游�ڵ�

	//������ڵ���� ���Ҹ��ڵ����ɫ�Ǻ�ɫ��
	while (parent = rb_parent(node) && rb_is_red(parent))
	{
		gparent = rb_parent(parent);

		//������ڵ����游�ڵ������ ��ô����ڵ�����Һ�����
		if (parent == gparent->left)
		{
			    //���1 ����ڵ��Ǻ�ɫ
				RBTNode<T>* uncle = gparent->right;
				if (uncle && rb_is_red(uncle))
				{
					rb_set_black(uncle);
					rb_set_black(parent);
					rb_set_red(gparent);
					node = gparent;
					continue;
				}

			   //���2 ����ڵ��Ǻ�ɫ ���ҵ�ǰ�ڵ����Һ���
				if (parent->right == node)
				{

					RBTNode<T>* tem;
					leftRotate(root, parent);
					tem = parent;
					parent = node;
					node = tem;
				}

			//���3 ����ڵ��Ǻ�ɫ ���ҵ�ǰ�ڵ�������
				{
					rb_set_black(parent);
					rb_set_red(gparent);
					rightRotate(root, parent);
				}
		}
		else//������ڵ����游�ڵ���Һ���
		{
			//���1 ����ڵ��Ǻ�ɫ
			RBTNode<T>* uncle = gparent->left;
			if (uncle && rb_is_red(uncle))
			{
				rb_set_black(uncle);
				rb_set_black(parent);
				rb_set_red(gparent);
				node = gparent;
				continue;
			}

			//���2 ����ڵ��Ǻ�ɫ ���ҵ�ǰ�ڵ�������
			if (parent->left == node)
			{

				RBTNode<T>* tem;
				leftRotate(root, parent);
				tem = parent;
				parent = node;
				node = tem;
			}

			//���3 ����ڵ��Ǻ�ɫ ���ҵ�ǰ�ڵ����Һ���
			{
				rb_set_black(parent);
				rb_set_red(gparent);
				leftRotate(root, parent);
			}
		}

	}
	//�����ڵ���Ϊ��ɫ
	rb_set_black(root);
}


/*
*	���ڵ���뵽�������
*	root ������ĸ��ڵ�
*	node ����Ľڵ�
*/
template<class T>
void RBTree<T>::insert(RBTNode<T>*& root, RBTNode<T>* node)
{
	RBTNode<T>* y = NULL;
	RBTNode<T>* x = root;

	//�����������һ����������������ڵ���ӽ�ȥ
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

	//���ýڵ����ɫΪ��ɫ
	node->color = RED;
	
	//������������Ϊһ�������
	insertFixUp(root, node);

}


/*
*	���ڵ�KEYΪ��ֵ���뵽�������
*	
*	key ����Ľڵ��ֵ
*/
template<class T>
void RBTree<T>::insert(T key)
{
	RBTNode<T>* z = NULL;
	//����½��ڵ�ʧ�� �򷵻�
	if ((z = new RBTNode<T>(key, BLACK, NULL, NULL, NULL)) == NULL)
		return;
	insert(key);
}

/*
*	�����ɾ����������
*	�ں������ɾ���ڵ��Ҫ�������һ���µĺ����
*	root ���ڵ�
*	node �������Ľڵ�
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
				//��x���ֵ��Ǻ�ɫ��
				rb_set_black(other);
				rb_set_red(parent);
				leftRotate(root, parent);
				other = parent->right;
			}
			if (!other->left || rb_is_black(other->left) && (!other->right||rb_is_black(other->right)))
			{
				//��x���ֵ��Ǻ�ɫ�� ������������Ҳ�Ǻ�ɫ
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
					//��x���ֵ��Ǻ�ɫ�� ���������Ǻ�ɫ �Һ���������ɫ
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
					//��x���ֵ��Ǻ�ɫ��
					rb_set_black(other);
					rb_set_red(parent);
					leftRotate(root, parent);
					other = parent->left;
				}
				if ((!other->left || rb_is_black(other->left))&&(!other -> right ||rb_is_black(othre->right)))
				{
					//��x���ֵ��Ǻ�ɫ�� ������������Ҳ�Ǻ�ɫ
						rb_set_red(other);
						node = parent;
						parent = rb_parent(node);
				}
				else
				{
					if (!other->left || rb_is_black(other->left))
					{
						//��x���ֵ��Ǻ�ɫ�� ���������Ǻ�ɫ �Һ����Ǻ�ɫ
						rb_set_black(other->right);
						rb_set_red(other);
						leftRotate(root, parent);
						other = parent->left;
					}

					
					//��x���ֵ��Ǻ�ɫ�� �����Һ����Ǻ�ɫ ������������ɫ
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
* ɾ���ڵ㣬�����ر�ɾ���Ľڵ�
*/
template<class T>
void RBTree<T>::remove(RBTNode<T>*& root, RBTNode<T>* node)
{
	RBTNode<T>* child, * parent;
	RBTColor color;
	//��ɾ���ڵ㡰���Һ��Ӳ�Ϊ�ա�
	if ((node->left != NULL) && (node->right != NULL))
	{
		//��ɾ���ڵ�ĺ�̽ڵ�
		//������ȡ����ɾ���ڵ��λ�ã�Ȼ���ڽ���ɾ���ڵ�ȥ��
		RBTNode<T>* replace = node;

		//��ȡ��̽ڵ�
		replace = replace->right;
		while (replace->left != NULL)
			replace = replace->left;

		//node�ڵ㲻�Ǹ��ڵ� ֻ�и��ڵ㲻���ڸ��ڵ�
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
			//node���Ǹ��ڵ� ������½ڵ�
			root = replace;

			//child��ȡ���ڵ���Һ��� Ҳ����Ҫ�����Ľڵ�
			//ȡ���ڵ�϶����������ӣ���Ϊ����һ����̽ڵ�
			child = replace->right;
			parent = rb_parent(replace);
			//����ȡ���ڵ����ɫ
			color = rb_color(replace);

			//��ɾ���ڵ�������̽ڵ�ĸ��ڵ�
			if (parent == node)
			{
				parent = replace;
			}
			else
			{
				//child��Ϊ��
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
	//����ȡ���ڵ����ɫ
	color = node->color;
	if (child)
		child->parent = parent;

	//node�ڵ㲻�Ǹ��ڵ�
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
*	ɾ����ֵΪkey�Ľڵ�
*/
template<class T>
void RBTree<T>::remove(T key)
{
	RBTNode<T>* node;
	//����key��Ӧ�Ľڵ㣬�ҵ��Ļ���ɾ���ڵ�
	if ((node = search(mRoot, key)) != NULL)
		remove(mRoot, node);
}

/*
*  ���ٺ����
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
* ��ӡ�����
* key -- ��ֵ
* direction --- 0 �ýڵ��Ǹ��ڵ�
*				1 �ýڵ��������ڵ������
*				2 �ýڵ��������ڵ���Һ���
*/
template<class T>
void RBTree<T>::Print(RBTNode<T>*& tree, T key, int direction)
{
	if (tree != NULL)
	{
		if (direction == 0) //tree�Ǹ��ڵ�
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

