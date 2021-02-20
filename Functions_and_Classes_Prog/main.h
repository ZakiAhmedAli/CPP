
#include<stdio.h>
#include<iostream>

using namespace std;
	
class Student
{
	private:
	int StudentID;
	int Grades[10];
	
    public:
	void SetStudentID(int id);
	void SetStudentGrade(int gradeNumber, int gradeIn);

	int GetStudentID();
	int *GetStudentGrades();
	int GetGrade(int gradeNumber);
    int GetMinGrade();
    int GetMaxGrade();
    int GetAvgGrade();
	void SortGrade();  
	void PrintGrades();

};//end of class

/****** implement class functions************/
void Student::SetStudentID(int id)
{
  StudentID = id;	
}

void Student::SetStudentGrade(int gradeNumber, int gradeIn)
{
	Grades[gradeNumber] = gradeIn;
}

int  Student::GetStudentID()
{
	return StudentID;
}

int* Student::GetStudentGrades()
{
	return Grades;
}

int  Student::GetGrade(int gradeNumber)
{
	return Grades[gradeNumber];
}

void Student::PrintGrades()
{
	for(int Count=0 ;Count< 10 ; Count++)
	{
		std::cout<<"\t"<<Grades[Count]<<"\n";
	}
}

void Student::SortGrade()
{
	int temp;
	for(int Count1 =0 ; Count1<10 ; Count1++)
	{
		for(int Count2=0 ; Count2<9-1 ; Count2++)
		{
			if(Grades[Count2+1] < Grades[Count2])
			{
				temp 			= Grades[Count2];
				Grades[Count2]  = Grades[Count2+1];
				Grades[Count2+1]= temp;
			}
		}
	}
}

int Student::GetMinGrade()
{
	SortGrade();
   
   return Grades[0];
}

int Student::GetMaxGrade()
{
   SortGrade();
   
   return Grades[9];
}

int  Student::GetAvgGrade()
{
	int sum =0 , avg =0 ;
	
	for(int i=0 ; i< 10 ; i++)
	{
		sum +=Grades[i];
	}
	
	avg = sum / 10;
	
	return avg;
}

/**********************************************/
class CourseEnrollment
{
    public:
    Student students[6];
    int courseMinGrade;
    int courseMaxGrade;
    float courseAvgGrade;
    int grades[60];
	
	void AddStudents(Student* studentIn);
	int* GetAllGrades();
	int* SortAllGrades();
	int  GetMinGrades();
	int  GetMaxGrades();
	int  GetAvgGrades();
	void PrintAllGrade();
	
};//end of class

/****** implement class functions************/
void CourseEnrollment::AddStudents(Student* studentIn)
{
	for(int i =0 ;i<6 ;i++)
	{
		studentIn[i] = studentIn[i];
	}		
}

int* CourseEnrollment::GetAllGrades()
{
	int G = 0;
	for(int i=0 ; i<6 ; i++)
	{
		for(int j=0; j<10; j++)
		{
			grades[G] = students[i].GetGrade(j); 
			G = G + 1;
		}
	}
	
	return grades;
}

int* CourseEnrollment::SortAllGrades()
{
	int temp = 0;
	for(int Count1 =0 ; Count1<60 ; Count1++)
	{
		for(int Count2=0 ; Count2<59-1 ; Count2++)
		{
			if(grades[Count2+1] < grades[Count2])
			{
				temp 			= grades[Count2];
				grades[Count2]  = grades[Count2+1];
				grades[Count2+1]= temp;
			}
		}
	}
	
	return grades;
}

int CourseEnrollment::GetMinGrades()
{
	SortAllGrades();
   
	return grades[0];
}

int  CourseEnrollment::GetMaxGrades()
{
	SortAllGrades();
   
	return grades[3];	
}

int CourseEnrollment::GetAvgGrades()
{
	int sum =0 , avg =0;
	for(int Count1 =0 ; Count1<60 ; Count1++)
	{
		sum = sum + grades[Count1];
	}
	avg = sum /60;
	
	return avg;
}

void CourseEnrollment::PrintAllGrade()
{
	for(int i=0;i<60;i++)
    {
        std::cout<<"grade="<<grades[i]<<"\n";
    }
}