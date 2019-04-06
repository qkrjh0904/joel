/*
 * 추상클래스는 인스턴스를 생성할 수 없다.
 * 그러므로 추상클래스는 인스턴스를 생성할 목적으로 만들지 않는다.
 * 따라서 상속받는 서브클래스에서 강제로 오버라이딩하도록 지시하기위해 만든것이다.
 * 서브클래스가 추상클래스가 되지 않기 위해서 추상메소드를 모두 오버라이딩 해야한다.
 */

abstract class Calculator{
	public abstract int add(int a, int b);
	public abstract int subtract(int a, int b);
	public abstract double average(int [] a);
}

class GoodCalc extends Calculator{
	public int add(int a, int b){
		return a+b;
	}
	public int subtract(int a, int b){
		return a-b;
	}
	public double average(int [] a){
		double sum = 0;
		for(int i=0; i<a.length; ++i){
			sum += a[i];
		}
		return sum/a.length;
	}
}
public class AbstractClass {

	public static void main(String[] args) {
		Calculator c = new GoodCalc();
		System.out.println(c.add(2, 3));
		System.out.println(c.subtract(2, 3));
		System.out.println(c.average(new int [] {2,3,4})); 
		

	}

}
