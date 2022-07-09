#include"RBTNode.h"
#include"RBTree.h"
int main()
{
	int a[] = { 10,40,30,60,90,70,20,50,80 };
	int check_insert = 0; //���뿪�� 1�� 0�ر�
	int check_remove = 0; //ɾ��
	int i;
	int ilen = (sizeof(a)) / (sizeof(a[0]));
	RBTree<int>* tree = new RBTree<int>();

	cout << "ԭʼ���ݣ�" << endl;
	for (i = 0; i < ilen; i++)
		cout << a[i] << " ";
	cout << endl;

	for (i = 0; i < ilen; i++)
	{
		tree->insert(a[i]);
		//�����
		if (check_insert)
		{
			cout << "��ӽڵ㣺" << a[i] << endl;
			cout << "������ϸ��Ϣ��" << endl;
			tree->Print();
			cout << endl;
		}
	}

	cout << "ǰ�������" << endl;
	tree->preOrder();
	cout << endl;
	cout << "���������" << endl;
	tree->inOrder();
	cout << endl;
	cout << "���������" << endl;
	tree->posOrder();
	cout << endl;

	cout << "��Сֵ��" << tree->minimum() << endl;
	cout << "���ֵ��" << tree->maximum() << endl;
	cout << "������ϸ��Ϣ��" << endl;
	tree->Print();
	cout << endl;

	//ɾ����
	if (check_remove)
	{
		for (i = 0; i < ilen; i++)
		{
			tree->remove(a[i]);

			cout << "ɾ���ڵ㣺" << a[i] << endl;
			cout << "������ϸ��Ϣ��" << endl;
			tree->Print();
			cout << endl;
		}
	}


	//���ٺ����
	tree->destory();
	system("pause");
	return 0;
}