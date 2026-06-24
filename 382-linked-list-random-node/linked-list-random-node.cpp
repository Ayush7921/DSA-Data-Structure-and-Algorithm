/**
 * Definition for singly-linked list.
 * struct ListNode {
 * int val;
 * ListNode *next;
 * ListNode() : val(0), next(nullptr) {}
 * ListNode(int x) : val(x), next(nullptr) {}
 * ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

class Solution {
private:
    // Vectors ko yahan declare karenge taaki poori class mein access ho sake
    vector<int> v; 

public:
    Solution(ListNode* head) {
        // Har baar sach mein random mile isliye seed set karte hain
         
        
        ListNode* temp = head;
        // Nodes ki sirf values ko vector mein store kar lete hain, kaam aasan ho jayega
        while (temp != nullptr) {
            v.push_back(temp->val);
            temp = temp->next; // Galti Fixed: Agle node par jaane ke liye
        }
    }
    
    int getRandom() {
        // Direct humne jo abhi shortcut seekha tha wahi use karenge
        int randomIndex = rand() % v.size();
        return v[randomIndex]; // Galti Fixed: int value return kar rahe hain
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */