
node* createList() {
    int value;
    cin >> value; // 读取第一个值

    // 如果第一个值就是-1，直接返回空指针
    if (value == -1) return nullptr;

    // 创建链表的头节点
    node* head = new node{ value, nullptr };
    node* tail = head; // 尾指针指向头节点

    while (cin >> value && value != -1) { // 循环读取直到-1
        tail->next = new node{ value, nullptr }; // 在尾部添加新节点
        tail = tail->next; // 更新尾指针
    }

    return head;
}