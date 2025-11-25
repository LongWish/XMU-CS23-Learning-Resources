#include <iostream>
using namespace std;
struct ListNode
{
    int val;
    ListNode* next;
};
ListNode* createList()
{
    ListNode* head = NULL;
    ListNode* p1, * p2;
    p1 = new ListNode;
    p2 = p1;
    cin >> p1->val;
    while (p1->val != -1)
    {
        if (head == NULL)
            head = p1;
        else p2->next = p1;
        p2 = p1;
        p1 = new struct ListNode;
        cin >> p1->val;
    }
    p2->next = NULL;
    delete p1;
    return head;
}

int isPalindrome(ListNode* head) {
    if (!head || !head->next) return 1;  // 如果链表为空或仅有一个元素，则直接返回是回文

    // 步骤1：找到链表的中点
    ListNode* slow = head;
    ListNode* fast = head;
    while (fast->next && fast->next->next) {
        slow = slow->next;  // 慢指针每次移动一步
        fast = fast->next->next;  // 快指针每次移动两步
    }

    // 步骤2：反转后半部分链表
    ListNode* secondHalf = slow->next;  // 后半部分的起始点
    ListNode* prev = nullptr;
    ListNode* temp = nullptr;
    while (secondHalf) {
        temp = secondHalf->next;
        secondHalf->next = prev;  // 反转指针
        prev = secondHalf;
        secondHalf = temp;
    }
    secondHalf = prev;  // 此时prev是反转后的后半部分的新头节点

    // 步骤3：比较两个链表的前半部和反转后的后半部
    ListNode* firstHalf = head;
    while (secondHalf) {
        if (firstHalf->val != secondHalf->val) {
            return 0;  // 如果有不相等的值，则不是回文
        }
        firstHalf = firstHalf->next;
        secondHalf = secondHalf->next;
    }

    return 1;  // 是回文
}



int main() {
    ListNode* head;
    head = createList();
    int ans = isPalindrome(head);
    cout << ans << '\n';
    return 0;
}
