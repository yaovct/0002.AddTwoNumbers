import java.lang.*;
import java.util.*;

/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class ListNode {
	int val;
	ListNode next;
	ListNode(int x) { val = x; }
}

class Solution {
  public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
    ListNode l3;
    ListNode p = l1;
    ListNode q = l2;
    ListNode h = l3 = new ListNode((p.val + q.val)%10);
    int carry = (int) (p.val + q.val)/10;
    p = p.next;
    q = q.next;
    while(p != null || q != null) {
    	if(p != null && q != null) {
    		h.next = new ListNode((p.val + q.val + carry)%10);
    		carry = (int) (p.val + q.val + carry)/10;
    		p = p.next;
    		q = q.next;
    		h = h.next;
    	} else if(p != null) {
    		h.next = new ListNode((p.val + carry)%10);
    		carry = (int) (p.val + carry)/10;
    		p = p.next;
    		h= h.next;
    	} else {
    		h.next = new ListNode((q.val + carry)%10);
    		carry = (int) (q.val + carry)/10;
    		q = q.next;
    		h = h.next;
    	}
    }
  	if(carry > 0) {
  		h.next = new ListNode(carry);
  	}
    return l3;
  }
}

public class index {

	protected static void readList(ListNode ll) {
		System.out.printf("[");
		while(ll.next != null) {
			System.out.printf("%d,",ll.val);
			ll = ll.next;
		}
		System.out.printf("%d]\n",ll.val);
	}

	public static void main(String[] args) { 
		int[] i1 = {4,5};
		int[] i2 = {6,4};
		ListNode l1 = new ListNode(2);
		ListNode l2 = new ListNode(3);
		ListNode p = l1;
		ListNode q = l2;
		for(int i=0; i<i1.length; i++) {
			p.next = new ListNode(i1[i]);
			p = p.next;
		}
		for(int i=0; i<i2.length; i++) {
			q.next = new ListNode(i2[i]);
			q = q.next;
		}
		readList(l1);
		readList(l2);
    Solution demo = new Solution();
    ListNode l3 = demo.addTwoNumbers(l1, l2);
    readList(l3);
	}
}