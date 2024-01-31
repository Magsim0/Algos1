#include "List.h"
#include <cstdlib>
#include <ctime> 
#include <iostream>
#include <fstream>
#include <stdio.h>
#include "defs_with_list.h"

using namespace std;

void displayList(const Node* head) {
    const Node* current = head;

    while (current != nullptr) {
        std::cout << current->number << " ";
        current = current->next;
    }

    std::cout << std::endl;
}
// 1. Добавление в конец списка
void insert_end (Node*& head, float value) {
    Node* newNode = new Node;
    newNode->number = value;
    newNode->next = nullptr;

    if (head == nullptr) {
        head = newNode;
    }
    else {
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// 2. Добавление в начало списка
void insert_beg(Node*& head, float value) {
    Node* newNode = new Node;
    newNode->number = value;
    newNode->next = head;
    head = newNode;
}

// 3. Удаление последнего элемента
void delete_last_node(Node*& head) {
    if (head == nullptr) {
        return;  
    }

    if (head->next == nullptr) {
        delete head;
        head = nullptr;
        return;  
    }

    Node* temp = head;
    while (temp->next->next != nullptr) {
        temp = temp->next;
    }

    delete temp->next;
    temp->next = nullptr;
}

// 4. Удаление первого элемента
void delete_beg_node(Node*& head) {
    if (head == nullptr) {
        return; 
    }

    Node* temp = head;
    head = head->next;
    delete temp;
}

// 5. Добавление элемента по индексу
void insert_at_index(Node*& head, float value, int index) {
    if (index < 0) {
        return;  
    }

    if (index == 0) {
        insert_beg(head, value);
        return;
    }

    Node* newNode = new Node;
    newNode->number = value;

    Node* temp = head;
    for (int i = 0; i < index - 1 && temp != nullptr; ++i) {
        temp = temp->next;
    }

    if (temp == nullptr) {
        delete newNode;
        return; 
    }

    newNode->next = temp->next;
    temp->next = newNode;
}

// 6. Получение элемента по индексу
float get_at_index(const Node* head, int index) {
    const Node* temp = head;

    for (int i = 0; i < index && temp != nullptr; ++i) {
        temp = temp->next;
    }

    if (temp == nullptr) {
        return 0.0;
    }

    return temp->number;
}

// 7. Удаление элемента по индексу
void delete_at_index(Node*& head, int index) {
    if (index < 0 || head == nullptr) {
        return; 
    }

    if (index == 0) {
        delete_beg_node(head);
        return;
    }

    Node* temp = head;
    for (int i = 0; i < index - 1 && temp != nullptr; ++i) {
        temp = temp->next;
    }

    if (temp == nullptr || temp->next == nullptr) {
        return;  
    }

    Node* nodeToDelete = temp->next;
    temp->next = temp->next->next;
    delete nodeToDelete;
}

// 8. Получение размера списка
int get_size(const Node* head) {
    int size = 0;
    const Node* temp = head;

    while (temp != nullptr) {
        ++size;
        temp = temp->next;
    }

    return size;
}

// 9. Удаление всех элементов списка
void delete_List(Node*& head) {
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

// 10. Замена элемента по индексу на передаваемый элемент
void replace_at_index(Node* head, int index, float newValue) {
    Node* temp = head;

    for (int i = 0; i < index && temp != nullptr; ++i) {
        temp = temp->next;
    }

    if (temp != nullptr) {
        temp->number = newValue;
    }
}

// 11. Проверка на пустоту списка
bool isempty(const Node* head) {
    return head == nullptr;
    
}

// 12. Меняет порядок элементов в списке на обратный
void reverse_List(Node*& head) {
    Node* prev = nullptr;
    Node* current = head;
    Node* next = nullptr;

    while (current != nullptr) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    head = prev;
}

// 13. Вставка другого списка в список, начиная с индекса
void insert_List_at_index(Node*& destHead, const Node* srcHead, int index) {
    if (index < 0 || srcHead == nullptr) {
        return; 
    }

    Node* temp = destHead;
    for (int i = 0; i < index - 1 && temp != nullptr; ++i) {
        temp = temp->next;
    }

    if (temp == nullptr) {
        return;  
    }

    // Копирование srcList в destList
    Node* newNodes = nullptr;
    const Node* srcTemp = srcHead;
    while (srcTemp != nullptr) {
        Node* newNode = new Node;
        newNode->number = srcTemp->number;
        newNode->next = nullptr;

        if (newNodes == nullptr) {
            newNodes = newNode;
        }
        else {
            Node* lastNode = newNodes;
            while (lastNode->next != nullptr) {
                lastNode = lastNode->next;
            }
            lastNode->next = newNode;
        }

        srcTemp = srcTemp->next;
    }

    // Вставка newNodes в destList
    if (temp->next == nullptr) {
        temp->next = newNodes;
    }
    else {
        Node* tail = newNodes;
        while (tail->next != nullptr) {
            tail = tail->next;
        }
        tail->next = temp->next;
        temp->next = newNodes;
    }
}

// 14. Вставка другого списка в конец
void insert_List(Node*& destHead, const Node* srcHead) {
    if (srcHead == nullptr) {
        return; 
    }

    if (destHead == nullptr) {
        destHead = new Node(*srcHead);
        return; 
    }

    Node* temp = destHead;
    while (temp->next != nullptr) {
        temp = temp->next;
    }

    // Копирование srcList в destList
    const Node* srcTemp = srcHead;
    while (srcTemp != nullptr) {
        Node* newNode = new Node;
        newNode->number = srcTemp->number;
        newNode->next = nullptr;

        temp->next = newNode;
        temp = temp->next;

        srcTemp = srcTemp->next;
    }
}

// 15. Вставка другого списка в начало
void insert_beg_List(Node*& destHead, const Node* srcHead) {
    if (srcHead == nullptr) {
        return;  
    }

    const Node* srcTemp = srcHead;
    while (srcTemp != nullptr) {
        Node* newNode = new Node;
        newNode->number = srcTemp->number;
        newNode->next = destHead;

        destHead = newNode;

        srcTemp = srcTemp->next;
    }
}

// 16. Проверка на содержание другого списка в списке
bool contains_List(const Node* list, const Node* subList) {
    const Node* current = list;

    while (current != nullptr) {
        const Node* subListCurrent = subList;
        const Node* currentOriginal = current;

        while (subListCurrent != nullptr && currentOriginal != nullptr && subListCurrent->number == currentOriginal->number) {
            subListCurrent = subListCurrent->next;
            currentOriginal = currentOriginal->next;
        }

        if (subListCurrent == nullptr) {
            return true; 
        }

        current = current->next;
    }

    return false;  
}

// 17. Поиск первого вхождения другого списка в список
int find_first_occurrence(const Node* list, const Node* subList) {
    const Node* current = list;
    int index = 0;

    while (current != nullptr) {
        const Node* subListCurrent = subList;
        const Node* currentOriginal = current;
        int subListIndex = index;

        while (subListCurrent != nullptr && currentOriginal != nullptr && subListCurrent->number == currentOriginal->number) {
            subListCurrent = subListCurrent->next;
            currentOriginal = currentOriginal->next;
            ++subListIndex;
        }

        if (subListCurrent == nullptr) {
            return index; 
        }

        current = current->next;
        ++index;
    }

    return -1;  
}

// 18. Поиск последнего вхождения другого списка в список
int find_last_occurrence(const Node* list, const Node* subList) {
    const Node* current = list;
    int index = 0;
    int lastOccurrenceIndex = -1;

    while (current != nullptr) {
        const Node* subListCurrent = subList;
        const Node* currentOriginal = current;
        int subListIndex = index;

        while (subListCurrent != nullptr && currentOriginal != nullptr && subListCurrent->number == currentOriginal->number) {
            subListCurrent = subListCurrent->next;
            currentOriginal = currentOriginal->next;
            ++subListIndex;
        }

        if (subListCurrent == nullptr) {
            lastOccurrenceIndex = subListIndex;  
        }

        current = current->next;
        ++index;
    }

    return lastOccurrenceIndex;  
}

// 19. Обмен двух элементов списка по индексам
void swap_elements(Node*& head, int index1, int index2) {
    if (index1 == index2) {
        return;  
    }
    Node* prev1 = nullptr;
    Node* current1 = head;
    for (int i = 0; i < index1 && current1 != nullptr; ++i) {
        prev1 = current1;
        current1 = current1->next;
    }

    Node* prev2 = nullptr;
    Node* current2 = head;
    for (int i = 0; i < index2 && current2 != nullptr; ++i) {
        prev2 = current2;
        current2 = current2->next;
    }

   
    if (current1 == nullptr || current2 == nullptr) {
        return;  
    }
    if (prev1 != nullptr) {
        prev1->next = current2;
    }
    else {
        head = current2;
    }

    if (prev2 != nullptr) {
        prev2->next = current1;
    }
    else {
        head = current1;
    }

    Node* temp = current1->next;
    current1->next = current2->next;
    current2->next = temp;
}
