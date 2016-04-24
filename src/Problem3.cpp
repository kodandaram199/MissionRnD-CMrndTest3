/*
Given a Tree which consists of operands and operators ,Solve the Tree and return the result
The tree will have special nodes of type enode which will have 3 fields
data => String of 5 chars .which can be either a operator or operand 
If its a operator its values will be one of the 3 following strings "+" , "-" , "*".
If its a operand its values will be any number from -9999 to 99999 in its respective string format;
Left and Right pointers will point to either NULL or another enode
Only the leaf nodes will have operand values .

Example 1:
    +
   / \
  4   5 
The Result expression is : 4+5 ,Ans is 9

Example 2:
        *
       / \
      -   5
     / \
    7   2

The Result expression is : (7-2) * 5  ,Ans is 25

Example 3:
       +
     /   \
    *     -  
   / \   / \
  7   2  4  *
           / \
          2   1
  
The Result expression is : (7*2) + (4-(2*1)) =>14+2 =>16 ,Ans is 16 

Constraints : 
Total number of enodes will be <=20 for 50% of Test cases
Data value will only have "0"<=data<="99999" values for 50% of cases .
Data value for operators will have sign as first character and \0 as next character .

Input :
Root node of a Tree of type enode
Output :
Return Final answer or -1 for Null inputs

Note :
->Dont Create an Extra Array/String ,or else your solution would receive 20%-40% Cut in the Marks you got .

Difficulty : Medium
*/
#include <stdlib.h>;
#include <stdio.h>

//data can be accessed using root->data;
struct enode{
	char data[6];
	struct enode *left;
	struct enode *right;
};

/*
Helper Functions are optional to write 
*/
//Helper Functions Start
int isOperator(char *data){
	if (*data == NULL)
		return -1;
	switch (*data)
	{
	case '+':
	case '-':
	case '*':
	case '/':
	case '**':
	case '%':
		return 1;
	default:
		return 0;
	}
}
int isOperand(char *data){
	if (*data == NULL)
		return -1;
	int c = isOperator(data);
	if (c == 1)
		return 0;
	
	return 1;
}
int getOperand(char *data){
	if (*data==NULL)
	return -1;
}
struct enode* postfix(struct enode* root)
{
	struct enode *temp = root;

	struct enode *temp1 = (struct enode*)calloc(1,sizeof(enode));
	struct enode *temp2 = NULL;
	if (temp)
	{
		postfix(temp->left);
		postfix(temp->right);
		temp2->data = temp->data;
		temp2->left = temp1;
		temp1 = temp2;
	}
	return temp1;
}
char * solve(struct enode* exp)
{
	struct enode* temp = exp;
	char *num1, *num2, *op;
	
	int result;
	if (temp)
	{
		struct enode* leftt = temp->left;
		struct enode* rightt = temp->right;

		if (leftt)
		{
			if (isOperand(leftt->data))
			{
				num1  = leftt->data;
			}
			else
			{
				num1 = solve(leftt);
			}
		}

		if (rightt)
		{
			if (isOperand(rightt->data))
			{
				num2 = rightt->data;
			}
			else
			{
				num2 = solve(rightt);
			}
		}

		op = temp->data;
		
		result = eval(op,num1 - '0', num2 - '0');
		
		temp->data = (result + '0');
	
		return temp->data;
	}

	return NULL;
}
int eval(char* op,char *op1, char *op2)
{
	
	switch (op)
	{
		case '+':   return(*op1 + *op2);
		break;
	case '-':   return(*op1 - *op2);
		break;
	case '*':   return((*op1)*(*op2));
		break;
	case '/':   return((*op1 )/ (*op2));
		break;
	case '%':   return((*op1)%(*op2));
		break;
	case '**':   return pow(op1, op2);
		break;
	}
}
int pow(int op1, int op2)
{
	for (int i = op2; i > 0; i--)
	{
		op1 = op1*i;
	}
	return op1;

}
int solve_tree(struct enode *root){
	if (root==NULL)
    return -1;
	struct enode* exp=postfix(root);
	while (exp->left != NULL)
	{
		if ()
	}
	solve(exp);
}

