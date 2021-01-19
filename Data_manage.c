#include <stdio.h>
#include <stdlib.h>
#include<string.h>

#define MAX 50

enum branch {CSE, EE, ME};

struct course 
{
    char code[MAX];
    char name[MAX];
    int credits;
    int ninstructors;
    char **instructor_ids;
    int nstudents;
    char **student_rollnos;
};

struct student 
{
    char rollno[MAX];
    char name[MAX];
    enum branch branch;
    int semester;
    int ncourses;
    char **courses_codes;
};

struct instructor 
{
    char id[MAX];
    char name[MAX];
    int ncourses;
    char **courses_codes;
};

void print_students();
void print_student(struct student s);
void add_student(struct student s);
void add_new_student();
struct student modify_student(struct student s);

void add_instructors(struct instructor ins);
void print_instructor(struct instructor ins);
void print_instructors();
void add_new_instructor();
struct instructor modify_instructor(struct instructor ins);

void add_course(struct course c);
void print_course(struct course c);
void print_courses();
void add_new_course();
struct course modify_course(struct course c);

void load_records();
void load_students();
void load_instructors();
void load_courses();

void write_records();
void write_students();
void write_instructors();
void write_courses();

struct course *courses;
struct student *students;
struct instructor *instructors;

FILE *fps;
FILE *fpc;
FILE *fpi;


int ncourses = 0, nstudents = 0, ninstructors = 0;


