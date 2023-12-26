//CONNECT FOUR PROJECT
#include<stdio.h>
#include<string.h>
#include<string.h>
#include<math.h>
#include<windows.h>
#include<conio.h>

char check[4];
char yes[] = "yes";
int num_rows = 12;
int num_cols = 12;

int save_load();

int i = 0, j = 0, k, n, row, col, value, score_x = 0, score_o = 0, game_mode = 0, number, Highscore, connecter = 0, b = 0, select_sides = 0;
char board[100][100];
char read[10];
char name1[20];
char name2[20];
char save[] = "save";
char sides[] = "replace";
char red[] = "redo";
char undo[] = "undo";
char mains[] = "start";
int position[100];
int redo[100];

void printboard();      //FUNCTIONS TO PRINT BOARD
void findposition();    //FUNCTION TO GET THE POSITION OF ELEMENT
void printnumber();     //FUNCTION TO PRINT NUMBER AND CHECK IT's VALIDTY
void scoreCheck();      //FUNCTION TO CHECK SCORE
void High_Score();      //FUNCTION TO DETERMINE THE HIGH SCORE
void select_side();     //FUNCTION TO SWAPE SELECT SIDES
void XML();             //FUNCTION TO READ FROM XML FILE
void instrctions();     //FUNCTIONS TO PRINT THE INSTRUCTIONS OF THE GAME
int main() {
    int flag = 1;
    XML();              //FUNCTION TO READ FROM XML FILE
    findposition();     //FUNCTION TO GET THE POSITION OF ELEMENT
    start();            //FUNCTION FOR MAIN MENU
    score_o = 0;
    score_x = 0;
    b = 0;                //NEW INTIALIZATION FOR NEW GAME
    while (flag == 1) {                         //FLAG TO START A NEW GAME
        printf("\nDo you want to go to main menue yes/no?");
        scanf("%s", &check);
        if (strcmp(check, yes) == 0)start();        //ASKING FOR CONTINUE
        else flag = 0;
    }
    return 0;
}

//FUNCTION TO STARTING THE MAIN MENU
void start() {
    XML();
    int choose;
    system("cls");                              //CLEAR SCREEN AFTER EACH PLAY
    for (i = 0; i < 15; i++)printf("\n");
    system("COLOR 1C");                         //CHANGING THE COLOR OF SCREEN
    printf("                              Welcome to connect four\n");              //WELCOME MESSAGE
    Sleep(1000);
    for (k = 0; k < 3; k++)printf("\n");
    system("COLOR EC");                           //CHANGING COLR OF THE SCREEN
    printf("                                   1-new game\n"                ////////////////////////////
           "                                   ----------  \n"              //                          //
           "                                   2-high scores\n"              //    MAIN MENU            //
           "                                   -------------\n"              ////////////////////////////
           "                                   3-load game\n"
           "                                   -----------\n"
           "                                   4-instruction\n"
           "                                   -------------      "
           "                                   \n");
    printf("choose from the previous options: \n");
    for (i = 0; i < 32; i++)
        printf("-");                                              //SCAN THE OPERATION TYPE FROM THE USER
    printf("\n");
    scanf("%d", &choose);                                                        //GET THE USER CHOOSE
    switch (choose) {
        case 1:
            printnumber();
            break;
        case 2:
            High_Score();
            break;
        case 3:
            read[0] = 'l';
            save_load();
            printnumber();
            break;
        case 4:
            instrctions();
            break;
        default:
            printf("error please try again !!");
    }
}

void instrctions() {
    system("cls");                                       //PRINTING A NEW SCREEN
    system("COLOR 1C");
    printf("             ****        HOW TO PLAY        **** \n\n\n");          //GAME INSTRUCTIONS
    printf("the aim of the game is to connect 4 (x) or 4 (0) vertically or\n horizontally or diagonally \n");
    printf("the player who connect 4 more than the other will be the winner\n\n\n");
    printf("press u or undo :    to go back one step , you can return back to first turn in the board\n");
    printf("press r or redo :    to go forward for one step, you can return the board again\n");
    printf("press s or save :    to save the game with its score \n");
    printf("to  load a game :    to load the game again you can use this option  \n                   just press start and choose load from menue\n");
    printf("press start     :    to go to main menue at any time\n");
    printf("press replace   :    to re-select sides this option can't be use in case of player v.s computer to prevent\n evil indeeds");
    char back[] = "back";
    char main[6];
    printf("\n press back to return to main menue \n");         //GET BACK TO MAIN MENU TO CONTINUE PLAYING
    scanf("%s", &main);
    if (strcmp(main, back) == 0) {
        system("cls");
        start();
    }
}

