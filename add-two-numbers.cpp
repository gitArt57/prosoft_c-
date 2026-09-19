class Solution
{
public:
    // Складывает два числа, представленных связными списками (цифры в обратном порядке)
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        // Фиктивный головной узел для упрощения работы со списком
        ListNode dummyHead(0);

        // Указатель на текущий узел результата
        ListNode *current = &dummyHead;

        // Перенос разряда (например, 7+8=15, переносим 1)
        int carry = 0;

        // Проходим по обоим спискам, пока есть цифры или перенос
        while (l1 != nullptr || l2 != nullptr || carry != 0)
        {
            // Получаем текущие цифры (0, если узел отсутствует)
            int val1 = (l1 != nullptr) ? l1->val : 0;
            int val2 = (l2 != nullptr) ? l2->val : 0;

            // Сумма цифр с учётом переноса
            int totalSum = val1 + val2 + carry;

            // Новый перенос (целая часть от деления на 10)
            carry = totalSum / 10;

            // Создаём новый узел с цифрой результата (остаток от деления на 10)
            current->next = new ListNode(totalSum % 10);

            // Перемещаем указатель на новый узел
            current = current->next;

            // Переходим к следующим узлам входных списков
            if (l1 != nullptr)
                l1 = l1->next;
            if (l2 != nullptr)
                l2 = l2->next;
        }

        // Возвращаем результат (пропускаем фиктивный узел)
        return dummyHead.next;
    }
};