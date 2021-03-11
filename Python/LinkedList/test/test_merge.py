import random

from list.list_node import ListNode
from list.list_utils import list_is_sorted, merge, create_rand_sorted_list

def test_simple_example():
    l1 = ListNode(1)
    l1.next = ListNode(2)
    l1.next.next = ListNode(4)

    l2 = ListNode(1)
    l2.next = ListNode(3)
    l2.next.next = ListNode(4)

    l3 = merge(l1, l2)
    assert list_is_sorted(l3)

def test_one_empty_list():
    l1 = create_rand_sorted_list(10)
    l2 = create_rand_sorted_list(10)

    l3 = merge(l1, None)
    assert list_is_sorted(l3)
    l4 = merge(None, l2)
    assert list_is_sorted(l4)


def test_equal_small_lists():
    l1 = create_rand_sorted_list(10)
    l2 = create_rand_sorted_list(10)

    assert list_is_sorted(l1)
    assert list_is_sorted(l2)

    l3 = merge(l1, l2)
    assert list_is_sorted(l3)

def test_equal_medium_lists():
    l1 = create_rand_sorted_list(1000)
    l2 = create_rand_sorted_list(1000)

    assert list_is_sorted(l1)
    assert list_is_sorted(l2)

    l3 = merge(l1, l2)
    assert list_is_sorted(l3)

def test_equal_big_lists():
    l1 = create_rand_sorted_list(100000)
    l2 = create_rand_sorted_list(100000)

    assert list_is_sorted(l1)
    assert list_is_sorted(l2)

    l3 = merge(l1, l2)
    assert list_is_sorted(l3)

def test_first_list_smaller():
    l1 = ListNode(5)
    l1.next = ListNode(10)

    l2 = ListNode(100)
    l2.next = ListNode(150)
    l2.next.next = ListNode(200)

    l3 = merge(l1, l2)
    assert list_is_sorted(l3)

def test_first_list_bigger():
    l1 = ListNode(5)
    l1.next = ListNode(10)
    l1.next.next = ListNode(200)

    l2 = ListNode(100)
    l2.next = ListNode(150)

    l3 = merge(l1, l2)
    assert list_is_sorted(l3)

def test_random_lists():
    size1 = random.randint(1, 100000)
    size2 = random.randint(1, 100000)

    l1 = create_rand_sorted_list(size1)
    l2 = create_rand_sorted_list(size2)

    assert list_is_sorted(l1)
    assert list_is_sorted(l2)

    l3 = merge(l1, l2)
    assert list_is_sorted(l3)