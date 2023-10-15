// This will contain the test suite using CUnit.
#include <stdio.h>
#include <CUnit/Basic.h>
#include "tic_tac_toe.c" // allow it to access functions and code

// test funtion for isValidMove function from tic_tac_toe.c
void test_isValidMove(){
    initializeBoard();
    // add some moves to the board
    board[0][0] = 'X'; // top left corner
    board[1][1] = 'O'; // middle

    // test if the ocupied cell is recognized as invalid
    CU_ASSERT_FALSE(isValidMove(0, 0));
    CU_ASSERT_FALSE(isValidMove(1, 1));

    // test if the empty cell is recognized as valid
    CU_ASSERT_TRUE(isValidMove(0, 1));
    CU_ASSERT_TRUE(isValidMove(2, 2));

    // test if the cell outside the board is recognized as invalid
    CU_ASSERT_FALSE(isValidMove(4, 4)); 
}

// tes for checkWin function from tic_tac_toe.c
void test_checkWin(){
    // test win condition for rows
    initializeBoard();
    board[0][0] = 'X';
    board[0][1] = 'X';
    board[0][2] = 'X';
    CU_ASSERT_TRUE(checkWin('X'));
    CU_ASSERT_FALSE(checkWin('O'))

    // test win condition for columns
    initializeBoard();
    board[0][0] = 'O';
    board[1][0] = 'O';
    board[2][0] = 'O';
    CU_ASSERT_TRUE(checkWin('O'));
    CU_ASSERT_FALSE(checkWin('X'));

    // Test win condition for diagonals
    initializeBoard();
    board[0][0] = 'X';
    board[1][1] = 'X';
    board[2][2] = 'X';
    CU_ASSERT_TRUE(checkWin('X'));
    CU_ASSERT_FALSE(checkWin('O'));

    initializeBoard();
    board[0][2] = 'O';
    board[1][1] = 'O';
    board[2][0] = 'O';
    CU_ASSERT_TRUE(checkWin('O'));
    CU_ASSERT_FALSE(checkWin('X'));

}

int main() {
    // Initialize CUnit test registry
    if (CUE_SUCCESS != CU_initialize_registry()) {
        return CU_get_error();
    }
    // Add test suite to registry
    CU_pSuite suite = CU_add_suite("Suite", NULL, NULL);
    if (NULL == suite) {
       CU_cleanup_registry();
       return CU_get_error();
    }
    // add the test funtin to the suite
    if (NULL == CU_add_test(suite, "Test isValidMove function", test_isValidMove) ||
        NULL == CU_add_test(suite, "Test Check win function", test_checkWin)) {
        CU_cleanup_registry(); 
        return CU_get_error();
    }
    // Set up the basic run mode and run the tests
    CU_basic_set_mode(CU_BRM_VERBOSE);
    CU_basic_run_tests();

    // Clean up the test registry
    CU_cleanup_registry();
    return CU_get_error();

}