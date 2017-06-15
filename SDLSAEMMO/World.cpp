#include "World.h"



World::World()
{
}


World::~World()
{
}

void DLinkedList::insertHead(Character * cha)
{
	head = NULL;
	Node* pTemp = new Node();
	pTemp->val = cha;
	pTemp->next = head;
	head = pTemp;
}

void DLinkedList::InsertTail(Character * cha)
{
	auto pTemp = new Node();
	if (head == nullptr)
		head = tail = pTemp;
	else 
	{
		tail->next = pTemp;
		tail = pTemp;
	}

}

void DLinkedList::Remove(Character * cha)
{
	Node *pTemp = head;
	while (head != NULL)
	{
		std::cout << head->val;
		head = head->next;
		delete pTemp;
		pTemp = head;
	}
}

Node DLinkedList::operator >> (const Node & c) const
{
	return Node(*(head)->next);
}

Node DLinkedList::operator<<(const Node & c) const
{
	return Node(*(head)->last);
}

