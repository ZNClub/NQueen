

#include<stdio.h>;

#include<math.h>;

int n = 0, col[20] = {0}, count = 0;

// column array and count getting initialized to zero

void solution()
 {

    int i, j;

    for (i = 1; i <= n; i++)

        /* loop for printing the solution vector which will show us the

        placement of all the queens */
 {

        for (j = 1; j < col[i]; j++)

            printf("x\t");

        printf("q%d\t", i);

        for (; j < n; j++)

            printf("x\t");

        printf("\n");

    }

}

void nqueen(int q)

/* only row no. is needed to pass as a parameter to nqueen function

since queen no. is same as that of the row no. */
 {

    int c, i;

    for (c = 1; c <= n; c++)
 {

        if (place(q, c)) // will call the place function
 {

            col[q] = c;

            if (q == n)

                // if all the queens are placed on the chessboard
 {

                count++;

                printf("\n-- -- -- -- -- SOLUTION NUMBER : %d-- -- -- -- -- \n\n", count);

                // suggests that multiple no. of solutions are possible

                solution();

                // call to solution function to display the result

            }
            else

                /* else not placed then it will call the nqueen function and it will try to

                place the next queen */

                nqueen(q + 1); //function call

        }

    }

}

int place(int q, int c)

/* function will return true or false based on whether the queen is

placed or not ; q is the row no. and c is the column no. */
 {

    int k;

    for (k = 1; k <= q - 1; k++)
 {

        if (c == col[k] || abs(k - q) == abs(col[k] - c))

            // checks for (column attack or diagonal attack)

            return 0;

    }

    return 1;

}

int main()
 {

    printf("ENTER THE NUMBER OF QUEENS:");

    scanf("%d", &n);

    // accepting no. of queens from the user

    if (n < 3)

        //solution cant be obtained for n&lt;3

        printf("\n NO SOLUTION FOR %d QUEEN PROBLEM\n", n);

    else

        nqueen(1); //call to nqueen function

}


/*

 ****************************************************

OUTPUT:

ENTER THE NUMBER OF QUEENS:4

-- -- -- -- -- -- -SOLUTION NUMBER : 1-- -- -- -- -- -- -- -- -- -- -- -- -- --

x q1 x x

x x x q2

q3 x x x

x x q4 x

-- -- -- -- -- -- -SOLUTION NUMBER : 2-- -- -- -- -- -- -- -- -- -- -- -- -- --

x x q1 x

q2 x x x

x x x q3

x q4 x x



 ****************************************************

 */
