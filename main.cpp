#include <iostream>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <map>
#include "LinkedList.h"

using namespace std;

int main() {
    // 1. Конструктор копирования
    LinkedList<int> list1;
    list1.add(1);
    list1.add(2);
    LinkedList<int> list2 = list1;  // копирование

    // 2. Оператор присваивания
    LinkedList<int> list3;
    list3 = list1;  // присваивание

    // 3. Самоприсваивание
    list1 = list1;  // не ломается

    // 4. Удаление разных случаев
    list1.delFirstFind(1);  // первого
    list1.delFirstFind(2);  // последнего

    LinkedList<int> list4;

    for (int i = 0; i < 10; i++) {
        list4.add(i);
    }
    list4.printAllNodes();
    return 0;  // деструкторы вызываются автоматически

    
}
