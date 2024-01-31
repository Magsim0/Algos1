#pragma once
#include "List.h"
#include<stdio.h>

void displayList(const Node* head);
void insert_end(Node*& head, float value);
void insert_beg(Node*& head, float value);
void delete_last_node(Node*& head);
void delete_beg_node(Node*& head);
void insert_at_index(Node*& head, float value, int index);
float get_at_index(const Node* head, int index);
void delete_at_index(Node*& head, int index);
int get_size(const Node* head);
void delete_List(Node*& head);
void replace_at_index(Node* head, int index, float newValue);
bool isempty(const Node* head);
void reverse_List(Node*& head);
void insert_List_at_index(Node*& destHead, const Node* srcHead, int index);
void insert_List(Node*& destHead, const Node* srcHead);
void insert_beg_List(Node*& destHead, const Node* srcHead);
bool contains_List(const Node* list, const Node* subList);
int find_first_occurrence(const Node* list, const Node* subList);
int find_last_occurrence(const Node* list, const Node* subList);
void swap_elements(Node*& head, int index1, int index2);