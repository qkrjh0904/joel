/*
 * 
 * Class : MyExp
 * 
 * 2019.03.26
 * 
 * Ver 1.0.0
 * 
 * Jeongho Park
 */


public class MyExp {

	int base;
	int exp;
	
	int getValue(){
		int ans = base;
		for(int i=1; i<exp; ++i)
			ans *= base;
		return ans;
	}
	
	public static void main(String[] args) {
		MyExp num1 = new MyExp();	//객체 num1 생성
		num1.base = 2;
		num1.exp = 3;
		
		MyExp num2 = new MyExp();	//객체 num2 생성
		num2.base = 3;
		num2.exp = 2;
		
		System.out.println(num1.base + "의 " + num1.exp + "제곱은 " + num1.getValue() + "이다.");
		System.out.println(num2.base + "의 " + num2.exp + "제곱은 " + num2.getValue() + "이다.");

	}

}

//MyExp라는 붕어빵틀(클래스)에서 num1, num2라는 붕어빵(객체) 2개 생성.