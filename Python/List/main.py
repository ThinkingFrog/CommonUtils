'''
Используемая версия Python 3.8
В модуле реализована структура узла односвязного списка
К этой структуре привязаны методы создания сортированного списка из случайных узлов, печати списка, объединения списков
и проверки, что список отсортирован
Для тестирования используется модуль unittest
Тесты проводятся на вспомогательные методы проверки сортированности и создания случайного списка и на основной метод merge
При запуске файла автоматически проводятся все тесты

ListNode:
    Содержит значение и ссылку на следующий жлемент

merge(l1: ListNode, l2: ListNode):
    Объединяет два сортированных списка в один сортированный
    Если один из списков пустой, возвращает второй список
    Алгоритм:
        1) Из двух списков выбирается тот, у которого первое значение наименьшее, он называется основным списком
        2) Далее итерируемся по основному списку, проверяя значения из вспомогательного
        3) Если значение из вспомогательного списка лежит между текущим и следующим значениями основного,
           узел вставляется в основной список
        4) Если по п.3 во вспомогательном списке подходящих узлов нет, переходим на следующий узел основного списка
        5) Если во вспомогательном списке больше нет значений, выходим из цикла
        6) Если в основном списке дошли до последнего узла, то дальше вставляем все оставшиеся узлы вспомогательного
           и выходим из цикла
        7) Возвращаем первый узел основного списка
    В худшем случае алгоритм проходит по каждому элементу обоих списков, поэтому алгоритмическая сложность равна O(N1+N2)
    Алгоритм не требует дополнительных выделений памяти, так как только меняет ссылки в уже существующих узлах

create_rand_sorted_lList(n: int):
    Создаёт сортированный список из случайных интовых значений с максимальной разницей в 10
    Возвращает первый узел этого списка

print_list(l: ListNode):
    Печатает значения из списка пока есть узлы

list_is_sorted(l: ListNode):
    Последовательно проверяет, что значение текущего узла не превосходит значение следующего узла
'''

import random
import unittest

class ListNode:
    def __init__(self, value):
        self.value = value
        self.next = None

def merge(l1: ListNode, l2: ListNode):
    if l1 is None:
        return l2
    if l2 is None:
        return l1

    main_list = l1 if l1.value < l2.value else l2
    sec_list = l2 if main_list == l1 else l1
    head = main_list

    while main_list:
        if main_list.next is None:
            while sec_list:
                main_list.next = sec_list
                sec_list = sec_list.next
            break

        if sec_list is None:
            break

        if sec_list.value < main_list.next.value:
            tmp = sec_list.next
            sec_list.next = main_list.next
            main_list.next = sec_list
            sec_list = tmp
        else:
            main_list = main_list.next

    return head


def create_rand_sorted_list(n: int):
    node = ListNode(random.randint(0, 10))
    head = node
    for i in range(n - 1):
        node.next = ListNode(random.randint(node.value, node.value + 10))
        node = node.next
    return head


def print_list(l: ListNode):
    while l:
        print(l.value)
        l = l.next


def list_is_sorted(l: ListNode):
    if l is None:
        return True

    while l.next:
        if l.value > l.next.value:
            return False
        l = l.next
    return True

#-----------------------------------------------------------------------------------------------------------------------
#Tests


class TestListIsSortedMethod(unittest.TestCase):

    def test_one_element(self):
        l1 = ListNode(1)
        self.assertTrue(list_is_sorted(l1))

    def test_multiple_elements(self):
        l1 = ListNode(2)
        l1.next = ListNode(5)
        l1.next.next = ListNode(10000)
        self.assertTrue(list_is_sorted(l1))
        l1.next.next.next = ListNode(6)
        self.assertFalse(list_is_sorted(l1))


class TestRandomListCreation(unittest.TestCase):

    def test_five_elements(self):
        self.assertTrue(list_is_sorted(create_rand_sorted_list(5)))

    def test_fifty_elements(self):
        self.assertTrue(list_is_sorted(create_rand_sorted_list(50)))

    def test_five_hundred_elements(self):
        self.assertTrue(list_is_sorted(create_rand_sorted_list(500)))

    def test_five_thousand_elements(self):
        self.assertTrue(list_is_sorted(create_rand_sorted_list(5000)))

class TestMergeMethod(unittest.TestCase):

    def test_simple_example(self):
        l1 = ListNode(1)
        l1.next = ListNode(2)
        l1.next.next = ListNode(4)

        l2 = ListNode(1)
        l2.next = ListNode(3)
        l2.next.next = ListNode(4)

        l3 = merge(l1, l2)
        self.assertTrue(list_is_sorted(l3))

    def test_one_empty_list(self):
        l1 = create_rand_sorted_list(10)
        l2 = create_rand_sorted_list(10)

        l3 = merge(l1, None)
        self.assertTrue(list_is_sorted(l3))
        l4 = merge(None, l2)
        self.assertTrue(list_is_sorted(l4))


    def test_equal_small_lists(self):
        l1 = create_rand_sorted_list(10)
        l2 = create_rand_sorted_list(10)

        self.assertTrue(list_is_sorted(l1))
        self.assertTrue(list_is_sorted(l2))

        l3 = merge(l1, l2)
        self.assertTrue(list_is_sorted(l3))

    def test_equal_medium_lists(self):
        l1 = create_rand_sorted_list(1000)
        l2 = create_rand_sorted_list(1000)

        self.assertTrue(list_is_sorted(l1))
        self.assertTrue(list_is_sorted(l2))

        l3 = merge(l1, l2)
        self.assertTrue(list_is_sorted(l3))

    def test_equal_big_lists(self):
        l1 = create_rand_sorted_list(100000)
        l2 = create_rand_sorted_list(100000)

        self.assertTrue(list_is_sorted(l1))
        self.assertTrue(list_is_sorted(l2))

        l3 = merge(l1, l2)
        self.assertTrue(list_is_sorted(l3))

    def test_first_list_smaller(self):
        l1 = ListNode(5)
        l1.next = ListNode(10)

        l2 = ListNode(100)
        l2.next = ListNode(150)
        l2.next.next = ListNode(200)

        l3 = merge(l1, l2)
        self.assertTrue(list_is_sorted(l3))

    def test_first_list_bigger(self):
        l1 = ListNode(5)
        l1.next = ListNode(10)
        l1.next.next = ListNode(200)

        l2 = ListNode(100)
        l2.next = ListNode(150)

        l3 = merge(l1, l2)
        self.assertTrue(list_is_sorted(l3))

    def test_random_lists(self):
        size1 = random.randint(1, 100000)
        size2 = random.randint(1, 100000)

        l1 = create_rand_sorted_list(size1)
        l2 = create_rand_sorted_list(size2)

        self.assertTrue(list_is_sorted(l1))
        self.assertTrue(list_is_sorted(l2))

        l3 = merge(l1, l2)
        self.assertTrue(list_is_sorted(l3))


if __name__ == '__main__':
    unittest.main()
