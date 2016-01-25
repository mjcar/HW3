#include <assert.h>
#include <stdlib.h>

#include "list.h"

// Takes a valid, sorted list starting at `head` and adds the element
// `new_element` to the list. The list is sorted based on the value of the
// `index` member in ascending order. Returns a pointer to the head of the list
// after the insertion of the new element.
list_t* insert_sorted(list_t* head, list_t* new_element) {
    assert(head != NULL);
    assert(new_element != NULL);
    list_t* prev; 
    list_t* curr;
    uint32_t new_index = new_element->index;
    if(new_index < head->index){
       new_element->next = head;
       head =  new_element;
       return head;
    }
    else{
         prev = head;
         while(prev->next != NULL){
            curr = prev->next;
            if(new_index < curr->index){
               prev->next = new_element;
               new_element->next = curr; 
               return head;
            }
            prev = curr;
          }
          if(prev->next== NULL){
               prev->next = new_element;
               new_element->next = NULL;
               return head; 
         }
    }
}

// Reverses the order of the list starting at `head` and returns a pointer to
// the resulting list. You do not need to preserve the original list.
list_t* reverse(list_t* head) {
    assert(head != NULL);
    list_t* first;
    list_t* sec;
    list_t* third;
    if(head->next == NULL){
        return head;
    } 
    else{
            sec = head->next;
            first = head;
            if(sec->next == NULL){
                 sec->next =  first;
                 first->next = NULL;
                 head = sec;
                 return head; 
            }
            else{ 
                 while(sec->next != NULL){
                    third = sec->next;
                    sec->next = first;
                    first = sec;
                    sec = third;
                 }
                 sec->next =  first;
                 head->next = NULL;
                 head = sec;
                 return head;
             }
       }
}