//FUNCTION TO PRINT THE BOARD
void printboard() {
    int row, col, a, c;
    if (b == 0) {                               //INTIALIZATION TO BOARD WITH '.'
        for (a = 0; a < num_rows; a++) {
            for (c = 0; c < num_cols; c++)
                board[a][c] = '.';
        }
    }
    b++;
    system("cls");                          //TO CLEAR SCREEN AFTER EACH PLAY
    system("COLOR 4E");                     //TO COLOR THE BOARD
    for (row = 0; row < num_rows; row++) {        //PRINTING THE BOARD
        for (col = 0; col < num_cols; col++) {

            printf("| %c ", board[row][col]);
        }
        printf("|\n");
        for (a = 0; a < num_cols; a++) printf("____");
        printf("\n");
    }
    for (a = 0; a < num_cols; a++)printf("%*d", 4, a + 1);
    printf("\n");
}

//FUNCTION TO FIND THE POSITION OF ELEMENTS IN BOARD
void findposition() {
    for (i = 0; i < num_cols; i++) {
        position[i] = num_rows - 1;
    }
}

//FUNCTION TO PRINT THE X & O AND CHECK THE BOARD
void printnumber() {

    if (read[0] != 'l') {
        printf("choose the game mode \n");
        printf("--------------------\n");
        printf("                         1) Player V.s Player \n                         2) Player V.s Computer \n                         3)player V.s hard computer\n");
        scanf("%d", &game_mode);                 //GET THE GAME MODE FROM THE USER
        b = 0;
        printboard();                           //FUNCTION TO PRINT BOARD
        findposition();                         //FUNCTION TO GET THE POSITION OF ELEMENT
    }
    printf("please enter player (1) name: ");       //GETTING THE PLAYERS NAME FROM THE USER
    scanf("%s", &name1);
    if (game_mode == 1) {
        printf("please enter player (2) name: ");
        scanf("%s", &name2);
    }

    for (i = connecter; i < num_cols * num_rows + select_sides; i++) {

        if (i % 2 == 0) {                         //SWAPING TURNS
            printf(" %s's turn\n choose the column to put x in: ", name1);       //PRINTING PLAYER'S TURNS
            scanf("%s", &read);
            number = atoi(read);

        } else {
            if (game_mode == 1) player2();                    //CALLING THE FUNCTIONS OF PLAYERS MODE
            else if (game_mode == 2)computer();
            else medium_computer();
        }
        if (strcmp(read, sides) == 0) {
            select_side();
            i--;
        }
        else if (strcmp(read, mains) == 0) {
            XML();
            printf("WARNING the game won't be save\n do you want to save yes/no ? ");           //WARNING IN CASE OF NOT SAVING FILE
            scanf("%s", check);
            if (strcmp(check, yes) == 0) {

                read[0] = 's';
                save_load();
            }
            score_x = 0;
            score_o = 0;
            findposition();
            b = 0;
            printboard();
            start();
            break;
        } else if (strcmp(read, save) == 0 ||
                   (read[0] == 's' && read[1] == '\0')) {     //COMPARISON IF THE USER WANT TO SAVE OR LOAD

            save_load();
            i--;
        } else if ((read[0] == 'r' && read[1] == '\0') || strcmp(read, red) == 0 ||
                   (read[0] == 'u' && read[1] == '\0') || strcmp(read, undo) == 0) {    //CHECK FOR UNDO AND REDO
            redo_undo();
        } else if (number < 1 || number > num_cols || board[0][number - 1] != '.') {                   //BOARD LIMITS
            printf("out of scoop please try again\n");
            i--;
        } else {                                                 //PRINTING X AND O
            redo[i] = number - 1;
            value = position[number - 1];
            if (i % 2 == 0)board[value][number - 1] = 'X';
            else board[value][number - 1] = 'O';
            position[number - 1] -= 1;
            scoreCheck();                                  //CHECK SCORE
            printboard();                                   //PRINTING THE BOARD
            if (i % 2 == 0) system("COLOR 5E");                  //CHANGING THE COLOR OF SCREEN FOR EACH PLAYER
            else system("COLOR BC");
            printf("Score X =  %d    Score O =%d\n ", score_x, score_o);          //PRINTING THE SCORE
            printf("             ****        HOW TO PLAY        **** \n\n\n");          //GAME INSTRUCTIONS
            printf("the aim of the game is to connect 4 (x) or 4 (0) vertically or\n horizontally or diagonally \n");
            printf("the player who connect 4 more than the other will be the winner\n\n\n");
            printf("press u or undo :    to go back one step , you can return back to first turn in the board\n");
            printf("press r or redo :    to go forward for one step, you can return the board again\n");
            printf("press s or save :    to save the game with its score \n");
            printf("to  load a game :    to load the game again you can use this option  \n                   just press start and choose load from menue\n");
            printf("press start     :    to go to main menue at any time\n");
            printf("press replace   :    to re-select sides this option can't be use in case of player v.s computer to prevent\n evil indeeds\n");
        }
    }
    if (i == num_rows * num_cols) {

        High_Score();                    //CALLING HIGH SCORE FUNCTION WHEN GAME IS ENDED
        printf("\nDo you want to save ? (yes/no ) \n");
        scanf("%s", &check);
        if (strcmp(check, yes) == 0) {
            read[0] = 's';
            save_load();
        }
    }
}

