//使用两个stack实现一个队列，实现压入和弹出的操作
import java.util.ArrayList;
import java.util.Stack;
public class Stack2QueueSolution {
    Stack<Integer> stack1 = new Stack<Integer>();
    Stack<Integer> stack2 = new Stack<Integer>();
    //使用栈1来进行数据的压入操作
    public void push(int node) {
        stack1.push(node);     
    }
    //使用栈2来进行数据的弹出操作
    //当栈2不为空的时候，直接弹出；如果为空，将栈1的数据弹出并压入栈2；如果栈2也为空，抛出异常
    public int pop() {
        if(stack2.isEmpty()) {
            if(stack1.isEmpty()) {
                System.out.println("没有数据弹出");
                return 0;
            } else {
                //循环将栈1的数据取出并放到栈2中
                while(stack1.isEmpty() == false) {
                    int data = stack1.pop();
                    stack2.push(data);
                }
                return stack2.pop();
            }
             
        } else {
            return stack2.pop();
        }      
    
    }
}
//class Test {
//  public static void main(String[] args) {
//      Solution test = new Solution();
//      test.push(1);
//      test.push(2);
//      test.push(3);
//      System.out.println(test.pop());
//      System.out.println(test.pop());
//      System.out.println(test.pop());
//  }
//}
 
 
//test
//{1,2,3,4,5}