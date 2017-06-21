#pragma once
#include "Character.h"
#include <iostream>

typedef struct Node 
{
	Character* val;
	Node* next;
	Node* last;
	
}Node;

class DLinkedList
{
public:
	DLinkedList();
	Node* head;
	Node* tail;

	void insertHead(Character* cha);
	
	void InsertTail(Character* cha);
	Node* FindByID(int id);
	void Remove(Character* cha);
	Node operator >> (const Node& c) const;
	Node operator << (const Node& c) const;
	
};
class World
{
public:
	static World* GetInstance();
	DLinkedList lista;
private: 
	World();
	static World* Instance;
	
};

