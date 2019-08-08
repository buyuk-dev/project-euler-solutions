''' My initial approach involved writing recursive formulas for elements on both
    diagonals, than converting them to iterative formulas which i next simplified
    by eliminating all summations. This worked, however was pretty cumbersome.

    Than i did some reading and it turns out that a simple paradigm shift makes the
    task much simpler. Instead of summing elements on the diagonals, we can think of it
    as summing corners of the sub-spirals.


  x-n+1 --> * . . . . . * <-- x
            . . . . . . .
            . . . . . . .
            . . . . . . .
            . . . . . . .
 x-2n+2 --> * . . . . . * <-- x-3n+3

    sum = x + (x-n+1) + (x-2n+2) + (x-3n+3)
        = 4x - 6n + 6

    Now for the spiral with size n, x = n^2, so we can substitute it in this equation:

    sum = 4n^2 - 6n + 6

    Now we just need to sum values of this formula for n = 1, 3, 5, ..., 1001
    We can compute sum of each term of the equation separately:

    sum n^2 = (4n^3 - n) / 3
    sum n = 6n^2
    sum 1 = 6n

    Bringing all of it together we get a final equation:

    solution = 4(4n^3 - n) / 3 - 6n^2 + 6n
'''

def cornerSum(n):
    if n == 1: return 1
    return 4 * n * n - 6 * n + 6


total = 0
for i in range(1, 1002, 2):
    total += cornerSum(i)


print(total)

