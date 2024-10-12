#include <stdio.h>

struct Student
{
    char name[30];
    int rollno;
    float marks;
};

void sortRecords(struct Student s[], int n);
int main()
{
    struct Student s[15];
    int records;

    printf("Enter the number of records of students: ");
    scanf("%d", &records);

    for (int i = 0; i < records; i++)
    {
        scanf("%s%d%f", s[i].name, &s[i].rollno, &s[i].marks);
    }

    sortRecords(s, records);
    printf("Sorted list of students by marks: \n");
    for (int i = 0; i < records; i++)
    {
        printf("Rollno: %d  Name : %s,  Marks: %.2f\n",
               s[i].rollno, s[i].name, s[i].marks);
    }
    return 0;
}

void sortRecords(struct Student s[], int n)
{
    struct Student temp;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (s[j].marks < s[j + 1].marks)
            {
                temp = s[j];
                s[j] = s[j + 1];
                s[j + 1] = temp;
            }
        }
    }
}