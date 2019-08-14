//反转一个单链表。
//
//示例:
//
//输入: 1->2->3->4->5->NULL
//输出: 5->4->3->2->1->NULL

class Solution {
  public:
    ListNode* reverseList(ListNode* head) {
      ListNode *cur = NULL;
      ListNode *node = head;
      while(node != NULL)
      {
        ListNode *next = node->next;

        node->next = cur;
        cur = node;

        node = next;
      }
      return cur;
    }
};
