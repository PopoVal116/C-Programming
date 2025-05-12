#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <cmocka.h>
#include <stdlib.h>
#include "sort.h"

// Проверяет, отсортирован ли массив (числа идут по порядку от меньшего к большему)
int is_sorted(int nums[], int count) {
    // Проходим по массиву, но не до конца, чтобы сравнить с следующим числом
    for (int i = 0; i < count - 1; i++) {
        // Если текущее число больше следующего, массив не отсортирован
        if (nums[i] > nums[i + 1]) {
            // Возвращаем 0 (значит "не отсортирован")
            return 0;
        }
    }
    // Если дошли сюда, массив отсортирован, возвращаем 1 (значит "да")
    return 1;
}

// Тест для bubbleSort с пустым массивом
void test_empty(void **state) {
    // Создаем указатель на массив, но он пустой (NULL)
    int *nums = NULL;
    // Создаем счетчики для сравнений и перемещений, ставим 0
    int comps = 0, moves = 0;
    // Вызываем bubbleSort с пустым массивом и размером 0
    bubbleSort(nums, 0, &comps, &moves);
    // Проверяем, что сравнений не было (должно быть 0)
    assert_int_equal(comps, 0);
    // Проверяем, что перемещений не было (должно быть 0)
    assert_int_equal(moves, 0);
}

// Тест для bubbleSort с массивом из одного числа
void test_one_num(void **state) {
    // Создаем массив с одним числом: 1
    int nums[] = {1};
    // Создаем счетчики и ставим 0
    int comps = 0, moves = 0;
    // Вызываем bubbleSort для массива с одним числом
    bubbleSort(nums, 1, &comps, &moves);
    // Проверяем, что число осталось 1 (не должно измениться)
    assert_int_equal(nums[0], 1);
    // Проверяем, что сравнений не было
    assert_int_equal(comps, 0);
    // Проверяем, что перемещений не было
    assert_int_equal(moves, 0);
}

// Тест для bubbleSort с уже отсортированным массивом
void test_sorted(void **state) {
    // Создаем отсортированный массив: 1, 2, 3, 4, 5
    int nums[] = {1, 2, 3, 4, 5};
    // Создаем счетчики и ставим 0
    int comps = 0, moves = 0;
    // Вызываем bubbleSort
    bubbleSort(nums, 5, &comps, &moves);
    // Проверяем, что массив остался отсортированным
    assert_true(is_sorted(nums, 5));
    // Проверяем, что было 10 сравнений (для 5 чисел: 5*4/2)
    assert_int_equal(comps, 10);
    // Проверяем, что перемещений не было (массив уже отсортирован)
    assert_int_equal(moves, 0);
}

// Тест для bubbleSort с массивом в обратном порядке
void test_reverse(void **state) {
    // Создаем массив в обратном порядке: 5, 4, 3, 2, 1
    int nums[] = {5, 4, 3, 2, 1};
    // Создаем счетчики и ставим 0
    int comps = 0, moves = 0;
    // Вызываем bubbleSort, чтобы отсортировать
    bubbleSort(nums, 5, &comps, &moves);
    // Проверяем, что массив теперь отсортирован
    assert_true(is_sorted(nums, 5));
    // Проверяем, что было 10 сравнений
    assert_int_equal(comps, 10);
    // Проверяем, что было 30 перемещений (3 перемещения на обмен, 10 обменов)
    assert_int_equal(moves, 30);
}

// Тест для bubbleSort с массивом в случайном порядке
void test_random(void **state) {
    // Создаем массив с числами в случайном порядке: 3, 1, 4, 5, 2
    int nums[] = {3, 1, 4, 5, 2};
    // Создаем счетчики и ставим 0
    int comps = 0, moves = 0;
    // Вызываем bubbleSort, чтобы отсортировать
    bubbleSort(nums, 5, &comps, &moves);
    // Проверяем, что массив отсортирован
    assert_true(is_sorted(nums, 5));
    // Проверяем, что первое число — 1 (самое маленькое)
    assert_int_equal(nums[0], 1);
    // Проверяем, что последнее число — 5 (самое большое)
    assert_int_equal(nums[4], 5);
}

// Тест для bubbleSort с массивом, где есть одинаковые числа
void test_same_nums(void **state) {
    // Создаем массив с повторяющимися числами: 3, 1, 3, 2, 1
    int nums[] = {3, 1, 3, 2, 1};
    // Создаем счетчики и ставим 0
    int comps = 0, moves = 0;
    // Вызываем bubbleSort, чтобы отсортировать
    bubbleSort(nums, 5, &comps, &moves);
    // Проверяем, что массив отсортирован
    assert_true(is_sorted(nums, 5));
    // Проверяем, что первое число — 1
    assert_int_equal(nums[0], 1);
    // Проверяем, что второе число — 1 (повторение)
    assert_int_equal(nums[1], 1);
    // Проверяем, что последнее число — 3
    assert_int_equal(nums[4], 3);
}

