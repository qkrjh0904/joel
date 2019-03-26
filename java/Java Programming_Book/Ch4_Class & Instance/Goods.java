
public class Goods {

	String name;
	int price;
	int numberOfStock;
	int sold;
	
	public static void main(String[] args) {
		
		Goods camera = new Goods();	//객체 생성
		
		camera.name = "Samsung";
		camera.price = 500000;
		camera.numberOfStock = 30;
		camera.sold = 50;
		
		System.out.println("상품 이름 : " + camera.name);
		System.out.println("상품 가격 : " + camera.price);
		System.out.println("재고 수량 : " + camera.numberOfStock);
		System.out.println("판매 수량 : " + camera.sold);

	}

}
