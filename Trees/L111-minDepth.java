import java.util.LinkedList;

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

    public int minDepth(TreeNode root) {
        LinkedList<TreeNode> que = new LinkedList<>();
        if(root==null)
            return 0;
        que.addLast(root);
        
        int level = 1;
        while(que.size()!=0){
            int size = que.size();
            while(size-->0){
                TreeNode curr = que.getFirst();
                que.removeFirst();
                
                if(curr.left==null && curr.right==null){
                    return level;
                }
                
                if(curr.left!=null) que.addLast(curr.left);
                
                if(curr.right!=null) que.addLast(curr.right);
            }
            level++;
        }
        
        return level;
    }
}