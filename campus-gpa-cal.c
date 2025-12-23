#include <stdio.h>
#include <string.h>


float getGradePoint(char grade[]) {
    if (strcmp(grade, "A+") == 0 || strcmp(grade, "A") == 0) return 4.0;
    if (strcmp(grade, "A-") == 0) return 3.7;
    if (strcmp(grade, "B+") == 0) return 3.3;
    if (strcmp(grade, "B") == 0) return 3.0;
    if (strcmp(grade, "B-") == 0) return 2.7;
    if (strcmp(grade, "C+") == 0) return 2.3;
    if (strcmp(grade, "C") == 0) return 2.0;
    if (strcmp(grade, "C-") == 0) return 1.7;
    if (strcmp(grade, "D") == 0) return 1.0;
    return 0.0; 
}

int main() {
    int numModules;
    char moduleName[50], grade[5];
    float credits, totalPoints = 0, totalCredits = 0, semesterGPA;

    printf("--- Campus GPA Calculator ---\n\n");
    printf("Enter number of modules: ");
    scanf("%d", &numModules);

    for (int i = 0; i < numModules; i++) {
        printf("\nModule %d details:\n", i + 1);
        printf("Module Name: ");
        scanf("%s", moduleName);
        printf("Credits: ");
        scanf("%f", &credits);
        printf("Grade (e.g. A+, B, C-): ");
        scanf("%s", grade);

        float gp = getGradePoint(grade);
        totalPoints += (gp * credits);
        totalCredits += credits;
    }

    if (totalCredits > 0) {
        semesterGPA = totalPoints / totalCredits;
        
        printf("\n==============================");
        printf("\nTotal Credits Earned: %.1f", totalCredits);
        printf("\nYour Semester GPA: %.3f", semesterGPA);

        // Dean's List Check
        if (semesterGPA >= 3.8) {
            printf("\nCongratulations! You are on the Dean's List.");
        }

        // Class Determinatin
        printf("\nClass Status: ");
        if (semesterGPA >= 3.70) printf("First Class");
        else if (semesterGPA >= 3.30) printf("Second Class Upper Division");
        else if (semesterGPA >= 3.00) printf("Second Class Lower Division");
        else if (semesterGPA >= 2.00) printf("General Pass");
        else printf("Fail");
        printf("\n==============================\n");
    }

    return 0;
}