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
            if (user.getName() == name) {  // �ҵ�����Ϊname�Ľڵ�
                if (&cur == &head) {  // �����ǰ�ڵ���ͷ�ڵ�
                    head = cur->getNext();
                    if (head != nullptr) {
                        head->setNext(nullptr);
                    }
                    delete cur;
                    len--;
                    return;
                }
                else if (cur == tail) {  // �����ǰ�ڵ���β�ڵ�
                    tail = cur->getPrev();
                    if (tail != nullptr) {
                        tail->setNext(nullptr);
                    }
                    delete cur;
                    len--;
                    return;
                }
                else {  // �����ǰ�ڵ㲻��ͷ�ڵ�Ҳ����β�ڵ�
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
        // ���������������Ȼû���ҵ�����Ϊname�Ľڵ�
        //cout << "User " << name << " ������" << endl;
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
        // ��ȡ�û�������û���������
        // ���û���Ϣ�����в����Ƿ���ڶ�Ӧ�û���Ϣ
        DListNode<User>* userNode = findUser(name, password);
        if (userNode != nullptr) {
            cout << "��¼�ɹ���" << endl;
            // TODO: ��¼�ɹ���Ĳ���
            return true;
        }
        else {
            cout << "�û������������" << endl;
            return false;
        }
    }

    void logout() {
        // TODO: �ǳ����ܵ�ʵ��
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
            cout << "ͷ�ڵ�" << data1.getName() << "|" << data1.getPassword() << endl;
            cout << "β���ڵ�" << data2.getName() << "|" << data2.getPassword() << endl;
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