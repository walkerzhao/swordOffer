import java.util.ArrayList;


public class GetLeastNumbersSolution {
	public ArrayList<Integer> GetLeastNumbers_Solution(int [] input, int k) {
        ArrayList<Integer> result = new ArrayList<Integer>();
        int length = input.length;
        if(length < k)
            return result;
        for(int i=0; i<k; ++i) {
            for(int j=i; j<length-1-i; ++j) {
                if(input[j] < input[j+1]) {
                    int temp = input[j];
                    input[j] = input[j+1];
                    input[j+1] = temp;
                }
            }
        }
        for(int i = length-1; i> length-1-k; --i) {
            result.add(input[i]);      
        }
        return result;
         
    }

}
