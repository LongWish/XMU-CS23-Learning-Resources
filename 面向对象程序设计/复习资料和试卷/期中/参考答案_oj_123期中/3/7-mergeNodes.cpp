
ListNode* mergeNodes(ListNode* head) {
	int count=0;
	ListNode dummy;
	ListNode *tail=&dummy;
	for(ListNode *p=head->next;p!=NULL;p=p->next)
	{
		if(p->val==0)
		{
			if(count>0)
			{
				tail->next=new ListNode;
				tail->next->val=count;
				tail=tail->next;
			}
			count=0;
		}
		else
		{
			count+=p->val; 
		 } 
		 
	 } 
	tail->next=NULL;
	return dummy.next;
	
}