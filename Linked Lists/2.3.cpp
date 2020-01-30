/*
Question:-Delete a given node in the list with access to only the nodes
Approach:-Copy the value of next node and rewire the list
Analysis:-Linear time and constant space
This is a bad question
*/

struct ListNode {
    int val;
    ListNode *next;

    explicit ListNode(int x) : val(x), next(nullptr) {}
};

void deleteNode(ListNode *node) {
    node->val = node->next->val;
    ListNode *temp = node->next->next;
    delete (node->next);
    node->next = temp;
}