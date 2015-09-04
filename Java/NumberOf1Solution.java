//求一个数字中1的个数

//当输入是0x80000000的时候，会陷入死循环
//public class Solution {
//public int NumberOf1(int n) {
//    int count =0;
//    while(n != 0) {
//        if((n & 1) == 1)
//            ++count;
//        n = n >> 1;
//    }
//    return count;
//  }
//}

//转换思路，让每位都和1相与，判断结果，需要判断32次
//public class Solution {
//public int NumberOf1(int n) {
//    int flag = 1;
//    int count =0;
//    while(flag != 0 ) {
//       
//        if((n & flag) != 0)
//            ++count;
//        flag = flag << 1;
//    }
//    return count;
//  }
//}

//转换思路，只需要判断1的个数那么多次
//技巧：n = n&(n-1)，是将n这个数的最右边的那个1置为0
public class NumberOf1Solution {
  public int NumberOf1(int n) {
      int count =0;
      while(n != 0 ) {
          n = n &(n-1);
          ++count;
      }
      return count;
  }
}
//class Test {
//public static void main(String[] args) {
//    Solution test = new Solution();
//    int n = test.NumberOf1(0x80000000);
//    System.out.println(n);
//}
//}


//test
//2