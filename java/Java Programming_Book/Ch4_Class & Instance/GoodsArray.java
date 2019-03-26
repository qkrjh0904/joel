import java.util.Scanner;

class Goods {

	String name;
	int price;
	int numberOfStock;
	int sold;
	
	Goods(String n, int p, int nOS, int s){
		this.name = n;
		this.price = p;
		this.numberOfStock = nOS;
		this.sold = s;
	}
	
	String getName(){ return name; }
	int getPrice(){ return price; }
	int getNumberOfStock(){ return numberOfStock; }
	int getSold(){ return sold; }

}

public class GoodsArray {

	public static void main(String[] args) {
		Goods goods [] = new Goods[3];
		
		Scanner in = new Scanner(System.in);
		for(int i=0; i<goods.length; ++i){
			String name = in.next();
			int price = in.nextInt();
			int numberOfStock = in.nextInt();
			int sold = in.nextInt();
			goods[i] = new Goods(name, price, numberOfStock, sold);
		}
		
		for(int i=0; i<goods.length; ++i){
			System.out.println("상품 이름 : " + goods[i].getName());
			System.out.println("상품 가격 : " + goods[i].getPrice());
			System.out.println("재고 수량 : " + goods[i].getNumberOfStock());
			System.out.println("판매 수량 : " + goods[i].getSold());
			System.out.println();
		}

	}

}
