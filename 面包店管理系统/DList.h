#pragma once // 防止头文件重复包含

#ifndef BSMS_DLIST_H
#define BSMS_DLIST_H
#include "DListNode.h"
#include <string>
#include <fstream>
#include <iostream>

template<typename T>
class DList {
public:
	DList() {
		init();
	}
	~DList() {
		destroy();
	}
	DList(const DList<T>& other) {
		copyFrom(other);
	}
	DList<T>& operator=(const DList<T>& other) {
		if (this != &other) {
			destroy();
			copyFrom(other);
		}
		return *this;
	}
	bool empty() const {
		return len == 0;
	}
	int size() const {
		return len;
	}
	void push_front(const T& data) {
		DListNode<T>* node = new DListNode<T>(data, nullptr, nullptr);
		if (head == nullptr && tail == nullptr) {
			head = node;
			tail = node;
		}
		else {
			node->setNext(head);
			if (head != nullptr) {
				head->setPrev(node); //原头指针前节点改变
			}
			head = node;
			if (tail == head->getNext()) { //仅有两个节点的情况
				tail->setPrev(head);
			}
		}
		len++;
	}
	void push_back(const T& data) {
		DListNode<T>* node = new DListNode<T>(data);
		if (head == nullptr && tail == nullptr) {
			head = node;
			tail = node;
		}
		else {
			node->setPrev(tail);
			if (tail != nullptr) {
				tail->setNext(node); //设置当前尾节点下一节点为为新增节点
			}
			tail = node; //尾节点替换为新增节点
			if (head == tail->getPrev()) { //仅有两个节点的情况
				head->setNext(tail);
			}
		}
		len++;
	}
	void pop_front() {
		if (len > 0) {
			DListNode<T>* node = head->next;
			head->next = node->next;
			if (node->next != nullptr) {
				node->next->prev = head;
			}
			delete node;
			len--;
			if (len == 0) {
				tail = head;
			}
		}
	}
	void pop_back() {
		if (len > 0) {
			DListNode<T>* node = tail;
			tail = node->prev;
			if (node->prev != nullptr) {
				node->prev->next = nullptr;
			}
			delete node;
			len--;
			if (len == 0) {
				head = tail;
			}
		}
	}
	void clear() {
		destroy();
		init();
	}
	T& front() {
		return head->next->data;
	}
	const T& front() const {
		return head->next->data;
	}
	T& back() {
		return tail->data;
	}
	const T& back() const {
		return tail->data;
	}
	void insert(DListNode<T>* pos, const T& data) {
		if (pos != nullptr) {
			DListNode<T>* node = new DListNode<T>(data, pos->prev, pos);
			if (pos->prev != nullptr) {
				pos->prev->next = node;
			}
			pos->prev = node;
			if (head == pos) {
				head->next = node;
			}
			len++;
		}
	}
	void erase(DListNode<T>* pos) {
		if (pos != nullptr) {
			if (pos->prev != nullptr) {
				pos->prev->next = pos->next;
			}
			if (pos->next != nullptr) {
				pos->next->prev = pos->prev;
			}
			if (head == pos) {
				head->next = pos->next;
			}
			if (tail == pos) {
				tail = pos->prev;
			}
			delete pos;
			len--;
			if (len == 0) {
				tail = head;
			}
		}
	}
	void remove(const T& data) {
		DListNode<T>* cur = head;
		while (cur != nullptr) {
			if (cur->data == data) {  // 如果当前节点的数据等于要删除的数据
				if (cur == head) {  // 如果当前节点是头节点
					pop_front();  // 直接删除头节点
					cur = head;  // 继续从头节点开始遍历
				}
				else if (cur == tail) { // 如果当前节点是尾节点
					pop_back();  // 直接删除尾节点
					cur = nullptr;  // 结束遍历
				}
				else { // 如果当前节点不是头节点也不是尾节点
					DListNode<T>* prev = cur->prev; //新前节点
					DListNode<T>* next = cur->next; //新后节点
					prev->next = next; //新前节点的后节点为新后节点
					next->prev = prev; //新后节点的前节点为新前节点
					delete cur;  // 删除当前节点
					cur = next;  // 继续从下一个节点开始遍历
					len--;
				}
			}
			else {
				cur = cur->next;  // 继续遍历下一个节点
			}
		}
	}
	DListNode<T>* getHead() {
		return head;
	}
	DListNode<T>* getTail() {
		return tail;
	}
	DListNode<T>* getHead() const {
		return head;
	}
	DListNode<T>* getTail() const {
		return tail;
	}
	void redudeLen() {
		len--;
	}
protected:
	DListNode<T>* head; // 链表头指针
	DListNode<T>* tail; // 链表尾指针
	int len; // 链表长度
	void init() {
		head = tail = nullptr;
		len = 0;
	}
	void destroy() {
		while (head != nullptr) {
			DListNode<T>* node = head;
			head = head->getNext();
			delete node;
		}
		tail = nullptr;
		len = 0;
	}
	void copyFrom(const DList<T>& other) {
		init();
		for (DListNode<T>* node = other.head->getNext(); node != nullptr; node = node->getNext()) {
			push_back(node->getData());
		}
	}
};
//#include "DList.cpp" // 包含模板类的定义和实现
#endif // DLIST_H