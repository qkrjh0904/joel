class Person{
	String phone;
	
	public void setPhone(String phone){
		this.phone = phone;
	}
	
	public String getPhone(){
		return phone;
	}
}

class Professor extends Person{
	public String getPhone(){	//Person의 getPhone을 overriding
		return "Professor : " + super.getPhone();
	}
}
public class MethodOverriding {

	public static void main(String[] args) {
		Professor a = new Professor();
		a.setPhone("010-1234-5678");
		System.out.println(a.getPhone());
		
		Person p = a;
		System.out.println(p.getPhone());	//동적바인딩에 의해 Professor의 getPhone 호출

	}

}
