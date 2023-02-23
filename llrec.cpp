#include "llrec.h"

//*********************************************
// Provide your implementation of llpivot below
//*********************************************

void llpivot(Node *&head, Node *&smaller, Node *&larger, int pivot) {
  //function is done if head is NULL
  //sets both smaller and larger to the current value
  smaller = head;
  larger = head;

  /*
  * 0 means the current value is smaller
  * 1 means the current value is larger
  */
  int state = 0;
  //if either the smaller or larger are NULL, the function is done
  if (smaller == NULL) {
    return;
  }
  //if the value is wrong, the value should be cleared out and recursive call ends
  else if (smaller->val > pivot) {
    smaller = NULL;
    state = 1;
  }

  //if either the smaller or larger are NULL, the function is done
  if (larger == NULL) {
    return;
  }
  //if the value is wrong, the value should be cleared out and recursive call ends
  else if (larger->val <= pivot) {
    larger = NULL;
  }

  //increments head
  head = head->next;
  
  //only calls recursively if the head is not NULL, or else the function ends
  if (head != NULL) {
    //checks which smaller or larger should be incremented
    if (state == 0) {
      llpivot(head, smaller->next, larger, pivot);
    }
    else {
      llpivot(head, smaller, larger->next, pivot);
    }
  }
}


