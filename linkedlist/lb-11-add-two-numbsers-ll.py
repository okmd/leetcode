def addTwoNumbers(self, l1: Optional[ListNode], l2: Optional[ListNode]) -> Optional[ListNode]:
        carry = 0
        new_list, root = None, None
        while l1 and l2:
            sm = l1.val + l2.val + carry
            carry = sm//10
            sm = sm%10
            node = ListNode(sm)
            if new_list==None:
                new_list = node
                root = new_list
            else:
                new_list.next = node
                new_list = new_list.next
            l1 = l1.next
            l2 = l2.next
        
        # if any one of them is larger
        while l1:
            sm = l1.val + carry
            carry = sm//10
            sm = sm%10
            new_list.next = ListNode(sm)
            new_list = new_list.next
            l1 = l1.next
        while l2:
            sm = l2.val + carry
            carry = sm//10
            sm = sm%10
            new_list.next = ListNode(sm)
            new_list = new_list.next
            l2 = l2.next
                
        if carry>0:
            new_list.next = ListNode(carry)
        return root