//FUNCTION TO CHECK CONNECT FOUR OR NOT
char checkFour(int a_1, int a_2, int b_1, int b_2, int c_1, int c_2, int d_1, int d_2) {
    if (board[a_1][a_2] == board[b_1][b_2] && board[b_1][b_2] == board[c_1][c_2] &&
        board[c_1][c_2] == board[d_1][d_2] && board[a_1][a_2] != '.')
        return board[a_1][a_2];
    return 'a';
}

//FUNCTION TO CHECK SCORE AFTER EACH PLAY
void scoreCheck() {
    int i = 1, j = 1, counter = 0, a, c = 1, b = -1;
    for (a = 0; a < 4; a++) {
        i = -i;
        j = j * pow(-1, counter); //LOOPING TO CHCK SCORE IN FOUR DIRECTIONS
        counter++;
        if (num_rows > value + i * 3 && value + i * 3 >= 0 && num_cols > number - 1 + j * 3 &&
            number - 1 + j * 3 >= 0) {
            if ('X' == checkFour(value, number - 1, value + i, number - 1 + j, value + i * 2, number - 1 + j * 2,
                                 value + i * 3, number - 1 + j * 3))
                score_x += 1;
            if ('O' == checkFour(value, number - 1, value + i, number - 1 + j, value + i * 2, number - 1 + j * 2,
                                 value + i * 3, number - 1 + j * 3))
                score_o += 1;
        }
        if ('X' == checkFour(value, number - 1, value + j, number - 1 + i, value - j, number - 1 - i, value - 2 * j,
                             number - 1 - 2 * i))
            score_x += 1;
        if ('O' == checkFour(value, number - 1, value + j, number - 1 + i, value - j, number - 1 - i, value - 2 * j,
                             number - 1 - 2 * i))
            score_o += 1;
    }
    for (a = 0; a < 2; a++) {
        c = -c;
        b *= -1;
        if (num_rows > value + 3 * c && value + 3 * c >= 0) {
            if ('X' == checkFour(value, number - 1, value + c, number - 1, value + 2 * c, number - 1, value + 3 * c,
                                 number - 1))
                score_x += 1;
            if ('O' == checkFour(value, number - 1, value + c, number - 1, value + 2 * c, number - 1, value + 3 * c,
                                 number - 1))
                score_o += 1;
        }
        if (num_cols > number - 1 + 3 * c && number - 1 + 3 * c >= 0) {
            if ('X' == checkFour(value, number - 1, value, number - 1 + c, value, number - 1 + 2 * c, value,
                                 number - 1 + 3 * c))
                score_x += 1;
            if ('O' == checkFour(value, number - 1, value, number - 1 + c, value, number - 1 + 2 * c, value,
                                 number - 1 + 3 * c))
                score_o += 1;
        }
        if ('X' ==
            checkFour(value, number - 1, value, number - 1 + b, value, number - 1 - b, value, number - 1 - 2 * b) &&
            value - 2 * b >= 0)
            score_x += 1;
        if ('O' ==
            checkFour(value, number - 1, value, number - 1 + b, value, number - 1 - b, value, number - 1 - 2 * b) &&
            value - 2 * b >= 0)
            score_o += 1;
    }
}

