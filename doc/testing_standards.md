## Testing Standards
We will be using CUnit for testing and make for automation.

In naming test methods, I follow the pattern of shouldDoSomethingWhenSomeConditionHolds.

1. Names must clearly communicate what is under test and what is being asserted.
2. As specifications they should be doing just that - specifying behaviour. That is, unit
tests should not contain logic - or potentially they fall into the trap of repeating the program's functionality rather than testing it.
3. When mock objects are involved the test setup should be separate from the logic.

Reference:
[xUnit Test Patterns by Gerard Meszaros](https://www.amazon.com/dp/0131495054/?tag=stackoverfl08-20)
