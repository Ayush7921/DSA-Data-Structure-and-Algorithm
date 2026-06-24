/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* merge(ListNode* list1, ListNode* list2) {
        ListNode* dummy = new ListNode(-1); // Lifesaver dummy node
        ListNode* tail = dummy;

        while (list1 && list2) {
            if (list1->val < list2->val) {
                tail->next = list1;
                list1 = list1->next;
            } else {
                tail->next = list2;
                list2 = list2->next;
            }
            tail = tail->next;
        }

        // Agar koi ek list abhi bhi bachi hui hai
        if (list1) tail->next = list1;
        if (list2) tail->next = list2;

        ListNode* sortedHead = dummy->next;
        delete dummy; // Memory clean
        return sortedHead;
    }

    // Helper Function: List ka middle element dhoondne ke liye
    ListNode* getMid(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head->next; // Twist: Taaki exact left-middle node mile

        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    ListNode* insertionSortList(ListNode* head) {
        // Base Case: Agar list khali hai ya sirf 1 hi element hai, toh woh already sorted hai
        if (!head || !head->next) return head;
        // 1. Split the list into two halves
        ListNode* mid = getMid(head);
        ListNode* left = head;
        ListNode* right = mid->next;
        mid->next = nullptr; // Crucial Step: Dono lists ko beech se break kar diya

        // 2. Recursively dono halves ko sort karo
        left = insertionSortList(left);
        right = insertionSortList(right);

        // 3. Sorted halves ko merge karke return kar do
        return merge(left, right);

    }
};