//FUNCTION FOR UNDO AND REDO
void redo_undo() {
    int old_scorex = score_x;
    int old_scoreo = score_o;
    if (strcmp(read, undo) == 0 ||
        (read[0] == 'u' && read[1] == '\0')) {             //CALLING THE FUNCTION WHEN UUSER ENTER U OR UNDO
        i--;
        if (i <
            0) {}                                                       //IF I<0 HE CAN'T UNDO ANY STEP SO THIS FUNCTION IS USELESS
        else {
            int col = redo[i];
            number = col + 1;
            value = position[number - 1] + 1;
            scoreCheck();                               //CHECKING THE SCORE
            if (score_x > old_scorex)
                score_x = score_x - 2 * (score_x - old_scorex);               //CECK THE NEW SCORE AFTER REDO
            if (score_o > old_scoreo)score_o = score_o - 2 * (score_o - old_scoreo);
            position[col] += 1;
            number = col + 1;
            row = position[col];
            board[row][col] = '.';
            i--;
            j++;
        }
    } else {
        if (j < 1) {
            i--;
        } else {
            int col = redo[i];
            row = position[col];
            if (i % 2 == 0)board[row][col] = 'X';              //IT RETURNS THE X REMOVED BY UNDO FUNCTION
            else board[row][col] = 'O';
            position[col] -= 1;
            value = row;
            number = col + 1;
            scoreCheck();
            j--;
        }
    }
    printboard();                                               //CHEXK SCORE AFTER UNDO & REDO
    printf("Score X = %d    Score O =%d \n", score_x, score_o);   //PRINTING THE SCORE
}

//FUNCTION TO PLAY PLAYER VS PLAYER
int player2() {

    printf("%s's turn\n choose the column to put 0 in: ", name2);          //PRINTING TURN TO PLAYER TWO
    scanf(" %s", read);                                          //SCAN THE NUMBR FROM PLAYER TWO
    number = atoi(read);
    return number;
}

//FUNCTION TO PLAY VS COMPUTER EASY
int computer() {
    printf("Computer  turn: ");
    if ((read[0] == 'u' && read[1] == '\0') || strcmp(read, undo) == 0)
        return;           //FOR UNDO AND REDO RETURN NOTHING TO GET BACK FOR PLAYER TURN
    else {
        number = 1 + (rand() % num_cols);                     //COMPUTER PLAYING IN A RANDOM WAY
        return number;
    }
}

