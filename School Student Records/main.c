#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//Declaring user defined functions//
int add_new_student();
int search_for_a_student();
int update_student_data();
int remove_student_data();


int main(){
    //SPCC//
    //WELCOME TO THE STUDENT DATABASE//
    printf("\t\t\t\t SPCC    SPCC    SPCC    SPCC    SPCC    SPCC    SPCC");
    printf("\n\n\t\t\t\t\t  WELCOME TO THE STUDENT DATABASE\n\n");

    //Use a loop to repeat the main menu process until user wants to quit//
    int loop_breaker = 0;
    for(int repeat_main = 0; repeat_main >= 0;repeat_main++){
         //1. Add student data//
         //2. Search for student data//
         //3. Update student data//
         //4. Remove student data//
         printf("\n\n\t    *******************  ENTER  *******  1  *******  TO ADD STUDENT DATA     *****************");
         printf("\n\t    *******************  ENTER  *******  2  *******  TO SEARCH STUDENT DATA  *****************");
         printf("\n\t    *******************  ENTER  *******  3  *******  TO UPDATE STUDENT DATA  *****************");
         printf("\n\t    *******************  ENTER  *******  4  *******  TO REMOVE STUDENT DATA  *****************");
         printf("\n\t    *******************  ENTER  ** ANY OTHER KEY **  TO QUIT *********************************  :- ");

         //Getting the input of what the user want to do//
         int user_main_input;
         scanf("%d", &user_main_input);

         //If user inputs 1 add new student data//
         if(user_main_input == 1){
              loop_breaker = add_new_student();
         }
         //If user input is 2 search for a file//
         else if(user_main_input == 2){
              loop_breaker = search_for_a_student();
         }
         //If user input is 3 update student data//
         else if(user_main_input == 3){
              loop_breaker = update_student_data();
         }
         //If user input is 4 remove the student's data//
         else if(user_main_input == 4){
              loop_breaker = remove_student_data();
         }
         //If user input any other key break the loop//
         else{
            break;
         }

         //If loop_breaker is 1 break the loop//
         if(loop_breaker == 1){
            break;
         }
    }
    //Print an appropriate ending message//
    printf("\n\n\n\t\t <<<<<<<<<<<<<<<<<<<<<<< THANK YOU FOR USING THIS PROGRAM >>>>>>>>>>>>>>>>>>>>>>>>>\n\n\n");
}







//Function for adding student data to a file//
int add_new_student(){
    printf("\n\n\t\t\t  *=*=*=*=*=*=*=*=*= ADD NEW STUDENT TO SCHOOL *=*=*=*=*=*=*=*=*=*");

    //Get the inputs from the user//
    char index_no[10], full_name[50], gender[2];
    int age, grade, telephone_no;

    printf("\n  ENTER THE INDEX NO :- ");
    scanf("%s", index_no);
    printf("\n  ENTER THE FULL NAME (USE _ FOR SPACES) :- ");
    scanf("%s", full_name);
    printf("\n  ENTER THE GENDER (M/F) :- ");
    scanf("%s", gender);
    printf("\n  ENTER THE AGE :- ");
    scanf("%d", &age);
    printf("\n  ENTER THE GRADE :- ");
    scanf("%d", &grade);
    printf("\n  ENTER THE TELEPHONE NO :- ");
    scanf("%d", &telephone_no);

    //Turn all non-string inputs to strings//
    char str_age[4], str_grade[10], str_telephone_no[15];
    sprintf(str_age,"%d",age);
    sprintf(str_grade,"%d",grade);
    sprintf(str_telephone_no,"%d",telephone_no);

    //When creating the file name it as students indexno//
    char file_name[10];
    strcpy(file_name,index_no);
    strcat(file_name,".txt");

    //Now create the file and insert data//
    FILE* fptr1;
    fptr1 = fopen(file_name,"w");
    fputs("\n  INDEX_NO :- ",fptr1);
    fputs(index_no,fptr1);
    fputs("\n  FULL_NAME :- ",fptr1);
    fputs(full_name,fptr1);
    fputs("\n  GENDER :- ",fptr1);
    fputs(gender,fptr1);
    fputs("\n  AGE :- ",fptr1);
    fputs(str_age,fptr1);
    fputs("\n  GRADE :- ",fptr1);
    fputs(str_grade,fptr1);
    fputs("\n  TELEPHONE_NO :- ",fptr1);
    fputs(str_telephone_no,fptr1);
    fclose(fptr1);

    //Now print an ending sentence//
    printf("\n\n\t  NEW STUDENT ADDED SUCCESSFULLY");

    //Ask user do he want to add another student//
    printf("\n\n\t  ------------- ENTER -------- y ----------- TO ADD ANOTHER STUDENT -------------------");
    printf("\n\t  ------------- ENTER -------- n ----------- TO GO BACK TO MAIN MENU ------------------");
    printf("\n\t  ------------- ENTER --- ANY OTHER KEY ---- TO QUIT ----------------------------------    :- ");

    //Get the user input to a variable//
    char add_another_student[2];
    scanf("%s", add_another_student);

    //If user input is "y" use recursion and run function again, If its "n" continue the main loop, Else break the main loop//
    if(strcmp(add_another_student,"y") == 0){
        return add_new_student();
    }
    else if(strcmp(add_another_student,"n") == 0){
        return 0;
    }
    else{
        return 1;
    }
}




