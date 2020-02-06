<?php
/**
 * Definition for a singly-linked list.
 * class ListNode {
 *     public $val = 0;
 *     public $next = null;
 *     function __construct($val) { $this->val = $val; }
 * }
 */
class ListNode {
  public $val = 0;
  public $next = null;
  function __construct($val) { $this->val = $val; }
}

class LinkList extends ListNode{
	function __construct($val) {
		$this->val = $val;
		$this->next = null;
	}
	public function insert($data) {
		$link = new ListNode($data);
		$curr = $this;
		while($curr->next != null) {
			$curr = $curr->next;
		}
		$curr->next = &$link;
	}
	public function read() {
		$curr = $this;
		printf("[");
		while($curr->next != null) {
			printf("%d,", $curr->val);
			$curr = $curr->next;
		}
		printf("%d]<br>", $curr->val);
	}
}

class Solution {

    /**
     * @param ListNode $l1
     * @param ListNode $l2
     * @return ListNode
     */
    function addTwoNumbers($l1, $l2) {
    	$p = $l1; $q = $l2;
    	$l3 = new LinkList(($p->val + $q->val)%10);
      $carry = intval(($p->val + $q->val)/10);
    	$p = $p->next;
    	$q = $q->next;
      while($p != null || $q !=null) {
      	if($p != null && $q != null) {
	      	$l3->insert(($p->val + $q->val + $carry)%10);
	      	$carry = intval(($p->val + $q->val + $carry)/10);
	      	$p = $p->next;
	      	$q = $q->next;
	      } else if($p != null) {
	      	$l3->insert(($p->val + $carry)%10);
	      	$carry = intval(($p->val + $carry)/10);
	      	$p = $p->next;
	      } else {
	      	$l3->insert(($q->val + $carry)%10);
	      	$carry = intval(($q->val + $carry)/10);
	      	$q = $q->next;
	      }
      }
      if($carry != 0) {
      	$l3->insert($carry);
      }
      return $l3;
    }
}

$i1 = [4,5];
$i2 = [6,4];
$l1 = new LinkList(2);
$l2 = new LinkList(5);
for($i=0; $i<count($i1); $i++) {
	$l1->insert($i1[$i]);
}
for($i=0; $i<count($i2); $i++) {
	$l2->insert($i2[$i]);
}

$l1->read();
$l2->read();

$testSolution = new Solution();
$l3 = $testSolution->addTwoNumbers($l1, $l2);
$l3->read();
?>