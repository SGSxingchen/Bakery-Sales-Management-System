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
            cout << "头节点" << data1.getId() << endl;
            cout << "尾部节点" << data2.getId() << endl;
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
            outfile << data.getId() << "|" //编号
                << data.getName() << "|" //名称
                << data.getDate() << "|" //生产日期
                << data.getValidPeriod() << "|" //有效期
                << data.getStock() << "|" //库存
                << data.getPrice() << "|" //价格
                << data.getDiscount() << "|" << endl;//折扣
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
                    << data.getId() << "|" //编号
                    << data.getName() << "|" //名称
                    << data.getDate() << "|" //生产日期
                    << data.getValidPeriod() << "|" //有效期
                    << data.getStock() << "|" //库存
                    << data.getPrice() << "|" //价格
                    << data.getDiscount() << "|" << endl;//折扣
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
                    << data.getId() << "|" //编号
                    << data.getName() << "|" //名称
                    << data.getDate() << "|" //生产日期
                    << data.getValidPeriod() << "|" //有效期
                    << data.getStock() << "|" //库存
                    << data.getPrice() << "|" //价格
                    << data.getDiscount() << "|" << endl;//折扣
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
                    << data.getId() << "|" //编号
                    << data.getName() << "|" //名称
                    << data.getDate() << "|" //生产日期
                    << data.getValidPeriod() << "|" //有效期
                    << data.getStock() << "|" //库存
                    << data.getPrice() << "|" //价格
                    << data.getDiscount() << "|" << endl;//折扣
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
                    << data.getId() << "|" //编号
                    << data.getName() << "|" //名称
                    << data.getDate() << "|" //生产日期
                    << data.getValidPeriod() << "|" //有效期
                    << data.getStock() << "|" //库存
                    << data.getPrice() << "|" //价格
                    << data.getDiscount() << "|" << endl;//折扣
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
                    << data.getId() << "|" //编号
                    << data.getName() << "|" //名称
                    << data.getDate() << "|" //生产日期
                    << data.getValidPeriod() << "|" //有效期
                    << data.getStock() << "|" //库存
                    << data.getPrice() << "|" //价格
                    << data.getDiscount() << "|" << endl;//折扣
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
                    << data.getId() << "|" //编号
                    << data.getName() << "|" //名称
                    << data.getDate() << "|" //生产日期
                    << data.getValidPeriod() << "|" //有效期
                    << data.getStock() << "|" //库存
                    << data.getPrice() << "|" //价格
                    << data.getDiscount() << "|" << endl;//折扣
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
                    << data.getId() << "|" //编号
                    << data.getName() << "|" //名称
                    << data.getDate() << "|" //生产日期
                    << data.getValidPeriod() << "|" //有效期
                    << data.getStock() << "|" //库存
                    << data.getPrice() << "|" //价格
                    << data.getDiscount() << "|" << endl;//折扣
                index++;
            }
            cur = cur->getNext();
        }
        cout << endl;
    }
    //将销售记录按日期、总价、数量等项目排序
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
        cout << "打印信息：";
        while (p != nullptr) {
            cout << p->getData().getDate();
            p = p->getNext();
        }
        cout << endl;
    }
    void sortById() {
        DListNode<GoodsInfo>* cur = head;
        DListNode<GoodsInfo>* head_m = head;    //头
        DListNode<GoodsInfo>* tail_m = tail; //尾
        DListNode<GoodsInfo>* p = head;
        bool exchange = true; //是否交换,并且最后根据是否发生交换来判断循环是否结束
        while (exchange)
        {   
            exchange = false;
            while (p != tail) //从左往右大数沉底
            {   
                cout << p << endl;
                //p->getData().getDate() > p->getNext()->getData().getDate()
                if (p->getData().getId() > p->getNext()->getData().getId()){
                    exchange = true; //发生了交换
                    swap(p->getData(), p->getNext()->getData());
                }

                p = p->getNext(); //后移
            }
            //小数起泡
            while (p != head) //从右往左小数冒泡
            {
                cout << p << endl;
                if (p->getData().getId() < p->getPrev()->getData().getId())
                {
                    exchange = true;
                    swap(p->getData(), p->getPrev()->getData());
                }

                p = p->getPrev(); //前移
            }
            
        }
    }
    void sortByAllPrice() {
        DListNode<GoodsInfo>* cur = head;
        DListNode<GoodsInfo>* head_m = head;    //头
        DListNode<GoodsInfo>* tail_m = tail; //尾
        DListNode<GoodsInfo>* p = head;
        bool exchange = true; //是否交换,并且最后根据是否发生交换来判断循环是否结束
        while (exchange)
        {
            exchange = false;
            while (p != tail) //从左往右大数沉底
            {
                if (p->getData().getPrice()* p->getData().getStock() < p->getNext()->getData().getPrice()* p->getNext()->getData().getStock()) {
                    exchange = true; //发生了交换
                    swap(p->getData(), p->getNext()->getData());
                }

                p = p->getNext(); //后移
            }
            //小数起泡
            while (p != head) //从右往左小数冒泡
            {
                if (p->getData().getPrice() * p->getData().getStock() > p->getPrev()->getData().getPrice() * p->getPrev()->getData().getStock())
                {
                    exchange = true;
                    swap(p->getData(), p->getPrev()->getData());
                }

                p = p->getPrev(); //前移
            }

        }
    }
    void sortByAmount() {
        DListNode<GoodsInfo>* cur = head;
        DListNode<GoodsInfo>* head_m = head;    //头
        DListNode<GoodsInfo>* tail_m = tail; //尾
        DListNode<GoodsInfo>* p = head;
        bool exchange = true; //是否交换,并且最后根据是否发生交换来判断循环是否结束
        while (exchange)
        {
            exchange = false;
            while (p != tail) //从左往右大数沉底
            {
                if ( p->getData().getStock() < p->getNext()->getData().getStock()) {
                    exchange = true; //发生了交换
                    swap(p->getData(), p->getNext()->getData());
                }

                p = p->getNext(); //后移
            }
            //小数起泡
            while (p != head) //从右往左小数冒泡
            {
                if (p->getData().getStock() > p->getPrev()->getData().getStock())
                {
                    exchange = true;
                    swap(p->getData(), p->getPrev()->getData());
                }

                p = p->getPrev(); //前移
            }

        }
    }
    void sortByDate() {
        DListNode<GoodsInfo>* cur = head;
        DListNode<GoodsInfo>* head_m = head;    //头
        DListNode<GoodsInfo>* tail_m = tail; //尾
        DListNode<GoodsInfo>* p = head;
        bool exchange = true; //是否交换,并且最后根据是否发生交换来判断循环是否结束
        while (exchange)
        {
            exchange = false;
            while (p != tail) //从左往右大数沉底
            {
                //cout<<"Big: " << p->getData().getDate() << " ： " << p->getNext()->getData().getDate() << " : " << compareBigDate(p->getData().getDate(), p->getNext()->getData().getDate()) << endl;
                if (compareBigDate(p->getData().getDate(), p->getNext()->getData().getDate())) {
                    exchange = true; //发生了交换
                    swap(p->getData(), p->getNext()->getData());
                }

                p = p->getNext(); //后移
            }
            //小数起泡
            while (p != head) //从右往左小数冒泡
            {
                //cout <<"Small: " << p->getData().getDate() << " ： " << p->getPrev()->getData().getDate() << " : " << compareSmallDate(p->getData().getDate(), p->getPrev()->getData().getDate()) << endl;
                if (compareSmallDate(p->getData().getDate(), p->getPrev()->getData().getDate()))
                {
                    exchange = true;
                    swap(p->getData(), p->getPrev()->getData());
                }

                p = p->getPrev(); //前移
            }

        }
    }
};
#endif
