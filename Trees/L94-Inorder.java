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
    
    public List<Integer> inorderTraversal(TreeNode root) {
        List<Integer> ans = new ArrayList<>();
        
        inorder(root,ans);
        
        return ans;
    }
    
    public static void inorder(TreeNode node,List<Integer> ans){
        if(node == null) return;
        
        inorder(node.left,ans);
        ans.add(node.val);
        inorder(node.right,ans);
    }
}
