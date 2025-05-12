#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <cmocka.h>
#include <stdlib.h>
#include <stdio.h> // Added for FILE, fopen, fgets, fclose, remove
#include "triangle.h"

static void test_get_tri_num(void **state) {
    (void)state;
    assert_int_equal(get_tri_num(1), 1);
    assert_int_equal(get_tri_num(5), 15);
    assert_int_equal(get_tri_num(10), 55);
}

static void test_make_tri_file(void **state) {
    (void)state;
    make_tri_file(3); // Creates triangle.txt for testing
    FILE *file = fopen("triangle.txt", "r");
    assert_non_null(file);
    char line[100];
    assert_non_null(fgets(line, sizeof(line), file));
    assert_string_equal(line, " * \n");
    assert_non_null(fgets(line, sizeof(line), file));
    assert_string_equal(line, "* * \n");
    assert_non_null(fgets(line, sizeof(line), file));
    assert_string_equal(line, "* * * \n");
    fclose(file);
    remove("triangle.txt"); // Clean up
}

int main(void) {
    const struct CMUnitTest tests[] = {
        cmocka_unit_test(test_get_tri_num),
        cmocka_unit_test(test_make_tri_file),
    };
    return cmocka_run_group_tests(tests, NULL, NULL);
}