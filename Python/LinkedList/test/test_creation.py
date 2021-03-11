from list.list_utils import list_is_sorted, create_rand_sorted_list

def test_five_elements():
    assert list_is_sorted(create_rand_sorted_list(5))

def test_fifty_elements():
    assert list_is_sorted(create_rand_sorted_list(50))

def test_five_hundred_elements():
    assert list_is_sorted(create_rand_sorted_list(500))

def test_five_thousand_elements():
    assert list_is_sorted(create_rand_sorted_list(5000))
