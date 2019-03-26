
public class returnArray {
	
	static int[] makeArray(){	// 반환 타입이 int[]
		int temp[] = new int[4];
		for(int i=0; i<temp.length; ++i){
			temp[i] = i;
		}
		return temp;
	}
	
	public static void main(String[] args) {
		int intArray[];
		intArray = makeArray();
		for(int i=0; i<intArray.length; ++i){
			System.out.println(intArray[i]);
		}
	}

}
