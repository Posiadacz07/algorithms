// You need to remaid yourself how work with pointers works

// Add numers stored in node list in reverse order
// Input: l1 = [2,4,3], l2 = [5,6,4]
// Output: [7,0,8]
// Explanation: 342 + 465 = 807.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode* dummy = new ListNode();
    ListNode* res = dummy;
    int rest = 0;
    int total = 0;

    while(l1 || l2 || rest){
        total = rest;

        if(l1) {
            total += l1->val;
            l1 = l1->next;
        }

        if(l2) {
            total += l2->val;
            l2 = l2->next;
        }

        int element = total % 10;
        rest = total / 10;

        dummy->next = new ListNode(element);
        dummy = dummy->next;
    }
    ListNode* result = res->next;
    delete res;
    return result;
}