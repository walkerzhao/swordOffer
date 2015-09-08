import java.util.ArrayList;
import java.util.Collections;

public class PrintListFromTailToHeadSolution {
    public ArrayList<Integer> printListFromTailToHead(ListNode listNode) {
        ArrayList<Integer> result = new ArrayList<Integer>();
         
        ListNode node = listNode;
        while(node != null) {
            result.add(node.val);
            node = node.next;
        }
        Collections.reverse(result);
        return result;
         
    }
}
