
class Point{
	int x, y;
	void set(int x, int y){
		this.x = x;
		this.y = y;
	}
	void showPoint(){
		System.out.println("(" + x + "," + y + ")");
	}
}


public class ColorPoint extends Point{
	String color;
	void setColor(String color){
		this.color = color;
	}
	void showColorPoint(){
		System.out.println(color);
		showPoint();
	}
	public static void main(String[] args) {
		ColorPoint cp = new ColorPoint();
		cp.set(3, 4);
		cp.setColor("red");
		cp.showColorPoint();

	}

}