int main() 
{    
    int n,m,check=0;
    struct student s;
    struct course c;
    struct instructor ins;
    char ch;
    printf("\nProgram To manage details...\nCurrently Saved in Records/Files : \n");
    load_records();
    printf("Kindly enter only 1 word for any option \n");    
    printf("\nEnter 1) for Student options");
    printf("\nEnter 2) for Instructor options");
    printf("\nEnter 3) for Course options");
    printf("\nEnter your choice from above :");
    scanf("%d",&n);
    
	switch(n)
    { case 1:
	 {printf("\n1)Display details of all students");
	  printf("\n2)Display detail of student of roll no");
	  printf("\n3)Add details of a new student");
	  printf("\n4)Delete details of student of roll no");
	  printf("\n5)Modify details of Existing student");
 	  printf("\nEnter your choice from above : ");
	   scanf("%d",&m);
	   switch(m)
	   {
		   case 1:
		   {print_students();
		   break;
		    }
		   case 2:
		  {  printf("Enter the roll no :");
		     scanf("%s",s.rollno);
		     for(int i=0;i<nstudents;i++)
		     {if (strcmp(students[i].rollno,s.rollno)==0)
		      {s=students[i];
		        check=1;
		       }
		      }
		     if(check==0)
		     {printf("Can't fint that roll no\n");		      	
		     break;
		      } 
		     else print_student(s);
		     break;
        	    }
		   case 3:
		   { add_new_student();
		     break;
		    }
		   case 4:
		    {printf("Enter the roll no :");
		     scanf("%s",s.rollno);
        	     for(int i=0;i<nstudents;i++)
		       {if (strcmp(students[i].rollno,s.rollno)==0)
		        { int j=i;
			   for( ;j<nstudents-1;j++)
		          students[j]=students[j+1];
			        nstudents--;
		         printf("\nDeletion success \n");
		         check=1;
			 break;
		        }
		       }
		     if(check==0)
		        printf("Can't fint that roll no\n");
					       
			break; 
		    }
		   case 5:
		   {printf("Enter the roll no :");
		    scanf("%s",s.rollno);
		    for(int i=0;i<nstudents;i++)
		     { if (strcmp(students[i].rollno,s.rollno)==0)
		       {students[i]=modify_student(students[i]);
		        check=1;
			printf("Details changed successfully\n"); 
			scanf("%c",ch);
			break;
		        }
        	      }
		   if(check==0)
		     printf("Can't fint that roll no\n");		                    
                     break;      
		   }
		   default :
	  	     printf("Entered choice is not correct\n");  
	            
             }   break;
          }
	case 2:
	 { 	printf("\n1)Display details of all instructors");
	  	printf("\n2)Display detail of instructor of id");
	  	printf("\n3)Add details of a new instructor");
	  	printf("\n4)Delete details of instructor of id");
	  	printf("\n5)Modify details of Existing instructor");
 	  	printf("\nEnter your choice from above : ");
	    scanf("%d",&m);
	    switch(m)
	    {
		   case 1:
		   {print_instructors();
		   break;
		    }
		   case 2:
		   {printf("Enter the id :");
		   scanf("%s",ins.id);
		    for(int i=0;i<ninstructors;i++)
		     {if (strcmp(instructors[i].id,ins.id)==0)
		      {ins=instructors[i];
		        check=1;
		       }
		      }
		   if(check==0)
		   {printf("Can't fint that id\n");
		   break;
		    } 
		   else print_instructor(ins);
		   break;
        	   }
		   case 3:
		   { add_new_instructor();
		     break;
		    }
		   case 4:
		    {printf("Enter the instructor id :");
		     scanf("%s",ins.id);
        	     for(int i=0;i<ninstructors;i++)
		       {if (strcmp(instructors[i].id,ins.id)==0)
		        { int j=i;
			 for( ;j<ninstructors-1;j++)
		          instructors[j]=instructors[j+1];
			  ninstructors--;
		         printf("Deletion success \n");
			     check=1;
			     break;
		        }
		       }
		     if(check==0)
		       printf("Can't fint that instructor id\n");		       
			break;		        
		     }

		   case 5:
		   { printf("Enter the instructor id :");
		     scanf("%s",ins.id);
		     for(int i=0;i<ninstructors;i++)
		      {if (strcmp(instructors[i].id,ins.id)==0)
		       {instructors[i]=modify_instructor(instructors[i]);
		        check=1;
			printf("Details changed successfully\n") ;			
			break;
		        }
        	       }
		  
		     if(check==0)
		     {printf("Can't fint that instructor id\n");
		   
                      }
		    break;
		   }
		    default :
	  	    printf("Entered choice is not correct\n"); 
	          
	    }	
 	  break;  
	}
      case 3:
	{ 	printf("\n1)Display details of all courses");
	  	printf("\n2)Display detail of a course by its code");
	  	printf("\n3)Add details of a new course");
	  	printf("\n4)Delete details of a course by code");
	  	printf("\n5)Modify details of Existing course");
 	  	printf("\nEnter your choice from above : ");
	        scanf("%d",&m);
	    switch(m)
	   {  
		case 1:
		   {print_courses();
		   break;
		    }
		   case 2:
		   { printf("Enter the course code :");
		     scanf("%s",c.code);
		     for(int i=0;i<ncourses;i++)
		      {if (strcmp(courses[i].code,c.code)==0)
		       {print_course(courses[i]);
		        check=1;
		        }
		       }
		     if(check==0)
		     {printf("Can't fint that course code \n");
		      break;
		     } 
		    }
		   case 3:
		   { add_new_course();
		     break;
		    }
		   case 4:
		    {printf("Enter the course code:");
		     scanf("%s",c.code);
        	     for(int i=0;i<ncourses;i++)
		       {if (strcmp(courses[i].code,c.code)==0)
		        { int j=i;
			 for( ;j<ncourses-1;j++)
		          courses[j]=courses[j+1];
			   ncourses--;            
		          printf("Deletion success\n ");
			   check=1;
			   break;
		        }
		       }
		     if(check==0)
		       printf("Can't fint that course code\n");		       
			break;		        
		      }

		   case 5:
		   {  printf("Enter the course code :");
		      scanf("%s",c.code);
		      for(int i=0;i<ncourses;i++)
		      {if (strcmp(courses[i].code,c.code)==0)
		        {courses[i]=modify_course(courses[i]);
		         check=1;
			 printf("Details changed successfully\n"); 
			 break;
		         }
        	       }
		  
		     if(check==0)
		      {printf("Can't fint that course code\n");
		       break;
                       }
		      break;
		   }	
		     default :
	  	     printf("Entered choice is not correct\n"); 
	            
	       } break;
    
	  }
    }
    write_records();
    return 0;
}
void add_student(struct student s) 
{   
    students = realloc (students, (nstudents+1)*sizeof(struct student));
    students[nstudents] = s;
    nstudents++;
     return;
 }
