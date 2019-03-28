
public class Book {
	String title;
	String author;
	int ISBN;
	
	public Book(String title, String author, int ISBN){//생성자
		this.title = title;
		this.author = author;
		this.ISBN = ISBN;
		System.out.println("인자 3개인 생성자 호출");
	}
	
	public Book(String title, int ISBN){
		this(title, "Anonymous", ISBN);
		System.out.println("인자 2개인 생성자 호출\n");
	}
	
	public Book(){
		this(null, null, 0);
		System.out.println("디폴트 생성자 호출\n");
	}
	
	public static void main(String[] args) {
		Book book = new Book("Java JDK", "황기태", 3333);//객체 생성, 생성자 호출
		Book holyBible = new Book("Holy Bible", 1);
		Book emptyBook = new Book();
		
	}

}