//FUNCTION FOR SAVE AND LOAD BINRY !!!!!!!!
int save_load() {

    int k = num_rows - 1, n, load;       //INTIALIZATION AND DECLERATION VARAIABLES
    static int counter = 6;
    char byte = 0;
    FILE *save;
    if ((read[0] == 's' && read[1] == '\0') || strcmp(read, save) == 0) {


        char fileName[100], str[100];
        puts("enter the file name : ");                     //GET THE FILE NAME FROM THE USER
        scanf("%s", fileName);
        sprintf(str, "%s%s", fileName, ".shehab");             //ADD THE EXE TO THE FILE NAME
        FILE *save = fopen(str, "wb");                          //OPEN THE FILE FOR WRITE BINRY
        byte |= num_cols << 4;
        byte |= num_rows;
        fprintf(save, "%c", byte);
        byte = 0;

        for (n = 0; n < num_cols; n++) {
            k = num_rows - 1;
            while (k >= 0) {                                    //WRITING IN BINRY FILE
                if (board[k][n] == 'X')load = 3;
                else if (board[k][n] == 'O')load = 2;
                else if (board[k][n] == '.')load = 0;
                byte |= load << counter;                      //SHIFTING THE BITS
                counter -= 2;
                if (counter == -2) {
                    counter = 6;
                    fprintf(save, "%c", byte);
                    byte = 0;
                }
                if (load == 0)break;
                k--;
            }
        }
        if (counter != -2)fprintf(save, "%c", byte);
        fclose(save);
        printf("Do you want to continue yes/no ? \n");
        scanf(" %s", &check);
        if (strcmp(yes, check) == 0) {}
        else exit(main);
    } else if (read[0] == 'l') {     //LOADING THE BINRY FILE

        i = 0;
        char fileName[100], str[100];               //DECLARTION
        puts("enter the file name : ");             //GET THE FILE NAME FROM THE USER
        scanf("%s", fileName);
        strcat(fileName, ".shehab");                 //ADD THE EXETO THE FILE NAME
        sscanf(str, "%s", fileName);
        printf(" 1) Player V.s Player \n 2) Player V.s Computer \n 3) medium computer \n");
        scanf("%d", &game_mode);                        //ASK THE USER FOR GAME LOADING MODE
        save = fopen(fileName, "rb");                     //READ BINRY FROM THE FILE
        fscanf(save, "%c", &byte);

        num_rows = byte & 0xF;
        num_cols = (byte >> 4) & 0xF;

        b = 0;
        findposition();
        printboard();
        system("cls");
        counter = 6;
        for (n = 0; n < num_cols; n++) {
            k = num_rows - 1;
            while (k >= 0) {                            //SHIFTING AND READING FROM BINRY FILE
                if (counter == 6) {
                    fscanf(save, "%c", &byte);
                }
                load = (byte >> counter) & 3;
                if (load == 0) {
                } else if (load == 2) {
                    i++;
                    connecter++;
                    board[k][n] = 'O';
                    value = k;
                    number = n + 1;
                    position[number - 1]--;
                    scoreCheck();                            //CHECK THE SCORE AFTER READING
                } else if (load == 3) {
                    i++;
                    connecter++;
                    board[k][n] = 'X';
                    value = k;
                    number = n + 1;
                    position[number - 1]--;
                    scoreCheck();
                }
                counter -= 2;
                if (counter == -2) {
                    counter = 6;
                }
                k--;
                if (load == 0)break;
            }

        }
        fclose(save);                      //closing the file
        printboard();
        printf("Score X = %d    Score O =%d \n", score_x, score_o);       //PRINTING THE SCORE
    }
}