void add_instructor(struct instructor ins) 
{
    instructors = realloc (instructors, (ninstructors+1)*sizeof(struct instructor));
    instructors[ninstructors] = ins;
    ninstructors++;
    return;
 }

void add_course(struct course c) 
{
    courses = realloc (courses, (ncourses+1)*sizeof(struct course));
    courses[ncourses] = c;
    ncourses++;
     return;
 }
void add_new_student()
{   char ch;
    
    struct student s;
    printf("Enter Roll No:");
    scanf("%s",s.rollno);
    scanf("%c",ch); 
    for(int i=0;i<nstudents;i++)
     { if(strcmp(students[i].rollno,s.rollno)==0)
	{printf("FAIL! Roll no already Exists \n");
	  return;
	 }
      }
    printf("Enter Name : ");  
    scanf("%s",s.name);
    printf("Enter Branch 1)CSE 2)EE 3)ME :");
    scanf("%u",&s.branch);
    s.branch-=1;
    printf("Enter Semester No:");
    scanf("%d", &s.semester);
    printf("Enter No of courses :");
    scanf("%d", &s.ncourses);
      s.courses_codes = malloc (s.ncourses * sizeof(char *));
        for (int j=0; j<s.ncourses; j++) 
         {  int check =0;
            s.courses_codes[j] = malloc (MAX * sizeof (char));
	        printf("Enter course %d :",j+1);
            scanf("%s",s.courses_codes[j]);
            for(int k=0;k<ncourses;k++)
            {if(strcmp(courses[k].code,s.courses_codes[j])==0)
              {courses[k].nstudents+=1;
                courses[k].student_rollnos = realloc(courses[k].student_rollnos, 
                                          courses[k].nstudents * sizeof(char *));
                if((courses[k].student_rollnos)==NULL)
                {printf("\nERROR Memory didnt reallocate \n");
                  return;
		 }               
                courses[k].student_rollnos[courses[k].nstudents-1] = 
                                             malloc (MAX * sizeof (char)); 
                printf("\t entering this rollno in this course \n");                       
 	        strcpy(courses[k].student_rollnos[courses[k].nstudents-1],s.rollno);
 			   check=1;
 	       }        
             } 
             if(check==0)
             {struct course c;
              strcpy(c.code,s.courses_codes[j]);
              strcpy(c.name,"DEFAULT");
              c.credits=1;
              c.ninstructors=1;
              c.instructor_ids = malloc(c.ninstructors * sizeof(char *));
              c.instructor_ids[0] = malloc (MAX * sizeof (char));
              strcpy(c.instructor_ids[0],"DEFAULT_ins");
              c.nstudents=1;
              c.student_rollnos = malloc(c.nstudents * sizeof(char *));
              c.student_rollnos[0] = malloc (MAX * sizeof (char));
              strcpy(c.student_rollnos[0],s.rollno);
              printf("\tThis new course code added in courses With DEFAULT values\n");
              add_course(c);
             }
         }
     add_student(s);
     return;
}
void add_new_instructor()
{       struct instructor ins;
	
	printf("Enter Instructor id:");
        scanf("%s",ins.id);
        for(int i=0;i<ninstructors;i++)
        { if(strcmp(instructors[i].id,ins.id)==0)
 	   {printf("FAIL! ID already Exists \n");
	    return;
	    }
         }
        printf("Enter Name :");
        scanf("%s",ins.name);
	printf("Enter number of courses: ");
	scanf("%d",&ins.ncourses);
	ins.courses_codes = malloc (ins.ncourses * sizeof(char *));
	printf("Enter the course codes :\n");
	for (int i=0; i<ins.ncourses; i++) 
         { printf("Enter course code %d) ",i+1);
           ins.courses_codes[i] = malloc (MAX * sizeof (char));
           scanf("%s", ins.courses_codes[i]);
	   int check=0;
	   for(int k=0;k<ncourses;k++)  //To check and add instructor id in course 
	   { if(strcmp(courses[k].code,ins.courses_codes[i])==0)
		  { 
			for(int l=0;l<courses[k].ninstructors;l++)
		             {if(strcmp(courses[k].instructor_ids[l],ins.id)==0)
		              check=2;
		              }
		  if(check!=2) 
		 { courses[k].ninstructors +=1;
		   courses[k].instructor_ids = realloc(courses[k].instructor_ids,
			                   courses[k].ninstructors * sizeof(char *));
		  if((courses[k].instructor_ids)==NULL)
      {printf("\nERROR Memory didnt reallocate \n");
           return;
		   }               
                courses[k].instructor_ids[courses[k].ninstructors-1] = 
                                             malloc (MAX * sizeof (char)); 
                printf("\tThis instructor id entered in this course \n");                       
 	              strcpy(courses[k].instructor_ids[courses[k].ninstructors-1],ins.id);
		        check=1;
	         }
	    }    
		}
		if(check==0)  //To create new course if its not present
		 { struct course c;
                   strcpy(c.code,ins.courses_codes[i]);
                   strcpy(c.name,"DEFAULT");
                   c.credits=1;
                   c.ninstructors=1;
                   c.instructor_ids = malloc(c.ninstructors * sizeof(char *));
                   c.instructor_ids[0] = malloc (MAX * sizeof (char));
                   strcpy(c.instructor_ids[0],ins.id);
                   c.nstudents=1;
                   c.student_rollnos = malloc(c.nstudents * sizeof(char *));
                   c.student_rollnos[0] = malloc (MAX * sizeof (char));
                   strcpy(c.student_rollnos[0],"DEFAULT_s");
                   printf("\tThis new course code added in courses With DEFAULT values\n");
                   add_course(c);
		  }
		 	
          }
	add_instructor(ins);
	 return;
 }
