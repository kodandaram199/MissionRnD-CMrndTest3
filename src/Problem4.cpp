/*

Given two Binary Search Trees ,Merge Both of them into a Single Binary Search Tree .
The Resultant Binary Search Tree will be BST1 .ie Merge all elements of BST2 into BST1.

Example 1:
Input : 
   20        25
  /  \      /  \
 5    30   10   35
Output :
Bst 1 :
     20
   /   \
  5     30
   \   /  \
   10 25   35

BST 2 can be merged in BST1 sometimes in many number of ways ,Any 1 of those correct ways would be fine .
Finally All elements of Both Trees should be in BST 1 .Dont process NULL Inputs 
(Both r1 and r2 shouldnt be NULL at the time of Input)

Note : Dont Create Nodes using malloc,or Swap the data values or else your solution would receive 100%
cut in the marks you got for this question .
You need to solve this question only by changing links.

You will also receive Bonus marks for any better optimizations you make .
Difficulty : Medium -Hard 
*/
#include <stdlib.h>
#include <stdio.h>

struct node{
	int data;
	struct node *left;
	struct node *right;
};

int count(struct node* root)
{
	int coun = 1;
	if (root == NULL)
		return 0;
	else
	{
		coun += count(root->left);
		coun += count(root->right);
		return coun;
	}
}
void inorder(struct node* root, int inorderarr[], int *index)
{
	if (root == NULL)
		return;
	inorder(root->left, inorderarr, index);

	inorderarr[*index] = root->data;
	(*index)++;

	inorder(root->right, inorderarr, index);
}
struct node* arraytobst(int *arr, int begin, int end)
{


	if (begin > end)
		return NULL;
	
	int mid = (begin + end) / 2;

	struct node *root = (struct node*) calloc(1,sizeof(struct node));

	root->data = arr[mid];
	root->left = arraytobst(arr, begin, mid - 1);
	root->right = arraytobst(arr, mid + 1, end);


}


int *merge(int arr1[], int arr2[], int m, int n)
{
	
	int *mergedArr = (int*)calloc((m + n),sizeof(int));
	int i = 0, j = 0, k = 0;
	while (i < m && j < n)
	{
		if (arr1[i] < arr2[j])
		{
			mergedArr[k] = arr1[i];
			i++;
		}
		else
		{
			mergedArr[k] = arr2[j];
			j++;
		}
		k++;
	}

	while (i < m)
	{
		mergedArr[k] = arr1[i];
		i++; k++;
	}

	
	while (j < n)
	{
		mergedArr[k] = arr2[j];
		j++; k++;
	}

	return mergedArr;
}


void merge_two_bst(struct node *root1, struct node *root2){
	struct node* temp1 = root1;
	struct node* temp2 = root1;
	int m = count(temp1);
	int n = count(temp2);
	int index1 = 0,index2=0;
	int* arr1 = (int*)calloc(m,sizeof(int));
	int* arr2 = (int*)calloc(m, sizeof(int));
	inorder(root1, arr1, &index1);
	inorder(root2, arr2, &index2);
	int *mergedBst = merge(arr1, arr2, m, n);
	struct node  *bst=arraytobst(mergedBst, 0, m + n - 1);
}