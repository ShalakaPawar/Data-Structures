/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        
        int carry = 0;
        ListNode ans = null;
        ListNode currentNode = ans;

        while (l1 != null || l2 != null) {
            int sum = carry;
            if (l1 != null) {
                sum += l1.val;
                l1 = l1.next;
            }

            if (l2 != null) {
                sum += l2.val;
                l2 = l2.next;
            }

            int val = sum%10;
            carry = sum/10;
            
            if (currentNode == null){
                ans = new ListNode(val);
                currentNode = ans;
            } else {
                currentNode.next = new ListNode(val);
                currentNode = currentNode.next;
            }
        }
        if (carry != 0) {
            currentNode.next = new ListNode(carry);
        }
        return ans;
    
    }
}