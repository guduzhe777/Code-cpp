/*

 *
 * [206] 反转链表
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

//         递归
//找到最后一个 及 最后一个的前一个
//修改 最后一个  保存返回值  用于当头节点 开始输出
//最后返回new_head 一直指向头节点  
//因为他仅仅在 head 为指向最后一个节点的时候被改变 其他时间一直返回本身

// class Solution {
// public:
//     ListNode* reverseList(ListNode* head) {
//         递归
//     if((head == NULL)||(head->next == NULL))
//     {
//         return head;
//     }
//         ListNode* new_node = reverseList(head->next);
//         head->next->next = head;
//         head->next = NULL;
//         return new_node;
//     }
// };

//迭代
//保存next  用于指向下一个 进行修改
//保存指向前一个的指针   用于指向前一个
//curr  用于 指向需要修改节点
//最后curr 为空  前一个地址为prev  返回头节点输出
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
    ListNode* next,*prev,*curr;

    curr = head;    //指向需要修改节点
    prev = NULL;    //用于指向前一个
    while(curr){
        next = curr->next;
        curr->next = prev;
        prev = curr;

        curr = next;
    }
    
    }
    return prev;
};
// @lc code=end

  