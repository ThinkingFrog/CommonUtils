'''
Используемая версия Python 3.8
В модуле реализована структура узла односвязного списка
К этой структуре привязаны методы создания сортированного списка из случайных узлов, печати списка, объединения списков
и проверки, что список отсортирован
Для тестирования используется модуль unittest
Тесты проводятся на вспомогательные методы проверки сортированности и создания случайного списка и на основной метод merge
При запуске файла автоматически проводятся все тесты

ListNode:
    Содержит значение и ссылку на следующий элемент

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

from list.list_node import ListNode

import random


def merge(l1: ListNode, l2: ListNode):
    if not l1 or l1 is None:
        return l2
    if not l2 or l2 is None:
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


def create_rand_sorted_list(n: int) -> ListNode:
    node = ListNode(random.randint(0, 10))
    head = node
    for _ in range(n - 1):
        node.next = ListNode(random.randint(node.value, node.value + 10))
        node = node.next
    return head


def print_list(l: ListNode) -> None:
    while l:
        print(l.value)
        l = l.next


def list_is_sorted(l: ListNode) -> bool:
    if not l or l is None:
        return True

    while l.next:
        if l.value > l.next.value:
            return False
        l = l.next
    return True
