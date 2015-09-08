
public class FindSolution {
	public boolean Find(int [][] array,int target) {
        boolean found = false;
        int rows = array.length;
        int columns = array[0].length;
         
        if(rows > 0 && columns > 0) {
            int row = 0;
            int column = columns - 1;
            while(row < rows && column >= 0) {
                if(array[row][column] == target) {
                    found = true;
                    break;
                     
                }
                else if(array[row][column] > target)
                    --column;
                else
                    ++row;
            }
        }
        return found;
 
 
    }

}
