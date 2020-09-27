
import java.util.*;
class Solution {
    
  public class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;
    TreeNode() {}
    TreeNode(int val) { this.val = val; }
    TreeNode(int val, TreeNode left, TreeNode right) {
        this.val = val;
        this.left = left;
        this.right = right;
    }
}
    public List<Integer> rightSideView(TreeNode root) {
    
        List<Integer> ans = new ArrayList<Integer>();
        
        if(root==null) return ans;
        LinkedList<TreeNode> que = new LinkedList<>();
        
        que.addLast(root);
        
        while(que.size()!=0){
            int size = que.size();
            ans.add(que.getLast().val);
            while(size-->0){
                TreeNode curr = que.getFirst();
                que.removeFirst();
                
                if(curr.left!=null) que.addLast(curr.left);
                if(curr.right!=null) que.addLast(curr.right);
            }
        }
        
        return ans;
        
    }
}