#include <stdio.h>
#include "gpa.h"

int main()
{
    double current_cgpa, completed_credits, target_cgpa, remaining_credits;

    printf("Current CGPA: ");
    scanf("%lf", &current_cgpa);
    printf("Completed credits: ");
    scanf("%lf", &completed_credits);
    printf("Target CGPA: ");
    scanf("%lf", &target_cgpa);
    printf("Remaining credits: ");
    scanf("%lf", &remaining_credits);

    printf("Required GPA: %.2f\n",
           calculateRequiredGPA(current_cgpa, completed_credits,
                                target_cgpa, remaining_credits));

    return 0;
}