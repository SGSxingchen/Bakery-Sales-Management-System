#pragma once
#ifndef BSMS_GOODSINFO_H
#define BSMS_GOODSINFO_H

#include <string>
class GoodsInfo {
public:
    // ���캯��
    GoodsInfo();
    GoodsInfo(int id, const std::string& name, const std::string& date, int validPeriod, int stock, double price, double discount);
    GoodsInfo(const std::string& id, const std::string& name, const std::string& date, const std::string& validPeriod, const std::string& stock, const std::string& price, const std::string& discount);

    // �������캯��
    GoodsInfo(const GoodsInfo& other);

    // ��ֵ���������
    GoodsInfo& operator=(const GoodsInfo& other);

    // ��ȡ�����ó�Ա�����ķ���
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

    // ��ӡ��Ʒ��Ϣ�ķ���
    void print() const;

private:
    int m_id; // ��Ʒ���
    std::string m_name; // ��Ʒ����
    std::string m_date; // ��������
    int m_validPeriod; // ��Ч��
    int m_stock; // ����
    double m_price; // �ۼ�
    double m_discount; // �ۿ�
};

#endif // GOODSINFO_H