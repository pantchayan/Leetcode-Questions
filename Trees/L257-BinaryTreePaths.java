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
    public List<String> binaryTreePaths(TreeNode root) {
        List<String> ans = new ArrayList<>();
        if(root==null) return ans;
        
        
        path(root,"",ans);
        return ans;
    }
    
    public static void path(TreeNode node,String path,List<String> ans){
        if(node==null) return;
        if(node.left==null && node.right==null){
            String temp = path;
            temp+=node.val;
            ans.add(temp);
        }
        path(node.left,path+node.val+"->",ans);
        path(node.right,path+node.val+"->",ans);
    }
}