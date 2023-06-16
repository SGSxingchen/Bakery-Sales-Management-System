#pragma once
#ifndef BSMS_USERLIST_H
#define BSMS_USERLIST_H
#include <iostream>
#include <fstream>

#include "DList.h"
#include "User.h"
#include "DListNode.h"
using namespace std;

class UserList : public DList<User> {
public:
    UserList() {
        loadList("UserList");
    }
    void  addUser(const User& user) {
        push_back(user);
        saveList("UserList");
    }
    void deleteUser(const string& name) {
        DListNode<User>* cur = head;
        //DListNode<User>* head = head;
        //DListNode<User>* tail = tail;
        while (cur != nullptr) {
            User user = cur->getData();
            if (user.getName() == name) {  // 找到名字为name的节点
                if (&cur == &head) {  // 如果当前节点是头节点
                    head = cur->getNext();
                    if (head != nullptr) {
                        head->setNext(nullptr);
                    }
                    delete cur;
                    len--;
                    return;
                }
                else if (cur == tail) {  // 如果当前节点是尾节点
                    tail = cur->getPrev();
                    if (tail != nullptr) {
                        tail->setNext(nullptr);
                    }
                    delete cur;
                    len--;
                    return;
                }
                else {  // 如果当前节点不是头节点也不是尾节点
                    DListNode<User>* prev = cur->getPrev();
                    DListNode<User>* next = cur->getNext();
                    prev->setNext(next);
                    next->setPrev(prev);
                    delete cur;
                    len--;
                    return;
                }
            }
            cur = cur->getNext();
        }
        // 如果遍历完链表仍然没有找到名字为name的节点
        //cout << "User " << name << " 不存在" << endl;
        //printf("%s", name);
    }
    DListNode<User>* findUser(const string& name, const string& password) const {
        DListNode<User>* p = head;
        while (p != nullptr) {
            User data = p->getData();
            if (data.getName() == name && data.getPassword() == password) {
                return p;
            }
            p = p->getNext();
        }
        return nullptr;
    }
    bool logincheck(const string& name, const string& password)const {
        // 获取用户输入的用户名和密码
        // 在用户信息链表中查找是否存在对应用户信息
        DListNode<User>* userNode = findUser(name, password);
        if (userNode != nullptr) {
            cout << "登录成功！" << endl;
            // TODO: 登录成功后的操作
            return true;
        }
        else {
            cout << "用户名或密码错误！" << endl;
            return false;
        }
    }

    void logout() {
        // TODO: 登出功能的实现
    }
    void saveList(string filename) {
        ofstream outfile(filename);
        DListNode<User>* cur = head;
        while (cur != nullptr) {
            User data = cur->getData();
            outfile << data.getName() << "|" << data.getPassword() << endl;
            cur = cur->getNext();
        }
        outfile.close();
    }
    void loadList(string filename) {
        ifstream infile(filename);
        string temp;
        while (infile >> temp) {
            int start = 0;
            int mid = temp.find('|');
            int end = temp.length()-1;
            string name = temp.substr(start, mid);
            string password = temp.substr(mid + 1, end);
            User user = User(name, password);
            addUser(user);
        }
        infile.close();
    }
    void printList() {
        DListNode<User>* cur = head;
        if (head != nullptr && tail != nullptr) {
            User data1 = head->getData();
            User data2 = tail->getData();
            cout << "头节点" << data1.getName() << "|" << data1.getPassword() << endl;
            cout << "尾部节点" << data2.getName() << "|" << data2.getPassword() << endl;
        }
        while (cur != nullptr) {
            User data = cur->getData();
            cout << data.getName() << "|" << data.getPassword() << endl;
            cur = cur->getNext();
        }
        cout << endl;
    }

    static UserList userlist;
};
#endif // BSMS_USERLIST_H