void add_new_course()
{	struct course c;
	printf("Enter course code");
	scanf(" %s", c.code);
	for(int i=0;i<ncourses;i++)
	 { if(strcmp(courses[i].code,c.code)==0)
	    {printf("FAIL!that course code exists");
	     return;
	     }
	  }
        printf("Enter Name of course : ");
	scanf("%s",c.name);
        printf("Enter total Credits of course : ");
	scanf("%d",&c.credits);
        printf("Enter number of instructors for that course :");
	scanf("%d",&c.ninstructors);
	c.instructor_ids = malloc(c.ninstructors * sizeof(char *));
	printf("Enter the ID /s of the instructors\n");
         for (int i=0; i<c.ninstructors; i++) 
         {printf("instructor %d) ID ",i+1);
          c.instructor_ids[i] = malloc (MAX * sizeof (char));
           scanf("%s", c.instructor_ids[i]);
	          int check=0;
	          for(int k=0;k<ninstructors;k++) //To check if this course code is present for this instructor
	            { if(strcmp(c.instructor_ids[i],instructors[k].id)==0)
		           { 
		            for(int l=0;l<instructors[k].ncourses;l++)
		             {if(strcmp(instructors[k].courses_codes[l],c.code)==0)
		              check=2;
		              }
		            if(check!=2) 
		            {instructors[k].ncourses +=1;
		             instructors[k].courses_codes = realloc(instructors[k].courses_codes,
					                                  instructors[k].ncourses * sizeof(char *));
		             if((instructors[k].courses_codes)==NULL)
                   {printf("\nERROR Memory didnt reallocate \n");
                     return;
		                }     
		             instructors[k].courses_codes[instructors[k].ncourses-1] =
					                                    malloc (MAX * sizeof (char));
		           printf("\tThis course code entered for this instructor \n");                       
 	             strcpy(instructors[k].courses_codes[instructors[k].ncourses-1],c.code);
		            check=1;
		            }
	            }
	           }
	            if (check==0)
		          { struct instructor ins;
		            strcpy(ins.id,c.instructor_ids[i]);
		            strcpy(ins.name,"DEFAULT_ins");
		            ins.ncourses=1;
		            ins.courses_codes = malloc (ins.ncourses * sizeof(char *));
		            ins.courses_codes[0] = malloc (MAX * sizeof (char));
		            strcpy(ins.courses_codes[0],c.code);
		            printf("\tThis new Instructor added  With DEFAULT values\n");
		            add_instructor(ins);
		           } 
 	   
            }
        printf("Enter of number students in course :");
	   scanf("%d",&c.nstudents);
	   c.student_rollnos = malloc(c.nstudents * sizeof(char *));
	   printf("Enter the roll no of students\n");
        for (int i=0; i<c.nstudents; i++) 
         { printf("Enter rollno of student %d) ",i+1);
           c.student_rollnos[i] = malloc (MAX * sizeof (char));
           scanf("%s", c.student_rollnos[i]);
	   int check=0;
	   for(int k=0;k<nstudents;k++)    //To check if that student has this course
	   { if(strcmp(c.student_rollnos[i],students[k].rollno)==0)
		  {for(int l=0;l<students[k].ncourses;l++)
		   {if(strcmp(students[k].courses_codes[l],c.code)==0)
		    check=2;
		    }
		   if(check!=2)
		   {students[k].ncourses +=1;
		     students[k].courses_codes = realloc(students[k].courses_codes,
					                       students[k].ncourses * sizeof(char *));
		     if((students[k].courses_codes)==NULL)
                {printf("\nERROR Memory didnt reallocate \n");
                  return;
		              }     
		      students[k].courses_codes[students[k].ncourses-1] =
					                       malloc (MAX * sizeof (char));
		       printf("\tThis course added for this roll no \n");                       
 	         strcpy(students[k].courses_codes[students[k].ncourses-1],c.code);
		       check=1;
	         }
	      }
	     } 
	     if (check==0)
		{ struct student s;
		  strcpy(s.rollno,c.student_rollnos[i]);
		  strcpy(s.name,"DEFAULT_s");
		  s.branch=0;
		  s.ncourses=1;
		  s.courses_codes = malloc (s.ncourses * sizeof(char *));
		  s.courses_codes[0] = malloc (MAX * sizeof (char));
		  strcpy(s.courses_codes[0],c.code);
		  printf("\tThis new Student added  With DEFAULT values\n");
		  add_student(s);
		 } 
 	   
            }
	   
          
	add_course(c);
         return;
}

