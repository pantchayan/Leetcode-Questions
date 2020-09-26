class Tree
{
    public class Node{
        Node right=null;
        Node left=null;
        int data = 0;
        Node(int data){
            this.data=data;
        }
    }
    int maxPathSum(Node root)
    { 
        maxPSL = Integer.MIN_VALUE;
        maxPathSumLeaves(root);
        return maxPSL;
        
    } 
    int maxPSL = Integer.MIN_VALUE;
    int maxPathSumLeaves(Node node){
        if(node==null) return 0;
        if(node.left==null&&node.right==null)return node.data;

        int lh=maxPathSumLeaves(node.left);
        int rh=maxPathSumLeaves(node.right);

        //PostOrder
        
        //both childs present ==> leaf to leaf path is possible
        if(node.left!=null && node.right!=null){
            maxPSL = Math.max(maxPSL,lh+rh+node.data);

            return Math.max(lh,rh) + node.data;
        }

        return node.left==null?rh+node.data:lh+node.data;

    }
    
}