//AI FUNCTION FOR PLAYING VS COMPUTER
int medium_computer() {
    // THE FIRST PART OF AI THE MAIN IDEA OF THE AI IS WHEN THE TURN IS TO COMPUTER THE COMPUTER PUT X IN THE BOARD AND IF THE SCORE OF X INC. THEN
    // IT'S THE BEST PLACE FOR O TO PREVENT X FROM CONNECTING FOUR
    //IF THERE IS NO DANGER FROM X TO WIN SO THE COMPUTER STARTS TO THINK ABOUT THE BEST WAY TO PLAY SO IT'S SCORE INC.
    int old_scorex = score_x;
    int old_scoreo = score_o;
    //CONNECT_4X REFERS TO ANY  FOUR X
    //CONNECT3_X REFERES TO EVERY THREE X AFTER EACH OTHER
    //CONNECT4_0 REFERES TO EVERY FOUR O AFTER EACH OTHER
    //CONNECT3_0 REFERES TO EVERY THREE O AFTER EACH OTHER
    //CONNECT2_0 REFERES TO EVERY TWO O AFTER EACH OTHER
    //CONNECT1_0 REFERES TO EVERY ONE O AND HAVE 3 SPACES AFTER IT OR BEFORE IT
    int connect4_x = -1, connect3_x = -1, connect4_o = -1, connect3_o = -1, connect2_o = -1, connect1_o = -1;
    int num = number, critical;
    number = number - 4;
    //HERE THE COMPUTER START TO DETECT THE BEST WAY FOR O TO PREVENT X FROM WINNIG
    for (k = -3; k <= 3; k++) {
        number++;
        if (number < 1 || position[number - 1] == -1 || number > num_cols) {
            continue;
        } else {
            value = position[number - 1];
            board[value][number - 1] = 'X';
            scoreCheck();
            board[value][number - 1] = '.';
            if (score_x - old_scorex > 0) {
                connect4_x = number;
                score_x = old_scorex;
            }
            score_x = old_scorex;
            if (score_x - old_scorex > 0)break;
        }
    }
    //AFTER COMPUTER FAIL IN FINDING THE PLACE WHERE IF X PLAYS ON IT WILL WIN HE BEGIN TO CHECK ONE CASE IF THERE IS 2 X ON THE
    //SAME ROW AND HAS TWO OR MORE SPACE BEFORE AND AFTER IT HE CONSIDER THIS CASE AS A CRITICAL ONE AND PREDICT WITH 2 STEPS
    if (connect4_x == -1) {
        number = num;
        value = position[number - 1];
        if (board[value + 1][number - 2] == 'X' &&
            ((value + 1 == position[number] && value + 1 == position[number + 1] &&
              value + 1 == position[number - 3]) ||
             (value + 1 == position[number] && value + 1 == position[number - 3] && value + 1 == position[number - 4])))
            connect3_x = number + 1;

        else if ((board[value + 1][number] == 'X') &&
                 ((value + 1 == position[number + 1] && value + 1 == position[number + 2] &&
                   value + 1 == position[number - 2]) ||
                  (value + 1 == position[number - 2] && value + 1 == position[number - 3] &&
                   value + 1 == position[number + 1])))
            connect3_x = number - 1;

    }
    //AFTER HE FAILS TO DEFENCE HE TRIES TO ATTACK
    //HE WILL CHECK THE BEST WAY TO PLAY O TO WIN
    if (connect3_x == -1 && connect4_x == -1) {
        for (n = 0; n < num_cols; n++) {
            number = n + 1;
            if (position[n] >= 0) {
                value = position[n];
                board[value][n] = 'O';
                number = n + 1;
                scoreCheck();
                if (score_o - old_scoreo > 0) {
                    connect4_o = number;
                    score_o = old_scoreo;
                    score_x = old_scorex;
                }
                score_o = old_scoreo;
                score_x = old_scorex;
            }
            if (n < num_cols - 1 && connect4_o == -1 && position[n + 1] >= 0) {
                value = position[n + 1];
                board[value][n + 1] = 'O';
                number = n + 2;
                scoreCheck();
                if (score_o - old_scoreo > 0) {
                    connect3_o = number;
                    score_o = old_scoreo;
                    score_x = old_scorex;
                }
                score_o = old_scoreo;
                score_x = old_scorex;
            }
            if (n < num_cols - 2 && connect3_o == -1 && position[n + 2] >= 0 && connect4_o == -1) {
                value = position[n + 2];
                board[value][n + 2] = 'O';
                number = n + 3;
                scoreCheck();
                if (score_o - old_scoreo > 0) {
                    connect2_o = number;
                    score_o = old_scoreo;
                    score_x = old_scorex;
                }
                score_o = old_scoreo;
                score_x = old_scorex;
            }
            if (n < num_cols - 3 && connect2_o == -1 && position[n + 3] >= 0 && connect3_o == -1 && connect4_o == -1) {
                value = position[n + 3];
                board[value][n + 3] = 'O';
                number = n + 4;
                scoreCheck();
                if (score_o - old_scoreo > 0) {
                    connect1_o = number;
                    score_o = old_scoreo;
                    score_x = old_scorex;
                }
                score_o = old_scoreo;
                score_x = old_scorex;
            }
            if (position[n] >= 0) {
                value = position[n];
                board[value][n] = '.';
            }
            if (n < num_cols - 1 && position[n + 1] >= 0) {
                value = position[n + 1];
                board[value][n + 1] = '.';
            }
            if (n < num_cols - 2 && position[n + 2] >= 0) {
                value = position[n + 2];
                board[value][n + 2] = '.';
            }
            if (n < num_cols - 3 && position[n + 3] >= 0) {
                value = position[n + 3];
                board[value][n + 3] = '.';
            }
        }
    }
    number = num;
    if ((read[0] == 'u' && read[1] == '\0') || strcmp(read, undo) == 0 || strcmp(read, sides) == 0) {

        return;
    } else if (connect4_x > -1) {
        number = connect4_x;
        return number;
    } else if (connect3_x > -1) {
        number = connect3_x;
        return number;
    } else if (connect4_o > -1) {
        number = connect4_o;
        return number;
    } else if (connect3_o > -1) {
        number = connect3_o;
        return number;
    } else if (connect2_o > -1) {
        number = connect2_o;
        return number;
    } else if (connect1_o > -1) {
        number = connect1_o;
        return number;
    } else {
        for (n = 0; n < num_cols; n++) {
            value = position[n];
            if (board[value][n] == '.') {
                number = n + 1;
                return number;
            }
        }
    }
}

