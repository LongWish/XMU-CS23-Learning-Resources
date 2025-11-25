
node* reverseList(node* head) 
{ //请将这函数补充完整
    struct node *h,*p1,*p2=NULL;
    h = head;
    while(h!=NULL)
    {
        p1 = (struct node*)malloc(sizeof(struct node));
        p1->val = h->val;
        p1->next = p2;
        p2 = p1;
        h = h->next;
    }
    return p2;
}