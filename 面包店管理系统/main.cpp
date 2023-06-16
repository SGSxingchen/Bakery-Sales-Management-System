#include "menu.h"
#include "UserList.h"
#include "DList.h"
#include "DListNode.h"
#include "GoodList.h"

UserList userlist;
GoodList goodlist;

void init() {

}
int main() {
    Menu menu;
    int num = 0;
    menu.menu(userlist,goodlist);
    return 0;
}