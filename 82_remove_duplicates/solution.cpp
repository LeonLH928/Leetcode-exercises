#include <iostream>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* prevP = nullptr;
        ListNode* p = head;
        while (p != nullptr) {
            ListNode *pNext = p -> next;
            bool dup = false;
            while (pNext != nullptr && pNext -> val == p -> val) {
                dup = true;
                p -> next = pNext -> next;
                delete pNext;
                pNext = p -> next;
            }
            if (dup) {
                delete p;
                if (prevP == nullptr) {
                    head = p = pNext;
                }
                else {
                    prevP -> next = p = pNext;
                }
            }
            else {
                prevP = p;
                p = p -> next;
            }
        }
        return head;
    }
};
void printList(ListNode *head) {
    while (head != nullptr) {
        cout << head -> val << ' ';
        head = head ->next; 
    }
    cout << '\n';
}
int main() {
    ListNode *head = new ListNode(1);
    ListNode *p = head;
    p->next = new ListNode(2);
    p = p->next;
    p->next = new ListNode(3);
    p = p->next;
    p->next = new ListNode(3);
    p = p->next;
    p->next = new ListNode(4);
    p = p->next;
    p->next = new ListNode(4);
    p = p->next;
    p->next = new ListNode(5);

    Solution s;
    printList(head);
    head = s.deleteDuplicates(head);
    printList(head);
}