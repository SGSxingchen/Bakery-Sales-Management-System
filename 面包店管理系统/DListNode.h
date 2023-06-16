#pragma once

#ifndef BSMS_DLIST_NODE_H
#define BSMS_DLIST_NODE_H

#include <iostream>

template <typename T>
class DListNode {
public:
    // 默认构造函数
    
    DListNode() : next(nullptr), prev(nullptr) {}

    // 带参数构造函数
    
    DListNode(const T& data) : data(data), next(nullptr), prev(nullptr) {}

    // 获取data
    
    const T& getData() const {
        return data;
    }

    
    T& getData() {
        return data;
    }

    // 设置data
    
    void setData(const T& data) {
        this->data = data;
    }

    // 获取后一个节点指针
    
    DListNode<T>* getNext() const {
        return next;
    }

    // 设置后一个节点指针
    
    void setNext(DListNode<T>* next) {
        this->next = next;
    }

    // 获取前一个节点指针
    
    DListNode<T>* getPrev() const {
        return prev;
    }

    // 设置前一个节点指针
    
    void setPrev(DListNode<T>* prev) {
        this->prev = prev;
    }

protected:
    T data; // 数据
    DListNode<T>* next; // 后指针
    DListNode<T>* prev; // 前指针
};

//#include "DListNode.cpp"
#endif // DLIST_NODE_H