void print_students()
{
    printf("Student's details\n--------------------\n");
    for (int i=0; i<nstudents; i++) 
    {
        print_student(students[i]);
    }
     return;
 }

void print_instructors()
{
    printf("Instructor's details\n---------------------\n");
    for (int i=0; i<ninstructors; i++) 
    {
        print_instructor(instructors[i]);
    }
     return;
 }

void print_courses()
{
    printf("Course's details\n------------------------\n");
    for (int i=0; i<ncourses; i++) 
    {
        print_course(courses[i]);
    }
     return;
 }
void print_student(struct student s) 
{
    printf("Roll no.: %s\t\t", s.rollno);
    printf("Name: %s\n", s.name);
    printf("Branch: ");
    if (s.branch==0)
    printf(" C S");
    else if (s.branch==1)
    printf(" E E");
    else if(s.branch==2)
    printf(" M E");
    printf("\t\tSemester: %d\n", s.semester);
    printf("List of courses:\n");
    for (int i=0; i<s.ncourses; i++) 
   {
        printf("%d) %s\t",i+1, s.courses_codes[i]);
    }
    printf("\n\n");
     return;
}

void print_instructor(struct instructor ins) 
{
    printf("ID : %s\t\t\t", ins.id);
    printf("Name : %s\t", ins.name);
    printf("\nList of courses:\n");
    for (int i=0; i<ins.ncourses; i++) 
   {
        printf("%d) %s\t",i+1, ins.courses_codes[i]);
    }
    printf("\n\n");
     return;
}

