/**@file t_lib.c
 * @date 3/20/14
 * @author Owen Watson
 *
 * @brief Initialize CUnit framework and unit tests for add
 *
 * ##Description
 * t_lib.c defines a test function for add, which contains many asserts for
 * the add(int a, int b) function.  The CUnit test suite is also setup here.
 * This involes setting up the test registry, which contains all test suites,
 * and adding the test (test_add) to the suite.  Following this setup, all the
 * test are run using the basic interface.
 */

#include "CUnit/Basic.h" 
#include "../src/lib.h"

/**
 * @brief A test function for add(int a, int b)
 * 
 * ##Description
 * test_add contains the logical testing for add.  
 * 
 * ##Test Function Information
 * There are no restrictions on the content of a test function, except that is
 * should not modify the CUnit framework (e.g add suites or tests, modify the
 * registry, or initiate a test run.) Registering a test will cause it's 
 * function to be run when the test is run.
 *
 * List of CUnit assertions:
 * http://cunit.sourceforge.net/doc/writing_tests.html
 *
 * @param void
 *
 * @return void
 */ 
void test_add(void) 
{
  CU_ASSERT(2 == add(1, 1));
  CU_ASSERT(0 == add(0, 0));
  CU_ASSERT(2 == add(0, 2));
  CU_ASSERT(2 == add(2, 0));
  CU_ASSERT(-2 == add(-1, -1));
  CU_ASSERT(-2 == add(0, -2));
  CU_ASSERT(-2 == add(-2, 0));
}

/**
 * @brief Function to initalize CUnit and runs test
 *
 * ##Description
 *
 * The main fucntion initializes the CUnit test registry, adds a suite to the
 * registry, adds the tests to the suite, and runs all test using the CUnit
 * Basic interface. The Basic interface outputs to stdout. 
 * 
 *
 * ##Unit Documentation
 * 
 * The active CUnit test registry must be initialized before use. The user
 * should call **CU_initialize_registry()** before calling any other CUnit
 * functions. 
 *
 * When testing is complete, the user should call **CU_cleanup_registry()** to 
 * clean up and release memory used by the framework. This should be the
 * last CUnit function called (except for restoring the test registry using
 * **CU_initialize_registry()** or **CU_set_registry()**). 
 *
 * **CU_add_suite** creates a new test collection (suite) having the specified name
 * ,initialization function, and cleanup function. The new suite is registered
 * with (and owned by) the test registry, so the registry must be initialized
 * before adding any suites.
 *
 * **CU_add_test** creates a new test having the specified name and test function,
 * and registers it with the specified suite. The suite must already have been
 * created using **CU_add_suite()**.
 * 
 * The basic interface is also non-interactive, with results output to stdout.
 * This interface supports running individual suites or tests, and allows
 * client code to control the type of output displayed during each run.
 *
 * **CU_basic_set_mode(CU_BasicRunMode mode)** sets the basic run mode, which
 * controls the output during test runs.
 * 
 * Basic run mode choices are:
 *   - **CU_BRM_NORMAL**  Failures and run summary are printed
 *   - **CU_BRM_SILENT**   No output is printed except error messages
 *   - **CU_BRM_VERBOSE**   Maximum output of run details [used here]
 *
 *
 *
 * **CU_basic_run_tests** runs all tests in all registered suites. 
 * Returns the 1st error code occurring during the test run.
 * 
 * **CU_get_error()** returns error status. 
 * 
 * List of error codes returned by **CU_get_error()**:
 * http://cunit.sourceforge.net/doc/error_handling.html
 *
 * @param argc (argument count) the number of arguments entered
 * @param argv (argument vector) an array of pointer to arrays of char objects
 *
 * @return CU_get_error() - framework error status
 */
 
int main (int argc, char** argv) 
{
  /* Used to for referencing the suite */
  CU_pSuite pSuite = NULL;

  /* Initialize the CUnit test registry */ 
  if (CUE_SUCCESS != CU_initialize_registry())
  {
    /* CUE_NOMEMORY - memory allocation failed*/
    return CU_get_error();
  }

  /* Add a suite to the test registry */ 
  pSuite = CU_add_suite("Suite_1", NULL, NULL);
  if (NULL == pSuite) 
  {
    CU_cleanup_registry();

    return CU_get_error();
  }

  /* Add the tests to the suite */ 
  if (NULL == CU_add_test(pSuite, "Simple Addition Test", test_add)) 
  {
    CU_cleanup_registry();

    return CU_get_error();
  }

  /* Run all tests using the CUnit Basic interface */ 
  CU_basic_set_mode(CU_BRM_VERBOSE);
  CU_basic_run_tests();
  CU_cleanup_registry();

  return CU_get_error();
}