//删除链表中等于给定值 val 的所有节点。
//
//示例:
//
//输入: 1->2->6->3->4->5->6, val = 6
//输出: 1->2->3->4->5

/*
 *   Definition for singly-linked list.
 *    struct ListNode {
 *         int val;
 *         ListNode *next;
 *           ListNode(int x) : val(x), next(NULL) {}
 *        };
 */
class Solution {
  public:
    ListNode* removeElements(ListNode* head, int val) {
      while(head != NULL && head->val == val)
      {
        head = head->next;
      }
      ListNode* cur = head;
      while(cur != NULL)
      {
        ListNode* tmp = cur->next;
        if(tmp != NULL && tmp->val == val)
        {
          cur->next = tmp->next;
          delete tmp;
        }
        else
        {
          cur = cur->next;
        }
      }
      return head;
    }
};
