
#include"main.h"

//using namespace std;

const int CLASS_SIZE = 6;
const int CRADES = 10;

int main(void)
{
	//Use two classes, student and courseEnrollment
	Student studentsInClass[CLASS_SIZE];
	
	CourseEnrollment course1;
	
	//there are 100 students to be enrolled
    static int studentNumber = 1000;
    int grade;
    int userInput;
	
	//asign student id to each student
	for(int i =0 ; i < CLASS_SIZE ; i++)
	{
		studentsInClass[i].SetStudentID(studentNumber);
		studentNumber++
	}
	   //assign grades to all students
	for(int i =0 ; i < CLASS_SIZE ; i++)
	{
		for(int j =0 ; j < CRADES ; j++)
		{
			scanf("%d", &grade);
			studentsInClass[CLASS_SIZE].SetStudentGrade(CRADES , grade);
		}
	}
	
	 //print out all students grades
	for(int i =0 ; i < CLASS_SIZE ; i++)
	{
		studentsInClass[CLASS_SIZE].PrintGrades();
		std::cout<<"\nMin grade = "<<studentsInClass[CLASS_SIZE].GetMinGrade();
		std::cout<<"\nmax grade = "<<studentsInClass[CLASS_SIZE].GetMaxGrade();
		std::cout<<"\nAvg grade = "<<studentsInClass[CLASS_SIZE].GetAvgGrade()<<"\n";
	}
	
	course1.AddStudents(studentsInClass);
	int *AllGrades;
	
	AllGrades = course1.GetAllGrades();
	AllGrades = course1.SortAllGrades();
	
	std::cout<<"Lowest grade for entire course = "<<course1.GetMinGrades()<<"\n";
    std::cout<<"Highest grade for entire course = "<<course1.GetMaxGrades()<<"\n";
    std::cout<<"Avg grade for entire course = "<<course1.GetAvgGrades()<<"\n";
	return 0;
}