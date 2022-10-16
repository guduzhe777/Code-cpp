// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem206.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=206 lang=cpp
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

//迭代
//找到最后一个 和前一个交换
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        
        //递归 找到最后一个 指向改变
        //一直返回最后一个节点
        //防止传入空节点
        // if((head == NULL)||(head->next == NULL))
        // {
        //     return head;
        // }
        // ListNode* new_Node = reverseList(head->next);//始终为最后一个
        // head->next->next = head;
        // head->next = NULL;

        // return new_Node;
    // ListNode* next,*prev,*curr;

    // curr = head;    //指向需要修改节点
    // prev = NULL;    //用于指向前一个
    // while(curr){
    //     next = curr->next;
    //     curr->next = prev;
    //     prev = curr;

    //     curr = next;
    // }
    // return prev;



    //迭代
    //从前到后  一组一组交换
    //保存前一个用于赋值  下一个--找到下一个
    //curr表示当前  用于 对某个节点操作到空截止 

    ListNode*prev,*curr,*next;

    curr = head;

    prev = NULL;
    
    while(curr){
        next = curr->next;  //必须保存不然找不到下一个了
        curr->next = prev;
        prev = curr;
        curr = next;
     }
     return prev;
    } 
    
};
// @lc code=end

