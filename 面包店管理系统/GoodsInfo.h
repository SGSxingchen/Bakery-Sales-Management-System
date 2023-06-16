#pragma once
#ifndef BSMS_GOODSINFO_H
#define BSMS_GOODSINFO_H

#include <string>
class GoodsInfo {
public:
    // 构造函数
    GoodsInfo();
    GoodsInfo(int id, const std::string& name, const std::string& date, int validPeriod, int stock, double price, double discount);
    GoodsInfo(const std::string& id, const std::string& name, const std::string& date, const std::string& validPeriod, const std::string& stock, const std::string& price, const std::string& discount);

    // 拷贝构造函数
    GoodsInfo(const GoodsInfo& other);

    // 赋值运算符重载
    GoodsInfo& operator=(const GoodsInfo& other);

    // 获取和设置成员变量的方法
    int getId() const;
    void setId(int id);
    std::string getName() const;
    void setName(const std::string& name);
    std::string getDate() const;
    void setDate(const std::string& date);
    int getValidPeriod() const;
    void setValidPeriod(int validPeriod);
    int getStock() const;
    void setStock(int stock);
    double getPrice() const;
    void setPrice(double price);
    double getDiscount() const;
    void setDiscount(double discount);

    // 打印商品信息的方法
    void print() const;

private:
    int m_id; // 商品编号
    std::string m_name; // 商品名称
    std::string m_date; // 制作日期
    int m_validPeriod; // 有效期
    int m_stock; // 数量
    double m_price; // 售价
    double m_discount; // 折扣
};

#endif // GOODSINFO_H