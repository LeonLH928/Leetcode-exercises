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
        ListNode* addLast(ListNode* last, int x) {
            last->next = new ListNode(x);
            last = last->next;
            return last;
        }
        ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
            ListNode dummy;
            ListNode *p = &dummy;
            while (list1 != nullptr && list2 != nullptr) {
                if (list1->val > list2->val) {
                    p = addLast(p, list2->val);
                    list2 = list2->next;
                }
                else {
                    p = addLast(p, list1->val);
                    list1 = list1->next;  
                }
            }
            while (list1 != nullptr) {
                p = addLast(p, list1->val);
                list1 = list1->next;  
            }
            while (list2 != nullptr) {
                p = addLast(p, list2->val);
                list2 = list2->next;
            }
            return dummy.next;
        }
    };

void printList(ListNode *l) {
    while (l != nullptr) {
        cout << l->val << ' ';
        l = l->next;
    }
    cout << '\n';
}
int main() {
    Solution s;
    ListNode *l1 = new ListNode(2);
    ListNode *p = l1;
    p = s.addLast(p, 3);
    p = s.addLast(p, 4);
    p = s.addLast(p, 5);
       
    ListNode *l2 = new ListNode(1);
    p = l2;
    p = s.addLast(p, 2);
    p = s.addLast(p, 5);
    
    printList(l1);
    printList(l2);
    ListNode* newList = s.mergeTwoLists(l1, l2);
    printList(newList);
}