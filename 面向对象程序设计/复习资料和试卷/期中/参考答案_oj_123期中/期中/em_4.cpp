#include <list>
#include <algorithm>
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

// ��ת�����ĺ���
ListNode* reverseList(ListNode* head) {
    ListNode* prev = nullptr;
    ListNode* curr = head;
    while (curr != nullptr) {
        ListNode* next_temp = curr->next;  // ������һ���ڵ�
        curr->next = prev;  // ��ת��ǰ�ڵ��ָ��
        prev = curr;  // �ƶ�prev��curr
        curr = next_temp;
    }
    return prev;  // �µ�ͷ�ڵ���prev
}

// ʵ�������������������
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    // �ȷ�ת��������
    l1 = reverseList(l1);
    l2 = reverseList(l2);

    ListNode* head = nullptr;  // ��������ͷ�ڵ�
    ListNode* tail = nullptr;  // �������ĵ�ǰ�ڵ�
    int carry = 0;  // ��λ

    while (l1 != nullptr || l2 != nullptr || carry) {
        int sum = carry;  // �ӽ�λ��ʼ��
        if (l1 != nullptr) {
            sum += l1->val;  // ���ϵ�һ�������ĵ�ǰλ
            l1 = l1->next;  // �ƶ�����һλ
        }
        if (l2 != nullptr) {
            sum += l2->val;  // ���ϵڶ��������ĵ�ǰλ
            l2 = l2->next;  // �ƶ�����һλ
        }

        // ȷ���½ڵ��ֵ���µĽ�λ
        int nodeValue = sum % 10;
        carry = sum / 10;

        // �����½ڵ㲢���뵽�������
        ListNode* newNode = new ListNode;
        if (head == nullptr) {
            head = tail = newNode;  // ��ʼ��ͷ�ڵ�
        }
        else {
            tail->next = newNode;  // ���½ڵ�ӵ�����β��
            tail = newNode;  // ����βָ��
        }
    }

    // ���ת���������������ȷ˳��Ľ��
    return reverseList(head);
}


int main() {
	ListNode* head1, * head2;
	head1 = createList();
	head2 = createList();
	ListNode* ans = addTwoNumbers(head1, head2);
	if (ans == NULL)
		cout << "-1";
	else {
		while (ans != NULL) {
			cout << ans->val << " ";
			ans = ans->next;
		}
		cout << -1;
	}
	return 0;
}
