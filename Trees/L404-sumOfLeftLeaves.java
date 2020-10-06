class Solution {
    static int sum = 0;
    public int sumOfLeftLeaves(TreeNode root) {
        sum = 0;
        
        sumLeaves(root);
        
        return sum;
    }
    
    
    public static void sumLeaves(TreeNode node){
        if(node==null) return;
        
        if(node.left!=null){
            if(node.left.left==null && node.left.right == null) sum+=node.left.val;
        }
        sumLeaves(node.left);
        sumLeaves(node.right);
    }
    
}