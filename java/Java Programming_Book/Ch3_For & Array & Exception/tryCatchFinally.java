/*
 * try - catch - finally
 * 
 * 2019. 03. 06
 * 
 * Ver 1.0.0
 * 
 * Jeongho Park
 */


/*
 * try{
 * 		예외가 발생할 가능성이 있는 실행문
 * }
 * catch{
 * 		예외 처리문
 * }
 * finally{
 * 		예외 발생 여부와 상관 없이 무조건 실행되는 문장(생략 가능)
 * }
 * 
 * 
 * Exception 종류(세가지 정도만)
 * 1. ArithmeticException : 정수를 0으로 나눌때 발생
 * 2. NullPointerException : null 레퍼런스를 참조할 때 발생
 * 3. ArrayIndexOutOfBoundsException : 배열의 범위를 벗어난 접근 시 발생
 */

package tryCatchFinally;

import java.util.Scanner;

public class tryCatchFinally {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int divisor;
		int dividend;
		
		System.out.println("input the divisor : ");
		divisor = in.nextInt();
		System.out.println("input the dividend : ");
		dividend = in.nextInt();
		
		try{
			System.out.println(divisor + " / " + dividend + " = " + divisor/dividend);
		}catch(ArithmeticException e){
			System.out.println("0으로 나눌 수 없습니다.");
		}

	}

}
