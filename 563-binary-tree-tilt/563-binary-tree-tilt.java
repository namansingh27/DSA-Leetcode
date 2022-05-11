/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
public class Solution {
	private int result = 0;

	public int findTilt(TreeNode root) {
		postOrder(root);
		return result;
	}

	private int postOrder(TreeNode root) {
		if (root == null) return 0;

		int leftSubstreeSum = postOrder(root.left);
		int rightSubstreeSum = postOrder(root.right);

		result += Math.abs(leftSubstreeSum - rightSubstreeSum);

		return leftSubstreeSum + rightSubstreeSum + root.val;
	}
}