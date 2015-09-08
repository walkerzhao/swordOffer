
public class FibonacciSolution {
	
	public int Fibonacci(int n) {
        if(n == 0) return 0;
        if(n == 1) return 1;
        int fibMinusOne = 0;
        int fibMinusTwo = 1;
        int fibN = 0;
        for(int i = 2; i <= n; ++i) {
            fibN = fibMinusOne + fibMinusTwo;
             
            fibMinusOne = fibMinusTwo;
            fibMinusTwo = fibN;
             
        }
        return fibN;
 
 
    }

}
