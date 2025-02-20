/*------- With Min Heap ---------*/
class Solution {
    public:
        ListNode* sortList(ListNode* head) {
            if (!head || !head->next) return head; 
            priority_queue<int, vector<int>, greater<int>> minHeap;
    
            ListNode* temp = head;
            while (temp) {
                minHeap.push(temp->val);
                temp = temp->next;
            }
    
            temp = head;
            while (!minHeap.empty()) {
                temp->val = minHeap.top();
                minHeap.pop();
                temp = temp->next;
            }
    
            return head; 
        }
    };
    