#include "goodsinfo.h"
#include <iostream>
using namespace std;

// 构造函数
GoodsInfo::GoodsInfo() : m_id(0), m_name(""), m_date(""), m_validPeriod(0), m_stock(0), m_price(0.0), m_discount(0.0) {}

GoodsInfo::GoodsInfo(int id, const std::string& name, const std::string& date, int validPeriod, int stock, double price, double discount)
    : m_id(id), m_name(name), m_date(date), m_validPeriod(validPeriod), m_stock(stock), m_price(price), m_discount(discount){}

GoodsInfo::GoodsInfo(const std::string& id, const std::string& name, const std::string& date, const std::string& validPeriod, const std::string& stock, const std::string& price, const std::string& discount)
    : m_id(std::stoi(id)), m_name(name), m_date(date), m_validPeriod(std::stoi(validPeriod)), m_stock(std::stoi(stock)), m_price(std::stod(price)), m_discount(std::stod(discount)){}

// 拷贝构造函数
GoodsInfo::GoodsInfo(const GoodsInfo& other)
    : m_id(other.m_id), m_name(other.m_name), m_date(other.m_date), m_validPeriod(other.m_validPeriod), m_stock(other.m_stock), m_price(other.m_price), m_discount(other.m_discount) {}

// 赋值运算符重载
GoodsInfo& GoodsInfo::operator=(const GoodsInfo& other) {
    if (this != &other) {
        m_id = other.m_id;
        m_name = other.m_name;
        m_date = other.m_date;
        m_validPeriod = other.m_validPeriod;
        m_stock = other.m_stock;
        m_price = other.m_price;
        m_discount = other.m_discount;
    }
    return *this;
}

// 获取和设置成员变量的方法
int GoodsInfo::getId() const {
    return m_id;
}

void GoodsInfo::setId(int id) {
    m_id = id;
}

std::string GoodsInfo::getName() const {
    return m_name;
}

void GoodsInfo::setName(const std::string& name) {
    m_name = name;
}

std::string GoodsInfo::getDate() const {
    return m_date;
}

void GoodsInfo::setDate(const std::string& date) {
    m_date = date;
}

int GoodsInfo::getValidPeriod() const {
    return m_validPeriod;
}

void GoodsInfo::setValidPeriod(int validPeriod) {
    m_validPeriod = validPeriod;
}

int GoodsInfo::getStock() const {
    return m_stock;
}

void GoodsInfo::setStock(int stock) {
    m_stock = stock;
}

double GoodsInfo::getPrice() const {
    return m_price;
}

void GoodsInfo::setPrice(double price) {
    m_price = price;
}

double GoodsInfo::getDiscount() const {
    return m_discount;
}

void GoodsInfo::setDiscount(double discount) {
    m_discount = discount;
}

// 打印商品信息的方法
void GoodsInfo::print() const {
    std::cout << "商品编号：" << m_id << std::endl;
    std::cout << "商品名称：" << m_name << std::endl;
    std::cout << "制作日期：" << m_date << std::endl;
    std::cout << "有效期：" << m_validPeriod << " 天" << std::endl;
    std::cout << "库存：" << m_stock << std::endl;
    std::cout << "售价：" << m_price << std::endl;
    std::cout << "折扣：" << m_discount << std::endl;
}