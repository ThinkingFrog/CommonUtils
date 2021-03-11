from list.list_node import ListNode
from list.list_utils import list_is_sorted

def test_one_element():
        l1 = ListNode(1)
        assert list_is_sorted(l1)

def test_multiple_elements():
    l1 = ListNode(2)
    l1.next = ListNode(5)
    l1.next.next = ListNode(10000)
    
    assert list_is_sorted(l1)
    
    l1.next.next.next = ListNode(6)
    assert not list_is_sorted(l1)