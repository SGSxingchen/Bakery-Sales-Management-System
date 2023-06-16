#pragma once
#ifndef BSMS_GOODLIST_H
#define BSMS_GOODLIST_H
#include <iostream>
#include <fstream>
#include "DList.h"
#include "GoodsInfo.h"
#include "User.h"
#include "DListNode.h"
using namespace std;

class GoodList : public DList<GoodsInfo> {
public:
    GoodList() {
        loadList("GoodList");
    }
    void printInfo() {
        DListNode<GoodsInfo>* cur = head;
        if (head != nullptr && tail != nullptr) {
            GoodsInfo data1 = head->getData();
            GoodsInfo data2 = tail->getData();
            cout << "ͷ�ڵ�" << data1.getId() << endl;
            cout << "β���ڵ�" << data2.getId() << endl;
        }
        while (cur != nullptr) {
            cout << "Pre: " << cur->getPrev()
                << "    Node: " << cur
                << "    Next: " << cur->getNext()<<endl;
            cur = cur->getNext();
        }
    }
    void addGood(const GoodsInfo& goodInfo) {
        push_back(goodInfo);
        saveList("GoodList");
    }
    void saveList(string filename) {
        ofstream outfile(filename);
        DListNode<GoodsInfo>* cur = head;
        while (cur != nullptr) {
            GoodsInfo data = cur->getData();
            outfile << data.getId() << "|" //���
                << data.getName() << "|" //����
                << data.getDate() << "|" //��������
                << data.getValidPeriod() << "|" //��Ч��
                << data.getStock() << "|" //���
                << data.getPrice() << "|" //�۸�
                << data.getDiscount() << "|" << endl;//�ۿ�
            cur = cur->getNext();
        }
        outfile.close();
    }
    void loadList(string filename) {
        ifstream infile(filename);
        string temp;
        while (infile >> temp) {
            int start = 0;
            int len = temp.length() - 1;
            int pos = start;
            string keys[7];
            int key = 0;
            while (pos != -1) {
                pos = temp.find('|', start);
                if (pos == -1) break;
                else {
                    keys[key] = temp.substr(start, pos-start);
                    start = pos+1 ;
                    key++;
                }
            }
            GoodsInfo good = GoodsInfo(keys[0], keys[1], keys[2], keys[3], keys[4], keys[5], keys[6]);
            addGood(good);
        }
        infile.close();
    }
    void queryGoodName(const string& name) {
        cout << endl;
        DListNode<GoodsInfo>* cur = head;
        int index = 1;
        while (cur != nullptr) {
            GoodsInfo data = cur->getData();
            string cur_name = data.getName();
            if (cur_name == name) {
                cout<< index << ". "
                    << data.getId() << "|" //���
                    << data.getName() << "|" //����
                    << data.getDate() << "|" //��������
                    << data.getValidPeriod() << "|" //��Ч��
                    << data.getStock() << "|" //���
                    << data.getPrice() << "|" //�۸�
                    << data.getDiscount() << "|" << endl;//�ۿ�
                index++;
            }
            cur = cur->getNext();
        }
        cout << endl;
    }
    void queryGoodNameTime(const string& name, const string& date) {
        DListNode<GoodsInfo>* cur = head;
        int index = 1;
        while (cur != nullptr) {
            GoodsInfo data = cur->getData();
            string cur_name = data.getName();
            string cur_date = data.getDate();
            if (cur_name == name && cur_date == date) {
                cout << index << ". "
                    << data.getId() << "|" //���
                    << data.getName() << "|" //����
                    << data.getDate() << "|" //��������
                    << data.getValidPeriod() << "|" //��Ч��
                    << data.getStock() << "|" //���
                    << data.getPrice() << "|" //�۸�
                    << data.getDiscount() << "|" << endl;//�ۿ�
                index++;
            }
            cur = cur->getNext();
        }
    }
    void queryGoodTime(const string& date) {
        cout << endl;
        DListNode<GoodsInfo>* cur = head;
        int index = 1;
        while (cur != nullptr) {
            GoodsInfo data = cur->getData();
            string cur_date = data.getDate();
            if (cur_date == date) {
                cout << index << ". "
                    << data.getId() << "|" //���
                    << data.getName() << "|" //����
                    << data.getDate() << "|" //��������
                    << data.getValidPeriod() << "|" //��Ч��
                    << data.getStock() << "|" //���
                    << data.getPrice() << "|" //�۸�
                    << data.getDiscount() << "|" << endl;//�ۿ�
                index++;
            }
            cur = cur->getNext();
        }
        cout << endl;
    }
    void exportGoodTime(const string& date,const string& filename) {
        ofstream outfile(filename);
        DListNode<GoodsInfo>* cur = head;
        int index = 1;
        while (cur != nullptr) {
            GoodsInfo data = cur->getData();
            string cur_date = data.getDate();
            if (cur_date == date) {
                outfile << index << ". "
                    << data.getId() << "|" //���
                    << data.getName() << "|" //����
                    << data.getDate() << "|" //��������
                    << data.getValidPeriod() << "|" //��Ч��
                    << data.getStock() << "|" //���
                    << data.getPrice() << "|" //�۸�
                    << data.getDiscount() << "|" << endl;//�ۿ�
                index++;
            }
            cur = cur->getNext();
        }
        outfile.close();
    }
    void exportGoodId(const int& id, const string& filename) {
        ofstream outfile(filename);
        DListNode<GoodsInfo>* cur = head;
        int index = 1;
        while (cur != nullptr) {
            GoodsInfo data = cur->getData();
            int cur_id = data.getId();
            if (cur_id == id) {
                outfile << index << ". "
                    << data.getId() << "|" //���
                    << data.getName() << "|" //����
                    << data.getDate() << "|" //��������
                    << data.getValidPeriod() << "|" //��Ч��
                    << data.getStock() << "|" //���
                    << data.getPrice() << "|" //�۸�
                    << data.getDiscount() << "|" << endl;//�ۿ�
                index++;
            }
            cur = cur->getNext();
        }
        outfile.close();
    }
    void queryGoodId(const int& id) {
        cout << endl;
        DListNode<GoodsInfo>* cur = head;
        int index = 1;
        while (cur != nullptr) {
            GoodsInfo data = cur->getData();
            int cur_id = data.getId();
            if (id == cur_id) {
                cout << index << ". "
                    << data.getId() << "|" //���
                    << data.getName() << "|" //����
                    << data.getDate() << "|" //��������
                    << data.getValidPeriod() << "|" //��Ч��
                    << data.getStock() << "|" //���
                    << data.getPrice() << "|" //�۸�
                    << data.getDiscount() << "|" << endl;//�ۿ�
                index++;
            }
            cur = cur->getNext();
        }
        cout << endl;
    }
    void queryGoodVoid() {
        cout << endl;
        DListNode<GoodsInfo>* cur = head;
        int index = 1;
        while (cur != nullptr) {
            GoodsInfo data = cur->getData();
            int cur_stock = data.getStock();
            if (cur_stock <= 0) {
                cout << index << ". "
                    << data.getId() << "|" //���
                    << data.getName() << "|" //����
                    << data.getDate() << "|" //��������
                    << data.getValidPeriod() << "|" //��Ч��
                    << data.getStock() << "|" //���
                    << data.getPrice() << "|" //�۸�
                    << data.getDiscount() << "|" << endl;//�ۿ�
                index++;
            }
            cur = cur->getNext();
        }
        cout << endl;
    }
    //�����ۼ�¼�����ڡ��ܼۡ���������Ŀ����
    bool compareBigDate(const string& a, const string& b) {
        int start = 0;
        int len = a.length() - 1;
        int pos = start;
        int keys[3] = {0};
        int key = 0;
        while (pos != -1) {
            if (key == 2) {
                keys[key] = std::stoi(a.substr(start, len - start + 1));
            }
            pos = a.find('-', start);
            if (pos == -1) break;
            else {
                keys[key] = std::stoi(a.substr(start, pos - start));
                
                start = pos + 1;
                key++;
            }
        }
        start = 0;
        len = b.length() - 1;
        pos = start;
        int keys_2[3] = {0};
        key = 0;
        while (pos != -1) {
            if (key == 2) {
                keys_2[key] = std::stoi(b.substr(start, len - start + 1));
            }
            pos = b.find('-', start);
            if (pos == -1) break;
            else {
                keys_2[key] = std::stoi(b.substr(start, pos - start));
                start = pos + 1;
                key++;
            }
        }
        if (keys[0] > keys_2[0]) {
            return true;
        }
        else if (keys[0] == keys_2[0]) {
            if (keys[1] > keys_2[1]) {
                return true;
            }
            else if (keys[1] == keys_2[1]) {
                if (keys[2] > keys_2[2]) {
                    return true;
                }
                else if (keys[2] == keys_2[2]) {
                    return false;
                }
                else if (keys[2] < keys_2[2]) {
                    return false;
                }
            }
            else if (keys[1] < keys_2[1]) {
                return false;
            }
        }
        else if (keys[0] < keys_2[0]) {
            return false;
        }
    }
    bool compareSmallDate(const string& a, const string& b) {
        int start = 0;
        int len = a.length() - 1;
        int pos = start;
        int keys[3] = { 0 };
        int key = 0;
        while (pos != -1) {
            if (key == 2) {
                keys[key] = std::stoi(a.substr(start, len - start + 1));
            }
            pos = a.find('-', start);
            if (pos == -1) break;
            else {
                keys[key] = std::stoi(a.substr(start, pos - start));

                start = pos + 1;
                key++;
            }
        }
        start = 0;
        len = b.length() - 1;
        pos = start;
        int keys_2[3] = { 0 };
        key = 0;
        while (pos != -1) {
            if (key == 2) {
                keys_2[key] = std::stoi(b.substr(start, len - start + 1));
            }
            pos = b.find('-', start);
            if (pos == -1) break;
            else {
                keys_2[key] = std::stoi(b.substr(start, pos - start));
                start = pos + 1;
                key++;
            }
        }
        if (keys[0] <  keys_2[0]) {
            return true;
        }
        else if (keys[0] == keys_2[0]) {
            if (keys[1] < keys_2[1]) {
                return true;
            }
            else if (keys[1] == keys_2[1]) {
                if (keys[2] < keys_2[2]) {
                    return true;
                }
                else if (keys[2] == keys_2[2]) {
                    return false;
                }
                else if (keys[2] > keys_2[2]) {
                    return false;
                }
            }
            else if (keys[1] > keys_2[1]) {
                return false;
            }
        }
        else if (keys[0] > keys_2[0]) {
            return false;
        }
    }
    void printfff() {
        DListNode<GoodsInfo>* p = head;
        cout << "��ӡ��Ϣ��";
        while (p != nullptr) {
            cout << p->getData().getDate();
            p = p->getNext();
        }
        cout << endl;
    }
    void sortById() {
        DListNode<GoodsInfo>* cur = head;
        DListNode<GoodsInfo>* head_m = head;    //ͷ
        DListNode<GoodsInfo>* tail_m = tail; //β
        DListNode<GoodsInfo>* p = head;
        bool exchange = true; //�Ƿ񽻻�,�����������Ƿ����������ж�ѭ���Ƿ����
        while (exchange)
        {   
            exchange = false;
            while (p != tail) //�������Ҵ�������
            {   
                cout << p << endl;
                //p->getData().getDate() > p->getNext()->getData().getDate()
                if (p->getData().getId() > p->getNext()->getData().getId()){
                    exchange = true; //�����˽���
                    swap(p->getData(), p->getNext()->getData());
                }

                p = p->getNext(); //����
            }
            //С������
            while (p != head) //��������С��ð��
            {
                cout << p << endl;
                if (p->getData().getId() < p->getPrev()->getData().getId())
                {
                    exchange = true;
                    swap(p->getData(), p->getPrev()->getData());
                }

                p = p->getPrev(); //ǰ��
            }
            
        }
    }
    void sortByAllPrice() {
        DListNode<GoodsInfo>* cur = head;
        DListNode<GoodsInfo>* head_m = head;    //ͷ
        DListNode<GoodsInfo>* tail_m = tail; //β
        DListNode<GoodsInfo>* p = head;
        bool exchange = true; //�Ƿ񽻻�,�����������Ƿ����������ж�ѭ���Ƿ����
        while (exchange)
        {
            exchange = false;
            while (p != tail) //�������Ҵ�������
            {
                if (p->getData().getPrice()* p->getData().getStock() < p->getNext()->getData().getPrice()* p->getNext()->getData().getStock()) {
                    exchange = true; //�����˽���
                    swap(p->getData(), p->getNext()->getData());
                }

                p = p->getNext(); //����
            }
            //С������
            while (p != head) //��������С��ð��
            {
                if (p->getData().getPrice() * p->getData().getStock() > p->getPrev()->getData().getPrice() * p->getPrev()->getData().getStock())
                {
                    exchange = true;
                    swap(p->getData(), p->getPrev()->getData());
                }

                p = p->getPrev(); //ǰ��
            }

        }
    }
    void sortByAmount() {
        DListNode<GoodsInfo>* cur = head;
        DListNode<GoodsInfo>* head_m = head;    //ͷ
        DListNode<GoodsInfo>* tail_m = tail; //β
        DListNode<GoodsInfo>* p = head;
        bool exchange = true; //�Ƿ񽻻�,�����������Ƿ����������ж�ѭ���Ƿ����
        while (exchange)
        {
            exchange = false;
            while (p != tail) //�������Ҵ�������
            {
                if ( p->getData().getStock() < p->getNext()->getData().getStock()) {
                    exchange = true; //�����˽���
                    swap(p->getData(), p->getNext()->getData());
                }

                p = p->getNext(); //����
            }
            //С������
            while (p != head) //��������С��ð��
            {
                if (p->getData().getStock() > p->getPrev()->getData().getStock())
                {
                    exchange = true;
                    swap(p->getData(), p->getPrev()->getData());
                }

                p = p->getPrev(); //ǰ��
            }

        }
    }
    void sortByDate() {
        DListNode<GoodsInfo>* cur = head;
        DListNode<GoodsInfo>* head_m = head;    //ͷ
        DListNode<GoodsInfo>* tail_m = tail; //β
        DListNode<GoodsInfo>* p = head;
        bool exchange = true; //�Ƿ񽻻�,�����������Ƿ����������ж�ѭ���Ƿ����
        while (exchange)
        {
            exchange = false;
            while (p != tail) //�������Ҵ�������
            {
                //cout<<"Big: " << p->getData().getDate() << " �� " << p->getNext()->getData().getDate() << " : " << compareBigDate(p->getData().getDate(), p->getNext()->getData().getDate()) << endl;
                if (compareBigDate(p->getData().getDate(), p->getNext()->getData().getDate())) {
                    exchange = true; //�����˽���
                    swap(p->getData(), p->getNext()->getData());
                }

                p = p->getNext(); //����
            }
            //С������
            while (p != head) //��������С��ð��
            {
                //cout <<"Small: " << p->getData().getDate() << " �� " << p->getPrev()->getData().getDate() << " : " << compareSmallDate(p->getData().getDate(), p->getPrev()->getData().getDate()) << endl;
                if (compareSmallDate(p->getData().getDate(), p->getPrev()->getData().getDate()))
                {
                    exchange = true;
                    swap(p->getData(), p->getPrev()->getData());
                }

                p = p->getPrev(); //ǰ��
            }

        }
    }
};
#endif
