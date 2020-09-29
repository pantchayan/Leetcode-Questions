import java.util.ArrayList;
import java.util.List;

class Solution {
    public class TreeNode {
        int val;
        TreeNode left;
        TreeNode right;

        TreeNode() {
        }

        TreeNode(int val) {
            this.val = val;
        }

        TreeNode(int val, TreeNode left, TreeNode right) {
            this.val = val;
            this.left = left;
            this.right = right;
        }
    }
    public List<Integer> preorderTraversal(TreeNode root) {
         List<Integer> ans = new ArrayList<>();
        
        preorder(root,ans);
        
        return ans;
    }
    
    public static void preorder(TreeNode node,List<Integer> ans){
        if(node == null) return;
        
        ans.add(node.val);
        preorder(node.left,ans);
        preorder(node.right,ans);
    }
    
}