package GradeBook;

public class GradeBook {
    private String courseName;
    private String courseInstructor;

    public GradeBook( String name, String instructor){
        courseInstructor = instructor;
        courseName = name;
    }

    public void setCourseName(String courseName) {
        this.courseName = courseName;
    }

    public String getCourseName() {
        return courseName;
    }

    public void setCourseInstructor(String courseInstructor) {
        this.courseInstructor = courseInstructor;
    }

    public String getCourseInstructor() {
        return courseInstructor;
    }

    public void displayMessage(){
        System.out.printf("Welcome to the GradeBook for\n%s!\n", getCourseName());
        System.out.printf("This course is taught by %s\n", getCourseInstructor());
    }
}
