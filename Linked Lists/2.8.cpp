//Detect Cycle in a linked list
//Floyd cycle detection algorithm
//Linear time complexity O(N) and constant space O(1)

struct ListNode {
    int val;
    ListNode *next;

    explicit ListNode(int x) : val(x), next(nullptr) {}
};
 ListNode *detectCycle(ListNode *head) {
                ListNode* cache = head;
        ListNode* slow = head;
        ListNode* fast = head;
        bool ans = false;
        while(slow != nullptr and fast != nullptr and fast->next != nullptr){
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast){
               slow = head;
                while(slow != fast){
                    slow = slow->next;
                    fast = fast->next;
                }
                return slow;
            }
        }
        return nullptr;
    }