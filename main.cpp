#include"RBTNode.h"
#include"RBTree.h"
int main()
{
	int a[] = { 10,40,30,60,90,70,20,50,80 };
	int check_insert = 0; //插入开关 1打开 0关闭
	int check_remove = 0; //删除
	int i;
	int ilen = (sizeof(a)) / (sizeof(a[0]));
	RBTree<int>* tree = new RBTree<int>();

	cout << "原始数据：" << endl;
	for (i = 0; i < ilen; i++)
		cout << a[i] << " ";
	cout << endl;

	for (i = 0; i < ilen; i++)
	{
		tree->insert(a[i]);
		//插入打开
		if (check_insert)
		{
			cout << "添加节点：" << a[i] << endl;
			cout << "树的详细信息：" << endl;
			tree->Print();
			cout << endl;
		}
	}

	cout << "前序遍历：" << endl;
	tree->preOrder();
	cout << endl;
	cout << "中序遍历：" << endl;
	tree->inOrder();
	cout << endl;
	cout << "后序遍历：" << endl;
	tree->posOrder();
	cout << endl;

	cout << "最小值：" << tree->minimum() << endl;
	cout << "最大值：" << tree->maximum() << endl;
	cout << "树的详细信息：" << endl;
	tree->Print();
	cout << endl;

	//删除打开
	if (check_remove)
	{
		for (i = 0; i < ilen; i++)
		{
			tree->remove(a[i]);

			cout << "删除节点：" << a[i] << endl;
			cout << "树的详细信息：" << endl;
			tree->Print();
			cout << endl;
		}
	}


	//销毁红黑树
	tree->destory();
	system("pause");
	return 0;
}