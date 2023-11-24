#include <iostream>
#include <vector>
#include "ListNode.h"

using namespace std;

//Runtime 30ms Beats 93.95%of users with C++
//Memory 15.12MB Beats 23.11%of users with C++
ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
  ListNode *ptrA = headA;
  ListNode *ptrB = headB;

  while (ptrA != ptrB) {
    ptrA = ptrA == nullptr ? headB : ptrA->next;
    ptrB = ptrB == nullptr ? headA : ptrB->next;
  }
  return ptrA;
}

// Runtime 556ms Beats 5.55%of users with C++
// Memory 14.83MB Beats 81.72%of users with C++
ListNode *getIntersectionNode2(ListNode *headA, ListNode *headB) {
  ListNode *copyHeadB = headB;
  while (headA) {
    while (headB) {
      if (headA == headB) {
        return headA;
      }
      headB = headB->next;
    }
    headB = copyHeadB;
    headA = headA->next;
  }
  return nullptr;
}
int main() {}