//FUNCTION TO READ FROM XML FILE
void XML() {
    //START REFEERE TO START OF INDEX TO CONFIGURATION TAG
    //END REFEERE TO END OF INDEX OF CONFIGURATION TAGG
    //START _W REFEERE TO STARTING INDEX OF WIDTH TAG
    //END_W REFEERE TO ENDING INDEX OF WIDTH TAG
    //START _H REFFERE TO START INDEX OF HEIGHT TAG
    //END_H REFFERE TO END INDEX OF HIEGHT TAG
    //START HS REFFERE TO START INDEX OF HIGHSCORES TAG
    //END_HS REFFERE TO END INDEX OF HIGHSCORE TAG
    //LEN REFFERE TO THE LENGTH BETWEEN TWO CONFIGURTIONS
    //a IN A COUNTER
    // HS ------> HIGHSSCORE    H -------> HEIGHT      W ---------> WIDTH
    char y, x[200] = {
            '0'}, conf_1[] = "<Configurations>", width_1[] = "<Width>", height_1[] = "<Height>", highscores_1[] = "<Highscores>";
    char conf_2[] = "</Configurations>", width_2[] = "</Width>", height_2[] = "</Height>", highscores_2[] = "</Highscores>";
    int i = 0, start, end, start_w, end_w, start_h, end_h, start_hs, end_hs, len, a, size, HS, H, W;
    FILE *file = fopen("project.xml", "r");              //READING FROM THE FILE
    while ((y = fgetc(file)) != EOF) {
        if (y != ' ' && y != '\n' && y != '\t') {           //IGNORING ANY SPACES OR TABS OR BREAKING LINE
            x[i] = y;
            i++;
            len++;
        }
    }
    start = over_lapping(conf_1, x);               //CALLING OVERLAPPING FUNCTION
    end = over_lapping(conf_2, x);
    size = end - start + 1;
    char array[size];                           //ARRAY TO RED BETWEEN TWO CONFIGRATIONS TAGS
    for (a = 0; a < size; a++)array[a] = x[start + a];   // INTIALIZATION FOR NWE ARRAY
    start_w = over_lapping(width_1, array);
    end_w = over_lapping(width_2, array);
    char row[3];                               //CHECKING OPENING AND CLOSING THE TAGS IN RIGHT WAY
    row[0] = array[start_w + 7];
    row[1] = array[start_w + 8];
    row[2] = '\0';
    if (start_w != -1 && end_w != -1 && (end_w - start_w == 8 || end_w - start_w == 9) && atoi(row) >= 4) W = atoi(row);

    else {                                       //SET THE DEFULT IN THERE IS WRONG IN READING THE XML FILE
        system("COLOR 8C");
        W = 7;
        printf("Width is Not found !! the defult is Width =7\n");
        printf("Wait to load the default!!\n");
        Sleep(5000);
    }
    start_h = over_lapping(height_1, array);       //CALLING THE OVERLAPPING FUNCTION
    end_h = over_lapping(height_2, array);
    char col[3];                                  //CHECK OPENING AND CLOSING THE TAGS IN WRIGHT WAY
    col[0] = array[start_h + 8];
    col[1] = array[start_h + 9];
    col[2] = '\0';
    if (start_h != -1 && end_h != -1 && (end_h - start_h == 9 || end_h - start_h == 10) && atoi(col) >= 4)H = atoi(col);
    else {
        H = 6;                                        //SET THE DEFULT IF THERE IS ERROR WHILE READING FROM XML FILE
        printf("Height is Not found !! the defult is Height =6\n");
        printf("Wait to load the default!!\n");
        Sleep(5000);
    }
    start_hs = over_lapping(highscores_1, array);
    end_hs = over_lapping(highscores_2, array);        //CALLING OVER LAPPING FUNCTIONS
    char score[3];
    score[0] = array[start_hs + 12];                    //PUTTING BETWEEN TAGS IN ARRAY FOR READING WITH ATOI
    score[1] = array[start_hs + 13];
    score[2] = '\0';
    if (start_hs != -1 && end_hs != -1 && end_hs - start_hs == 13 || end_hs - start_hs == 14)HS = atoi(score);
    else {
        HS = 5;                                       //SET THE DEFULT VALUE
        printf("High_score is Not found !! the defult is Highscore =5\n");      //PRINTING ERROR
        printf("Wait to load the default!!\n");                                 //ERROR MESSAGE
        Sleep(5000);
    }
    num_cols = W;                                     //CHANGING THE GLOBAL VALUE FOR WIDTH
    num_rows = H;                                     //CHANGING THE GLOBAL VALUE FOR HEIGHT
    Highscore = HS;                                   //CHANGING THE GLOBAL VAUE FOR HIGH SCORE
}

