#include "List.h"
#include "defs_with_list.h"
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <chrono>


using namespace std; 

int main()
{
    setlocale(LC_ALL, "Russian");
    Node* myList = nullptr;

    for (int i = 0; i < 300; ++i) {
        float randomValue = static_cast<float>(rand()) / RAND_MAX;
        insert_end(myList, randomValue);
    }
    Node* anotherList = nullptr;
    for (int i = 0; i < 150; ++i) {
        float randomValue = static_cast<float>(rand()) / RAND_MAX;
        insert_end(anotherList, randomValue);
    }
    
   cout << "Время работы функции в наносекундах: "<<endl;
    //displayList(myList);

    auto start1 = chrono::steady_clock::now();
    insert_end(myList, 1.23);
    auto end1 = chrono::steady_clock::now();
    chrono::duration<float> duration1 = end1 - start1;
    cout <<"insert_end =" << duration1.count() * 1e9 << endl;

    //cout << " " << endl;
    // 2. Добавление в начало списка
    auto start2 = chrono::steady_clock::now();
    insert_beg(myList, 1.87);
    auto end2 = chrono::steady_clock::now();
    chrono::duration<float> duration2 = end2 - start2;
    cout  <<"insert_beg  = "<< duration2.count() * 1e9 << endl;
    //cout << " " << endl;
    // 3. Удаление последнего элемента
    auto start3 = chrono::steady_clock::now();
    delete_last_node(myList);
    auto end3 = chrono::steady_clock::now();
    chrono::duration<float> duration3 = end3 - start3;
    cout  <<"delete_last_node = "<< duration3.count() * 1e9  << endl;
    //cout << " " << endl;
    // 4. Удаление первого элемента
    auto start4 = chrono::steady_clock::now();
    delete_beg_node(myList);
    auto end4 = chrono::steady_clock::now();
    chrono::duration<float> duration4 = end4 - start4;
    cout  <<"delete_beg_node = "<< duration4.count() * 1e9  << endl;
    //cout << " " << endl;
    // 5. Добавление элемента по индексу
    auto start5 = chrono::steady_clock::now();
    insert_at_index(myList, 1.23, 2);
    auto end5 = chrono::steady_clock::now();
    chrono::duration<float> duration5 = end5 - start5;
    cout  <<"insert_at_index  = "<< duration5.count() * 1e9  << endl;
    //cout << " " << endl;

    // 6. Получение элемента по индексу
    auto start6 = chrono::steady_clock::now();
    float valueAtIndex = get_at_index(myList, 3);
    auto end6 = chrono::steady_clock::now();
    chrono::duration<float> duration6 = end6 - start6;
    cout  <<"get_at_index  = "<< duration6.count() * 1e9  << endl;
    //cout << " " << endl;
    // 7. Удаление элемента по индексу
    auto start7 = chrono::steady_clock::now();
    delete_at_index(myList, 4);
    auto end7 = chrono::steady_clock::now();
    chrono::duration<float> duration7 = end7 - start7;
    cout <<"delete_at_index  = "<< duration7.count() * 1e9  << endl;
    //cout << " " << endl;
    // 8. Получение размера списка
    auto start8 = chrono::steady_clock::now();
    int sizeOfList = get_size(myList);
    auto end8 = chrono::steady_clock::now();
    chrono::duration<float> duration8 = end8 - start8;
    cout <<"get_size ="<< duration8.count() * 1e9 << endl;
    //cout << " " << endl;
    
    // 10. Замена элемента по индексу на передаваемый элемент
    auto start10 = chrono::steady_clock::now();
    replace_at_index(myList, 1, 77.77);
    auto end10 = chrono::steady_clock::now();
    chrono::duration<float> duration10 = end10 - start10;
    cout <<"replace_at_index=" <<  duration10.count() * 1e9 << endl;
    //cout << " " << endl;
    // 11. Проверка на пустоту списка
    auto start11 = chrono::steady_clock::now();
    bool isEmpty = isempty(myList);
    auto end11 = chrono::steady_clock::now();
    chrono::duration<float> duration11 = end11 - start11;
    cout <<"isempty = "<< duration11.count() * 1e9  << endl;
    //cout << " " << endl;
    // 12. Меняет порядок элементов в списке на обратный
    auto start12 = chrono::steady_clock::now();
    reverse_List(myList);
    auto end12 = chrono::steady_clock::now();
    chrono::duration<float> duration12 = end12 - start12;
    cout <<"reverse_List = "<< duration12.count() * 1e9  << endl;

    //cout << " " << endl;
    
    // 13. Вставка другого списка в список, начиная с индекса
    auto start13 = chrono::steady_clock::now();
    insert_List_at_index(myList, anotherList, 2);
    auto end13 = chrono::steady_clock::now();
    chrono::duration<float> duration13 = end13 - start13;
    cout  <<"insert_List_at_index = "<< duration13.count() * 1e9  << endl;
    //cout << " " << endl;
    // 14. Вставка другого списка в конец
    auto start14 = chrono::steady_clock::now();
    insert_List(myList, anotherList);
    auto end14 = chrono::steady_clock::now();
    chrono::duration<float> duration14 = end14 - start14;
    cout  <<"insert_List  = "<< duration14.count() * 1e9  << endl;
    //cout << " " << endl;
    // 15. Вставка другого списка в начало
        auto start15 = chrono::steady_clock::now();
    insert_beg_List(myList, anotherList);
    auto end15 = chrono::steady_clock::now();
    chrono::duration<float> duration15 = end15 - start15;
    cout  <<"insert_beg_List = "<< duration15.count() * 1e9  << endl;
    //cout << " " << endl;
    // 16. Проверка на содержание другого списка в списке
    auto start16 = chrono::steady_clock::now();
    bool containsOtherList = contains_List(myList, anotherList);
    auto end16 = chrono::steady_clock::now();
    chrono::duration<float> duration16 = end16 - start16;
    cout  <<"contains_List = "<< duration16.count() * 1e9  << endl;
    //cout << " " << endl;
    // 17. Поиск первого вхождения другого списка в список
    auto start17 = chrono::steady_clock::now();
    int firstOccurrence = find_first_occurrence(myList, anotherList);
    auto end17 = chrono::steady_clock::now();
    chrono::duration<float> duration17 = end17 - start17;
    cout  <<"find_first_occurrence  = "<< duration17.count() * 1e9  << endl;
    //cout << " " << endl;
    // 18. Поиск последнего вхождения другого списка в список
    auto start18 = chrono::steady_clock::now();
    int lastOccurrence = find_last_occurrence(myList, anotherList);
    auto end18 = chrono::steady_clock::now();
    chrono::duration<float> duration18 = end18 - start18;
    cout  <<"find_last_occurrence = "<< duration18.count() * 1e9  << endl;
    ////cout << " " << endl;
    // 19. Обмен двух элементов списка по индексам
    auto start19 = chrono::steady_clock::now();
    swap_elements(myList, 1, 4);
    auto end19 = chrono::steady_clock::now();
    chrono::duration<float> duration19 = end19 - start19;
    cout  <<"swap_elements  = "<< duration19.count() * 1e9  << endl;
   // //cout << " " << endl;
    // 9. Удаление всех элементов списка
    auto start9 = chrono::steady_clock::now();
    delete_List(myList);
    auto end9 = chrono::steady_clock::now();
    chrono::duration<float> duration9 = end9 - start9;
    cout  <<" delete_List = "<< duration9.count() * 1e9  << endl;
    delete_List(anotherList);
 }
