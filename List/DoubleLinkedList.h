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
	//1. 检查node是否存在

	Node* nodeExists(int k)
	{
		Node* temp = NULL;
		Node* ptr = head;  //把他存在head里面

		while (ptr != NULL)
		{
			if (ptr->key == k)
			{
				temp = ptr;
			}
			ptr = ptr->next; //将数据存在下一个里面
		}

		return temp;
	}

	//2. 将Node添加到列表里 

	void appendNode(Node* n)
	{
		if (nodeExists(n->key) != NULL)
		{
			cout << "Node 已经存在且已经赋值 : " << n->key << ". 附加其他的Node用不同的赋值" << endl;
		}
		else
		{
			if (head == NULL)
			{
				head = n;
				cout << "Node 添加为 Head Node" << endl;
			}
			else
			{
				Node* ptr = head;
				while (ptr->next != NULL)
				{
					ptr = ptr->next; //将数据移入下一格
				}
				ptr->next = n;
				n->previous = ptr;
				cout << "Node已添加" << endl;

			}
		}
	}
	//3.Prepend Node - 添加node在首位
	void prependNode(Node* n)
	{
		if (nodeExists(n->key) != NULL)
		{
			cout << "Node 已经存在并赋值 :" << n->key << ".  附加其他的Node用不同的赋值" << endl;
		}
		else
		{
			if (head == NULL)
			{
				head = n;
				cout << "Node 首位已经是 Head Node" << endl;
			}
			else
			{
				head->previous = n;
				n->next = head;

				head = n;
				cout << "Node 添加为首位" << endl;
			}

		}
	}

		//4. 添加Node在特定的node过后
	void insertNodeAfter(int k, Node* n)
	{
		Node* ptr = nodeExists(k);
		if (ptr == NULL)
		{
			cout << "没有node被赋值" << k << endl;
		}
		else
		{
			if (nodeExists(n->key) != NULL)
			{
				cout << "Node 已经存在并赋值 :" << n->key << ". 附加其他的Node用不同的赋值" << endl;
			}
			else
			{
				Node* nextnode = ptr->next;
				//添加在结尾
				if (nextnode == NULL)
				{
					ptr->next = n;
					n->previous = ptr;
					cout << "Node 添加在尾端" << endl;

				}

				//添加在中间
				else
				{
					n->next = nextnode;
					nextnode->previous = n;
					n->previous = ptr;
					ptr->next = n;

					cout << "Node 添加在中间" << endl;
				}
			}
		}
	}

	//删除node
	void deleteNodeByKey(int k)
	{
		Node* ptr = nodeExists(k);
		if (ptr == NULL)
		{
			cout << "没有node存在并赋值: " << k << endl;
		}
		else
		{
			if (head == NULL)
			{
				cout << "Doubly Linked List 已经清空，不能删除" << endl;
			}
			else if (head!=NULL)
			{
				if (head->key == k)
				{
					head = head->next;
					cout << "Node 取消赋值节点: " << k << endl;
				}
				else
				{
					Node *nextNode = ptr->next;
					Node* prevNode = ptr->previous;
					//删除在结尾
					if (nextNode == NULL)
					{
						prevNode->next = NULL;
						cout << "Node 删除在结尾" << endl;
					} 
					//  删除中间的
					else
					{
						prevNode->next = nextNode;
						nextNode->previous = prevNode;
						cout << "Node删除在中间" << endl;
					}
					
				}
			}
		}
	}
	//  更新特定的Node
	void updateNodeByKey(int k, int d)
	{
		Node* ptr = nodeExists(k);
		if (ptr != NULL)
		{
			ptr->data = d;
			cout << "Node 更新成功" << endl;
		}
		else
		{
			cout << "Node 没有存在于任意值" << k << endl;
		}
	}

	// print
	void printList()
	{
		if (head == NULL)
		{
			cout << "没有Node 在 DoublyLinkedList里";
		}
		else
		{
			cout << endl << "DoublyLinkedList值为:";
			Node* temp = head;

			while (temp != NULL)
			{
				cout << "(" << temp->key << "," << temp->data << ")<-->";
				temp = temp->next;
			}
		}
	}
};