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
		cout << "\n ����������ʽ����Ҫִ�У� ѡ��һ��ѡ��.���� 0 �˳�." << endl;
		cout << "1.���Node()" << endl;
		cout << "2.���Node����λ()" << endl;
		cout << "3.���ض��Ľڵ�����Node()" << endl;
		cout << "4.ɾ��Node()by Key" << endl;
		cout << "5.����Node()by Key" << endl;
		cout << "6.print()" << endl;
		cout << "7.Clear Screen" << endl;

		cin >> option;
		Node* n1 = new Node();


		switch (option)
		{
			case 0:
				break;
			case 1:
				cout << "�������Node \nEnter Key��data��note�������" << endl;
				cin >> key1;
				cin >> data1;
				n1->key = key1;
				n1->data = data1;
				obj.appendNode(n1);
				break;

			case 2:
				cout << "���Ϊ��λNode \nEnter Key & data ��Ҫ��ӵ�Node" << endl;
				cin >> key1;
				cin >> data1;
				n1->key = key1;
				n1->data = data1;
				obj.prependNode(n1);
				break;

			case 3:
				cout << "���Node��֮�� \nEnter key ����Ҫ������½ڵ�����нڵ�ļ�:" << endl;
				cin >> k1;
				cout << "��ӵ�һ��Node��key and data" << endl;
				cin >> key1;
				cin >> data1;
				n1->key = key1;
				n1->data = data1;

				obj.insertNodeAfter(k1, n1);
				break;


			case 4:

				cout << "ɾ��node -\nEnter key ��Ҫɾ����Node:" << endl;
				cin >> k1;
				obj.deleteNodeByKey(k1);

			case 5:
				cout << "����note - \nEnter key Ҫ���µ�����" << endl;
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
				cout << "������" << endl;
			}

	} while (option != 0);

	return 0;

	{

	}

}



