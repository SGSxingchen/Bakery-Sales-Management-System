#pragma once
#include "DList.h"
#include "GoodsInfo.h"

class GoodsList : public DList<GoodsInfo> {
public:
    // 构造函数和析构函数
    GoodsList();
    virtual ~GoodsList();

    // 通过商品编号查找商品
    GoodsInfo* findByID(int id);

    // 通过商品名称查找商品
    GoodsInfo* findByName(const std::string& name);

    // 添加商品
    bool addGoods(const GoodsInfo& goods);

    // 删除商品
    bool removeGoods(int id);

    // 修改商品
    bool modifyGoods(int id, const GoodsInfo& newGoods);

    // 购买商品
    bool buyGoods(int id, int quantity);
};
#pragma once
