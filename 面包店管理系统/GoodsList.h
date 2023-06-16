#pragma once
#include "DList.h"
#include "GoodsInfo.h"

class GoodsList : public DList<GoodsInfo> {
public:
    // ���캯������������
    GoodsList();
    virtual ~GoodsList();

    // ͨ����Ʒ��Ų�����Ʒ
    GoodsInfo* findByID(int id);

    // ͨ����Ʒ���Ʋ�����Ʒ
    GoodsInfo* findByName(const std::string& name);

    // �����Ʒ
    bool addGoods(const GoodsInfo& goods);

    // ɾ����Ʒ
    bool removeGoods(int id);

    // �޸���Ʒ
    bool modifyGoods(int id, const GoodsInfo& newGoods);

    // ������Ʒ
    bool buyGoods(int id, int quantity);
};
#pragma once
