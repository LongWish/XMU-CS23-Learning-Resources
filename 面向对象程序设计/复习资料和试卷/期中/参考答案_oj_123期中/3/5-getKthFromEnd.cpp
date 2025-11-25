
ListNode* reverseList(ListNode* head)
{ //请将这函数补充完整
    if(head==NULL)
        return head;

    ListNode *temp=NULL;
    ListNode *p=head;
    ListNode *q=head->next;
    while(q!=NULL)
    {
        temp=q->next;
        q->next=p;
        p=q;
        q=temp;
    }
    head->next=NULL;
    head=p;
    return head;
}

ListNode* getKthFromEnd(ListNode* head, int k) {
	// 本函数需要你补充完整
    if(!head)
        return NULL;
    ListNode *head1=NULL;
    head1=reverseList(head);
    for(int i=0;i<k;i++)
            head1=head1->next;
    return head1;
}