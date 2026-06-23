class Solution {
public:
    Node* flatten(Node* head) {
        if (!head) return nullptr;

        Node* curr = head;
        stack<Node*> st; // DFS ke liye Stack zaroori hai

        while (curr != nullptr) {
            // 1. Agar child milta hai
            if (curr->child != nullptr) {
                // Agar piche next bacha hai, toh use stack mein save karo
                if (curr->next != nullptr) {
                    st.push(curr->next);
                }
                
                // Pointers ko child list se connect karo
                curr->next = curr->child;
                curr->next->prev = curr;
                curr->child = nullptr; // Child ko null karna zaroori hai
            }
            
            // 2. Agar current level khatam aur stack mein purane next nodes bache hain
            if (curr->next == nullptr && !st.empty()) {
                Node* nextNode = st.top();
                st.pop();
                
                curr->next = nextNode;
                nextNode->prev = curr;
            }
            
            curr = curr->next; // Normal aage badho
        }
        
        return head;
    }
};