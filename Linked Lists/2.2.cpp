/*
 Question:- Remove nth node from end of the list
 Approach:- Find the location to remove the node at from start and rewire the previous
 node with the next node of the node to be removed if encountered
 Analysis:  Linear runtime as we have to traverse the list till end and O(1) space complexity as we modify the list inplace
*/

#include <bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    explicit ListNode(int x) : val(x), next(nullptr) {}
};

ListNode *removeNthFromEnd(ListNode *head, int n) {

    if (!head)
        return nullptr;
    int counter = 0;
    ListNode *curr = head;
    ListNode *prev;
    int size = 0;
    while (curr != nullptr) {
        size++;
        curr = curr->next;
    }
    if (size == 1)
        return nullptr;
    curr = head;
    int toremove = size - n;
    if (toremove == 0)
        return head->next;
    while (curr != nullptr) {
        counter++;
        prev = curr;
        curr = curr->next;
        if (counter == toremove) {
            prev->next = curr->next;
            break;
        } else
            continue;
    }
    return head;
}

int main() {
    // TO DO Test Program
    return 0;
}