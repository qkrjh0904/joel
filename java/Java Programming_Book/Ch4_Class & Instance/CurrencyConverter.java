class StaticMember{
	private static double rate;
	
	public static double toDollar(double won){
		return won/rate;
	}
	public static double toKWR(double dollar){
		return dollar*rate;
	}
	public static void setRate(double r){
		rate = r;
	}
	
}



public class CurrencyConverter {

	public static void main(String[] args) {
		StaticMember.setRate(1137.5);
		System.out.println("백만원은 " + Math.round(StaticMember.toDollar(1000000)) + "달러 입니다.");
		System.out.println("백달러는 " + Math.round(StaticMember.toKWR(100)) + "원 입니다.");
	}

}