//Function for printing student data that user want//
int search_for_a_student(){
    printf("\n\n\t\t\t\t *=*=*=*=*=*=*=*=*=* SEARCH STUDENT DATA *=*=*=*=*=*=*=*=*=*");

    //Get the input from the user//
    char search_index_no[10];
    printf("\n  ENTER THE INDEX NO OF THE STUDENT :- ");
    scanf("%s", search_index_no);
    strcat(search_index_no,".txt");

    //Now open the file//
    FILE* fptr_open;
    fptr_open = fopen(search_index_no,"r");

    //Print the data in the file//
    if(fptr_open != NULL){
        char details_inside[2000];
        while(fgets(details_inside,2000,fptr_open)){
            printf(" %s",details_inside);
        }
    }
    else{
        printf("  !!!INVALID INDEX NO!!!");
    }
    fclose(fptr_open);

    //Ask user do he wants to search data again//
    printf("\n\n\t  -------------- ENTER -------- y ---------- TO SEARCH AGAIN --------------");
    printf("\n\t  -------------- ENTER -------- n ---------- TO GO BACK TO MAIN MENU ------");
    printf("\n\t  -------------- ENTER --- ANY OTHER KEY --- TO QUIT ----------------------    :-  ");

    //Get the user input//
    char search_student_again[2];
    scanf("%s", search_student_again);

    //If user wants to search again use recursion, If input is "n" continue the main loop, Else break the main loop//
    if(strcmp(search_student_again,"y") == 0){
        return search_for_a_student();
    }
    else if(strcmp(search_student_again,"n") == 0){
        return 0;
    }
    else{
        return 1;
    }
}





