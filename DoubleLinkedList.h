#include <iostream>
using namespace std;
class Node {

	public:
		int key;
		int data;
		Node* next;
		Node* previous;

	Node()
	{
		key = 0;
		data = 0;
		next = NULL;
		previous = NULL;
	}
	Node(int k, int d)
	{
		key = k;
		data = d;
	}
};

class DoublyLinkedList {

public:
	Node* head;

	DoublyLinkedList()
	{
		head = NULL;
	}
	DoublyLinkedList(Node* n)
	{
		head = n;
	}
	//1. ���node�Ƿ����

	Node* nodeExists(int k)
	{
		Node* temp = NULL;
		Node* ptr = head;  //��������head����

		while (ptr != NULL)
		{
			if (ptr->key == k)
			{
				temp = ptr;
			}
			ptr = ptr->next; //�����ݴ�����һ������
		}

		return temp;
	}

	//2. ��Node��ӵ��б��� 

	void appendNode(Node* n)
	{
		if (nodeExists(n->key) != NULL)
		{
			cout << "Node �Ѿ��������Ѿ���ֵ : " << n->key << ". ����������Node�ò�ͬ�ĸ�ֵ" << endl;
		}
		else
		{
			if (head == NULL)
			{
				head = n;
				cout << "Node ���Ϊ Head Node" << endl;
			}
			else
			{
				Node* ptr = head;
				while (ptr->next != NULL)
				{
					ptr = ptr->next; //������������һ��
				}
				ptr->next = n;
				n->previous = ptr;
				cout << "Node�����" << endl;

			}
		}
	}
	//3.Prepend Node - ���node����λ
	void prependNode(Node* n)
	{
		if (nodeExists(n->key) != NULL)
		{
			cout << "Node �Ѿ����ڲ���ֵ :" << n->key << ".  ����������Node�ò�ͬ�ĸ�ֵ" << endl;
		}
		else
		{
			if (head == NULL)
			{
				head = n;
				cout << "Node ��λ�Ѿ��� Head Node" << endl;
			}
			else
			{
				head->previous = n;
				n->next = head;

				head = n;
				cout << "Node ���Ϊ��λ" << endl;
			}

		}
	}

		//4. ���Node���ض���node����
	void insertNodeAfter(int k, Node* n)
	{
		Node* ptr = nodeExists(k);
		if (ptr == NULL)
		{
			cout << "û��node����ֵ" << k << endl;
		}
		else
		{
			if (nodeExists(n->key) != NULL)
			{
				cout << "Node �Ѿ����ڲ���ֵ :" << n->key << ". ����������Node�ò�ͬ�ĸ�ֵ" << endl;
			}
			else
			{
				Node* nextnode = ptr->next;
				//����ڽ�β
				if (nextnode == NULL)
				{
					ptr->next = n;
					n->previous = ptr;
					cout << "Node �����β��" << endl;

				}

				//������м�
				else
				{
					n->next = nextnode;
					nextnode->previous = n;
					n->previous = ptr;
					ptr->next = n;

					cout << "Node ������м�" << endl;
				}
			}
		}
	}

	//ɾ��node
	void deleteNodeByKey(int k)
	{
		Node* ptr = nodeExists(k);
		if (ptr == NULL)
		{
			cout << "û��node���ڲ���ֵ: " << k << endl;
		}
		else
		{
			if (head == NULL)
			{
				cout << "Doubly Linked List �Ѿ���գ�����ɾ��" << endl;
			}
			else if (head!=NULL)
			{
				if (head->key == k)
				{
					head = head->next;
					cout << "Node ȡ����ֵ�ڵ�: " << k << endl;
				}
				else
				{
					Node *nextNode = ptr->next;
					Node* prevNode = ptr->previous;
					//ɾ���ڽ�β
					if (nextNode == NULL)
					{
						prevNode->next = NULL;
						cout << "Node ɾ���ڽ�β" << endl;
					} 
					//  ɾ���м��
					else
					{
						prevNode->next = nextNode;
						nextNode->previous = prevNode;
						cout << "Nodeɾ�����м�" << endl;
					}
					
				}
			}
		}
	}
	//  �����ض���Node
	void updateNodeByKey(int k, int d)
	{
		Node* ptr = nodeExists(k);
		if (ptr != NULL)
		{
			ptr->data = d;
			cout << "Node ���³ɹ�" << endl;
		}
		else
		{
			cout << "Node û�д���������ֵ" << k << endl;
		}
	}

	// print
	void printList()
	{
		if (head == NULL)
		{
			cout << "û��Node �� DoublyLinkedList��";
		}
		else
		{
			cout << endl << "DoublyLinkedListֵΪ:";
			Node* temp = head;

			while (temp != NULL)
			{
				cout << "(" << temp->key << "," << temp->data << ")<-->";
				temp = temp->next;
			}
		}
	}
};