# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None
import sys

class ListNode(object):
    def __init__(self, x):
        self.val = x
        self.next = None

class LinkList(ListNode):
    def __init__(self, x):
        self.val = x
        self.next = None
        
    def insert(self, data):
    		link = ListNode(data)
    		curr = self
    		while curr.next != None:
    			curr = curr.next
    		curr.next = link
    		
    def read(self):
    		curr = self
    		sys.stdout.write("[")
    		while curr.next != None:
    			sys.stdout.write("%d," % curr.val)
    			curr = curr.next
    		print("%d]" % curr.val)

class Solution(object):
    def addTwoNumbers(self, l1, l2):
        """
        :type l1: ListNode
        :type l2: ListNode
        :rtype: ListNode
        """
        p = l1
        q = l2
        l3 = LinkList((l1.val + l2.val)%10)
        carry = int((l1.val + l2.val)/10)
        p = p.next
        q = q.next
        while p != None or q != None:
        	if p != None and q != None:
        		l3.insert((p.val + q.val + carry)%10)
        		carry = int((p.val + q.val + carry)/10)
        		p = p.next
        		q = q.next
        	elif p != None:
        		l3.insert((p.val + carry)%10)
        		carry = int((p.val + carry)/10)
        		p = p.next
        	else:
        		l3.insert((q.val + carry)%10)
        		carry = int((q.val + carry)/10)
        		q = q.next
        if carry > 0:
        	l3.insert(carry)
        return l3

i1 = [4,5];
i2 = [6,4];
l1 = LinkList(2)
l2 = LinkList(3)
for i in range(0, len(i1)):
	l1.insert(i1[i])
for i in range(0, len(i2)):
	l2.insert(i2[i])
l1.read()
l2.read()

my_test = Solution()
l3 = my_test.addTwoNumbers(l1, l2)
l3.read()
