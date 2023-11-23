#include <iostream>

#include "ListNode.h"

using namespace std;
// Runtime 7ms Beats 88.67%of users with C++
// Memory 8.52MB Beats 33.03%of users with C++
bool hasCycle(ListNode* head) {
  if (!head) {
    return false;
  }
  ListNode* slowPtr = head;
  ListNode* fastPtr = head;
  while (fastPtr && fastPtr->next) {
    slowPtr = slowPtr->next;
    fastPtr = fastPtr->next->next;
    if (slowPtr == fastPtr) {
      return true;
    }
  }
  return false;
}
// Runtime 10ms Beats 45.34%of users with C++
// Memory 8.5MB Beats 33.3%of users with C++
bool hasCycle2(ListNode* head) {
  if (!head) {
    return false;
  }
  ListNode* slowPtr = head;
  ListNode* fastPtr = head->next;
  while (fastPtr) {
    if (slowPtr == fastPtr) {
      return true;
    }
    slowPtr = slowPtr->next;
    fastPtr = fastPtr->next;
    if (!fastPtr) {
      break;
    }
    fastPtr = fastPtr->next;
  }
  return false;
}
// Runtime 11ms Beats 40.21%of users with C++
// Memory 8.56MB Beats 33.03%of users with C++
bool hasCycle3(ListNode* head) {
  ListNode* slowPtr = head;
  ListNode* fastPtr = head;
  while (fastPtr && fastPtr->next) {
    slowPtr = slowPtr->next;
    fastPtr = fastPtr->next->next;
    if (slowPtr == fastPtr) {
      return true;
    }
  }
  return false;
}
int main() {}