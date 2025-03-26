#include <iostream>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
struct List {
    ListNode* head=nullptr;
};
void insertLast(List &l, int x) {
    if (l.head == nullptr) {
        l.head = new ListNode(x);
        return;
    }
    ListNode *p = l.head;
    while (p->next != nullptr) {
        p = p->next;
    }
    p->next = new ListNode(x);
}
void printList(List &l) {
    ListNode *ptr = l.head;
    while (ptr != nullptr) {
        cout << ptr->val << ' ';
        ptr = ptr->next;
    }
    cout << '\n';
}
class Solution {
    public:
        static ListNode* removeNthFromEnd(ListNode* &head, int n) {
            if (head->next == nullptr) {
                delete head;
                return nullptr;
            }
            int count = 1;
            ListNode *fast = head;
            ListNode *slow = nullptr;
            ListNode *prev_slow = nullptr;
            while (fast != nullptr) {
                fast = fast->next;
                count++;
                if (count > n) {
                    if (slow == nullptr) slow = head;
                    else {
                        prev_slow = slow;
                        slow = slow->next;
                    }
                }
            }
            if (slow == head) {
                head = head->next;
            }
            else {
                prev_slow->next = slow->next;
            }
            delete slow;
            return head;
        }
    };

int main() {
    List l;
    while (1) {
        int temp;
        cin >> temp;
        if (temp == -1) break;
        else {
            int val;
            cin >> val;
            insertLast(l, val);
        }
    }
    
    Solution::removeNthFromEnd(l.head, 2);
    printList(l);
    
}