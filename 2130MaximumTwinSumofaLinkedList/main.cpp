#include <vector>

struct ListNode
{
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

int pairSum(ListNode *head)
{
  std::vector<int> v;
  int max = INT32_MIN;
  while (head) {
    v.emplace_back(head->val);
    head = head->next;
  }
  for (int i = 0, j = v.size() - 1; i < j; ++i, --j) { max = std::max(v[i] + v[j], max); }

  return max;
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
  ListNode *n7 = new ListNode(8);
  n0->next = n1;
  n1->next = n2;
  n2->next = n3;
  n3->next = n4;
  n4->next = n5;
  n5->next = n6;
  n6->next = n7;

  pairSum(n0);
  return 0;
}
