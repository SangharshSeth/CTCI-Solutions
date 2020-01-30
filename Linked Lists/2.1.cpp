/*
 * Que:-Write Code to remove duplicates form an unsorted list.
 * Approach:-Use a map to keep track of duplicate values and when encountered rewire the last unique node to next of the repeated node
 * Analysis:-This algorithm modifies the list in place with a Linear runtime O(N)
*/
#include<bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    explicit ListNode(int x) : val(x), next(nullptr) {}
};

void removeDuplicates(ListNode *head) {
    map<int, int> map;
    ListNode *temp = head;
    ListNode *prev = nullptr;
    while (temp != nullptr) {
        int value = temp->val;
        if (map.find(value) == map.end()) {
            map[value]++;
            prev = temp;
            temp = temp->next;

        } else {
            prev->next = temp->next;
            temp = temp->next;
        }

    }
}

/*
 * 2nd Approach(two pointers):- Use two pointers one to iterate over the linked list and another to check every other nodes for duplicated
 * Analysis:- Quadratic run-time O(N^2) and constant space O(1)
*/
void removeDuplicatesTwoPointer(ListNode *head) {
    ListNode *curr = head;
    ListNode *runner = nullptr;
    while (curr != nullptr) {
        runner = curr;
        while (runner->next != nullptr) {
            if (runner->next->val == curr->val) {
                runner->next = runner->next->next;

            } else {
                runner = runner->next;
            }
        }
        curr = curr->next;
    }
}

int main() {
    auto *head = new ListNode(1);
    head->next = new ListNode(1);
    head->next->next = new ListNode(22);
    head->next->next->next = new ListNode(1);
    head->next->next->next->next = new ListNode(21);
    removeDuplicatesTwoPointer(head);
    while (head != nullptr) {
        cout << head->val << " ";
        head = head->next;
    }


    return 0;
}