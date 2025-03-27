#include <iostream>
#include <vector>
#include <algorithm>
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
    ListNode *getNode(int x) {
        return new ListNode(x);
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode dummy;
        ListNode *p = &dummy;
        dummy.next = nullptr;

        vector<int> temp;
        for (int i = 0; i < lists.size(); i++) {
            ListNode* &ptr = lists[i];
            while (ptr != nullptr) {
                ListNode *tempNode = ptr;
                ptr = ptr->next;
                temp.push_back(tempNode->val);
                delete tempNode;
            }
        }
        sort(temp.begin(), temp.end());
        for (int i = 0; i < temp.size(); i++) {
            ListNode *newNode = getNode(temp[i]);
            p->next = newNode;
            p = p->next;
        }
        return dummy.next;
    }
};