void print_course(struct course c) 
{
    printf("Course code.: %s\t\t", c.code);
    printf("Name: %s", c.name);
    printf("\nCredits: %d\n", c.credits);
    printf("List of instructors: \n");
    for (int i=0; i<c.ninstructors; i++) 
   {
        printf("%d) %s\t",i+1, c.instructor_ids[i]);
    }
    printf("\nList of students:\n");
    for (int i=0; i<c.nstudents; i++) 
   {
        printf("%d) %s\t",i+1, c.student_rollnos[i]);
    }
    printf("\n\n");
     return;
}
struct student modify_student(struct student s)
{   char str[MAX];
    printf("Enter the detail You wish to change/modify : ");
    printf("\nie name OR branch OR semester OR courses : ");
    scanf("%s",str);
    if(strcmp(str,"name")==0)
    { printf("Enter New Name :");
      scanf("%s",s.name);
     }
    else if (strcmp(str,"branch")==0)
    { printf("Enter New Branch 1)CSE 2)EE 3)ME :");
      scanf("%u",&s.branch);
    }
    else if (strcmp(str,"semester")==0)
    {printf("Enter New Semester :");
     scanf("%d", &s.semester);
    }
    else if (strcmp(str,"courses")==0)
    {printf("Enter Changed No of courses :");
     scanf("%d", &s.ncourses);

     s.courses_codes = malloc (s.ncourses * sizeof(char *));
        for (int j=0; j<s.ncourses; j++) 
         {
            s.courses_codes[j] = malloc (MAX * sizeof (char));
	    printf("Enter course code %d",j+1," :");
            scanf("%s", s.courses_codes[j]);
         }	
      }	
	
	 return(s);
}
struct instructor modify_instructor(struct instructor ins )
{	char str[MAX];
	printf("Enter the detail to changed/modified : ");
	printf("\nie name OR courses : ");
	scanf("%s",str); 
	if(strcmp(str,"name")==0)      
	{ printf("Enter New Name :");
          scanf("%s",ins.name);
          }
        else if (strcmp(str,"courses")==0)
	{printf("Enter new number of courses");
	 scanf("%d",&ins.ncourses);
	 ins.courses_codes = malloc (ins.ncourses * sizeof(char *));
	 printf("Enter the courses :\n");
	 for (int i=0; i<ins.ncourses; i++) 
         { printf("Enter course %d) code",i+1);
	   ins.courses_codes[i] = malloc (MAX * sizeof (char));
           scanf("%s", ins.courses_codes[i]);
          }
	}
	  return(ins);
}
struct course modify_course(struct course c)
{	char str[MAX];
	printf("Enter the detail to be changed/modified");
	printf("\nie name OR credits OR instructors OR students : ");
	scanf("%s",str);
	if(strcmp(str,"name")==0)
	{printf("Enter New Name of course : ");
	 scanf("%s",c.name);
         }
        else if(strcmp(str,"credits")==0)
        {printf("Enter total Credits of course : ");
	 scanf("%d",&c.credits);
         }
         else if(strcmp(str,"instructors")==0)
        {printf("Enter new number of instructors for that course :");
	 scanf("%d",&c.ninstructors);
	 c.instructor_ids = malloc(c.ninstructors * sizeof(char *));
	 printf("Enter the id of the instructors :\n");
         for (int i=0; i<c.ninstructors; i++) 
         {printf("Enter instructor %d) ID :",i+1);
	  c.instructor_ids[i] = malloc (MAX * sizeof (char));
          scanf("%s", c.instructor_ids[i]);
          }
         }
         else if (strcmp(str,"students")==0) 
         {printf("Enter of new number students in course :");
	  scanf("%d",&c.nstudents);
	  c.student_rollnos = malloc(c.nstudents * sizeof(char *));
	    printf("Enter the roll no of students\n");
          for (int i=0; i<c.nstudents; i++) 
          {printf("Enter  student %d) rollno :",i+1);
	   c.student_rollnos[i] = malloc (MAX * sizeof (char));
           scanf("%s", c.student_rollnos[i]);
           }
	  }  return(c);
}
void load_records() 
{
    load_students();
    load_instructors();
    load_courses();

 }

