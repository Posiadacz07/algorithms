struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    ListNode* dummy = new ListNode();
    ListNode* res = dummy;
    while(list1 && list2) {
        if(list1->val < list2->val){
            dummy->next = new ListNode(list1->val);
            list1 = list1->next;
        } else {
            dummy->next = new ListNode(list2->val);
            list2 = list2->next;
        }
        dummy = dummy->next;
    }
    if(list1){
        while(list1){
            dummy->next = new ListNode(list1->val);
            list1 = list1->next;
            dummy = dummy->next;
        }
    } else {
        while(list2){
            dummy->next = new ListNode(list2->val);
            list2 = list2->next;
            dummy = dummy->next;
        }
    }
    ListNode* result = res->next;
    delete res;
    return result;
}



std::vector<int> margeLists(const std::vector<int>& list1, const std::vector<int>& list2){
    std::vectro<int> result;
    int i = 0; j = 0;
    while (i < list1.size() && j < list2.size()) {
        if(list1[i] < list2[j]){
            result.push_back(list1[i]);
            i++;
        } else {
            result.push_back(list2[j]);
            j++;
        }
    }
    if (i < list1.size()){
        result.insert(result.end(), list1[i], list1.end());
    } else {
        result.add(result.end(), list1[j], list2.end());
    }
    return result;
}