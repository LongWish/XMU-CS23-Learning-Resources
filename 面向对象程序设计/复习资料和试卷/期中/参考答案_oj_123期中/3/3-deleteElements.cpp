
node* deleteElements(node* head, int v) 
{ // 请将这函数补充完整
  while (head != NULL && head->val == v) {
        //node* p3 = head;
        head = head->next;
        //delete p3;
    }
    if (head == NULL) return NULL;

    node* p1 = head, *p2 = NULL;
    while (p1 != NULL) {
        p2 = p1->next;
        while (p2 != NULL && p2->val == v) {
            p2 = p2->next;
            //delete p2;
        }
        p1->next = p2;
        p1 = p1->next;
    }
    return head;
}