void write_records()
{
	write_students();
	write_instructors();
	write_courses();
}

void load_students() 
{
    fps = fopen("students.txt", "r");
    int nstudents;
    char ch;
    char buff[MAX];
    struct student s;
    fscanf(fps, "%d", &nstudents);
    printf("Total students in Record :%d\n",nstudents);
    for (int i=0; i<nstudents; i++)
  {
        
	    fscanf(fps, "%s", s.rollno );
	    fscanf(fps, "%s", s.name );
	    label :
	    ch=fgetc(fps);	    
	    ch=fgetc(fps);	    	    
	    if(ch<'0'||ch>'9')
	    { fseek(fps, -2, SEEK_CUR );
	      fscanf(fps, "%s" ,buff);
	      strcat(s.name,"_");
		    strcat(s.name,buff);
	        goto label ;
	     }
	    else if(ch>='0'||ch<='9')
	    fseek( fps, -2, SEEK_CUR );
           
        fscanf(fps, "%u", &s.branch);
        fscanf(fps, "%d", &s.semester);
        fscanf(fps, "%d", &s.ncourses);
        s.courses_codes = malloc (s.ncourses * sizeof(char *));
        for (int j=0; j<s.ncourses; j++) 
         {
            s.courses_codes[j] = malloc (MAX * sizeof (char));
	    fscanf(fps, "%s", s.courses_codes[j] );
            ch=fgetc(fps);
        }ch=fgetc(fps);
        add_student(s);
    } fclose(fps);
	return;
}
void load_instructors()
{	char ch;
	fpi = fopen("instructors.txt","r");
	int ninstructors;
	char buff[MAX];
	struct instructor ins;
	fscanf(fpi,"%d",&ninstructors);
	printf("Total instructors in Record :%d\n",ninstructors);
	for (int i=0; i<ninstructors; i++)
     {    
	  ch=fgetc(fpi);
          fscanf(fpi, "%s", ins.id);
          fscanf(fpi, "%s", ins.name);
             label :
	            ch=fgetc(fpi);	    
	           ch=fgetc(fpi);	    	    
	           if(ch<'0'||ch>'9')
	   			 { fseek(fpi, -2, SEEK_CUR );
	     			 fscanf(fpi, "%s" ,buff);
	       		 strcat(ins.name,"_");
		   			 strcat(ins.name,buff);
	       		 goto label ;
	          }
	          else if(ch>='0'||ch<='9')
	          fseek( fpi, -2, SEEK_CUR );
          fscanf(fpi, "%d", &ins.ncourses);
          ins.courses_codes = malloc (ins.ncourses * sizeof(char *));
          for (int j=0; j<ins.ncourses; j++) 
          {
            ins.courses_codes[j] = malloc (MAX * sizeof (char));
            fscanf(fpi, "%s", ins.courses_codes[j]);
	    ch=fgetc(fpi);
           }
          add_instructor(ins);
      } fclose(fpi);
           
}
void load_courses()
{
	fpc = fopen("courses.txt","r");
	int ncourses;
	char ch;
	char buff[MAX];
	fscanf(fpc,"%d",&ncourses);
	printf("Total courses in Record :%d\n",ncourses);
	for(int i=0;i<ncourses;i++)
	{   
	    ch=fgetc(fpc);
	    struct course c;
	    fscanf(fpc, "%s" ,c.code);
	    fscanf(fpc, "%s" ,c.name);
	    label :
	    ch=fgetc(fpc);	    
	    ch=fgetc(fpc);	    	    
	    if(ch<'0'||ch>'9')
	    { fseek(fpc, -2, SEEK_CUR );
	      fscanf(fpc, "%s" ,buff);
	      strcat(c.name,"_");
		    strcat(c.name,buff);
	        goto label ;
	     }
	    else if(ch>='0'||ch<='9')
	    fseek( fpc, -2, SEEK_CUR );
            fscanf(fpc, "%d" ,&c.credits);
	    fscanf(fpc, "%d" ,&c.ninstructors);
	    c.instructor_ids = malloc(c.ninstructors * sizeof(char *));
	    for (int j=0; j<c.ninstructors; j++) 
          {
            c.instructor_ids[j] = malloc (MAX * sizeof (char));
            fscanf(fpc, "%s", c.instructor_ids[j]);
	    ch=fgetc(fpc);
           }

	    fscanf(fpc, "%d" ,&c.nstudents);
	    c.student_rollnos = malloc(c.nstudents * sizeof(char *));
	     for (int j=0; j<c.nstudents; j++) 
          {
            c.student_rollnos[j] = malloc (MAX * sizeof (char));
            fscanf(fpc, "%s", c.student_rollnos[j]);
	    ch=fgetc(fpc);
           }
	   add_course(c);
	  
	 }   fclose(fpc);
}

