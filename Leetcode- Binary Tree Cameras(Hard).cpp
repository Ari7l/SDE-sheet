//So first of all this is recursive postorder, which should be clear from the title.
//And on each step we determine in which state are both of our children.
//There are 3 possible states for each node:
//-1 - node is NOT watched by the camera, which means it needs to be watched by parent
//1 - node IS watched by the camera (also that's return value for null child, since it doesn't need to be watched)
//0 - node is camera itself
class Solution {
public:
    int camera=0;
    
    int solve(TreeNode *root)
    {
        if(!root) //null child hence no need of camera
            return 1;
        int lc=solve(root->left);//post order traversal left right root
        int rc=solve(root->right);
        if(lc==-1 or rc==-1)// atleast one of child node needs to be watched hence increment camera no.
        //and return 0 as now I have camera	
        {
            camera++;
            return 0;
        }
        if(lc==0 or rc==0) // I am a parent node which is watched by its child node camera
            return 1; //hence return I am being watched
        return -1;// now if none of the above conditions are true i.e my child is being watched by its child
        //hence I'm telling my parent to install a camera 
    }
    
    int minCameraCover(TreeNode* root) {
        camera=0;
        if(solve(root)==-1)//if the root node is not being watched by either of its child then
        	//root needs a camera
            camera++;
        return camera;
    }
};