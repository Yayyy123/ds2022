#include <iostream>
#include "DoubleLinkedList.h"
using namespace std;



int main()
{
	DoublyLinkedList obj;
	int option;
	int key1, k1, data1;
	do
	{
		cout << "\n 何种运作方式你需要执行？ 选择一下选项.输入 0 退出." << endl;
		cout << "1.添加Node()" << endl;
		cout << "2.添加Node在首位()" << endl;
		cout << "3.在特定的节点后添加Node()" << endl;
		cout << "4.删除Node()by Key" << endl;
		cout << "5.更新Node()by Key" << endl;
		cout << "6.print()" << endl;
		cout << "7.Clear Screen" << endl;

		cin >> option;
		Node* n1 = new Node();


		switch (option)
		{
			case 0:
				break;
			case 1:
				cout << "正常添加Node \nEnter Key和data让note可以添加" << endl;
				cin >> key1;
				cin >> data1;
				n1->key = key1;
				n1->data = data1;
				obj.appendNode(n1);
				break;

			case 2:
				cout << "添加为首位Node \nEnter Key & data 你要添加的Node" << endl;
				cin >> key1;
				cin >> data1;
				n1->key = key1;
				n1->data = data1;
				obj.prependNode(n1);
				break;

			case 3:
				cout << "添加Node在之后 \nEnter key 您想要插入此新节点的现有节点的键:" << endl;
				cin >> k1;
				cout << "添加第一个Node的key and data" << endl;
				cin >> key1;
				cin >> data1;
				n1->key = key1;
				n1->data = data1;

				obj.insertNodeAfter(k1, n1);
				break;


			case 4:

				cout << "删除node -\nEnter key 你要删除的Node:" << endl;
				cin >> k1;
				obj.deleteNodeByKey(k1);

			case 5:
				cout << "更新note - \nEnter key 要更新的数据" << endl;
				cin >> key1;
				cin >> data1;
				obj.updateNodeByKey(key1, data1);

				break;
			case 6:
				obj.printList();

				break;
			case 7:
				system("cls");
				break;
			default:
				cout << "输入编号" << endl;
			}

	} while (option != 0);

	return 0;

	{

	}

}



