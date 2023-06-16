#pragma once
#ifndef BSMS_MENU_H
#define BSMS_MENU_H
#include <iostream>
#include "Menu.h"
#include "UserList.h"
#include "GoodList.h"
using namespace std;

class Menu {
public:
    void menu(UserList& userlist,GoodList& goodlist) {
        cout << "欢迎使用面包店销售管理系统" << endl
            << "请选择操作：" << endl
            << "1. 登录" << endl
            << "2. 注册" << endl
            << "0. 退出" << endl
            << "> ";
        //userlist.printList();
        int num = 0;
        cin >> num;
        switch (num)
        {
        case 1:
            login(userlist, goodlist);
            break;
        case 2:
            reg(userlist, goodlist);
            break;
        case 0:
            return;
            break;
        default:
            break;
        }
    }
    void login(UserList& userlist,GoodList& goodlist) {
        string name;
        string password;
        cout << "请输将要登录的账号密码：" << endl;
        cout << "账号：";
        cin >> name;
        cout << "密码：";
        cin >> password;
        bool Flag = userlist.logincheck(name, password);
        switch (Flag)
        {
        case true:
            main(userlist,goodlist);
            break;
        case false:
            menu(userlist,goodlist);
            cout << "账号密码错误，请重试" << endl;
            break;
        }
    }
    void reg(UserList& userlist,GoodList& goodlist) {
        string name;
        string password;
        cout << "请输将要注册的账号密码：" << endl;
        cout << "账号：";
        cin >> name;
        cout << "密码：";
        cin >> password;
       
        userlist.addUser(User(name, password));
        cout << "注册成功！" << endl;
        //userlist.printList();
        menu(userlist, goodlist);
    }
    void sort(UserList& userlist, GoodList& goodlist) {
        cout << "请选择操作：" << endl
            << "1. 根据编码排序" << endl
            << "2. 根据总价排序" << endl
            << "3. 根据数量排序" << endl
            << "4. 根据日期排序" << endl
            << "0. 退出" << endl
            << "> ";
        int num;
        cin >> num;
        switch (num)
        {
        case 1:
            goodlist.sortById();
            goodlist.saveList("GoodList");
            main(userlist, goodlist);
            break;
        case 2:
            goodlist.sortByAllPrice();
            goodlist.saveList("GoodList");
            main(userlist, goodlist);
            break;
        case 3:
            goodlist.sortByAmount();
            goodlist.saveList("GoodList");
            main(userlist, goodlist);
            break;
        case 4:
            goodlist.sortByDate();
            goodlist.saveList("GoodList");
            main(userlist, goodlist);
            break;
        case 0:
            main(userlist, goodlist);
            break;
        }
    }
    void view(UserList& userlist, GoodList& goodlist, DListNode<GoodsInfo>* cur) {
        if (cur == nullptr) {
            cur = goodlist.getHead();
        }
        for (int i = 1; i <= 10; i++) {
            cout << i << ". "
                << cur->getData().getId() << "|" //编号
                << cur->getData().getName() << "|" //名称
                << cur->getData().getDate() << "|" //生产日期
                << cur->getData().getValidPeriod() << "|" //有效期
                << cur->getData().getStock() << "|" //库存
                << cur->getData().getPrice() << "|" //价格
                << cur->getData().getDiscount() << "|" << endl;//折扣
            if (cur->getNext() != nullptr) {
                cur = cur->getNext();
            }
            else {
                break;
            }
        }
        cout << "请选择操作：" << endl
            << "1. 上一页" << endl
            << "2. 下一页" << endl
            << "0. 返回" << endl
            << "> ";
        int num;
        cin >> num;
        switch (num)
        {
        case 2:
            view(userlist, goodlist, cur);
            break;
        case 1:
            for (int i = 1; i <= 10; i++) {
                if (cur->getPrev() != nullptr) {
                    cur = cur->getPrev();
                }
                else {
                    break;
                }
            }
            view(userlist, goodlist, cur);
            break;
        case 0:
            main(userlist, goodlist);
            break;
        }
        
    }
    void main(UserList& userlist,GoodList& goodlist) {
        cout << "请选择操作：" << endl
            << "1. 查询记录" << endl
            << "2. 添加记录" << endl
            << "3. 分类统计" << endl
            << "4. 导入记录" << endl
            << "5. 导出记录" << endl
            << "6. 数据处理" << endl 
            << "7. 查看当前数据" << endl //待做
            << "0. 退出" << endl
            << "> ";
        int num;
        cin >> num;
        switch (num)
        {
        case 1:
            query(userlist, goodlist);
            break;
        case 2:
            add(userlist, goodlist);
            break;
        case 3:
            statistics(userlist, goodlist);
            break;
        case 4:
            import(userlist, goodlist);
            break;
        case 5:
            eexport(userlist, goodlist);
            break;
        case 6:
            sort(userlist, goodlist);
            break;
        case 7:
            view(userlist, goodlist, nullptr);
            break;
        case 0:
            break;
        }
    }
    void eexport(UserList& userlist, GoodList& goodlist) {
        cout << "请选择操作" << endl
            << "1. 导出指定日期记录" << endl
            << "2. 导出指定编号记录" << endl
            << "0. 返回" << endl
            << "> ";
        int num,id;
        string date, filename;
        cin >> num;
        switch (num) {
        case 1:
            cout << "请输入日期：";
            cin >> date;
            cout << "请输入导出文件名称: ";
            cin >> filename;
            goodlist.exportGoodTime(date, filename + ".txt");
            cout << "导出成功！" << endl << endl;
            main(userlist, goodlist);
            break;
        case 2:
            cout << "请输入编号：";
            cin >> id;
            cout << "请输入导出文件名称: ";
            cin >> filename;
            goodlist.exportGoodId(id, filename + ".txt");
            cout << "导出成功！" << endl << endl;
            main(userlist, goodlist);
            break;
        }
    }
    void import(UserList& userlist, GoodList& goodlist) {
        cout<< "1. 导入记录文件名称: "<< endl
            << "0. 返回" << endl
            << "> ";
        int num;
        cin >> num;
        switch (num)
        {
        case 0:
            main(userlist, goodlist);
            break;
        case 1:
            cout << "请输入导入的记录名称（包含后缀）：";
            string filename;
            cin >> filename;
            goodlist.loadList(filename);
            cout << "导入成功！" << endl << endl;
            goodlist.saveList("GoodList");
            main(userlist, goodlist);
            break;
        }
        
    }
    void query(UserList& userlist,GoodList& goodlist) {
        cout << "请选择查询方式：" << endl
            << "1. 按名称查询记录" << endl
            << "2. 按生产日期查询记录" << endl
            << "3. 查询库存不足的商品" << endl
            << "0. 返回" << endl
            << "> ";
        int num;
        string s;
        cin >> num;
        switch (num)
        {
        case 1:
            cout << "请输入要查询的记录商品名称: ";
            cin >> s;
            goodlist.queryGoodName(s);
            query(userlist, goodlist);
            break;
        case 0:
            main(userlist, goodlist);
            break;
        case 2:
            cout << "请输入要查询的记录商品生产日期: ";
            cin >> s;
            goodlist.queryGoodTime(s);
            query(userlist, goodlist);
            break;
        case 3:
            goodlist.queryGoodVoid();
            query(userlist, goodlist);
            break;
        }
    }
    void add(UserList& userlist,GoodList& goodlist) {
        cout << "请选择：" << endl
            << "1. 添加记录" << endl
            << "0. 返回" << endl
            << "> ";
        int num;
        cin >> num;
        switch (num)
        {
        case 1:
            addSingleFood(userlist, goodlist);
            break;
        case 0:
            main(userlist, goodlist);
            break;
        }
    }
    void addSingleFood(UserList& userlist, GoodList& goodlist) {
        int m_id; // 商品编号
        std::string m_name; // 商品名称
        std::string m_date; // 制作日期
        int m_validPeriod; // 有效期
        int m_stock; // 库存
        double m_price; // 售价
        double m_discount; // 折扣
        cout << "商品编号：";
        cin >> m_id;
        cout << "商品名称：";
        cin >> m_name;
        cout  << "制作日期：";
        cin >> m_date;
        cout  << "有效期：";
        cin >> m_validPeriod;
        cout  << "库存：";
        cin >> m_stock;
        cout  << "售价：";
        cin >> m_price;
        cout  << "折扣：";
        cin >> m_discount;
        GoodsInfo good = GoodsInfo(m_id, m_name, m_date, m_validPeriod, m_stock, m_price, m_discount);
        goodlist.addGood(good);
        cout << endl << "添加成功！"<<endl;
        add(userlist, goodlist);
    }
    void modify(UserList& userlist,GoodList& goodlist) {
        cout << "请选择修改方式：" << endl
            << "1. 修改商品名称" << endl
            << "2. 修改商品价格" << endl
            << "3. 修改商品库存" << endl
            << "0. 返回" << endl
            << "> ";
        int num;
        cin >> num;
    }
    void statistics(UserList& userlist,GoodList& goodlist) {
        cout << "请选择：" << endl
            << "1. 按商品编号统计记录" << endl
            << "2. 按销售日期统计记录" << endl
            << "0. 返回" << endl
            << "> ";
        int num,id;
        cin >> num;
        string s;
        switch (num)
        {
        case 0:
            main(userlist, goodlist);
            break;
        case 1:
            cout << "请输入要统计的商品编号: ";
            cin >> id;
            goodlist.queryGoodId(id);
            statistics(userlist, goodlist);
            break;
        case 2:
            cout << "请输入要查询的商品生产日期: ";
            cin >> s;
            goodlist.queryGoodTime(s);
            query(userlist, goodlist);
            break;
        }
    }
    void confirmQuit(UserList& userlist,GoodList& goodlist) {
        cout << "确定要退出吗？(y/n)" << endl
            << "> ";
        int num;
        cin >> num;
    }
};
#endif // BSMS_MENU_H