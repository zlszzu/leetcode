/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* removeElements(struct ListNode* head, int val){
    while ((head != NULL) && (head->val == val)) {
        head = head->next;
    }
    if (head == NULL) {
        return NULL;
    }
    struct ListNode *curNode = head;
    struct ListNode *nextNode = head->next;
    while (nextNode != NULL) {
        if (nextNode->val == val) {
            curNode->next = nextNode->next;
        } else {
            curNode = nextNode;
        }
        nextNode = nextNode->next;
    }
    return head;
}