//Function for updating student details//
int update_student_data(){
    printf("\n\n\t\t\t  *=*=*=*=*=*=*=*=*=*= UPDATE STUDENT DATA *=*=*=*=*=*=*=*=*=*=*=");

    //Get the index no of the student from the user//
    char update_file_name[10];
    printf("\n  ENTER THE INDEX NO :- ");
    scanf("%s", update_file_name);
    strcat(update_file_name,".txt");

    //Now open the file named as the given index no//
    FILE* fptr_update_1;
    fptr_update_1 = fopen(update_file_name,"r");

    //Look for a file named as given index no//
    if(fptr_update_1 == NULL){
        printf("\n  !!!INVALID INDEX NO!!!");
    }
    else{
        //Now make a struct variable to store data//
        int i = 0;
        struct update{
            char word_1[50];
            char word_2[10];
            char word_3[50];
        }update_array[6];

        //Now get all the data in the file to the variables//
        for(i = 0;i < 6;i++){
            fscanf(fptr_update_1,"%s %s %s",update_array[i].word_1,update_array[i].word_2,update_array[i].word_3);
        }

        //Use a loop to continuously update data//
        char update_user_input[2];
        int do_you_have_to_rename_the_file = 0, not_updated_any_data = 0;
        char new_index_no[10],new_full_name[50],new_age[4],new_grade[10],new_telephone_no[15];
        for(int repeat_update = 0;repeat_update >= 0;repeat_update++){
            //Now ask the user what he's going to update//
            printf("\n\t  ENTER -------- 1 ----------- TO UPDATE INDEX NO -------");
            printf("\n\t  ENTER -------- 2 ----------- TO UPDATE FULL NAME ------");
            printf("\n\t  ENTER -------- 3 ----------- TO UPDATE AGE ------------");
            printf("\n\t  ENTER -------- 4 ----------- TO UPDATE GRADE ----------");
            printf("\n\t  ENTER -------- 5 ----------- TO UPDATE TELEPHONE NO ---");
            printf("\n\t  ENTER --- ANY OTHER KEY ---- TO SAVE ------------------   :-  ");
            scanf("%s", update_user_input);

            //Now update the data//
            if(strcmp(update_user_input,"1") == 0){
                printf("\n  ENTER THE NEW INDEX NO :- ");
                scanf("%s", new_index_no);
                strcpy(update_array[0].word_3,new_index_no);
                do_you_have_to_rename_the_file = 1;
            }
            else if(strcmp(update_user_input,"2") == 0){
                printf("\n  ENTER THE NEW FULL NAME :- ");
                scanf("%s", new_full_name);
                strcpy(update_array[1].word_3,new_full_name);
            }
            else if(strcmp(update_user_input,"3") == 0){
                printf("\n  ENTER THE NEW AGE :- ");
                scanf("%s", new_age);
                strcpy(update_array[3].word_3,new_age);
            }
            else if(strcmp(update_user_input,"4") == 0){
                printf("\n  ENTER THE NEW GRADE :- ");
                scanf("%s", new_grade);
                strcpy(update_array[4].word_3,new_grade);
            }
            else if(strcmp(update_user_input,"5") == 0){
                printf("\n  ENTER THE NEW TELEPHONE NO :- ");
                scanf("%s", new_telephone_no);
                strcpy(update_array[5].word_3,new_telephone_no);
            }
            else{
                if(repeat_update == 0){
                    not_updated_any_data = 1;
                }
                break;
            }
        }

        if(not_updated_any_data == 0){
            //Close the currently data holding file and if their is a new index no rename the file//
            fclose(fptr_update_1);
            if(do_you_have_to_rename_the_file == 1){
                  strcat(new_index_no,".txt");
                  rename(update_file_name,new_index_no);
                  strcpy(update_file_name,new_index_no);
            }

            //Now open the same file in writable mode//
            FILE* fptr_update_2;
            fptr_update_2 = fopen(update_file_name,"w");

            //Now insert all the updated data to the file//
            for(int k = 0;k < 6;k++){
                  fprintf(fptr_update_2,"%s %s %s\n",update_array[k].word_1,update_array[k].word_2,update_array[k].word_3);
            }

            //Now close the file//
            fclose(fptr_update_2);

            printf("\n  DATA UPDATED SUCCESSFULLY");
        }
        else{
            fclose(fptr_update_1);
        }
    }

    //Ask user do he wants to update data again//
    printf("\n\n\t  -------------- ENTER -------- y --- ------- TO UPDATE DATA----------------");
    printf("\n\t  -------------- ENTER -------- n --- ------- TO GO BACK TO MAIN MENU-------");
    printf("\n\t  -------------- ENTER --- ANY OTHER KEY ---- TO QUIT-----------------------   :-  ");

    //Get the user input//
    char update_student_again[2];
    scanf("%s", update_student_again);

    //If user input is "y" use recursion, If its "n" continue the main loop, Else break the main loop//
    if(strcmp(update_student_again,"y") == 0){
        return update_student_data();
    }
    else if(strcmp(update_student_again,"n") == 0){
        return 0;
    }
    else{
        return 1;
    }
}



//Function for removing student data//
int remove_student_data(){
    printf("\n\n\t\t\t   *=*=*=*=*=*=*=*=*=* REMOVE STUDENT DATA *=*=*=*=*=*=*=*=*=*");

    //Get the index no of the student//
    printf("\n  ENTER THE INDEX NO :- ");
    char remove_index_no[10],decision[2];
    scanf("%s", remove_index_no);
    strcat(remove_index_no,".txt");

    //Check for a file named remove_index_no. And if their isn't a file named like that, display invalid index no//
    FILE* remove_fptr;
    remove_fptr = fopen(remove_index_no,"r");
    if(remove_fptr == NULL){
        printf("\n  !!!INVALID INDEX NO!!!");
    }
    else{
        //Now close the file//
        fclose(remove_fptr);

        //Ask him again to make sure he wants to delete the file//
        printf("\n  ARE YOU SURE YOU WANT TO PERMANANTLY DELETE THIS STUDENT'S DATA? (y/n)  :- ");
        scanf("%s", decision);

        //Delete the file if he enters "y", Otherwise do nothing//
        if(strcmp(decision,"y") == 0){
            remove(remove_index_no);
            printf("\n  DATA REMOVED SUCCESSFULLY");
        }
        else{
            printf("\n  DATA NOT REMOVED");
        }
    }

    //Ask user do he want to go back to main menu or do he want to quit//
    printf("\n\n\t  -------------- ENTER -------- n --- ------- TO GO BACK TO MAIN MENU ------");
    printf("\n\t  -------------- ENTER --- ANY OTHER KEY --- TO QUIT -----------------------   :-  ");

    //Get the user input//
    char r_go_back[2];
    scanf("%s",r_go_back);

    //If answer is "n" continue main loop, Else break main loop//
    if(strcmp(r_go_back,"n") == 0){
        return 0;
    }
    else{
        return 1;
    }
}
