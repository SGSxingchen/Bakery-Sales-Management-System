#pragma once // ��ֹͷ�ļ��ظ�����

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
				head->setPrev(node); //ԭͷָ��ǰ�ڵ�ı�
			}
			head = node;
			if (tail == head->getNext()) { //���������ڵ�����
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
				tail->setNext(node); //���õ�ǰβ�ڵ���һ�ڵ�ΪΪ�����ڵ�
			}
			tail = node; //β�ڵ��滻Ϊ�����ڵ�
			if (head == tail->getPrev()) { //���������ڵ�����
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
			if (cur->data == data) {  // �����ǰ�ڵ�����ݵ���Ҫɾ��������
				if (cur == head) {  // �����ǰ�ڵ���ͷ�ڵ�
					pop_front();  // ֱ��ɾ��ͷ�ڵ�
					cur = head;  // ������ͷ�ڵ㿪ʼ����
				}
				else if (cur == tail) { // �����ǰ�ڵ���β�ڵ�
					pop_back();  // ֱ��ɾ��β�ڵ�
					cur = nullptr;  // ��������
				}
				else { // �����ǰ�ڵ㲻��ͷ�ڵ�Ҳ����β�ڵ�
					DListNode<T>* prev = cur->prev; //��ǰ�ڵ�
					DListNode<T>* next = cur->next; //�º�ڵ�
					prev->next = next; //��ǰ�ڵ�ĺ�ڵ�Ϊ�º�ڵ�
					next->prev = prev; //�º�ڵ��ǰ�ڵ�Ϊ��ǰ�ڵ�
					delete cur;  // ɾ����ǰ�ڵ�
					cur = next;  // ��������һ���ڵ㿪ʼ����
					len--;
				}
			}
			else {
				cur = cur->next;  // ����������һ���ڵ�
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
	DListNode<T>* head; // ����ͷָ��
	DListNode<T>* tail; // ����βָ��
	int len; // ������
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
//#include "DList.cpp" // ����ģ����Ķ����ʵ��
#endif // DLIST_H