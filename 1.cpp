#include <iostream>
#include <string>
#include <vector>

class Person {
public:
    std::string name;
    std::string email;
    std::string phone;

    Person(std::string n, std::string e, std::string p) : name(n), email(e), phone(p) {}
};

class Student : public Person {
public:
    int student_id;
    std::vector<std::string> enrolled_courses;

    Student(std::string n, std::string e, std::string p, int id) : Person(n, e, p), student_id(id) {}

    void registerCourse(std::string course) {
        enrolled_courses.push_back(course);
    }
};

class Instructor : public Person {
public:
    int employee_id;
    std::vector<std::string> teaching_courses;

    Instructor(std::string n, std::string e, std::string ph, int id) : Person(n, e, ph), employee_id(id) {}

    void assignCourse(std::string course) {
        teaching_courses.push_back(course);
    }
};

class Course {
public:
    std::string course_name;
    std::string course_code;
    Instructor* instructor;
    std::vector<Student*> students;

    Course(std::string name, std::string code, Instructor* instr) : course_name(name), course_code(code), instructor(instr) {}
};

class Department {
public:
    std::string name;
    std::vector<Course*> courses;
    std::vector<Instructor*> instructors;

    Department(std::string n) : name(n) {}
};

class University {
public:
    std::vector<Student*> students;
    std::vector<Instructor*> instructors;
    std::vector<Course*> courses;

    void addStudent(Student* student) {
        students.push_back(student);
    }

    void addInstructor(Instructor* instructor) {
        instructors.push_back(instructor);
    }

    void addCourse(Course* course) {
        courses.push_back(course);
    }

    void getCourseInfo() {
        for (Course* course : courses) {
            std::cout << "Course Name: " << course->course_name << ", Course Code: " << course->course_code << std::endl;
        }
    }

    void getStudentInfo() {
        for (Student* student : students) {
            std::cout << "Student Name: " << student->name << ", Student ID: " << student->student_id << std::endl;
        }
    }
};

int main() {
    Instructor* instructor1 = new Instructor("John Doe", "johndoe@example.com", "123456789", 101);
    Student* student1 = new Student("Jane Smith", "janesmith@example.com", "987654321", 201);
    Course* course1 = new Course("Introduction to Programming", "CS101", instructor1);

    Department csDepartment("Computer Science");
    csDepartment.courses.push_back(course1);
    csDepartment.instructors.push_back(instructor1);

    University myUniversity;
    myUniversity.addInstructor(instructor1);
    myUniversity.addStudent(student1);
    myUniversity.addCourse(course1);

    myUniversity.getCourseInfo();
    myUniversity.getStudentInfo();

    delete instructor1;
    delete student1;
    delete course1;

    return 0;
}