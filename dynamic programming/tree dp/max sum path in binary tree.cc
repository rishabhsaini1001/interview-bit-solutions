/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

 int max(int a, int b)
{ return (a >= b)? a: b; }

 int m(TreeNode* A, int *sum)
 {
    if(A == NULL)
        return 0;
    else
    {
        int m1 = m(A->left,sum);
        int m2 = m(A->right,sum);
        int max2 = A->val;
        int h = max(m1,m2);
        if(h>0)
            max2 +=h;
        int max1 = m1 + m2 + A->val;
        if(max1 < max2)
            max1 = max2;
        if(max1 < *sum)
            *sum = max1;
        return max2;
    }
 }


int maxPath(TreeNode* A, int* sum) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

        int m1,m2;
        if(!A->left)
            m1 = 0;
        else
            m1 = maxPath(A->left,sum);
        if(!A->right)
            m2 = 0;
        else
            m2 = maxPath(A->right,sum);
        if(m1==m2==0)
        {
            if(A->val>*sum)
                *sum = A->val;
            return A->val;
        }
        int max = A->val,max1;
        //if(max < m1 + m2 + A->val)
        max1 = m1 + m2 + A->val;

        int h = m1>m2?m1:m2;
        if(h>0)
            max +=h;

        if(max > max1)
            max1 = max;
        if(max1>*sum)
            *sum = max1;
        return max;

}

int maxPathSumUtil(TreeNode *root, int *res)
{
    // Base cases
    if (root==NULL) return 0;
    if (!root->left && !root->right) return root->val;

    // Find maximum sum in left and right subtree. Also
    // find maximum root to leaf sums in left and right
    // subtrees and store them in ls and rs
    int ls = maxPathSumUtil(root->left, res);
    int rs = maxPathSumUtil(root->right, res);


    // If both left and right children exist
    if (root->left && root->right)
    {
        // Update result if needed
        *res = max(*res, ls + rs + root->val);

        // Return maxium possible value for root being
        // on one side
        return max(ls, rs) + root->val;
    }

    // If any of the two children is empty, return
    // root sum for root being on one side
    return (!root->left)? rs + root->val:
                          ls + root->val;
}

int findMaxUtil(TreeNode* root, int *res)
{
    //Base Case
    if (root == NULL)
        return 0;

    // l and r store maximum path sum going through left and
    // right child of root respectively
    int l = findMaxUtil(root->left,res);
    int r = findMaxUtil(root->right,res);

    // Max path for parent call of root. This path must
    // include at-most one child of root
    int max_single = max(max(l, r) + root->val, root->val);

    // Max Top represents the sum when the Node under
    // consideration is the root of the maxsum path and no
    // ancestors of root are there in max sum path
    int max_top = max(max_single, l + r + root->val);

    *res = max(*res, max_top); // Store the Maximum Result.

    return max_single;
}

// Returns maximum path sum in tree with given root
/*
int findMaxSum(TreeNode *root)
{
    // Initialize result
    int res = INT_MIN;

    // Compute and return result
    findMaxUtil(root, res);
    return res;
}
*/
int Solution::maxPathSum(TreeNode* A) {
    int sum = INT_MIN;
    int a =  m(A,&sum);
    return sum;
 }