void write_students()
{    fps = fopen("students.txt", "w");
     fprintf(fps,"%d\n\n\n",nstudents);
     for (int i=0; i<nstudents; i++)
  {
	   fprintf(fps, "%s\n", students[i].rollno);
	   fprintf(fps, "%s\n", students[i].name);
	   
        fprintf(fps, "%u\n", students[i].branch);
        fprintf(fps, "%d\n", students[i].semester);
        fprintf(fps, "%d\n", students[i].ncourses);
        for (int j=0; j<students[i].ncourses; j++) 
         {
            fputs(students[i].courses_codes[j] , fps);
	    fputc('\t',fps);
        }
	fputc('\n',fps);
	fputc('\n',fps);
    }	
    fclose(fps);
	
}
void write_instructors()
{      fpi = fopen("instructors.txt","w");
	
	fprintf(fpi,"%d\n\n\n",ninstructors);
	for (int i=0; i<ninstructors; i++)
     {
          fprintf(fpi, "%s\n", instructors[i].id);
          fprintf(fpi, "%s\n", instructors[i].name);
          fprintf(fpi, "%d\n", instructors[i].ncourses);

          for (int j=0; j<instructors[i].ncourses; j++) 
           fprintf(fpi, "%s\t", instructors[i].courses_codes[j]);
	 fputc('\n',fpi);
	 fputc('\n',fpi);
      }  
	fclose(fpi);
}
void write_courses()
{ 
	fpc = fopen("courses.txt","w");
	fprintf(fpc,"%d\n\n\n",ncourses);
	for(int i=0;i<ncourses;i++)
	{   fprintf(fpc,"%s\n",courses[i].code);
	    fprintf(fpc,"%s\n",courses[i].name);
	    fprintf(fpc,"%d\n",courses[i].credits);
	    fprintf(fpc, "%d\n" ,courses[i].ninstructors);

	    for (int j=0; j<courses[i].ninstructors; j++) 
             fprintf(fpc, "%s\t", courses[i].instructor_ids[j]);
	     fputc('\n', fpc); 
	     fprintf(fpc, "%d\n" ,courses[i].nstudents);

	    for (int j=0; j<courses[i].nstudents; j++) 
             fprintf(fpc, "%s\t", courses[i].student_rollnos[j]);
	     fputc('\n',fpc);
	     fputc('\n',fpc);
	}
	  
	   fclose(fpc);
}