//FUNCTION TO CHECK IF WORD IS FOUND IN STRING OR NOT
int over_lapping(char s1[], char s2[]) {
    int counter = -1, i = 0;
    while (s2[i] != '\0') {
        int j = 0;
        if (s2[i] == s1[j]) {
            int k = i;
            while (s2[k] == s1[j] && s1[j] != '\0') {
                k++;
                j++;
            }
            if (s1[j] == '\0') {
                counter = i;
            }
        }
        i++;
    }
    return counter;
}

//FUNCTION TO PRINT THE HIGH SCORE LIST
void High_Score() {
    int scores[100] = {0}, i, counter = -1, j = 0, temp = 0;
    FILE *file = fopen("High_scores.text", "r");         //READING FROM THE FILE
    for (i = 0; i < 20; i++) {
        fscanf(file, "%d", &scores[i]);
        if (scores[i] != 0) counter++;
    }
    if (score_x > score_o) scores[counter + 1] = score_x;
    else scores[counter + 1] = score_o;
    for (i = 0; i < Highscore; i++) {             //SORTING THE ARRAY FOR PRINTING
        for (j = 0; j < Highscore; j++)
            if (scores[j] < scores[i]) {
                temp = scores[i];
                scores[i] = scores[j];
                scores[j] = temp;
            }
    }
    printf("HIGH SCORE LIST IS : ");                    //PRINING THE HIGH SCORE LIST
    file = fopen("High_scores.text", "w");               // WRITING THE HIGH SCORE LIST IN FILE
    for (i = 0; i < Highscore; i++) {
        printf("%d   ", scores[i]);
        fprintf(file, "%d  ", scores[i]);
    }
    fclose(file);
}

//FUNCTIONS TO SWAP SELECT SIDES OF TWO PLAYERS
void select_side() {
    if (game_mode == 1) {
        printf("Enter the new name for %s :", name1);        //GETTING THE USER NAME
        scanf("%s", &name1);
        printf("Enter the new name for %s :", name2);
        scanf("%s", &name2);
        select_sides = 1;
    }
}
