struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* deleteMiddle(ListNode* head) {
  if(!head->next){
    return nullptr;
  }
  ListNode* slow = head;
  ListNode* fast = head;
  ListNode* prev = head;
  while (fast && fast->next)
  {
    prev = slow;
    slow = slow->next;
    fast = fast->next->next; 
  }
  prev->next = slow->next;
  return head;
}
int main(){
  ListNode* n0 = new ListNode(0);
  deleteMiddle(n0);

  delete n0;
  return 0;
}