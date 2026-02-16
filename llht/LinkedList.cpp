#include <cstdlib>

#include "LinkedList.hpp"
#include "LinkedList_priv.hpp"

///////////////////////////////////////////////////////////////////////////////
// LinkedList implementation.

LinkedList* LinkedList_New() {
  // TODO: allocate the LinkedList struct and initialize the newly allocated
  // record structure.
  LinkedList* list = new LinkedList;
  if (list == nullptr) {
    return nullptr;
  }
  list->num_elements = 0;
  list->head = nullptr;
  list->tail = nullptr;
  return list;

  // you may want to change this
}

void LinkedList_Delete(LinkedList* list,
                       LLPayloadFreeFnPtr payload_free_function) {
  // TODO: sweep through the list and deallocate all of the nodes' payloads
  // (using the payload_free_function supplied as an argument) and
  // the nodes themselves.

  // delete the LinkedList
  if (list == nullptr) {
    return;
  }

  LinkedListNode* curr = list->head;
  while (curr != nullptr) {
    LinkedListNode* nxt = curr->next;

    if (payload_free_function != nullptr) {
      payload_free_function(curr->payload);
    }
    delete curr;
    curr = nxt;
  }

  delete list;
}

size_t LinkedList_NumElements(LinkedList* list) {
  return list->num_elements;
}

void LinkedList_Push(LinkedList* list, LLPayload_t payload) {
  // TODO: implement LinkedList_Push
  if (list == nullptr) {
    return;
  }
  LinkedListNode* new_node = new LinkedListNode;
  if (new_node == nullptr) {
    return;
  }
  new_node->payload = payload;
  new_node->next = list->head;
  new_node->prev = nullptr;
  if (list->head != nullptr) {
    list->head->prev = new_node;
  } else {
    list->tail = new_node;
  }
  list->head = new_node;
  list->num_elements++;
}

bool LinkedList_Pop(LinkedList* list, LLPayload_t* payload_ptr) {
  // TODO: implement LinkedList_Pop. Make sure you test for
  // and empty list and fail. If the list is non-empty, there
  // are two cases to consider: (a) a list with a single element in it
  // and (b) the general case of a list with >=2 elements in it.
  // Be sure to call delete to deallocate the memory that was
  // previously allocated by LinkedList_Push().
  if (list == nullptr || list->head == nullptr) {
    return false;
  }
  LinkedListNode* to_remove = list->head;
  *payload_ptr = to_remove->payload;

  list->head = to_remove->next;
  if (list->head != nullptr) {
    list->head->prev = nullptr;
  } else {
    list->tail = nullptr;
  }
  delete to_remove;
  list->num_elements--;
  return true;  // you may need to change this return value
}

void LinkedList_Append(LinkedList* list, LLPayload_t payload) {
  // TODO: implement LinkedList_Append. It's kind of like
  // LinkedList_Push, but obviously you need to add to the end
  // instead of the beginning.
  if (list == nullptr) {
    return;
  }
  LinkedListNode* new_node = new LinkedListNode;
  if (new_node == nullptr) {
    return;
  }
  new_node->payload = payload;
  new_node->next = nullptr;
  new_node->prev = list->tail;

  if (list->tail != nullptr) {
    list->tail->next = new_node;
  } else {
    list->head = new_node;
  }

  list->tail = new_node;
  list->num_elements++;
}

bool LinkedList_Slice(LinkedList* list, LLPayload_t* payload_ptr) {
  // TODO: implement LinkedList_Slice.
  if (list == nullptr || list->tail == nullptr) {
    return false;
  }
  LinkedListNode* to_remove = list->tail;
  *payload_ptr = to_remove->payload;
  list->tail = to_remove->prev;
  if (list->tail != nullptr) {
    list->tail->next = nullptr;
  } else {
    list->head = nullptr;
  }
  delete to_remove;
  list->num_elements--;
  return true;  // you may need to change this return value
}

///////////////////////////////////////////////////////////////////////////////
// LLIterator implementation.

LLIterator* LLIterator_New(LinkedList* list) {
  // TODO: implement
  if (list == nullptr) {
    return nullptr;
  }
  LLIterator* iter = new LLIterator;
  if (iter == nullptr) {
    return nullptr;
  }
  iter->list = list;
  iter->node = list->head;
  return iter;  // you may want to change this
}

// implemented for you
void LLIterator_Delete(LLIterator* iter) {
  delete iter;
}

bool LLIterator_IsValid(LLIterator* iter) {
  // TODO: implement
  if (iter == nullptr) {
    return false;
  }
  return iter->node != nullptr;  // you may want to change this
}

bool LLIterator_Next(LLIterator* iter) {
  // TODO: try to advance iterator to the next node and return true if
  // you succeed and are now on a new node, false otherwise
  if (iter == nullptr || iter->node == nullptr) {
    return false;
  }
  iter->node = iter->node->next;
  return iter->node != nullptr;  // you may need to change this return value
}

void LLIterator_Get(LLIterator* iter, LLPayload_t* payload) {
  // TODO: implement
  if (iter == nullptr || iter->node == nullptr) {
    return;
  }
  *payload = iter->node->payload;
}

bool LLIterator_Remove(LLIterator* iter,
                       LLPayloadFreeFnPtr payload_free_function) {
  // TODO: implement LLIterator_Remove. This is the most
  // complex function you'll build. There are several cases
  // to consider:
  // - degenerate case: the list becomes empty after deleting.
  // - degenerate case: iter points at head
  // - degenerate case: iter points at tail
  // - fully general case: iter points in the middle of a list,
  //   and you have to "splice".
  //
  // Be sure to call the payload_free_function to deallocate the payload
  // the iterator is pointing to, and also deallocate any LinkedList
  // data structure element as appropriate.
  if (iter == nullptr || iter->node == nullptr) {
    return false;
  }
  LinkedListNode* to_remove = iter->node;
  LinkedList* list = iter->list;
  if (payload_free_function != nullptr) {
    payload_free_function(to_remove->payload);
  }
  if (to_remove->prev != nullptr) {
    to_remove->prev->next = to_remove->next;
  } else {
    list->head = to_remove->next;
  }
  if (to_remove->next != nullptr) {
    to_remove->next->prev = to_remove->prev;
    iter->node = to_remove->next;
  } else {
    list->tail = to_remove->prev;
    iter->node = nullptr;
  }
  delete to_remove;
  list->num_elements--;
  return list->head != nullptr;
  // you may need to change this return value
}

// Implemented for you
void LLIterator_Rewind(LLIterator* iter) {
  iter->node = iter->list->head;
}
