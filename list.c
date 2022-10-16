// list/list.c
//
// Implementation for linked list.
//
// <Author>

#include <stdio.h>
#include <stdlib.h>
#include "list.h"

list_t *list_alloc() {return (list_t *) malloc(sizeof(list_t));}

void recurse_free(node_t *x){
  if (x) {
    recurse_free(x->next);
    free(x);
  }
}

void list_free(list_t *list){
    recurse_free(list->head);
    free(list);
}

void list_print(list_t *l) {
  node_t* itr = l->head;
  while(itr) {
    printf("%d->", itr->value);
    itr = itr->next;
  }
  printf("NULL\n");
}

int list_length(list_t *l) {
  node_t* itr = l->head;
  int i = 0;
  while(itr) {
    i++;
    itr = itr->next;
  }
  return i;
}

void list_add_to_back(list_t *l, elem value) {
  if (l->head){
    node_t* itr = l->head;
    while (itr->next) {
      itr = itr->next;
    }// go to last node in linked list^
    node_t* node = (node_t*)malloc(sizeof(node_t));
    node->value = value;
    itr->next = node;
    node->next = NULL;
  }
  else {
    list_add_to_front(l, value);
  }
}

void list_add_to_front(list_t *l, elem value) {
  node_t* node = (node_t*)malloc(sizeof(node_t));
  node->value = value;
  if (l->head != NULL){
    node->next = l->head;
    l->head = node;
  }
  else{
    node->next = NULL;
    l->head = node;
  }
}

void list_add_at_index(list_t *l, elem value, int index) {
  if (index == 0 || l->head == NULL){
    list_add_to_front(l, value);
  }
  else{
    node_t* itr = l->head;
    node_t* prev = NULL;
    int i = 0;
    while (itr && i < index) {
      i++;
      prev = itr;
      itr = itr->next;
    }
    if (itr == NULL && i == index){
      list_add_to_back(l, value);
    }
    else if (i == index){
      node_t* new_node = (node_t*)malloc(sizeof(node_t));
      new_node->value = value;
      new_node->next = prev->next;//new nodes next is the where the iterator at the prev element in link list next is
      prev->next = new_node; // insert new node into index in link list
    }
  }
}
elem list_remove_from_back(list_t *l) {
  if (l->head){
    node_t* itr = l->head;
    node_t* prev = NULL;
    while (itr->next) {
      prev = itr;
      itr = itr->next;
    }
    prev->next = itr->next;
    elem temp = itr->value;
    free(itr);
    return temp;
  }
  return -1;
}
elem list_remove_from_front(list_t *l) {
  if (l->head){
    node_t* itr = l->head;
    elem temp = itr->value;
    l->head = itr->next;
    free(itr);
    return temp;
  }
return -1;
}

elem list_remove_at_index(list_t *l, int index) {
  if (index == 0){
    return list_remove_from_front(l);
  }
  if (l->head){
    node_t* itr = l->head;
    node_t* prev = NULL;
    int i = 0;
    while (itr && i < index) {
      i++;
      prev = itr;
      itr = itr->next;
    }
    if (itr == NULL && i == index){
      return list_remove_from_back(l);
    }
    else if (i == index){
      elem temp = itr->value;
      prev->next = itr->next;
      free(itr);
      return temp;
    }
  }
return -1;
}

bool list_is_in(list_t *l, elem value) { 
  if (l->head){
    node_t* itr = l->head;
    while(itr){//is not None
      if (itr->value == value){
        return true;
      }
      itr=itr->next;
    }
  }//if goes through loop without returning its not in list
  return false; }

  elem list_get_elem_at(list_t *l, int index) {
  
  if (l->head){
    node_t* itr = l->head;
    int i = 0;
    while(itr){//iterate through linked list until i = index
      if (i == index){
        return itr->value;
      }
      i++;
      itr=itr->next;
    }
  }
  
  return -1; 
}

int list_get_index_of(list_t *l, elem value) { 
  
   if (l->head){
    node_t* itr = l->head;
    int i = 0;
    while(itr){
      if (itr->value == value){//return index when itr.value is = to input val
        return i;
      }
      i++;
      itr=itr->next;
    }
  }
  
  return -1; 
}
