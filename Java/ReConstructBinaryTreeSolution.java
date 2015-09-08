//根据二叉树的前序序列和中序序列，构建出该二叉树
//根据前序序列的第一个为根节点，在中序序列中遍历根节点可以得到左子树和右子树
//通过递归，可以构造出这颗二叉树

public class ReConstructBinaryTreeSolution {
  public TreeNode reConstructBinaryTree(int [] pre,int [] in) {
      int length = pre.length;
      if(length <= 0) return null;
       
      int preStart = 0;
      int preEnd = length-1;
      int inStart = 0;
      int inEnd = length-1;
      return constructBinaryTree(pre, preStart, preEnd,
              in, inStart, inEnd);   
  }
   
  private TreeNode constructBinaryTree(int[] pre, int preStart, int preEnd,
          int[] in, int inStart, int inEnd) {
      int rootValue = pre[preStart];
      TreeNode root = new TreeNode(rootValue);
      root.left = null;
      root.right = null;
       
      //递归的最后一次，返回root节点
      if(preStart == preEnd) {
          if(inStart == inEnd && pre[preStart] == in[inStart]) {
              return root;
          }
      }
       
      //遍历中序序列，找到根节点
      int rootIndex=inStart;
      while(rootIndex <= inEnd) {
          if(in[rootIndex] == rootValue) break;
          if(rootIndex == inEnd) {
              System.out.println("input is unvalid!");
          }
          else ++rootIndex;
      }
       
      int leftTreeLength = rootIndex-inStart;
      int leftPreEnd = preStart+leftTreeLength;
      if(leftTreeLength > 0) {
          //构造左子树
          root.left = constructBinaryTree(pre, preStart+1, leftPreEnd,
                  in, inStart, rootIndex-1);
      }
      if(leftTreeLength < preEnd-preStart) {
          //构建右子树
          root.right = constructBinaryTree(pre, leftPreEnd+1, preEnd,
                  in, rootIndex+1, inEnd);
      }
      return root;
  }
}
//class Test {
//public static void main(String[] args) {
//    Solution test = new Solution();
//    int[] pre = {1,2,4,7,3,5,6,8};
//    int[] in = {4,7,2,1,5,3,8,6};
//    TreeNode n = test.reConstructBinaryTree(pre, in);
//    //System.out.println(n);
//}
//}


//test
//{1,2,3,4,5}
//{3,4,5,6,7,1,2}
//原始：{1,2,2,2,2,2},旋转数组1：{2,2,1,2,2,2}，旋转数组2：{2,2,2,2,1,2}
//