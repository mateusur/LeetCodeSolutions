struct ListNode
{
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *oddEvenList(ListNode *head)
{
  if (!head) { return nullptr; }

  ListNode *even_begin = head->next;
  ListNode *odd = head;
  ListNode *even = head->next;
  while (odd && even && even->next) {
    odd->next = even->next;
    odd = even->next;
    even->next = odd->next;
    even = odd->next;
  }
  odd->next = even_begin;
  return head;
}

int main()
{
  ListNode *n0 = new ListNode(1);
  ListNode *n1 = new ListNode(2);
  ListNode *n2 = new ListNode(3);
  ListNode *n3 = new ListNode(4);
  ListNode *n4 = new ListNode(5);
  ListNode *n5 = new ListNode(6);
  ListNode *n6 = new ListNode(7);
  n0->next = n1;
  n1->next = n2;
  n2->next = n3;
  n3->next = n4;
  n4->next = n5;
  n5->next = n6;

  oddEvenList(n0);
  return 0;
}
