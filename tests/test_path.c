/*==============================================================================#
# test_path.c -- Unit tests for path.c
#
# Check is a unit testing framework for C.
# See: http://check.sourceforge.net
# 
# Contributor: Chen Ye <ycchina@gmail.com>
#==============================================================================*/

#include <stdlib.h>
#include <check.h>
#include "../src/path.h"

Node *head;

void
setup (void)
{
	head = path_init(5.0, 5.0);
	path_append(6.0, 6.0);
	path_append(7.0, 7.0);
}

void
teardown (void)
{
	path_free();
}

START_TEST(test_path_init)
{
	ck_assert(path_head_node()->x == 5.0);
	ck_assert(path_head_node()->y == 5.0);

	ck_assert(path_current_node()->x == 7.0);
	ck_assert(path_current_node()->y == 7.0);
}
END_TEST

START_TEST(test_path_append_neg)
{
	Node *path = path_append (-1.0, -1.0);
	ck_assert_msg (path == NULL,
			"NULL should be returned on attempt to append with "
			"a negative value");
}
END_TEST

START_TEST(test_path_append_zero)
{
	Node *path = path_append (0.0, 0.0);
	if (path_current_node(path)->x != 0.0 ||
		path_current_node(path)->y != 0.0)
	{
		ck_abort_msg("Zero is a valid value");
	}
}
END_TEST

Suite *
path_suite(void)
{
	Suite *s = suite_create("Path");

	/* Core test case */
	TCase *tc_core = tcase_create("Core");
	tcase_add_checked_fixture(tc_core, setup, teardown);
	tcase_add_test(tc_core, test_path_init);
	suite_add_tcase(s, tc_core);

	/* Limits test case */
	TCase *tc_limits = tcase_create ("Limits");
	tcase_add_test(tc_limits, test_path_append_neg);
	tcase_add_test(tc_limits, test_path_append_zero);
	suite_add_tcase(s, tc_limits);

	return s;
}

int
main(void)
{
	int number_failed;
	Suite *s = path_suite();
	SRunner *sr = srunner_create(s);
	srunner_run_all(sr, CK_NORMAL);
	number_failed = srunner_ntests_failed(sr);
	srunner_free(sr);
	return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
