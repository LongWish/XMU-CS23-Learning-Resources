
node* merge(node* head1, node* head2)
{
  if (head1 == NULL)
        return head2;
    if (head2 == NULL)
        return head1;

    node* mergedHead = NULL;
    if (head1->val < head2->val)
    {
        mergedHead = head1;
        head1 = head1->next;
    }
    else
    {
        mergedHead = head2;
        head2 = head2->next;
    }

    node* curr = mergedHead;
    while (head1 != NULL && head2 != NULL)
    {
        if (head1->val < head2->val)
        {
            curr->next = head1;
            head1 = head1->next;
        }
        else
        {
            curr->next = head2;
            head2 = head2->next;
        }
        curr = curr->next;
    }

    if (head1 != NULL)
        curr->next = head1;
    else
        curr->next = head2;

    return mergedHead;

}