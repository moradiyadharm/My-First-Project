#include <stdio.h>

void main() {
    int max_students = 100;  
    int num_students = 0;
    int num_days, choice;
    float percentage;
    int eno[max_students]; 
    char names[max_students][50]; 
    int attendance[max_students]; 


    for (int i = 0; i < max_students; i++) {
        attendance[i] = 0;
    }

    printf("Enter the number of days: ");
    scanf("%d", &num_days);

    do {
        printf("\nMenu:\n");
        printf("1. Input New Student Names with Enrollment No. and Attendance\n");
        printf("2. Generate Attendance Report\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the number of new students to add: ");
                int new_students;
                scanf("%d", &new_students);

                if(num_students + new_students > max_students) {
                    printf("Cannot add more students. Maximum capacity reached.\n");
                } else {
                    for (int i = num_students; i < num_students + new_students; i++) {
                        printf("Enter the name of student %d: ", i + 1);
                        scanf(" %[^\n]s", names[i]);
                        printf("Enter enrollment number for %s: ", names[i]);
                        scanf("%d", &eno[i]);

                        printf("Enter attendance for %s (P for Present, A for Absent):\n", names[i]);
                        for (int j = 0; j < num_days; j++) {
                            char day;
                            printf("Day %d: ", j + 1); 
                            scanf(" %c", &day);
                            if (day == 'P' || day == 'p') {
                                attendance[i]++;
                            }
                           
                        }
                        
                    }
                    num_students += new_students; }
                
                break;

            case 2:
                printf("\nAttendance Report:\n");
                for (int i = 0; i < num_students; i++) {
                    percentage = (float)attendance[i] / num_days * 100;
                    printf("%s's (%d) attendance: %.2f%%\n", names[i], eno[i], percentage);
                    if (percentage >= 75)
                        printf("%s is eligible for exam\n", names[i]);
                    else
                        printf("%s is not eligible for exam\n", names[i]);
                }
                break;

            case 3:
                printf("Exiting program.\n");
                break;

            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 3);
}