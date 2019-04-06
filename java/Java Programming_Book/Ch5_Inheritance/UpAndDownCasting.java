class Person{
	String name;
	String id;
	
	public Person(String name){
		this.name = name;
	}
}

class Student extends Person{
	String grade;
	
	public Student(String name){
		super(name);
	}
}
public class UpAndDownCasting {

	public static void main(String[] args) {
		Person p;
		Student s = new Student("박정호");
		s.id = "qkrjh0904";
		s.grade = "100";
		p = s;
		Student s2 = (Student)p;
		
		System.out.println(p.name);
		System.out.println(p.id + "\n");
//		System.out.println(p.grade);	//업캐스팅으로 인해 Person class의 멤버만 접근 가능
		
		System.out.println(s.name);
		System.out.println(s.id);
		System.out.println(s.grade + "\n");
		
		System.out.println(s2.name);
		System.out.println(s2.id);
		System.out.println(s2.grade + "\n");
	}

}
