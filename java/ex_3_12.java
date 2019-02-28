
public class ex_3_12 {
	
	static int[] makeArray(){
		int temp[] = new int[4];
		for(int i=0; i<temp.length; ++i)
			temp[i] = i;
		return temp;
	}

	public static void main(String[] args) {		
		int a[];
		a = makeArray();
		
		for(int i=0; i<a.length; ++i)
			System.out.println(a[i]);
	}

}
