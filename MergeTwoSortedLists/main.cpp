#include <iostream>
#include <map>
#include <string>

using namespace std;
struct ListNode {
  int val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}
};

ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    ListNode* anwser;
    ListNode* tail;
    if (!list1) {
        return list2;
    } else if (!list2) {
        return list1;
    }

    if(list1->val <= list2->val){
        anwser =list1;
        list1 = list1->next;
    }
    else{
        anwser = list2;
        list2= list2->next;
    }
    tail = anwser;

    while (list1 != nullptr && list2!=nullptr){
        ListNode* temp = nullptr;
        if(list1->val <= list2->val){
            temp =list1;
            list1 = list1->next;
        }
        else{
            temp = list2;
            list2= list2->next;
        }
        tail->next = temp;
        tail=temp;
    }
    tail->next = list1 ? list1 : list2;
    return anwser;
}

void printListNode(ListNode* list){
  while (list!=nullptr)
  {
    cout<< list->val << endl;
    list=list->next;
  }
  
}

int main() {
  ListNode l1;
  ListNode l11(3);
  ListNode l111(5);
  ListNode l2(2);
  ListNode l22(6);
  l1.next = &l11;
  l11.next = &l111;
  l2.next = &l22;
  
  mergeTwoLists(&l1,&l2);
  
}