// Тест для make_down_nums с пустым массивом
void test_down_empty(void **state) {
    // Создаем маленький массив, чтобы не было ошибок
    int nums[1] = {0};
    // Вызываем make_down_nums с размером 0 (ничего не должно произойти)
    make_down_nums(nums, 0);
}

// Тест для make_down_nums с одним числом
void test_down_one(void **state) {
    // Создаем массив с одним числом, ставим 0
    int nums[] = {0};
    // Вызываем make_down_nums, чтобы заполнить
    make_down_nums(nums, 1);
    // Проверяем, что число стало 1 (для размера 1 это просто 1)
    assert_int_equal(nums[0], 1);
}

// Тест для make_down_nums с пятью числами
void test_down_five(void **state) {
    // Создаем массив из пяти нулей
    int nums[] = {0, 0, 0, 0, 0};
    // Вызываем make_down_nums, чтобы заполнить числами 5, 4, 3, 2, 1
    make_down_nums(nums, 5);
    // Проверяем, что первое число — 5
    assert_int_equal(nums[0], 5);
    // Проверяем, что последнее число — 1
    assert_int_equal(nums[4], 1);
}

// Тест для make_up_nums с пустым массивом
void test_up_empty(void **state) {
    // Создаем маленький массив
    int nums[1] = {0};
    // Вызываем make_up_nums с размером 0 (ничего не делаем)
    make_up_nums(nums, 0);
}

// Тест для make_up_nums с одним числом
void test_up_one(void **state) {
    // Создаем массив с одним нулем
    int nums[] = {0};
    // Вызываем make_up_nums, чтобы заполнить
    make_up_nums(nums, 1);
    // Проверяем, что число стало 1
    assert_int_equal(nums[0], 1);
}

// Тест для make_up_nums с пятью числами
void test_up_five(void **state) {
    // Создаем массив из пяти нулей
    int nums[] = {0, 0, 0, 0, 0};
    // Вызываем make_up_nums, чтобы заполнить числами 1, 2, 3, 4, 5
    make_up_nums(nums, 5);
    // Проверяем, что первое число — 1
    assert_int_equal(nums[0], 1);
    // Проверяем, что последнее число — 5
    assert_int_equal(nums[4], 5);
}

// Тест для make_random_nums с пустым массивом
void test_random_empty(void **state) {
    // Создаем маленький массив
    int nums[1] = {0};
    // Вызываем make_random_nums с размером 0 (ничего не делаем)
    make_random_nums(nums, 0);
}

// Тест для make_random_nums с одним числом
void test_random_one(void **state) {
    // Создаем массив с одним нулем
    int nums[] = {0};
    // Устанавливаем начальное число для случайных чисел, чтобы результаты были одинаковыми
    srand(42);
    // Вызываем make_random_nums, чтобы заполнить одним случайным числом
    make_random_nums(nums, 1);
    // Проверяем, что число от 0 до 99
    assert_in_range(nums[0], 0, 99);
}

// Тест для make_random_nums с пятью числами
void test_random_five(void **state) {
    // Создаем массив из пяти нулей
    int nums[] = {0, 0, 0, 0, 0};
    // Устанавливаем начальное число для случайных чисел
    srand(42);
    // Вызываем make_random_nums, чтобы заполнить пятью случайными числами
    make_random_nums(nums, 5);
    // Проходим по массиву
    for (int i = 0; i < 5; i++) {
        // Проверяем, что каждое число от 0 до 99
        assert_in_range(nums[i], 0, 99);
    }
}

// Главная функция, которая запускает все тесты
int main(void) {
    // Создаем список всех тестов
    const struct CMUnitTest tests[] = {
        // Добавляем каждый тест в список
        cmocka_unit_test(test_empty),
        cmocka_unit_test(test_one_num),
        cmocka_unit_test(test_sorted),
        cmocka_unit_test(test_reverse),
        cmocka_unit_test(test_random),
        cmocka_unit_test(test_same_nums),
        cmocka_unit_test(test_down_empty),
        cmocka_unit_test(test_down_one),
        cmocka_unit_test(test_down_five),
        cmocka_unit_test(test_up_empty),
        cmocka_unit_test(test_up_one),
        cmocka_unit_test(test_up_five),
        cmocka_unit_test(test_random_empty),
        cmocka_unit_test(test_random_one),
        cmocka_unit_test(test_random_five),
    };
    // Запускаем все тесты и возвращаем результат (0, если всё прошло)
    return cmocka_run_group_tests(tests, NULL, NULL);
}