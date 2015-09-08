
public class MoreThanHalfNumSolution {
	public int MoreThanHalfNum_Solution(int [] array) {
        if(array.length == 0)
            return 0;
        int result = array[0];
        int count = 1;
        for(int i=1; i< array.length; ++i) {
            if(result == array[i])
                ++count;
            else {
                --count;
                if(count == 0) {
                    result = array[i];
                    count = 1;
                }
            }
        }
        //这个数字不一定超过数组的一半，再遍历一次，统计次数就知道结果了
        int times = 0;
        for(int i=0; i < array.length; ++i) {
            if(array[i] == result)
                ++times;
        }
        if(times >= array.length/2)
            return result;
        else
            return 0;
         
    }

}
