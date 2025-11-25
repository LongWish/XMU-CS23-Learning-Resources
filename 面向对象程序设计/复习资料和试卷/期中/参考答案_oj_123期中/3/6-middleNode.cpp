
ListNode* middleNode(ListNode* head) {
	int num = 0;
	for (ListNode* p = head; p != nullptr; p = p->next) num++;
	if (num == 0) return nullptr;
	int k = num / 2;
	ListNode* p = head;
	for (int cnt = 0; cnt < k; cnt++) {
		p = p->next;
	}
	return p;
}