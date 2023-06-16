#pragma once

#ifndef BSMS_DLIST_NODE_H
#define BSMS_DLIST_NODE_H

#include <iostream>

template <typename T>
class DListNode {
public:
    // Ĭ�Ϲ��캯��
    
    DListNode() : next(nullptr), prev(nullptr) {}

    // ���������캯��
    
    DListNode(const T& data) : data(data), next(nullptr), prev(nullptr) {}

    // ��ȡdata
    
    const T& getData() const {
        return data;
    }

    
    T& getData() {
        return data;
    }

    // ����data
    
    void setData(const T& data) {
        this->data = data;
    }

    // ��ȡ��һ���ڵ�ָ��
    
    DListNode<T>* getNext() const {
        return next;
    }

    // ���ú�һ���ڵ�ָ��
    
    void setNext(DListNode<T>* next) {
        this->next = next;
    }

    // ��ȡǰһ���ڵ�ָ��
    
    DListNode<T>* getPrev() const {
        return prev;
    }

    // ����ǰһ���ڵ�ָ��
    
    void setPrev(DListNode<T>* prev) {
        this->prev = prev;
    }

protected:
    T data; // ����
    DListNode<T>* next; // ��ָ��
    DListNode<T>* prev; // ǰָ��
};

//#include "DListNode.cpp"
#endif // DLIST_NODE_H