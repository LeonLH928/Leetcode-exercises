struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return head;
        ListNode* p = head;

        ListNode* node1 = p;
        ListNode* node2 = p->next;
        // First swap
        node1->next = node2->next;
        node2->next = node1;
        head = node2;

        // now p is the previous ptr
        while (p -> next != nullptr) {
            ListNode* prev = p;
            node1 = p -> next;
            if (node1 -> next != nullptr) {
                node2 = node1 -> next;
            }
            else {
                break;
            }
            ListNode *next = node2 -> next;
            prev -> next = node2;
            node2 -> next = node1;
            node1 -> next = next;
            p = node1;
        }
        return head;
    }
};