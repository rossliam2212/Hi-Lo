# Simple Hi-Lo Console Game

The game automatically logs the details of every round and any deposits made to the [GameHistory.txt](https://github.com/rossliam2212/Hi-Lo/blob/master/GameHistory.txt) file.

Inspiration from [Gamdom.com/hilo](https://gamdom.com/hilo).

#### Note: 
- There is color while playing in the console to make things easier to read.
- If the unicode characters/colors don't show correctly in the console, try changing how the file is being encoded in your IDE/editor.

### Nine Different Option to Bet On:
- Each option has its own win multiplier.
- The Hi & Lo win multipliers are calculated each round depending on what the previous card flipped was. 
- The rest of the win multipliers are fixed.
```
------------------------------------
Option            Range   Multiplier
------------------------------------
1 - Bet Hi        (4-A)       [1.2x]
2 - Bet Lo        (2)          [12x]
3 - Bet Red                     [2x]
4 - Bet Black                   [2x]
5 - Bet 2-10                  [1.5x]
6 - Bet J,Q,K,A                 [3x]
7 - Bet K,A                     [6x]
8 - Bet A                      [12x]
9 - Bet Joker                  [24x]

10 - Additional Options
------------------------------------
```

### View Previous Card Details:
```
---------------------------
Previous 50 rounds
---------------------------
Red            24     [48%]
Black          25     [50%]
---------------------------
2               3      [6%]
3               3      [6%]
4               2      [4%]
5               5     [10%]
6               3      [6%]
7               5     [10%]
8               2      [4%]
9               4      [8%]
10              3      [6%]
J               5     [10%]
Q               5     [10%]
K               3      [6%]
A               6     [12%]
Joker           1      [2%]
---------------------------
```
### Sample Game:
```
Please enter your name: 
>Liam

Enter your starting Balance: 
>5000

=== Welcome to Hi-Lo Liam! ===

-- Game Instructions --
- When the game starts, you will be shown the back of a card like below.
=========
|       |
|   ♠   |
|       |
=========
- You will then be asked what you would like to be on from the options displayed.
- Once an option is chosen, you will be asked to enter the amount you want to bet.
- After your bet has been entered, the card will be flipped and the results will be calculated and displayed.

- The win multipliers for all of the options are displayed beside each option every round.
- The multipliers for Red, Black, (2-10), (J,Q,K,A), (K,A), (A) and Joker are fixed.
- However, the Hi & Lo multipliers are calculated based on what the previous card flipped was.
- The range for the Hi & Lo options are also calculated based on what the previous card flipped was.
- Note: You will not be able to bet on Hi or Lo until after the first card has been flipped.
- Note: The Joker is a special card and is not included in the Hi & Lo ranges or bets.

Ready to play? (y/n)
>y

-- Game Started. Good Luck! --

=========
|       |
|   ♠   |
|       |
=========
Balance: $5000
------------------------------------
Option            Range   Multiplier
------------------------------------
3 - Bet Red                     [2x]
4 - Bet Black                   [2x]
5 - Bet 2-10                  [1.5x]
6 - Bet J,Q,K,A                 [3x]
7 - Bet K,A                     [6x]
8 - Bet A                      [12x]
9 - Bet Joker                  [24x]

10 - Additional Options
------------------------------------
Previous Cards: 

What would you like to bet on?
>3
Enter your bet amount:
>500

=========
|       |
|   7   |
|       |
=========
Bet Amount: $500
Bet on: Red
Result: -$500

=========
|       |
|   ♠   |
|       |
=========
Balance: $4500
------------------------------------
Option            Range   Multiplier
------------------------------------
1 - Bet Hi        (8-A)         [2x]
2 - Bet Lo        (2-6)       [2.4x]
3 - Bet Red                     [2x]
4 - Bet Black                   [2x]
5 - Bet 2-10                  [1.5x]
6 - Bet J,Q,K,A                 [3x]
7 - Bet K,A                     [6x]
8 - Bet A                      [12x]
9 - Bet Joker                  [24x]

10 - Additional Options
------------------------------------
Previous Cards: 7, 

What would you like to bet on?
>10

Additional Options:
1 - View Balance.
2 - Deposit Balance.
3 - View previous cards in a table.
4 - Quit Game.

What would you like to do? 
>2

How much would you like to deposit?
>500
500 has been successfully added to your balance.
------------------------------------
Option            Range   Multiplier
------------------------------------
1 - Bet Hi        (8-A)         [2x]
2 - Bet Lo        (2-6)       [2.4x]
3 - Bet Red                     [2x]
4 - Bet Black                   [2x]
5 - Bet 2-10                  [1.5x]
6 - Bet J,Q,K,A                 [3x]
7 - Bet K,A                     [6x]
8 - Bet A                      [12x]
9 - Bet Joker                  [24x]

10 - Additional Options
------------------------------------
Previous Cards: 7, 

What would you like to bet on?
>5
Enter your bet amount:
>500

=========
|       |
|   9   |
|       |
=========
Bet Amount: $500
Bet on: 2 - 10
Result: +$750

=========
|       |
|   ♠   |
|       |
=========
Balance: $5250
------------------------------------
Option            Range   Multiplier
------------------------------------
1 - Bet Hi        (10-A)        [3x]
2 - Bet Lo        (2-8)      [1.71x]
3 - Bet Red                     [2x]
4 - Bet Black                   [2x]
5 - Bet 2-10                  [1.5x]
6 - Bet J,Q,K,A                 [3x]
7 - Bet K,A                     [6x]
8 - Bet A                      [12x]
9 - Bet Joker                  [24x]

10 - Additional Options
------------------------------------
Previous Cards: 7, 9, 

What would you like to bet on?
>9
Enter your bet amount:
>500

=========
|       |
|   2   |
|       |
=========
Bet Amount: $500
Bet on: Joker
Result: -$500

=========
|       |
|   ♠   |
|       |
=========
Balance: $4750
------------------------------------
Option            Range   Multiplier
------------------------------------
1 - Bet Hi        (3-A)      [1.09x]
2 - Bet Lo        (2)          [12x]
3 - Bet Red                     [2x]
4 - Bet Black                   [2x]
5 - Bet 2-10                  [1.5x]
6 - Bet J,Q,K,A                 [3x]
7 - Bet K,A                     [6x]
8 - Bet A                      [12x]
9 - Bet Joker                  [24x]

10 - Additional Options
------------------------------------
Previous Cards: 7, 9, 2, 

What would you like to bet on?
>7
Enter your bet amount:
>500

=========
|       |
|   10  |
|       |
=========
Bet Amount: $500
Bet on: K, A
Result: -$500

=========
|       |
|   ♠   |
|       |
=========
Balance: $4250
------------------------------------
Option            Range   Multiplier
------------------------------------
1 - Bet Hi        (J-A)         [3x]
2 - Bet Lo        (2-9)      [1.71x]
3 - Bet Red                     [2x]
4 - Bet Black                   [2x]
5 - Bet 2-10                  [1.5x]
6 - Bet J,Q,K,A                 [3x]
7 - Bet K,A                     [6x]
8 - Bet A                      [12x]
9 - Bet Joker                  [24x]

10 - Additional Options
------------------------------------
Previous Cards: 7, 9, 2, 10, 

What would you like to bet on?
>6
Enter your bet amount:
>500

=========
|       |
|   A   |
|       |
=========
Bet Amount: $500
Bet on: J, Q, K, A
Result: +$1500

=========
|       |
|   ♠   |
|       |
=========
Balance: $5250
------------------------------------
Option            Range   Multiplier
------------------------------------
1 - Bet Hi        (A)          [12x]
2 - Bet Lo        (2-K)      [1.09x]
3 - Bet Red                     [2x]
4 - Bet Black                   [2x]
5 - Bet 2-10                  [1.5x]
6 - Bet J,Q,K,A                 [3x]
7 - Bet K,A                     [6x]
8 - Bet A                      [12x]
9 - Bet Joker                  [24x]

10 - Additional Options
------------------------------------
Previous Cards: 7, 9, 2, 10, A, 

What would you like to bet on?
>6
Enter your bet amount:
>500

=========
|       |
|   4   |
|       |
=========
Bet Amount: $500
Bet on: J, Q, K, A
Result: -$500

=========
|       |
|   ♠   |
|       |
=========
Balance: $4750
------------------------------------
Option            Range   Multiplier
------------------------------------
1 - Bet Hi        (5-A)      [1.33x]
2 - Bet Lo        (2-3)         [6x]
3 - Bet Red                     [2x]
4 - Bet Black                   [2x]
5 - Bet 2-10                  [1.5x]
6 - Bet J,Q,K,A                 [3x]
7 - Bet K,A                     [6x]
8 - Bet A                      [12x]
9 - Bet Joker                  [24x]

10 - Additional Options
------------------------------------
Previous Cards: 7, 9, 2, 10, A, 4, 

What would you like to bet on?
>6
Enter your bet amount:
>500

=========
|       |
|   Q   |
|       |
=========
Bet Amount: $500
Bet on: J, Q, K, A
Result: +$1500

=========
|       |
|   ♠   |
|       |
=========
Balance: $5750
------------------------------------
Option            Range   Multiplier
------------------------------------
1 - Bet Hi        (K-A)         [6x]
2 - Bet Lo        (2-J)      [1.33x]
3 - Bet Red                     [2x]
4 - Bet Black                   [2x]
5 - Bet 2-10                  [1.5x]
6 - Bet J,Q,K,A                 [3x]
7 - Bet K,A                     [6x]
8 - Bet A                      [12x]
9 - Bet Joker                  [24x]

10 - Additional Options
------------------------------------
Previous Cards: 7, 9, 2, 10, A, 4, Q, 

What would you like to bet on?
>9
Enter your bet amount:
>250

=========
|       |
|   8   |
|       |
=========
Bet Amount: $250
Bet on: Joker
Result: -$250

=========
|       |
|   ♠   |
|       |
=========
Balance: $5500
------------------------------------
Option            Range   Multiplier
------------------------------------
1 - Bet Hi        (9-A)       [2.4x]
2 - Bet Lo        (2-7)         [2x]
3 - Bet Red                     [2x]
4 - Bet Black                   [2x]
5 - Bet 2-10                  [1.5x]
6 - Bet J,Q,K,A                 [3x]
7 - Bet K,A                     [6x]
8 - Bet A                      [12x]
9 - Bet Joker                  [24x]

10 - Additional Options
------------------------------------
Previous Cards: 7, 9, 2, 10, A, 4, Q, 8, 

What would you like to bet on?
>9
Enter your bet amount:
>250

=========
|       |
|   8   |
|       |
=========
Bet Amount: $250
Bet on: Joker
Result: -$250

=========
|       |
|   ♠   |
|       |
=========
Balance: $5250
------------------------------------
Option            Range   Multiplier
------------------------------------
1 - Bet Hi        (9-A)       [2.4x]
2 - Bet Lo        (2-7)         [2x]
3 - Bet Red                     [2x]
4 - Bet Black                   [2x]
5 - Bet 2-10                  [1.5x]
6 - Bet J,Q,K,A                 [3x]
7 - Bet K,A                     [6x]
8 - Bet A                      [12x]
9 - Bet Joker                  [24x]

10 - Additional Options
------------------------------------
Previous Cards: 7, 9, 2, 10, A, 4, Q, 8, 8, 

What would you like to bet on?
>9
Enter your bet amount:
>250

=========
|       |
|   5   |
|       |
=========
Bet Amount: $250
Bet on: Joker
Result: -$250

=========
|       |
|   ♠   |
|       |
=========
Balance: $5000
------------------------------------
Option            Range   Multiplier
------------------------------------
1 - Bet Hi        (6-A)       [1.5x]
2 - Bet Lo        (2-4)         [4x]
3 - Bet Red                     [2x]
4 - Bet Black                   [2x]
5 - Bet 2-10                  [1.5x]
6 - Bet J,Q,K,A                 [3x]
7 - Bet K,A                     [6x]
8 - Bet A                      [12x]
9 - Bet Joker                  [24x]

10 - Additional Options
------------------------------------
Previous Cards: 7, 9, 2, 10, A, 4, Q, 8, 8, 5, 

What would you like to bet on?
>10

Additional Options:
1 - View Balance.
2 - Deposit Balance.
3 - View previous cards in a table.
4 - Quit Game.

What would you like to do? 
>4

Thanks for playing Liam!
Come back soon :)

```
